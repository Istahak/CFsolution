#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    vector<int> v[26];
    for (int i = 0; i < n; i++)
    {
        v[s[i] - 'a'].push_back(i);
    }
    bool ok = true;
    for (auto v : v)
    {
        set<int> st;
        for (auto x : v)
            st.insert(x % 2);
        if (st.size() == 2)
            ok = false;
    }
    cout << (ok ? "YES" : "NO") << endl;
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
