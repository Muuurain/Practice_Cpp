#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+100;
int n, a[N];
typedef long long ll;
bool check(){
    if(a[1] >= n) return false;
    ll sum = a[1];
    for(int i = 2; i <= n; i++){
        if(!sum) return false;
        sum--;
        if(a[i] > n-i+1) return false;
        sum += (a[i]-1);
    }
    return (!sum);
}
 
int main(){
    int _; scanf("%d", &_);
    while(_--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        printf(check()? "Yes\n": "No\n");
    }
    return 0;
}
