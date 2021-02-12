#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <stdexcept>

using namespace std;

//removes element at certain position from vector
void erase_element(vector<int>& vec, int position);

int main()
{


    vector<int> products;
    vector<int> pieces;
    string input = "" ;

    while(getline(cin, input))
    {
        string delimeter = " ";
        const string command = input.substr(0, input.find(delimeter));
        const char* command_c[] = { command.c_str() };

        string product_id = input.substr(input.find(delimeter),input.length());

        int prod_id;
        try
        {
            prod_id = stoi(product_id);
        }
        catch (invalid_argument& e)
        {
            cerr << product_id << " is not a number" << endl;
        }

        enum Command { add , show, get };

        Command comm;

        string c = "add";
        const char* temp_add[] = { c.c_str() };

        if (strcmp(*temp_add, *command_c) == 0)
        {
            comm = (Command)0;
        }

        c = "show";
        const char* temp_show[] = {c.c_str()};
        if (strcmp(*temp_show, *command_c) == 0)
        {
            comm = (Command)1;
        }

        c = "get";
        const char* temp_get[] = {c.c_str()};
        if (strcmp(*temp_get, *command_c) == 0)
        {
            comm = (Command)2;
        }

        if(comm == add)
        {
            if ((int)products.size() == 0)
            {
                products.push_back(prod_id);
                pieces.push_back(1);
            }
            else
            {
                for(int i = 0; i < (int)products.size() ; i++)
                {
                    if (products[i] == prod_id) // if some of the available products ids matches the wanted id
                    {
                        pieces[i]++;
                        break;
                    }

                    else
                    {
                        if((i + 1) == (int)products.size())
                        {
                            products.push_back(prod_id);
                            pieces.push_back(1);
                            break;
                        }

                    }
                }

            }
        }

        else if (comm == show)
        {

            if ((int)products.size() == 0)
            cout << "0" << endl;

            for (int k = 0; k < (int)products.size(); k++)
            {
                if (products[k] == prod_id)
                {
                    cout << pieces[k] << endl;
                    break;
                }
                else if (k == (int)products.size())
                {
                    cout << "NOT FOUND" << endl;
                }
            }
        }

        else if (comm == get)
        {
            if ((int)products.size() == 0)
                cout << "NOT FOUND" << endl;

            for (int k = 0; k < (int)products.size(); k++)
            {
                if (products[k] == prod_id)
                {
                    if (pieces[k] > 0)
                        pieces[k]--;
                }

                else
                {
                    erase_element(products, k);
                    erase_element(pieces, k);
                }
            }
        }
        else
            cout << "Invalid command" << endl << endl;

    }
    return 0;
}

void erase_element(vector<int>& vec, int position)
{
    for (int i = position; i < (int)vec.size() - 1; i++)
        vec[i] = vec[i + 1];
    vec.pop_back();
}
