// Copyright 2024 <DaniilParfenov>

#include "MyString.h"

int main() {
    // Using of constructor MyString(const char* = nullptr)
    // with default value = nullptr
    MyString str0;
    std::cout << "str0: " << str0 << "\n\n";

    // Using of constructor MyString(const char* = nullptr)
    // with some value
    MyString str1("str1");
    std::cout << "str1: " << str1 << "\n\n";

    // Using of constructor MyString(const std::string& str).
    // I added "const" and access by reference so that the
    // original string cannot be changed and a copy of the string is not created
    std::string notMyStr = "str";
    MyString strFromNotMyStr(notMyStr);
    std::cout << "not my string: " << notMyStr << "\n";
    std::cout << "My string from not my str: " << strFromNotMyStr << "\n\n";

    // Using the copy constructor
    MyString copiedStr(str1);
    std::cout << "str1: " << str1 << "\n";
    std::cout << "copied str: " << copiedStr << "\n\n";

    // Using the moving constructor
    MyString newStr(std::move(str1));
    std::cout << "new string from moved str1: " << newStr << "\n";
    std::cout << "moved string: " <<  str1 << "\n\n";

    // Using of length() and get()
    std::cout << "lenght of new str: " <<  newStr.length() << "\n";
    std::cout << "pointer of new str: " << newStr.get() << "\n";
    std::cout << "first character of new str received by pointer: "
              << newStr.get()[0] << "\n\n";

    // Concatenation and copy assignment
    MyString a = "Hello, ";
    MyString b = "world :)";
    MyString sum = a + b;
    std::cout << "First Str: " << a << "\n";
    std::cout << "Second Str: " << b << "\n";
    std::cout << "Sum: " << sum << "\n\n";

    // Move assignment
    MyString x = "hiiii";
    std::cout << "moving string: " << x << "\n";
    MyString x1 = std::move(x);
    std::cout << "new string: " << x1 << "\n";
    std::cout << "moved string: " << x << "\n\n";


    // comparisons
    MyString s1 = "aaa";
    MyString s1_1 = "aaa";
    MyString s2 = "ab";

    std::cout << "s1 (\"aaa\") == s1_1 (\"aaa\") " << (s1 == s1_1) << "\n";
    std::cout << "s1 (\"aaa\") != s2 (\"ab\") " << (s1 != s2) << "\n";
    std::cout << "s1 (\"aaa\") > s2 (\"ab\") " << (s1 > s2) << "\n";
    std::cout << "s1 (\"aaa\") < s2 (\"ab\") " << (s1 < s2) << "\n";
    std::cout << "s1 (\"aaa\") >= s2 (\"ab\") " << (s1 >= s2) << "\n";
    std::cout << "s1 (\"aaa\") <= s1 (\"aaa\") " << (s1 <= s1) << "\n\n";

    // operator !
    MyString string = "aBCd01";
    std::cout << "string:  " << string << "\n";
    std::cout << "!string:  " << !string << "\n";
    std::cout << "string: " << string << "\n\n";

    // Accessing a symbol by index
    std::cout << "string: " << string << "\n";
    for (int i = 0; i < string.length(); i++) {
        std::cout << "string[" << i << "]='" << string[i] << "' ";
    }
    std::cout << "\n\n";

    // Search for a substring
    MyString subString = "d0";
    std::cout << "string: " << string << "\n";
    std::cout << "subString: " << subString << "\n";
    std::cout << "answer(SubString of My Class): " << string(subString) << "\n";
    std::cout << "answer(SubString is char array): " << string("d0") << "\n\n";

    // Reading from and writing to a stream
    MyString input;
    std::cout << "Enter your string: ";
    std::cin >> input;
    std::cout << "Your input: " << input << "\n";

    MyString da;

    return 0;
}
