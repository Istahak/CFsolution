#include <bits/stdc++.h>
#define ll long long int
using namespace std;
vector<int> primes;
void sive()
{
    int n = sqrt(1e7 + 2);
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i * 1ll <= n; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    primes.push_back(2);
    for (int i = 3; i <= n; i += 2)
    {
        if (is_prime[i])
            primes.push_back(i);
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
        for (auto p : primes)
        {
            while (x % p == 0)
            {
                mp[p]++;
                x /= p;
            }
        }
        if (x > 1)
            mp[x]++;
    }
    int ans = 0, odd = 0;

    for (auto [x, y] : mp)
    {
        ans += y / 2;
        odd += y % 2;
    }
    ans += odd / 3;
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sive();
    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }

    return 0;
}