#include<bits/stdc++.h>
using namespace std;

int n, m;
const int N = 1e6 + 10;
int num[N];
int check(int aim) {
    int l = 1, r = n;
    int mid;
    while(l < r) {
        mid = (l + r) / 2;
        if(num[mid] >= aim) {
            r = mid;
        }
        else if(num[mid] < aim) {
            l = mid + 1;
        }
    }
    if(num[l] == aim) {
        return l;
    }
    else {
        return -1;
    }   
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> num[i];
    }
    while(m--) {
        int aim;
        cin >> aim;
        cout << check(aim) << ' ';
    }


    return 0;
}