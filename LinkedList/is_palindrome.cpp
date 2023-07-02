/* logic:

Create a struct for the LL
create a function that takes the head of a LL as input and reverses it
Create a function that takes head of LL as input and checks if it is Palindrome:
    find the middle of the given LL using slow and fast pointers (FP 
    traverses twice as fast so by the time it reaches the end of the LL, 
    the SP reaches middle ele) 
    Reverse the 2nd half of the LL
    Check ele by ele if the 1st half and 2nd half are identical
Main function to create LL and call isPalindrome() function
    
*/


#include <iostream>

//single LL definition
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode (int x, ListNode* next) : val(x), next(next) {}
};

//Function to reverse LL
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;

    while (curr != nullptr){
        ListNode* nextNode = curr->next;
        curr->next=prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

//Function to check if a LL is palindrome
bool isPalindrome(ListNode* head){
    
    //empty LL
    if(head == nullptr || head->next == nullptr){
        return true;
    }

    //Find the middle of the LL using slow and fast pointers
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast->next != nullptr && fast->next->next != nullptr){
        slow = slow -> next;
        fast = fast -> next -> next;
    }    

    //Reverse the second half of the LL
    ListNode* secondHalf = reverseList(slow->next);
    ListNode* firstHalf = head;

    //Compare the values of the first half and reversed second half
    while(secondhalf != nullptr){
        if(firstHalf->val != secondHalf->val){
            return false;
        }
        firstHalf = firstHalf -> next;
        secondHalf = secondHalf -> next;
    }

    return true;
}

int main(){
    //create a sample LL
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = nullptr;

    //call the isPalindrome function and print the result
    bool result = isPalindrome(head);
    std::cout << "Is the linked list a palindrome?" << (result ? "true" : "false") << std::endl;

    //clean up memory
    delete head->next;
    delete head;

    reutrn 0;
}

































