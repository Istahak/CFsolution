#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    set<int> a, b;
    for (int i = 1; i <= n; i++)
    {
        a.insert(i);
        b.insert(i);
    }
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x)
        {
            v[i] = x;
            a.erase(i);
            b.erase(x);
        }
    }
    set<pair<int, int>> st;
    for (int i = 1; i <= n; i++)
    {
        if (a.count(i))
        {
            if (a.count(i) == b.count(i))
                st.insert({0, i});
            else
                st.insert({1, i});
        }
    }
    while (!st.empty())
    {
        auto [x, id] = *st.begin();
        st.erase(*st.begin());
        auto val = *b.begin();
        if (id == val)
        {
            val = *b.rbegin();
            v[id] = val;
        }
        else
        {
            v[id] = val;
        }
        b.erase(val);
    }

    for (int i = 1; i <= n; i++)
        cout << v[i] << ' ';
    cout << endl;
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