#include <bits/stdc++.h>
using namespace std;

void test_case()
{
    int N, H, X;
    cin >> N >> H >> X;
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        if (H + x >= X and !ans)
            ans = i + 1;
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