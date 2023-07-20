#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    int ans = 0;
    for (int i = 0; i < n;)
    {
        int cnt = 0;
        while ((v[i] & 1) && i < n)
        {
            i++;
            cnt++;
        }
        if (cnt)
            ans += (cnt - 1);
        cnt = 0;
        while (v[i] % 2 == 0 && i < n)
        {
            i++;
            cnt++;
        }
        if (cnt)
            ans += (cnt - 1);
    }
    cout << ans << endl;
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