#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    const int n = 7;
    int a[n] = {3, 7, -2, 4, 12, -23, 9};

    int max_global = a[0], max_current = a[0];


    for(int i = 1 ; i < n; i++)
    {
        max_current = max(a[i], a[i] + max_current);
        max_global = max(max_current, max_global);
    }

    for(int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << endl << "max subarray sum is : " << max_global;
    return 0;
}
