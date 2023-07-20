#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
vector<int> v(103);
int n;
bool ispossible(int mid)
{
    int l = 1, r = n;
    for (int i = 1; i <= mid; i++)
    {
        while (r >= l && v[r] > mid - i + 1)
            r--;
        if (r < l)
            return false;
        l++;
        r--;
    }
    return true;
}
int bs(int l, int r)
{
    int ans = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (ispossible(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return ans;
}
void solve()
{

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    sort(v.begin() + 1, v.begin() + n + 1);
    cout << bs(0, n + 1) << endl;
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