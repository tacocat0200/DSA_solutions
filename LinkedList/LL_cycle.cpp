/* #141 - LL cycle https://leetcode.com/problems/linked-list-cycle/description/?envType=study-plan-v2&envId=top-interview-150 */

#include <iostream>

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode* head) {
    if(head == nullptr || head->next == nullptr) {
        return false;
    }

    ListNode* slow = head;
    ListNode* fast = head->next;

    while (slow != fast) {
        if(fast == nullptr || fast->next == nullptr){
            return false;
        }

        slow = slow->next;
        fast = fast -> next -> next;
    }

    return true;
}

int main() {
    //Create a linked list with a cycle (for testing)
    ListNode* head = new ListNode(3);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(0);
    ListNode* node3 = new ListNode(-4);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node1; //cycle created, tail connects to node1

    //check if the LL has a cycle
    bool result = hasCycle(head);
    std::cout << "Cycle Detected: " << (result ? "true" : "false") << std::endl;

    //Clean up memory (deallocate nodes)
    delete head;
    delete node1;
    delete node2;
    delete node3;

    return 0;
}