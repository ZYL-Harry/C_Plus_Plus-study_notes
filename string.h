/*string.h*/
/*class with pointer member*/
#ifndef __STRING__
#define __STRING__

class String
{
public:
	String(const char* cstr = 0);	//构造函数的声明，默认值设置为0
	String(const String& str);		//拷贝构造的声明
	String& operator = (const String& str);	//拷贝赋值的声明，返回值类型为String&
	~String();	//析构函数的声明
	char* get_c_str()  const { return m_data; }	//之后需要通过cout输出，通过该函数取出字符串的内容private
private:
	char* m_data;	//创建指针（4个字节）
	
};

/*—— —— —— —— —— —— —— —— —— —— —— —— —— —— 构造函数的定义 —— —— —— —— —— —— —— —— —— —— —— —— —— —— —— —— —— —— ——*/

#include< >		//用到了strlen()和strcpy()
inline	//没有return，单单 inline就行
String::String(const char* cstr = 0)
{
	if(cstr)
	{
		m_data = new char[strlen((cstr)+1];	//获得传进来的字符串（直接给出了字符串数据）的长度	，array new
		strcpy(m_data, cstr);
	}
	else	//空字符串也有一个字符'0'
	{
		m_data = new char[1];
		*m_data = '\0';			
	}
}

/*—— —— —— —— —— —— —— —— —— —— —— —— —— —— 析构函数的定义 —— —— —— —— —— —— —— —— —— —— —— —— —— —— —— —— —— —— ——*/

inline
String::~String()
{
	delete[] m_data;	//array delete
}

/*—— —— —— —— —— —— —— —— —— —— —— —— —— —— 拷贝构造函数的定义 —— —— —— —— —— —— —— —— —— —— —— —— —— —— —— —— —— —— ——*/

inline
String::String(const String& str)
{
	m_data = new char[strlen(str.m_data)+1];	//获得作为蓝本的字符串（只是给出字符串代表符，没有直接给出字符串数据）的长度
	strcpy(m_data, str.m_data);
}

/*—— —— —— —— —— —— —— —— —— —— —— —— —— —— 拷贝赋值的定义 —— —— —— —— —— —— —— —— —— —— —— —— —— —— —— —— —— —— ——*/

inline
String& String::operator=(const String& str)	//&：reference（typename后）
{
	/*自我检测：是不是自我赋值->不仅关乎效率还关乎是否正确*/
	if(this == &str)	//指针之间的比较，&：取地址addressof（object前）
		return *this;
	delete[] m_data;	//先删除目的端原来有的东西删除
	m_data = new char[strlen(str.m_data)+1];	//获得作为蓝本的字符串（只是给出字符串代表符，没有直接给出字符串数据）的长度
	strcpy(m_data, str.m_data);
	return *this;	//返回目的端
}

#endif	/*__STRING__*/