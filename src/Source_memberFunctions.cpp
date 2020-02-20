#include"Header.h"

MyString::MyString()
{
	capacity = 16;
	nlength = 0;
	nstring = new char[capacity + 1];
	nstring[nlength] = '\0';
}

MyString::MyString(const char *aCString)
{
	int numCharsToCopy = strlen(aCString);
	if (numCharsToCopy > 16)
		capacity = numCharsToCopy;
	else
		capacity = 16;

	nlength = numCharsToCopy;
	nstring = new char[capacity + 1];
	for (int i = 0; i < nlength; i++)
	{
		nstring[i] = aCString[i];
	}
	//strcpy(nstring, aCString);
	nstring[nlength] = NULL;
}

MyString::MyString(const char str[], uint_t n) : nlength(n)
{
	capacity = INITIAL_CAPACITY;
	while (n + 1 > capacity){
		capacity *= 2;
	}
	nstring = new char[capacity];
	memcpy(nstring, str, n);
	nstring[n] = '\0';
}


// takes an int argument
// initializes capacity to numChars chars
// initializes this MyString to an empty MyString
MyString::MyString(int NumChars)
{
	if (NumChars < 0)
		throw std::runtime_error("RAGEQUIT Negative string length given.");
	capacity = NumChars;
	nlength = 0;
	nstring = new char[capacity + 1];
	nstring[nlength] = '\0';
}

MyString::MyString(const MyString &original)
{
	capacity = original.capacity;	// Copy capacity from original
	nlength = original.nlength;	// Copy length from original
	nstring = new char[nlength];
	for (int i = 0; i < (nlength - 1); i++)
	{
		nstring[i] = original.nstring[i];
	}
	//strcpy(nstring, original.nstring);
	//nstring[nlength] = '\0';
	if (nstring[nlength - 1] != '\0')
		nstring[nlength - 1] = '\0';
}

MyString::~MyString() {
	delete[]nstring;
}

MyString::iterator MyString::begin()
{
	return &nstring[0];
}

MyString::const_iterator MyString::begin() const
{
	return &nstring[0];
}

MyString::const_iterator MyString::cbegin() const
{
	return &nstring[0];
}

MyString::iterator MyString::end()
{
	return &nstring[nlength];
}

MyString::const_iterator MyString::end() const
{
	return &nstring[nlength];
}

MyString::const_iterator MyString::cend() const
{
	return &nstring[nlength];
}

void MyString::swap(MyString &from)
{
	int lena = nlength;
	int lenb = from.nlength;
	char *temp1 = new char[lena];
	char *temp2 = new char[lenb];

	for (int i = 0; i < (lena - 1); i++)
	{
		temp1[i] = nstring[i];
	}
	if (temp1[lena - 1] != '\0'){ temp1[lena - 1] = '\0'; }

	for (int j = 0; j < (lenb - 1); j++)
	{
		temp2[j] = from.nstring[j];
	}
	if (temp2[lenb - 1] != '\0'){ temp2[lenb - 1] = '\0'; }

	delete[] nstring; delete[]from.nstring;

	nstring = new char[lenb];
	nlength = lenb;
	from.nstring = new char[lena];
	from.nlength = lena;

	for (int k = 0; k < (lenb - 1); k++)
	{
		nstring[k] = temp2[k];
	}
	if (nstring[lenb - 1] != '\0'){ nstring[lenb - 1] = '\0'; }

	for (int l = 0; l < (lena - 1); l++)
	{
		from.nstring[l] = temp1[l];
	}
	if (from.nstring[lena - 1] != '\0'){ from.nstring[lena - 1] = '\0'; }

	delete[]temp1; delete[]temp2;
}

char& MyString::back()
{
	return nstring[nlength - 1];
}

const char& MyString::back() const
{
	return nstring[nlength - 1];
}


char& MyString::front()
{
	return nstring[0];
}

const char& MyString::front() const
{
	return nstring[0];
}

/*void MyString::append(const MyString &aMyString)
{
MyString bMyString = MyString(aMyString);// prevent self-dereferencing
int totalLength = nlength + bMyString.nlength;
if (capacity < totalLength) {
capacity = totalLength;
char *oldString = new char[capacity + 1];
strcpy(oldString, nstring);
delete[] nstring;
nstring = oldString;
}
strcat(nstring, bMyString.nstring);
nlength = totalLength;
nstring[nlength] = '\0';
}*/
MyString& MyString::append(const MyString &str)
{
	size_t last_capacity = capacity;
	setNewCapacity(nlength + str.nlength + 1);
	if (capacity > last_capacity){
		char *result_str = new char[capacity];
		memcpy(result_str, nstring, nlength - 1);
		delete[] nstring;
		memcpy(result_str + nlength, str.nstring, str.nlength + 1);
		nstring = result_str;
	}
	else {
		memcpy(nstring + nlength, str.nstring, str.nlength + 1);
	}
	nlength += str.nlength;
	return *this;
}

