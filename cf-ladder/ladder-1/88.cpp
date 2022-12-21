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
string s;

void solve()
{
    int x{}, y{}, ans{};

    int plane = 0;

    for(char c: s) {

        if(c == 'R') {
            x++;
        } else if(c == 'L') {
            x--;
        } else if(c == 'D') {
            y--;
        } else if(c == 'U') {
            y++;
        }

        if(x != y) {
            int new_plane = x > y? 1: -1;

            if(new_plane != plane) {
                if(plane != 0) {
                    ans++;
                }
                plane = new_plane;
            }
        }
    }

    cout << ans << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> s;
    solve();
}
