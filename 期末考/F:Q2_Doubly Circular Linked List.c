#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <math.h>

typedef long long ll;

struct __node {
    int v;
    struct __node *fd, *bk;
};
typedef struct __node node_t;

signed main() {
    node_t *head = (node_t*)malloc(sizeof(node_t));
    head->v = 1;
    head->fd = head->bk = head;

    int t;
    scanf("%d", &t);
    while (t--) {
        char c, z;
        do c = getchar(); while (c == '\r' || c == '\n' || c == ' ');
        do z = getchar(); while (z != '\n' && z != ',');
        switch(c) {
        case 'W':
            printf("%d\n", head->v);
            break;
        case 'I': {
            node_t* it = (node_t*)malloc(sizeof(node_t));
            scanf("%d", &it->v);
            it->fd = head->fd;
            it->bk = head;
            head->fd->bk = it;
            head->fd = it;
            break;
        }
        case 'L':
            head = head->bk;
            break;
        case 'R':
            head = head->fd;
            break;
        case 'D': {
            node_t *it = head;
            node_t *bk = head->bk, *fd = head->fd;
            bk->fd = fd;
            fd->bk = bk;
            free(it);
            head = fd;
            break;
        }
        }
    }

    return 0;
}