MyString& MyString::append(const MyString &str, size_t index, size_t n)
{
	size_t len_copy = index + n > str.nlength ? str.nlength - index : n;
	size_t last_capacity = capacity;
	setNewCapacity(nlength + len_copy + 1);
	if (capacity > last_capacity){
		char *result_str = new char[capacity];
		memcpy(result_str, nstring, nlength);
		delete[] nstring;
		memcpy(result_str + nlength, str.nstring + index, len_copy);
		nlength += len_copy;
		nstring = result_str;
	}
	else
	{
		memcpy(nstring + nlength, str.nstring + index, len_copy);
		nlength += len_copy;
	}
	nstring[nlength] = '\0';
	return *this;
}

MyString& MyString::append(size_t n, char ch)
{
	size_t last_capacity = capacity;
	setNewCapacity(nlength + n + 1);
	if (capacity > last_capacity){
		char *result_str = new char[capacity];
		memcpy(result_str, nstring, nlength);
		delete[] nstring;
		memset(result_str + nlength, ch, n);
		nstring = result_str;
	}
	else {
		memset(nstring + nlength, ch, n);
	}
	nlength += n;
	nstring[nlength] = '\0';
	return *this;
}

/*void MyString::append(const char *aCString)
{
int totalLength = nlength + strlen(aCString);
if (nlength < totalLength) {
capacity = totalLength;
char * oldString = new char[capacity + 1];
strcpy(oldString, nstring);
delete[] nstring;
nstring = oldString;
}
strcat(nstring, aCString);
nlength = totalLength;
nstring[nlength] = '\0';
}*/
MyString& MyString::append(const char * aCString)
{
	return append(aCString, strlen(aCString));
}

MyString& MyString::append(const char* s, size_t n)
{
	size_t j = this->nlength;
	this->nlength = this->nlength + n;
	nstring = (char*)realloc(nstring, this->nlength + 1);
	for (size_t i = 0; j < this->nlength; j++, i++)
	{
		nstring[j] = s[i];
	}
	nstring[this->nlength] = '\0';
	return *this;
}

// Assign
// Takes a MyString argument
// makes this MyString a copy of aMyString
void MyString::assign(const MyString &aMyString)
{
	MyString bMyString = MyString(aMyString); 
	delete[] nstring;
	capacity = bMyString.capacity;	
	nlength = bMyString.nlength;	
	nstring = new char[capacity + 1];
	strcpy(nstring, bMyString.nstring);
	//	aMyString
	nstring[nlength] = '\0';	
}

MyString& MyString::assign(const MyString& str, uint_t index, uint_t n)
{
	uint_t len_copy = index + n > str.nlength ? str.nlength - index : n;
	uint_t last_capacity = capacity;
	setNewCapacity(len_copy + 1);
	if (capacity > last_capacity){
		delete[] nstring;
		nstring = new char[capacity];
	}
	memcpy(nstring, str.nstring + index, len_copy);
	nlength = len_copy;
	nstring[nlength] = '\0';
	return *this;
}

// Takes  a c style string argument
// makes this MyString contain the chars of aCString
void MyString::assign(const char *const aCString)
{
	// Two ints and a pointer!
	// There'd better be a null char at index _length

	// strlen does not count the null char.
	int numCharsToCopy = strlen(aCString);

	if (numCharsToCopy > capacity)	{
		// Cap'n, we need more capacity!
		capacity = numCharsToCopy;
		// Deallocate old array
		delete[] nstring;

		// Allocate new memory
		nstring = new char[capacity + 1];
	}

	// strcpy copy will copy the null char.
	strcpy(nstring, aCString);

	// Set the length.
	nlength = numCharsToCopy;
}

/*MyString& MyString::assign(const char *chars)
{
uint_t chars_len = strlen(chars);
uint_t last_capacity = capacity;
setNewCapacity(chars_len + 1);
if (capacity > last_capacity){
delete[] s_ptr;
s_ptr = new char[capacity];
}
memcpy(s_ptr, chars, chars_len + 1);
size = chars_len;
return *this;
}*/

MyString& MyString::assign(const char *chars, uint_t n)
{
	uint_t last_capacity = capacity;
	setNewCapacity(n + 1);
	if (capacity > last_capacity){
		delete[] nstring;
		nstring = new char[capacity];
	}
	memcpy(nstring, chars, n);
	nlength = n;
	nstring[nlength] = '\0';
	return *this;
}

