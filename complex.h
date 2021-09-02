/*complex.h*/
/*class without pointer member*/
#ifndef __COMPLEX__
#define __COMPLEX__

class complex
{
public:	
	/*构造函数*/
	complex(double r = 0; double i = 0)
	:re(r),im(i) 	//Initialization list
	{}
	complex& operator += (const complex&);	//成员函数声明，加法，passed&return by reference，返回类型为complex&
	
	double real() const {return re;}		//返回实部，不改变值，用const
	double imag() const {return im;}		//返回虚部，不改变值，用const
private:
	double re, im;	//数据

	friend complex& __doapl(complex*, const complex&);	//友元，可直接取出private中的数据，返回类型为complex&
};

/*—— —— —— —— —— —— —— —— —— —— —— —— —— —— 成员函数的加法 —— —— —— —— —— —— —— —— —— —— —— —— —— —— —— —— —— —— ——*/

inline complex&			/*前置声明*/
__doapl(complex* ths, const complex& r)
{
	ths->re += r.re;
	ths->im += r.im;
	return *ths;
}

/*成员函数定义*/
inline complex&			//(return type)：非(local object)[函数中新产生的]就可以(return by reference)；class本体之外定义，需要加上inline（内联函数）
complex::operator += (const complex& r)		//成员函数的参数只写右数
{
	return __doapl(this, r);
}

/*—— —— —— —— —— —— —— —— —— —— —— —— —— —— 非成员函数的加法 —— —— —— —— —— —— —— —— —— —— —— —— —— —— —— —— —— —— ——*/

/*非成员函数的定义，选择非成员函数考虑到加法可能在复数与实数之间进行，有许多种*/
inline complex			//(return type)：(local object)[函数中新产生的]只能(return by value)
operator + (const complex& x, const complex& y)		/*复数加复数*/
{
	return complex( real(x) + real(y), imag(x) + imag(y) );		//创建一个新的complex类的对象（临时对象）
}

inline complex			//(return type)：(local object)[函数中新产生的]只能(return by value)
operator + (const complex& x, double y)		/*复数加实数*/
{
	return complex( real(x) + y, imag(x) );		//创建一个新的complex类的对象（临时对象）
}

inline complex			//(return type)：(local object)[函数中新产生的]只能(return by value)
operator + (double x, const complex& y)		/*实数加复数*/
{
	return complex( x + real(y), imag(y) );		//创建一个新的complex类的对象（临时对象）
}

/*—— —— —— —— —— —— —— —— —— —— —— —— —— —— 输出 —— —— —— —— —— —— —— —— —— —— —— —— —— —— —— —— —— —— ——*/
/*非成员函数的定义*/
#include <iostream.h>
ostream&		//(return type)：非(local object)[函数中新产生的]就可以(return by reference)
operator << (ostream& os, const complex& x)
{
	return os << '(' << real(x) << ',' << imag(x) << ')';	//数据输出到屏幕上
}

#endif