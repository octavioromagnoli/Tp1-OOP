
SRCS2 := $(shell find ej2 -type f -name "*.cpp")
HDRS2 := $(shell find ej2 -type f -name "*.hpp")
OBJS2 := $(SRCS2:.cpp=.o)

SRCS3 := $(shell find ej3 -type f -name "*.cpp") $(shell find ej2/armas ej2/personajes -type f -name "*.cpp")
HDRS3 := $(shell find ej3 -type f -name "*.hpp") $(shell find ej2/armas ej2/personajes -type f -name "*.hpp")
OBJS3 := $(SRCS3:.cpp=.o)

SRCS4 := $(shell find ej4 -type f -name "*.cpp") $(shell find ej2/armas ej2/personajes -type f -name "*.cpp")  $(shell find ej3/PersonajeFactory -type f -name "*.cpp")
HDRS4 := $(shell find ej4 -type f -name "*.hpp") $(shell find ej2/armas ej2/personajes -type f -name "*.hpp") $(shell find ej3/PersonajeFactory -type f -name "*.hpp")
OBJS4 := $(SRCS4:.cpp=.o)

%.o: %.cpp $(HDRS2)
	g++ -Wall -g -c $< -o $@

run2: $(OBJS2)
	g++ -Wall -g $(OBJS2) -o 2
	./2


run3: $(OBJS3)
	g++ -Wall -g $(OBJS3) -o 3
	./3

run4: $(OBJS4)
	g++ -Wall -g $(OBJS4) -o 4
	./4
