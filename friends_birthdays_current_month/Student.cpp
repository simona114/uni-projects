#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include "Student.h"
class Student{
    public:
        Student(const std::string&, const std::string&) ;

        //returns the name of the student
        std::string get_name();

        //extracting student's birthday month from the entered birthday string and converting it to int using sstream
        int get_bday_month();

        //checks if student's birthday falls in the current month
        bool bday_in_curr_month (const int&);

    private:
        std::string s_name;
        std::string birthday; // in DD/MM/YYYY format
};

Student::Student(const std::string& s_name, const std::string& birthday)
{
    this -> s_name = s_name;
    this -> birthday = birthday;
}

std::string Student::get_name()
{
    return s_name;
}

int Student::get_bday_month()
{
    int bday_m;
    std::string month_str = birthday.substr(3, 2);
    std::stringstream m (month_str);
    m >> bday_m;

    return bday_m;
}

bool Student::bday_in_curr_month (const int& current_month)
{
    int bday_month = get_bday_month();
    if (bday_month == current_month)
        return true;

    return false;
}

#endif // STUDENT_H
