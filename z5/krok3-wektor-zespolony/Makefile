CXXFLAGS= -c -g -std=c++11 -iquote inc -Wall -pedantic
TRGDIR=./
OBJ=obj

__start__: ${TRGDIR}/test_wektora
	${TRGDIR}/test_wektora

${OBJ}:
	mkdir -p ${OBJ}

${TRGDIR}/test_wektora: ${OBJ} ${OBJ}/main.o ${OBJ}/LZespolona.o
	g++ -o ${TRGDIR}/test_wektora ${OBJ}/main.o ${OBJ}/LZespolona.o

${OBJ}/main.o: src/main.cpp inc/SWektor.hh inc/SUkladRownanLiniowych.hh inc/SMacierz.hh inc/LZespolona.hh
	g++ -c ${CXXFLAGS} -o ${OBJ}/main.o src/main.cpp


${OBJ}/LZespolona.o: src/LZespolona.cpp inc/LZespolona.hh
	g++ -c ${CXXFLAGS} -o ${OBJ}/LZespolona.o src/LZespolona.cpp

clean:
	rm -f obj/*.o test_wektora
