// Copyright (C) 2011-2012  CEA/DEN, EDF R&D
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
//
// See http://www.salome-platform.org/ or email : webmaster.salome@opencascade.com
//

#include "HomardMedCommun.h"

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>

extern "C" 
{
#include <med.h>
}

#include "utilities.h"
// =======================================================================
std::set<std::string> GetListeGroupesInMedFile(const char * aFile)
// =======================================================================
{
  std::set<std::string> ListeGroupes;
  med_idt medIdt = MEDfileOpen(aFile,MED_ACC_RDONLY);
  if ( medIdt < 0 ) { return ListeGroupes; };

  char meshname[MED_NAME_SIZE+1];
  med_int spacedim,meshdim;
  med_mesh_type meshtype;
  char descriptionription[MED_COMMENT_SIZE+1];
  char dtunit[MED_SNAME_SIZE+1];
  med_sorting_type sortingtype;
  med_int nstep;
  med_axis_type axistype;
  int naxis = MEDmeshnAxis(medIdt,1);
  char *axisname=new char[naxis*MED_SNAME_SIZE+1];
  char *axisunit=new char[naxis*MED_SNAME_SIZE+1];
  med_err aRet = MEDmeshInfo(medIdt,
                          1,
                          meshname,
                          &spacedim,
                          &meshdim,
                          &meshtype,
                          descriptionription,
                          dtunit,
                          &sortingtype,
                          &nstep,
                          &axistype,
                          axisname,
                          axisunit);
   if ( aRet < 0 ) { return ListeGroupes; };
   
   med_int nfam, ngro, natt;
   if ((nfam = MEDnFamily(medIdt,meshname)) < 0) { return ListeGroupes; };
   
  char familyname[MED_NAME_SIZE+1];
  med_int numfam;
  for (int i=0;i<nfam;i++) 
  {
    if ((ngro = MEDnFamilyGroup(medIdt,meshname,i+1)) < 0) 
    {
      // GERALD -- QMESSAGE BOX
      std::cerr << " Error : Families are unreadable" << std::endl;
      std::cerr << "Pb avec la famille : " << i+1 << std::endl;
      break;
    }
    if (ngro == 0) continue;

    if ((natt = MEDnFamily23Attribute(medIdt,meshname,i+1)) < 0) 
    {
      // GERALD -- QMESSAGE BOX
      std::cerr << " Error : Families are unreadable" << std::endl;
      std::cerr << "Pb avec la famille : " << i+1 << std::endl;
      break;
    }

    med_int* attide = (med_int*) malloc(sizeof(med_int)*natt);
    med_int* attval = (med_int*) malloc(sizeof(med_int)*natt);
    char*    attdes = (char *)   malloc(MED_COMMENT_SIZE*natt+1);
    char*    gro    = (char*)    malloc(MED_LNAME_SIZE*ngro+1);
    
    med_err aRet = MEDfamily23Info(medIdt,
                                meshname,
                                i+1,
                                familyname,
                                attide,
                                attval,
                                attdes,
                                &numfam,
                                gro);
    
    if (aRet < 0) 
    { 
      // GERALD -- QMESSAGE BOX
      std::cerr << " Error : Families are unreadable" << std::endl;
      std::cerr << "Pb avec la famille : " << i+1 << std::endl;
        break;
    }
    free(attide);
    free(attval);
    free(attdes);
    if ((numfam )> 0) { continue;} // On ne garde que les familles d elts

    for (int j=0;j<ngro;j++) 
    {
          char str2[MED_LNAME_SIZE+1];
          strncpy(str2,gro+j*MED_LNAME_SIZE,MED_LNAME_SIZE);
          str2[MED_LNAME_SIZE] = '\0';
          ListeGroupes.insert(std::string(str2));
    }
    free(gro);
  }
  MEDfileClose(medIdt);
  return ListeGroupes;
}

