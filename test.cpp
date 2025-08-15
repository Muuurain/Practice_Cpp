#include<bits/stdc++.h>
using namespace std;
const int M = 2e3 + 10;
typedef struct bigint{
    vector<int> num;
    bigint(int inum = 0) : num(M) {
        string s = to_string(inum);
        int pos = s.length() - 1;
        for(auto i : s) this->num[pos--] = i - '0';
    }
    
    bigint& operator=(const bigint& y) {
            this->num = y.num;
        return *this;
    }

    bigint operator+(const bigint& x) const {
        bigint bigsum;
        int carry = 0;
        for(int i = 0; i < M; i++) {
            int sum = this->num[i] + x.num[i] + carry;
            bigsum.num[i] = sum % 10;
            carry = sum / 10;
        }
        return bigsum;
    }

    bigint operator*(const bigint& x) const {
        bigint bigmulti;
        int carry = 0;
        for(int i = 0; i < M; i++) {
            for(int j = 0; i + j < M; j++) {
                int sum = this->num[i] * x.num[j] + carry;
                bigmulti.num[i + j] += sum % 10;
                carry = sum / 10;
                carry += bigmulti.num[i + j] / 10;
                bigmulti.num[i + j] %= 10;
            }
        }
        return bigmulti;
    }
}bi;
istream& operator>>(istream& a, bigint& b) {
    string s;
    a >> s;
    int pos = s.length() - 1;;
    for(auto i : s) b.num[pos--] = i - '0';

    return a;
}
ostream& operator<<(ostream& a, const bigint& b) {
    int pos = M - 1;
    while(!b.num[pos] && pos) pos--;
    for(int i = pos; i >= 0; i--) {
        a << b.num[i];
    }

    return a;
}
int sh, sm, ss;
int main() {
    bi a, b;
    cin >> a >> b;
    bi ans = a * b;
    cout << ans << endl;

    return 0;
}



