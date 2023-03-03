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

map<string, int> cnt;
vector<pair<char, string>> q;

void trns(string &s)
{
    reverse(s.begin(), s.end());

    for(char &c: s) {
        c = '0' + ((c - '0') % 2);
    }

    while(s.size() < 18) {
        s.push_back('0');
    }
}
 
void solve()
{
    for(auto &[op, num]: q) {

        trns(num);

        switch(op) {
            case '+':
                cnt[num]++;
            break;
            case '-':
                cnt[num]--;
            break;
            case '?':
                cout << cnt[num] << '\n';
            break;
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n;
    q.resize(n);

    for(auto &[op, num]: q) {
        cin >> op >> num;
    }
    solve();
}
