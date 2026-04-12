#include <unordered_map>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

unordered_map<char, char> mp = {{')', '('}, {']', '['}, {'}', '{'}};

bool isValid(string s){
    if(s.length() % 2) return false;
    stack<char> st;
    for(char c : s){
        if(!mp.count(c)) st.push(c);//遇到左括号就入堆
        else{
            if(st.empty() || st.top() != mp[c]) return false;
            st.pop();
        }
    }
    return st.empty();
}

int main(){
    string s = "()[](){}({})";
    cout << isValid(s) << "\n";
    return 0;
}