#include <bits/stdc++.h>
using namespace std;

int value = 0;
int nums[10];
int A, B, C;
void dfs(int &ans) {
    if(ans / 100) {
        if(ans % A) {
            return;
        }
        int base = ans / A;
        int t1 = base * B;
        int t2 = base * C;
        if(t1 > 999 || t2 > 999) {
            return;
        }
        for(int i = 0; i < 3; i++) {
            if(nums[t1 / (int)pow(10, i) % 10] && t1 / (int)pow(10, i) % 10) nums[t1 / (int)pow(10, i) % 10]--;
            else {
                while(i--) {
                    nums[t1 / (int)pow(10, i) % 10]++;
                }
                return;
            }
        }
        for(int i = 0; i < 3; i++) {
            if(nums[t2 / (int)pow(10, i) % 10] && t2 / (int)pow(10, i) % 10) nums[t2 / (int)pow(10, i) % 10]--;
            else {
                while(i--) {
                    nums[t2 / (int)pow(10, i) % 10]++;
                }
                for(int j = 2; j >= 0; j--) {
                    nums[t1 / (int)pow(10, j) % 10]++;
                }
                return;
            }
        }
        value = 1;
        cout << ans << " " << t1 << " " << t2 << endl;
        for(int i = 2; i >= 0; i--) {
            nums[t1 / (int)pow(10, i) % 10]++;
            nums[t2 / (int)pow(10, i) % 10]++;
        }
        return;
    }
    for(int i = 1; i < 10; i++) {
        if(nums[i]) {
            ans = ans * 10 + i;
            nums[i]--;
            dfs(ans);
            nums[i]++;
            ans /= 10;
        }
    }
}
int main() {
    cin >> A >> B >> C;
    if(A == 0) {
        cout << "No!!!" << endl;
        return 0;
    }
    for(int i = 0; i < 10; i++) {
        nums[i] = 1;
    }
    int ans = 0;
    dfs(ans);
    if(!value) {
        cout << "No!!!" << endl;
    }

    return 0;
}