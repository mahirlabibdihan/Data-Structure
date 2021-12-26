#include <iostream>
#include <cstring>
using namespace std;
class string // :public string
{
	char *s;
	int currentLength;
public:
	string()
	{
		currentLength = 1;
		s = new char[currentLength];
		strcpy(s, "");
	}
	string(const char *str)
	{
		currentLength = strlen(str) + 1;
		s = new char[currentLength];
		strcpy(s, str);
	}
	string(const string &str)
	{
		currentLength = str.currentLength;
		s = new char[currentLength];
		strcpy(s, str.s);
	}
	string(const char c)
	{
		currentLength = 2;
		s = new char[currentLength];
		s[0]=c;
	}
	~string()
	{
		delete[] s;
	}
	int length()
	{
		return currentLength - 1;
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
	void resize(int n)
	{
		char* temp = new char[n];
		strcpy(temp, s);
		delete[] s;
		s = temp;
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
		temp[0] = c; temp[1] = '\0';
		strcat(temp, s);
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
			s[currentLength - 1] = '\0';
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
			s[currentLength - 1] = '\0';
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
	void operator=(string str)
	{
		currentLength = str.currentLength;
		s = new char[currentLength];
		strcpy(s, str.s);
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
		currentLength += strlen(str);
		char* temp = new char[currentLength];
		strcpy(temp, s);
		strcat(temp, str);
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
			s[currentLength - 1] = '\0';
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
			s[currentLength - 1] = '\0';
		}
	}
	string operator+(char c)
	{
		char* temp = new char[currentLength + 1];
		strcpy(temp, s);
		temp[currentLength - 1] = c;
		temp[currentLength] = '\0';
		return temp;
	}
	string operator+(const char* str)
	{
		char* temp = new char[currentLength + strlen(str)];
		strcpy(temp, s);
		strcat(temp, str);
		return temp;
	}
	bool operator!= (const char* str){
		return s!=str;
	}
	bool operator!= (const string str){
		return s!=str.s;
	}
	bool operator!= (const char c){
		return s[0]!=c;
	}
	friend string operator+(char c, string str);
	friend string operator+(const char* c, string str);
	friend istream& operator>>(istream& in, string str);
	friend ostream& operator<<(ostream& out, string str);
};

istream& operator>>(istream& in, string str)
{
	in>>str.s;
	return in;
}
ostream& operator<<(ostream& out, string str)
{
	out<<str.s;
	return out;
}

string operator+(char c, string str)
{
	cout << c << " " << str.s << endl;
	char* temp = new char[str.currentLength + 1];
	for (int i = 0; i < str.currentLength; i++)
	{
		temp[i + 1] = str.s[i];
	}
	temp[0] = c;
	cout << temp << endl;
	return temp;
}
string operator+(const char* str1, string str2)
{
	char* temp = new char[str2.currentLength + strlen(str1)];
	strcpy(temp, str1);
	strcat(temp, str2.s);
	return temp;
}