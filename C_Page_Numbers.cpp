#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    vector<int> v;
    set<int> st;
    int a;
    char c;
    scanf("%d", &a);
    st.insert(a);
    while (scanf("%c%d", &c, &a) != EOF)
    {
        st.insert(a);
    }
    for (auto x : st)
        v.push_back(x);
    vector<vector<int>> ans(1000 + 1);
    int k = 0;
    int i = 0;
    int sz = v.size();
    bool ok = false;
    while (i < sz)
    {
        ans[k].push_back(v[i]);
        while (v[i] + 1 == v[i + 1])
        {
            ok = true;
            i++;
        }
        if (ok)
        {
            ans[k].push_back(v[i]);
            ok = false;
        }
        i++, k++;
    }
    for (int j = 0; j < k; j++)
    {
        auto v = ans[j];
        if (v.size() == 1 && j == k - 1)
        {
            cout << v[0] << endl;
        }
        else if (v.size() > 1 && j == k - 1)
        {
            cout << v[0] << '-' << v.back() << endl;
        }
        else if (v.size() == 1)
        {
            cout << v[0] << ',';
        }
        else
        {
            cout << v[0] << '-' << v.back() << ',';
        }
    }
    return 0;
}
