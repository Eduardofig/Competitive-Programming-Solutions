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

ull k;
//int k;
//int a[MXN];
//int b[MXN];
//string s;

vector<ull> range;

void init()
{
    range.push_back(0);
    range.push_back(9);
    ull curr = 90;
    ull digits = 2;

    do {
        range.push_back(range.back() + curr * digits++);
        curr *= 10;
    } while(range.back() <= (ull)1e18); 

    /*
    for(ull i: range) {
        cout << i << '\n';
    }
    */
}
 
void solve()
{
    ull digits = lower_bound(range.begin(), range.end(), k) - range.begin();

    ull over = k - range[digits - 1];

    ull num = 1;
    
    for(int i = 0; i < digits - 1; ++i) {
        num *= 10;
    }

    num += over / digits - (ull)(over > 0);

    string ans = to_string(num);

    cout << ans[max<ull>(over - 1, 0) % digits] << '\n';

}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    init();
    int q;
    cin >> q;
    while(q--) {
        cin >> k;
        solve();
    }
}
