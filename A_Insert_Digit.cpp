#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    int c;
    cin >> n >> c;
    string s;
    cin >> s;
    int i = 0;
    for (; i < n;)
    {
        if (s[i] >= (c + '0'))
        {
            cout << s[i];
            i++;
        }
        else
            break;
    }
    cout << c;
    for (; i < n; i++)
        cout << s[i];
    cout << endl;
}
int main()
{

    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }

    return 0;
}