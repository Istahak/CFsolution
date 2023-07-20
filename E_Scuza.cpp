#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
void solve()
{
    long long int n, q;
    cin >> n >> q;
    long long int arr[n + 1];
    long long int height[n + 1];
    arr[0] = 0;
    height[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
        height[i] = arr[i] + height[i - 1];
        arr[i] = max(arr[i], arr[i - 1]);
    }
    while (q--)
    {
        long long int x;
        cin >> x;
        long long int start = 0, end = n;
        long long int ans = -1;
        while (end >= start)
        {
            long long int mid = start + (end - start) / 2;
            if (arr[mid] <= x)
            {
                ans = mid;
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        cout << height[ans] << ' ';
    }
    cout << endl;
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
