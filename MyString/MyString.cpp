// Copyright 2024 <DaniilParfenov>

#include "MyString.h"


MyString::MyString(const char* arr) {
    if (arr == nullptr) {
        this->str = nullptr;
        this->size = 0;
    } else {
        while (arr[size] != '\0') {
            size++;
        }

        this->str = new char[++size];
        for (int i = 0; i < size; i++) {
            this->str[i] = arr[i];
        }
        this->str[size - 1] = '\0';
    }
}

MyString::MyString(const std::string& str) {
    size = str.size() + 1;
    this->str = new char[size];
    for (int i = 0; i < size; i++) {
        this->str[i] = str[i];
    }
    this->str[size - 1] = '\0';
}

MyString::MyString(const std::vector<char>& str) {
    size = str.size() + 1;
    this->str = new char[size];
    for (int i = 0; i < size - 1; i++) {
        this->str[i] = str[i];
    }
    this->str[size - 1] = '\0';
}

MyString::MyString(const MyString& ref) : size(ref.size) {
    str = new char[size];
    for (int i = 0; i < size; i++) {
        str[i] = ref.str[i];
    }
}

MyString::MyString(MyString&& ref) : size(ref.size), str(std::move(ref.str)) {
    ref.str = nullptr;
    ref.size = 0;
}

MyString::~MyString() {
    delete[] str;
}

int MyString::length() const {
    return size - 1;
}

char* MyString::get() const {
    return str;
}

MyString MyString::operator+(const MyString& right) const {
    int newStrSize = right.size + this->size - 1;
    char* newStr = new char[newStrSize];

    for (int i = 0; i < this->size && this->str[i] != '\0'; i++) {
        newStr[i] = this->str[i];
    }
    for (int i = 0; i < right.size; i++) {
        newStr[size + i - 1] = right.str[i];
    }

    MyString result(newStr);
    delete[] newStr;

    return result;
}

MyString MyString::operator-(const MyString& right) const {
    char* newStr = new char[this->size];
    int curIndex = 0;
    bool haveSameLetter = false;
    for (int i = 0; i < this->size; i++) {
        haveSameLetter = false;
        for (int j = 0; j < right.size; j++) {
            if (this->str[i] == right.str[j]) {
                haveSameLetter = true;
                break;
            }
        }

        if (!haveSameLetter) {
            newStr[curIndex++] = this->str[i];
        }
    }
    newStr[curIndex] = '\0';
    MyString result(newStr);
    delete[] newStr;
    return result;
}

MyString MyString::operator*(const int number) const {
    int resSize = (size - 1) * number + 1;
    char* newStr = new char[resSize];

    for (int i = 0; i < resSize; i++) {
        newStr[i] = str[i % (size - 1)];
    }

    newStr[resSize - 1] = '\0';
    MyString result(newStr);
    delete[] newStr;
    return result;
}

bool MyString::operator==(const MyString& right) const {
    if (this->size != right.size) {
        return false;
    }
    for (int i = 0; i < this->size; i++) {
        if (this->str[i] != right.str[i]) {
            return false;
        }
    }
    return true;
}

bool MyString::operator!=(const MyString& right) const {
    return !(right == *this);
}

bool MyString::operator>(const MyString& right) const {
    int minSize = std::min(right.size, this->size);

    for (int i = 0; i < minSize; i++) {
        if (this->str[i] < right.str[i]) {
            return false;
        }
        if (this->str[i] > right.str[i]) {
            return true;
        }
    }

    if (right.size == this->size) {
        return false;
    }
    return true;
}

bool MyString::operator<(const MyString& right) const {
    return (right > *this);
}

bool MyString::operator<=(const MyString& right) const {
    return (*this < right) || (*this == right);
}

bool MyString::operator>=(const MyString& right) const {
    return (*this > right) || (*this == right);
}

MyString MyString::operator!() const {
    char* newStr = new char[size];

    for (int i = 0; i < size - 1; i++) {
        if ('a' <= str[i] && str[i] <= 'z') {
            newStr[i] = toupper(str[i]);
        } else if ('A' <= str[i] && str[i] <= 'Z') {
            newStr[i] = tolower(str[i]);
        } else {
            newStr[i] = str[i];
        }
    }
    newStr[size - 1] = '\0';
    MyString result(newStr);
    delete[] newStr;
    return result;
}

char& MyString::operator[](const int index) const {
    if (index >= 0 && index < size) {
        return str[index];
    }
}

int MyString::operator()(const char* soughtString) const {
    int res = -1;
    int indexOfSoughtStr = 0;
    for (int i = 0; i < size; i++) {
        if (str[i] == soughtString[indexOfSoughtStr]) {
            if (res == -1) {
                res = i;
            }
            indexOfSoughtStr++;
            if (soughtString[indexOfSoughtStr] == '\0') {
                break;
            }
        } else {
            indexOfSoughtStr = 0;
            res = -1;
        }
    }
    return res;
}

int MyString::operator()(const MyString& soughtString) const {
    int res = -1;
    int indexOfSoughtStr = 0;
    for (int i = 0; i < size; i++) {
        if (str[i] == soughtString[indexOfSoughtStr]) {
            if (res == -1) {
                res = i;
            }
            indexOfSoughtStr++;
            if (soughtString[indexOfSoughtStr] == '\0') {
                break;
            }
        } else {
            indexOfSoughtStr = 0;
            res = -1;
        }
    }
    return res;
}


MyString& MyString::operator=(const MyString& right) {
    if (this != &right) {
        delete[] this->str;
        this->str = new char[right.size];
        this->size = right.size;
        for (int i = 0; i < size; i++) {
            this->str[i] = right.str[i];
        }
    }
    return *this;
}

MyString& MyString::operator=(MyString&& right) {
    if (this != &right) {
        delete[] this->str;
        this->str = std::move(right.str);
        this->size = right.size;
        right.str = nullptr;
        right.size = 0;
    }
    return *this;
}

std::istream& operator>>(std::istream& input, MyString& ref) {
    std::vector<char> in;
    char c = '0';
    while (true) {
        c = input.get();
        if (c == '\n') {
            break;
        }
        in.push_back(c);
    }
    MyString res(in);
    ref = res;
    return input;
}

std::ostream& operator<<(std::ostream& output, const MyString& ref) {
    if (ref.get() == nullptr) {
        output << '\0';
    } else {
        output << ref.get();
    }
    return output;
}
