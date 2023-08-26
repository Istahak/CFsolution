#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    int cnt = 0;
    int idx = 0;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] == arr[0])
        {
            cnt++;
            idx = i;
        }
        if (cnt == k)
            break;
    }
    if (cnt < k)
    {
        cout << "NO" << endl;
        return;
    }
    if (arr[0] == arr[n - 1])
    {
        cout << "YES" << endl;
        return;
    }
    cnt = 0;
    for (int i = idx + 1; i < n; ++i)
    {
        if (arr[i] == arr[n - 1])
            cnt++;
    }
    if (cnt >= k)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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