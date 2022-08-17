#include<iostream>
using namespace std;


class Fraction
{
	int numerator;
	int denominator;

public:
	int get_numerator()const 
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		this->denominator = denominator;
	}
	//Consructors:
	Fraction(int numerator = 0, int denominator = 0)
	{
		this->numerator = numerator;
		this->denominator = denominator;
		cout << "Constructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}
	//Operators:



	//Methods:
};