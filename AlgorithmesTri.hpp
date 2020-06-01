
#ifndef _ALGORITHMES_TRI_HPP
#define _ALGORITHMES_TRI_HPP

#include "ProfileTableau.hpp"

typedef void (* FonctionTri )( ProfileTableau & );

void triSelection( ProfileTableau & tab );

void triInsertion( ProfileTableau & tab );

void triBulle( ProfileTableau & tab );

void triRapide( ProfileTableau & tab );

#endif