MyString& MyString::assign(uint_t n, char ch)
{
	uint_t last_capacity = capacity;
	setNewCapacity(n + 1);
	if (capacity > last_capacity){
		delete[] nstring;
		nstring = new char[capacity];
	}
	memset(nstring, ch, n);
	nlength = n;
	nstring[nlength] = '\0';
	return *this;
}

char& MyString::at(size_t pos)
{
	if (pos >= nlength) throw std::out_of_range{ "invalid index passed to MyString::at" };
	return nstring[pos];
}

const char& MyString::at(size_t pos) const
{
	if (pos >= nlength) throw std::out_of_range{ "invalid index passed to MyString::at" };
	return nstring[pos];
}


void MyString::clear()
{
	nlength = 0;
	nstring[nlength] = '\0';
}

void MyString::clear(int newCapacity)
{
	if (newCapacity < 0)
		throw std::runtime_error("RAGEQUIT newCapacity given is less than 0");
	nlength = 0;
	capacity = newCapacity;
	nstring[nlength] = '\0';
}


int MyString::compare(const MyString &str)
{
	char *p = nstring;
	const char *q = str.data();
	while (*p != '\0' && *q != '\0'){
		if (*p != *q)
		{
			return *p - *q;
		}
		else {
			p++;
			q++;
		}
	}
	return *p - *q;
}

int MyString::compare(uint_t index, uint_t n, const MyString &str, uint_t index_str, uint_t n_str) const
{
	if (index >= nlength || index_str >= str.nlength){
		cout << "Index out of range." << endl;
		return 0;
	}
	else {
		char *p = nstring + index;
		const char *q = str.data() + index_str;
		int i = 0;
		int min_n = n > n_str ? n_str : n;
		while (*p != '\0' && *q != '\0' && i < min_n)
		{
			if (*p != *q){
				return *p - *q;
			}
			else {
				p++;	q++;
				i++;
			}
		}
		return *p - *q;
	}
}

int MyString::compare(uint_t index, uint_t n, const MyString &str) const
{
	if (index >= nlength)
	{
		return 0;
	}
	else {
		char *p = nstring + index;
		const char *q = str.data();
		int i = 0;
		//int min_n = n > n_str ? n_str : n;
		while (*p != '\0' && *q != '\0' && i < n)
		{
			if (*p != *q){
				return *p - *q;
			}
			else
			{
				p++;
				q++;
				i++;
			}
		}
		return *p - *q;
	}
}
/*int MyString::compare(const MyString &aMyString)
{
return strcmp(nstring, aMyString.nstring);
}*/

MyString::uint_t MyString::copy(char *s, uint_t index, uint_t n) const
{
	char *p = nstring;
	if (index + n > nlength){
		while (*p != '\0')
		{
			*s++ = *p++;
		}
		return nlength - index;
	}
	else {
		for (size_t i = 0; i < n; i++){
			s[i] = p[index + i];
		}
		return n;
	}
}

const char* MyString::c_str() const
{
	return nstring;
}


inline void MyString::setNewCapacity(uint_t n)
{
	while (n > capacity){
		capacity *= 2;
	}
}

inline const char* MyString::data() const
{
	return nstring;
}

MyString& MyString::erase(uint_t index, uint_t n)
{
	if (index >= nlength){
		return *this;
	}
	if (index == 0 && n == -1){
		clear();
	}
	else if (index + n > nlength){
		*(nstring + index) = '\0';
		nlength = index + 1;
	}
	else {
		for (uint_t i = 0; i < n; i++){
			*(nstring + index + i) = *(nstring + index + n + i);
		}
		*(nstring + index + n) = '\0';
		nlength -= n;
	}

	return *this;
}

MyString::iterator MyString::erase(const_iterator p)
{
	auto elem = std::find(begin(), end(), *p);
	if (elem == end()) return elem;

	//this loop also copies back the terminating zero
	for (auto iter = elem; iter != end(); ++iter)
	{
		*iter = *(iter + 1);
	}
	--nlength;
	return elem;
}

/*MyString::iterator MyString::erase(iterator first, iterator last)
{
auto fir = std::find(begin(), end(), *first);
auto las = std::find(begin(), end(), *last);
if (fir == end()) return fir;
if (las == end()) return las;
//if (fir > las) return;
auto iter = fir;
size_t i = 0;
for (; iter != las; ++iter)
{
--nlength;
i++;
}
*iter = *(iter + i);
--nlength;
return fir;
}*/

