#include<iostream>
#include<cstring>
using namespace std;
class String {
	char *s;
	int currentLength;
public:
	String()
	{
		currentLength = 1;
		s = new char[currentLength];
		strcpy(s, "");
	}
	String(const char *str)
	{
		currentLength = strlen(str) + 1;
		s = new char[currentLength];
		strcpy(s, str);
	}
	String(const String &str)
	{
		currentLength=str.currentLength;
		s = new char[currentLength];
		strcpy(s,str.s);
	}
	~String()
	{
		delete[] s;
	}
	int length()
	{
		return currentLength-1;
	}
	void in()
	{
		scanf("\n%[^\n]", s);
		while ((getchar()) != '\n');
	}
	void out()
	{
		puts(s);
	}
	void push_back(char c)
	{
		char* temp = new char[++currentLength];
		strcpy(temp, s);
		delete[] s;
		s = temp;
		s[currentLength - 2] = c;
		s[currentLength - 1] = '\0';
	}
	void push_front(char c)
	{
		char* temp = new char[++currentLength];
		temp[0] = c;temp[1]='\0';
		strcat(temp,s);
		delete[] s;
		s = temp;
	}
	void pop_back()
	{
		if (currentLength == 1)
		{
		}
		else
		{
			currentLength--;
			s[currentLength-1]='\0';
		}
	}
	void pop_front()
	{
		if (currentLength == 1)
		{
		}
		else
		{
			currentLength--;
			for (int i = 0; i < currentLength ; i++)
			{
				s[i] = s[i + 1];
			}
			s[currentLength-1]='\0';
		}
	}
	char back()
	{
		return s[currentLength - 1];
	}
	char front()
	{
		return s[0];
	}
	char charAt(int index)
	{
		return s[index];
	}
	bool empty()
	{
		return currentLength == 1;
	}
	char& operator[](char index)
	{
		return s[index];
	}
	void operator=(const char* str)
	{
		currentLength = strlen(str) + 1;
		s = new char[currentLength];
		strcpy(s, str);
	}
	void operator=(String str)
	{
		currentLength=str.currentLength;
		s = new char[currentLength];
		strcpy(s,str.s);
	}

	void operator+=(char c)
	{
		char* temp = new char[++currentLength];
		strcpy(temp, s);
		delete[] s;
		s = temp;
		s[currentLength - 2] = c;
		s[currentLength - 1] = '\0';
	}
	void operator+=(const char* str)
	{
		currentLength+=strlen(str);
		char* temp = new char[currentLength];
		strcpy(temp, s);
		strcat(temp,str);
		delete[] s;
		s = temp;
	}
	void operator--()
	{
		if (currentLength == 1)
		{
		}
		else
		{
			currentLength--;
			for (int i = 0; i < currentLength ; i++)
			{
				s[i] = s[i + 1];
			}
			s[currentLength-1]='\0';
		}
		
	}
	void operator--(int)
	{
		if (currentLength == 1)
		{
		}
		else
		{
			currentLength--;
			s[currentLength-1]='\0';
		}
	}
	String operator+(char c)
	{
		char* temp = new char[currentLength + 1];
		strcpy(temp, s);
		temp[currentLength - 1] = c;
		temp[currentLength] = '\0';
		return temp;
	}
	String operator+(const char* str)
	{
		char* temp = new char[currentLength + strlen(str)];
		strcpy(temp, s);
		strcat(temp, str);
		return temp;
	}
	friend String operator+(char c, String str);
	friend String operator+(const char* c, String str);
};

String operator+(char c, String str)
{
	cout<<c<<" "<<str.s<<endl;
	char* temp = new char[str.currentLength + 1];
	for (int i = 0; i < str.currentLength; i++)
	{
		temp[i + 1] = str.s[i];
	}
	temp[0] = c;
	cout<<temp<<endl;
	return temp;
}
String operator+(const char* str1, String str2)
{
	char* temp = new char[str2.currentLength + strlen(str1)];
	strcpy(temp,str1);
	strcat(temp,str2.s);
	return temp;
}
int main()
{
	String s("DIhu");
	String p(s);
	s.push_front('a');
	s.out();
	s.push_back('d');
	s.out();
	s.pop_back();
	s.out();
	s.pop_front();
	s.out();
	s+='c';
	s.out();
	s+="Ohi";
	s.out();
	s=s+'h';
	s.out();
	s='c'+s;
	s.out();
	s="Amrin"+s;
	s.out();
	s--;
	--s;
	s+="Ohi";
	s.out();
}