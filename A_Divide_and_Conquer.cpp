#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n), odd, even;
    ll sum = 0;
    for (auto &i : v)
    {
        cin >> i;
        sum += i;
        if (i & 1)
            odd.push_back(i);
        else
            even.push_back(i);
    }
    if (sum % 2 == 0)
    {
        cout << 0 << endl;
        return;
    }
    int ans = INT_MAX;
    for (auto x : odd)
    {
        int cnt = 0;
        while (x & 1)
        {
            x /= 2;
            cnt++;
        }
        ans = min(ans, cnt);
    }
    for (auto x : even)
    {
        int cnt = 0;
        while (x % 2 == 0)
        {
            x /= 2;
            cnt++;
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
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