#include <iostream>
#include <vector>

using namespace std;

bool is_prime (unsigned number);

int main()
{
    unsigned *numbers = nullptr;
    unsigned n = 0;

    cout << "How many numbers do you want to enter?" << endl;
    cin >> n;

    numbers = new unsigned [n];

    cout << "Enter values for " << n  << " numbers. " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    vector <unsigned> curr_seq {}; // current sequence of composites
    vector <unsigned> longest_seq {}; // longest sequence of composites


   for (int j = 0; j < n; j++)
   {
        for (int i = 0; i < n; i++)
       {
            if (!is_prime(numbers[i]))
            {
                curr_seq.push_back(numbers[i]);

                if(curr_seq.size() >= longest_seq.size())
                {
                    longest_seq.clear();
                    longest_seq.insert(longest_seq.begin(), curr_seq.begin(), curr_seq.end());
                }
            }
            else
                curr_seq.clear();
       }
       curr_seq.clear();
  }

    cout << "Longest subsequence of composite numbers. printed in reverse: ";
    for (int i = longest_seq.size() - 1; i >= 0; i--)
    {
        cout << longest_seq[i] << " ";
    }

    delete[] numbers;
    numbers = nullptr;

    return 0;
}

bool is_prime (unsigned number)
{
    if (number <= 1) return false;
    if (number == 2) return true;

    for (int i = 2; i < number; i++)
    {
        if (number % i == 0) return false;
    }
    return true;
}

