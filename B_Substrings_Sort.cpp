#include <bits/stdc++.h>
#define ll long long int
using namespace std;
bool f(string &a, string &b)
{
    return a.size() < b.size();
}
void solve()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for (auto &c : v)
        cin >> c;
    sort(v.begin(), v.end(), f);

    bool ok = true;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[i].find(v[j]) == string::npos)
            {
                ok = false;
            }
        }
    }
    if (ok)
    {
        cout << "YES" << endl;
        for (auto x : v)
            cout << x << endl;
    }
    else
        cout << "NO" << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}