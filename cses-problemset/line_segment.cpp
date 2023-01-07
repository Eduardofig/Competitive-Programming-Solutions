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

int n;
//int k;
//int a[MXN];
//int b[MXN];
//string s;
 
struct point
{
    ll x{}, y{};

    void read()
    {
        cin >> x >> y;
    }

    ll operator^(const point &p)
    {
        ll x2 = p.x;
        ll y2 = p.y;

        return x * y2 - x2 * y;
    }

    point operator+(const point &p)
    {
        ll x2 = p.x;
        ll y2 = p.y;

        return point(x + x2, y + y2);
    }

    point operator-(const point &p)
    {
        ll x2 = p.x;
        ll y2 = p.y;

        return point(x - x2, y - y2);
    }

    point operator*(const point &p)
    {
        ll x2 = p.x;
        ll y2 = p.y;

        return point(x * x2, y * y2);
    }

    point operator*(ll s)
    {
        return point(x * s, y * s);
    }

    bool operator==(point p)
    {
        ll x2 = p.x;
        ll y2 = p.y;

        return x == x2 && y == y2;
    }

    int tri(point p1, point p2)
    {
        return (p2 - *this) ^ (p1 - *this);
    }

    point(){}

    point(ll x, ll y)
    {
        this->x = x;
        this->y = y;
    }
};

vector<point> v(4);
 
void solve()
{


    point ref = v[1] - v[0];

    if(ref.tri(v[2] - v[0], v[3] - v[0]) == 0) {
        cout << "YES\n";
        return;
    }

    point v1 = v[2] - v[0];
    point v2 = v[3] - v[0];

    if((v1 ^ ref) < 0 && (v2 ^ ref) < 0) {
        cout << "NO\n";
        return;
    }

    if((v1 ^ ref) > 0 && (v2 ^ ref) > 0) {
        cout << "NO\n";
        return;
    }

    ref = v[3] - v[2];
    v1 = v[0] - v[2];
    v2 = v[1] - v[2];

    if((v1 ^ ref) < 0 && (v2 ^ ref) < 0) {
        cout << "NO\n";
        return;
    }

    if((v1 ^ ref) > 0 && (v2 ^ ref) > 0) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        for(point &p: v) {
            p.read();
        }
        solve();
    }
}
