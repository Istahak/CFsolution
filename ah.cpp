#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);
    int mx = 0;
    do
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += (v[i] ^ (i + 1));
        }
        mx = max(mx, sum);

    } while (next_permutation(v.begin(), v.end()));

    do
    {
        int sum = 0;
        vector<int> Xor(n);
        for (int i = 0; i < n; i++)
        {
            sum += (v[i] ^ (i + 1));
            Xor[i] = (v[i] ^ (i + 1));
        }
        if (mx == sum)
        {
            for (auto x : v)
            {
                cout << x << ' ';
            }
            cout << endl;

            for (auto x : Xor)
            {
                cout << x << ' ';
            }
            cout << endl;
        }

    } while (next_permutation(v.begin(), v.end()));
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