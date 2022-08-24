#include<iostream>
using namespace std;

class Fraction
{
	int numerator;
	int denominator;


public:
	void set_numerator(int num)
	{
		numerator = num;
	}
	void set_denominator(int den)
	{
		if (den != 0)
			denominator = den;
		else
			cout << "Знаменатель не может быть равен нулю" << endl;
	}
	int get_numerator()
	{
		return numerator;
	}
	int get_denominator()
	{
		return denominator;
	}
	Fraction(int num = 0, int den = 1)
	{
		numerator = num;
		set_denominator(den);
	}
	Fraction(const Fraction& other)
	{
		//Fraction f1;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
	}
	Fraction Add(Fraction f1, Fraction f2)
	{
		Fraction f3;
		f3.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
		f3.denominator = f1.denominator * f2.denominator;
		return f3;
	}
	Fraction Sub(Fraction f1, Fraction f2)
	{
		Fraction f3;
		f3.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
		f3.denominator = f1.denominator * f2.denominator;
		return f3;
	}
	Fraction Mult(Fraction f1, Fraction f2)
	{
		Fraction f3;
		f3.numerator = f1.numerator * f2.numerator;
		f3.denominator = f2.denominator * f1.denominator;
		return f3;
	}
	Fraction Div(Fraction f1, Fraction f2)
	{
		Fraction f3;
		f3.numerator = f1.numerator * f2.denominator;
		f3.denominator = f1.denominator * f2.numerator;
		return f3;
	}
	Fraction Pow(Fraction f, int n) //возведение в степень //f2=f=>(f2.num=f.num)&&(f2.den=f.den)
	{
		Fraction f2(f.numerator, f.denominator);
		for (int i = 1; i < n; i++)
		{
			f2.numerator *= f.numerator; //f2.num=f2.num*f.num
			f2.denominator *= f.denominator;
		}
		return f2;
	}
	bool Compare(Fraction f1, Fraction f2) //Сравнение дробей
	{
		f1.numerator *= f2.denominator;
		f1.denominator *= f2.denominator;
		f2.numerator *= f2.denominator;
		f2.denominator *= f1.denominator;

	}
	bool Equals(Fraction f1, Fraction f2) //равно
	{
		f1.numerator *= f2.denominator;
		
		f2.numerator *= f2.denominator;
		
		return f1.numerator == f2.numerator;
	}
	bool NotEquals(Fraction f1, Fraction f2) //не равно
	{
		return!Equals(f1, f2);
	}
	bool Less(Fraction f1, Fraction f2) //меньше
	{
		f1.numerator *= f2.denominator;
		
		f2.numerator *= f2.denominator;
		
		return f1.numerator < f2.numerator;
	}
	bool More(Fraction f1, Fraction f2) //больше
	{
		f1.numerator *= f2.denominator;
		
		f2.numerator *= f2.denominator;
		
		return f1.numerator > f2.numerator;
	}
	Fraction Square(Fraction &f) //извлечение квадратного корня
	{
		f.numerator = sqrt(f.numerator);
		f.denominator = sqrt(f.denominator);
		return f;
	}
	double Decimal(Fraction f) //перевод в десятичную дробь
	{
		return f.numerator / f.denominator;
	}
	void Print()
	{
		cout << numerator << "/" << denominator;
	}

};

	int main()
	{
		setlocale(0, "");
		Fraction f(1,2), f1(3,4);
		f.Print();
		cout << "\t";
		f1.Print();
		Fraction f2;
		f2=f.Add(f, f1);
		cout << "\t";
		f2.Print();
		f2 = f.Sub(f, f1);
		cout << "\t";
		f2.Print();
		cout << "\t";
		f2 = f.Mult(f, f1);
		f2.Print();
		cout << "\t";
		f2 = f.Div(f, f1);
		f2.Print();
		cout << "\t";
		f2 = f.Pow(f, 2);
		f2.Print();
		cout << "\t";
		f2 = f.Square(f);
		f2.Print();
		cout << "\t";
		bool temp;
		temp = f.More(f1, f);
		cout << temp << endl;
		temp = f.Less(f1, f);
		cout << temp << "\t";
		temp = f.Equals(f1, f);
		cout << temp << "\t";
		cout << "\t";
		temp = f.NotEquals(f1, f);
		cout << temp << "\t";
		double t = f.Decimal(f);
		cout << t;
		return 0;
	}







