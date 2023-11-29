#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif
class Mex
{
private:
    map<int, int> frequency;
    set<int> missing_numbers;
    vector<int> A;

public:
    Mex(vector<int> const &A) : A(A)
    {
        for (int i = 0; i <= A.size(); i++)
            missing_numbers.insert(i);

        for (int x : A)
        {
            ++frequency[x];
            missing_numbers.erase(x);
        }
    }

    int mex()
    {
        return *missing_numbers.begin();
    }

    void update(int idx, int new_value)
    {
        if (--frequency[A[idx]] == 0)
            missing_numbers.insert(A[idx]);
        A[idx] = new_value;
        ++frequency[new_value];
        missing_numbers.erase(new_value);
    }
};
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;
    Mex st(v);
    while (q--)
    {
        int i, val;
        cin >> i >> val;
        st.update(i - 1, val);
        cout << st.mex() << '\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case " << cs << ": ";
        solve();
    }
    return 0;
}