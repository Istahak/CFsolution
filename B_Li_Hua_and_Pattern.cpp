#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void rotateMatrix180(vector<vector<int>> &matrix)
{
    int numRows = matrix.size();
    int numCols = matrix[0].size();

    // Reverse each row of the matrix
    for (int i = 0; i < numRows; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }

    // Reverse the order of the rows in the matrix
    reverse(matrix.begin(), matrix.end());
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(n));
    for (auto &x : v)
    {
        for (auto &i : x)
        {
            cin >> i;
        }
    }
    auto copy = v;
    rotateMatrix180(v);
    ll cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (copy[i][j] != v[i][j])
            {
                cnt++;
            }
        }
    }
    if (cnt == 0)
    {
        cout << "YES" << endl;
        return;
    }
    cnt /= 2;
    if (cnt > m)
    {
        cout << "NO" << endl;
        return;
    }
    m -= cnt;
    cout << (((~m & 1) || (n & 1)) ? "YES" : "NO") << endl;
}
int main()
{

    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }

    return 0;
}