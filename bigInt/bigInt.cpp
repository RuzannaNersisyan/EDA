#include "bigInt.hpp"
#include <cassert>
#include <string>
#include <cstdlib>
#include <sstream>

bool isNumber(const std::string& s);

integer::integer(std::string num)
	: allNum(num)
{
	strToCharArray256(num);
	for(int i = 0; i < num256.size(); ++i) {
		std::cout << num256[i] << " num256 " << i << std::endl;
	}
}

void integer::strToCharArray256(std::string num)
{
	std::string intermediate = "", part = "", allTemp = "", intTemp = "";
	std::string::const_iterator it = num.begin();
	std::string::const_iterator end = num.end();
	part.assign(num, *(it-1), 3);
	int divisible = stoi(part);
	if(divisible < 256 && num.length() > 3) {
		part.assign(num, *(it-1), 4);
		divisible = stoi(part);
		num.assign(num, 4, *(end-1));
	}else if(divisible >= 256){
		num.assign(num, 3, *(end-1));
	}
	while(it != num.end()) { 
		allTemp = std::to_string(divisible / 256);
		intermediate += allTemp;
		intTemp = std::to_string(divisible % 256);
		part.assign(num, *(it-1), 1);
		part = intTemp + part;
		divisible = stoi(part);
		if(divisible < 256) {
			intermediate += "0";
			part.assign(num, *(it-1), 2);
			part = intTemp + part;
			divisible = stoi(part);
			if(num.length() > 2) {
				num.assign(num, 2, *(end-1));
			}else if(num.length() < 3){
				if(divisible < 256) {
					num256.push_back(divisible);
				}else {
					allTemp = std::to_string(divisible / 256);
					intermediate += allTemp;
					intTemp = std::to_string(divisible % 256);
					divisible = stoi(intTemp);
				}
			}
		}else {
			num.assign(num, 1, *(end-1));
		}
		it = num.begin();
	}
	num256.push_back(divisible);
	num = intermediate;
	if(num.length() > 2) {
		return strToCharArray256(num);
	}
}

std::ostream& operator <<(std::ostream& stream, const integer& i)
{
	stream << i.allNum << std::endl;
	return stream;
}

std::istream& operator >>(std::istream& stream, integer& i) 
{
	std::cout << "Enter a number: ";
	stream >> i.allNum;
	if(isNumber(i.allNum)) {
		return stream;
	}else {
		std::cout << "You entered not a number!!\n\tPlease try again." << std::endl;
		return operator >>(stream, i);
	}
}

bool isNumber(const std::string& s) 
{
	std::string::const_iterator it = s.begin();
	while(it != s.end()) {
		if(std::isdigit(*it)) {
			++it;
		}else {
			return false;
		}
	}
	return true;
}

