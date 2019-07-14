#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cassert>

void generate1(const char* fn, int row, int column, int n);
void generate2(const char* fn, int row, int column, int n);

int main () {

    int n, row, column, column2;
    std::cout << "Enter count of matrices for files: ";
    std::cin >> n;
    std::cout << std::endl << "Enter matrix dimensions. row1: ";
    std::cin >> row;
    std::cout << "\n\tcolumn1 and row2: " ;
    std::cin >> column;
    std::cout << "\n\tcolumn2: " ;
    std::cin >> column2;

    generate1("1.txt", row, column, n);
    generate1("2.txt", row, column, n);
    generate2("3.txt", column, column2, n);
    generate2("4.txt", column, column2, n);

    return 0;

}



void generate1(const char* fn, int row, int column, int n) {
    std::ofstream gen_file(fn, std::ios::out);
    assert(gen_file);
    int gen;
    gen_file <<  row <<  " x " << column << "\t(Matrix_dimensions)" << std::endl << std::endl;
        srand(time(NULL));
    for(int i = 1; i <= n; ++i) {
        gen_file << "<" << i << ">" << std::endl;
        for(int j = 0; j < row*column; ++j) {
            gen = rand() % 20 - 10;
            gen_file << gen <<  " " ;
        }
        gen_file << std::endl;
    }

}


void generate2(const char* fn, int column, int column2, int n) {
    std::ofstream gen_file(fn, std::ios::out);
    assert(gen_file);
    int gen;
    gen_file <<  column <<  " x " << column2 << "\t(Matrix_dimensions)" << std::endl << std::endl;
        srand(time(NULL));
    for(int i = 1; i <= n; ++i) {
        gen_file << "<" << i << ">" << std::endl;
        for(int j = 0; j < column*column2; ++j) {
            gen = rand() % 20 - 10;
            gen_file << gen <<  " " ;
        }
        gen_file << std::endl;
    }

}

