#include <bits/stdc++.h>

using namespace std;

int main() {
    int opt = 4;
    string s;
    cin >> s;
    int spc;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '.') {
            opt = 1;
            spc = i;
            break;
        }
        else if(s[i] == '/') {
            opt = 2;
            spc = i;
            break;
        }
        else if(s[i] == '%') {
            opt = 3;
            break;
        }
    }
    string ans = "";
    int n0 = 0;
    int start = 1;
    int temp;
    switch (opt) {
        case 1: {
            for(int i = spc - 1; i >= 0; i--) {
                if(start) {
                    if(s[i] == '0') {
                        continue;
                    }
                    else {
                        start = 0;
                        ans += s[i];
                    }
                }
                else {
                    ans += s[i];
                }
            }
            if(ans.length() == 0) {
                ans += "0";
            }
            ans += ".";
            temp = ans.length();
            for(int i = spc + 1; i < s.length(); i++) {
                if(s[i] == '0') {
                    n0++;
                }
                else {
                    break;
                }
            }
            for(int i = s.length() - 1; i >=  spc + 1 + n0; i--) {
                ans += s[i];
            }
            if(ans.length() == temp) {
                ans += "0";
            }
            break;
        }
        case 2: {
            for(int i = spc - 1; i >= 0; i--) {
                if(start) {
                    if(s[i] == '0') {
                        continue;
                    }
                    else {
                        start = 0;
                        ans += s[i];
                    }
                }
                else {
                    ans += s[i];
                }
            }
            if(ans.length() == 0) {
                ans += "0";
            }
            ans += "/";
            start = 1;
            temp = ans.length();
            for(int i = s.length() - 1; i >=  spc + 1; i--) {
                if(start) {
                    if(s[i] == '0') {
                        continue;
                    }
                    else {
                        start = 0;
                        ans += s[i];
                    }
                }
                else {
                    ans += s[i];
                }
            }
            if(ans.length() == temp) {
                ans += "0";
            }
            break;
        }
        case 3: {
            for(int i = s.length() - 2; i >= 0; i--) {
                if(start) {
                    if(s[i] == '0') {
                        continue;
                    }
                    else {
                        start = 0;
                        ans += s[i];
                    }
                }
                else {
                    ans += s[i];
                }
            }
            if(ans.length() == 0) {
                ans += "0";
            }
            ans += "%";
            break;
        }
        case 4: {
            for(int i = s.length() - 1; i >= 0; i--) {
                if(start) {
                    if(s[i] == '0') {
                        continue;
                    }
                    else {
                        start = 0;
                        ans += s[i];
                    }
                }
                else {
                    ans += s[i];
                }
            }
            if(ans.length() == 0) {
                ans += "0";
            }
            break;
        }
    }

    cout << ans << endl;

    return 0;
}