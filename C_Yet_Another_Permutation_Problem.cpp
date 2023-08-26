#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 1; i <= n; i++)
        v[i - 1] = i;
    int mx = 0;
    do
    {
        set<int> st;
        for (int i = 0; i < n; i++)
        {
            int x;
            if (i < n - 1)
                x = __gcd(v[i], v[i + 1]);
            else
                x = __gcd(v[n - 1], v[0]);
            st.insert(x);
        }
        // cout << st.size() << endl;
        mx = max(mx, (int)st.size());
    } while (next_permutation(v.begin(), v.end()));

    do
    {
        set<int> st;
        for (int i = 0; i < n; i++)
        {
            int x;
            if (i < n - 1)
                x = __gcd(v[i], v[i + 1]);
            else
                x = __gcd(v[n - 1], v[0]);
            st.insert(x);
        }
        if (mx == st.size())
        {
            for (int i : v)
                cout << i << ' ';
            cout << endl;
        }
    } while (next_permutation(v.begin(), v.end()));
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