#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <math.h>
#include <assert.h>

typedef long long ll;

#define DIR 1
#define FILE 2
struct _trie_node {
    int size, type;
    char* name;
    struct _list_node {
        struct _trie_node *it;
        struct _list_node *next;
    } *files, *dirs;
};
typedef struct _trie_node Trie;
typedef struct _list_node List;

Trie* root;
Trie* new(char* name, int size, int type) {
    Trie* it = (Trie*)malloc(sizeof(Trie));
    it->name = name;
    it->size = size;
    it->type = type;
    it->files = it->dirs = NULL;
    return it;
}

char* copy(char* str) {
    int n = strlen(str);
    char* r = (char*)malloc(sizeof(char)*(n+1));
    strcpy(r, str);
    return r;
}

Trie* add(Trie* cur, char* name, int size, int type) {
    Trie* it = new(name, size, type);
    List* jt = (List*)malloc(sizeof(List));
    jt->it = it;
    List** kt = NULL;
    switch(type) {
    case DIR:
        kt = &cur->dirs;
        break;
    case FILE:
        kt = &cur->files;
        break;
    default:
        assert(!"Type not exist");
    }
    jt->next = *kt;
    *kt = jt;
    return it;
}
Trie* find(Trie* cur, char* name, int a) {
    assert(cur);
    for(List* it = cur->dirs; it; it = it->next) {
        assert(it->it && it->it->name);
        if (strcmp(it->it->name,name) == 0)
            return it->it;
    }
    if (a)
        return add(cur, name, 0, DIR);
    return NULL;
}

void add_file(char* path, int size) {
    Trie* it = root;
    int i = 1, n;
    char* name;
    // printf("%s %d\n", path, size);
    while (1) {
        n = 0;
        while (path[i+n] != '/' && path[i+n] != '\0')
            n++;
        assert(n);
        char z = path[i+n] == '\0';
        path[i+n] = '\0';
        name = copy(path+i);
        // printf("%p %d %s\n", name, i, path+i);
        if (z) break;
        // printf("%s %s %d %p\n", name, path+i, n, it);
        it = find(it, name, 1);
        it->size += size;
        assert(it);
        path[i+n] = '/';
        i += n+1;
    }
    add(it, name, size, FILE);
}

int cmp(const void* pa, const void* pb) {
    const Trie* a = *(const Trie**)pa;
    const Trie* b = *(const Trie**)pb;
    return strcmp(a->name, b->name);
}

int m;
Trie* res[400];
void query(char* path) {
    Trie* cur = root;
    int i = 1, n = strlen(path);
    if (path[n-1] == '/') path[n-1] = '\0';
    while (path[1]) {
        n = 0;
        while (path[i+n] != '/' && path[i+n] != '\0')
            n++;
        assert(n);
        char z = path[i+n] == '\0';
        path[i+n] = '\0';
        cur = find(cur, path+i, 0);
        if (cur == NULL) {
            m = -1;
            return;
        }
        if (z) break;
        path[i+n] = '/';
        i += n+1;
    }
    m = 0;
    for(List* it = cur->dirs; it; it = it->next) {
        res[m++] = it->it;
        // printf("D %s %d\n", it->it->name, it->it->size);
    }
    for(List* it = cur->files; it; it = it->next) {
        res[m++] = it->it;
        // printf("F %s %d\n", it->it->name, it->it->size);
    }
    assert(m);
    qsort(res, m, sizeof(res[0]), cmp);
}

signed main() {
    root = new("", -1, 0);

    int n;
    char path[105];
    scanf("%d", &n);
    while (n--) {
        int size;
        scanf("%s%d", path, &size);
        add_file(path, size);
    }
    scanf("%d", &n);
    while (n--) {
        scanf("%s", path);
        query(path);
        if (m == -1)
            puts("invalid path");
        else
            for(int i = 0; i < m; i++) {
                Trie* t = res[i];
                // printf("%d %d %p\n", t->type-1, t->size, t->name);
                printf("%c %s %d\n", "DF"[t->type-1], t->name, t->size);
            }
        puts("");
    }

    return 0;
}
