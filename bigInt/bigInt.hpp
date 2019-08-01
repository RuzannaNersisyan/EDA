#ifndef big_integer
#define big_integer

#include <iostream>
#include <string>


class integer
{
    public:
        integer() {}
        integer(char*);
        integer(const integer&);
        ~integer() {} 
	void charArray256ToStr(const char*, char*);
	integer pow256(integer&);
/*	integer& operator=(const integer&);
        void operator+=(integer&, integer);
        integer operator+(integer, integer);
        void operator-=(integer&, integer);
        integer operator-(integer, integer);
        void operator*=(integer&, integer);
        integer operator*(integer, integer);
        void operator/=(integer&, integer);
        integer operator/(integr, integer);
        void operator%=(integer&, integer);
        integer operator%(integer, integer);
        integer operator++(integer&);
        void operator++(integer&);
        integer operator--(integer&);
        void operator--(integer&);
        bool operator==(integer, integer);
        bool operator!=(integer, integer);
        bool operator<(integer, integer);
        bool operator<=(integer, integer);
        bool operator>(integer, integer);
        bool operator>=(integer, integer);
	bool operator!(integer);
        integer pow(const integer&, const integer&);
        integer abs(const integer&);
        integer sqr(integer);
        integer sqrt(integer);
        integer sign(integer);*/
        bool isPositive(integer);
        bool even(integer);
        bool odd(integer);
        void add(integer, integer, integer&);
        void sub(integer, integer, integer&);
        void mul(integer, integer, integer&);
        void div(integer, integer, integer&);
        void mod(integer, integer, integer&);
        void pow(integer, integer, integer&);
        void negate(integer, integer&);
	char* getNum() const { return allNum; }
    private:
        char* allNum;
	char* num256;
};

std::ostream& operator<<(std::ostream&, const integer&);
std::istream& operator>>(std::istream&, integer&);
	
#endif
