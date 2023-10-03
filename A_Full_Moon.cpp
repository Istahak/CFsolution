#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    vector<vector<int>> v(4, vector<int>(4));
    v[0] = {1, 0, 0, 0};
    v[1] = {0, 1, 0, 0};
    v[2] = {0, 0, 1, 0};
    v[3] = {0, 0, 0, 1};
    do
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cout << v[i][j] << ' ';
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