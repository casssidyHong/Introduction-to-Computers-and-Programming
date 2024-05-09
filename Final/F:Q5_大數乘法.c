#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <math.h>
#include <assert.h>

typedef long long ll;

#define BOUND 1000000000 // ～～為什麼要這樣設～～
#define SIZE 20
struct _BigInt 
{
    int sign; //記錄數字正負
    int ary[SIZE]; // ～～它想要幹嘛～～
};
typedef struct _BigInt BigInt;

BigInt read_bigint() // 用char的形式輸入兩個大數
{
    char s[100];
    scanf("%s", s); // 換行前是第一個數字
    BigInt r; //建立一個名稱為r的BigInt（包含r.sign和r.ayr[]）
    memset(&r, 0, sizeof(BigInt)); // ～～把數字對齊到最後面？啊最前面補0 嗎 但這樣怎麼知道要到多後面才有對齊到？～～
    int i = 0, n = strlen(s); // n=數字的長度       ～～sizeof 跟 strlen 差在哪裡？🤔～～
    // if (s[i] == '-') r.sign = 1, i = 1;         ～～跟下面那個同義？～～
    if (s[i] == '-') //假設是負數的話
    {
        r.sign = 1;
        i=1; //數字從第一個開始計（第0個是負號）
    }
    int p = 1, b = 0;
    for(int j = n-1; j >= i; j--) //從最後一個跑回來
    {
        r.ary[b] += p * (s[j] - '0'); // char是用ASCII存的 啊從0開始(0是48)所以扣掉48就會變成原本的數字了
        p = p * 10; //看位數 ex.如果倒數第二位就是十位所以要*10
        if (p == BOUND) // ～～這又想幹麻了 哭😢～～
        {
            b++; 
            p = 1; //回歸個位數
        }
    }
    return r;
}
void write_bigint(BigInt r) 
{
    if (r.sign == 1) printf("-");
    int n = SIZE-1;
    while (n > 0 && r.ary[n] == 0) n--; //排除掉前面是0的數不用印出來
    printf("%d", r.ary[n--]);
    while (n >= 0)
        printf("%09d", r.ary[n--]); // ～～09d又是什麼 我要瘋了🤦‍♀️～～
    puts(""); // ～～所以您在這邊扮演了什麼重要角色🥺～～
}

BigInt mul(BigInt a, BigInt b) 
{
    BigInt r; //開另外一個R去存結果
    memset(&r, 0, sizeof(BigInt));
    r.sign = a.sign ^ b.sign; //判斷數字正負
    for(int i = 0; i < SIZE/2; i++) // ～～SIZE/2又是哪招～～
    {
        ll c = 0;
        for(int j = 0; j < SIZE/2; j++) 
        {
            c += 1ll * a.ary[i] * b.ary[j]; //第一個數的第一位乘以第二個數
            c += r.ary[i+j]; // ～～看了個心酸寂寞覺得冷～～
            r.ary[i+j] = c % BOUND;
            c = c / BOUND; // ???
        }
    }
    return r;
}

signed main() // ～～signed main() 跟 int main() 一樣？～～
{ 
    //BigInt a = read_bigint(), b = read_bigint();      ～～跟下面那個同義？～～
    BigInt a = read_bigint();
    BigInt b = read_bigint();
    BigInt r = mul(a,b);
    write_bigint(r);
    return 0;
}
