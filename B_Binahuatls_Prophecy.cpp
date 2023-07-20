#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
const int N = 1e5 + 10;
vector<ll> ans;
int bs[32];
void dfs(int l, int r, int ln)
{
    if (l > r)
    {
        int cur = 0;
        for (int i = 0; i < ln; i++)
        {
            cur = cur * 2 + bs[i];
        }
        ans.push_back(cur);
        return;
    }
    if (l == 0)
    {
        bs[l] = bs[r] = 1;
        dfs(l + 1, r - 1, ln);
    }
    else
    {
        bs[l] = bs[r] = 1;
        dfs(l + 1, r - 1, ln);
        bs[l] = bs[r] = 0;
        dfs(l + 1, r - 1, ln);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i <= 31; i++)
    {
        dfs(0, i, i + 1);
    }
    sort(ans.begin(), ans.end());
    int q;
    cin >> q;

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int lll = lower_bound(ans.begin(), ans.end(), l) - ans.begin();
        int rr = upper_bound(ans.begin(), ans.end(), r) - ans.begin();
        cout << rr - lll << endl;
    }
    return 0;
}
