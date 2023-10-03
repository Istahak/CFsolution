#include <bits/stdc++.h>
using namespace std;

void test_case()
{

    int m;
    cin >> m;
    string a, b, c;
    cin >> a >> b >> c;

    int ans = INT_MAX;
    for (int i = 0; i < 3 * m; i++)
    {
        for (int j = 0; j < 3 * m; j++)
        {
            for (int k = 0; k < 3 * m; k++)
            {
                if (i == j or j == k or k == i)
                    continue;
                if (a[i % m] == b[j % m] and b[j % m] == c[k % m])
                {

                    ans = min(ans, max({i, j, k}));
                }
            }
        }
    }
    if (ans == INT_MAX)
        ans = -1;

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