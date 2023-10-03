#include <bits/stdc++.h>
using namespace std;

#define LL long long
const int N = 2e6 + 5, MOD = 1e9 + 7;

char s[N], t[N], s1[N], t1[N];

int main()
{
    //    freopen("in.txt","r",stdin);
    ios::sync_with_stdio(0);

    cin >> s >> t;
    int n = strlen(s), l2 = strlen(t);

    if (strcmp(s, t) == 0)
    {
        cout << "=" << endl;
        return 0;
    }

    int p1 = 0, p2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (p1 < n)
        {
            if (s[p1] >= 'a' && s[p1] <= 'z')
            {
                if (s[p1] == t[p2])
                {
                    p1++, p2++;
                    continue;
                }
                else
                {
                    if (s[p1] < t[p2])
                    {
                        cout << "<" << endl;
                        return 0;
                    }
                    else
                    {
                        cout << ">" << endl;
                        return 0;
                    }
                }
            }
            else
            {
                int t1 = p1, t2 = p2;
                while (t1 < n && s[t1] >= '0' && s[t1] <= '9')
                    t1++;
                while (t2 < l2 && t[t2] >= '0' && t[t2] <= '9')
                    t2++;
                if (t1 - p1 != t2 - p2)
                {
                    if (t1 - p1 < t2 - p2)
                    {
                        cout << "<" << endl;
                        return 0;
                    }
                    else
                    {
                        cout << ">" << endl;
                        return 0;
                    }
                }
                else
                {
                    for (int i = 0; i < t1 - p1; i++)
                    {
                        if (s[p1 + i] < t[p2 + i])
                        {
                            cout << "<" << endl;
                            return 0;
                        }
                        else if (s[p1 + i] > t[p2 + i])
                        {
                            cout << ">" << endl;
                            return 0;
                        }
                    }
                    p1 = t1, p2 = t2;
                }
            }
        }
        else
            break;
    }
}