// Equals
// Takes a MyString argument
// Returns (true) if the argument contains
//   the same string of chars as this MyString,
//   otherwise it returns (false).
bool MyString::equals(const MyString & aMyString) const
{
	if (aMyString.nlength != nlength)
		return false;
	for (int i = 0; i < aMyString.nlength; i++) {
		if (nstring[i] != aMyString.nstring[i])
			return false;
	}
	return true;
}

// Takes a c style string argument
// Returns (true) if the argument contains
//   the same string of chars as this MyString,
//   otherwise it returns (false).
bool MyString::equals(const char *const aCString) const
{
	MyString aMyString(aCString);
	if (aMyString.nlength != nlength)
		return false;
	for (int i = 0; i < aMyString.nlength; i++) {
		if (nstring[i] != aMyString.nstring[i])
			return false;
	}
	return true;
}

// Find
// Takes a myString argument
// Returns the index (int)
//   where the argument MyString was found
//   in this MyString. If it is not found, then returns -1.

/*int MyString::find(const MyString &aMyString) const
{
int index = 0;
if (aMyString.nlength == 0 || aMyString.nlength > nlength)
return -1;
bool isFound = true;
for (int i = 0; i < nlength; i++)
{
isFound = true;
for (int j = 0; j < aMyString.nlength; j++) {
if (nstring[i + j] != aMyString.nstring[j]) {
isFound = false;
break;
}
}
if (isFound)
return i;
}
if (!isFound)
return -1;
}*/

size_t MyString::find(const MyString& str) const
{
	size_t counter = 0, ctr = 0, l = str.nlength;
	if (nlength < 1 || nlength < l || l < 1) return nlength;
	while (ctr <= (nlength - l) && l > 0) {
		if ((nstring[ctr]) == str.nstring[0]) {
			counter = 0;
			for (rsize_t count = ctr; count < (ctr + l); count++) {
				if (nstring[count] == str.nstring[counter])
					++counter;
				else { counter = 0; break; }
			}
			if (counter == l)
				return ctr;
		} ++ctr;
	}
	return nlength;
}

size_t MyString::find(const char* s) const
{
	size_t counter = 0, ctr = 0, l = strlen(s);
	if (nlength < 1 || nlength < l || l < 1) return nlength;
	while (ctr <= (nlength - l) && l > 0) {
		if ((nstring[ctr]) == s[0]) {
			counter = 0;
			for (size_t count = ctr; count < (ctr + l); count++) {
				if (nstring[count] == s[counter])
					++counter;
				else { counter = 0; break; }
			}
			if (counter == l)
				return ctr;
		} ++ctr;
	}
	return nlength;
}

size_t MyString::find(const char* s, size_t pos, size_t n) const
{
	size_t counter = 0, ctr = pos, l = strlen(s);
	if (nlength < 1 || nlength < l || l < 1) return nlength;
	while (ctr <= (nlength - l) && l > 0 && n) {
		if ((nstring[ctr]) == s[0]) {
			counter = 0;
			for (size_t n = ctr; n < (ctr + l); n++) {
				if (nstring[n] == s[n])
					++counter;
				else { counter = 0; break; }
			}
			if (counter == l)
				return ctr;
		} ++ctr, --n;
	}
	return nlength;
}

size_t MyString::find(char aMyString) const
{
	int index = 0;
	bool isFound = true;
	for (int i = 0; i < nlength; i++)
	{
		isFound = true;
		//for (int j = 0; j < aMyString.nlength; j++) {
		if (nstring[i + 1] != aMyString) {
			isFound = false;
			break;
		}

		if (isFound)
			return i;
	}
	if (!isFound)
		return -1;
}

size_t MyString::find_first_not_of(const char*s) const
{
	int a;
	for (int i = 0; i < nlength; i++)
	{
		a = 0;
		for (int j = 0; j < strlen(s); j++)
		{
			if (nstring[i] == s[j])
				a = 1;
		}
		if (a == 0)
			return i;
	}
	return MyString::npos;
}

size_t MyString::find_first_not_of(const MyString& s) const
{
	int a;
	for (int i = 0; i < nlength; i++)
	{
		a = 0;
		for (int j = 0; j < s.nlength; j++)
		{
			if (nstring[i] == s.nstring[j])
				a = 1;
		}
		if (a == 0)
			return i;
	}
	return MyString::npos;
}

size_t MyString::find_first_not_of(const char* s, size_t pos, size_t n) const
{
	int a;
	for (int i = pos; i < nlength; i++)
	{
		a = 0;
		for (int j = 0; j < n; j++)
		{
			if (nstring[i] == s[j])
				a = 1;
		}
		if (a == 0)
			return i;
	}
	return MyString::npos;
}

