#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <math.h>
#include <assert.h>

int compare_ints(const void* a, const void* b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;

    // return (arg1 > arg2) - (arg1 < arg2); // possible shortcut
    // return arg1 - arg2; // erroneous shortcut (fails if INT_MIN is present)
}

#define SIZE 20005
typedef long long ll;
ll v[SIZE];

signed main() { 
    ll m, n;
    scanf("%lld%lld", &m, &n);
    assert(n < SIZE); // ～～查了個寂寞～～
    for(int i = 0; i < n; i++)
        scanf("%lld", v+i);
    qsort(v, n, sizeof(ll), compare_ints);
    int i = 0;
    while (i < n) {
        // printf("%d %d\n", m, v[i]);
        if (v[i] > m) break;
        m += v[i];
        i++;
    }
    puts(i == n ? "true" : "false");
    return 0;
}
