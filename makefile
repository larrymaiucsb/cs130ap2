all: project2_first.out 

project2_first.out: Dictionary.cpp hash24.cpp project2_first.cpp
	g++ -std=c++11 $^ -o $@

project2_second.out: Dictionary.cpp hash24.cpp 
	g++ -std=c++11 $^ -o $@

clean:
	rm -f *.out