size_t MyString::find_first_not_of(char c, size_t pos) const
{
	int a;
	for (int i = pos; i < nlength; i++)
	{
		a = 0;
		if (nstring[i] == c)
		{
			a = 1;
		}
		if (a == 0)
			return i;
	}
	return MyString::npos;
}

size_t MyString::find_first_of(const char* s, size_t pos) const
{
	int a;
	for (int i = pos; i < nlength; i++)
	{
		a = 0;
		for (int j = 0; j < strlen(s); j++)
		{
			if (nstring[i] == s[j])
			{
				return i;
			}
		}
	}
	return std::string::npos;
}

size_t MyString::find_first_of(const MyString& s, size_t pos) const
{
	int a;
	for (int i = pos; i < nlength; i++)
	{
		a = 0;
		for (int j = 0; j < s.nlength; j++)
		{
			if (nstring[i] == s.nstring[j])
			{
				return i;
			}
		}
	}
	return std::string::npos;
}

size_t MyString::find_first_of(const char* s, size_t pos, size_t n) const
{
	for (int i = pos; i < nlength; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (nstring[i] == s[j])
				return i;
		}
	}
	return std::string::npos;
}

size_t MyString::find_first_of(char c, size_t pos) const
{
	for (int i = pos; i < nlength; i++)
	{
		if (nstring[i] == c)
			return i;
	}
	return std::string::npos;
}

size_t MyString::find_last_not_of(const char*s, size_t pos) const
{
	int i, a;
	int b = -1;
	for (int i = pos; i < nlength; i++)
	{
		a = 0;
		for (int j = 0; j < strlen(s); j++)
		{
			if (nstring[i] == s[j])
			{
				a = 1;
			}
		}
		if (a == 0)
		{
			b = i;
		}
	}
	if (b != -1)return b;
	return std::string::npos;
}

size_t MyString::find_last_not_of(const MyString& s, size_t pos) const
{
	int i, a;
	int b = -1;
	for (int i = pos; i < nlength; i++)
	{
		a = 0;
		for (int j = 0; j < s.nlength; j++)
		{
			if (nstring[i] == s.nstring[j])
			{
				a = 1;
			}
		}
		if (a == 0)
		{
			b = i;
		}
	}
	if (b != -1)return b;
	return std::string::npos;
}

size_t MyString::find_last_not_of(const char* s, size_t pos, size_t n) const
{
	int i, a = 0;
	int b = -1;
	for (int i = 0; i < pos; i++)
	{
		a = 0;
		for (int j = 0; j < n; j++)
		{
			if (nstring[i] == s[j])
			{
				a = 1;
			}
		}
		if (a == 0)
		{
			b = i;
		}
	}
	if (b != -1)return b;
	return std::string::npos;
}

size_t MyString::find_last_not_of(char c, size_t pos) const
{
	int b = -1;
	for (int i = 0; i <= pos; i++)
	{
		if (nstring[i] != c)
			b = i;
	}
	if (b != -1) return b;
	return std::string::npos;
}

size_t MyString::find_last_of(const char* s, size_t pos) const
{
	int a;
	int b = -1;
	int x;
	if (pos == 0) x = nlength - 1;
	else
	{
		x = pos;
	}
	for (int i = 0; i <= x; i++)
	{
		a = 0;
		for (int j = 0; j < strlen(s); j++)
		{
			if (nstring[i] == s[j])
			{
				a = 1;
			}
		}
		if (a == 1)b = i;
	}
	return std::string::npos;
}

size_t MyString::find_last_of(const MyString& s, size_t pos) const
{
	int a;
	int b = -1;
	int x;
	if (pos == 0) x = nlength - 1;
	else
	{
		x = pos;
	}
	for (int i = 0; i <= x; i++)
	{
		a = 0;
		for (int j = 0; j < s.nlength; j++)
		{
			if (nstring[i] == s.nstring[j])
			{
				a = 1;
			}
		}
		if (a == 1)b = i;
	}
	return std::string::npos;
}

size_t MyString::find_last_of(const char* s, size_t pos, size_t n) const
{
	int a;
	int b = -1;
	int x;
	if (pos == 0) x = nlength - 1;
	else
	{
		x = pos;
	}
	for (int i = 0; i <= x; i++)
	{
		a = 0;
		for (int j = 0; j < n; j++)
		{
			if (nstring[i] == s[j])
			{
				a = 1;
			}
		}
		if (a == 1)b = i;
	}
	if (b != -1) return b;
	return std::string::npos;
}

