SRC = src
INC = include
OBJ = obj
LIB = lib
BIN = bin
TST = test
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


#all: $(BIN)/pruebacronologia

test: $(TST)/test
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************
#$(BIN)/pruebacronologia:

$(OBJ)/Darray.o : $(SRC)/dinamicArray.cpp $(INC)/dinamicArray.h
	$(CXX) $(CPPFLAGS) -I./$(INC) -o $(OBJ)/Darray.o $(SRC)/dinamicArray.cpp 


# ************ Tests ***************


$(OBJ)/test.o : $(TST)/test.cpp $(INC)/dinamicArray.h
	$(CXX) $(CPPFLAGS) -I./$(INC) -o $(OBJ)/test.o $(TST)/test.cpp


$(TST)/test : $(OBJ)/test.o $(OBJ)/Darray.o 
	$(CXX) -o $(BIN)/test $(OBJ)/test.o $(OBJ)/Darray.o 


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
