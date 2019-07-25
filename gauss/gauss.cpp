#include "System.hpp"

void straightStep(System&, System&);
void backwordStep(System&, System&);
bool check(System&, System&);

unsigned count = 0;

int main() {
	fileReader fr("systems.txt");
	fileWriter fw("result.txt");

	System A;
	System b;
	while(readSystem(A, b, fr)) {
		straightStep(A, b);
		if(!check(A, b)) {
			if(fw.symbolWriting('#') && fw.sysNumWriting(fw.getSystemCounter()) 
					&& fw.symbolWriting('\n')) {
				fw.systemCounter();
				fw.stringWriting("No solutions!");
				fw.symbolWriting('\n');
				fw.symbolWriting('\n');
			}
		}else {
			backwordStep(A, b);
			writeSystem(b, fw);
			fw.symbolWriting('\n');
			if(count == 1) {
				fw.stringWriting("Solution set for private case!");
				fw.symbolWriting('\n');
				fw.symbolWriting('\n');
			}
		}
	}
	return 0;
}

void straightStep(System& A, System& b) {
	for(int i = 0; i < A.getRows()-1; ++i) {
		double del;
		int change = 0;
		for(int l = i+1; l < A.getRows(); ++l){
			if(i < A.getColumns()) {
				del = -(A(l, i)) / A(i, i);
			}
			for(int j = i; j < A.getColumns(); ++j) {
				if(i == j && A(i,j) == 0) {
					double bigger = 0;
					std::cout << i+1 << " i+1 " << std::endl;
					if(A(i+1, j) != 0) {
						bigger = A(i+1, j);
					//	std::cout << bigger << " bigger " << l << std::endl;
						change = i+1;
					}
					for(unsigned k = i+2; k < A.getRows(); ++k) {
						if(A(k, j) != 0) {
							if(A(k, j) > bigger) {
								bigger = A(k, j);
								change = k;
							}else if(A(k, j) < bigger && bigger == 0) {
								bigger = A(k,j);
								std::cout << bigger << " bigger " << l << std::endl;
								change = k;
							}
						}
					}
					if(bigger != 0) {
						double middle;
						for(int j = 0; j < A.getColumns(); ++j) {
							middle = A(i,j);
							A(i,j) = A(change,j);
							A(change,j) = middle;
						}
						middle = b(i);
						b(i) = b(change);
						b(change) = middle;
					}
				}
				A(l,j) += A(i,j) * del;
				std::cout << A(l, j) << " A " << l << std::endl;
			}
			b(l) += b(i) * del;
			std::cout << b(l) << " b " << std::endl;
		}
		if(i >= A.getColumns()) {
			int k = A.getColumns() - 1;
			double d = -(A(i, k)) / A(k, k);
			A(i+1, k) += A(k, k) * d;
			b(i+1) += b(i) * d;
		}
	}
}

bool check(System& A, System& b) {
	if(A.getRows() <= A.getColumns()) {
		int i = A.getRows()-1;
		if(A(i, i) != 0) {
			return true;
		}
		else if(A(i, i) == 0 && b(i) == 0) {
			A.setRows(A.getRows()-1);
			b.setRows(b.getRows()-1);
			count = 1;
			return true;
		}else if(A(i, i) == 0 && b(i) != 0){
			return false;
		}
	}
	if(A.getRows() > A.getColumns()) {
		std::cout << "11" << std::endl;
		for(unsigned i = (A.getRows()-1); i >= (A.getColumns()-1); --i) {
			std::cout << A.getRows()-1 << " row" << std::endl;
			std::cout << A.getColumns()-1 << " col" << std::endl;
			if(i == (A.getColumns()-1)) {
				std::cout << "11" << std::endl;
				if(A(i, i) == 0) {
					if(b(i) == 0) { 
						A.setRows(i);
						std::cout << "11" << std::endl;
						return true;
					}else { 
						std::cout << "11" << std::endl;
						return false; 
					}
				}else {
					std::cout << "11" << std::endl;
					return true; }
			}
			if(b(i) != 0) {
				std::cout << b(i) << " b" << std::endl;
				return false;
			}
		}
		A.setRows(A.getColumns());
	}
	return true;
}

void backwordStep(System& A, System& b) {
	int k = A.getRows()-1; 
	b(k) = b(k) / A(k, k);
	for(int i = k; i >= 0; --i) {
		int j = i;
		for(int l = i-1; l >= 0; --l) {
			A(l, j) *= b(i);
			b(l) -= A(l, i);
		}	
		b(i) = b(i) / A(i, j);
	}
}
