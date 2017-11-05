SRC = src
INC = include
OBJ = obj
LIB = lib
BIN = bin
TST = test
CXX = g++
CPPFLAGS = -std=c++11 -Wall -g  -I$(INC) -c


all: $(BIN)/pruebacronologia

#test: $(BIN)/testDinamic $(BIN)/testChronology $(BIN)/testHistoric
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************
$(OBJ)/pruebacronologia.o : $(SRC)/pruebacronologia.cpp $(INC)/dinamicArray.h $(INC)/historicDate.h $(INC)/chronology.h
	$(CXX) $(CPPFLAGS) -I./$(INC) -o $(OBJ)/pruebacronologia.o $(SRC)/pruebacronologia.cpp

$(BIN)/pruebacronologia : $(OBJ)/pruebacronologia.o $(OBJ)/chronology.o $(OBJ)/historicDate.o
	$(CXX) -o $(BIN)/pruebacronologia $(OBJ)/pruebacronologia.o $(OBJ)/chronology.o $(OBJ)/historicDate.o


$(OBJ)/historicDate.o : $(INC)/historicDate.h $(INC)/dinamicArray.h $(SRC)/historicDate.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/historicDate.o $(SRC)/historicDate.cpp

$(OBJ)/chronology.o : $(INC)/chronology.h $(INC)/historicDate.h $(INC)/dinamicArray.h $(SRC)/chronology.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/chronology.o $(SRC)/chronology.cpp


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*

zip: mrproper
	tar -cvzf practica3.tgz .
