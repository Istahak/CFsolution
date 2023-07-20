#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + k; j < n; j += k)
        {
            if (arr[j] > arr[i])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
    long long int ans = 0;
    for (int i = 0; i < k; ++i)
    {
        ans += arr[i];
    }

    cout << ans << endl;
}
int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}