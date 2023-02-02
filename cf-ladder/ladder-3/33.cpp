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
int a[MXN];
int b[MXN];
//string s;
 
void solve()
{
    set<int> fi;
    int i = 0, j = 0;

    while(i < n) {
        while(fi.find(a[i]) != fi.end() && i < n) {
            i++;
        }

        while(a[i] != b[j] && j < n) {
            fi.insert(b[j]);
            j++;
        }

        i++;
        j++;
    }

    cout << fi.size() << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    solve();
}
