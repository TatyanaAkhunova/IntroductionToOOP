#include<iostream>
//class DynArray
//{
//	int* arr;
//	int size;
//public:
//	DynArray(int sizeP) : arr{ new int[sizeP] {} }, size{ sizeP }
//	{
//		std::cout << "DynArr constructed for " << size << " elements, for " << this << '\n';
//	}
//	DynArray():DynArray(5){}
//	DynArray(const DynArray& object) :arr{ new int[object.size] }, size{ object.size }
//	{
//		/*� ������ ��������������� ����� ������ ���� �������� ����� ���� ������������
//		������ ������� �������,��� � ���������� ���������� ������ DynArray
//		��������� ������ �������� �������� �� ������������� ����� ������ �� �����
//		����������*/
//		for (int i{ 0 }; i < size; i++)
//			arr[i] = object.arr[i];
//		std::cout << "DynArray copy constructed for " << size << " elements, for " << this << '\n';
//	}
//	DynArray& operator=(const DynArray& object)
//	{
//		//�������� �� ����������������
//		if (!(this == &object))
//		{
//			//��������� �� ������������� "����������������" ���� ������, ���������� ���
//			//��������� ������
//			if (size != object.size)
//			{
//				/*� ������ ������������� "�����������������" ���������� ����������
//				������, ��� ���������� ��������� �������� ������������� �������*/
//				delete[]arr;
//				/*�������� ����� ���� ������ �������� ������� ����������� �������*/
//				arr = new int[object.size];
//			}
//			size = object.size;
//			/*��������� ������ �������� �������� �� ������������� ����� ������ �� 
//			����� ����������*/
//			for (int i = 0; i < size; i++)
//				
//			arr[i] = object.arr[i];
//		}
//		std::cout << "DynArr copy assigned fof " << size << " elements, for " << this << '\n';
//		return *this;
//	}
//	int getElem(int idx)const
//	{
//		return arr[idx];
//	}
//	void setElem(int idx, int val) { arr[idx] = val; }
//	void print()const;
//	void randomize();
//	~DynArray()
//	{
//		std::cout << "Try to free memory from DynArray for " << arr << "pointer \n";
//		delete[]arr;
//		std::cout << "DynArr dectructed for " << size << "elements, for " << this << '\n';
//	}
//	};
//		void DynArray::print()const
//		{
//			for (int i = 0; i < size; i++)
//				std::cout << arr[i] << ' ';
//			std::cout << '\n';
//		}
//		void DynArray::randomize()
//		{
//			for (int i = 0; i < size; i++)
//				arr[i] = rand() % 10;
//		}
//		DynArray arrayFactory(int arrSize)
//		{
//			DynArray arr{ arrSize };
//			arr.randomize();
//			return arr;
//	}
//int main()
//	{
//	/*DynArray ar1{ 10 };
//	ar1.randomize();
//	std::cout << "ar1 elements: ";
//	ar1.print();
//	DynArray ar2{ ar1 };
//	std::cout << "arr2 elements: ";
//	ar2.print();
//	std::cout << "Copy-assigment test\n";
//	DynArray ar3{ 5 };
//	std::cout << "ar3 elements before copy: ";
//	ar3.print();
//	ar3 = ar2;*/
//	DynArray ar1{ arrayFactory(10) };
//	std::cout << "ar1 elements: ";
//	ar1.print();
//	return 0;
//	}


/*
int main()
{
	int x{ 42 };
	int& refX{ x };
	const int& cRefX{ x };
	const int& cRefXX{ x + 24 };
	std::cout << x << '\n' << refX << '\n' << cRefX << '\n' << cRefXX << '\n';

}
//RefType&& refName{rvalue object}
*/

/*int max(int a, int b)
{
	return a > b ? a:b;
}
int main()
{
	int&& rvalRef{ 2 + 3 };//��� ������� lvalue, �� ��� ����������� ����������� � �������� �
	//� rvalue ��������
	rvalRef += 3;//��������� �� ������� ������ � ����������� ���-�� ������
	std::cout << rvalRef << '\n';

	int&& res{ max(3,5) };//������������ ���������
	res += max(6, 4);
	std::cout << res << '\n';
	int x{ 42 };//����� ����������� �������� rvalue 
	//�������� ����������� ������� ������, ��� ������ �����-�� ��������
	int&& rvalRef1{std::move(x)};//rval - ������� � ��������� ������� ������, � ��� ��������� ��������
	// ��� ���������
	std::cout << rvalRef1 << '\n';
	//int&& rvalBad{res};
	int& lvalRef{ res };
	std::cout << lvalRef << '\n';
	return 0;
}*/

//������� ��� ��������� ��������� �������� lvalue � rvalue 
//funA overloads with rvalue overload

