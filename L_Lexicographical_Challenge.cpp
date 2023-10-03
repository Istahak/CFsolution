#include <bits/stdc++.h>
using namespace std;

void test_case()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    vector<char> v[k];
    int sz = s.size();
    for (int i = 0; i < sz; i++)
    {
        v[i % k].push_back(s[i]);
    }
    for (int i = 0; i < k; i++)
    {
        sort(v[i].rbegin(), v[i].rend());
    }
    for (int i = 0; i < sz; i++)
    {
        cout << v[i % k].back();
        v[i % k].pop_back();
    }
    cout << endl;
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