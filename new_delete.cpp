////#include <iostream>
////using namespace std;
////
////class Date
////{
////public:
////	Date(int year = 1900, int month = 1, int day = 1)
////		:_year(year)
////		,_month(month)
////		,_day(day)
////	{
////		++_scount;
////	}
////
////	Date(const Date& d)
////		:_year(d._year)
////		,_month(d._month)
////		,_day(d._day)
////	{
////		++_scount;
////	}
////	
////	// 没有this指针
////	static int GetCount()
////	{
////		return _scount;
////	}
////
////private:
////	int _year;
////	int _month;
////	int _day;
////
////	static int _scount;
////};
////
////int Date::_scount = 0;
////
////Date f()
////{
////	Date d;
////	return d;
////}
////
////int main()
////{
////	Date d1;
////	Date d2;
////	f();
////
////	//cout<<d1._scount<<endl;
////	//cout<<d2._scount<<endl;
////	//cout<<Date::_scount<<endl;
////	//cout<<Date::GetCount()<<endl;
////	cout<<sizeof(d1)<<endl;
////
////	return 0;
////}
//
//#include <iostream>
//using namespace std;
//
//class Date
//{
//public:
//	Date()
//	{
//		cout<<"Date()"<<endl;
//	}
//
//	Date(const Date& d)
//	{
//		cout<<"Date(const Date& d)"<<endl;
//	}
//
//	Date& operator=(const Date& d)
//	{
//		cout<<"Date& operator=(const Date& d)"<<endl;
//		return *this;
//	}
//
//	~Date()
//	{
//		cout<<"~Date()"<<endl;
//	}
//};
//
//// 1.传参
//// 2.传返回值
//// 3.接收返回值
//void Func1(Date d)
//{}
//
//Date Func2()
//{
//	//Date d;
//	//return d;
//	return Date();
//}
//
//class AA
//{
//public:
//	AA()
//	{}
//
//	AA(const AA& a)
//	{
//		cout<<"AA(const AA&);"<<endl;
//	}
//
//	AA& operator=(const AA& a)
//	{
//		cout<<"AA& operator=(const AA&)"<<endl;
//		return *this;
//	}
//};
//
//AA f (AA a)
//{
//	return a ;
//}
//void Test1 ()
//{
//	AA a1 ;
//	a1 = f(a1);
//}
//void Test2 ()
//{
//	AA a1 ;
//	AA a2 = f(a1);
//}
//
//void Test3 ()
//{
//	AA a1 ;
//	AA a2 = f(f(a1));
//}
//
//int main()
//{
//	//Func1(Date());
//
//
//	//Date ret;
//	//ret = Func2();
//
//	//Date ret = Func2();
//	//Test3();
//
//	//int* p1 = new int;
//	//int* p2 = new int(10);
//	//int* p3 = new int[10];
//
//	//delete p1;
//	//delete p2;
//	//delete[] p3;
//
//	/*int* p4 = new int;
//	int* p5 = new int(3);
//	int* p6 = new int[3];
//	int* p7 = (int*) malloc(sizeof (int));
//
//	delete[] p4 ;
//	free(p5 );
//	delete p6 ;
//	delete p7 ;*/
//
//	return 0;
//}


#include <iostream>
#include <memory>
using namespace std;

//1. 内置类型，new -- malloc 本质没有区别
//2. 自定义类型
class AA
{
public:
	AA()
	{
		cout<<"AA()"<<endl;
	}

	~AA()
	{
		cout<<"~AA()"<<endl;
	}
};

class MyVector
{
public:
	MyVector(size_t n)
	{
		_a = new int[n];

		cout<<"MyVector()"<<endl;
	}

	~MyVector()
	{
		delete[] _a;

		cout<<"~MyVector()"<<endl;
	}

private:
	int* _a;
};

int main()
{
	//// 1.动态开空间
	//AA* p1 = (AA*)malloc(sizeof(AA));
	//free(p1);

	//// 1.动态开空间
	//// 2.调用构造函数(初始化)和析构函数(清理)
	//AA* p2 = new AA;
	//delete p2;

	//MyVector* pv = new MyVector(10);
	////delete[] pv;
	//free(pv);

	//try
	//{
	//	char* p3 = (char*)malloc(0x7fffffff);
	//	//char* p4 = new char[0x7fffffff];
	//}
	//catch (exception& e)
	//{
	//	cout<<e.what()<<endl;
	//}

	// 语言坑
	//int* p5 = (int*)operator new(4);
	//int* p6 = (int*)malloc(4);

	// 1.开空间->operator new == malloc + 失败抛异常
	// 2.调用构造
	//AA* p7 = new AA; // call operator new() call AA()

	// 3.调析构函数
	// 4.释放空间 operator delete-> free
	//delete p7; 

	//AA* p8 = new AA[10];
	//delete[] p8;
	//delete p8;

	//int* p9 = new int[10];
	//delete p9;
	
	//
	allocator<AA> alloc;
	AA* p10 = alloc.allocate(1); // 内存池
	new(p10)AA; // 定位new replacement

	return 0;
}
