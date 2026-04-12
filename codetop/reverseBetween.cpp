#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverseBetween(ListNode* head, int left, int right){
    int count = left;
    ListNode dummy(0, head);
    ListNode* p0 = &dummy;
    for(int i = 0; i < left - 1; i++){
        p0 = p0->next;
    }
    ListNode* pre = nullptr;
    ListNode* cur = p0->next;
    for(int i = 0; i < right - left + 1; i++){
        ListNode* nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }
    p0->next->next = cur;
    p0->next = pre;
    return dummy.next;
}

int main(){
    ListNode* head = new ListNode(1);
    ListNode* n1 = new ListNode(2);
    ListNode* n2 = new ListNode(3);
    ListNode* n3 = new ListNode(4);
    ListNode* n4 = new ListNode(5);
    ListNode* n5 = new ListNode(6);
    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    ListNode* ans = reverseBetween(head, 2, 4);
    for(ListNode* cur = ans; cur; cur = cur->next){
        cout << cur->val << " ";
    }
    return 0;
}