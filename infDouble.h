#pragma once

#include <iostream>
#include <limits>

// double plus infinite portion
class infDouble
{
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

std::istream& operator>> (std::istream& input, infDouble& target);

std::ostream& operator<< (std::ostream& output, infDouble& target);
