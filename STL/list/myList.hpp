#include <iostream>
#include <cassert>
#include <cstdlib>
// #include <ctime>

class myList {
public:

	myList() {
		head = NULL;
		tail = NULL;
		size = 0;
        }
	~myList();
	
//	void initialize(unsigned);	

	void pushFront(int);
	void pushBack(int);
	void popFront();
	void popBack();
	void insert(unsigned, int);
	void erase(unsigned);

        int& operator [] (unsigned);
        const int& operator [] (unsigned) const;

	void clear();
	unsigned getSize() { return size; }

private:

	struct Node {
		Node (int data, Node *pNext = NULL, Node *pPrev = NULL) {
			this->data = data;
			this->pNext = pNext;
			this->pPrev = pPrev;
		}

		int data;
		Node *pNext;
		Node *pPrev;
	};

	Node *head;
	Node *tail;
	unsigned size;
};

myList::~myList() {
	clear();
}

void myList::clear() {
	if (getSize() % 2 == 0) {
                for(int i = 0; i < getSize()/2; ++i) {
                        popFront();
                        popBack();
                }
	}else {
                for(int i = 0; i < (getSize()-1)/2; ++i) {
                        popFront();
                        popBack();
                }
                popFront();
        }
}

/* void myList::initialize(unsigned count, int data) {
	srand(time(NULL));
	if(count == 1) {
		head = tail = new Node(data, head, tail);
		assert(head && tail);
		head->data = tail->data = rand() % 10 - 10; 
	}else {
		head = tail = new Node(data, head, tail);
		assert(head && tail);
		head->data = tail->data = rand() % 10 - 10; 
		Node *prev = tail;
		for(int i = 1; i < count; ++i) {
			tail = new Node(data, NULL, prev);
			tail->data = rand() % 10 - 10;
			prev = tail;
		} 
	}
	size = count;
} */

void myList::pushFront(int data) {
	if (size > 1) {
		Node *temp = head;
		head = new Node(data, head, NULL);
		assert(head);
		temp->pPrev = head;

	}else if (size == 1) {
		tail = head;
		head = new Node(data, head, NULL);
		assert(head);
		tail->pPrev = head;

	}else {
		head = tail = new Node(data, head, tail);
		assert(head && tail);
	}
	size++;
}

void myList::pushBack(int data) {
	if (size > 1) {
		Node *temp = tail;
		tail = new Node(data, NULL, tail);
		assert(tail);
		temp->pNext = tail;

	}else if (size == 1) {
		tail = new Node(data, NULL, tail);
		assert(tail);
		head->pNext = this->tail;

	}else {
		head = tail = new Node(data, head, tail);
		assert(head && tail);
	}
	size++;
}

void myList::popFront() {
	if (size > 1) {
		Node *temp = head;
		head = head->pNext;
		delete temp;

	}else if (size == 1) {
		Node *temp = head;
		tail = head = NULL;
		delete temp;
	}

	size--;
}

void myList::popBack() {
	if (size > 1) {
		Node *temp = tail;
		tail = tail->pPrev;
		delete temp;

	}else if (size == 1) {
		Node *temp = tail;
		tail = head = NULL;
		delete temp;
	}

	size--;
}

void myList::insert(unsigned index, int data) {
	if (index == 0) {
		 pushFront(data);

	}else if (index == size || index > size) {
		 pushBack(data);

	}else if (index <= size / 2) {
		Node *previous = head;
		for (int i = 0; i < index - 1; i++) {
			previous = previous->pNext;
		}

		Node *newNode = new Node(data, previous->pNext, previous);
		assert(newNode);

		previous->pNext = newNode;
		Node *next = newNode->pNext;
		next->pPrev = newNode;

		size++;

	}else if (index > size / 2) {
		Node *next = this->tail;
		for (int i = size - 1; index < i; i--) {
			next = next->pPrev;
		}

		Node *newNode = new Node(data, next, next->pPrev);
		assert(newNode);

		next->pPrev = newNode;
		Node *previous = newNode->pPrev;
		previous->pNext = newNode;

		size++;
	}
}

void myList::erase(unsigned index) {
	if (index == 0) {
		 popFront();
	}else if (index == size || index > size) {
		 popBack();

	}else if (index <= size / 2) {
		Node *previous = head;
		for (int i = 0; i < index - 1; i++) {
			previous = previous->pNext;
		}

		Node *toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		Node *next = toDelete->pNext;
		delete toDelete;
		next->pPrev = previous;

		size--;

	}else if (index > size / 2) {
		Node *next = tail;
		for (int i = size - 1; index < i; i--) {
			next = next->pPrev;
		}

		Node *toDelete = next->pPrev;
		next->pPrev = toDelete->pPrev;
		Node *previous = toDelete->pPrev;
		delete toDelete;
		previous->pNext = next;

		size--;
	}
}

int& myList::operator[] (unsigned index) {
	if (index <= size / 2) {
		int counter = 0;
		Node *current = head;

		while (current != NULL) {
			if (counter == index) {
				 return current->data;
			}
			current = current->pNext;
			counter++;
		}

	}else {
		int counter = size - 1;
		Node *current = tail;

		while (current != NULL) {
			if (counter == index) {
				return current->data;
			}
			current = current->pPrev;
			counter--;
		}
	}
}


const int& myList::operator[] (unsigned index) const {
	if (index <= size / 2) {
		int counter = 0;
		Node *current = head;

		while (current != NULL) {
			if (counter == index) {
				 return current->data;
			}
			current = current->pNext;
			counter++;
		}

	}else {
		int counter = size - 1;
		Node *current = tail;

		while (current != NULL) {
			if (counter == index) {
				return current->data;
			}
			current = current->pPrev;
			counter--;
		}
	}
}
