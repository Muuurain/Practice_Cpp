#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    long long sum = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'F') {
            s[i] = 'E';
        }
    }
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'H') {
            sum += s.length() - i;
        }
    }
    if(sum & 1) {
        cout << "Alice" << endl;
    }
    else {
        cout << "Bob" << endl;
    }


    return 0;
}