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
        for (int i = 1; i <= n; i++)
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
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};
void solve()
{
    int n;
    cin >> n;
    DSU st(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        st.marge(x, i);
    }
    for (int i = 1; i <= n; i++)
    {
        int rt = st.find_set(i);
        cout << st.size[rt] << ' ';
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