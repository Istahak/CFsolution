#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n != 5)
    {
        cout << "NO\n";
        return;
    }
    map<char, int> mp;
    for (int i = 0; i < 5; i++)
    {
        mp[s[i]]++;
    }
    if (mp['T'] && mp['i'] && mp['m'] && mp['u'] && mp['r'])
        cout << "YES\n";
    else
        cout << "NO\n";
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