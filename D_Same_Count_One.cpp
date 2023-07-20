#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n, m;
    cin >> n >> m;
    int arr[n + 1][m + 1];
    vector<int> cnt(n + 1, 0);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
            sum += arr[i][j], cnt[i] += arr[i][j];
        }
    }
    if (sum % n)
    {
        cout << -1 << endl;
        return;
    }
    sum /= n;
    vector<tuple<int, int, int>> ans;

    for (int j = 1; j <= m; j++)
    {
        vector<int> needs, gives;
        for (int i = 1; i <= n; i++)
        {
            if (arr[i][j] == 1 && cnt[i] > sum)
                gives.push_back(i);
            if (arr[i][j] == 0 && cnt[i] < sum)
                needs.push_back(i);
        }
        for (int i = 0; i < min(gives.size(), needs.size()); i++)
        {
            ans.emplace_back(gives[i], needs[i], j);
            cnt[gives[i]]--, cnt[needs[i]]++;
        }
    }
    cout << ans.size() << endl;
    for (auto [x, y, z] : ans)
        cout << x << ' ' << y << ' ' << z << endl;
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