#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <string>
#include <cstdio>

void testing(const char* fn1, const char* fn2,std::vector<int>& buf, std::vector<int>& num);
void result(const char* res, const std::vector<int>& buf,const std::vector<int>& num);

int main() {

	std::vector<int> buf, num;
	
	testing("first.txt", "task_solving.txt", buf, num);
	result("tested.txt", buf, num);

	return 0;
}

void testing(const char* fn1, const char* fn2, std::vector<int>& buf, std::vector<int>& num) {
	
	std::ifstream first_file(fn1, std::ios::in);
	std::ifstream task_file(fn2, std::ios::in);
	assert(first_file.is_open());
	assert(task_file.is_open());
	int hold1, hold2;	
	char ch;
	std::string tasm;
	for(int i = 0; i < 2; ++i){
		first_file >> hold1;
		task_file >> hold2;
		if (hold1 == hold2) {
			buf.push_back(1);
			num.push_back(hold1);
		}else{
			buf.push_back(0);
		}
		first_file >> tasm;
		task_file >> tasm;
		
	}
	while(first_file >> ch && task_file >> ch){
		first_file >> hold1;
		task_file >> hold2;
		if(hold1 == hold2) {
			num.push_back(1);
		}else {
			num.push_back(0);
		}
		first_file >> ch; task_file >> ch;
		for(int i = 0; i < num[0]*num[1]; i++) {
			first_file >> hold1;
			task_file >> hold2;
			if(hold1 == hold2) {
				buf.push_back(1);
			}else {
				buf.push_back(0);
			}
		}
	}	
}

void result(const char* res,const std::vector<int>& buf, const std::vector<int>& num){

	std::ofstream test_file(res, std::ios::out);
	assert(test_file.is_open());
	test_file << "\t\t\t_____________________________________________________________________________________________________________" << std::endl;
	test_file << "\t\t\t                                   Found inconsistencies during testing!                                     " << std::endl;
	test_file << "\t\t\t_____________________________________________________________________________________________________________" << std::endl;
	int all_count = 0;
	if(buf[0] == 0 || buf[1] == 0) {
		all_count++;
		test_file << "\t\t\t\tDon't match the matrices dimensions!" << std::endl
			<< "\t\t\t\tIf you want to continue testing, correct the mistakes!" << std::endl;
	}else {
		for(int i = 2; i < num.size(); ++i) {
			if(num[i] == 0) {
				all_count++;
				test_file << "\t\t\t\tIn the files don't match number of matrices -->  \"" << i-1 << "\" " << std::endl;
			}
		}
		int number = 0, s = 2, count = 0;
		for(int i = 2; i < num.size(); ++i) {
			int elem = 1;
			number++;
			for(int j = s; j < num[0]*num[1] + s; ++j) {
				if(buf[j] == 0) {
					all_count++;
					test_file << "\t\t\t\tIn the matrix \"" << number << "\" don't match element --> \"" << elem << "\"" <<std::endl;
				}
				elem++;
			}
			count++;
			s = num[0]*num[1]*count + 2;
		}
	}
	test_file << "\t\t\t_____________________________________________________________________________________________________________" << std::endl;
	test_file << "\t\t\t                                   Don't match | " << all_count << " | elements!                             " << std::endl;
	test_file << "\t\t\t_____________________________________________________________________________________________________________" << std::endl;
}
