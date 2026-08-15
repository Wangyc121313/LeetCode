/*
20.有效的括号

给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。
*/
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