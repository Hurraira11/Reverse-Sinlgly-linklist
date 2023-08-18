#include <iostream>
using namespace std;

struct ListNode 
{
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};


ListNode* reverseLinkedList(ListNode* head) 
{
    ListNode* prevNode = nullptr;
    ListNode* current = head;

    while (current != nullptr) 
    {
        ListNode* nextNode = current->next;
        current->next = prevNode;
        prevNode = current;
        current = nextNode;
    }

    return prevNode; // The new head of the reversed list
}

// Helper function to print the linked list
void printList(ListNode* head) 
{
    while (head != nullptr) 
    {
         cout << head->val << " ";
        head = head->next;
    }
     cout <<  endl;
}

int main() {
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

     cout << "Original list: ";
    printList(head);

    head = reverseLinkedList(head);

     cout << "Reversed list: ";
    printList(head);


    return 0;
}
