#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* node) : val(x), next(node) {}
};

ListNode* deleteDuplicates(ListNode* head){
    ListNode* dummy = (0, head);
    ListNode* fast = head;
    ListNode* slow = dummy;
    while(fast && fast->next){
        if(fast->val == fast->next->val){//由于是排序链表所以不需要考虑后面在出现相同元素的情况
            int x = fast->val;
            while(fast && fast->val == x){
                fast = fast->next;    
            }
            slow->next = fast;
        }else{
            fast = fast->next;
            slow = slow->next;
        }
    }
    return dummy->next;
}

int main(){
    ListNode* head = new ListNode(1);
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(1);
    ListNode* n3 = new ListNode(2);
    ListNode* n4 = new ListNode(3);
    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    ListNode* ans = deleteDuplicates(head);
    while(ans){
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << "\n";
    return 0;
}