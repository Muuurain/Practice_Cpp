#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;
int ret[N] = {1};
int num[1000];

void bigmulti(int x) {
    int head = 0;
    for(int i = N - 1; i >= 0; i--) {
        if(ret[i] != 0) {
            head = i;
            break;
        }
    }
    for(int i = 0; i <= head; i++) {
        ret[i] *= x;
    }
    int jin = 0;
    for(int i = 0; i < N; i++) {
        ret[i] += jin;
        jin = ret[i] / 10;
        ret[i] %= 10;
    }
}

int main() {
    int n;
    cin >> n;
    if(n == 3 || n == 4) {
        cout << n << endl;
        cout << n << endl;
    }
    else {
        int sum = 0;
        int cnt = 0;
        for(int i = 2; sum + i <= n; i++) {
            num[cnt++] = i;
            sum += i;
        }
        if(sum < n) {
            int temp = cnt - 1;
            for(int i = temp; i >= 0; i--) {
                num[temp--]++;
                sum++;
                if(sum == n) {
                    break;
                }
            }
            if(sum < n) {
                num[cnt - 1]++;
                sum++;
            }
        }
        for(int i = 0; i < cnt; i++) {
            bigmulti(num[i]);
        }
        int head = 0;
        for(int i = N - 1; i >= 0; i--) {
            if(ret[i]) {
                head = i;
                break;
            }
        }
        for(int i = 0; i < cnt; i++) {
            cout << num[i];
            if(i != cnt - 1) {
                cout << " ";
            }
            else {
                cout << endl;
            }
        }
        for(int i = head; i >= 0; i--) {
            printf("%d", ret[i]);
        }
        cout << endl;
    }

    return 0;
}