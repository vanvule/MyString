#define _CRT_SECURE_NO_WARNINGS

#ifndef _DO_AN_OOP_H_
#define _DO_AN_OOP_H_

#include<iostream>
using namespace std;
#include<iterator>
#include <stdexcept>

void menu();

int chon();
void run(int lenh);

class MyString
{

private:
	char* nstring;
	int nlength;
	int capacity;

	inline void setNewCapacity(size_t nlength);

public:
	typedef unsigned int uint_t;
	static const uint_t INITIAL_CAPACITY = 20;

	MyString();
	MyString(const char * aCString);
	MyString(int numChars);
	MyString(const MyString & original);
	MyString(const char str[], uint_t n);
	~MyString();

	using iterator = char*;
	using const_iterator = const char*;
	iterator begin();
	const_iterator begin() const;
	const_iterator cbegin() const;
	iterator end();
	const_iterator end() const;
	const_iterator cend() const;

	void swap(MyString &from);

	MyString& append(const MyString &str);
	MyString& append(const MyString &str, size_t index, size_t n);
	MyString& append(size_t n, char ch);
	MyString& append(const char* s, size_t n);
	MyString& append(const char * aCString);

	void assign(const MyString & aMyString);
	MyString& assign(const MyString &str, uint_t index, uint_t n);
	void assign(const char * const aCString);
	MyString& assign(const char *chars, uint_t n);
	MyString& assign(uint_t n, char ch);

	char& at(size_t pos);
	const char& at(size_t pos) const;

	char& back();
	const char& back() const;

	void clear();
	void clear(int newCapacity);

	int compare(const MyString & aMyString);
	int compare(uint_t index, uint_t n, const MyString &str, uint_t index_str, uint_t n_str) const;
	int compare(uint_t index, uint_t n, const MyString &str)const;

	uint_t copy(char *s, uint_t index, uint_t n = 0) const;

	const char* c_str() const;
	inline const char *data() const;
	bool empty() const;
	MyString& erase(uint_t index = 0, uint_t n = -1);
	iterator erase(const_iterator p);
	iterator erase(iterator first, iterator last); 
	bool equals(const MyString & aMyString) const;
	bool equals(const char * const aCString) const;


	size_t find(const MyString& str) const;
	size_t find(const char* s) const;
	size_t find(const char* s, size_t pos, size_t n) const;
	size_t find(char c) const;

	size_t find_first_not_of(const MyString& st) const;
	size_t find_first_not_of(const char*) const;
	size_t find_first_not_of(const char* s, size_t pos, size_t n) const;
	size_t find_first_not_of(char c, size_t pos = 0) const;

	size_t find_first_of(const MyString& str, size_t pos = 0) const;
	size_t find_first_of(const char* s, size_t pos = 0) const;
	size_t find_first_of(const char* s, size_t pos, size_t n) const;
	size_t find_first_of(char c, size_t pos = 0) const;

	size_t find_last_not_of(const MyString& str, size_t pos = npos) const;
	size_t find_last_not_of(const char* s, size_t pos = npos) const;
	size_t find_last_not_of(const char* s, size_t pos, size_t n) const;
	size_t find_last_not_of(char c, size_t pos = npos) const;

	size_t find_last_of(const MyString& str, size_t pos = npos) const;
	size_t find_last_of(const char* s, size_t pos = npos) const;
	size_t find_last_of(const char* s, size_t pos, size_t n) const;
	size_t find_last_of(char c, size_t pos = npos) const;

	char& front();
	const char& front() const;

	void insert(const MyString & aMyString, int index);

	size_t length() const;

	

	void pop_back();
	void push_back(char c);

	MyString& replace(size_t pos, size_t len, const MyString& str);
	MyString& replace(iterator i1, iterator i2, const MyString& str);
	MyString& replace(size_t pos, size_t len, const MyString& str, size_t subpos, size_t sublen);
	MyString& replace(size_t pos, size_t len, const char* s);
	MyString& replace(iterator i1, iterator i2, const char* s);
	MyString& replace(size_t pos, size_t len, const char* s, size_t n);
	MyString& replace(iterator i1, iterator i2, const char* s, size_t n);
	MyString& replace(size_t pos, size_t len, size_t n, char c);
	MyString& replace(iterator i1, iterator i2, size_t n, char c);

	void reserve(size_t n);
	void resize(size_t n);
	void resize(size_t n, char c);
	int size();

	MyString substr(size_t startIndex = 0, size_t numChars = npos) const;


	static const size_t npos = -1;

	MyString& operator= (const MyString & aMyString);
	MyString operator= (const char * const aCString);



	
	MyString& operator+= (const MyString& aMyString);
	MyString& operator+= (const char* s);
	MyString& operator+= (const char c);
	
	char  operator[] (size_t index) const;
	char& operator[] (size_t index);




	friend ostream& operator << (ostream & OS, const MyString &S);
	friend istream& operator >> (istream & IS, MyString &S);

	friend MyString operator+ (const MyString& lhs, const MyString& rhs);
	friend MyString operator+ (const MyString& lhs, char          rhs);
	friend MyString operator+ (const MyString& lhs, const char*   rhs);
	friend MyString operator+ (char          lhs, const MyString& rhs);
	friend MyString operator+ (const char*   lhs, const MyString& rhs);

	friend bool operator== (const MyString& lhs, const MyString& rhs);
	friend bool operator== (const MyString& lhs, char          rhs);
	friend bool operator== (const MyString& lhs, const char*   rhs);
	friend bool operator== (char          lhs, const MyString& rhs);
	friend bool operator== (const char*   lhs, const MyString& rhs);

	friend bool operator> (const MyString& lhs, const MyString& rhs);
	friend bool operator> (const MyString& lhs, char          rhs);
	friend bool operator> (const MyString& lhs, const char*   rhs);
	friend bool operator> (char          lhs, const MyString& rhs);
	friend bool operator> (const char*   lhs, const MyString& rhs);

	friend bool operator!= (const MyString& lhs, const MyString& rhs);
	friend bool operator!= (const MyString& lhs, char          rhs);
	friend bool operator!= (const MyString& lhs, const char*   rhs);
	friend bool operator!= (char          lhs, const MyString& rhs);
	friend bool operator!= (const char*   lhs, const MyString& rhs);

	friend bool operator< (const MyString& lhs, const MyString& rhs);
	friend bool operator< (const MyString& lhs, char          rhs);
	friend bool operator< (const MyString& lhs, const char*   rhs);
	friend bool operator< (char          lhs, const MyString& rhs);
	friend bool operator< (const char*   lhs, const MyString& rhs);

	friend bool operator<= (const MyString& lhs, const MyString& rhs);
	friend bool operator<= (const MyString& lhs, char          rhs);
	friend bool operator<= (const MyString& lhs, const char*   rhs);
	friend bool operator<= (char          lhs, const MyString& rhs);
	friend bool operator<= (const char*   lhs, const MyString& rhs);

	friend bool operator>= (const MyString& lhs, const MyString& rhs);
	friend bool operator>= (const MyString& lhs, char          rhs);
	friend bool operator>= (const MyString& lhs, const char*   rhs);
	friend bool operator>= (char          lhs, const MyString& rhs);
	friend bool operator>= (const char*   lhs, const MyString& rhs);

};


#endif
