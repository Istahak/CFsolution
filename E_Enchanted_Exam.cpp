#include <bits/stdc++.h>
#define ll long long int
using namespace std;
string ask(int x)
{
    cout << x << endl;
    string s;
    cin >> s;
    return s;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 2; i <= 100; i++)
    {
        string s = ask(i);
        if (s == "factor")
        {
            for (int j = i * 2; j <= 100; j += i)
            {
                string ss = ask(j);
                if (ss == "equal")
                {
                    cout << j << endl;
                    return 0;
                }
            }
        }
        else if (s == "multiple")
        {
            for (int j = 1; j * j <= i; j++)
            {
                if (i % j == 0)
                {
                    string ss = ask(j);
                    if (ss == "equal")
                    {
                        cout << j << endl;
                        return 0;
                    }

                    int k = i / j;
                    if (k == i)
                        continue;

                    ss = ask(k);
                    if (ss == "equal")
                    {
                        cout << k << endl;
                        return 0;
                    }
                }
            }
        }
        else if (s == "equal")
        {
            cout << i << endl;
            return 0;
        }
        else
        {
            for (int j = 3; j <= 99; j += 2)
            {

                string ss = ask(j);
                if (ss == "equal")
                {
                    cout << j << endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}