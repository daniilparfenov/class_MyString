// Copyright 2024 <DaniilParfenov>

#ifndef MYSTRING_H
#define MYSTRING_H
#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

class MyString {
 public:
    MyString(const char* str = nullptr);
    explicit MyString(const std::vector<char>& str);
    explicit MyString(const std::string& str);
    MyString(const MyString& ref);
    MyString(MyString&& ref);
    ~MyString();
    int length() const;
    char* get() const;
    void print() const;

    MyString operator+(const MyString& right) const;
    MyString operator-(const MyString& right) const;
    MyString operator*(const int number) const;

    bool operator==(const MyString& right) const;
    bool operator!=(const MyString& right) const;
    bool operator>(const MyString& right) const;
    bool operator<(const MyString& right) const;
    bool operator<=(const MyString& right) const;
    bool operator>=(const MyString& right) const;

    MyString operator!() const;
    char& operator[](const int index) const;
    int operator()(const char* soughtString) const;
    int operator()(const MyString& soughtString) const;

    MyString& operator=(const MyString& right);
    MyString& operator=(MyString&& right);

 private:
    char* str;
    int size = 0;
};

std::ostream& operator<<(std::ostream& output, const MyString& ref);
std::istream& operator>>(std::istream& input, MyString& ref);
#endif
