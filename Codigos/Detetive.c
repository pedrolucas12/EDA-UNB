#include <stdio.h>
#include <stdlib.h>

typedef struct road
{
    int index;
    int value;
    int nextIndex;
} road;

void insert(road *head, int index, int value, int nextIndex, int *count)
{
    head[*count].index = index;
    head[*count].value = value;
    head[*count].nextIndex = nextIndex;
    (*count)++;
}

void sort(road *head, int count)
{
    road temp[count];
    int j = 0;
    int currentIndex = head[0].index;
    while (j < count)
    {
        temp[j++] = head[currentIndex];
        int nextIndex = head[currentIndex].nextIndex;
        if (nextIndex == -1)
            break;

        int found = 0;
        for (int i = 0; i < count; i++)
        {
            if (head[i].index == nextIndex)
            {
                currentIndex = i;
                found = 1;
                break;
            }
        }

        if (!found)
        {
            printf("Error: Next index not found\n");
            return;
        }
    }

    for (int i = 0; i < count; i++)
    {
        head[i] = temp[i];
    }
}

int main()
{
    int index, value, nextIndex, n;
    int count = 0;
    road head[10000];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &index, &value, &nextIndex);
        insert(head, index, value, nextIndex, &count);
    }

    sort(head, count);

    for (int i = 0; i < count; i++)
    {
        printf("%d\n", head[i].value);
    }

    return 0;
}