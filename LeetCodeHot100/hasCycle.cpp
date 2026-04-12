#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    if(!head) return false;
    ListNode* slow = head, *fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}

ListNode* bulidList(const vector<int>& nums){
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for(int num : nums){
        tail->next = new ListNode(num);
        tail = tail->next;
    }
    return dummy.next;
}

int main(){
    ListNode* head = bulidList({3, 2, 0, -4});
    head->next->next->next->next = head->next; // Create a cycle
    cout << (hasCycle(head) ? "true" : "false") << "\n";
    return 0;
}