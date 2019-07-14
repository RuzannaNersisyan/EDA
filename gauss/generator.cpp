#include <iostream>
#include <fstream>
#include "System.hpp"
#include <cstdlib>
#include <ctime>
#include <cassert>

void generate_A(const char*, int, int, unsigned);
void generate_b(const char*, int); 

int main() {

	unsigned count, counter;
	srand(time(NULL));
	
	std::ofstream fout("systems.txt", std::ios::out);
	std::cout << "Enter a count of systems: ";
	std::cin >> count;
	assert(fout.good());
	fout << "Systems_count: ";
	assert(fout.good());
	fout << count;
	assert(fout.good());
	fout << std::endl;
	for(int i = 0; i < count; ++i) {
		int rows = rand() % 50 + 1;
		int columns = rand() % 50 + 1;
		counter = i + 1;
		generate_A("systems.txt", rows, columns, counter);
		generate_b("systems.txt", rows);
	}
	return 0;
}

void generate_A(const char* fn, int r, int c, unsigned counter) {
	std::ofstream gen_A(fn, std::ios::app);
	assert(gen_A.good());
	gen_A << "#";
	assert(gen_A.good());
	gen_A << counter; 
	assert(gen_A.good());
	gen_A << "\n";
	assert(gen_A.good());
	gen_A << "A( ";
	assert(gen_A.good());
	gen_A << r;
	assert(gen_A.good());
	gen_A << " x ";
	assert(gen_A.good());
	gen_A << c;
	assert(gen_A.good());
	gen_A << " )\n";
	for(int i = 0; i < r; ++i) {
		for(int j = 0; j < c; ++j) {
			assert(gen_A.good());
			gen_A << rand() % 100 - 50;
			assert(gen_A.good());
			gen_A << " ";
		}
		assert(gen_A.good());
		gen_A << "\n\n" ;
	}
}

void generate_b(const char* fn, int r) {
	std::ofstream gen_b(fn, std::ios::app);
	assert(gen_b.good());
	gen_b << "b( ";
	assert(gen_b.good());
	gen_b << r;
	assert(gen_b.good());
	gen_b << " x ";
	assert(gen_b.good());
	gen_b << "1";
	assert(gen_b.good());
	gen_b << " )\n";
	for(int i = 0; i < r; ++i) {
		assert(gen_b.good());
		gen_b << rand() % 100 - 50;
		assert(gen_b.good());
		gen_b << " ";
	}
	assert(gen_b.good());
	gen_b << "\n\n";
}
