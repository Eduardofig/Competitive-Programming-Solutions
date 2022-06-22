#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s;
    cin >> s;

    int count{};
    char prev{};

    for(char curr : s) {
        if(curr == prev && curr != 'W') {
            count++;
        }

        if(curr == 'W') {
            if(prev != 'W') {
                if(count >= 2) {
                    cout << "NO\n";
                    return;
                } else {
                    count = -1;
                }
            }
        } else {
            if(prev == curr && prev != 'W') {
                count++;
            } else {
                count = 1;
            }
        }

        prev = curr;
    }

    cout << "YES\n";
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        solve();
    }
}
