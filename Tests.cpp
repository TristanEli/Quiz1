
#include <iostream>

#include "ProfileTableau.hpp"
#include "Tests.hpp"

using namespace std;


int const NBR_TESTS = 6;

double const PONDERATION = 0.5;



/*
  Description des cas de tests.
------------------------------------------------------------------  
  1 : but : tableau avec 2 elements, donc 1 sera les plus accede.
      construit le profile d'acces : { 2, 1 }
      moyenne   = 1.5
	  ecartType = 0.5
	  somme     = 2.0
	  
	  case avec egal ou plus de 2.0 : { 0 }
------------------------------------------------------------------  
  2 : but : les elements a la fin du tableau sont les plus accedes.
      construit le profile d'acces : { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 }
      moyenne   = 10.5
	  ecartType =  5.76628
	  somme     = 16.26628
	  
	  case avec egal ou plus de 16.26628 : { 16, 17, 18, 19 }
------------------------------------------------------------------  
  3 : but : les elements au debut du tableau sont les plus accedes.
      construit le profile d'acces : { 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 }
      moyenne   = 10.5
	  ecartType =  5.76628
	  somme     = 16.26628
	  
	  case avec egal ou plus de 16.26628 : { 0, 1, 2, 3 }
------------------------------------------------------------------  
  4 : but : les elements ont 0 acces, donc ils sont tous plus accedes.
      construit le profile d'acces : { 0, 0, 0, 0, 0 }
      moyenne   = 0.0
	  ecartType = 0.0
	  somme     = 0.0
	  
	  case avec egal ou plus de 0.0 : { 0, 1, 2, 3, 4 }
------------------------------------------------------------------
  5 : but : les elements les plus accedes ne sont pas consecutif dans le tableau.
      construit le profile d'acces : { 5, 1, 2, 2, 2, 2, 3, 2, 2, 2,
									   3, 1, 3, 1, 3, 3, 2, 1, 3, 1,
									   3, 3, 2, 1, 3, 2, 2, 2, 3, 1,
									   4, 1, 2, 2, 2, 3, 3, 1, 2, 2,
									   3, 1, 4, 1, 2, 3, 2, 1, 3, 2,
									   3, 2, 2, 1, 3, 2, 3, 2, 2, 1,
									  }
      moyenne   = 2.18333
	  ecartType = 0.884904
	  somme     = 3.068124
	  
	  case avec plus de 3.068124 : { 0, 30, 42 }
------------------------------------------------------------------
  6 : but : il y a une demande d'ecart type durant la construction du tableau,
             ce qui ne devrait pas changer les resultats.
      construit le profile d'acces : { 5, 1, 2, 2, 2, 2, 3, 2, 2, 2,
									   3, 1, 3, 1, 3, 3, 2, 1, 3, 1,
									   3, 3, 2, 1, 3, 2, 2, 2, 3, 1,
									   4, 1, 2, 2, 2, 3, 3, 1, 2, 2,
									   3, 1, 4, 1, 2, 3, 2, 1, 3, 2,
									   3, 2, 2, 1, 3, 2, 3, 2, 2, 1,
									  }
      moyenne   = 2.18333
	  ecartType = 0.884904
	  somme     = 3.068124
	  
	  case avec plus de 3.068124 : { 0, 30, 42 }
------------------------------------------------------------------
*/


/////////////////////////////////////////////////////////////////
// type de donnée pour décrire la fonction qui prépare le tableau 
// a tester.

typedef ProfileTableau * (*FonctionConstructionProfile)( void );


/////////////////////////
// données pour le test 1

int const NBR_CAS_TEST_1 = 2;
int RESULTATS_ATTENDU_TEST_1[ NBR_CAS_TEST_1 ] = { 0, -1 };

ProfileTableau * 
constructionProfileTest1( void )
{
    ProfileTableau * tab = new ProfileTableau( 2 );

    int i = 0;
	for( i = 0; i < tab->taille(); ++ i )
	{
		(*tab)[i] = 1;
	}
	(*tab)[0] = 0;
	
	return tab;
}


/////////////////////////
// données pour le test 2

int const NBR_CAS_TEST_2 = 5;
int RESULTATS_ATTENDU_TEST_2 [ NBR_CAS_TEST_2 ] = { 16, 17, 18, 19, -1 };

ProfileTableau * 
constructionProfileTest2( void )
{
    ProfileTableau * tab = new ProfileTableau( 20 );
	int i = 0;
	int j = 0;
	
	for( i = 0; i < tab->taille(); ++ i )
	{
	    for( j = i; j < tab->taille(); ++ j ) 
		{
			(* tab)[j] = 1;
		}
	}
	
	return tab;
}


/////////////////////////
// données pour le test 3

int const NBR_CAS_TEST_3 = 5;
int RESULTATS_ATTENDU_TEST_3 [ NBR_CAS_TEST_3 ] = { 0, 1, 2, 3, -1 };

ProfileTableau * 
constructionProfileTest3( void )
{
    ProfileTableau * tab = new ProfileTableau( 20 );
    int i = 0;
	int j = 0;
	
	for( i = 0; i < tab->taille(); ++ i )
	{
	    for( j = 0; j <= i; ++ j ) 
		{
			(* tab)[j] = 1;
		}
	}
	
	return tab;
}
	

