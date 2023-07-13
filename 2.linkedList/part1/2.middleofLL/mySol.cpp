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

Node *findMiddle(Node *head) {
    
    Node * temp = head;
    int cnt = 0;

    while (temp) {
        temp = temp -> next;
        cnt++;
    }

    cnt = cnt/2 + 1 ;

    temp = head;

    for (int i=1; i<cnt; i++) {
        temp = temp -> next;
    }

    return temp;
}

