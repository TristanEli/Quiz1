
#include <cassert>
#include <cmath>

#include "ProfileTableau.hpp"

using namespace std;

ProfileTableau::ProfileTableau( int a_nbrElement )
: _contenue( new int[ a_nbrElement ] ),
  _nbrAcces( new double[ a_nbrElement ] ),
  _estValideNbrAccesMoyen( false ),
  _taille( a_nbrElement )
{
	assert( 0 < a_nbrElement );

    for( int i = 0; i < a_nbrElement; ++ i )
    {
        _nbrAcces[ i ] = 0.0;
    }
}


ProfileTableau::~ProfileTableau( void )
{
    delete [] _contenue;
    _contenue = nullptr;
    delete [] _nbrAcces;
    _nbrAcces = nullptr;
}


int & 
ProfileTableau::operator []( int a_position ) 
{
	assert( 0 <= a_position );
	assert( a_position < _taille );
	
    _estValideNbrAccesMoyen = false;
    ++ _nbrAcces[ a_position ];
    return _contenue[ a_position ];
}
    

int 
ProfileTableau::taille( void ) const
{
    return _taille;
}


double 
ProfileTableau::nbrAcces( int a_position ) const
{
	assert( 0 <= a_position );
	assert( a_position < _taille );
	
    return _nbrAcces[ a_position ];
}


double 
ProfileTableau::nbrAccesMoyen( void )
{
	if( ! _estValideNbrAccesMoyen )
	{
	    int i = 0;
		double somme = 0.0;
		
		for( i = 0; i < _taille; ++i ) 
		{
			somme += _nbrAcces[ i ];
		}
		
		_nbrAccesMoyen = somme / _taille;
		_estValideNbrAccesMoyen = true;
		_estValideEcartType = false;
	}
	
	return _nbrAccesMoyen;
}


double 
ProfileTableau::ecartType( void )
{
    double moyenne = nbrAccesMoyen();
	
	if( ! _estValideEcartType )
	{
		int i = 0;
		double somme = 0.0;
		
		for( i = 0; i < _taille; ++ i )
		{
		    double ecart = _nbrAcces[ i ] - moyenne;
			somme += ( ecart * ecart );
		}
		
		_ecartType = sqrt( somme / _taille );
		_estValideEcartType = true;
	}
	
	return _ecartType;
}


int * 
ProfileTableau::indicesPlusUtilises( void ){

int * tabIndices;
double bareme = ecartType() + nbrAccesMoyen();
int compteur=0;
int compteur2=0;

//Parcourir le tableau et trouver le nombre de cases qui repondent au criteres
	for (int i = 0; i < _taille; i++){
		if (_nbrAcces[i] >= bareme){
			compteur++;
			}
		}
//Allocation dynamique du tableau dentier qui pourra contenir les indices
tabIndices = new int[compteur+1];
//S il y a des elements qui correspondent aux exigences on procede au remplissage du tableau
	if (compteur!=0) {
		for (int i = 0; i < _taille; i++){
			if (_nbrAcces[i] >= bareme){
				tabIndices[compteur2] = i;
				compteur2++;
			}
		}
	}	
//Mettre le dernier indice a -1
	tabIndices[compteur] = -1;
	return tabIndices;
}
