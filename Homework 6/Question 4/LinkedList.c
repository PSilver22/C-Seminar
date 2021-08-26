#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

List* CreateList(void)
{
    List* result = malloc(sizeof(List));
    result->head = NULL;

    return result;
}

void FreeList(List* list)
{
    if (list)
    {
        Node* currentNode = list->head;

        while (currentNode != NULL)
        {
            Node* nextNode = currentNode->nextLink;
            free(currentNode);
            currentNode = nextNode;
        }

        free(list);
    }
}

size_t GetListSize(List* list)
{
    size_t result = 0;

    if (list)
    {
        size_t size = 0;

        Node* currentNode = list->head;
        while (currentNode != NULL)
        {
            ++size;

            currentNode = currentNode->nextLink;
        }

        result = size;
    }

    return result;
}

Node* GetListHead(List* list)
{
    Node* result = NULL;

    if (list)
    {
        result = list->head;
    }

    return result;
}

Node* GetNextNode(Node* currentNode)
{
    Node* result = NULL;

    if (currentNode)
    {
        result = currentNode->nextLink;
    }

    return result;
}

ListDataType GetValue(Node* node)
{
    ListDataType result = -1;

    if (node)
    {
        result = node->data;
    }

    return result;
}

Node* Insert(Node* after, ListDataType newValue)
{
    Node* result = NULL;

    if (after)
    {
        Node* insertNode = malloc(sizeof(Node));
        insertNode->data = newValue;
        insertNode->nextLink = after->nextLink;

        after->nextLink = insertNode;

        result = insertNode;
    }

    return result;
}

Node* PushFront(List* list, ListDataType newValue)
{
    Node* result = NULL;

    if (list)
    {
        Node* insertNode = malloc(sizeof(Node));
        insertNode->data = newValue;
        insertNode->nextLink = list->head;

        list->head = insertNode;

        result = insertNode;
    }

    return result;
}

Node* PushBack(List* list, ListDataType newValue)
{
    Node* result = NULL;

    if (list)
    {
        Node* prevNode = NULL;
        Node* currentNode = list->head;

        while (currentNode != NULL)
        {
            prevNode = currentNode;
            currentNode = currentNode->nextLink;
        }

        Node* insertNode = malloc(sizeof(Node));
        insertNode->data = newValue;
        insertNode->nextLink = NULL;

        result = insertNode;

        if (!prevNode && !currentNode)
        {
            list->head = insertNode;
        }

        else
        {
            prevNode->nextLink = insertNode;
        }
    }

    return result;
}

ListDataType PopFront(List* list)
{
    ListDataType result = 0;

    if (list)
    {
        if (list->head)
        {
            result = list->head->data;

            Node* nodeToDelete = list->head;
            list->head = list->head->nextLink;
            free(nodeToDelete);
        }
    }

    return result;
}

ListDataType PopBack(List* list)
{
    ListDataType result = 0;

    if (list)
    {
        if (list->head)
        {
            Node* prevNode = NULL;
            Node* currentNode = list->head;

            while (currentNode->nextLink != NULL)
            {
                prevNode = currentNode;
                currentNode = currentNode->nextLink;
            }

            if (prevNode && currentNode)
            {
                result = currentNode->data;

                free(currentNode);
                prevNode->nextLink = NULL;
            }
        }
    }

    return result;
}

void DeleteNode(List* list, Node* target)
{
    if (list && target)
    {
        Node* prevNode = NULL;
        Node* currentNode = list->head;

        while (currentNode != NULL && currentNode != target)
        {
            prevNode = currentNode;
            currentNode = currentNode->nextLink;
        }

        if (!currentNode || !prevNode)
        {
            return;
        }

        prevNode->nextLink = currentNode->nextLink;
        free(currentNode);
    }
}

Node* DeleteValue(List* list, ListDataType value)
{
    Node* result = NULL;

    if (list)
    {
        Node* prevNode = NULL;
        Node* currentNode = list->head;

        while (currentNode != NULL && currentNode->data != value)
        {
            prevNode = currentNode;
            currentNode = currentNode->nextLink;
        }

        if (currentNode && prevNode)
        {
            prevNode->nextLink = currentNode->nextLink;
            result = currentNode;
            free(currentNode);
        }
    }

    return result;
}

Node* Find(List* list, ListDataType value)
{
    Node* result = NULL;

    if (list)
    {
        Node* currentNode = list->head;
        while (currentNode != NULL && currentNode->data != value)
        {
            currentNode = currentNode->nextLink;
        }

        result = currentNode;
    }

    return result;
}

void PrintList(List* list)
{
    if (list)
    {
        Node* currentNode = list->head;

        while (currentNode != NULL)
        {
            printf("%d ", currentNode->data);

            currentNode = currentNode->nextLink;
        }
    }
}