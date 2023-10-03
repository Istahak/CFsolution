#include <bits/stdc++.h>
using namespace std;

void test_case()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x, x--;
    if (k == 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (v[i] != i)
            {
                cout << "NO" << endl;
                return;
            }
        }
        cout << "YES" << endl;
        return;
    }

    vector<int> vis(n, false);
    int cyclesz = -1, Time = 0;
    vector<int> distime(n, 0);
    bool ok = true;
    function<void(int)> dfs = [&](int cur)
    {
        if (vis[cur] == 2)
            return;
        distime[cur] = Time++;
        vis[cur] = 1;
        if (vis[v[cur]] == 0)
            dfs(v[cur]);
        else if (vis[v[cur]] == 1)
        {
            cyclesz = distime[cur] - distime[v[cur]] + 1;
            if (cyclesz != k)
                ok = false;
        }
        vis[cur] = 2;
        return;
    };
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            cyclesz = -1;
            dfs(i);
            if (cyclesz == -1)
                continue;
            if (cyclesz != k)
            {
                ok = false;
            }
        }
    }
    cout << (ok ? "YES" : "NO") << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case " << cs << ": ";
        test_case();
    }

    return 0;
}