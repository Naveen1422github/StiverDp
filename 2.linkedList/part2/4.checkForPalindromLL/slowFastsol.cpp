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

LinkedListNode<int> reverse(LinkedListNode<int> *head, int n)
{
    LinkedListNode<int> *prev = NULL;

    while (n--) {
        LinkedListNode<int> *next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }

    head = prev;
    return next;
}

int length(LinkedListNode<int> * head) {
    int len = 0;
    LinkedListNode<int>* temp = head; 

    while (temp) {
        temp = temp -> next;
        len++;
    }

    return len;
}

bool isPalindrome(LinkedListNode<int> *head)
{
    if(head == NULL || head -> next == NULL) return true;
    int len = lenght(head);
    LinkedListNode* first = head;
    LinkedListNode* second = reverse(first, len/2);

    if(len % 2 != 0) second = second -> next;

    while (first && second) {
        if(first->data != second->data) return false;
        first = first -> next; 
        second = second -> next;
    }

    if(first || second) return false;

    return true;
}