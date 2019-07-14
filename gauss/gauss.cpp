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
			fw.stringWriting("No solutions!");
			fw.symbolWriting('\n');
		}
	}else {
		if(count == 1) {
			fw.stringWriting("Solution set for private case!");
		}
        	backwordStep(A, b);
	        writeSystem(b, fw);
	}
    }
	return 0;
}

void straightStep(System& A, System& b) {
	for(int i = 0; i < A.getRows()-1; ++i) {
	        int change = 0;
		double del = A(i+1, i) / A(i, i);
		for(int j = i; j < A.getColumns(); ++j) {
			 if(i == j && A(i,j) == 0) {
			        double bigger = 0;
			        for(int k = i+1; k < A.getRows(); ++k) {
                                 	if(A(k,j) > bigger) {
                                 		bigger = A(k,j);
                                		change = k;
                	        	}
                		}
              		        unsigned k;
	                        for(int j = 0; j < A.getColumns(); ++j) {
        	                        A(k,j) = A(i,j);
                	                A(i,j) = A(change,j);
                        	        A(change,j) = A(k,j);
	                        }
                                b[k] = b[i];
                	        b[i] = b[change];
	                        b[change] = b[k];
		        }
			A(i+1, j) -= A(i, i) * del;
			b[i+1] -= b[i] * del;
		}
		if(i >= A.getColumns()) {
		        int j = A.getColumns() - 1;
			double d = A(i, j) / A(j, j);
			A(i+1, j) -= A(i, i) * d;
                        b[i+1] -= b[i] * d;
		}
	}
}

bool check(System& A, System& b) {
        count = 0;
        if(A.getRows() <= A.getColumns()) {
                int i = A.getRows() - 1;
                        if(A(i, i) != 0) {
                                return true;
                        }
                        else if(b[i] == 0)
                        {
                                return true;
                        }
                        else
                        {
                                return false;
                        }
                }
        if(A.getRows() > A.getColumns()) {
		for(int i = A.getRows() - 1; i >= A.getColumns(); --i) {
			if(b[i] != 0) {
				return false;
			}else {
				A.setRows(A.getColumns());
			}
		}
	}
}


void backwordStep(System& A, System& b) {
	unsigned k = 0;
	for(int i = A.getRows()-1; i >= 0; --i) {
		for(int j = i - 1; j >= 0; --j) {
			A(i-1, j) += A(i, i) * (-A(i-1, i)) / A(i, i);
			b[i-1] += b[i] * (-A(i-1, i)) / A(i, i);
		}
	}
	for(int i = 0; i < A.getRows(); ++i) {
		b[i] /= A(i, i);
	}
}
