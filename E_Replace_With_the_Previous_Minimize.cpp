#include <bits/stdc++.h>
#define ll long long int
using namespace std;
class DSU
{
public:
    int n;
    vector<int> parent;
    vector<int> size;
    DSU(int n)
    {
        this->n = n;
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i, size[i] = 1;
    }
    int find_set(int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }
    void marge(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
        {
            // if (size[a] < size[b])
            if (a > b)
                swap(a, b);
            parent[b] = a;
            size[b] += size[a];
        }
    }
};
void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    DSU st(29);
    for (int i = 0; i <= n; i++)
    {
        int x = s[i] - 'a';
        while (x > 0 && k > 0 && st.find_set(x) != st.find_set(x - 1))
        {
            st.marge(x, x - 1);
            x--, k--;
        }
        if (st.find_set(0) == st.find_set(25))
            break;
    }
    for (int i = 0; i < n; i++)
    {
        cout << char(st.find_set(s[i] - 'a') + 'a');
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}