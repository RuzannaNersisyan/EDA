#include "bigInt.hpp"
#include <cassert>
#include <cstdlib>
#include <sstream>

integer::integer(char* num)
{
	allNum = num;
}

/* void integer::strToCharArray256(const char* num, char* n256)
	: allNum(num)
	, num256(n256)
{
	
} */

std::ostream& operator<<(std::ostream& stream, const integer& i)
{
	stream << i.getNum() << std::endl;
	return stream;
}

std::istream& operator>>(std::istream& stream, integer& i) 
{
	stream >> i.getNum(); 
	return stream;
}
