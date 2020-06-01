
#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <utility>

#include "AlgorithmesTri.hpp"
#include "Constantes.hpp"
#include "ProfileTableau.hpp"
#include "Tests.hpp"

using namespace std;


class Arguments
{
private :
    void identifierLettre( string );
    void identifierLettreTri( string );
public :
    FonctionTri trier;
    int taille;
    bool demandeAide;
    bool demandeTest;
    Arguments( int argn, char * argv [] );
};



Arguments::Arguments( int argn, char * argv [] ) 
  : demandeAide( false ),
    demandeTest( false )
{
    int i = 0;
    int nombreTrouve = 0;
    size_t position;

    for( i = 1; i < argn; ++ i ) 
    {
        string arg( argv[i] );
        try 
        {
            taille = stoi( arg, &position );
            if( taille <= 0 ) 
            {
                cerr << MSSG_ERREUR_TAILLE_INVALIDE
                     << MSSG_SEPARATEUR_ERREUR 
                     << taille
                     << endl;
                exit( NUMERO_ERREUR_TAILLE_INVALIDE );
            }
        }
        catch( invalid_argument e )
        {
            identifierLettre( arg );
            ++ nombreTrouve;
        }
        if( 1 != nombreTrouve )
        {
            cerr << MSSG_ERREUR_NOMBRE_ARG_INVALIDE
                 << MSSG_SEPARATEUR_ERREUR 
                 << nombreTrouve
                 << endl;
            exit( NUMERO_ERREUR_NOMBRE_ARG_INVALIDE );
        }
    }
}


void 
Arguments::identifierLettre( string arg )
{
    if( ARG_AIDE == arg )
    {
        demandeAide = true;
    } 
    else if( ARG_TESTS == arg )
    {
        demandeTest = true;
    }
    else
    {
        identifierLettreTri( arg );
    }
}


void
Arguments::identifierLettreTri( string arg )
{
    int j = 0;
    while( j < NOMBRES_TRI && TRI[j].first != arg )
    {
        ++ j;
    }
    
    if( NOMBRES_TRI == j )
    {
        cerr << MSSG_ERREUR_ARGUMENT_INVALIDE
             << MSSG_SEPARATEUR_ERREUR 
             << arg
             << endl;
        exit( NUMERO_ERREUR_ARGUMENT_INVALIDE );
    }
    
    trier = TRI[j].second;
}



void remplirTableau( ProfileTableau & tab )
{
    unsigned depart = chrono::system_clock::now()
                      .time_since_epoch()
                      .count();
    default_random_engine generateur( depart );
    uniform_int_distribution< int > 
        intervale( - tab.taille(), tab.taille() );

    int i = 0;
    
    for( i = 0; i < tab.taille(); ++ i ) 
    {
        tab[i] = intervale( generateur );
    }
}


void afficherStatistique( ProfileTableau & tab )
{
    int i = 0;
    int * indices = tab.indicesPlusUtilises();

    cout << MSSG_PRESENTATION_MOYENNE << tab.nbrAccesMoyen() << endl;
    cout << MSSG_PRESENTATION_ECART_TYPE << tab.ecartType() << endl;
    cout << endl;
 
    cout << MSSG_PRESENTATION_INDICES;
    i = 0;
    while( -1 != indices[i] )
    {
        cout << ( 0 == i ? "" : MSSG_SEPARATEUR_INDICE )
             << indices[i] ;             
        ++ i;
    }
    cout << endl;
    
    delete [] indices;
    indices = nullptr;
}


void
lancerTri( Arguments args ) 
{
    ProfileTableau tab( args.taille );
    remplirTableau( tab );

    args.trier( tab );
    afficherStatistique( tab );
}


void
afficherMessageAide( void )
{
    cout << MSSG_AIDE << endl;
}


int
main( int argn, char * argv [] )
{
    Arguments args( argn, argv );
    
    if( args.demandeAide )
    {
        afficherMessageAide();
    } 
    else if( args.demandeTest )
    {
        lancerTests();
    }
    else
    {
        lancerTri( args );
    }
    
    return 0;
}




