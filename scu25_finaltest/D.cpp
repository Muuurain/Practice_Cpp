#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    int sum = 0;
    cin >> N;
    if(N < 0) {
        N *= -1;
        while(N) {
            sum = sum * 10 + N % 10;
            N /= 10;
        }
        sum *= -1;
    }
    else {
        while(N) {
            sum = sum * 10 + N % 10;
            N /= 10;
        }
    }
    cout << sum << endl;
    return 0;
}