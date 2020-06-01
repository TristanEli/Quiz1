

#include "AlgorithmesTri.hpp"

void
triSelection( ProfileTableau & tab )
{
    int i = 0;
    int j = 0;
    
    for( i = 0; i < tab.taille() - 1; ++ i )
    {
        int position = i;
        int minima = tab[i];
        
        for( j = i + 1; j < tab.taille(); ++ j ) 
        {
            if( tab[j] < minima )
            {
                position = j;
                minima = tab[j];
            }
        }
        
        tab[position] = tab[i];
        tab[i] = minima;
    }        
}


void
triInsertion( ProfileTableau & tab )
{
    int i = 0;
    int j = 0;
    
    for( i = 1; i < tab.taille(); ++ i )
    {
        j = i - 1;
        int temp = tab[i];
        
        while( 0 <= j && temp < tab[j] ) 
        {
            tab[j+1] = tab[j];
            -- j;
        }
        tab[j+1] = temp;
    }
}


void 
triBulle( ProfileTableau & tab )
{
	bool estTrie = false;
	int fin = tab.taille();

	while( ! estTrie ) {
		estTrie = true;
		for( int i = 0; i < fin; ++ i ) {
			if( tab[i + 1] < tab[i] ) {
				int temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
				estTrie = false;
			}
		}
		-- fin;
	}
}


void 
triRapide( ProfileTableau & tab, int debut, int fin )
{
	if( debut < fin ) {
		int pivot = tab[ ( debut + fin ) / 2 ];
		int i = debut - 1;
		int j = fin + 1;
		
		while( i < j ) {
			do -- j; while( pivot < tab[j] );
			do ++ i; while( tab[i] < pivot );
			
			if( i < j ) {
				int temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
		}
		
		triRapide( tab, debut, j );
		triRapide( tab, j + 1, fin );
	}
}


void 
triRapide( ProfileTableau & tab )
{
	triRapide( tab, 0, tab.taille() - 1 );
}
