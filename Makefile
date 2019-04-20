LB = main.o library.o reader.o

main: ${LB} 
	g++ ${LB} -o main

main.o: main.cpp library.hpp reader.hpp
library.o: library.cpp library.hpp
reader.o: reader.cpp library.hpp reader.hpp

clean:
	rm *.o main

