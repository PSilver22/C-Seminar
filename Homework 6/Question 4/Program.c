#include <stdio.h>
#include "LinkedList.h"

int main(void)
{
    List* list = CreateList();

    for (size_t i = 0; i < 10; ++i)
    {
        PushBack(list, i);
    }

    PushFront(list, -1);
    Insert(Find(list, 7), 3);

    printf("Current list: ");
    PrintList(list);

    printf("\nSize: %u", GetListSize(list));

    printf("\nRemoved back: %d", PopBack(list));

    printf("\nRemoved front: %d", PopFront(list));

    DeleteNode(list, Find(list, 7));
    DeleteValue(list, 5);

    printf("\nList after removals: ");
    PrintList(list);

    return 0;
}