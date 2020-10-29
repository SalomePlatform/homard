/* __________________________________________________________________________ */
/*                                                                            */
/*                              H O M A R D                                   */
/*                                                                            */
/*   Outil de Maillage Adaptatif par Raffinement et Deraffinement d'EDF R&D   */
/*                                                                            */
/* Version originale enregistrée le 18 juin 1996 sous le numéro 96036 auprès  */
/* des huissiers de justice Simart et Lavoir à Clamart                        */
/* Version 11.2 enregistrée le 13 février 2015 sous le numéro 2015/014 auprès */
/* des huissiers de justice Lavoir, Silinski & Cherqui-Abrahmi à Clamart      */
/*                                                                            */
/*   HOMARD est une marque déposée d'Electricite de France                    */
/*                                                                            */
/* Copyright EDF 1997                                                         */
/* Copyright EDF 1998                                                         */
/* Copyright EDF 1999                                                         */
/* Copyright EDF 2021                                                         */
/* __________________________________________________________________________ */

#include "dminfc.h"
#include "dmport.h"
#include "FC.h"

/* %%%%%%%%%%%%%%%%% début de zone à préprocesser %%%%%%%%%%%%%%%%%% */
#ifdef _POSIX
void dmloca_( void *a, INTGR *iad )
#else
#ifdef extern_stdcall
extern void __stdcall DMLOCA( void *a, INTGR *iad )
#else
void FortranCInterface_GLOBAL(dmloca, DMLOCA)(void *a, INTGR *iad)
#endif
#endif
/* %%%%%%%%%%%%%%%%%% fin de zone à préprocesser %%%%%%%%%%%%%%%%%%% */

{
    *iad = (long) a ;
}

