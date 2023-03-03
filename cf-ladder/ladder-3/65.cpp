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
string s, t;
 
void solve()
{
    int cnts[26]{}, cntt[26]{};

    for(char c: t) {
        cntt[c - 'a']++;
    }

    int j = 0;
    for(char c: s) {
        if(c == t[j] && j < t.size()) {
            j++;
        }

        cnts[c - 'a']++;
    }

    bool is_sub = j == t.size();

    if(is_sub) {
        cout << "automaton\n";
        return;
    }
    
    bool has = true;
    bool eq = true;

    for(int i = 0; i < 26; i++) {
        if(cntt[i] != cnts[i]) {
            eq = false;
        }
        if(cntt[i] > cnts[i]) {
            has = false;
        }
    }

    if(eq) {
        cout << "array\n";
        return;
    }

    if(has) {
        cout << "both\n";
        return;
    }

    cout << "need tree\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> s >> t;
    solve();
}
