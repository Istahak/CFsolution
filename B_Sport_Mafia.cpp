#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
long long int n, k;
ll ispossible(ll mid)
{
    ll add = n - mid;
    ll x = (add * (add + 1)) / 2 - mid;
    return x;
}
ll Binaryserach(ll l, ll r)
{
    ll ans = 0;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        ll x = ispossible(mid);
        if (x == k)
        {
            ans = mid;
            return ans;
        }
        else if (x > k)
            l = mid;
        else
            r = mid;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    cout << Binaryserach(0, n + 1) << endl;

    return 0;
}