#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    int ans = -1;
    int cur = -1;
    for (int i = 0; i < n; i++)
    {
        // if (x < a[i])
        //     break;
        if (x >= a[i])
        {
            if (b[i] > cur)
            {
                cur = b[i];
                ans = i + 1;
            }
        }
         x--;
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