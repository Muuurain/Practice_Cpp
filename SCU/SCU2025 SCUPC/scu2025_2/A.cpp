#include <bits/stdc++.h>

using namespace std;

long long plant[210000];
long long A[210000];
long long ret[200];
void bigplus(long long num) {
    int cnt = 0;
    num *= num;
    while(num) {
        ret[cnt] += num % 10;
        cnt++;
        num /= 10;
    }
    int jin = 0;
    for(int i = 0; i < 200; i++) {
        ret[i] += jin;
        jin = ret[i] / 10;
        ret[i] %= 10;
    }
}
int main() {
    int N, M;
    cin >> N >> M;
    int cnt = 1;
    for(int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }
    sort(A, A + N);
    for(int i = N - 1; i >= N - M; i--) {
        plant[cnt] += A[i];
        cnt++;
    }
    cnt--;
    for(int i = N - M - 1; i >= 0; i--) {
        plant[cnt] += A[i];
        cnt--;
    }
    for(int i = 1; i <= M; i++) {
        bigplus(plant[i]);
    }
    int head = 0;
    for(int i = 199; i >= 0; i--) {
        if(ret[i]) {
            head = i;
            break;
        }
    }
    for(int i = head; i >= 0; i--) {
        cout << ret[i];
    }
    cout << endl;

    return 0;
}