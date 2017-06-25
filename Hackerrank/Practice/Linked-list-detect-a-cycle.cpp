/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    if(head==0) return false;
    Node * rab = head;
    while(head != 0) {
        if(head->next == 0) return false;
        head = head->next->next;
        rab = rab->next;
        if(rab == head) return true;
    }
    return false;
}
