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

int pa(int n) {
    return (1 + n) * n / 2;
}
 
void solve()
{
    if(a > b) {
        swap(a, b);
    }

    int target = (a + b) / 2;

    cout << pa(target - a) + pa(b - target) << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> a >> b;
    solve();
}
