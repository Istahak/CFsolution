#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < n; i++)
    {
        if ((s1[i] == 'R' && s2[i] == 'G'))
        {
            cout << "NO\n";
            return;
        }
        if ((s1[i] == 'G' && s2[i] == 'R'))
        {
            cout << "NO\n";
            return;
        }
        if ((s1[i] == 'B' && s2[i] == 'R'))
        {
            cout << "NO\n";
            return;
        }
        if ((s1[i] == 'R' && s2[i] == 'B'))
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    cin >> t;
    while (t--)
    {

        solve();
    }

    return 0;
}