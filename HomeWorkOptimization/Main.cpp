#include<iostream>
using namespace std;

void Print(int a, int b)
{
	std::cout << a + b;
}

class Fraction
{
	int num;
	int den;
	int integral;
public:
	//Fraction(){}
	Fraction() :num(0), den(1), integral{ 0 }{} //конструктор по умолчанию
	/*Fraction(int _num, int _den) {
		num = _num;
		den = _den;
		integral = 0;
	}*/
	Fraction(int _num, int _den):num(_num), den(_den), integral{0} {}
	void Print() {
		cout << num << "/" << den << endl;
	}
	/*Fraction Add(Fraction &A, Fraction &B) 
	{
		Fraction C;
		C.num = A.num * B.den + B.num * A.den;
		C.den = A.den * B.den;
		C.integral = 0;
		return C;
	}*/
	Fraction Add(Fraction& F)
	{
		Fraction C;
		C.num = num * F.den + F.num * den;
		C.den = den * F.den;
		C.integral = 0;
		return C;
	}
	Fraction Sub(Fraction& F)
	{
		Fraction C;
		C.num = num * F.den - F.num * den;
		C.den = den * F.den;
		C.integral = 0;
		return C;
	}
	Fraction Mult(Fraction& F)
	{
		Fraction C;
		C.num = num * F.num;
		C.den = den * F.den;
		C.integral = 0;
		return C;
	}
	Fraction Div(Fraction& F)
	{
		Fraction C;
		C.num = num * F.den;
		C.den = den * F.num;
		C.integral = 0;
		return C;
	}
	Fraction To_proper(Fraction& F) //Выделение целой части из дроби
	{
		Fraction C;
		integral += num / den;
		/*if (num %= den)
		{
			cout << integral<<"\t";
		}*/
		(num %= den) ? cout << integral << "\t":cout<< num%den;
		return C;
	}
	Fraction Cancellation(Fraction& F)
	{
		Fraction C;
		int more, less, ost;
		if (num > den)
		{
			more = num;
			less = den;
		}
		else
		{
			less = num;
			more = den;
		}
		do
		{
			ost = more % less;
			more = less;
			less = ost;

		} while (ost);
			int nod = more;
			if (ost == 0) return *this;
			C.num /= nod;
			C.den /= nod;
		return C;
	}

	Fraction operator+(const Fraction& F) 
	{
		Fraction C;
		C.num = num * F.den;
		C.den = den * F.num;
		C.integral = 0;
		return C;
	}
	bool operator>(const Fraction& F)
	{
		return (num * F.den > F.num * den);
	}
	bool operator<(const Fraction& F)
	{
		return (num * F.den < F.num * den);
	}
	bool operator==(const Fraction& F)
	{
		return (num * F.den == F.num* den);
	}
	bool operator>=(const Fraction& F)
	{
		return (num * F.den >= F.num * den);
	}
	bool operator<=(const Fraction& F)
	{
		return (num * F.den <= F.num* den);
	}
};

int main()
{
	int i = 0;

	Fraction F(3, 9);
	Fraction G(5, 2);
	Fraction I(G);
	//Fraction E = G.Add(G, F);
	 //            G   +    F
	Fraction E = G.Add(F);
	//cout <<      G.+  (F);
	Fraction H = G + F; 
	//H = G.Add(F);
	E.Print();
	Fraction S = G.Sub(F);
	S.Print();
	Fraction M = G.Mult(F);
	M.Print();
	Fraction D = G.Div(F);
	D.Print();
	Fraction T = G.To_proper(F);
	T.Print();
	cout << "Cancellation " << endl;
	Fraction C = G.Cancellation(F);
	C.Print();


	int a{ 1 };
	int b{ 2 };
	cout<< std::boolalpha;
	//cout << (a > b);
	cout << (G > F);
}