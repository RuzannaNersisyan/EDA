#ifndef system_class
#define system_class

#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>

class System {
public:
        void Initialize(unsigned, unsigned);
	~System();
	const double& operator() (unsigned i, unsigned j = 0) const;
	double& operator() (unsigned i, unsigned j = 0);
	unsigned getRows() const { return rows; }
	unsigned getColumns() const  { return columns; }
	void setRows(unsigned r) { rows = r; }
	void setColumns(unsigned c) { columns = c; }
private:
	unsigned rows;
	unsigned columns;
	double **A;
};

class fileReader {
public:
	fileReader(const char*);
	bool elemReading(double&);
	bool numReading(unsigned&);
	bool symbolReading(char&);
	~fileReader();
private:
	const char* readerFile;
	std::ifstream fin;
};

class fileWriter
{
public:
        fileWriter(const char*);
	bool numWriting(double);
	bool sysNumWriting(unsigned);
	bool symbolWriting(char);
	bool stringWriting(std::string);
	~fileWriter();
	unsigned getSystemCounter() { return SystemCounter; }
	void systemCounter();

private:
        const char * writerFile;
	std::ofstream fout;
	unsigned SystemCounter;
};


bool readSystem (System&, System&, fileReader&);
bool writeSystem (System&, fileWriter&);

#endif

