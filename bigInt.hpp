#ifndef big_integer
#define big_integer

#include <iostream>
#include <cassert>
#include <string>

class integer
{
public:
	integer();
	integer(std::string);
	integer(const integer&);
	~integer();
	integer& operator=(const integer&);
	integer& operator+();
	integer& operator-();
	integer& operator*();
	integer& operator/();
	integer& operator+=();
	integer& operator-=();
	integer& operator*=();
	integer& operator/=();
	integer& operator++();
	integer& operator++(integer&);
	integer& operator--();
	integer& operator--(integer&);
private:
	std::string allNum;
	int num;
}

#endif
