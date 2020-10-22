#include <iostream>

using namespace std;
//nizhodqsht red
int main()
{
    int a, b, c;
    cout << "Enter a number " << endl;
    cin >> a;
    cout << "Enter another number" << endl;
    cin >> b;
    cout << "Enter another number" << endl;
    cin >> c;
    /* if(a >= b)
       {
           if ((b >= c))
            cout << a<< " " << b<<" " << c ;
           else
            cout << a << " " << c<< " " << b;
       }
    if(a >= c)
       {
           if ((c >= b))
            cout << a<< " " << c<<" " << b ;
           else
            cout << a << " " << b<< " " << c;
       }
    if (b >= c)
       {
           if (c >= a)
            cout << b<< " " << c<<" " << a ;
           else
            cout << b<< " " << a<< " " << c;
       }
    */

    if ((a<=b)&& (a<=c))
    {
        if ( b <=c) cout << a <<b<<c;
        else cout << a<<c<<b;
    }
    else if ((b<=a)&& (b<=c))
    {
        if ( a <=c) cout << b <<a<<c;
        else cout << b<<c<<a;
    }

    else ((c<=a)&& (c<=b));
    {
        if ( b <=a) cout << c <<b<<a;
        else cout << c<<a<<b;
    }
    return 0;
}
