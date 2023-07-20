#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> h(n);
    for (auto &x : h)
        cin >> x;
    int p = max_element(h.begin(), h.end()) - h.begin();
    // cout << p << endl;
    int ans = 0;
    int cur = INT_MIN;
    for (int i = 0; i < p; i++)
    {
        cur = max(cur, h[i]);
        ans += (cur - h[i]);
    }
    cur = INT_MIN;
    for (int i = n - 1; i > p; i--)
    {
        cur = max(cur, h[i]);
        ans += (cur - h[i]);
    }
    cout << ans << endl;
}
int main()
{

    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        solve();
    }

    return 0;
}