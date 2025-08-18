#include <bits/stdc++.h>
using namespace std;

// 大数结构，用数组存储数字的每一位，从低位到高位
struct BigInt {
    vector<int> digits;
    bool isNegative;

    // 构造函数
    BigInt(long long num = 0) {
        isNegative = false;
        if (num < 0) {
            isNegative = true;
            num = -num;
        }
        if (num == 0) {
            digits.push_back(0);
        } else {
            while (num > 0) {
                digits.push_back(num % 10);
                num /= 10;
            }
        }
    }

    BigInt(const string& s) {
        isNegative = false;
        int start = 0;
        if (s[0] == '-') {
            isNegative = true;
            start = 1;
        }
        for (int i = s.size() - 1; i >= start; --i) {
            digits.push_back(s[i] - '0');
        }
        // 移除前导零
        while (digits.size() > 1 && digits.back() == 0) {
            digits.pop_back();
        }
    }

    // 转换为字符串
    string toString() const {
        if (digits.empty()) return "0";
        string s;
        if (isNegative) s += '-';
        for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
            s += (*it) + '0';
        }
        return s;
    }

    // 加法重载
    BigInt operator+(const BigInt& other) const {
        if (isNegative != other.isNegative) {
            BigInt temp = other;
            temp.isNegative = !temp.isNegative;
            return *this - temp;
        }

        BigInt result;
        result.isNegative = isNegative;
        result.digits.clear();

        int carry = 0;
        int maxLen = max(digits.size(), other.digits.size());
        for (int i = 0; i < maxLen || carry; ++i) {
            int sum = carry;
            if (i < digits.size()) sum += digits[i];
            if (i < other.digits.size()) sum += other.digits[i];
            
            result.digits.push_back(sum % 10);
            carry = sum / 10;
        }

        return result;
    }

    // 减法重载
    BigInt operator-(const BigInt& other) const {
        if (isNegative != other.isNegative) {
            BigInt temp = other;
            temp.isNegative = !temp.isNegative;
            return *this + temp;
        }

        // 比较绝对值
        if (absCompare(other) < 0) {
            BigInt temp = other - *this;
            temp.isNegative = !temp.isNegative;
            return temp;
        }

        BigInt result;
        result.isNegative = isNegative;
        result.digits.clear();

        int borrow = 0;
        for (int i = 0; i < digits.size() || borrow; ++i) {
            int diff = digits[i] - borrow;
            if (i < other.digits.size()) diff -= other.digits[i];
            
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            
            result.digits.push_back(diff);
        }

        // 移除前导零
        while (result.digits.size() > 1 && result.digits.back() == 0) {
            result.digits.pop_back();
        }

        return result;
    }

    // 乘法重载
    BigInt operator*(const BigInt& other) const {
        BigInt result;
        result.isNegative = isNegative != other.isNegative;
        result.digits.resize(digits.size() + other.digits.size(), 0);

        for (int i = 0; i < digits.size(); ++i) {
            int carry = 0;
            for (int j = 0; j < other.digits.size() || carry; ++j) {
                long long product = result.digits[i + j] + carry;
                if (j < other.digits.size()) {
                    product += (long long)digits[i] * other.digits[j];
                }
                
                result.digits[i + j] = product % 10;
                carry = product / 10;
            }
        }

        // 移除前导零
        while (result.digits.size() > 1 && result.digits.back() == 0) {
            result.digits.pop_back();
        }

        return result;
    }

    // 除法重载（仅支持除以整数）
    BigInt operator/(int divisor) const {
        BigInt result;
        result.isNegative = isNegative != (divisor < 0);
        divisor = abs(divisor);
        
        result.digits.clear();
        long long remainder = 0;
        
        for (int i = digits.size() - 1; i >= 0; --i) {
            remainder = remainder * 10 + digits[i];
            result.digits.push_back(remainder / divisor);
            remainder %= divisor;
        }
        
        reverse(result.digits.begin(), result.digits.end());
        
        // 移除前导零
        while (result.digits.size() > 1 && result.digits.back() == 0) {
            result.digits.pop_back();
        }
        
        return result;
    }

    // 比较绝对值大小
    int absCompare(const BigInt& other) const {
        if (digits.size() != other.digits.size()) {
            return digits.size() > other.digits.size() ? 1 : -1;
        }
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] != other.digits[i]) {
                return digits[i] > other.digits[i] ? 1 : -1;
            }
        }
        return 0;
    }

    // 大于运算符重载
    bool operator>(const BigInt& other) const {
        if (isNegative != other.isNegative) {
            return !isNegative;
        }
        if (isNegative) {
            return absCompare(other) < 0;
        } else {
            return absCompare(other) > 0;
        }
    }

    // 赋值运算符重载
    BigInt& operator=(int num) {
        *this = BigInt(num);
        return *this;
    }
};

struct node{
    int l;
    int r;
    BigInt prefix;
}man[1010];

bool cmp(node x, node y) {
    return (long long)x.l * x.r < (long long)y.l * y.r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int a, b;
    cin >> n;
    cin >> a >> b;
    
    for(int i = 0; i < n; i++) {
        cin >> man[i].l >> man[i].r;
    }
    
    sort(man, man + n, cmp);
    
    man[0].prefix = a;
    BigInt ans = man[0].prefix / man[0].r;
    
    for(int i = 1; i < n; i++) {
        man[i].prefix = man[i - 1].prefix * man[i - 1].l;
        BigInt current = man[i].prefix / man[i].r;
        if (current > ans) {
            ans = current;
        }
    }
    
    cout << ans.toString() << '\n';

    return 0;
}