size_t MyString::find_last_of(char c, size_t pos) const
{
	int a;
	int b = -1;
	int x;
	if (pos == 0) x = nlength - 1;
	else
	{
		x = pos;
	}
	for (int i = 0; i <= x; i++)
	{

		if (nstring[i] == c)
		{
			b = i;
		}
	}
	if (b != -1) return b;
	return std::string::npos;
}

void MyString::insert(const MyString & aMyString, int index)
{
	{
		if (index > nlength)
		throw std::runtime_error("RAGEQUIT index is greater than Length()");
		if (index < 0)
			throw std::runtime_error("RAGEQUIT index is less than zero");

		MyString bMyString = aMyString;

		MyString returnString = MyString();
		MyString subString = MyString(substr(index, nlength - index));

		returnString.assign(substr(0, index));
		returnString.append(bMyString);
		returnString.append(subString);

		assign(returnString);

	}

}

size_t MyString::length() const
{
	return nlength;
};

void MyString::pop_back()
{
	nstring[nlength - 1] = NULL;
	nlength = nlength - 1;
}

void MyString::push_back(char c)
{
	nlength = nlength + 1;
	nstring[nlength - 1] = c;
	nstring[nlength] = NULL;
}

/*void MyString::replace(int startIndex, int numChars, const MyString & aMyString)
{
int totalLength = capacity;

// Exception handling
if (startIndex >= nlength)
throw std::runtime_error("RAGEQUIT startIndex >= Length()");
else if (startIndex + numChars > nlength)
throw std::runtime_error("RAGEQUIT startIndex + numChars > Length()");
else if (aMyString.nlength < numChars)
throw std::runtime_error("RAGEQUIT aMyString.Length() < numChars");

// check to see if _capacity is insufficent
if (aMyString.nlength > capacity) {
totalLength = aMyString.nlength + capacity;
capacity = totalLength;
MyString temp(*this);
delete[] nstring;
nstring = new char[capacity + 1];
// restore string to old value. We use the CString to preserve the new _capacity
assign(temp.nstring);
}
for (int i = 0; i < numChars; i++) // repace the chars we wanted
nstring[startIndex + i] = aMyString[i];
}*/

MyString& MyString::replace(size_t pos, size_t len, const MyString& str)
{
	MyString temp1, temp2;
	temp1.nlength = pos;
	temp2.nlength = this->nlength - pos - len;
	temp1.nstring = new char[temp1.nlength + 1];
	temp2.nstring = new char[temp2.nlength + 1];
	for (int i = 0; i < temp1.nlength; i++)
	{
		temp1.nstring[i] = this->nstring[i];
	}
	temp1.nstring[temp1.nlength] = '\0';
	for (int i = 0; i < temp2.nlength; i++)
	{
		temp2.nstring[i] = this->nstring[i + len + pos];
	}
	temp2.nstring[temp2.nlength] = '\0';
	*this = temp1 + str + temp2;
	return *this;
}
MyString& MyString::replace(size_t pos, size_t len, const MyString& str, size_t subpos, size_t sublen)
{
	MyString temp1, temp2, temp3;
	temp1.nlength = pos;
	temp2.nlength = this->nlength - pos - len;
	temp3.nlength = sublen;
	temp1.nstring = new char[temp1.nlength + 1];
	temp2.nstring = new char[temp2.nlength + 1];
	temp3.nstring = new char[temp3.nlength + 1];

	for (int i = 0; i < temp1.nlength; i++)
	{
		temp1.nstring[i] = this->nstring[i];
	}
	temp1.nstring[temp1.nlength] = '\0';
	for (int i = 0; i < temp2.nlength; i++)
	{
		temp2.nstring[i] = this->nstring[i + len + pos];
	}
	temp2.nstring[temp2.nlength] = '\0';
	for (int i = 0; i < temp3.nlength; i++)
	{
		temp3.nstring[i] = str.nstring[i + subpos];
	}
	temp3.nstring[temp3.nlength] = '\0';
	*this = temp1 + temp3 + temp2;
	return *this;
}
MyString& MyString::replace(size_t pos, size_t len, const char* s)
{
	MyString temp1, temp2, temp3;
	temp1.nlength = pos;
	temp2.nlength = this->nlength - pos - len;
	temp1.nstring = new char[temp1.nlength + 1];
	temp2.nstring = new char[temp2.nlength + 1];
	for (int i = 0; i < temp1.nlength; i++)
	{
		temp1.nstring[i] = this->nstring[i];
	}
	temp1.nstring[temp1.nlength] = '\0';
	for (int i = 0; i < temp2.nlength; i++)
	{
		temp2.nstring[i] = this->nstring[i + len + pos];
	}
	temp2.nstring[temp2.nlength] = '\0';
	temp3 = s;
	*this = temp1 + temp3 + temp2;
	return *this;
}
MyString& MyString::replace(size_t pos, size_t len, const char* s, size_t n)
{
	MyString temp1, temp2, temp3;
	temp1.nlength = pos;
	temp2.nlength = this->nlength - pos - len;
	temp3.nlength = n;
	temp1.nstring = new char[temp1.nlength + 1];
	temp2.nstring = new char[temp2.nlength + 1];
	temp3.nstring = new char[temp3.nlength + 1];

	for (int i = 0; i < temp1.nlength; i++)
	{
		temp1.nstring[i] = this->nstring[i];
	}
	temp1.nstring[temp1.nlength] = '\0';
	for (int i = 0; i < temp2.nlength; i++)
	{
		temp2.nstring[i] = this->nstring[i + len + pos];
	}
	temp2.nstring[temp2.nlength] = '\0';
	for (int i = 0; i < temp3.nlength; i++)
	{
		temp3.nstring[i] = s[i];
	}
	temp3.nstring[temp3.nlength] = '\0';
	*this = temp1 + temp3 + temp2;
	return *this;
}
MyString& MyString::replace(size_t pos, size_t len, size_t n, char c)
{
	MyString temp1, temp2, temp3;
	temp1.nlength = pos;
	temp2.nlength = this->nlength - pos - len;
	temp3.nlength = n;
	temp1.nstring = new char[temp1.nlength + 1];
	temp2.nstring = new char[temp2.nlength + 1];
	temp3.nstring = new char[temp3.nlength + 1];

	for (int i = 0; i < temp1.nlength; i++)
	{
		temp1.nstring[i] = this->nstring[i];
	}
	temp1.nstring[temp1.nlength] = '\0';
	for (int i = 0; i < temp2.nlength; i++)
	{
		temp2.nstring[i] = this->nstring[i + len + pos];
	}
	temp2.nstring[temp2.nlength] = '\0';
	for (int i = 0; i < temp3.nlength; i++)
	{
		temp3.nstring[i] = c;
	}
	temp3.nstring[temp3.nlength] = '\0';
	*this = temp1 + temp3 + temp2;
	return *this;
}

