#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll ask(int mid, vector<ll> v, int l)
{
    cout << "? " << mid - l + 1 << ' ';
    for (int i = l; i <= mid; i++)
    {
        cout << i << ' ';
    }
    cout << endl;
    ll sum;
    cin >> sum;
    return sum;
}
void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n + 1), va(n + 1);
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        va[i] = v[i];
    }
    for (int i = 1; i <= n; i++)
        v[i] += v[i - 1];
    int l = 1, r = n;
    while (l <= r)
    {
        int mid = (l + r) / 2;

        ll k = ask(mid, va, l);
        ll as = v[mid] - v[l - 1];
        if (k > as)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << "! " << r + 1 << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}
