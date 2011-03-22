using namespace std;

#include "MonEditFile.h"

#include <QFile>
#include <QTextStream>
#include <QMessageBox>

#include "SalomeApp_Tools.h"
#include "HOMARDGUI_Utils.h"
#include "HomardQtCommun.h"
#include <utilities.h>

/* ---------------------------------------------------------
 * MonEditFile classe derivee de EditFile
 *               elle meme generee par uic
 * Ouvre le fichier passe en parametre
 * et affiche le texte correspondant dans la fenetre de log
 * ---------------------------------------------------------
 */

/* ---------------------------------------------------------
 * MonEditFile Constructeur
 * ---------------------------------------------------------
 */
MonEditFile::MonEditFile( QWidget* parent,  bool modal,
                          HOMARD::HOMARD_Gen_var myHomardGen,
                          QString aFileName):
//    QWidget(0),
    Ui_EditFile(),
    _aFileName (aFileName)
{
  MESSAGE("Debut de MonEditFile " << aFileName.toStdString().c_str());
  setupUi(this);
  InitConnect();
  EditText();
}
/*
 *  Destroys the object and frees any allocated resources
 */
MonEditFile::~MonEditFile()
{
   MESSAGE("Destructeur de ~MonEditFile");
}
// ------------------------------------------------------------------------
void MonEditFile::InitConnect()
// ------------------------------------------------------------------------
{
    connect( buttonQuit,     SIGNAL(pressed()), this, SLOT(close()));
    connect( buttonPrint,    SIGNAL(pressed()), this, SLOT(PushOnPrint()));
}
// ------------------------------------------------------------------------
void MonEditFile::EditText()
// ------------------------------------------------------------------------
{
// Creation de l'objet fichier QT associe
  QFile file( _aFileName );
// Ouverture
  bool bOpen = file.open( QIODevice::ReadOnly | QIODevice::Text ) ;
//
  if ( bOpen )
  {
// Lecture
//    Remarque : il serait plus clair de tout lire d'un coup mais cela ne marche pas !
//               alors on fait ligne par ligne et on cumule en ajoutant un saut de ligne.
      QTextStream stream( &file );
      QString tout;
      while ( !stream.atEnd() )
      {
        tout = tout + stream.readLine() + "\n" ;
      }
//       tout = stream.readAll() ;
      QTBEditFile->setPlainText( tout );
  }
  else
  {
     // GERALD -- QMESSAGE BOX
     MESSAGE( "EditText " << _aFileName.toStdString().c_str() << "est impossible a ouvrir ");
  }
}
// ------------------------------------------------------------------------
void MonEditFile::PushOnPrint()
// ------------------------------------------------------------------------
{
  MESSAGE("Debut de MonEditFile::PushOnPrint")
  QMessageBox::information( 0, "Error",
                            "Inactive button.",
                            QMessageBox::Ok + QMessageBox::Default );
  return;
}


