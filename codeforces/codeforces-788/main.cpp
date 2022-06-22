#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 1e4 + 3;
const int INF = 0x3f3f3f3f;

int n;
int a[MXN], b[MXN], p[MXN];
vector<int> ga[MXN], gb[MXN];
 
void solve()
{
    for(int i = 0; i < n; ++i) {

    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        cin >> n;

        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            a[i]--;
        }
        for(int i = 0; i < n; ++i) {
            cin >> b[i];
            b[i]--;
        }
        for(int i = 0; i < n; ++i) {
            cin >> p[i];
            if(p[i] != 0) {
                p[i]--;
            }
        }

        solve();
    }
}
