#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
// 组合数生成器结构体，基于杨辉三角实现
struct CombinationGenerator {
    // 存储阶乘：fact[i] = i! % MOD
    vector<long long> fact;
    // 存储阶乘的逆元：inv_fact[i] = (i!)^(-1) % MOD
    vector<long long> inv_fact;
    // 最大支持的n值（组合数C(n,k)中的n）
    int maxN;

    // 构造函数：预生成阶乘和逆元数组
    CombinationGenerator(int maxN) : maxN(maxN) {
        fact.resize(maxN + 1);
        inv_fact.resize(maxN + 1);
        generateFactorials();
        generateInverseFactorials();
    }

    // 预计算阶乘数组
    void generateFactorials() {
        fact[0] = 1; // 0! = 1
        for (int i = 1; i <= maxN; ++i) {
            fact[i] = fact[i - 1] * i % MOD;
        }
    }

    // 预计算阶乘的逆元数组（基于费马小定理）
    void generateInverseFactorials() {
        // 先计算最大n的逆元，再反向递推
        inv_fact[maxN] = powMod(fact[maxN], MOD - 2);
        for (int i = maxN - 1; i >= 0; --i) {
            inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
        }
    }

    // 快速幂计算：a^b % MOD（用于求逆元）
    long long powMod(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b % 2 == 1) {
                res = res * a % MOD;
            }
            a = a * a % MOD;
            b /= 2;
        }
        return res;
    }

    // 获取组合数C(n,k)
    // 参数：n - 总元素个数；k - 选择的元素个数
    // 返回：组合数C(n,k)，若输入无效返回-1
    long long getCombination(int n, int k) {
        // 检查输入合法性
        if (n < 0 || k < 0 || k > n || n > maxN) {
            cerr << "无效的组合数参数: C(" << n << "," << k << ")" << endl;
            return -1;
        }
        // 组合数公式：C(n,k) = n! / (k! * (n-k)!) mod MOD
        // 等价于：n! * (k!)^(-1) * ((n-k)!)^(-1) mod MOD
        return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
    }

private:
    // 禁用默认构造函数
    CombinationGenerator() = delete;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b;
    cin >> a >> b;
    int m1 = a - 1;
    int m2 = b - 1;
    CombinationGenerator ret(200010);
    cout << ret.getCombination(m1 + m2, m1) << endl;
    return 0;
}


