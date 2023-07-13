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
    Node *slow = head;
    Node *fast = head;

    while (slow -> next && fast -> next )
    {
        slow = slow -> next;

        if(fast -> next -> next) {
            fast = fast -> next ->next;
        }
        else {
            return false;
        }

        if (slow == fast) return true;
    }

    return false;
}