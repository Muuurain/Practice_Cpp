#include <bits/stdc++.h>

using namespace std;

string temp[100];

int main() {
    int p1, p2, p3;
    cin >> p1 >> p2 >> p3;
    string s = "";
    string ret = "";
    cin >> s;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] != '-') {
            ret += s[i];
        }
        else {
            if(((s[i - 1] >= '0' && s[i + 1] <= '9') || (s[i - 1] >= 'a' && s[i + 1] <= 'z')) && s[i - 1] < s[i + 1]) {
                if(p3 == 1) {
                    for(int j = s[i - 1] + 1; j < s[i + 1]; j++) {
                        if(s[i - 1] >= 'a' && s[i - 1] <= 'z') {
                            if(p1 == 1) {
                                for(int k = 0; k < p2; k++) {
                                    ret += (char)j;
                                }
                            }
                            else if(p1 == 2) {
                                for(int k = 0; k < p2; k++) {
                                    ret += (char)(j - 'a' + 'A');
                                }
                            }
                            else {
                                for(int k = 0; k < p2; k++) {
                                    ret += "*";
                                }
                            }
                        }
                        else {
                            if(p1 != 3) {
                                for(int k = 0; k < p2; k++) {
                                    ret += (char)j;
                                }
                            }
                            else {
                                for(int k = 0; k < p2; k++) {
                                    ret += "*";
                                }
                            }
                        }
                    }
                }
                else {
                    for(int j = s[i + 1] - 1; j > s[i - 1]; j--) {
                        if(s[i - 1] >= 'a' && s[i - 1] <= 'z') {
                            if(p1 == 1) {
                                for(int k = 0; k < p2; k++) {
                                    ret += (char)j;
                                }
                            }
                            else if(p1 == 2) {
                                for(int k = 0; k < p2; k++) {
                                    ret += (char)(j - 'a' + 'A');
                                }
                            }
                            else {
                                for(int k = 0; k < p2; k++) {
                                    ret += "*";
                                }
                            }
                        }
                        else {
                            if(p1 != 3) {
                                for(int k = 0; k < p2; k++) {
                                    ret += (char)j;
                                }
                            }
                            else {
                                for(int k = 0; k < p2; k++) {
                                    ret += "*";
                                }
                            }
                        }
                    }
                }
            }
            else {
                ret += s[i++];
                ret += s[i];
            }
        }
    }
    cout << ret;

    

    return 0;
}