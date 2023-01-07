#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;
const int MOD = 1e7 + 9;

ll n;
//ll k;
//ll a[MXN];
//ll b[MXN];
//string s;

struct point
{
    ll x{}, y{};

    ll operator^(point p)
    {
        ll x2 = p.x;
        ll y2 = p.y;

        return x * y2 - x2 * y;
    }

    point operator+(point p)
    {
        ll x2 = p.x;
        ll y2 = p.y;

        return point(x + x2, y + y2);
    }

    point operator-(point p)
    {
        ll x2 = p.x;
        ll y2 = p.y;

        return point(x - x2, y - y2);
    }

    point operator*(point p)
    {
        ll x2 = p.x;
        ll y2 = p.y;

        return point(x * x2, y * y2);
    }

    point operator*(ll s)
    {
        return point(x * s, y * s);
    }

    point(){}

    point(ll x, ll y)
    {
        this->x = x;
        this->y = y;
    }
};
 
point p1, p2, p3;

void solve()
{
    point dir1 = p2 - p1;
    point dir2 = p3 - p1;

    ll cross = dir1 ^ dir2;

    if(cross == 0) {
        cout << "TOUCH";
    } else if(cross > 0) {
        cout << "LEFT";
    } else {
        cout << "RIGHT";
    }
    cout << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    ll t;
    cin >> t;
    while(t--) {
        cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
        solve();
    }
}
