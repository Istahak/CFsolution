#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    sort(b.begin(), b.end());
    reverse(a.begin(), a.end());
    vector<int> ans;
    while (!a.empty() and !b.empty())
    {
        if (a.back() > b.back())
        {
            ans.push_back(a.back());
            a.pop_back();
        }
        else
        {
            ans.push_back(b.back());
            b.pop_back();
        }
    }
    while (!a.empty())
    {
        ans.push_back(a.back());
        a.pop_back();
    }
    while (!b.empty())
    {
        ans.push_back(b.back());
        b.pop_back();
    }
    for (auto x : ans)
        cout << x << ' ';
    cout << '\n';
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