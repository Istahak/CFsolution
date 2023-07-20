#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> divisor[N];
void pre()
{
    for (int i = 1; i < N; i++)
    {
        for (int j = i; j < N; j += i)
        {
            divisor[j].push_back(i);
        }
    }
}
void solve()
{
    int n, q;
    cin >> n >> q;
    set<int> st;
    for (int i = 0, x; i < n; i++)
    {
        cin >> x;
        st.insert(x);
    }
    while (q--)
    {
        int m;
        cin >> m;
        int ans = 0;
        for (auto x : divisor[m])
        {
            if (st.count(x) == 0)
                ans++;
        }
        cout << ans << endl;
    }
}
int main()
{
    pre();

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solve();
    }

    return 0;
}