// =======================================================================
std::vector<double> GetBoundingBoxInMedFile(const char * aFile)
// =======================================================================
{
// Le vecteur en retour contiendra les informations suivantes :
// en position 0 et 1 Xmin, Xmax et en position 2 Dx si < 0  2D
// en position 3 et 4 Ymin, Ymax et en position 5 Dy si < 0  2D
// en position 6 et 7 Zmin, Zmax et en position 8 Dz si < 0  2D
//  9 distance max dans le maillage

   std::vector<double> LesExtremes;
   
   // Ouverture du Fichier Med
   med_idt medIdt = MEDfileOpen(aFile,MED_ACC_RDONLY);
   if (medIdt <0) 
   {
          // GERALD -- QMESSAGE BOX
          std::cerr << "Error : mesh is unreadable" << std::endl;
          return LesExtremes;
   }

                                // Le fichier Med est lisible
    // Boucle sur les noms de maillage
   med_int numberOfMeshes = MEDnMesh(medIdt) ;
   if (numberOfMeshes != 1 ) 
   {
          // GERALD -- QMESSAGE BOX
          std::cerr << "Error : file contains more than one mesh" << std::endl;
          return LesExtremes;
   }

  char meshname[MED_NAME_SIZE+1];
  med_int spacedim,meshdim;
  med_mesh_type meshtype;
  char descriptionription[MED_COMMENT_SIZE+1];
  char dtunit[MED_SNAME_SIZE+1];
  med_sorting_type sortingtype;
  med_int nstep;
  med_axis_type axistype;
  int naxis = MEDmeshnAxis(medIdt,1);
  char *axisname=new char[naxis*MED_SNAME_SIZE+1];
  char *axisunit=new char[naxis*MED_SNAME_SIZE+1];
  med_err aRet = MEDmeshInfo(medIdt,
                          1,
                          meshname,
                          &spacedim,
                          &meshdim,
                          &meshtype,
                          descriptionription,
                          dtunit,
                          &sortingtype,
                          &nstep,
                          &axistype,
                          axisname,
                          axisunit);

   if (aRet < 0) 
   {
          // GERALD -- QMESSAGE BOX
          std::cerr << "Error : mesh is unreadable" << std::endl;
          return LesExtremes;
   }

  med_bool chgt,trsf;
  med_int nnoe  = MEDmeshnEntity(medIdt,
                            meshname,
                            MED_NO_DT,
                            MED_NO_IT,
                            MED_NODE,
                            MED_NO_GEOTYPE,
                            MED_COORDINATE,
                            MED_NO_CMODE,
                            &chgt,
                            &trsf);
   if ( nnoe < 0) 
   {
          // GERALD -- QMESSAGE BOX
          std::cerr << "Error : mesh is unreadable" << std::endl;
          return LesExtremes;
   }

  med_float* coo    = (med_float*) malloc(sizeof(med_float)*nnoe*spacedim);

  aRet = MEDmeshNodeCoordinateRd(medIdt,
                                      meshname,
                                      MED_NO_DT,
                                      MED_NO_IT,
                                      MED_NO_INTERLACE,
                                      coo);
   if ( aRet < 0) 
   {
          // GERALD -- QMESSAGE BOX
          std::cerr << "Error : mesh coordinates are unreadable" << std::endl;
          return LesExtremes;
   }

   med_float xmin,xmax,ymin,ymax,zmin,zmax;
   
   xmin=coo[0];
   xmax=coo[0];
   for (int i=1;i<nnoe;i++)
   {
      xmin = std::min(xmin,coo[i]);
      xmax = std::max(xmax,coo[i]);
   }
//
   if (spacedim > 1)
   {
       ymin=coo[nnoe]; ymax=coo[nnoe];
       for (int i=nnoe+1;i<2*nnoe;i++)
       {
           ymin = std::min(ymin,coo[i]);
           ymax = std::max(ymax,coo[i]);
       }
   }
   else
   {
       ymin=0;
       ymax=0;
       zmin=0;
       zmax=0;
   }
//
   if (spacedim > 2)
   {
       zmin=coo[2*nnoe]; zmax=coo[2*nnoe];
       for (int i=2*nnoe+1;i<3*nnoe;i++)
       {
           zmin = std::min(zmin,coo[i]);
           zmax = std::max(zmax,coo[i]);
       }
   }
   else
   {
       zmin=0;
       zmax=0;
   }
   MEDfileClose(medIdt);

   MESSAGE( "_______________________________________");
   MESSAGE( "xmin : " << xmin << " xmax : " << xmax );
   MESSAGE( "ymin : " << ymin << " ymax : " << ymax );
   MESSAGE( "zmin : " << zmin << " zmax : " << zmax );
   MESSAGE( "_______________________________________" );
   double epsilon = 1.e-6 ;
   LesExtremes.push_back(xmin);
   LesExtremes.push_back(xmax);
   LesExtremes.push_back(0);
   LesExtremes.push_back(ymin);
   LesExtremes.push_back(ymax);
   LesExtremes.push_back(0);
   LesExtremes.push_back(zmin);
   LesExtremes.push_back(zmax);
   LesExtremes.push_back(0);


   double max1=std::max ( LesExtremes[1] - LesExtremes[0] , LesExtremes[4] - LesExtremes[3] ) ;
   double max2=std::max ( max1 , LesExtremes[7] - LesExtremes[6] ) ;
   LesExtremes.push_back(max2);

// LesExtremes[0] = Xmini du maillage
// LesExtremes[1] = Xmaxi du maillage
// LesExtremes[2] = increment de progression en X
// LesExtremes[3,4,5] : idem pour Y
// LesExtremes[6,7,8] : idem pour Z
// LesExtremes[9] = ecart maximal entre coordonnees
// On fait un traitement pour dans le cas d'une coordonnee constante
// inhiber ce cas en mettant un increment negatif
//
   double diff = LesExtremes[1] - LesExtremes[0];
   if (fabs(diff)  > epsilon*max2)
   {
      LesExtremes[2] = diff/100.;
   }
   else
   {
      LesExtremes[2] = -1. ;
   }

   diff = LesExtremes[4] - LesExtremes[3];
   if (fabs(diff)  > epsilon*max2)
   {
      LesExtremes[5]=diff/100.;
   }
   else
   {
      LesExtremes[5] = -1. ;
   }

   diff = LesExtremes[7] - LesExtremes[6];
   if (fabs(diff)  > epsilon*max2)
   {
      LesExtremes[8]=diff/100.;
   }
   else
   {
      LesExtremes[8] = -1. ;
   }

   MESSAGE ( "_______________________________________" );
   MESSAGE ( "xmin : " << LesExtremes[0] << " xmax : " << LesExtremes[1] << " xincr : " << LesExtremes[2] );
   MESSAGE ( "ymin : " << LesExtremes[3] << " ymax : " << LesExtremes[4] << " yincr : " << LesExtremes[5] );
   MESSAGE ( "zmin : " << LesExtremes[6] << " zmax : " << LesExtremes[7] << " zincr : " << LesExtremes[8] );
   MESSAGE ( "dmax : " << LesExtremes[9] );
   MESSAGE ( "_______________________________________" );

   return  LesExtremes;
}

