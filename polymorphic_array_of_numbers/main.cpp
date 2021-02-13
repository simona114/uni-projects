#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;

class Number
{
public:
    Number(int number_part1, double number_part2)
    {
        this ->number_part1 = number_part1;
        this ->number_part2 = number_part2;
    }

    double get_part1()const
    {
        return number_part1;
    }

    double get_part2()const
    {
        return number_part2;
    }

    virtual double get_square() = 0;
    virtual ~Number(){}

private:
    double number_part1;
    double number_part2;
};

class Real : public Number
{
public:
    Real(int integer_part, double fraction_part) : Number(integer_part, fraction_part)
    {

    }

    double get_square() override
    {
        return (get_part1() + get_part2()) * (get_part1() + get_part2()) ;
    }

};

class Complex : public Number
{
public:
    Complex(double real_part, double imaginary_part): Number(real_part, imaginary_part){}

    double get_square() override
    {
        return (get_part1() * get_part1()) + (get_part2() * get_part2());
    }

};
int main()
{
    cout << "How many numbers do you want to enter?" << endl;
    int n;
    cin >> n;

    cout << "For real number :\npart1 - integer part \npart2 - fractional part \n\nFor complex number :\npart1 - real part \npart2 - imaginary part\n\n";
    vector<Number*> numbers;
    double part1, part2;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter number " << i + 1 << "'s part 1" << endl;
        cin >> part1;

        cout << "Enter number " << i + 1 << "'s part 2" << endl;
        cin >> part2;

        cout << "For creating a real number enter 0, For creating a complex number enter 1" << endl;
        bool type;
        cin >> type;

        if (type)
        {
            Number* number = new Complex(part1, part2);
            numbers.push_back(number);
        }
        else
        {
            Number* number = new Real(part1, part2);
            numbers.push_back(number);
        }

    }

    for (int i = 0; i < n; i++)
    {
        cout << "Square of number " << i + 1 << " of type " << typeid(*numbers[i]).name() << " is ";
        cout << numbers[i] -> get_square() << endl;
    }

    return 0;
}
