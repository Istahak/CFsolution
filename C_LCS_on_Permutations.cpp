#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int longestCommonSubsequence(const std::vector<int> &sequence1, const std::vector<int> &sequence2)
{
    std::vector<int> lis;

    for (int num : sequence1)
    {
        auto it = std::lower_bound(lis.begin(), lis.end(), num);
        if (it == lis.end())
        {
            lis.push_back(num);
        }
        else
        {
            *it = num;
        }
    }

    int commonLength = 0;

    for (int num : sequence2)
    {
        auto it = std::lower_bound(lis.begin(), lis.end(), num);
        if (it != lis.end() && *it == num)
        {
            ++commonLength;
        }
    }

    return commonLength;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    int ans = longestCommonSubsequence(a, b);
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}