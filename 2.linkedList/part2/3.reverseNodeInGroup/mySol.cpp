#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }

        };

*****************************************************************/

void reverse (Node *head, Node* tail) {

	Node* prev = tail->next;

	while (head != tail -> next) {
        Node* next = head -> next;
        head -> next = prev;
        prev = head;
        head = next;
	}
}

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
    Node* temp = head;

    for ( int i = 0; i < n; i++) {
        Node *newHead = temp;
        int count = b[i] - 1;
        Node *tail = temp;
        while (count-- && tail->next) {
            tail = tail-> next;
        }

        if (tail -> next == NULL) break;

        reverse(newHead, tail);
        temp = temp -> next;
        
    }

    return head;
}