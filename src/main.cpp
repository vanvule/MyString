#include"Header.h"

void menu()
{
	system("cls");
	cout << "0. Thoat." << endl;
	cout << "1.operator=." << endl;
	cout << "\nIterators:." << endl;
	cout << "2.begin." << endl;
	cout << "3.end." << endl;
	cout << "4.rbegin." << endl;
	cout << "5.rend." << endl;
	cout << "6.cbegin." << endl;
	cout << "7.cend." << endl;
	cout << "8.crbegin." << endl;
	cout << "9.crend." << endl;

	cout << "\nCapacity:." << endl;
	cout << "10.size." << endl;
	cout << "11.length." << endl;
	cout << "12.max_size." << endl;
	cout << "13.resize." << endl;
	cout << "14.capacity." << endl;
	cout << "15.reserve." << endl;
	cout << "16.clear." << endl;
	cout << "17.empty." << endl;
	cout << "18.shrink_to_fit." << endl;

	cout << "\nElement access :." << endl;
	cout << "19.operator[]." << endl;
	cout << "20.at." << endl;
	cout << "21.back." << endl;
	cout << "22.front." << endl;

	cout << "\nModifiers:." << endl;
	cout << "23.operator+=." << endl;
	cout << "24.append." << endl;
	cout << "25.push_back." << endl;
	cout << "26.assign." << endl;
	cout << "27.insert." << endl;
	cout << "28.erase." << endl;
	cout << "29.replace." << endl;
	cout << "30.swap." << endl;
	cout << "31.pop_back." << endl;

	cout << "\nString operations :." << endl;
	cout << "32.c_str." << endl;
	cout << "33.data." << endl;
	cout << "34.get_allocator." << endl;
	cout << "35.copy." << endl;
	cout << "36.find." << endl;
	cout << "37.rfind." << endl;
	cout << "38.find_first_of." << endl;
	cout << "39.find_last_of." << endl;
	cout << "40.find_first_not_of." << endl;
	cout << "41.find_last_not_of." << endl;
	cout << "42.substr." << endl;
	cout << "43.compare." << endl;

	cout << "\nNon - member function overloads." << endl;
	cout << "44.operator+." << endl;
	cout << "45.relational operators." << endl;
	cout << "46.swap." << endl;
	cout << "47.operator>>." << endl;
	cout << "48.operator<<." << endl;
	cout << "49.getline." << endl;
}

int chon()
{
	int chon;
	cout << "\n\t\t\tMoi ban chon: ";
	cin >> chon;
	return chon;
}


