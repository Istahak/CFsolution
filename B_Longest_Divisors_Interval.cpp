#include <bits/stdc++.h>
#define lll __int128_t
using namespace std;
vector<unsigned long long int> v;
void solve()
{
    long long int n;
    cin >> n;
    int ans = 0;
    int sz = v.size();
    for (int i = 0; i < sz; i++)
    {
        if (n % v[i] == 0)
        {
            ans = i + 1;
        }
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unsigned long long int cur = 1;
    for (unsigned long long int i = 1;; i++)
    {
        cur = lcm(cur, i);
        if (cur >= 1e18)
        {
            break;
        }
        v.push_back(cur);
    }
    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}