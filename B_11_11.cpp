#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int d;
        cin >> d;
        set<int> sst;
        int q = i;
        while (q)
        {
            sst.insert(q % 10);
            q /= 10;
        }
        if (sst.size() == 1)
        {
            for (int k = 1; k <= d; k++)
            {
                set<int> st;
                int p = k;
                while (p)
                {
                    st.insert(p % 10);
                    p /= 10;
                }
                if (st.size() == 1)
                {
                    if (*st.begin() == *sst.begin())
                        ans++;
                }
            }
        }
    }
    cout << ans << '\n';
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