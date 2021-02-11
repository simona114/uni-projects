#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include "Student.h"
using namespace std;

//fills in student information
//@param vector<Student>& - students
void fill_vector(vector<Student>&);


//prints the names of all students born in the current month
//@param const vector<Student>& - students
void print_vector_born_curr_mo(vector<Student>&, const int&);

int main()
{
    vector<Student> friends;

    fill_vector(friends);

    enum Months
    {
        January = 1, February, March, April, May, June, July, August, September, October, November, December
    };

    int current_month;
    do
    {
        cout << "Enter the number of the current month (number between 1 and 12)" << endl;
        cin.clear();
        cin.ignore();
        cin >> current_month;
    }
    while (current_month < January || current_month > December || isnanf(current_month));

    switch (current_month){
    case January:
    {
        cout << "Friends' birthdays in January: "  << endl;
        break;
    }
    case February:
    {
        cout << "Friends' birthdays in February: "  << endl;
        break;
    }
    case March:
    {
        cout << "Friends' birthdays in March: "  << endl;
        break;
    }
    case April:
    {
        cout << "Friends' birthdays in April: "  << endl;
        break;
    }
    case May:
    {
        cout << "Friends' birthdays in May: "  << endl;
        break;
    }
    case June:
    {
        cout << "Friends' birthdays in June: "  << endl;
        break;
    }
    case July:
    {
        cout << "Friends' birthdays in July: "  << endl;
        break;
    }
    case August:
    {
        cout << "Friends' birthdays in August: "  << endl;
        break;
    }
    case September:
    {
        cout << "Friends' birthdays in September: "  << endl;
        break;
    }
    case October:
    {
        cout << "Friends' birthdays in October: "  << endl;
        break;
    }
    case November:
    {
        cout << "Friends' birthdays in November: "  << endl;
        break;
    }
    case December:
    {
        cout << "Friends' birthdays in December: "  << endl;
        break;
    }
    default:
        cout << "No such month" << endl;
    }

    print_vector_born_curr_mo(friends, current_month);

    return 0;
}



void fill_vector(vector<Student>& my_friends){
    int friends_number;
    do
    {

        cout << "How many friends do you have? (it must be a positive number)" << endl;
        cin.clear();
        cin.ignore();
        cin >> friends_number;
    }
    while (friends_number < 1 || isnanf(friends_number));

    string name, birthday;
    for (int i = 1; i <= friends_number; i++)
    {
        cout << "Enter name of friend " << i << endl;
        cin >> name;

        cout << "Enter birthday of friend " << i <<" in DD/MM/YYYY format " << endl;
        cin >> birthday;

        Student newStudent(name, birthday);
        my_friends.push_back(newStudent);

    }
}

void print_vector_born_curr_mo(vector<Student>& my_friends, const int& current_month)
{
    unsigned int friends_number = my_friends.size();

    for (unsigned int i = 0; i < friends_number; i++)
        if (my_friends[i].bday_in_curr_month(current_month))
        cout << my_friends[i].get_name();
}

