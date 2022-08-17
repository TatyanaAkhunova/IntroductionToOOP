#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n-------------------------------------\n"

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	//      Constructors:

	/*Point()
	{
		x = y = double(); //�������� �� ��������� ��� double
		cout << "Constructor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = double();
		cout << "largConstructor:" << this << endl; //����������� � ����� ����������
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor: \t" << this << endl;
	}
	
	//      Operators:
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor: " << this << endl;
	}
	Point& operator =(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	Point& operator++()
	{
		x++;
		y++;
		return *this;
	}
	Point operator++(int)
	{
		Point old = *this;
		x++;
		y++;
		return old;
	}
	
	//      Methods:
	//double distance(Point other)
	double distance(const Point& other)
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(pow(x_distance, 2)+pow(y_distance, 2)); //Square Root
		return distance;
	}
	void print()const
	{
		cout << "X = " << x << "\tY ="  << y << endl;
	}
};

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(pow(x_distance, 2) + pow(y_distance, 2));
	return distance;
}
Point operator+(const Point& left, const Point& right)
{
	Point res;
	res.set_x(left.get_x() + right.get_x());
	res.set_y(left.get_y() + right.get_y());
	return res;
}
//#define STRUCT_POINT
//#define DISTANCE
//#define CONSTRUCTORS_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
	int a; //���������� ���������� 'a' ���� 'int'
	//type name;
	Point A; //���������� ���������� 'A' ���� 'Point'
			 // ���������� ������� 'A' ���� 'Point'
			 // ���������� ���������� 'A' ��������� 'Point' 
	A.x = 2;
	A.y = 3;

	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif // 

#ifdef DISTANCE
	Point A; //Default constructor
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;
	Point B; //Default constructor
	B.set_x(7);
	B.set_y(8);
	cout << B.get_x() << "\t" << B.get_y() << endl;
	cout << delimiter << endl;
	cout << "���������� �� ����� � �� ����� �: " << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "���������� �� ����� B �� ����� A: " << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "���������� ����� ������� � � �: " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "���������� ����� ������� � � �: " << distance(B, A) << endl;
#endif // DISTANCE

#ifdef CONSTRUCTORS_CHECK
	Point A; //Default constructor /����������� �� ���������, ��� ����������
	A.print();
	cout << double() << endl;

	Point B(2, 3);
	B.print();

	Point C = 5;
	C.print();

	Point D = B; //CopyConstructor
	D.print();

	Point E;
	E = D;   //CopyAssignment (=)
	E.print();
#endif // CONSTRUCTORS_CHECK
	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;

	Point A, B, C;
	A = B = C = Point(2, 3);

	C = A + B;
	C.print();
	C++;
	C.print();
}			 