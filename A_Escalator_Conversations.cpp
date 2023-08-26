#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, m, k, x;
    cin >> n >> m >> k >> x;
    m--;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int temp = abs(arr[i] - x);
        if (temp == 0)
            continue;
        if (temp % k != 0)
            continue;
        if ((temp / k) <= m)
            ans++;
    }
    cout << ans << endl;
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