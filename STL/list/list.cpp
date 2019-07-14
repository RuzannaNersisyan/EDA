#include "myList.hpp"

int main() {

        myList list;
	unsigned count;
	int num;	

	std::cout << "---You'r create a empty list!" << std::endl;	
/*	std::cout << "---Enter a sizeof list for generating:\t";
	std::cin >> count;
	list.initialize(count, data);
	std::cout << "---Your list is:\t";
	for(int i = 0; i < list.getSize(); ++i) {
		std::cout << list[i] << " ";
	}
	std::cout << std::endl; */
	
	for(int i = 0; i < 2; ++i) {
		std::cout << "---Enter a element for pushing in list in front:\t";
		std::cin >> num;
		list.pushFront(num);
		std::cout << "---Enter a element for pushing in list in back:\t";
		std::cin >> num;
		list.pushFront(num);
		std::cout << "---Your list is:\t";
		for(unsigned i = 0; i < list.getSize(); ++i) {
			std::cout << list[i] << " ";
		}
		std::cout << std::endl;

		std::cout << "---Enter a index of element for pushing in list:\t";
		std::cin >> count;
		std::cout << "---Enter a element for adding:\t";
		std::cin >> num;
		list.insert(count,num);
		std::cout << "---Your list is:\t";
		for(unsigned i = 0; i < list.getSize(); ++i) {
			std::cout << list[i] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "---Enter a index of element which one you want to delete:\t";
	std::cin >> count;
	list.erase(count);
	std::cout << "---Your list is:\t";
	for(unsigned i = 0; i < list.getSize(); ++i) {
		std::cout << list[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "---Now element poping front in list:\n";
	list.popFront();
	std::cout << "---Your list is:\t";
	for(unsigned i = 0; i < list.getSize(); ++i) {
		std::cout << list[i] << " ";
	}
	std::cout << std::endl;
	
	std::cout << "---Now element poping back in list:\n";
	list.popBack();
	std::cout << "---Your list is:\t";
	for(unsigned i = 0; i < list.getSize(); ++i) {
		std::cout << list[i] << " ";
	}
	std::cout << std::endl;

return 0;
}
