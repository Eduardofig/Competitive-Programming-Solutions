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

int n, m;
int pw[10000];
//int k;
//int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    int idx = 0;

    pw[0] = 1;

    while(pw[idx] <= (int)1e8) {
        pw[idx + 1] = pw[idx] * 2;
        idx++;
    }

    if(n > idx) {
        cout << m;
    } else {
        cout << m % pw[n];
    }

    cout << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> m;
    solve();
}
