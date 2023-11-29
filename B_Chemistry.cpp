#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> cnt(26, 0);
    string s;
    cin >> s;
    for (auto c : s)
    {
        cnt[c - 'a']++;
    }
    int cc = 0;
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] % 2 == 1)
        {
            cc++;
        }
    }
    // if (cc == 0 or cc == 1)
    // {

    //     cout << "YES" << '\n';
    //     return;
    // }
    if (k < (cc - 1))
    {
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
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