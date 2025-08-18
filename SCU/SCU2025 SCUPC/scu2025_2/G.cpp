#include <bits/stdc++.h>
using namespace std;

queue<int> q;
int main() {
    int N, K;
    cin >> N >> K;
    int seat = 0;
    while(N--) {
        int a;
        scanf("%d", &a);
        q.push(a);
    }
    int ret = 0;
    while(!q.empty()) {
        int now = q.front();
        if(seat + now <= K) {
            q.pop();
            seat += now;
        }
        else {
            ret++;
            seat = 0;
        }
    }
    if(seat) {
        ret++;
    }
    cout << ret << endl;

    return 0;
}