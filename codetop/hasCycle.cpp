#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode* head){
    ListNode *slow = head, *fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}

int main(){
    ListNode* head = new ListNode(1);
    ListNode* n1 = new ListNode(2);
    ListNode* n2 = new ListNode(3);
    ListNode* n3 = new ListNode(4);
    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n1;
    cout << hasCycle(head) << "\n";
    return 0;
}