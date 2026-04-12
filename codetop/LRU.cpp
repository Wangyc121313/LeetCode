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
            key_to_node.erase(last->key);
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