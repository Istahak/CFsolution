#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    vector<int> v(26, 0);
    vector<string> s(3);
    for (auto &i : s)
        cin >> i;

    for (auto s : s)
    {
        for (auto s : s)
        {
            if (s != '*')
                v[s - 'A'] = 1;
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        string s;
        cin >> s;
        vector<int> vi(26, 1);
        for (auto s : s)
            vi[s - 'A'] = 0;

        cout << (v == vi ? "POSSIBLE" : "IMPOSSIBLE") << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    // cin >> tt;
    while (tt--)
        solve();

    return 0;
}