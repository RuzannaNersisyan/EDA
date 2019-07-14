all: generator.cpp task_solving.cpp copy tester.cpp show

generator.cpp: 
	g++ generator.cpp -o generate.exe

task_solving.cpp: 
	g++ task_solving.cpp -o task.exe

copy:	
	@cp task_solving.txt first.txt
	@vim first.txt

tester.cpp:
	g++ tester.cpp -o test.exe

show:
	@vim tested.txt

clean: 
	rm 1.txt 2.txt 3.txt 4.txt task_solving.txt first.txt tested.txt generate.exe task.exe test.exe
 