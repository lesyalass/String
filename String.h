#pragma once
#include <string.h>

class String
{
	public:
		int length();
		String();
		String(const char* input);
		char* c_str();
		int countChar(char c);
		int findFirstOf(char c);
		char operator[](int index);
		String operator+(String s);
		String* split(int index);
		bool findstr(char* str);

	private:
		int size;
		char* data;	
		int memorySize;
};

