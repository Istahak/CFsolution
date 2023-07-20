#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n;
    cin >> n;
    vector<string> s1(n), s2(n), s3(n);
    map<string, int> mp;
    for (auto &i : s1)
    {
        cin >> i;
        mp[i]++;
    }
    for (auto &i : s2)
    {
        cin >> i;
        mp[i]++;
    }
    for (auto &i : s3)
    {
        cin >> i;
        mp[i]++;
    }
    int cnt = 0;
    for (auto i : s1)
    {
        if (mp[i] == 3)
            continue;
        if (mp[i] == 2)
            cnt += 1;
        if (mp[i] == 1)
            cnt += 3;
    }
    cout << cnt << ' ';

    cnt = 0;
    for (auto i : s2)
    {
        if (mp[i] == 3)
            continue;
        if (mp[i] == 2)
            cnt += 1;
        if (mp[i] == 1)
            cnt += 3;
    }
    cout << cnt << ' ';

    cnt = 0;
    for (auto i : s3)
    {
        if (mp[i] == 3)
            continue;
        if (mp[i] == 2)
            cnt += 1;
        if (mp[i] == 1)
            cnt += 3;
    }
    cout << cnt << endl;
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