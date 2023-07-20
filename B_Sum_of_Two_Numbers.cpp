#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    string s;
    cin >> s;
    int sz = s.size();
    vector<int> f, ss;
    int k = 0;
    for (int i = 0; i < sz; i++)
    {
        int x = s[i] - '0';
        if (x & 1)
        {
            if (k & 1)
            {
                f.push_back(x / 2 + 1);
                ss.push_back(x / 2);
            }
            else
            {
                ss.push_back(x / 2 + 1);
                f.push_back(x / 2);
            }
            k++;
        }
        else
        {
            f.push_back(x / 2);
            ss.push_back(x / 2);
        }
    }
    ll ans = 0;
    for (auto x : f)
    {
        ans = ans * 10 + x;
    }
    cout << ans << ' ';
    ans = 0;
    for (auto x : ss)
        ans = ans * 10 + x;

    cout <<ans<< endl;
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