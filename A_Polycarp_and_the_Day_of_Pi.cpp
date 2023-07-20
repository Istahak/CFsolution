
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
string x = "314159265358979323846264338327";

void solve()
{
    string s;
    cin >> s;
    int ans = 0;
    while (s[ans] == x[ans] and ans < (int)s.size())
        ans++;
    cout << ans << endl;
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