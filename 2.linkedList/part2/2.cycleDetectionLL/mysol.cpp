/****************************************************************

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


*****************************************************************/
#include<set>
bool detectCycle(Node *head)
{
    set <Node*> s;

    while (head) {
        
        if (s.find(head) == s.end()) {
            s.insert(head);
            head = head -> next;
        }
        else return true;

    }
	return false;
}