void MyString::reserve(size_t n)
{
	n = 0;
	char * new_array;

	if (n == capacity - 1)
	{
		return;
	}

	if (n < nlength + 1)
	{
		n = capacity;
	}

	new_array = new char[n];
	strcpy(new_array, nstring);
	delete[] nstring;
	nstring = new_array;
	capacity = n;
}


/*MyString& MyString::replace(size_t pos, size_t len, const MyString& str)
{
if (pos > this->nlength)
{
return *this;
}
else
{
size_t newSize = this->nlength + str.nlength - len;
char* newX = new char[newSize];
for (size_t i = 0; i < pos; i++)
{
newX[i] = nstring[i];
}
for (size_t j = 0; j < str.nlength; j++)
{
newX[pos + j] = str.nstring[j];
}
size_t h = 0;
for (size_t k = pos + len; k < this->nlength; k++)
{
newX[pos + str.nlength + h] = nstring[k];
h++;
}
delete[]nstring;
while (newSize>this->reserved_size)
this->reserved_size += _DEFAULT_STRING_SIZE;
s = new char[this->reserved_size];
this->size = newsize;
this->s = newX;
return *this;
}

}*/

/*MyString MyString::reverse() const
{
nlength = 0;
int i = nlength;
MyString result(i + 1);

for (; i >= 0; --i)
{
result += s[i];
}

return result;
}*/

void MyString::resize(size_t n)
{
	
	if ((n<nlength && n >= 0))
	{
		for (size_t i = n; i <= nlength - 1; i++)
		{
			nstring[i] = NULL;
		}
		nlength = n;
	}
	else if (n>nlength)
	{
		nlength = n;
		for (size_t i = nlength - 1; i <= n - 1; i++)
		{
			nstring[i] = NULL;
		}
	}

}
void MyString::resize(size_t n, char c)
{
	
	if ((n<nlength && n >= 0))
	{
		for (size_t i = n; i <= nlength - 1; i++)
		{
			nstring[i] = NULL;
		}
		nlength = n;
	}
	else if (n>nlength)
	{
		for (size_t i = nlength; i <= n - 1; i++)
		{
			nstring[i] = c;
		}
		nlength = n;
		nstring[n] = NULL;
	}
}

int MyString::size()
{
	int i = 0;
	while (nstring[i] != '\0')
	{
		i++;
	}
	return i;
}

