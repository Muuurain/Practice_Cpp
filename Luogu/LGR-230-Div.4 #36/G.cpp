#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    getline(cin, s);
    cout << "*";
    for(int i = 0; i < s.length(); i++) {
        char c = s[i];
        if(c == '(') {
            i++;
            string ts = "";
            while(s[i] != ')') {
                ts += s[i];
                i++;
            }
            i += 2;
            string tss = "";
            while(s[i] != ']') {
                tss += s[i];
                i++;
            }
            int times = stoi(tss);
            while(times--) {
                cout << ts;
            }
        }
    }
    cout << "*";


    return 0;
}