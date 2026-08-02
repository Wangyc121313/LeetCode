/*
请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
实现 LRUCache 类：
- LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
- int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
- void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；
  如果不存在，则向缓存中插入该组 key-value 
- 如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。
*/
#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int key;
    int value;
    Node* next;
    Node* prev;

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
        // 双向链表
        x->prev->next = x;
        x->next->prev = x;
    }

    Node* get_node(int key){
        if(!key_to_node.count(key)) return nullptr;
        Node* node = key_to_node[key];
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
            key_to_node.erase(last->key);//删除键值对
            remove(last);
            delete last;
        }
    }
};

int main(){
    LRUCache Cache(2);
    Cache.put(1, 1);
    Cache.put(2, 2);
    cout << Cache.get(1) << "\n";
    Cache.put(3, 3);
    cout << Cache.get(1) << "\n";
    cout << Cache.get(2) << "\n";//由于get1所以2作废
    Cache.put(4, 4);
    cout << Cache.get(1) << "\n";
    cout << Cache.get(3) << "\n";
    Cache.put(4, 5);
    cout << Cache.get(4) << "\n";
    return 0;
}