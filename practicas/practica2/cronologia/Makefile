SRC = src
INC = include
OBJ = obj
LIB = lib
BIN = bin
TST = test
CXX = g++
CPPFLAGS = -std=c++11 -Wall -g  -I$(INC) -c


#all: $(BIN)/pruebacronologia

test: $(BIN)/testDinamic $(BIN)/testChronology $(BIN)/testHistoric
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************
#$(BIN)/pruebacronologia:

#$(OBJ)/Darray.o : $(SRC)/dinamicArray.cpp $(INC)/dinamicArray.h  $(INC)/historicDate.h
#	$(CXX) $(CPPFLAGS) -o $(OBJ)/Darray.o $(SRC)/dinamicArray.cpp

$(OBJ)/historicDate.o : $(INC)/historicDate.h $(INC)/dinamicArray.h $(SRC)/historicDate.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/historicDate.o $(SRC)/historicDate.cpp

$(OBJ)/chronology.o : $(INC)/chronology.h $(INC)/historicDate.h $(INC)/dinamicArray.h $(SRC)/chronology.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/chronology.o $(SRC)/chronology.cpp


# ************ Tests ***************


$(OBJ)/testDinamic.o : $(TST)/testDinamic.cpp $(INC)/dinamicArray.h
	$(CXX) $(CPPFLAGS) -I./$(INC) -o $(OBJ)/testDinamic.o $(TST)/testDinamic.cpp

$(BIN)/testDinamic : $(OBJ)/testDinamic.o
	$(CXX) -o $(BIN)/testDinamic $(OBJ)/testDinamic.o


$(OBJ)/testHistoric.o : $(TST)/testHistoric.cpp $(INC)/dinamicArray.h $(INC)/historicDate.h
	$(CXX) $(CPPFLAGS) -I./$(INC) -o $(OBJ)/testHistoric.o $(TST)/testHistoric.cpp

$(BIN)/testHistoric : $(OBJ)/testHistoric.o $(OBJ)/historicDate.o
	$(CXX) -o $(BIN)/testHistoric $(OBJ)/testHistoric.o $(OBJ)/historicDate.o


$(OBJ)/testChronology.o : $(TST)/testChronology.cpp $(INC)/dinamicArray.h $(INC)/historicDate.h $(INC)/chronology.h
	$(CXX) $(CPPFLAGS) -I./$(INC) -o $(OBJ)/testChronology.o $(TST)/testChronology.cpp

$(BIN)/testChronology : $(OBJ)/testChronology.o $(OBJ)/chronology.o $(OBJ)/historicDate.o
	$(CXX) -o $(BIN)/testChronology $(OBJ)/testChronology.o $(OBJ)/chronology.o $(OBJ)/historicDate.o

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
