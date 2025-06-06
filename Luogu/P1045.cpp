#include <bits/stdc++.h>

using namespace std;
const int N = 500;
typedef long long ll;

int ret[N] = {1};
int pow2s[50][N];
void bigmulti(int ret[], int num[], int temp[]) {
    for(int i = 0; i < N; i++) {
        if(ret[i] == 0) continue;
        else {
            for(int j = 0; j < N; j++) {
                if(num[j] == 0) continue;
                else if(i + j >= 500) break;
                else {
                    temp[i + j] += ret[i] * num[j]; 
                }
            }
        }
    } 
    int carry = 0;
    for(int i = 0; i < N; i++) {
        temp[i] += carry;
        carry = temp[i] / 10;
        temp[i] %= 10;
    }
}

void quick_pow(int p) {
    vector<int> bits;
    while(p) {
        bits.push_back(p & 1);
        p >>= 1;
    }
    int temp[N] = {2};
    int cnt = 0;
    memcpy(pow2s[cnt++], temp, sizeof(temp));
    for(int i = 1; i < bits.size(); i++) {
        int prev[N] = {0};
        memcpy(prev, pow2s[cnt - 1], sizeof(prev));
        int temp[N] = {0};
        bigmulti(prev, prev, temp);
        memcpy(pow2s[cnt++], temp, sizeof(temp));
    }

    for(int i = 0; i < bits.size(); i++) {
        if(bits[i]) {
            int temp[N] = {0};
            bigmulti(ret, pow2s[i], temp);
            memcpy(ret, temp, sizeof(ret));
        }
    }
 
}

int main() {
    int P;
    cin >> P;
    int index = P * log10(2) + 1;
    cout << index << endl;
    quick_pow(P);
    int cnt = N - 1;
    ret[0]--;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 50; j++) {
            cout << ret[cnt--];
        }
        cout << endl;
    }

    return 0;
}