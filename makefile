
ARMAS = ej2/armas

run2armas: $(ARMAS)/interfaz/Arma.hpp $(ARMAS)/Magico/Magico.hpp $(ARMAS)/Magico/Magico.cpp ej2/main.cpp
	g++ -Wall -g $(ARMAS)/Magico/Magico.cpp ej2/main.cpp -o 2
	./2