MyString MyString::substr(size_t index, size_t n) const
{
	
	if (index >= nlength){
		cout << "Index out of memory." << endl;
		return *this;
	}
	if (index + n > nlength){
		return MyString(nstring + index);
	}
	else {
		return MyString(nstring + index, n);
	}

}

/*istream& getline(istream&is, MyString&s, char delim)
{
if (s.nlength == 0) {
s.nstring = new char[11];
s.nlength = 10;
}
int read{};
for (int c{}; delim != c; ++read) {
c = is.get();
if (read > s.nlength - 2) {
s.nstring[read] = '\0';
s.nlength *= 2;
char* tmp = new char[s.nlength] {};
std::strcpy(tmp, s.nstring);
delete s.nstring;
s.nstring = tmp;
}
s.nstring[read] = static_cast<char>(c);
}
s.nstring[read + 1] = '\0';
auto len = static_cast<int>(strlen(s.nstring));
if (s.nlength > len) {
char* tmp = new char[len + 1];
std::strcpy(tmp, s.nstring);
delete s.nstring;
s.nstring = tmp;
s.nlength= len;
}
return is;
}

istream& getline(istream& is, MyString& s)
{
char delim = '\n';
if (s.nlength == 0) {
s.nstring = new char[11];
s.nlength = 10;
}
int read{};
for (int c{}; delim != c; ++read) {
c = is.get();
if (read > s.nlength - 2) {
s.nstring[read] = '\0';
s.nlength *= 2;
char* tmp = new char[s.nlength] {};
std::strcpy(tmp, s.nstring);
delete s.nstring;
s.nstring = tmp;
}
s.nstring[read] = static_cast<char>(c);
}
s.nstring[read + 1] = '\0';
auto len = static_cast<int>(strlen(s.nstring));
if (s.nlength > len) {
char* tmp = new char[len + 1];
std::strcpy(tmp, s.nstring);
delete s.nstring;
s.nstring = tmp;
s.nlength = len;
}
return is;
}*/

/*bool operator == (const MyString & S1, const MyString & S2)
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

}*/

ostream& operator <<(ostream & OS, const MyString& S)
{
	OS << S.nstring;
	return OS;
}

istream& operator >>(istream & IS, MyString& S)
{
	char* input = new char[100];
	IS.getline(input, 100);

	int i = 0;
	while (input[i] != '\0')
	{
		i++;
	}
	S.nlength = i + 1;
	delete[]S.nstring;
	S.nstring = new char[(i + 1)];
	for (int j = 0; j < (i); j++)
	{
		S.nstring[j] = input[j];
	}
	S.nstring[i] = '\0';
	delete[]input;
	return IS;
}



/*MyString operator + (const MyString& S1, const MyString & S2)
{
int size = S1.nlength + S2.nlength + 1;
char * temp = new char[size];
for (int i = 0; i < (S1.nlength - 1); i++)
{
temp[i] = S1.nstring[i];
}

int j = 0;
for (short k = S1.nlength, j = 0; k < (size - 1); k++, j++)
{
temp[k] = S2.nstring[j];
}
if (temp[size - 1] != '\0'){ temp[size - 1] = '\0'; }

MyString S3;
S3.nlength = size;
delete[] S3.nstring;
S3.nstring = new char[size];
for (int z = 0; z < (size - 1); z++)
{
S3.nstring[z] = temp[z];
}
if (S3.nstring[size - 1] != '\0'){ S3.nstring = '\0'; }
return S3;
delete[] temp;
}*/

/*bool MyString::operator != (const MyString & aMyString)
{
if (nstring != aMyString.nstring){
return true;
}
else
return false;
}*/

/*MyString MyString::operator = (const MyString & aMyString)
{
assign(aMyString.nstring);
return *this;
}*/

MyString& MyString::operator= (const MyString& s)
{
	if (this == &s) return *this;

	delete nstring;
	nlength = s.length();
	nstring = new char[nlength];
	for (unsigned j = 0; j < nlength; j++)
		nstring[j] = s[j];
	return *this;
}

MyString MyString::operator = (const char *  const aCString) {
	assign(aCString);
	return *this;
}

bool MyString::empty() const{
	return nlength == 0 ? true : false;
}




MyString& MyString::operator+= (const MyString& s)
{
	unsigned len = nlength + s.length();
	char*    str = new char[len];

	for (unsigned j = 0; j < nlength; j++)
		str[j] = nstring[j];

	for (unsigned i = 0; i < s.length(); i++)
		str[nlength + i] = s[i];

	delete nstring;
	nlength = len;
	nstring = str;
	return *this;
}

MyString& MyString::operator+= (const char* s)
{
	return append(s);

}


















