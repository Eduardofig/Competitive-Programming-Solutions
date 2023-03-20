#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e6 + 3;
const int INF = 0x3f3f3f3f;

const bool MULTIPLE_TESTCASES = 0;

int n;
//int a[MXN];
//int b[MXN];
string s;

int pg[MXN];

const int MOD = 1e9 + 7;

int mod_add(int a, int b)
{
    a %= MOD;
    b %= MOD;

    return (a + b) % MOD;
}
    
int mod_mul(int a, int b)
{
    a %= MOD;
    b %= MOD;
    
    return (a * b) % MOD;
}

int mod_sub(int a, int b)
{
    a %= MOD;
    b %= MOD;
    
    return (((a - b) % MOD) + MOD) % MOD;
}

void init()
{
    int curr = 1;
    pg[1] = 1;

    for(int i = 2; i < MXN; i++) {
        curr = mod_mul(curr, 2);
        pg[i] = mod_add(pg[i - 1], curr);
    }
}

void solve()
{
    init();
    int pref = 0;
    int ans = 0;

    for(char c: s) {
        if(c == 'a') {
            pref++;
        } else {
            ans = mod_add(ans, pg[pref]);
        }
    }

    cout << (ans % MOD) << '\n';
}


void read()
{
    cin >> s;
    n = s.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    if(MULTIPLE_TESTCASES) {
        int t;
        cin >> t;
        while(t--) {
            read();
            solve();
        }
    } else {
        read();
        solve();
    }
}
