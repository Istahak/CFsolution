#include <bits/stdc++.h>
using namespace std;

void test_case()
{
    int n;
    cin >> n;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a = __gcd(a, x);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        b = __gcd(b, x);
    }
    int ans = 0;
    if (a == b)
        ans = 0;
    else if (a > b)
    {
        ans = (a % b != 0) + 1;
    }
    else
    {
        ans = (b % a != 0) + 1;
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case " << cs << ": ";
        test_case();
    }

    return 0;
}