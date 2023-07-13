#include<stack>
/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* removeKthNode(Node* head, int K)
{
    Node *temp = head;
    int cnt = 0;

    while(temp){
        temp = temp -> next;
        cnt++;
    }

    int k = cnt - K ;

    if (k==0) return head -> next;

    temp = head;
    while (k>1) {
        temp = temp -> next;
        k--;
    }
    
    temp -> next = temp -> next -> next ;

    return head;
}
