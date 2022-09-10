#include<iostream>
using namespace std;

class Fraction
{
	int numerator;
	int denominator;
	int integer;
	int cancellation;

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
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	int get_numerator() const
	{
		return numerator;
	}
	int get_denominator() const
	{
		return denominator;
	}
	int get_integer()
	{
		return integer;
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
	bool Less_Equals(Fraction f1, Fraction f2) //меньше
	{
		f1.numerator *= f2.denominator;

		f2.numerator *= f2.denominator;

		return f1.numerator <= f2.numerator;
	}
	bool More_Equals(Fraction f1, Fraction f2) //больше
	{
		f1.numerator *= f2.denominator;

		f2.numerator *= f2.denominator;

		return f1.numerator >= f2.numerator;
	}
	Fraction Square(Fraction &f) //извлечение квадратного корня
	{
		f.numerator = sqrt(f.numerator);
		f.denominator = sqrt(f.denominator);
		return f;
	}
	Fraction Square_integer(Fraction& s) //извлечение квадратного корня из целого числа
	{
		return s.integer = sqrt(s.integer);
	}
	double Decimal(Fraction f) //перевод в десятичную дробь
	{
		return f.numerator / f.denominator;
	}
	void Print() const
	{
		cout << numerator << "/" << denominator;
	}
	Fraction Reduction(Fraction f1, Fraction f2) //сокращение дробей
	{
		
	}
		/*{
			if (f2.numerator > f2.denominator)
			{
				f2.numerator %= f2.denominator;
			}
			else
			{
				f2.denominator %= f2.numerator;
			}
			return f2.numerator+f2.denominator;
		}*/
	
	Fraction to_proper(Fraction f) //выделяет целую часть /перевод дроби в правильную
	{
		Fraction F2(f.numerator, f.denominator);
		integer += numerator / denominator;
		(numerator %= denominator) ? cout << integer << "\t" : cout << numerator % denominator; ;
		return F2;
	}
};

	int main()
	{
		setlocale(0, "");
		Fraction s(25);
		cout << "Square_integer: ";
		s.Print(); cout << endl;
		Fraction f(5, 4), f1(1,3);
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
		cout << temp << "\t";
		temp = f.Less(f1, f);
		cout << temp << "\t";
		temp = f.Equals(f1, f);
		cout << temp << "\t";
		temp = f.NotEquals(f1, f);
		cout << temp << "\t";
		temp = f.Less_Equals(f1, f);
		cout << temp << "\t";
		temp = f.More_Equals(f1, f);
		cout << temp << "\t";
		cout << "Выделение целой части из дроби " << endl;
		f2 = f.to_proper(f);
		f2.Print();
		cout << "\t";
		//f2 = f.Reduction(f, f1);
		//f2.Print();
		cout << "\t";
        double t = f.Decimal(f);
		cout << t;
		return 0;
	}




