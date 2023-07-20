#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> v(k);
    for (auto &i : v)
        cin >> i;

    if (k == 1)
    {
        cout << "Yes" << endl;
        return;
    }

    bool flag = true;
    ll mi = INT_MAX;
    for (int i = k - 2; i >= 0; i--)
    {
        if (v[i + 1] - v[i] <= mi)
        {
            mi = v[i + 1] - v[i];
            continue;
        }

        flag = false;
    }

    ll first = n - k + 1;
    if (mi * first < v[0])
        flag = false;
    cout << (flag ? "Yes" : "No") << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    cin >> t;
    while (t--)
    {

        solve();
    }

    return 0;
}
