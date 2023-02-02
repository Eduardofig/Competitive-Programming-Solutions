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
string s;

set<char> se = {'.', ',', '?', '!', '@', '"'};

bool isok(char c) {
    bool ok = c >= 'A' && c <= 'Z';
    ok = ok || (c >= 'a' && c <= 'z');
    ok = ok || (c >= '0' && c <= '9');


    ok = ok || (se.find(c) != se.end());

    return ok;
}
 
void solve()
{
    int i = 0;
    n = s.size();

    while(i < n) {
        if(s[i] == '"') {
            int j = i + 1;

            while(j < n && s[j] != '"') {
                if(s[j] == ' ') {
                    s[j] = '@';
                }
                j++;
            }
            i = j;
        }
        i++;
    }
    vector<string> ans;

    string tmp = "";

    i = 0;

    while(i < n) {
        while(!isok(s[i]) && i < n) {
            i++;
        }
        while(isok(s[i]) && i < n) {
            tmp += s[i];
            i++;
        }

        if(tmp != "") {
            ans.push_back(tmp);
        }
        tmp = "";

    }

    for(string &arg: ans) {

        cout << "<";
        for(char c: arg) {
            if(c != '"') {
                if(c == '@') {
                    cout << ' ';
                } else {
                    cout << c;
                }
            }
        }
        cout << ">\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    getline(cin, s);
    solve();
}
