#include <iostream>
#define MOD 1000000007
using namespace std;

long long power(long long num,long long p){
    long long ret = 1;
    long long mul = num;
    mul %= MOD;
    while(p){
        if(p%2){
            ret *= mul;
            ret %= MOD;
        }
        p >>= 1;
        mul *= mul;
        mul %= MOD;
    }
    return ret;
}

int main(){
    int q;
    cin >> q;
    //greedy
    long long mul1 = power(2,q) - 1;
    long long mul2 = power(power(2,q)-2,(1ll<<(q-1))-1);
    long long ans = mul1 * mul2;
    ans %= MOD;
    cout << ans << "\n";
}
