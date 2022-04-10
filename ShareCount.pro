QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    affichage/fenetre.cpp \
    affichage/fenetreauthentification.cpp \
    affichage/fenetrecagnotte.cpp \
    affichage/fenetreconsultermesdepenses.cpp \
    affichage/fenetrecontact.cpp \
    affichage/fenetrecreationcagnotte.cpp \
    affichage/fenetrecreationgdb.cpp \
    affichage/fenetredepenses.cpp \
    affichage/fenetregdb.cpp \
    affichage/fenetreinscription.cpp \
    affichage/fenetremenu.cpp \
    affichage/fenetreprofile.cpp \
    affichage/fenetrevisucagnotte.cpp \
    affichage/fenetrevisugdb.cpp \
    compte/cagnotte.cpp \
    compte/compte.cpp \
    compte/gestionnairedebudget.cpp \
    console.cpp \
    formulaire/formulaire.cpp \
    formulaire/formulaireauthentification.cpp \
    formulaire/formulairecompte.cpp \
    formulaire/formulairecontact.cpp \
    formulaire/formulairedepensegdb.cpp \
    formulaire/formulaireinscription.cpp \
    formulaire/formulairemenu.cpp \
    formulaire/formulairemodification.cpp \
    main.cpp \
    mainwindow.cpp \
    model.cpp \
    outils/basededonnees.cpp \
    outils/gestionnairedialogue.cpp \
    outils/gestionnairefenetres.cpp \
    outils/idgenerator.cpp \
    smtp/emailaddress.cpp \
    smtp/mimeattachment.cpp \
    smtp/mimecontentformatter.cpp \
    smtp/mimefile.cpp \
    smtp/mimehtml.cpp \
    smtp/mimeinlinefile.cpp \
    smtp/mimemessage.cpp \
    smtp/mimemultipart.cpp \
    smtp/mimepart.cpp \
    smtp/mimetext.cpp \
    smtp/quotedprintable.cpp \
    smtp/smtpclient.cpp \
    utilisateur/administrateur.cpp \
    utilisateur/gestionnaireutilisateur.cpp \
    utilisateur/utilisateur.cpp

HEADERS += \
    affichage/fenetre.h \
    affichage/fenetreauthentification.h \
    affichage/fenetrecagnotte.h \
    affichage/fenetreconsultermesdepenses.h \
    affichage/fenetrecontact.h \
    affichage/fenetrecreationcagnotte.h \
    affichage/fenetrecreationgdb.h \
    affichage/fenetredepenses.h \
    affichage/fenetregdb.h \
    affichage/fenetreinscription.h \
    affichage/fenetremenu.h \
    affichage/fenetreprofile.h \
    affichage/fenetrevisucagnotte.h \
    affichage/fenetrevisugdb.h \
    compte/cagnotte.h \
    compte/compte.h \
    compte/gestionnairedebudget.h \
    formulaire/formulaire.h \
    formulaire/formulaireauthentification.h \
    formulaire/formulairecompte.h \
    formulaire/formulairecontact.h \
    formulaire/formulairedepensegdb.h \
    formulaire/formulaireinscription.h \
    formulaire/formulairemenu.h \
    formulaire/formulairemodification.h \
    mainwindow.h \
    model.h \
    outils/basededonnees.h \
    outils/gestionnairedialogue.h \
    outils/gestionnairefenetres.h \
    outils/idgenerator.h \
    smtp/SmtpMime \
    smtp/emailaddress.h \
    smtp/mimeattachment.h \
    smtp/mimecontentformatter.h \
    smtp/mimefile.h \
    smtp/mimehtml.h \
    smtp/mimeinlinefile.h \
    smtp/mimemessage.h \
    smtp/mimemultipart.h \
    smtp/mimepart.h \
    smtp/mimetext.h \
    smtp/quotedprintable.h \
    smtp/smtpclient.h \
    smtp/smtpexports.h \
    utilisateur/administrateur.h \
    utilisateur/gestionnaireutilisateur.h \
    utilisateur/utilisateur.h

FORMS += \
    fenetreauthentification.ui \
    fenetrecagnotte.ui \
    fenetreconsultermesdepenses.ui \
    fenetrecontact.ui \
    fenetrecreationcagnotte.ui \
    fenetrecreationgdb.ui \
    fenetredepenses.ui \
    fenetregdb.ui \
    fenetreinscription.ui \
    fenetremenu.ui \
    fenetreprofile.ui \
    fenetrevisucagnotte.ui \
    fenetrevisugdb.ui \
    mainwindow.ui

TRANSLATIONS += \
    ShareCount_fr_FR.ts
#CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    baseDeDonnees.db \
    text.make

RESOURCES += \
    cagnotte.qrc \
    gestionnaire.qrc \
    images.qrc \
    profile.qrc
