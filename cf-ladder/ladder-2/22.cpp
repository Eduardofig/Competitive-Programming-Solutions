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
//string s;
multiset<int> s1, s2, s3;
 
void solve()
{
    for(int i: s2) {
        s1.erase(s1.find(i));
    }

    for(int i: s3) {
        s2.erase(s2.find(i));
    }

    cout << *s1.begin() << '\n' << *s2.begin() << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        s1.insert(num);
    }

    for(int i = 0; i < n - 1; ++i) {
        int num;
        cin >> num;
        s2.insert(num);
    }

    for(int i = 0; i < n - 2; ++i) {
        int num;
        cin >> num;
        s3.insert(num);
    }
    solve();
}
