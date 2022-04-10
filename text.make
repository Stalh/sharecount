#
#Makefile pour compiler et exécuter le projet
#

TEST = console.cpp
FILES =     compte/cagnotte.cpp compte/compte.cpp compte/gestionnairedebudget.cpp formulaire/formulaire.cpp outils/idgenerator.cpp
FILES +=	utilisateur/administrateur.cpp
FILES +=	utilisateur/gestionnaireutilisateur.cpp
FILES +=	formulaire/formulaireInscription.cpp
FILES +=	utilisateur/utilisateur.cpp $(TEST)
DOX_FL = Doxyfile
DOC_FL = $(FILES)  $(DOX_FL)

1a:	$(FILES)
	g++ -std=c++11 -Wall -Wextra -pedantic -o  $@ $(FILES)

doc:	$(DOC_FL)
	doxygen $(DOX_FL)

clean:	clean_doc
	\rm -f *~ *.o 1a

clean_doc:
	\rm -Rf html/*
