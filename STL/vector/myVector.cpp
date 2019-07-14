#include "myVector.hpp"
#include <iostream>
#include <cassert>

myVector::myVector() {
    size = 0;
    capacity = 20;
    data = new int[capacity];
}

void myVector::initJustSize(unsigned vSize) {
    size = vSize;
    capacity = vSize * 2;
    data = new int[capacity];
    assert(data);
}

void myVector::initWithElem(unsigned vSize, int elem) {
    size = vSize;
    capacity = vSize * 2;
    data = new int[capacity];
    assert(data);
    for(int i = 0; i < size; ++i) {
        data[i] = elem;
    }
}

myVector::~myVector() {
    assert(data);
    delete[] data;
    data = 0;
}

void myVector::pushBack(int num) {
    if(size == capacity) {
        capacity *= 2;
        int* temp = data;
        data = new int[capacity];
        assert(data);
        for(int i = 0; i < size; ++i){
            data[i] = temp[i];
        }
        delete[] temp;
    }
    data[size] = num;
    size++;     
}

void myVector::popBack() {
    size--;
}

void myVector::insert(unsigned index, int num) {
    assert(index >= 0 && index < size && "Out of range!");
    if(index == size) {
        this->pushBack(num);
        return;
    }
    int* temp = data;
    assert(temp);
    if(size == capacity) {
        capacity *= 2;
    }
    data = new int[capacity];
    assert(data);
    for(int i = 0; i < index; ++i) {
        data[i] = temp[i];
    }
    data[index] = num;
    for(int i = index + 1; i < size+1; ++i) {
        data[i] = temp[i-1];
    }
    delete[] temp;
    size++;
}

void myVector::erase(unsigned index) {
    assert(index >= 0 && index < size && "Out of range!");
    if(index == size) {
	this->popBack();
	return;
    }
    int* temp = data;
    assert(temp);
    data = new int[capacity];
    assert(data);
    for(int i = 0; i < index; ++i) {
        data[i] = temp[i];
    }
    for(int i = index + 1; i < size; ++i) {
        data[i-1] = temp[i];
    }
    delete[] temp;
    size--;
    
}

unsigned myVector::getSize() const{
    return size;
}

int& myVector::operator[](unsigned index) {
    assert(index < size && index >= 0 && "Out of range!");
    return data[index];
}

const int& myVector::operator[](unsigned index) const {
    assert(index < size && index >= 0 && "Out of range!");
    return data[index];
}

unsigned myVector::find(int elem) const{
    for(int i = 0; i < size; ++i) {
        if(data[i] == elem) {
            return i;
        }
    }
    return -1;
}

int main() {
	
	unsigned num;
	unsigned size;
	myVector vec;

	std::cout << "\t\t\t---------------Create vector---------------\n" << std::endl;

	std::cout << "1. Empty vector." << "\n2. Vector with some size but without elements." 
			<< "\n3. Vector with some size and some 'arjeq' of elements." << std::endl;
	
	std::cout << "---Input a number wich one you want to create:\t";
	std::cin >> num;

	if(num == 1) {
		vec;
		std::cout << "---Your vector is empty!!" <<std::endl;
	}else if(num == 2) {
		std::cout << "---Enter a size of vector:\t";
		std::cin >> size; 
		vec.initJustSize(size);
	}else if(num == 3){
		int elem;
		std::cout << "---Enter a size of vector:\t";
		std::cin >> size;
		std::cout << std::endl << "---Enter a 'arjeq' of your vector:\t";
		std::cin >> elem;
	 	vec.initWithElem(size, elem);
		std::cout << "---Your vector is:\t ";
		for(int i = 0; i < size; ++i) {
			std::cout << vec[i] << " ";
		}
	std::cout << std::endl;
	}

	std::cout << "---Add a new element in vector in back:\t";
	int push;
	std::cin >> push;
	vec.pushBack(push);
	std::cout << "---Your vector is:\t";
	if(getSize() == 0) {
		std::cout << "empyt.!" << std::endl;
	}else {
		for(int i = 0; i < vec.getSize(); ++i) {
			std::cout << vec[i] << " ";
		}
	}
	std::cout << std::endl;
	

	std::cout << "---Choose index of element for inserting that element:\t" ;
	std::cin >> num;
	std::cout << std::endl << "---Enter a element which you want to add:\t";
	std::cin >> push;
	std::cout << std::endl;
	vec.insert(num, push);
	std::cout << "---Your vector is:\t";
	if(getSize() == 0) {
		std::cout << "empyt.!" << std::endl;
	}else {
		for(int i = 0; i < vec.getSize(); ++i) {
			std::cout << vec[i] << " ";
		}
	}
	std::cout << std::endl;

	
	std::cout << "---Delete a new element in vector in back.\n";
	vec.popBack();
	std::cout << "---Your vector is:\t";
	if(getSize() == 0) {
		std::cout << "empyt.!" << std::endl;
	}else {
		for(int i = 0; i < vec.getSize(); ++i) {
			std::cout << vec[i] << " ";
		}
	}
	std::cout << std::endl;


	std::cout << "---Choose index of element for deleting that element:\t";
	std::cin >> num;
	vec.erase(num);
	std::cout << std::endl;
	std::cout << "---Your vector is:\t";
	if(getSize() == 0) {
		std::cout << "empyt.!" << std::endl;
	}else {
		for(int i = 0; i < vec.getSize(); ++i) {
			std::cout << vec[i] << " ";
		}
	}
	std::cout << std::endl;


	std::cout << "---Choose a number which you want to fined in vector:\t";
	std::cin >> push;
	std::cout << vec.find(push) << std::endl;
	std::cout << std::endl;
	
	
	std::cout << "---Your vector is:\t"; 
	if(getSize() == 0) {
		std::cout << "empyt.!" << std::endl;
	}else {
		for(int i = 0; i < vec.getSize(); ++i) {
			std::cout << vec[i] << " ";
		}
	}
	std::cout << std::endl;
	

return 0;
}
