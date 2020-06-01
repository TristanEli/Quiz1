
NOM=pTri

FLAGS=-DNDEBUG
CC= g++

OBJ=$(NOM).o AlgorithmesTri.o ProfileTableau.o Tests.o


.cpp.o :
	$(CC) $(FLAGS) -c $<

$(NOM) : $(OBJ)
	$(CC) -o $(NOM) $(OBJ)


AlgorithmesTri.cpp : AlgorithmesTri.hpp ProfileTableau.hpp

ProfileTableau.cpp : ProfileTableau.hpp

Tests.cpp : Tests.hpp ProfileTableau.hpp

$(NOM).cpp : AlgorithmesTri.hpp Constantes.hpp ProfileTableau.hpp Tests.hpp

clean :
	\rm -f *.o
	\rm -f $(NOM)
