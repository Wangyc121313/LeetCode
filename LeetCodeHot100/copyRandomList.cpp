#include <vector>
#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val){
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

Node* copyRandomList(Node* head){
    if(!head) return nullptr;
    //核心是在原链表的每个节点后面复制粘贴一个新节点
    //第一步，复制，不拷贝随机节点
    for(Node* cur = head; cur; cur = cur->next->next){
        Node* next = cur->next;
        cur->next = new Node(cur->val); //创建新节点
        cur->next->next = next;         //复原指向
    }
    //将新节点的random对应过去
    for(Node* cur = head; cur; cur = cur->next->next){
        if(cur->random) cur->next->random = cur->random->next;
        //默认指向nullptr，无需处理
    }
    Node dummy(0);
    Node* tail = &dummy;
    for(Node* cur = head; cur; ){
        Node* copy = cur->next;
        tail->next = copy;
        cur->next = copy->next;
        cur = cur->next;//相当于cur = cur->next->next
        tail = tail->next;
    }
    return dummy.next;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->random = head->next;
    head->next->random = head->next;
    head->next->next->random = head;
    
    Node* ans = copyRandomList(head);
    cout << ans->val << " " << ans->next->val << endl;
    cout << ans->random->val << " " << ans->next->random->val << endl;
    return 0;
}