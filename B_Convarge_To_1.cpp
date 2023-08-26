#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 2e6 + 9;
vector<int> largest_factor(N);
vector<int> smallest_factor;
vector<bool> prime;
vector<int> primes;
void sieve(ll maximum)
{
    maximum = max(maximum, 1ll);
    smallest_factor.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    primes = {};
    for (int p = 2; p <= maximum; p++)
    {
        if (prime[p])
        {
            smallest_factor[p] = p;
            primes.push_back(p);
            for (int64_t i = (int64_t)(p)*p; i <= maximum; i += p)
            {
                if (prime[i])
                {
                    prime[i] = false;
                    smallest_factor[i] = p;
                }
            }
        }
    }
}
const int LOGN = 22;

int st[N][LOGN];
int get(int L, int R)
{
    int d = 31 - __builtin_clz(R - L);

    return max(st[L][d], st[R - (1 << d)][d]);
}
void build(vector<int> &v)
{
    int n = v.size();

    // v index 0 base
    for (int i = 0; i < n; i++)
        st[i][0] = v[i];

    for (int j = 1; j < LOGN; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            st[i][j] = max(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
}

int n, m;
void solve()
{
    cin >> n >> m;
    priority_queue<pair<int, int>> pq;
    vector<int> rang(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            rang[i] = 0;
            continue;
        }

        pq.emplace(x, -i);
    }

    int ti = 0;
    while (!pq.empty())
    {
        auto [val, index] = pq.top();
        pq.pop();
        if (prime[val])
        {
            ti++;
            rang[(-index)] = ti;
        }
        else
        {

            ti++;
            val /= largest_factor[val];
            pq.emplace(val, index);
        }
    }
    build(rang);
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        cout << get(l - 1, r) << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    sieve(N);
    for (auto p : primes)
    {
        for (int i = p; i < N; i += p)
        {
            largest_factor[i] = p;
        }
    }

    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}