#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
struct chash
{
    const int RANDOM = (long long)(make_unique<char>().get()) ^ chrono::high_resolution_clock::now()
                                                                    .time_since_epoch()
                                                                    .count();
    static unsigned long long hash_f(unsigned long long x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    static unsigned hash_combine(unsigned a, unsigned b)
    {
        return a * 31 + b;
    }
    int operator()(int x) const { return hash_f(x) ^ RANDOM; }
    int operator()(pair<int, int> x) const
    {
        return hash_combine(x.first, x.second) ^ RANDOM;
    }
};
gp_hash_table<ll, ll, chash> mp, ans;
void solve()
{
    int q;
    cin >> q;
    while (q--)
    {
        char c;
        ll x;
        cin >> c >> x;
        if (c == '+')
            mp[x] = 1;
        else
        {
            ll cur = max(ans[x], x);
            while (mp.find(cur) != mp.end())
                cur += x;
            ans[x] = cur;
            cout << ans[x] << "\n";
        }
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