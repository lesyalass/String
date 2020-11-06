#include "String.h"
#include <iostream>

int String::length()
{
	return size;
}

char* String::c_str()
{
	return data;
}

int String::countChar(char c)
{
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		if (data[i] == c)
		{
			counter++;
		}
	}
	return counter;
}

int String::findFirstOf(char c)
{	
	for (int i = 0; i < size; i++)
	{
		if (data[i] == c)
		{
			return i;
		}
	}	
}

char String::operator[](int index)
{
	if (index >= 0 && index < size)
	{
		return data[index];
	}
	else
	{
		return '\0';
	}
}

String String::operator+(String s)
{
	String a = String();
	if (a.memorySize <= this->length() + s.length() + 1)
	{
		memorySize = this->length() + s.length() + 1;
		delete[] a.data;
		a.data = new char[memorySize];
	}
	strcpy_s(a.data, a.memorySize, this->data);
	strcpy_s(a.data + this->length(), a.memorySize - this->length(), s.data);
	return a;
}

String* String::split(int index)
{
	String s1 = String();
	String s2 = String();
	if (index >= this->length() || index < 0)
	{
		return NULL;
	}
	if (s1.memorySize < index + 1)
	{
		s1.memorySize = index + 1;
	}
	if (s2.memorySize < this->length() - index - 1)
	{
		s2.memorySize = this->length() - index - 1;
	}
	strncpy_s(s1.data, s1.memorySize, this->data, index);
	strcpy_s (s2.data, s2.memorySize, this->data + index + 1);
	String* result = new String[2];
	result[0] = s1;
	result[1] = s2;
	return result;
}

bool String::findstr(char* str)
{
	char* istr;
	istr = strstr(data, str);
	if (istr == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}

String::String(const char* input)
{
	memorySize = 100;	
	size = strlen(input);
	if (memorySize <= size)
	{
		memorySize = size;
	}
	data = new char[memorySize];
	strcpy_s(data, memorySize, input);
}

String::String()
{
	memorySize = 100;
	data = new char[memorySize];
	size = 0;
	data[0] = '\0';
}

