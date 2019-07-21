#include "System.hpp"
#include <cassert>
#include <cstdlib>

System::~System() {
	for(int i = 0; i < getRows(); ++i) {
		assert(A);
		delete [] A[i];
	}
	assert(A);
	delete [] A;
} 
	
const double& System::operator() (unsigned i, unsigned j) const {
        assert(i >= 0 && i < rows && "out of range");
        assert(j >= 0 && j < columns && "out of range");
	return A[i][j];
}

double& System::operator() (unsigned i, unsigned j) {
        assert(i >= 0 && i < rows && "out of range");
        assert(j >= 0 && j < columns && "out of range");
        return A[i][j];
}

fileReader::fileReader(const char* fn)
	: readerFile(fn)
{
	fin.open(readerFile, std::ios::in);
        assert(fin.good() && "cannot read from file");
	std::string s;
        unsigned x;
	if(!(fin >> s && fin >> x)){
		exit(1);
	}
}

bool fileReader::elemReading(double& num) {
        assert(fin.good() && "cannot read from file");
	if (fin >> num) {
		return true;
	}
	else {
		return false;
	}
}

bool fileReader::numReading(unsigned& num) {
        assert(fin.good() && "cannot read from file");
	if (fin >> num) {
		return true;
	}else {
		return false;
	}
}

bool fileReader::symbolReading(char& ch) {
        assert(fin.good() && "cannot read from file");
        if (fin >> ch){
                return true;
	}
	else  {
                return false;
        }
}

fileReader::~fileReader(){
	fin.close();
}

fileWriter::fileWriter(const char* fn)
	: writerFile(fn)
	, SystemCounter(1) {

        fout.open(writerFile, std::ios::out);
	assert(fout.is_open());
	if(!(fout << "Result vector:\n\n")) {
                exit(1);
        }
}

bool fileWriter::numWriting(double num) {
        if (fout << num) {
		return true;
	}
	else{
		return false;
	}
}


bool fileWriter::sysNumWriting(unsigned num) {
	if (fout << num) {
		return true;
	}
	else {
		return false;
	}
}

bool fileWriter::symbolWriting(char ch) {
	if (fout << ch) {
		return true;
	}
	else {
		return false;
	}
}

bool fileWriter::stringWriting(std::string str) {
		if(fout << str) {
			return true;
		}
		else {
			return false;
		}
	}


fileWriter::~fileWriter() {
        fout.close();
}

void fileWriter::systemCounter() {
	++SystemCounter;
}

void System::Initialize(unsigned num1, unsigned  num2)
        {	
                setRows(num1);
		setColumns(num2);
        	A = new double*[num1];
		assert(A);
		for(int i = 0; i < num1; ++i) {
			A[i] = new double[num2];
			assert(A[i]);
		}
        }

bool readSystem(System& S, System& b, fileReader& fr) {
	unsigned num, num1, num2;
	char ch;
	if(fr.symbolReading(ch) && fr.numReading(num))	{
	}
	else {
		return false;
	}
	if(fr.symbolReading(ch) && fr.symbolReading(ch) && fr.numReading(num1) &&
		 fr.symbolReading(ch) && fr.numReading(num2) && fr.symbolReading(ch)) {
	}
        S.Initialize(num1, num2);
	for(int i = 0; i < S.getRows(); ++i) {
		for(int j = 0; j < S.getColumns(); ++j) {
			double n = 0;
			if(fr.elemReading(n)) {
				S(i,j) = n;
			}
			else {
				return false;
			}
		}
	}
        if(fr.symbolReading(ch) && fr.symbolReading(ch) && fr.numReading(num1) &&
		 fr.symbolReading(ch) && fr.numReading(num2) && fr.symbolReading(ch)) {
	        b.Initialize(num1, num2);
		for(int i = 0; i < b.getRows(); ++i) {
			double n = 0;
			if(fr.elemReading(n)) {
				b(i, 0) = n;
			}else {
				return false;
			}
		}
        }else {
                return false;
        }
	return true;
}

bool writeSystem (System& b, fileWriter& fw) {
	if (!fw.symbolWriting('#') || !fw.sysNumWriting(fw.getSystemCounter())
			 || !fw.symbolWriting('\n')) {
		return false;
	 }
	for(int i = 0; i < b.getRows(); ++i) {
		if(!fw.numWriting(b(i, 0)) || !fw.symbolWriting(' ')) {
				return false;
			}
		}
	fw.symbolWriting('\n');
        fw.systemCounter();
	return true;
}
