#include <bits/stdc++.h>
using namespace std;

void test_case()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        int cnt = 0;
        int j = 0;
        while (j < n)
        {
            if (s[j] == 'N')
            {
                cnt++, j++;
            }
            else
            {
                ans += cnt / 2;
                cnt = 0, j++;
            }
        }
        ans += cnt / 2;
    }
    cout << ans << '\n';
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