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
	int a; //���������� ���������� 'a' ���� 'int'
	//type name;
	Point A; //���������� ���������� 'A' ���� 'Point'
			 // ���������� ������� 'A' ���� 'Point'
			 // ���������� ���������� 'A' ��������� 'Point' 
	A.x = 2;// �������������
	A.y = 3;

	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif // 

	
}