#include <bits/stdc++.h>

using namespace std;

int main()
{
    wstring s = L"We can only see a short distance ahead, but we can see plenty there that needs to be done.\n Science is a differential equation. Religion is a boundary condition.";

    ofstream file("rom.txt");

    file << "v2.0 raw" << endl;

    for(char c: s) {
        file << hex << (int)c << endl;
    }

    for(int i = s.size(); i < 0xff; ++i) {
        file << hex << rand() % 0xffff << endl;
    }
}
