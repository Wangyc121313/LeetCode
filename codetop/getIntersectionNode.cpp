#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB){
    ListNode* p = headA;
    ListNode* q = headB;
    while(p != q){
        p = p ? p->next : headB;
        q = q ? q->next : headA;
    }
    return p;
}

int main(){
    ListNode* a1 = new ListNode(1);
    ListNode* a2 = new ListNode(2);
    ListNode* c1 = new ListNode(3);
    ListNode* c2 = new ListNode(4);
    ListNode* c3 = new ListNode(5);
    ListNode* b1 = new ListNode(8);
    ListNode* b2 = new ListNode(7);
    ListNode* b3 = new ListNode(6);
    a1->next = a2;
    a2->next = c1;
    c1->next = c2;
    c2->next = c3;
    b1->next = b2;
    b2->next = b3;
    b3->next = c1;
    ListNode* ans = getIntersectionNode(a1, b1);
    cout << ans->val << "\n";
    return 0;
}