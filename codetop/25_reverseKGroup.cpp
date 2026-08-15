/*
25.K个一组反转链表

给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
*/
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
        //以{1,2,3,4,5}为例，第一次内循环结束，pre=3,cur=4,p0->next仍然指向1
        ListNode* next = p0->next;  // 保存1
        p0->next->next = cur;       // 1指向4
        p0->next = pre;             // dummy指向3
        p0 = next;                  // 更新p0为1
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