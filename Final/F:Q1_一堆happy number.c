#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <math.h>

typedef long long ll;

int next(int n) {
    int r = 0;
    while (n) {
        int k = n%10;
        r += k*k;
        n /= 10;
    }
    return r;
}
int check(int n) {
    int a = n, b = n;
    do {
        a = next(a);
        a = next(a);
        b = next(b);
        // printf("%d %d\n", a, b);
    } while (a != b);
    return a == 1;
}

signed main() { 
    int ans = 0, n;
    while (scanf("%d", &n) != EOF)
        if (check(n))
            ans++;
    printf("%d\n", ans);

    return 0;
}
