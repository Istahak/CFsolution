#include <bits/stdc++.h>
#define ll long long int
using namespace std;
vector<int> ans;
int n, m;
void rec(int cur)
{
    if (ans.size() >= n)
    {
        for (auto x : ans)
            cout << x << ' ';
        cout << '\n';
        return;
    }
   
    for (int i = 1; i <= m; i++)
    {
        ans.push_back(i);
        rec(i + 1);
        ans.pop_back();
    }
}
void solve()
{

    cin >> n >> m;
    rec(1);
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