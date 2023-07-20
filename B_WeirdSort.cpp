#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), p(m);
    for (auto &i : a)
    {
        cin >> i;
    }

    for (auto &i : p)
    {
        cin >> i;
    }
    sort(p.begin(), p.end());

    for (int i = 0; i < n; i++)
    {
        for (int i = 0; i < m; i++)
        {
            if (a[p[i] - 1] > a[p[i]])
                swap(a[p[i] - 1], a[p[i]]);
        }
    }

    cout << (is_sorted(a.begin(), a.end()) ? "YES" : "NO") << endl;
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
