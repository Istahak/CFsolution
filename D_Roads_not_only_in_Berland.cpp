#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
const int N = 10000;
vector<int> parent(N);
vector<int> xans(N), yans(N), zans(N);
int cnt = 0;
void make_set(int v)
{
    parent[v] = v;
}

int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{

    if (a != b)
        parent[b] = a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        make_set(i);
    }
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        int a = find_set(x);
        int b = find_set(y);
        if (a == b)
        {
            cnt++;
            xans[cnt] = x;
            yans[cnt] = y;
        }
        else
        {
            union_sets(a, b);
        }
    }
    cout << cnt << endl;
    cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (parent[i] == i)
        {
            cnt++;
            zans[cnt] = i;
        }
    }
    for (int i = 1; i < cnt; i++)
    {
        cout << xans[i] << ' ' << yans[i] << ' ' << zans[i] << ' ' << zans[i + 1] << endl;
    }

    return 0;
}