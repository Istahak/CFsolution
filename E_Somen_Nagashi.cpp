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

int orientation(point2d a, point2d b, point2d c)
{
    double v = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
    if (v < 0)
        return -1; // clockwise
    if (v > 0)
        return +1; // counter-clockwise
    return 0;
}

bool cw(point2d a, point2d b, point2d c, bool include_collinear)
{
    int o = orientation(a, b, c);
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

bool point_in_polygon(point2d point, vector<point2d> polygon)
{

    int num_vertices = polygon.size();

    int x = point.x, y = point.y;

    bool inside = false;

    // Store the first point in the polygon and initialize the second point
    point2d p1 = polygon[0], p2;

    // Loop through each edge in the polygon
    for (int i = 1; i <= num_vertices; i++)
    {

        // Get the next point in the polygon
        p2 = polygon[i % num_vertices];

        // Check if the point is above the minimum y coordinate of the edge
        if (y > min(p1.y, p2.y))
        {

            // Check if the point is below the maximum y coordinate of the edge
            if (y <= max(p1.y, p2.y))
            {

                // Check if the point is to the left of the maximum x coordinate of the edge
                if (x <= max(p1.x, p2.x))
                {

                    /*
                         Calculate the x-intersection of the line connecting the point to the edge
                    */
                    double x_intersection = (y - p1.y) * (p2.x - p1.x) / (p2.y - p1.y) + p1.x;

                    // Check if the point is on the same line as the edge or to the left of the x-intersection
                    if (p1.x == p2.x || x <= x_intersection)
                    {

                        // Flip the inside flag
                        inside = !inside;
                    }
                }
            }
        }

        // Store the current point as the first point for the next iteration
        p1 = p2;
    }

    // Return the value of the inside flag
    return inside;
}
void test_case()
{

    vector<point2d> v(4);
    for (int i = 0; i < 4; i++)
    {
        cin >> v[i].x >> v[i].y;
    }
    convex_hull(v);
    point2d pivot;
    cin >> pivot.x >> pivot.y;
    int w, h;
    cin >> w >> h;
    // for (auto [x, y] : v)
    //     cout << x << ' ' << y << endl;
    int totalarea = 0;
    for (int i = 0; i < 4; i++)
    {
        int j = (i + 1) % 4;
        totalarea += cross(v[i], v[i + 1]);
    }
    auto ok = [&](point2d a, point2d b, point2d c, point2d d)
    {
        if (point_in_polygon(a, v) == false)
            return false;
        if (point_in_polygon(b, v) == false)
            return false;
        if (point_in_polygon(c, v) == false)
            return false;
        if (point_in_polygon(d, v) == false)
            return false;

        return true;
    };

    int l = 0, r = 1e9;
    long long int ans = 0;
    while (l <= r)
    {
        int m = (l + r) / 2;
        int x1 = pivot.x - m * w;
        int x2 = pivot.x + m * w;
        int y1 = pivot.y - m * h;
        int y2 = pivot.y + m * h;
        point2d a(x1, y1), b(x1, y2);
        point2d c(x2, y1), d(x2, y2);

        if (ok(a, b, c, d))
        {
            ans = abs(x1 - x2)*1LL * abs(y1 - y2);
            l = m + 1;
        }
        else
            r = m - 1;
    }

    l = 0, r = 1e9;
    long long int ans1 = 0;
    while (l <= r)
    {
        int m = (l + r) / 2;
        int x1 = pivot.x - m * h;
        int x2 = pivot.x + m * h;
        int y1 = pivot.y - m * w;
        int y2 = pivot.y + m * w;
        point2d a(x1, y1), b(x1, y2);
        point2d c(x2, y1), d(x2, y2);

        if (ok(a, b, c, d))
        {
            ans1 = abs(x1 - x2)*1LL * abs(y1 - y2);
            l = m + 1;
        }
        else
            r = m - 1;
    }

    cout << max(ans * ans, ans1 * ans1) << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    for (int cs = 1; cs <= t; cs++)
    {
        cout << "Case " << cs << ": ";
        test_case();
    }

    return 0;
}