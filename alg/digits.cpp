#include <bits/stdc++.h>

using namespace std;

long long num;
multiset<int> digits;

void solve()
{
    digits.clear();

    if(num == 0) {
        cout << 0 << endl;
        return;
    }

    for(int i = 9; i >= 2; --i) {
        while(!(num % i) && num != 0) {
            digits.insert(i);
            num /= i;
        }
    }

    if(num != 1) cout << -1;
    else if(digits.empty()) cout << 1;
    else cout << accumulate(digits.begin(), digits.end(), string(), [](string s, int d) { return s + to_string(d); });

    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        cin >> num;
        solve();
    }
}
