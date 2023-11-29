#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int q;
    cin >> q;

    multiset<pair<int, int>> st;
    multiset<int> rir;

    while (q--)
    {
        char c;
        int l, r;
        cin >> c >> l >> r;
        if (c == '+')
        {
            st.insert({l, r});
            rir.insert(r);
        }
        else
        {
            st.erase(st.find({l, r}));
            rir.erase(rir.find(r));
        }
        if (st.empty())
        {
            cout << "NO"
                 << "\n";
            continue;
        }
        auto [x, b] = *st.rbegin();
        auto y = *rir.begin();
        cout << ((x > y) ? "YES" : "NO") << '\n';
    }
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