// Programming Technique II

//? EXERCISE 3: STRING MANIPULATIONS
//? file: custom_string.cpp

//!----------------------------------------------------------------------------------------
//! This is the only file that you will need to modify in this exercise.
//! Also, you will submit only this file.
//! This file is the implementation for the class CustomString.
//!----------------------------------------------------------------------------------------


// Member 1's Name: DAYANG FARAH FARZANA BINTI ABANG IDHAM
// Member 2's Name: FARRA NURZAHIN BT ZAHARIL ANUAR

// Link video : https://drive.google.com/file/d/1FBMhDWgQgqpsNJxqGBed61IXxdd_x9_B/view?usp=drivesdk

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#include "custom_string.hpp"

//?----------------------------------------------------------------------------------------
//? The following methods are fully given: a constructor, getData() and setData()
//?----------------------------------------------------------------------------------------

CustomString::CustomString(const string &_data) : data(_data) {}
string CustomString::getData() const { return data; }
void CustomString::setData(const string &_data) { data = _data; }

//! Task 1: Complete the implementation of the following mutator methods:
//!        (a) pushFront()
//!        (b) pushBack()
//!        (c) pop()
//!        (d) popFront()
//!        (e) popBack()

void CustomString::pushFront(const string &s)
{
    data.insert(0,s);
}

void CustomString::pushBack(const string &s)
{
    data.insert(data.length(), s);
}

string CustomString::pop(int index, int count)
{
    string extracted = data.substr(index, count);
    data.erase(index,count);
    return extracted;
}

string CustomString::popFront(int count)
{
    string extracted = data.substr(0, count);
    data.erase(0, count);
    return extracted;
}

string CustomString::popBack(int count)
{
    string extracted = data.substr(data.length() - count);
    data.erase(data.length()-count,count);
    return extracted;
}

//! Task 2: Complete the implementation of the following overloaded operators:
//!        (a) operator !
//!        (b) operator *

CustomString CustomString::operator!() const
{
    string reversedData = data;
    reverse (reversedData.begin(), reversedData.end());
    return CustomString(reversedData);
}

CustomString CustomString::operator*(int count) const
{
    string repeatedData;
    for(int i=0; i<count; ++i)
    {
        repeatedData += data;
    }
    return CustomString(repeatedData);
}

//! Task 3: Complete the implementation of the following conversion methods:
//!        (a) toDouble()
//!        (b) toUpper()

double CustomString::toDouble() const
{
    return stod(data);
}

CustomString CustomString::toUpper() const
{
    string upperData = data;
    for(int i=0; i<upperData.length();++i)
    {
        if(isalpha(upperData[i]))
        {
            upperData[i] = toupper(upperData[i]);
        }
    }
    return CustomString(upperData);
}