#include <vector>
#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr){}
};

ListNode* reverseKGroup(ListNode* head, int k){
    int n = 0;
    for(ListNode* cur = head; cur; cur = cur->next) n++;
    ListNode dummy(0);
    dummy.next = head;
    ListNode* p0 = &dummy;
    ListNode* cur = head;
    ListNode* pre = nullptr;
    for(; n >= k; n -= k){
        for(int j = 0; j < k; j++){
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        ListNode* next = p0->next;//1
        p0->next->next = cur;
        p0->next = pre;
        p0 = next;
    }
    return dummy.next;
}

int main(){
    ListNode* head = new ListNode(1);
    ListNode* n1 = new ListNode(2);
    ListNode* n2 = new ListNode(3);
    ListNode* n3 = new ListNode(4);
    ListNode* n4 = new ListNode(5);
    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    head = reverseKGroup(head, 2);
    for(ListNode* cur = head; cur; cur = cur->next) cout << cur->val << "\n";
    return 0;
}