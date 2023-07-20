#include <bits/stdc++.h>
using namespace std;
const int N = 262144 + 5;
int n, v[N], ans;
vector<int> rec(int i, int j)
{
    if (i == j)
        return {v[i]};

    int m = (i + j) / 2;
    vector<int> a = rec(i, m);
    vector<int> b = rec(m + 1, j);

    if (a[0] > b[0])
    {
        ans++;
        swap(a, b);
    }

    for (auto x : b)
        a.push_back(x);

    return a;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    ans = 0;
    vector<int> ok = rec(1, n);
    cout << (is_sorted(ok.begin(), ok.end()) ? ans : -1) << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}