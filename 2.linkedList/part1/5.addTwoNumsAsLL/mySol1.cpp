/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/
Node *addTwoNumbers(Node *num1, Node *num2)
{
    int power = 0;
    Node *temp;
    Node *head = num1;
    while (num1 && num2) {

        int val = num1 -> data + num2 -> data + power;

        power = val/10;
        val = val % 10;
        num1 -> data = val;

        temp = num1;

        num1 = num1 -> next;
        num2 = num2 -> next;
    }
   
    if (num2) {
        num1 = temp;
        num1 -> next = num2;
        num1 = num1->next;
    }

    while(num1) {
        int val = num1 -> data + power;

        power = val/10;
        val = val % 10;

        num1 -> data = val;
        temp = num1;
        num1 = num1 -> next;  
    }

    if(power==1) {
        temp -> next = new Node(1);
    }

    return head;
}
