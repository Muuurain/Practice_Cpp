#include <bits/stdc++.h>

using namespace std;

vector<int> a, b;
int score[2];

int main() {
    int N, Na, Nb;
    cin >> N >> Na >> Nb;

    for(int i = 0; i < Na; i++) {
        int t;
        cin >> t;
        a.push_back(t);
    }
    for(int i = 0; i < Nb; i++) {
        int t;
        cin >> t;
        b.push_back(t);
    }
    int cnt1 = 0, cnt2 = 0;
    while(N--) {
        if(a[cnt1] == 0) {
            if(b[cnt2] == 1 || b[cnt2] == 4) {
                score[1]++;
            } 
            else if(b[cnt2] == 2 || b[cnt2] == 3) {
                score[0]++;
            }
        }
        else if(a[cnt1] == 1) {
            if(b[cnt2] == 0 || b[cnt2] == 3) {
                score[0]++;
            }
            else if(b[cnt2] == 2 || b[cnt2] == 4) {
                score[1]++;
            }
        }
        else if(a[cnt1] == 2) {
            if(b[cnt2] == 0 || b[cnt2] == 3) {
                score[1]++;
            }
            else if(b[cnt2] == 1 || b[cnt2] == 4) {
                score[0]++;
            }
        }
        else if(a[cnt1] == 3) {
            if(b[cnt2] == 0 || b[cnt2] == 1) {
                score[1]++;
            }
            else if(b[cnt2] == 2 || b[cnt2] == 4) {
                score[0]++;
            }
        }
        else if(a[cnt1] == 4) {
            if(b[cnt2] == 0 || b[cnt2] == 1) {
                score[0]++;
            }
            else if(b[cnt2] == 2 || b[cnt2] == 3) {
                score[1]++;
            }
        }
        cnt1 = (cnt1 + 1) % Na;
        cnt2 = (cnt2 + 1) % Nb;
    }
    cout << score[0] << " " << score[1] << endl;

    return 0;
}