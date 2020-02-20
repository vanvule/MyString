#include"Header.h"

char MyString::operator[] (size_t index) const
{
	if (index < 0)
		throw std::runtime_error("RAGEQUIT index is < 0");
	if (index >= nlength)
		throw std::runtime_error("RAGEQUIT index is >= nlength");
	return nstring[index];
}

char& MyString::operator[] (size_t j)
{
	if (j >= nlength) throw 1;
	return nstring[j];
}

MyString operator + (const MyString& s1, const MyString &s2)
{

	MyString result;
	result += s1;
	result += s2;
	return result;
}

MyString operator+ (const MyString& lhs, char rhs)
{
	return MyString(lhs) += MyString(rhs);
}

MyString operator+ (const MyString& lhs, const char* rhs)
{
	return MyString(lhs) += MyString(rhs);
}

MyString operator+ (char lhs, const MyString& rhs)
{
	return MyString(lhs) += rhs;
}
MyString operator+ (const char* lhs, const MyString& rhs)
{
	return MyString(lhs) += rhs;
}



bool operator == (const MyString & S1, const MyString & S2)
{
	if (S1.nlength == S2.nlength)
	{
		short counter1 = S1.nlength;
		int counter2 = 0;
		int i = 0;
		while (i != counter1)
		{
			if (S1.nstring[i] != S2.nstring[i]){ counter2++; }
			i++;
		}
		cout << i << " " << counter2 << endl;
		if (counter2 != 0) { return false; }
		else{ return true; }
	}
	else { return false; }

}

bool operator== (const MyString& lhs, char rhs)
{
	return (lhs == MyString(rhs));
}

bool operator== (const MyString& lhs, const char* rhs)
{
	return (lhs == MyString(rhs));
}

bool operator== (char lhs, const MyString& rhs)
{
	return (MyString(lhs) == rhs);
}

bool operator== (const char* lhs, const MyString& rhs)
{
	return (MyString(lhs) == rhs);
}



bool operator> (const MyString& lhs, const MyString& rhs)
{
	unsigned cap = (lhs.length() < rhs.length()) ? lhs.length() : rhs.length();
	unsigned n = 0;
	while ((n < cap) && (lhs[n] == rhs[n])) n++;
	if (n == cap) return (lhs.length() > rhs.length());

	if ((('A' <= lhs[n] && lhs[n] <= 'Z') || ('a' <= lhs[n] && lhs[n] <= 'z')) &&
		(('A' <= rhs[n] && rhs[n] <= 'Z') || ('a' <= rhs[n] && rhs[n] <= 'z')))
	{
		char A = (lhs[n] & ~32);
		char B = (rhs[n] & ~32);
		if (A != B) return (A > B);
	}
	return lhs[n] > rhs[n];
}

bool operator> (const MyString& lhs, char rhs)
{
	return (lhs > MyString(rhs));
}

bool operator> (const MyString& lhs, const char* rhs)
{
	return (lhs > MyString(rhs));
}

bool operator> (char lhs, const MyString& rhs)
{
	return (MyString(lhs) > rhs);
}

bool operator> (const char* lhs, const MyString& rhs)
{
	return (MyString(lhs) > rhs);
}



bool operator!= (const MyString& lhs, const MyString& rhs)
{
	return !(lhs == rhs);
}

bool operator!= (const MyString& lhs, char rhs)
{
	return !(lhs == rhs);
}

bool operator!= (const MyString& lhs, const char* rhs)
{
	return !(lhs == rhs);
}

bool operator!= (char lhs, const MyString& rhs)
{
	return !(lhs == rhs);
}

bool operator!= (const char* lhs, const MyString& rhs)
{
	return !(lhs == rhs);
}



bool operator< (const MyString& lhs, const MyString& rhs)
{
	return !(lhs == rhs) && !(lhs > rhs);
}

bool operator< (const MyString& lhs, char rhs)
{
	return !(lhs == rhs) && !(lhs > rhs);
}

bool operator< (const MyString& lhs, const char* rhs)
{
	return !(lhs == rhs) && !(lhs > rhs);
}

bool operator< (char lhs, const MyString& rhs)
{
	return !(lhs == rhs) && !(lhs > rhs);
}

bool operator< (const char* lhs, const MyString& rhs)
{
	return !(lhs == rhs) && !(lhs > rhs);
}



bool operator<= (const MyString& lhs, const MyString& rhs)
{
	return !(lhs > rhs);
}

bool operator<= (const MyString& lhs, char rhs)
{
	return !(lhs > rhs);
}

bool operator<= (const MyString& lhs, const char* rhs)
{
	return !(lhs > rhs);
}

bool operator<= (char lhs, const MyString& rhs)
{
	return !(lhs > rhs);
}

bool operator<= (const char* lhs, const MyString& rhs)
{
	return !(lhs > rhs);
}



bool operator>= (const MyString& lhs, const MyString& rhs)
{
	return (lhs == rhs) || (lhs > rhs);
}

bool operator>= (const MyString& lhs, char rhs)
{
	return (lhs == rhs) || (lhs > rhs);
}

bool operator>= (const MyString& lhs, const char* rhs)
{
	return (lhs == rhs) || (lhs > rhs);
}

bool operator>= (char lhs, const MyString& rhs)
{
	return (lhs == rhs) || (lhs > rhs);
}

bool operator>= (const char* lhs, const MyString& rhs)
{
	return (lhs == rhs) || (lhs > rhs);
}
