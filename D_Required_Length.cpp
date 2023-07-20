#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    ll X;
    cin >> n >> X;

    __uint128_t x = X;
    map<__uint128_t, ll> dist;
    queue<__uint128_t> q;
    q.emplace(x);
    dist[x] = 0;
    ll ans = -1;
    auto digit = [&](__uint128_t d)
    {
        set<ll> s;
        while (d)
        {
            s.insert(d % 10);
            d /= 10;
        }
        return s;
    };
    auto len = [&](__uint128_t d)
    {
        int sz = 0;
        while (d)
        {
            sz++;
            d /= 10;
        }
        return sz;
    };
    while (!q.empty())
    {
        auto v = q.front();
        q.pop();
        int vl = len(v);
        auto di = digit(v);
        if (vl == n)
        {
            ans = dist[v];
            break;
        }
        for (auto d : di)
        {
            if (d == 0)
                continue;
            __uint128_t cur = v * d;
            if (dist.find(cur) == dist.end())
            {
                dist[cur] = 1 + dist[v];
                q.emplace(cur);
            }
        }
    }
    cout << ans << endl;
    return 0;
}