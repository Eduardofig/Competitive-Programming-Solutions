#include <bits/stdc++.h>


using namespace std;

using ll = long long;
using ull = unsigned long long;

string s;
ull n, tt, ans;

const int MXN = 2e6 + 3;

struct trie_node
{
    ll ch[2];
    ull end;
};

trie_node trie[MXN];

void insert_trie(string s)
{
    ull curr = 0;

    for(char c: s) {
        if(trie[curr].ch[c - '0'] == 0) {
            trie[curr].ch[c - '0'] = ++tt;
            trie[tt].end = 0;
            memset(trie[tt].ch, 0, sizeof trie[tt].ch);
        }
        trie[trie[curr].ch[c - '0']].end++;
        curr = trie[curr].ch[c - '0'];
    }
}

void dfs(ull curr, ull val)
{
    for(int i = 0; i < 2; ++i) {
        ull next = trie[curr].ch[i];
        if(next != 0) {
            if(i == (val ^ 1) || curr == 0) {
                ans += trie[next].end;
            }
            dfs(next, i);
        }
    }
}

void solve()
{
    tt = 0;
    ans = 0;
    memset(trie[0].ch, 0, sizeof trie[0].ch);

    for(int i = 0; i < n; ++i) {
        insert_trie(s.substr(i, n));
    }

    dfs(0, (s[0] - '0') ^ 1);

    cout << ans << '\n';
}

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        cin >> n >> s;
        solve();
    }
}
