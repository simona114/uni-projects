#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
class Student
{
    public:
        Student(const string&, const string&);

        //returns the name of the student
        string get_name();

        //extracting student's birthday month from the entered birthday string and converting it to int using sstream
        int get_bday_month();

        //checks if student's birthday falls in the current month
        bool bday_in_curr_month (const int&);

    private:
        string name;
        string birthday; // in DD/MM/YYYY format
};

#endif // STUDENT_H
