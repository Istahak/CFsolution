#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        vector<long long> v(n);
        for (auto &i : v)
            cin >> i;
        sort(v.begin(), v.end());
        long long ans = 0;
        for (int i = 1; i < n; i += 2)
        {
            ans += v[i];
        }
        cout << ans << endl;
    }

    return 0;
}