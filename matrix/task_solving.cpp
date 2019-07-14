#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdio>

	void read_from_file(const char* fn, std::vector<int>& buf);
	void sum_of_matrix(std::vector<int>& b1,const std::vector<int>& b2);
	void mult_of_matrix(const std::vector<int>& b1,const std::vector<int>& b2, std::vector<int>& res);
	void write_to_file(const char* fn,const std::vector<int>&  buf);

int main() {
	
	std::vector<int> buf1, buf2, buf3, buf4, buf5;

	read_from_file("1.txt", buf1);
	read_from_file("2.txt", buf2);
	read_from_file("3.txt", buf3);
	read_from_file("4.txt", buf4);
	sum_of_matrix(buf1, buf2);
	sum_of_matrix(buf3, buf4);
	mult_of_matrix(buf1, buf3, buf5);
	write_to_file("task_solving.txt", buf5);

	return 0;
}

	void read_from_file(const char* fn, std::vector<int>& buf) {
		std::ifstream input_file(fn, std::ios::in);
		assert(input_file);
		int hold;
		char ch;
		std::string temp;
		for(int i=0; i<2; ++i) {
			input_file >> hold;
			buf.push_back(hold);
			input_file >> temp;
		}


		while(input_file >> temp) {
			for(int i = 0; i<buf[0]*buf[1]; i++){
				input_file >> hold;
				buf.push_back(hold);
			}
		}
	}

	void sum_of_matrix(std::vector<int>& b1,const std::vector<int>& b2) {
		int s = std::min(b1.size(), b2.size());
		assert(b1[0]==b2[0] && b1[1]==b2[1]);
		for(int i = 2; i < s; ++i) {
			b1[i] = b1[i] + b2[i];
		}
	}


	void mult_of_matrix(const std::vector<int>& b1,const std::vector<int>&  b2, std::vector<int>& res) {
		assert(b1[1] == b2[0]);
		int size = std::min((b1.size()-2) / (b1[0] * b1[1]), (b2.size() -2)/(b2[0] * b2[1]));
		int s = 0, n = 0, ss = 0, add = 0;
		res.push_back(b1[0]);
		res.push_back(b2[1]);
		while(s < size *std::min(b1[0]*b1[1], b2[0]*b2[1])) {
			for(int k = s; k < b1[0] + s; ++k){
				for(int j = ss; j < b2[1] + ss; ++j){
					int sum = 0, m = 0; 
					for(int i = add; i < b1[1] + add; ++i) {
						sum += b1[i+2]*b2[(m*b2[1] + j) + 2];					
						m++;
					}
					res.push_back(sum);
				}
				add += 3;
			}
			++n;	
			ss = b2[0]*b2[1]*n;
			s = b1[0]*b1[1]*n;
		}
	}


	void write_to_file(const char* fn, const std::vector<int>& buf){
		std::ofstream output_file(fn, std::ios::out);
		assert(output_file);
		output_file << buf[0] << " x " << buf[1] <<"\t(Matrix_dimensions)" << std::endl << std::endl;
		for(int count = 0 ; count < (buf.size() - 2)/(buf[0]*buf[1]); count++){
			int s = buf[0]*buf[1]*count + 2;
			output_file << "<" << count+1 << ">" << std::endl;
			for (int i = s; i < (buf[0]*buf[1]) + s; ++i) {
				output_file << buf[i] << " ";
			}
			output_file  << std::endl << std::endl;		
		}
	}
