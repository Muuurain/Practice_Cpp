#include <bits/stdc++.h>

using namespace std;

void bplus(int num, int ret[]) {
    if(num == 0) {
        return;
    }
    int head = 0;
    for(int i = 2999; i >= 0; i--) {
        if(ret[i]) {
            head = i;
            break;
        }
    }
    for(int i = 0; i < 3000; i++) {
        ret[i] *= num;
    }
    int jin = 0;
    int t;
    for(int i = 0; i < 3000; i++) {
        int t = ret[i] + jin;
        ret[i] = t % 10;
        jin = t / 10;
    }
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        int ret[3000] = {1};
        int n, a;
        cin >> n >> a;
        int cnt = 0;
        for(int i = n; i > 1; i--) {
            bplus(i, ret);
        }
        int head = 0;
        for(int i = 2999; i >= 0; i--) {
            if(ret[i]) {
                head = i;
                break;
            }
        }
        for(int i = 0; i <= head; i++) {
            if(ret[i] == a) {
                cnt++;
            }
        }
        cout << cnt <<endl;
    }

    return 0;
}