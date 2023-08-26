#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e6;
vector<int> di[N];
void init()
{
    for (int i = 1; i < N; i++)
    {
        for (int j = i; j < N; j += i)
        {
            di[j].push_back(i);
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    int ans = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        auto v = di[i];
        int cur = 0;
        for (auto x : v)
        {
            if (mp.count(x))
            {
                cur += mp[x];
            }
        }
        ans = max(ans, cur);
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}