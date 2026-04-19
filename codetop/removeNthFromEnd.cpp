#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* left = &dummy, *right = &dummy;
    while(n--) right = right->next;
    while(right->next){
        left = left->next;
        right = right->next;
    }
    ListNode* nxt = left->next;
    left->next = left->next->next;
    delete nxt;
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
    ListNode* ans = removeNthFromEnd(head, 2);
    while(ans){
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << "\n";
    return 0;
}