#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Amount {
	int collect = 0;    // 0:沒湊出 1:有湊出 此價錢
	int item[20];       // 存湊出此價錢的是哪一個硬幣
	int item_size = 0;  // item陣列大小
};

Amount sum[10000];
int ans[20];
int coins[20];      //有哪些硬幣
int coins_count = 0;    //幾個硬幣

void traverse(int target)
{
	if (target == 0)
	{
		for (int i = 0; i < coins_count; i++)
			(ans[i] ? printf("O") : printf("X")); //印出答案。但題目要求排序，所以要改成儲存答案>排序>再印出

		printf("\n");
		return;
	}

	for (int i = 0; i < sum[target].item_size; i++)  //遍歷item
	{
		int c = sum[target].item[i];
		if (ans[c] == 1)             //第c個硬幣已拿過，此路不通，跳過。
			continue;
		ans[c] = 1;
		traverse(target - coins[c]);
		ans[c] = 0;                 //路徑遍歷結束，復原ans陣列，進行下個嘗試。
	}
	return;
}

int main()
{
	int T, target;
	scanf_s("%d", T);

	while (T--)      //執行T次
	{
		//讀測資、ans歸零、設定sum陣列初值...
		for (int i = 0; i < 20; i++)
			ans[i] = 0;
		for (int i = 0; i < 10000; i++)
		{
			sum[i].collect = 0;
			sum[i].item_size = 0;
		}
		sum[0].collect = 1;

		scanf_s("%d", target);

		int temp;
		coins_count = 0;
		while (scanf_s("%d", temp) && temp)
			coins[coins_count++] = temp;

		for (int c = 0; c < coins_count; c++)    //第0~最後一個硬幣
		{
			for (int i = target; i >= 0; i--)    //掃sum
			{
				if (sum[i].collect == 1)                     //若能湊出i，
				{
					sum[i + coins[c]].collect = 1;             //則 i+coin[c] 也能湊出
					sum[i + coins[c]].item[sum[i + coins[c]].item_size++] = c;   //紀錄這步使用第幾個硬幣，size再加1
				}
			}
		}

		if (sum[target].collect == 0)    //無解
			printf("no solution\n");
		else
		{
			traverse(target);
			printf("finish\n");
		}
	}

	return 0;
}
