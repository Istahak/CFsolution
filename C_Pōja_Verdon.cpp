#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    cin >> t;
    ll sum = 0;
    while (t--)
    {
        int x;
        cin >> x;
        sum += x;
    }
    cout << sum << endl;

    return 0;
}
/*Write a program in C to read –
(The course title of this course is Computer and Programming Language
Sessional) and remove the spaces between two words of its content.*/

/*Write a C code to replace each uppercase letter with the same lowercase
letter of the given string “Computer”. Return the new string.*/