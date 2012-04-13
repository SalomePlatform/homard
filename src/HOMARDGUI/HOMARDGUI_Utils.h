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

#ifndef HOMARD_H_UTILS
#define HOMARD_H_UTILS


#include <SALOMEconfig.h>

#include <CORBA.h>
#include CORBA_CLIENT_HEADER(HOMARD_Cas)
#include CORBA_CLIENT_HEADER(HOMARD_Gen)

#include "SALOMEDSClient_definitions.hxx"
#include "SALOME_InteractiveObject.hxx"
#include "LightApp_DataOwner.h"
#include "SalomeApp_Application.h"
#include <SALOME_ListIO.hxx>

class QString;
class QStringList;

class SUIT_ViewWindow;
class SUIT_Desktop;
class SUIT_Study;
class SUIT_ResourceMgr;

class CAM_Module;

class SALOMEDSClient_Study;
class SALOMEDSClient_SObject;

class SalomeApp_Study;
class SalomeApp_Module;
class LightApp_SelectionMgr;

namespace HOMARD_UTILS {

  _PTR(Study)
  GetCStudy(const SalomeApp_Study* theStudy);
  SUIT_Study* GetActiveStudy();
  _PTR(Study) GetActiveStudyDocument();

  void updateObjBrowser();

  const SALOME_ListIO& selectedIO();    // Function returns a list of SALOME_InteractiveObject's from
                                        // selection manager in GUI

  int   IObjectCount() ;                // Function returns the number of selected objects

  Handle(SALOME_InteractiveObject) firstIObject() ;
                                        // Function returns the first selected object in the list
                                        // of selected objects

  Handle(SALOME_InteractiveObject) lastIObject() ;
                                      // Function returns the last selected object in the list
                                       // of selected objects

  bool isXmgrace(_PTR(SObject)  MonObj);
  bool isBoundaryAn(_PTR(SObject)  MonObj);
  bool isBoundaryDi(_PTR(SObject)  MonObj);
  bool isZone(_PTR(SObject)  MonObj);
  bool isHypo(_PTR(SObject)  MonObj);
  bool isIter(_PTR(SObject)  MonObj);
  bool isCase(_PTR(SObject)  MonObj);
  bool isFileMess(_PTR(SObject)  MonObj);
  bool isFileSummary(_PTR(SObject)  MonObj);
  bool isObject(_PTR(SObject)  MonObj, QString TypeObject, int option );

  void PushOnHelp(QString monFichierAide);

  extern SALOME_ListIO mySelected;
}

#endif // ifndef HOMARD_H_UTILS
