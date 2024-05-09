#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dat{
    int sumSiz;
    int idx;
    int dSiz;
    int fSiz;
    char name[105];
    struct WTF *nextd[105]; //指到下一個區塊
}WTF;

WTF *wtfPos[50005];
int cnt = 1;

void init(){
    WTF *rootPos = (WTF*)malloc(sizeof(WTF)); //取得記憶體空間
    rootPos->sumSiz = 0;
    rootPos->idx = 1;
    rootPos->dSiz = 0;
    rootPos->fSiz = 0;
    wtfPos[1] = rootPos;
}

int check(int pos, char *str, int strl){
    WTF *cur = wtfPos[pos];
    for(int i=0 ; i<cur->dSiz ; i++){
        WTF *nxt = cur->nextd[i];
        if(strcmp(nxt->name,str) == 0)
            return nxt->idx;
    }
    cur->nextd[cur->dSiz++] = (WTF*)malloc(sizeof(WTF));
    wtfPos[++cnt] = cur = cur->nextd[cur->dSiz-1];
    cur->sumSiz = 0 , cur->idx = cnt;
    cur->dSiz = cur->fSiz = 0;

    for(int i=0 ; i<strl ; i++)
        cur->name[i] = str[i];
    return cnt;
}

int checkII(int pos, char *str, int strl){
    WTF *cur = wtfPos[pos];
    for(int i=0 ; i<cur->dSiz ; i++){
        WTF *nxt = cur->nextd[i];
        if(strcmp(nxt->name,str) == 0)
            return nxt->idx;
    }
    return -1;
}

int main(){
    init();
    int n;
    scanf("%d",&n);
    char str[105];
    int siz;
    while(n--){
        int curPos = 1;
        scanf("%s",&str);
        int sl = strlen(str);
        for(int i=sl-2 ; i>=0 ; i--)
            if(str[i] == '/'){
                str[i] = '\0';
                break;
            }
        char *pch = strtok(str,"/");
        while(pch != NULL){
            sl = strlen(pch);
            curPos = check(curPos,pch,sl);
            pch = strtok(NULL, "/");
        }
        scanf("%d",&siz);
        wtfPos[curPos]->fSiz++;
        wtfPos[curPos]->sumSiz += siz;
    }
    scanf("%d",&n);
    while(n--){
        int curPos = 1;
        scanf("%s",&str);
        char *pch = strtok(str,"/");
        while(pch != NULL){
            int sl = strlen(pch);
            curPos = checkII(curPos,pch,sl);
            if(curPos == -1)
                break;
            pch = strtok(NULL, "/");
        }
        if(curPos != -1)
            printf("%d %d %d\n",wtfPos[curPos]->dSiz,wtfPos[curPos]->fSiz,wtfPos[curPos]->sumSiz);
        else
            printf("invalid path\n");
    }
}