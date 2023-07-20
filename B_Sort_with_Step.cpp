#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        x--;
        if (x % k != i % k)
            cnt++;
    }
    cout << (cnt == 0 ? cnt : (cnt == 2 ? 1 : -1)) << endl;
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