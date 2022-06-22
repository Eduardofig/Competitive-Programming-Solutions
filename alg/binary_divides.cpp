#include <bits/stdc++.h>

using namespace std;

string binary;
const int num = 131071;

void solve()
{
    int z = 0;

    for(char c: binary) {
        if(c == '1') {
            if(z*2 + 1 >= num) z = z*2 + 1 - num;
            else z = z*2 + 1;
        } else if(c == '0') {
            if(z*2 > num) z = z*2 - num;
            else z *= 2;
        }
    }

    if(z == 0) cout << "YES";
    else cout << "NO";
    cout << endl;
}

int main()
{
    while(cin >> binary)
        solve();
}
