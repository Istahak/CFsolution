#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int f = 0, cnt = 0;
    for (int i = 0; i < n - 2; i++)
    {
        if (s[i] == s[i + 2])
            cnt++;
    }
    cout << n - 1 - cnt << endl;
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