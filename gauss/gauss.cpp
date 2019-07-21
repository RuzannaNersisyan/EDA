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
			for(int j = i; j < A.getColumns(); ++j) {
				del = -(A(l, i)) / A(i, i);
				if(i == j && A(i,j) == 0) {
					double bigger = 0;
					if(A(i+1, j) != 0) {
						bigger = A(i+1, j);
						change = i+1;
					}
					for(unsigned k = i+2; k < A.getRows(); ++k) {
						if(A(k,j) > bigger) {
							bigger = A(k,j);
							change = k;
						}
					}
					double middle;
					for(int j = 0; j < A.getColumns(); ++j) {
						middle = A(i,j);
						A(i,j) = A(change,j);
						A(change,j) = middle;
					}
					middle = b(i, 0);
					b(i, 0) = b(change, 0);
					b(change, 0) = middle;
				}
				A(l,j) += A(i,j) * del;
			}
			b(l, 0) += b(i, 0) * del;
		}
		if(i >= A.getColumns()) {
			int k = A.getColumns() - 1;
			double d = -(A(i, k)) / A(k, k);
			A(i+1, k) += A(k, k) * d;
			b(i+1, 0) += b(i, 0) * d;
		}
	}
}

bool check(System& A, System& b) {
	count = 0;
	if(A.getRows() <= A.getColumns()) {
		int i = A.getRows()-1;
		if(A(i, i) != 0) {
			count = 1;
			return true;
		}
		else if(A(i, i) == 0 && b(i, 0) == 0) {
			A.setRows(A.getRows()-1);
			count = 1;
			return true;
		}else if(A(i, i) == 0 && b(i, 0) != 0){
			return false;
		}
	}
	if(A.getRows() > A.getColumns()) {
		for(int i = A.getRows()-1; i >= A.getColumns()-1; --i) {
			if(i == A.getColumns()-1) {
				if(A(i, i) == 0) {
					if(b(i, 0) == 0) { 
						return true;
						A.setRows(i);
					}else { return false; }
				}else { return true; }
			}
			if(b(i, 0) != 0) {
				return false;
			}
		}
		A.setRows(A.getColumns());
	}
	return true;
}

void backwordStep(System& A, System& b) {
	int k = A.getRows()-1; 
	for(int i = k; i >= 0; --i) {
		int j = i;
		b(i, 0) = b(i, 0) / A(i, j);
		for(int l = i-1; l >= 0; --l) {
			A(l, j) *= b(i, 0);
			b(l, 0) -= A(l, i);
		}	
	}
}
