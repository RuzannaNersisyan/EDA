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
        	backwordStep(A, b);
	        writeSystem(b, fw);
		if(count == 1) {
			fw.stringWriting("Solution set for private case!");
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
				A(l,j) += A(i,j) * del;
			}
			b[l] += b[i] * del;
		}
		if(i >= A.getColumns()) {
		        int k = A.getColumns() - 1;
			double d = -(A(i, k)) / A(k, k);
			A(i+1, k) += A(k, k) * d;
                        b[i+1] += b[i] * d;
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
                        else if(A(i, i) == 0 && b[i] == 0) {
				A.setRows(A.getRows()-1);
				count = 1;
                                return true;
                        }else if(A(i, i) == 0 && b[i] != 0){
                                return false;
                        }
                }
        if(A.getRows() > A.getColumns()) {
		for(int i = A.getRows()-1; i >= A.getColumns()-1; --i) {
			if(i == A.getColumns()-1) {
				if(A(i, i) == 0) {
					if(b[i] == 0) { 
						return true;
						A.setRows(i);
					}else { return false; }
				}else { return true; }
			}
			if(b[i] != 0) {
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
		b[i] = b[i] / A(i, j);
		for(int l = i-1; l >= 0; --l) {
			A(l, j) *= b[i];
			b[l] = b[l] - A(l, i);
		}	
	}
}
