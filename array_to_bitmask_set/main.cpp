#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void input_arr(char*& input, int& n);
void print_arr(char* arr, int arr_size);
void print_arr(bool* arr, int arr_size);

void to_set(char* input, int input_size,  char*& result, int& result_size);

void generate_mask(bool*& mask, int mask_size);
void input_mask(bool*& mask, int mask_size);
void disjunction_mask(bool* input_mask1, bool* input_mask2, bool*& result_mask, int result_size);

int main()
{
    char* text = nullptr;
    int text_size = 0;

    char* output_set = nullptr;
    int output_size = 0;

    input_arr(text, text_size);
    to_set(text, text_size, output_set, output_size);

    bool* mask1 = nullptr;
    generate_mask(mask1, output_size);

    bool* mask2 = nullptr;
    input_mask(mask2, output_size);

    unsigned count_mask1 = 0, count_mask2 = 0;
    for (int i = 0; i < output_size; i++)
    {
        if (mask1[i] == 1)
          count_mask1++;

        if (mask2[i] == 1)
          count_mask2++;
    }

    if (count_mask1 == count_mask2)
        cout << "MATCH" << endl;
    else
    {
        cout << "Difference: ";
        if (count_mask1 > count_mask2)
            cout << (count_mask1 - count_mask2);
        else
            cout << (count_mask2 - count_mask1);
    }

    bool* mask3 = nullptr;
    disjunction_mask(mask1, mask2, mask3, output_size);


    cout << endl << "Input text consists of  " << text_size  << " elements: " << endl;
    print_arr(text, text_size);

    cout << "\nCreated set: " << endl;
    print_arr(output_set, output_size);

    cout << "\nGenerated mask: " << mask1;
    print_arr(mask1, output_size);

    cout << "\nEntered mask: " << endl;
    print_arr(mask2, output_size);

    cout << "\nUnion mask:" << endl;
    print_arr(mask3, output_size);

    return 0;
}

void input_arr(char*& input, int& n)
{
    cout << "How many elements do you want to enter: " << endl;
    cin  >> n;

    input = new char[n];

    cout << "Enter values for " << n  << " elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    return;
}

void  print_arr(char* arr, int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return;
}

void print_arr(bool* arr, int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return;
}

void to_set(char* input, int input_size,  char*& result, int& result_size)
{
    result_size = 0;
    int j;

    for (int i = 0; i < input_size - 1; i++)
    {
        for (j = i + 1; j < input_size; j++)
        {
            if (input[i] == input[j])
            {
                break;
            }
        }
        if (j == input_size)
        {
            result_size++;
        }
    }

    // including last element
    result_size++;

    int index = 0;
    result = new char[result_size];

    for (int i = 0; i < input_size; i++)
    {
        for (j = 0; j < index; j++)
        {
            if (input[i] == result[j])
            {
                break;
            }
        }
        if (j == index)
        {
           result[index] = input[i];
           index++;
        }
    }
    return;
}

void generate_mask(bool*& mask, int mask_size)
{
    mask = new bool[mask_size];

    unsigned zeroes = 0, ones = 0;
    srand(time(0));
    for (int i = 0; i < mask_size; i++)
    {
        if ((rand() % 2)== 0)
            mask[i] = 0;
        else
            mask[i]= 1;
    }

    unsigned random_pos = 0;
    while(zeroes != ones)
    {
        unsigned random_pos = (rand() % (mask_size + 1)); // random position in [0; mask_size - 1]
        if (zeroes > ones)
        {
            if (mask[random_pos] == 0)
                mask[random_pos] == 1;
        }
        else
            mask[random_pos] == 0;

        if ((mask_size % 2 == 1) && ((zeroes = ones + 1) || (zeroes = ones - 1)))
            break;
    }
    return;
}

void input_mask(bool*& mask, int mask_size)
{
    mask = new bool[mask_size];
    cout << "Enter a mask for the set: ";
    for (int i = 0; i < mask_size; i++)
    {
        cin >> mask[i];
    }
    return;
}

void disjunction_mask(bool* input_mask1, bool* input_mask2, bool*& result_mask, int result_size)
{
    result_mask = new bool[result_size];

    for (int i = 0; i < result_size; i++)
    {
        result_mask[i] = (input_mask1[i] || input_mask2[i]);
    }
}
