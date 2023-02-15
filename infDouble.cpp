#pragma once

#include <iostream>
#include <limits>

// double plus infinite portion
class infDouble {
	using idou = infDouble;

	double normalValue = 0;
	int infiniteValue = 0;

public:

	infDouble();
	infDouble(double x);
	infDouble(double x, int y);
	infDouble(std::string input);
	infDouble(char input);

	static idou OMEGA;

	friend std::istream& operator>> (std::istream& input, infDouble& target);
	friend std::ostream& operator<< (std::ostream& output, infDouble& target);



	// operator overloading stuffs

	bool operator> (idou other) const;
	bool operator> (std::string other) const;
	bool operator>= (idou other) const;
	bool operator>= (std::string other) const;

	bool operator< (idou other) const;
	bool operator< (std::string other) const;
	bool operator<= (idou other) const;
	bool operator<= (std::string other) const;

	bool operator== (idou other) const;
	bool operator== (std::string other) const;
	bool operator!= (idou other) const;
	bool operator!= (std::string other) const;

	idou operator+ (idou other) const;
	idou operator+ (std::string other) const;
	idou& operator+=(idou other);
	idou& operator+= (std::string other);
	idou& operator++();

	idou operator- (idou other) const;
	idou operator- (std::string other) const;
	idou& operator-=(idou other);
	idou& operator-= (std::string other);
	idou& operator--();

	operator double() const;
};

infDouble::infDouble() : normalValue(0), infiniteValue(0) {}
infDouble::infDouble(double x) : normalValue(x), infiniteValue(0) {}
infDouble::infDouble(double x, int y) : normalValue(x), infiniteValue(y) {}
infDouble::infDouble(std::string input) : normalValue(0), infiniteValue(1) {}
infDouble::infDouble(char input) : normalValue(0), infiniteValue(1) {}



bool infDouble::operator> (infDouble other) const {
	if (infiniteValue == other.infiniteValue) {
		return normalValue > other.normalValue;
	}

	return infiniteValue > other.infiniteValue;
}
bool infDouble::operator> (std::string other) const { return operator>((idou)other); }
bool infDouble::operator>= (infDouble other) const {
	if (infiniteValue == other.infiniteValue) {
		return normalValue >= other.normalValue;
	}

	return infiniteValue >= other.infiniteValue;
}
bool infDouble::operator>= (std::string other) const { return operator>=((idou)other); }

bool infDouble::operator< (infDouble other) const {
	if (infiniteValue == other.infiniteValue) {
		return normalValue < other.normalValue;
	}

	return infiniteValue < other.infiniteValue;
}
bool infDouble::operator< (std::string other) const { return operator<((idou)other); }
bool infDouble::operator<= (infDouble other) const {
	if (infiniteValue == other.infiniteValue) {
		return normalValue <= other.normalValue;
	}

	return infiniteValue <= other.infiniteValue;
}
bool infDouble::operator<= (std::string other) const { return operator<=((idou)other); }

bool infDouble::operator== (infDouble other) const {
	if (normalValue == other.normalValue) {
		return infiniteValue == other.infiniteValue;
	}

	return false;
}
bool infDouble::operator== (std::string other) const { return operator==((idou)other); }
bool infDouble::operator!= (infDouble other) const {
	if (normalValue == other.normalValue) {
		return infiniteValue != other.infiniteValue;
	}

	return true;
}
bool infDouble::operator!= (std::string other) const { return operator!=((idou)other); }

infDouble infDouble::operator+ (infDouble other) const { return idou(normalValue + other.normalValue, infiniteValue + other.infiniteValue); }
infDouble infDouble::operator+ (std::string other) const { return idou(normalValue, infiniteValue + 1); }
infDouble& infDouble::operator+=(infDouble other) {


	normalValue += other.normalValue;
	infiniteValue += other.infiniteValue;
	return *this;
}
infDouble& infDouble::operator+= (std::string other) { infiniteValue++; return *this; }
infDouble& infDouble::operator++() { infiniteValue++; return *this; }

infDouble infDouble::operator- (infDouble other) const { return idou(normalValue - other.normalValue, infiniteValue - other.infiniteValue); }
infDouble infDouble::operator- (std::string other) const { return idou(normalValue, infiniteValue - 1); }
infDouble& infDouble::operator-=(infDouble other) {
	normalValue -= other.normalValue;
	infiniteValue -= other.infiniteValue;
	return *this;
}
infDouble& infDouble::operator-= (std::string other) { infiniteValue--; return *this; }
infDouble& infDouble::operator--() { infiniteValue--; return *this; }



infDouble::operator double() const {
	if (infiniteValue > 0) {
		//	std::cerr << "error: positive infinite return value\n";
		return DBL_MAX;
	}

	if (infiniteValue < 0) {
		//	std::cerr << "error: negative infinite return value\n";
		return DBL_MIN;
	}

	return normalValue;
}

std::istream& operator>> (std::istream& input, infDouble& target)
{
	static int temp;
	try
	{
		if (!(input >> temp))
		{
			std::cin.clear();
			std::string garbage;

			input >> garbage;

			throw 1;
		}

		target.normalValue = temp;
	}
	catch (int)
	{
		target.infiniteValue = 1;
	}


	return input;
}

std::ostream& operator<< (std::ostream& output, infDouble& target) {
	if (target.infiniteValue != 0)
	{
		output << "inf";
	}
	else
	{
		output << target.normalValue;
	}

	return output;
}

infDouble infDouble::OMEGA = infDouble(DBL_MAX, INT_MAX);
