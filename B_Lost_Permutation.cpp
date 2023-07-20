#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n, k;
    cin >> n >> k;
    int sum = 0, mx = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        sum += x;
        mx = max(mx, x);
    }
    int sum2 = (mx * (mx + 1)) / 2;
    sum2 -= sum;
    bool flag = false;
    if (sum2 == k)
    {
        flag = true;
    }

    while (sum2 <= k)
    {
        if (sum2 == k)
        {
            flag = true;
            break;
        }
        mx++;
        sum2 += mx;
    }
    cout << (flag ? "YES" : "NO") << endl;
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