#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
using namespace std;

bool isValidBrackets(string s){
    unordered_map<char, char> mp = {{')', '('}, {'}', '{'}, {']', '['}};
    stack<char> st;
    int n = s.length();
    if(n % 2 != 0) return false;
    for(char c : s){
        if(!mp.count(c)){
            st.push(c);
        }else{
            if(st.empty() || st.top() != mp[c]) return false;
            st.pop();
        }
    }
    return st.empty();
}

int main(){
    string s = "([]})";
    cout << isValidBrackets(s) << "\n";
    return 0;
}