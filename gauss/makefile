.PHONY : clean

start : gauss

gauss : gauss.cpp System.cpp
	g++ $^ -g -o $@

gen : generator

generator : generator.cpp
	g++ $< -o $@

clean : 
	rm *.exe
