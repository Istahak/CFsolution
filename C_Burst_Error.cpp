#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
            v.push_back(i);
    }
    if (v.empty() or v.size() <= k)
    {
        cout << 0 << endl;
        return;
    }

    n = v.size();
    k = n - k;
    int result = INT_MAX;
    for (int i = 0; i <= n - k ; i++)
        result = min(result, v[i + k - 1] - v[i] + 1);
    cout << result << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}