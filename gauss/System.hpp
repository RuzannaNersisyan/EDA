#ifndef system_class
#define system_class

#include <vector>
#include <cstring>
#include <fstream>
#include <iostream>

class System {
public:
        System() {}
        void Initialize(unsigned, unsigned);
        void Initialize(unsigned);
	const double& operator() (unsigned i, unsigned j = 0) const;
	double& operator() (unsigned i, unsigned j = 0);
	const double& operator[] (unsigned) const;
	double& operator[] (unsigned);
	unsigned getRows() const { return rows; }
	unsigned getColumns() const  { return columns; }
	unsigned getSystemNumber() const { return SystemNumber; }
	void setSystemNumber(unsigned n) { SystemNumber = n; }
	void setRows(unsigned r) { rows = r; }
	void setColumns(unsigned c) { columns = c; }
private:
	unsigned rows;
	unsigned columns;
	unsigned SystemNumber;
	std::vector<double> b;
	std::vector<std::vector<double> > A;
};

class fileReader {
public:
	fileReader(const char*);
	bool elemReading(double&);
	bool numReading(unsigned&);
	bool symbolReading(char&);
	void getStr(std::string);
	~fileReader();
	unsigned getRowsValue() { return SystemRows; }
        unsigned getColumnsValue() { return SystemColumns; }
private:
	const char* readerFile;
	std::ifstream fin;
	unsigned SystemRows;
	unsigned SystemColumns;
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
	unsigned SystemRows;
	unsigned SystemColumns;
	unsigned SystemCounter;
};


bool readSystem (System&, System&, fileReader&);
bool writeSystem (const System&, fileWriter&);

#endif

