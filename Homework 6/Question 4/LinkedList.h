#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <stddef.h>

typedef int ListDataType;

/// @struct Node
/// @brief Node structure for a node in linked list
/// @var data The data stored in the node of the linked list
/// @var nextLink A pointer to the next node in the linked list
typedef struct Node_t
{
    ListDataType data;
    struct Node_t* nextLink;
} Node;

/// @struct List
/// @brief Structure for linked list
/// @var head Pointer to the first node in the list
typedef struct List_t
{
    Node* head;
} List;

/// @brief Create a pointer to a list with head pointing to NULL 
/// @return pointer to new list
List* CreateList(void);

/// @brief Frees the memory of a linked list and it's nodes
/// @param list The list to free
void FreeList(List* list);

/// @brief Gets size of a linked list
/// @param list The list to get the size of
/// @return size of list
size_t GetListSize(List* list);

/// @brief Get the head of a list
/// @param list The list to get the head of
/// @return The first node in a list
Node* GetListHead(List* list);

/// @brief gets the node after the given
/// @param currentNode 
/// @return The node after the given node
Node* GetNextNode(Node* currentNode);

/// @brief Gets the value of the given node
/// @param node 
/// @return value of node
ListDataType GetValue(Node* node);

/// @brief Inserts a node after the given node
/// @param after The node to insert after
/// @param newValue The value of the node to insert
/// @return The new node
Node* Insert(Node* after, ListDataType newValue);

/// @brief Inserts a node to the front of the linked list
/// @param list List to insert into
/// @param newValue The value of the new node
/// @return The new node
Node* PushFront(List* list, ListDataType newValue);

/// @brief Inserts a node to the back of the linked list
/// @param list List to insert into
/// @param newValue The value of the new node
/// @return The new node
Node* PushBack(List* list, ListDataType newValue);

/// @brief Removes the front of the list
/// @param list List to remove item of
/// @return The value of the node removed
ListDataType PopFront(List* list);

/// @brief Removes the back of the list
/// @param list List to remove item of
/// @return The value of the node removed
ListDataType PopBack(List* list);

/// @brief Deletes a specific node in the list
/// @param list List to remove from
/// @param target A pointer to the node to remove
void DeleteNode(List* list, Node* target);

/// @brief Delete the first node with the given value
/// @param list List to remove from
/// @param value The value of the node to remove
/// @return The node that was removed
Node* DeleteValue(List* list, ListDataType value);

/// @brief Finds the node in a list
/// @param list List to check
/// @param value The value of the node to search for
/// @return The node if found, if not found returns NULL
Node* Find(List* list, ListDataType value);

/// @brief Prints the linked list
/// @param list The list to print
void PrintList(List* list);

#endif