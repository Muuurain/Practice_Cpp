#include <bits/stdc++.h>
using namespace std;

int ret[210];
int K[210];
queue<int> q;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(ret, -1, sizeof(ret));
    int N, A, B;
    cin >> N >> A >> B;
    ret[A] = 0;
    for(int i = 1; i <= N; i++) {
        cin >> K[i];
    }
    if(A + K[A] > 0 && A + K[A] <= N) {
        q.push(A + K[A]);
        ret[A + K[A]] = ret[A] + 1;
    }
    if(A - K[A] > 0 && A - K[A] <= N) {
        q.push(A - K[A]);
        ret[A - K[A]] = ret[A] + 1;
    }
    while(!q.empty()) {
        A = q.front();
        q.pop();
        if(A + K[A] > 0 && A + K[A] <= N && ret[A + K[A]] == -1) {
            q.push(A + K[A]);
            ret[A + K[A]] = ret[A] + 1;
            if(A + K[A] == B) {
                break;
            }
        }
        if(A - K[A] > 0 && A - K[A] <= N && ret[A - K[A]] == -1) {
            q.push(A - K[A]);
            ret[A - K[A]] = ret[A] + 1;
            if(A - K[A] == B) {
                break;
            }
        }
    }
    cout << ret[B] << endl;


    return 0;
}