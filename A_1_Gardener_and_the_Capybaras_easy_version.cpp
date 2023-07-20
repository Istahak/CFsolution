#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    if (s[0] != s[n - 1])
    {
        for (int i = 1; i < n - 1; i++)
        {
            if (s[i] == 'a')
            {
                cout << s.substr(0, i) << ' ' << s.substr(i, 0) << ' ' << s.substr(i + 1, n - i - 1) << endl;
                return;
            }
            else if (s[i] == 'b')
            {
                cout << s[0] << ' ';
                for (int j = 1; j < n - 1; j++)
                    cout << s[j];
                cout << ' ' << s[n - 1] << endl;
                return;
            }
        }
    }
    else
    {
        cout << s[0] << ' ';
        for (int i = 1; i < n - 1; i++)
            cout << s[i];
        cout << ' ' << s[n - 1] << endl;
        return;
    }
    cout << ":(" << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}