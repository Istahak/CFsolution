#include <bits/stdc++.h>
using namespace std;
typedef long long int ftype;
struct point2d
{
    ftype x, y;
    point2d() {}
    point2d(ftype x, ftype y) : x(x), y(y) {}
    point2d &operator+=(const point2d &t)
    {
        x += t.x;
        y += t.y;
        return *this;
    }
    point2d &operator-=(const point2d &t)
    {
        x -= t.x;
        y -= t.y;
        return *this;
    }
    point2d &operator*=(ftype t)
    {
        x *= t;
        y *= t;
        return *this;
    }
    point2d &operator/=(ftype t)
    {
        x /= t;
        y /= t;
        return *this;
    }
    point2d operator+(const point2d &t) const
    {
        return point2d(*this) += t;
    }
    point2d operator-(const point2d &t) const
    {
        return point2d(*this) -= t;
    }
    point2d operator*(ftype t) const
    {
        return point2d(*this) *= t;
    }
    point2d operator/(ftype t) const
    {
        return point2d(*this) /= t;
    }
};
point2d operator*(ftype a, point2d b)
{
    return b * a;
}

ftype dot(point2d a, point2d b)
{
    return a.x * b.x + a.y * b.y;
}

ftype norm(point2d a)
{
    return dot(a, a);
}
double abs(point2d a)
{
    return sqrt(norm(a));
}
double proj(point2d a, point2d b)
{
    return dot(a, b) / abs(b);
}
double angle(point2d a, point2d b)
{
    return acos(dot(a, b) / abs(a) / abs(b));
}
ftype cross(point2d a, point2d b)
{
    return a.x * b.y - a.y * b.x;
}

ftype orientation(point2d a, point2d b, point2d c)
{
    ftype v = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
    if (v < 0)
        return -1; // clockwise
    if (v > 0)
        return +1; // counter-clockwise
    return 0;
}

bool cw(point2d a, point2d b, point2d c, bool include_collinear)
{
    ftype o = orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}
bool collinear(point2d a, point2d b, point2d c) { return orientation(a, b, c) == 0; }
void convex_hull(vector<point2d> &a, bool include_collinear = false)
{
    point2d p0 = *min_element(a.begin(), a.end(), [](point2d a, point2d b)
                              { return make_pair(a.y, a.x) < make_pair(b.y, b.x); });
    sort(a.begin(), a.end(), [&p0](const point2d &a, const point2d &b)
         {
        int o = orientation(p0, a, b);
        if (o == 0)
            return (p0.x-a.x)*(p0.x-a.x) + (p0.y-a.y)*(p0.y-a.y)
                < (p0.x-b.x)*(p0.x-b.x) + (p0.y-b.y)*(p0.y-b.y);
        return o < 0; });
    if (include_collinear)
    {
        int i = (int)a.size() - 1;
        while (i >= 0 && collinear(p0, a[i], a.back()))
            i--;
        reverse(a.begin() + i + 1, a.end());
    }

    vector<point2d> st;
    for (int i = 0; i < (int)a.size(); i++)
    {
        while (st.size() > 1 && !cw(st[st.size() - 2], st.back(), a[i], include_collinear))
            st.pop_back();
        st.push_back(a[i]);
    }

    a = st;
}
long long int areaofthree(point2d a, point2d b, point2d c)
{
    return cross(b - a, c - a);
}
void test_case()
{

    int n;
    cin >> n;
    vector<point2d> v(n);
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].x >> v[i].y;
        mp[{v[i].x, v[i].y}] = i + 1;
    }
    convex_hull(v, true);
    vector<int> ans;
    for (auto [x, y] : v)
    {
        ans.push_back(mp[{x, y}]);
    }
    sort(ans.begin(), ans.end());
    for (auto x : ans)
        cout << x << ' ';
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