#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
    ListNode dummy;
    ListNode* cur = &dummy;
    while(list1 && list2){
        if(list1->val > list2->val){
            cur->next = list2;
            list2 = list2->next;
        }else{
            cur->next = list1;
            list1 = list1->next;
        }
        cur = cur->next;
    }
    cur->next = list1 ? list1 : list2;
    return dummy.next;
}

ListNode* mergeKLists(vector<ListNode*>& lists, int i, int j){
    int m = j - i;
    if(m == 0) return nullptr;
    if(m == 1) return lists[i];
    auto left = mergeKLists(lists, i, i + m / 2);
    auto right = mergeKLists(lists, i + m / 2, j);
    return mergeTwoLists(left, right);
}

int main(){
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(4);
    ListNode* head3 = new ListNode(5);
    head3->next = new ListNode(7);
    head3->next->next = new ListNode(8);
    vector<ListNode*> lists = {head1, head2, head3};
    ListNode* ans = mergeKLists(lists, 0, 3);
    while(ans){
        cout << ans->val << " ";
        ans = ans->next;
    }
    return 0;
}