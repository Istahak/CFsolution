#include <bits/stdc++.h>
using namespace std;

void test_case()
{
    int d, r, ans;
    cin >> d >> r >> ans;
    vector<int> v(r);
    for (auto &x : v)
        cin >> x;
    for (int i = 0; i < ans; i++)
    {
        int x;
        cin >> x;
        d += x;
    }
    for (int i = 0; i < r; i++)
    {
        if (v[i] <= d)
        {
            ans += 1;
            d -= v[i];
        }
        else
            break;
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //   cin >> t;

    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case " << cs << ": ";
        test_case();
    }

    return 0;
}