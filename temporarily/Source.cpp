#include<iostream>
using namespace std;

struct Point
{
	double x;
	double y;

};

#define STRUCT_POINT
void main()
{
#ifdef STRUCT_POINT
	setlocale(LC_ALL, "");
	int a; //объявление переменной 'a' типа 'int'
	//type name;
	Point A; //объявление переменной 'A' типа 'Point'
			 // объявление объекта 'A' типа 'Point'
			 // объявление экземпляра 'A' структуры 'Point' 
	A.x = 2;// инициализация
	A.y = 3;

	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif // 

	
}