/////////////////////////
// données pour le test 4

int const NBR_CAS_TEST_4 = 6;
int RESULTATS_ATTENDU_TEST_4 [ NBR_CAS_TEST_4 ] = { 0, 1, 2, 3, 4, -1 };

ProfileTableau * 
constructionProfileTest4( void )
{
    ProfileTableau * tab = new ProfileTableau( 5 );

	return tab;
}


/////////////////////////
// données pour le test 5

int const NBR_CAS_TEST_5 = 4;
int RESULTATS_ATTENDU_TEST_5 [ NBR_CAS_TEST_5 ] = { 0, 30, 42, -1 };

ProfileTableau * 
constructionProfileTest5( void )
{
    ProfileTableau * tab = new ProfileTableau( 60 );

    int i = 0;
	int j = 0;
	
	for( i = 0; i < tab->taille(); ++ i )
	{
		(* tab)[i] = 1;
		if( 0 == i % 2 ) 
		{
			(* tab)[i] = 1;
		}
		if( 0 == i % 3 ) 
		{
			(* tab)[i] = 1;
		}
		if( 0 == i % 5 ) 
		{
			(* tab)[i] = 1;
		}
		if( 0 == i % 7 ) 
		{
			(* tab)[i] = 1;
		}
	}
	
	return tab;
}
	

/////////////////////////
// données pour le test 6

int const NBR_CAS_TEST_6 = 4;
int RESULTATS_ATTENDU_TEST_6 [ NBR_CAS_TEST_6 ] = { 0, 30, 42, -1 };

ProfileTableau * 
constructionProfileTest6( void )
{
    ProfileTableau * tab = new ProfileTableau( 60 );
    int i = 0;
	int j = 0;

	for( i = 0; i < tab->taille(); ++ i )
	{
		(* tab)[i] = 1;
		if( 0 == i % 2 ) 
		{
			(* tab)[i] = 1;
		}
		if( 0 == i % 3 ) 
		{
			(* tab)[i] = 1;
		}
	}

	tab->ecartType(); 
	
	for( i = 0; i < tab->taille(); ++ i )
	{
		if( 0 == i % 5 ) 
		{
			(* tab)[i] = 1;
		}
		if( 0 == i % 7 ) 
		{
			(* tab)[i] = 1;
		}
	}
	
	return tab;
}


/*
     fin de la description des tests.
------------------------------------------------------------------
*/

/////////////////////////////////////////
// Accumuler les tests dans une structure

class DescriptionTest{
	double verifier( int * ) const;
public :
    string id;
    FonctionConstructionProfile fProfile;
    int nbrCas;
	int * resultatsAttendus;
	double ponderation;
	
	double tester( void ) const;
};

double 
DescriptionTest::verifier( int * resultats ) const
{
	double somme = 0.0;
	int i = 0;
	
	for( i = 0; i < nbrCas; ++ i )
	{
		if( resultatsAttendus[i] == resultats[i] )
		{
			somme += 1.0;
		}
		else
		{
			cerr << "Le test "
				 << id
				 << "."
				 << i
				 << " a donne " 
				 << resultatsAttendus[i]
				 << " alors qu'il devait donner "
				 << resultats[i]
				 << "."
				 << endl;
		}
	}
	
	return somme;
}


double 
DescriptionTest::tester( void ) const
{
	cout << endl 
	     << "Lancement du test " 
		 << id 
		 << endl;

    ProfileTableau * tab = fProfile();
	int * prof = tab->indicesPlusUtilises();
	
	double somme = verifier( prof );
	
	double points = ( somme / nbrCas ) * ponderation;
	cout << somme 
	     << "/" 
		 << nbrCas 
		 <<  " -> " 
		 << points 
		 << " / "
         << ponderation		 
		 << endl;
	
	delete tab;
	tab = nullptr;
	
	return points;
}



/////////////////////
// Tous les tests.

DescriptionTest const TESTS[ NBR_TESTS ] =
{
    { "1", constructionProfileTest1, NBR_CAS_TEST_1, RESULTATS_ATTENDU_TEST_1, PONDERATION },
    { "2", constructionProfileTest2, NBR_CAS_TEST_2, RESULTATS_ATTENDU_TEST_2, PONDERATION },
    { "3", constructionProfileTest3, NBR_CAS_TEST_3, RESULTATS_ATTENDU_TEST_3, PONDERATION },
    { "4", constructionProfileTest4, NBR_CAS_TEST_4, RESULTATS_ATTENDU_TEST_4, PONDERATION },
    { "5", constructionProfileTest5, NBR_CAS_TEST_5, RESULTATS_ATTENDU_TEST_5, PONDERATION },
    { "6", constructionProfileTest6, NBR_CAS_TEST_6, RESULTATS_ATTENDU_TEST_6, PONDERATION }
};






void 
lancerTests( void )
{
    double somme = 0.0;
	double maximumPossible = 0.0;
	int i = 0;
	
	for( i = 0; i < NBR_TESTS; ++ i ) 
	{    
		DescriptionTest const & description = TESTS[ i ];
		somme += description.tester();
		maximumPossible += description.ponderation;
	}
	
	cout << endl
	     << "total : "
	     << somme
	     << " / " 
	     << maximumPossible
	     << endl;
}
