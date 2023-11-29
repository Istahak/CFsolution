#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int arr[10][10];
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= 9; i++)
    {
        set<int> st;
        for (int j = 1; j <= 9; j++)
        {
            st.insert(arr[i][j]);
        }
        if (st.size() != 9)
        {
            cout << "No" << '\n';
            return;
        }
    }

    for (int i = 1; i <= 9; i++)
    {
        set<int> st;
        for (int j = 1; j <= 9; j++)
        {
            st.insert(arr[j][i]);
        }
        if (st.size() != 9)
        {
            cout << "No" << '\n';
            return;
        }
    }
    vector<pair<int, int>> v;
    v.push_back({1, 1});
    v.push_back({1, 4});
    v.push_back({1, 7});
    v.push_back({4, 1});
    v.push_back({4, 4});
    v.push_back({4, 7});
    v.push_back({7, 1});
    v.push_back({7, 4});
    v.push_back({7, 7});
    for (auto [x, y] : v)
    {
        set<int> st;

        for (int i = x, cntx = 0; cntx < 3; i++, cntx++)
        {
            for (int j = y, cnty = 0; cnty < 3; j++, cnty++)
            {
                st.insert(arr[i][j]);
            }
        }
        if (st.size() != 9)
        {
            cout << "No" << '\n';
            return;
        }
    }
    cout << "Yes"
         << "\n";
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