#include <bits/stdc++.h>
#define ll long long int
using namespace std;
bool isCriticalPoint(int prev, int pres, int next)
{
    // Critical point condition
    if ((prev < pres && pres > next) || (prev > pres && pres < next))
        return true;
    return false;
}
void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;
    ll sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        sum += abs(v[i] - v[i + 1]);
    }
    if (sum == 0)
    {
        cout << 1 << endl;
        return;
    }
    vector<int> ans;
    ans.push_back(v[0]);
    int l = 0, m = 1, r = 2;
    for (int i = 1; i < n - 1; i++)
    {
        if (v[i] == v[i + 1])
        {
            r++;
            continue;
        }
        if (isCriticalPoint(v[l], v[m], v[r]))
        {
            l = i, r = i + 2, m = i + 1;
            ans.push_back(v[i]);
        }
        else
        {
            l = i, r = i + 2, m = i + 1;
        }
    }
    ans.push_back(v[n - 1]);
    cout << ans.size() << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}