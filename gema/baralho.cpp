#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s, naipes = "CEUP";
    cin >> s;

    map<char, int[13]> m;
    map<char, int> miss;

    for(char n: naipes) {
        memset(m[n], 0, sizeof m[n]);
        miss[n] = 0;
    }

    int num, i = 0;

    //analise do baralho
    while(i < s.size()) {
        num = 0;
        num += 10*(s[i++] - '0');
        num += s[i++] - '0';
        m[s[i++]][num]++;
    }

    string ans;

    for(char n: naipes) {
        for(int i = 0; i < 13; ++i) {
            if(m[n][i] > 1) {
                ans = "erro";
                break;
            }
            else if(m[n][i] == 0) miss[n]++;
        }

        if(ans == "erro") cout << ans;
        else if(miss[n] >= 0) cout << miss[n];
        else cout << "ok";

        cout << endl;
    }
}
