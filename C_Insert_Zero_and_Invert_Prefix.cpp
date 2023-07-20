#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    if (arr[n - 1] != 0)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for (int i = n - 1; i >= 0;)
    {
        int cnt = 0;
        int x = 0;
        while (arr[i] != 1 && i >= 0)
        {
            --i;
            cnt++;
        }
        while (arr[i] != 0 && i >= 0)
        {
            --i;
            cnt++;
            x++;
        }
        for (int i = 0; i < cnt - 1; ++i)
        {
            cout << 0 << ' ';
        }
        cout << x << ' ';
    }
    cout << endl;
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