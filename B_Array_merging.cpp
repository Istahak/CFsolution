#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    map<int, int> ma, mb;
    int c = 1;
    for (int j = 0; j < n;)
    {
        c = 1;
        while (j < n - 1 and a[j] == a[j + 1])
        {
            j++;
            c++;
        }
        ma[a[j]] = max(c, ma[a[j]]);
        j++;
    }
    c = 1;
    for (int j = 0; j < n;)
    {
        c = 1;
        while (j < n - 1 and b[j] == b[j + 1])
        {
            j++;
            c++;
        }
        mb[b[j]] = max(c, mb[b[j]]);

        j++;
    }

    int ans = INT_MIN;
    for (int i = 0; i <= 2 * n; i++)
    {
        ans = max(ans, ma[i] + mb[i]);
        // cout << ma[i] << ' ' << mb[i] << endl;
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