/*using namespace std;
void funA(int& val)
{
	cout << "FunA() called for int&\n";
}
void funA(const int& val)
{
	cout << "funA() called for const int&\n";
}
void funA(int&& val)
{
	cout << "fun() called for int&&\n";
}
//funB overload without rvalue overload
void funB(int& val)
{
	cout << "funB() called for int&\n";
}
void funB(const int& val)
{
	cout << "funB() called for const int&\n";
}

int main()
{
	int val{ 42 };
	const int cVal{ 26 };
	cout << "funA overloads with rvalue overload\n";
	cout << "lvalue\n";
	funA(val);//lvalue-> int&
	cout << "const lvalue\n";
	funA(cVal);//const lvalue->const int&
	cout << "rvalue\n";
	funA(80 + 1);//rvalue->int&&
	cout << "moved lvalue\n";
	funA(move(val));//moved lvalue->int&&
	cout << endl;
	cout << "funB overloads without rvalue overload:\n";
	cout << "lvalue\n";
	funB(val);//lval->int&&
	cout << "const lvalue\n";
	funB(cVal);//const lvalue->const int&
	cout << "rvalue\n";
	funB(move(val));//moved lvalue->const int&
	return 0;
}*/

//��������������� DynArray
using namespace std;
class DynArray
{
	int* arr;
	int size;
public:
	DynArray(int sizeP) : arr{ new int[sizeP] }, size{ sizeP }
	{
		cout << "DynArr constructed for " << size << " element, for " << this << endl;
	}
	DynArray():DynArray(5){}
	DynArray(const DynArray& object) :arr{ new int[object.size] }, size{ object.size }
	{
/*� ������ ���� ��������������� ����� ������ ���� �������� ����� ���� ������������
������ ���� �� ��������, ��� � � ���������� ���������� ������ DynArray.
��������� ������ �������� �������� �� ������������� ����� ������ �� ����� ����������*/
		for (int i = 0; i < size; i++)
			arr[i] = object.arr[i];
		cout << "DynArr copy constructed for " << size << " elements, for" << this << endl;
	}
	//����������� �����������
	DynArray(DynArray&& object) :arr{ object.arr }, size{ object.size } 
		/*�������� ��������� �� ���������� � �������� ������� ���� ������������ ������
		� ������ ����� ����� � ���������������� ������������� ������*/
	{
		/*"��������" � ��������� ������� ����� �������� ������ ������������ ������
		� ������������� ������ ����� � 0*/
		object.arr = nullptr;//������������ �������� ��������� � ���� ������������ ������ ��������� �������
		object.size = 0;//��������������� ������=0
		cout << "DynArr move constructed for " << size << " elements, for " << this << endl;
		//� ����������� ����������� ������ ��������� ����� ������������� rvalue ������, �.� �� ���� DynArray&&
	}
	DynArray& operator=(const DynArray& object)
	{
		if (!(this == &object))
		{
			if (size != object.size)
			{
				delete[] arr;
				arr = new int[object.size];
			}
			size = object.size;
			/* �������������� ������ ���������� ������� ����� ����������� � �����
			������ ������� ���������� ����� ���� �������������� ����������*/
			//��������� �� ������ �������-���������� �����������
			int* dest{ arr };
			//��������� �� ������ �������-��������� �����������
			int* src{ object.arr };
			/*����������� ��������� �� ��������� �� ��������� ���������
			� �������-���������� - "����� ������� ���������"*/
			int* const end{ arr + size };

			//���� ��������� "����������" �� ��������� "�����"....
			while (dest < end)
			{
				/*������ �� ������ ��������� dest ��������, �������� �� ������
				src ����� �������������� ��� ���������*/
				*dest++ = *src++;
			}
			// ������ �� obj.arr ����������� � arr.
		}
		cout << "DynArr copy assigned for " << size << "elements, for " << this << endl;
		return *this;
	}
	int getElem(int idx) const { return arr[idx]; }
	void setElem(int idx, int val) { arr[idx] = val; }
	void print()const;
	void randomize();
	~DynArray()
	{
		cout << "Try to free memory from DynArray for " << arr << " pointer\n";
		delete[]arr;
		cout << "DinArr destructed for " << size << " elemebts, for" << this << endl;
	}
};
void DynArray::print()const
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << ' ';
	cout << endl;
}
void DynArray::randomize()//���������� �������
{
	for (int i = 0; i < size; i++)
		arr[i] = rand() % 10;
}
DynArray arrayFactory(int arrSize)//������� ������
{
	DynArray arr{ arrSize };
	arr.randomize();
	return arr;
}
int main()
{
	DynArray ar1{ arrayFactory(10) };
	cout << "ar1 elemebts: ";
	ar1.print();
	return 0;
}
