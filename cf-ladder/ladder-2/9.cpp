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

int a1, a2;
//int k;
//int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    int ans = 0;
    if(a2 > a1) {
        swap(a2, a1);
    }

    while(!(a1 < 2 && a2 < 2) && a1 > 0 && a2 > 0) {
        a1 -= 2;
        a2++;

        ans++;

        if(a2 > a1) {
            swap(a2, a1);
        }
    }


    cout << ans << '\n';

}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> a1 >> a2;
    solve();
}
