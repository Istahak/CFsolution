#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    if (n % 2 == 0)
    {
        int same = 0, diff = 0, ze = 0;
        for (int i = 0; i < n / 2; i++)
        {
            if (s[i] == s[n - i - 1])
                same++;
            else
                diff++;
            if (s[i] == '0')
                ze++;
        }
        if (diff)
        {
            cout << 0;
            int i = 1;
            for (; i < diff;)
            {
                cout << 0;
                i++;
            }
            int p = 1;
            for (; i <= n - diff;)
            {
                cout << p;
                p ^= 1;
                i++;
            }
            // return;
            for (; i <= n; i++)
                cout << 0;
            cout << endl;
        }
        else
        {

            cout << 1;
            for (int i = 1; i < n; i++)
            {
                if (i & 1)
                {
                    cout << 0;
                }
                else
                {
                    cout << 1;
                }
            }
            cout << 1 << endl;
        }
    }
    else
    {
        int same = 0, diff = 0, ze = 0;
        for (int i = 0; i < n / 2; i++)
        {
            if (s[i] == s[n - i - 1])
                same++;
            else
                diff++;
            if (s[i] == '0')
                ze++;
        }
    
        if (diff)
        {
            cout << 0;
            int i = 1;
            for (; i < diff; i++)
            {
                cout << 0;
            }
            int p = 1;
            for (; i <= n - diff; i++)
            {
                cout << 1;
            }
            for (; i <= n; i++)
                cout << 0;
            cout << endl;
        }
        else
        {

            for (int i = 0; i <= n; i++)
            {
                cout << 1;
            }
            cout << endl;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}