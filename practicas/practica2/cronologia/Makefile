SRC = src
INC = include
OBJ = obj
LIB = lib
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


#all: $(BIN)/pruebacronologia
all: $(BIN)/test
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Compilación de módulos ************
#$(BIN)/pruebacronologia:
$(BIN)/test : $(OBJ)/test.o $(LIB)/libhistorica.a
	$(CXX) -o $(BIN)/test $(OBJ)/test.o -I$(INC) -L$(LIB) -lhistorica

$(LIB)/libhistorica.a : $(OBJ)/historica.o
	ar rvs $(LIB)/libhistorica.a $(OBJ)/historica.o

$(OBJ)/historica.o : $(SRC)/historica.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/historica.o $(SRC)/historica.cpp -I$(INC)

$(OBJ)/test.o : $(SRC)/test.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/test.o $(SRC)/test.cpp -I$(INC)

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
