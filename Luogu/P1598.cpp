#include <bits/stdc++.h>

using namespace std;

unordered_map<char, int> lt;
int main() {
    char c;
    while((c = getchar()) != EOF) {
        if(c >= 'A' && c <= 'Z') {
            lt[c]++;
        }
    }
    int maxcnt = 0;
    for(char i = 'A'; i <= 'Z'; i++) {
        maxcnt = max(maxcnt, lt[i]);
    }
    for(int i = maxcnt; i >= 0; i--) {
        if(i != 0) {
            for(int j = 'A'; j <= 'Z'; j++) {
                if(lt[j] == i) {
                    cout << "*";
                    lt[j]--;
                }
                else {
                    cout << " ";
                }
                if(j != 'Z') {
                    cout << " ";
                }
            }
        }
        else {
            for(char j = 'A'; j <= 'Z'; j++) {
                cout << j;
                if(j != 'Z') {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }

    return 0;
}