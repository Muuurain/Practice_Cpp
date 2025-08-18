#include <bits/stdc++.h>

using namespace std;

int main() {
    char c;
    string s = "";
    while((c = getchar()) != 'E') {
        if(c == 'W' || c == 'L') {
            s += c;
        }
    }
    int cnt1 = 0;
    int cnt2 = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'W') {
            cnt1++;
        }
        else if(s[i] == 'L') {
            cnt2++;
        }
        if(cnt1 >= 11 && cnt1 > cnt2 && cnt1 - cnt2 > 1) {
            cout << cnt1 << ":" << cnt2 << endl;
            cnt1 = cnt2 = 0;
        }
        else if(cnt2 >= 11 && cnt2 > cnt1 && cnt2 - cnt1 > 1) {
            cout << cnt1 << ":" << cnt2 << endl;
            cnt1 = cnt2 = 0;
        }
    }
    cout << cnt1 << ":" << cnt2 << endl << endl;
    cnt1 = cnt2 = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'W') {
            cnt1++;
        }
        else if(s[i] == 'L') {
            cnt2++;
        }
        if(cnt1 >= 21 && cnt1 > cnt2 && cnt1 - cnt2 > 1) {
            cout << cnt1 << ":" << cnt2 << endl;
            cnt1 = cnt2 = 0;
        }
        else if(cnt2 >= 21 && cnt2 > cnt1 && cnt2 - cnt1 > 1) {
            cout << cnt1 << ":" << cnt2 << endl;
            cnt1 = cnt2 = 0;
        }
    }
    cout << cnt1 << ":" << cnt2 << endl;

    return 0;
}