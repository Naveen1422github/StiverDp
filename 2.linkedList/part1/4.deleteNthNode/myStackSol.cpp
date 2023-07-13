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
    stack<Node*> s;

    Node* temp = head;

    while(temp){
        s.push(temp);
        temp = temp -> next;
    }

    for (int i = 0; i < K; i++) {
        temp = s.top();
        s.pop();
    }

    s.top() -> next = temp -> next;

    return head;
}
