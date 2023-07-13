#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    LinkedListNode<int> *temp = head;
    LinkedListNode<int> *temp1 = head;

    if (head == NULL || head->next == NULL) {
        return head;
    }

    head = head->next;
    temp -> next = NULL;

    while (head -> next != NULL) {
        temp1 = head;
        head = head -> next;
        temp1 -> next = temp;
        temp = temp1;

    }

    head -> next = temp1;

    return head;
    
}