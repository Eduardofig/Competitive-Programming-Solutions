#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;

int ex, ey, sx, sy, t;
string s;
 
void solve()
{
    int distx = abs(ex - sx), disty = abs(ey - sy);
    char rightx = ex > sx? 'E': 'W';
    char righty = ey > sy? 'N': 'S';

    for(int i = 0; i < t; ++i) {
        if(s[i] == rightx) {
            distx--;
        } else if(s[i] == righty) {
            disty--;
        }
        if(distx <= 0 && disty <= 0) {
            cout << i + 1 << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> t >> sx >> sy >> ex >> ey >> s;
    solve();
}
