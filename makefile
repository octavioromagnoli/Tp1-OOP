
SRCS2 := $(shell find ej2 -type f -name "*.cpp")
HDRS2 := $(shell find ej2 -type f -name "*.hpp")
OBJS2 := $(SRCS2:.cpp=.o)

%.o: %.cpp $(HDRS2)
	g++ -Wall -g -c $< -o $@

run2: $(OBJS2)
	g++ -Wall -g $(OBJS2) -o 2
	./2