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
	assert(index >= 0 && index < size && "index out of range");
	return data[index];
	
}

String String::operator+(String s)
{
	String a = String();
	if (a.memorySize <= this->length() + s.length() + 1)
	{
		a.memorySize = (this->length() + s.length() + 1)*2;
		delete[] a.data;
		a.data = new char[a.memorySize];
	}
	strcpy(a.data, this->data);
	strcpy(a.data + this->length(), s.data);
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
		s1.memorySize = (index + 1)*2;
		delete[] s1.data;	
		s1.data = new char[s1.memorySize];
	}
	if (s2.memorySize < this->length() - index - 1)
	{
		s2.memorySize = (this->length() - index - 1)*2;
		delete[] s2.data;
		s2.data = new char[s2.memorySize];
	}
	strncpy(s1.data, this->data, index);
	strcpy(s2.data, this->data + index + 1);
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
		memorySize = size*2;
	}
	data = new char[memorySize];
	strcpy(data, input);
}

String::String()
{
	memorySize = 100;
	data = new char[memorySize];
	size = 0;
	data[0] = '\0';
}

