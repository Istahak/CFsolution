#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 110;
vector<int> primes;
void sive()
{
    int n = N;
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
    vector<ll> v(n);
    map<ll, int> mp;
    for (auto &i : v)
        cin >> i, mp[i]++;

    if (mp.size() != n)
    {
        cout << "NO" << endl;
        return;
    }

    int ok = true;
    for (auto prime : primes)
        cout<<prime<<endl;
    for (auto prime : primes)
    {
        vector<int> cnt(prime, 0);
        for (auto value : v)
            cnt[value % prime]++;

        int mi = *min_element(cnt.begin(), cnt.end());
        if (mi >= 2)
        {
            ok = false;
            break;
        }
    }

    cout << (ok ? "YES" : "NO") << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    sive();
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}