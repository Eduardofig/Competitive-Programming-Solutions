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

int a, b;
//int k;
//int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    for(int turn = 1; true; ++turn) {
        if(turn % 2 > 0) {
            int n = turn / 2 + turn % 2;
            int vl = a - n * n;
            if(vl < 0) {
                cout << "Vladik\n";
                return;
            }
        } else {
            int n = turn / 2;
            int va = b - n * (n + 1);
            if(va < 0) {
                cout << "Valera\n";
                return;
            }
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> a >> b;
    solve();
}
