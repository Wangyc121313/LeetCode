/*
21.合并两个有序链表

将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
*/
#include <vector>
#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeTwoList(ListNode* l1, ListNode* l2){
    ListNode dummy(0);
    ListNode* ans = &dummy;
    while(l1 && l2){
        if(l1->val > l2->val){
            ans->next = l2;
            l2 = l2->next;
        }else{
            ans->next = l1;
            l1 = l1->next;
        }
        ans = ans->next;
    }
    ans->next = l1 ? l1 : l2;
    return dummy.next;
}

int main(){
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    ListNode* ans = mergeTwoList(l1, l2);
    for(ListNode* cur = ans; cur; cur = cur->next){
        cout << cur->val << " ";
    }
    return 0;
}