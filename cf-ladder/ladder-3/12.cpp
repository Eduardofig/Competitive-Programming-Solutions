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
string og, s;
int cnt = 0;
int target;

void bkt(int pos, int curr)
{
    if(pos == n) {
        if(curr == target) {
            cnt++;
        }
        return;
    }

    if(s[pos] == '-') {
        bkt(pos + 1, curr - 1);
    } else if(s[pos] == '+') {
        bkt(pos + 1, curr + 1);
    } else {
        bkt(pos + 1, curr + 1);
        bkt(pos + 1, curr - 1);
    }
}

void solve()
{
    n = og.size();
    target = 0;

    for(char c: og) {
        if(c == '-') {
            target--;
        } else {
            target++;
        }
    }

    bkt(0, 0);

    double ans = (double)cnt / ((double)(1 << (count(s.begin(), s.end(), '?'))));

    cout << fixed << setprecision(12) << (ans > 1.0? 1.0: ans) << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> og >> s;
    solve();
}
