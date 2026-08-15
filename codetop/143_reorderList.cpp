/*
143.重排链表

给定一个单链表 L 的头节点 head ，单链表 L 表示为：
L0 → L1 → … → Ln - 1 → Ln
请将其重新排列后变为：
L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
*/
#include <vector>
#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* middleList(ListNode* head){
    ListNode *slow = head, *fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* reverseList(ListNode* head){
    ListNode* pre = nullptr, *cur = head;
    while(cur){
        ListNode* nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }
    return pre;
}

void reorderList(ListNode* head){
    ListNode* middle = middleList(head);
    ListNode* head2 = reverseList(middle);
    while(head2->next){
        ListNode* nxt1 = head->next;
        ListNode* nxt2 = head2->next;
        head->next = head2;
        head2->next = nxt1;
        head = nxt1;
        head2 = nxt2;
    }
}

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    reorderList(head);
    while(head){
        cout << head->val << "\n";
        head = head->next;
    }
    return 0;
}