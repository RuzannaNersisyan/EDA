#include "bigInt.hpp"
#include <cassert>
#include <string>
#include <cstdlib>
#include <sstream>

bool isNumber(const std::string&);
std::string pow256(unsigned);
std::string pow7Of256(unsigned);
std::string allPowOf256(unsigned);
std::string strMult(std::string, std::string);
std::string strAdd(std::string, std::string);

integer::integer(std::string num)
//	: allNum(num)
{
	strToCharArray256(num);
	for(int i = 0; i < num256.size(); ++i) {
		std::cout << num256[i] << " num256 " << i << std::endl;
	}
	std::cout << allNum << " allNum ___ convert to string" << std::endl;
	charArray256ToStr();
	std::cout << allNum << " allNum ___ convert to string" << std::endl;
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

void integer::strToCharArray256(std::string num)
{
	std::string wholeNum = "", residualNum = "", allTemp = "", intTemp = "";
	std::string::const_iterator it = num.begin();
	std::string::const_iterator end = num.end();
	residualNum.assign(num, *(it-1), 3);
	int divisible = stoi(residualNum);
	char ch;
	if(divisible < 256 && num.length() > 3) {
		residualNum.assign(num, *(it-1), 4);
		divisible = stoi(residualNum);
		num.assign(num, 4, *(end-1));
	}else if(divisible >= 256){
		num.assign(num, 3, *(end-1));
	}
	allTemp = std::to_string(divisible / 256);
	wholeNum += allTemp;
	intTemp = std::to_string(divisible % 256);
	residualNum.assign(num, *(it-1), 1);
	residualNum = intTemp + residualNum;
	divisible = stoi(residualNum);
	while(it != num.end()) {
		if(divisible < 256 && num.length() >= 2) {
			wholeNum += "0";
			residualNum.assign(num, *(it-1), 2);
			residualNum = intTemp + residualNum;
			divisible = stoi(residualNum);
			num.assign(num, 2, *(end-1));
		}else if(divisible < 256 && num.length() < 2) {
			ch = static_cast<char>(divisible);
			num256.push_back(ch);
			if(num.length() == 0) {
				break;
			}else {
				num.assign(num, 1, *(end-1));
			}
		}else if(divisible > 256) {
			num.assign(num, 1, *(end-1));
		}
		allTemp = std::to_string(divisible / 256);
		wholeNum += allTemp;
		intTemp = std::to_string(divisible % 256);
		residualNum.assign(num, *(it-1), 1);
		residualNum = intTemp + residualNum;
		divisible = stoi(residualNum);
	}
	ch = static_cast<char>(divisible);
	num256.push_back(ch);
	if(wholeNum.length() <= 3) {
		divisible = stoi(wholeNum);
		if(divisible < 256) {
			ch = static_cast<char>(divisible);
			num256.push_back(ch);
		}else {
			strToCharArray256(wholeNum);
		}
	}else {
		strToCharArray256(wholeNum);
	}
}	

void integer::charArray256ToStr() 
{
	std::string str = "", pow = "";
	for(unsigned i = 0; i < num256.size(); ++i) {
		str = std::to_string(num256[i]); 
		pow = pow256(i);
		str = strMult(str, pow);
		allNum = strAdd(allNum, str);
	}
}

std::string pow256(unsigned power) 
{
	if(power < 8) {
		return pow7Of256(power);
	}else {
		return allPowOf256(power);
	}
}

std::string pow7Of256(unsigned power) 
{
	unsigned long long p7 = 1;
	std::string pow7 = "";
	if(power == 0) {
		pow7 = std::to_string(p7);
		return pow7;
	}else {
		for(unsigned i = 0; i < power; ++i) {
			p7 *= 256;
		}
		pow7 = std::to_string(p7);
		return pow7;
	}
}

std::string allPowOf256(unsigned power) 
{
	std::string outerStr = "", itm = "";
	int whole = 0, surplus = 0;
	whole = power / 7;
	surplus = power % 7;
	for(int i = 0; i < whole; ++i) {
		itm = pow7Of256(7);
		outerStr = strMult(outerStr, itm); 
	}
	itm = pow7Of256(surplus);
	outerStr = strMult(outerStr, itm); 
	return outerStr;
}

std::string strAdd(std::string str1, std::string str2) 
{
	std::string outStr = "", str = "";
	int first = 0, second = 0, out = 0, temp = 0;
	if(str1.length() < str2.length()) {
		str = str1;
		str1 = str2;
		str2 = str;
	}
	std::string::iterator it1 = str1.begin();
	std::string::iterator it2 = str2.begin();
	while(str1.length() > 0) {
		str.assign(str1, str1.length()-1, 1);
		first = stoi(str);
		first += temp;
		str1.assign(str1, *(it1-1), str1.length()-1);
		if(str2.length() != 0) {
			str.assign(str2, str2.length()-1, 1);
			second = stoi(str);
			str2.assign(str2, *(it2-1), str2.length()-1);
			out = first + second;
		}else { out = first; }
		if(out > 9){
			temp = 1;
			out -= 10;
		}else {	temp = 0; }
		outStr = std::to_string(out) + outStr;
	}
	if(temp != 0) {
		outStr = std::to_string(temp) + outStr;
	}
	return outStr;
}

std::string strMult(std::string str1, std::string str2) 
{
	if(str1 == "" && str2 == "") { return ""; }
	else if(str1 == "") { return str2; }
	else if(str2 == "") { return str1; }
	std::string str = "", zero = "", out = "", outerStr = "", itm = "";
	int temp = 0, first = 0, second = 0, mm = 0, whole = 0, surplus = 0;
	std::string::iterator it1 = str1.begin();
	std::string::iterator it2 = str2.begin();
	while(str1.length() > 0) {
		str.assign(str1, str1.length()-1, 1);
		second = stoi(str);
		str1.assign(str1, *(it1-1), str1.length()-1);
		if(second == 0) {
			zero += "0";
			continue;
		}
		for(int j = 0; j < str2.length(); ++j) {
			str.assign(str2, str2.length()-1-j, 1);
			first = stoi(str);
			mm = first * second;
			if(mm > 9) {
				whole = mm / 10;
				surplus = mm % 10;
				surplus += temp;
			}else {
				whole = 0;
				surplus = mm + temp;
			}
			if(surplus > 9) {
				temp = 1;
				surplus -= 10;
			}else { temp = 0; }
			itm = std::to_string(surplus);
			out = itm + out;
			temp += whole;
		}
		if(temp != 0) {
			out = std::to_string(temp) + out;
			temp = 0;
		}
		out += zero;
		outerStr = strAdd(outerStr, out);
		zero += "0";
		out = "";
	}
	return outerStr;
}
