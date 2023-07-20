#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n;
    cin >> n;
    vector<int> va;
    unordered_map<int, int> mpa;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x != 1)
            mpa[x]++;
    }
    vector<int> vb;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (mpa[x])
        {
            mpa[x]--;
        }
        else
        {
            if (x != 1)
                vb.push_back(x);
        }
    }

    for (auto i : mpa)
    {
        while (i.second)
        {
            va.push_back(i.first);
            i.second--;
        }
    }
    mpa.clear();
    int cnt = 0;
    for (int i = 0; i < va.size(); i++)
    {
        if (va[i] > 9)
        {
            va[i] = log10(va[i]) + 1;
            cnt++;
        }
        mpa[va[i]]++;
    }

    for (int i = 0; i < vb.size(); i++)
    {
        if (vb[i] > 9)
        {
            vb[i] = log10(vb[i]) + 1;
            cnt++;
        }
        if (mpa[vb[i]])
        {
            mpa[vb[i]]--;
        }
        else
        {
            cnt++;
        }
    }
    for (auto i : mpa)
    {
        cnt += i.second;
    }
    // for(auto i:va)cout<<i<<' ';cout<<endl;
    // for(auto i:vb)cout<<i<<' ';cout<<endl;
    cout << cnt << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    cin >> t;
    while (t--)
    {

        solve();
    }

    return 0;
}