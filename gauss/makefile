.PHONY : clean

start : gauss.exe

gauss.exe : gauss.cpp System.cpp
	g++ $^ -g -o $@

gen : generator.exe

generator.exe : generator.cpp
	g++ $< -o $@

clean : 
	rm *.exe
