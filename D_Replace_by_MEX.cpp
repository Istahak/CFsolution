#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
vector<int> v(100000);
int findmexx(int n)
{

    vector<bool> vis(n + 1, false);
    for (int i = 0; i < n; i++)
        vis[v[i]] = true;
    int ans = -1;
    for (int i = 0; i <= n; i++)
        if (!vis[i])
        {
            ans = i;
            break;
        }

    return ans;
}
void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> ans;
    while (!is_sorted(v.begin(), v.end() + n))
    {
        int mexx = findmexx(n);
        if (mexx == n)
        {
            int ok = -1;
            for (int i = 0; i < n; i++)
            {
                if (v[i] != i)
                {
                    ok = i;
                    break;
                }
            }
            for (int i = 0; i < n; i++)
            {
                if (v[i] == ok)
                {
                    ans.push_back(i + 1);
                    v[i] = mexx;
                    break;
                }
            }
        }
        else
        {
            v[mexx] = mexx;
            ans.push_back(mexx + 1);
        }
    }
    // for(int i=0;i<n;i++)cout<<v[i]<<' ';cout<<endl;
    cout << ans.size() << endl;
    for (auto ans : ans)
        cout << ans << ' ';
    cout << endl;
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
        v.clear();
        solve();
    }

    return 0;
}