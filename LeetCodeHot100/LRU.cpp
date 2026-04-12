#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

struct Node{
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int k = 0, int v = 0) : key(k), value(v) {}
};

class LRUCache{
private:
    int capacity;
    Node* dummy;
    unordered_map<int, Node*> key_to_node;

    void remove(Node* x){
        x->prev->next = x->next;
        x->next->prev = x->prev;
    }

    void push_front(Node* x){
        x->prev = dummy;
        x->next = dummy->next;
        x->prev->next = x;
        x->next->prev = x;
    }

    Node* get_node(int key){
        if(!key_to_node.count(key)) return nullptr;
        Node* node = key_to_node[key];//哈希表的访问会把这个节点提升到最近使用的位置
        remove(node);
        push_front(node);
        return node;
    }

public:
    LRUCache(int capacity): capacity(capacity), dummy(new Node()){
        dummy->next = dummy;
        dummy->prev = dummy;
    }
    int get(int key){
        Node* node = get_node(key);
        return node ? node->value : -1;
    }
    void put(int key, int value){
        Node* node = get_node(key);
        if(node){
            node->value = value;
            return;
        }
        key_to_node[key] = node = new Node(key, value);
        push_front(node);
        if(key_to_node.size() > capacity){
            Node* last = dummy->prev;
            key_to_node.erase(last->key);
            remove(last);
            delete last;
        } 
    }
};

int main(){
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;   // 返回 1
    cache.put(3, 3);                // 淘汰 2
    cout << cache.get(2) << endl;   // 返回 -1 (未找到)
    cache.put(4, 4);                // 淘汰 1
    cout << cache.get(1) << endl;   // 返回 -1 (未找到)
    cout << cache.get(3) << endl;   // 返回 3
    cout << cache.get(4) << endl;   // 返回 4
    return 0;
}