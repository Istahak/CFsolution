#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n), ans;
    for (auto &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    if (v.back() == 0)
    {
        cout << "No" << endl;
        return;
    }
    int i = 0, j = n - 1;
    int sum = 0;
    while (i <= j)
    {
        if (sum < 0)
        {
            ans.push_back(v[j--]);
            sum += ans.back();
        }
        else
        {
            ans.push_back(v[i++]);
            sum += ans.back();
        }
    }
    cout << "Yes" << endl;
    for (auto ans : ans)
        cout << ans << ' ';
    cout << endl;
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}
