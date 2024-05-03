#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dat
{
    int sumSiz;
    int idx;
    int dSiz;
    int fSiz;
    char name[105];
    int nextd[105];
}F;

F fPos[50005];
int cnt = 0;

void init()
{
    F rootPos; //建立一個新的dat然後把所有東西都初始化成0
    rootPos.sumSiz = 0;
    rootPos.idx = 0;
    rootPos.dSiz = 0;
    rootPos.fSiz = 0;
    fPos[0] = rootPos; //這行在幹嘛
}

int check(int pos, char *str, int strl)
{
    for(int i=0 ; i<fPos[pos].dSiz ; i++)
    {
        F nxt = fPos[fPos[pos].nextd[i]];
        if(strcmp(nxt.name,str) == 0)
            return nxt.idx;
    }
    cnt++;
    fPos[pos].nextd[fPos[pos].dSiz] = cnt;
    fPos[pos].dSiz++;
    fPos[cnt].dSiz = fPos[cnt].fSiz = fPos[cnt].sumSiz = 0;
    fPos[cnt].idx = cnt;

    for(int i=0 ; i<strl ; i++)
        fPos[cnt].name[i] = str[i];
    return cnt;
}

int checkII(int pos, char *str, int strl)
{
    for(int i=0 ; i<fPos[pos].dSiz ; i++)
    {
        F nxt = fPos[fPos[pos].nextd[i]];
        if(strcmp(nxt.name,str) == 0)
            return nxt.idx;
    }
    return -1;
}

int main()
{
    init();
    int n;
    scanf("%d",&n);
    char str[105]; //一行最多100個字元
    int siz;
    while(n--)
    {
        int curPos = 0;
        scanf("%s",&str); //資料夾名稱跟檔案格式
        int sl = strlen(str); //算那行有幾個字元
        for(int i=sl-2 ; i>=0 ; i--) //從後面往前跑 [啊為毛要扣掉2]
            if(str[i] == '/') //如果遇到'/'就把字串切掉 改成'\0' ['\0'是什麼東東]
            {
                str[i] = '\0';
                break;
            }
        char *pch = strtok(str,"/"); //str中被用'/'符號分隔
        while(pch != NULL)
        {
            sl = strlen(pch); //算那個檔案夾名稱有多少字元
            curPos = check(curPos,pch,sl); // [第一次的pch是什麼]
            pch = strtok(NULL, "/"); 
        }
        scanf("%d",&siz); //檔案大小
        fPos[curPos].fSiz++;
        fPos[curPos].sumSiz += siz;
    }
    scanf("%d",&n); //題目所求
    while(n--) //跑n次
    {
        int curPos = 0; //用來檢查檔案是否存在的變數
        scanf("%s",&str);
        char *pch = strtok(str,"/");
        while(pch != NULL)
        {
            int sl = strlen(pch); //算那個檔案夾名稱有多少字元
            curPos = checkII(curPos,pch,sl);
            if(curPos == -1) //檔案不存在
                break;
            pch = strtok(NULL, "/");
        }
        if(curPos != -1)
            printf("%d %d %d\n",fPos[curPos].dSiz,fPos[curPos].fSiz,fPos[curPos].sumSiz);
        else
            printf("invalid path\n");
    }
}