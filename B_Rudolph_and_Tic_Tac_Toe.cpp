#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    string s[3];
    cin >> s[0] >> s[1] >> s[2];
    for (int i = 0; i < 3; i++)
    {
        if (s[i] == "XXX")
        {
            cout << "X" << endl;
            return;
        }
        if (s[i] == "OOO")
        {
            cout << "O" << endl;
            return;
        }
        if (s[i] == "+++")
        {
            cout << "+" << endl;
            return;
        }
    }
    string x[3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            x[i].push_back(s[j][i]);
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (x[i] == "XXX")
        {
            cout << "X" << endl;
            return;
        }
        if (x[i] == "OOO")
        {
            cout << "O" << endl;
            return;
        }
        if (x[i] == "+++")
        {
            cout << "+" << endl;
            return;
        }
    }
    string f[2];
    f[0].push_back(s[0][0]);
    f[0].push_back(s[1][1]);
    f[0].push_back(s[2][2]);
    f[1].push_back(s[2][0]);
    f[1].push_back(s[1][1]);
    f[1].push_back(s[0][2]);

       for (int i = 0; i < 2; i++)
    {
        if (f[i] == "XXX")
        {
            cout << "X" << endl;
            return;
        }
        if (f[i] == "OOO")
        {
            cout << "O" << endl;
            return;
        }
        if (f[i] == "+++")
        {
            cout << "+" << endl;
            return;
        }
    }
    cout << "DRAW" << endl;
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