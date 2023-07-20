#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    int cnt = 1;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == cnt)
            cnt++;
    }
    cnt--;
    int ans = n - cnt;
    cout << (ans % k == 0 ? ans / k : (ans / k) + 1) << endl;
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