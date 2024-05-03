#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct F{
    int value;
    F *next;
};
typedef F F;

int main()
{
    int count;
    scanf("%d, &count");

    F *head = (F*)malloc(sizeof(F));
    int something;
    scanf("%d", &something);

    head -> value = something;
    head -> next = NULL;

    F *current = head;
    for(int i=1; i<count; i++)
    {
        scanf("%d", &something);
        current -> next =(F*)malloc(sizeof(F));
        current = current -> next;
        current -> next = NULL;
    }

    current = head;
    while(1)
    {
        printf
    }
}