void run(int lenh)
{
	if (lenh == 0)
	{
		cout << "Nhan ENTER de thoat" << endl;
		exit(0);
	}
	if (lenh == 1)
	{
		MyString str1;
		cout << "str1 = Test string :" << endl;
		cout << "==> In ra str1: ";
		str1 = "Test string: ";
		std::cout << str1 << '\n';
		system("pause");
	}
	else if (lenh == 2)
	{
		MyString str("Test string");
		cout << "str: Test string" << endl;
		cout << "==> In ra str tu dau den cuoi chuoi:";
		for (MyString::iterator it = str.begin(); it != str.end(); ++it)
			std::cout << *it;
		std::cout << '\n';
		system("pause");
	}
	else if (lenh == 3)
	{
		MyString str("Test string");
		cout << "str: Test string" << endl;
		cout << "==> In ra str tu dau den cuoi chuoi:";
		for (MyString::iterator it = str.begin(); it != str.end(); ++it)
			std::cout << *it;
		std::cout << '\n';
		system("pause");
	}
	else if (lenh == 4)
	{
		cout << "Xin loi. Thao tac khong duoc thuc hien -_-" << endl;
		system("pause");
	}
	else if (lenh == 5)
	{
		cout << "Xin loi. Thao tac khong duoc thuc hien -_-" << endl;
		system("pause");
	}
	else if (lenh == 6)
	{
		MyString str("Test string");
		cout << "str: Test string (khong duoc thay doi chuoi trong qt in ra)" << endl;
		cout << "==> In ra str tu dau den cuoi chuoi:";
		for (MyString::const_iterator it = str.cbegin(); it != str.cend(); ++it)
			std::cout << *it;
		std::cout << '\n';
		system("pause");
	}
	else if (lenh == 7)
	{
		MyString str("Test string");
		cout << "str: Test string (khong duoc thay doi chuoi trong qt in ra)" << endl;
		cout << "==> In ra str tu dau den cuoi chuoi:";
		for (MyString::const_iterator it = str.cbegin(); it != str.cend(); ++it)
			std::cout << *it;
		std::cout << '\n';
		system("pause");
	}
	else if (lenh == 8)
	{
		cout << "Xin loi. Thao tac khong duoc thuc hien -_-" << endl;
		system("pause");
	}
	else if (lenh == 9)
	{
		cout << "Xin loi. Thao tac khong duoc thuc hien -_-" << endl;
		system("pause");
	}
	else if (lenh == 10)
	{
		MyString str("Test string");
		cout << "str:Test string " << endl;
		std::cout << "==>The size of str is " << str.size() << " bytes.\n";

		system("pause");
	}

	else if (lenh == 10)
	{
		MyString str("Test string");
		cout << "str:Test string " << endl;
		std::cout << "==>The size of str is " << str.size() << " bytes.\n";

		system("pause");
	}
	else if (lenh == 11)
	{
		MyString str("Test string");
		cout << "str:Test string " << endl;
		std::cout << "==>The size of str is " << str.length() << " bytes.\n";

		system("pause");
	}
	else if (lenh == 12)
	{
		cout << "Xin loi. Thao tac khong duoc thuc hien -_-" << endl;
		system("pause");
	}
	else if (lenh == 13)
	{
		MyString str("I like to code in C");

		std::cout << "str:" << str << '\n';

		unsigned sz = str.size();
		cout << "==>> Them 2 dau + vao cuoi chuoi str, tang size len 2: ";
		str.resize(sz + 2, '+');
		std::cout << str << '\n';

		cout << "==>> Bo 2 Ki tu cuoi chuoi str, giam size len 2: ";
		str.resize(14);
		std::cout << str << '\n';
		system("pause");
	}
	else if (lenh == 14)
	{
		cout << "Xin loi. Thao tac khong duoc thuc hien -_-" << endl;
		system("pause");
	}
	else if (lenh == 15)
	{
		system("cls");
		cout << "Xin loi. Chuc nang nay chua kip cai dat trong ham main()." << endl;
		system("pause");
	}
	else if (lenh == 16)
	{
		MyString str("I dislike to code in C");

		std::cout << "str:" << str << '\n';

		str.clear();
		cout << "==>> Lam sach toan bo str: size = 0" << endl;
		std::cout << str << '\n';
		system("pause");
	}
	else if (lenh == 17)
	{
		MyString str("I dislike to code in C");

		std::cout << "str:" << str << '\n';
		if (str.empty())cout << "==> str rong." << endl;
		else cout << "==> str khong rong." << endl;
		system("pause");
	}
	else if (lenh == 18)
	{
		cout << "Xin loi. Thao tac khong duoc thuc hien -_-" << endl;
		system("pause");
	}
	else if (lenh == 19)
	{
		MyString str("Test string");
		cout << "str: Test string " << endl;
		for (int i = 0; i<str.length(); ++i)
		{
			std::cout << str[i];
		}
		cout << endl;
		system("pause");
	}
	else if (lenh == 20)
	{
		MyString str("Test string");
		cout << "str: Test string " << endl;
		std::cout << "Tra ve VT thu 2 trong chuoi: " << str.at(1) << endl;
		system("pause");
	}
	else if (lenh == 21)
	{
		system("cls");
		MyString str("hello world.");
		cout << "str: hello world." << endl;
		cout << "str.back()='!': ";
		str.back() = '!';
		std::cout << str << '\n';
		system("pause");
	}
	else if (lenh == 22)
	{
		system("cls");
		MyString str("hello world.");
		cout << "str: hello world." << endl;
		cout << "==> str.front()='H': ";
		str.front() = 'H';
		std::cout << str << '\n';
		system("pause");
	}
	else if (lenh == 23)
	{
		system("cls");
		MyString name("John");
		cout << "name: John, " << "family: Smith" << endl;
		MyString family("Smith");
		name += " K. ";         // c-string
		name += family;         // string          
		std::cout << name;

		system("pause");
	}
	else if (lenh == 24)
	{
		system("cls");
		MyString str;
		MyString str2 = "Writing ";
		MyString str3 = "print 10 and then 5 more";
		cout << "str1: Writing " << endl;
		cout << "str2: print 10 and then 5 more" << endl;
		cout << "str sau khi thuc hien cac thao tac: str.append(str2)-> str.append(str3, 6, 3)->str.append('dots are cool', 5)->str.append('here: '): " << endl;
		str.append(str2);                       // "Writing "
		str.append(str3, 6, 3);                   // "10 "
		str.append("dots are cool", 5);          // "dots "
		str.append("here: ");
		cout << str << endl;

		system("pause");
	}
	else if (lenh == 25)
	{
		system("cls");
		MyString str("Van V");

		cout << "str: Van V" << endl;
		cout << "==> str.push_back('u'): ";
		str.push_back('u');
		cout << str << endl;

		system("pause");
	}
	else if (lenh == 26)
	{
		system("cls");
		MyString str;
		MyString base = "The quick brown fox jumps over a lazy dog.";
		cout << "base: The quick brown fox jumps over a lazy dog." << endl;

		cout << "==>str.assign(base): ";
		str.assign(base);
		std::cout << str << '\n';

		cout << "==>str.assign(base, 10, 9): ";
		str.assign(base, 10, 9);
		std::cout << str << '\n';         // "brown fox"

		cout << "==>str.assign('pangrams are cool', 7): ";
		str.assign("pangrams are cool", 7);
		std::cout << str << '\n';         // "pangram"

		cout << "==>str.assign('c - string.): ";
		str.assign("c-string");
		std::cout << str << '\n';         // "c-string"

		system("pause");
	}

	else if (lenh == 28)
	{
		system("cls");
		MyString str("This is an example sentence.");
		std::cout << str << '\n';

		cout << "==> Sau khi thu hien 1 so thao tac erase: " << endl;
		str.erase(10, 8);                        //            ^^^^^^^^
		std::cout << str << '\n';
		// "This is an sentence."
		str.erase(str.begin() + 9);               //           ^
		std::cout << str << '\n';
		system("pause");
	}
	else if (lenh == 29)
	{
		system("cls");
		cout << "Xin loi. Chuc nang nay chua kip cai dat trong ham main()." << endl;
		system("pause");
	}
	else if (lenh == 30)
	{
		system("cls");
		MyString buyer("money");
		cout << "buyer: money" << endl;
		MyString seller("goods");
		cout << "sleler: goods" << endl;

		std::cout << "==>Before the swap, buyer has " << buyer;
		std::cout << " and seller has " << seller << '\n';

		seller.swap(buyer);

		std::cout << " ==>After the swap, buyer has " << buyer;
		std::cout << " and seller has " << seller << '\n';
		system("pause");
	}
	else if (lenh == 31)
	{
		system("cls");
		cout << "Xin loi. Chuc nang nay chua kip cai dat trong ham main()." << endl;
		system("pause");
	}
	else if (lenh == 32)
	{
		system("cls");
		cout << "Xin loi. Chuc nang nay chua kip cai dat trong ham main()." << endl;
		system("pause");
	}
	else if (lenh == 33)
	{
		system("cls");
		cout << "Xin loi. Chuc nang nay chua kip cai dat trong ham main()." << endl;
		system("pause");
	}
	else if (lenh == 34)
	{
		system("cls");
		cout << "Xin loi. Chuc nang nay chua kip cai dat trong ham main()." << endl;
		system("pause");
	}
	else if (lenh == 35)
	{
		system("cls");
		cout << "Xin loi. Chuc nang nay chua kip cai dat trong ham main()." << endl;
		system("pause");
	}
	else if (lenh == 36)
	{
		system("cls");
		cout << "Xin loi. Chuc nang nay chua kip cai dat trong ham main()." << endl;
		system("pause");
	}
	else if (lenh == 37)
	{
		system("cls");
		cout << "Xin loi. Chuc nang nay chua kip cai dat trong ham main()." << endl;
		system("pause");
	}
	else if (lenh == 38)
	{
		system("cls");
		cout << "Xin loi. Chuc nang nay chua kip cai dat trong ham main()." << endl;
		system("pause");
	}

	else if (lenh == 39)
	{
		system("cls");
		cout << "Xin loi. Chuc nang nay chua kip cai dat trong ham main()." << endl;
		system("pause");
	}
	else if (lenh == 40)
	{
		system("cls");
		cout << "Xin loi. Chuc nang nay chua kip cai dat trong ham main()." << endl;
		system("pause");
	}
	else if (lenh == 41)
	{
		system("cls");
		cout << "Xin loi. Chuc nang nay chua kip cai dat trong ham main()." << endl;
		system("pause");
	}
	else if (lenh == 42)
	{
		system("cls");
		cout << "Xin loi. Chuc nang nay chua kip cai dat trong ham main()." << endl;
		system("pause");
	}
	else if (lenh == 45)
	{
		system("cls");
		cout << "foo: alpha" << endl;
		MyString foo = "alpha";
		cout << "bar: beta" << endl;
		MyString bar = "beta";

		if (foo == bar) std::cout << "==>foo and bar are equal\n";
		if (foo != bar) std::cout << "==>foo and bar are not equal\n";
		if (foo< bar) std::cout << "==>foo is less than bar\n";
		if (foo> bar) std::cout << "==>foo is greater than bar\n";
		if (foo <= bar) std::cout << "==>foo is less than or equal to bar\n";
		if (foo >= bar) std::cout << "==>foo is greater than or equal to bar\n";

		system("pause");
	}
}

int main()
{
	int x;
	do
	{
		menu();
		x = chon();
		run(x);
	} while (x != 0);

	system("pause");
	return 0;
}