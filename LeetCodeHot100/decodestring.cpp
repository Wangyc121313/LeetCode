#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

string decodestring(string s){
    string res = " ";
    long long multi = 0;
    stack<int> numStack;
    stack<string> strStack;
    for(char c : s){
        if(isdigit(c)) multi = multi * 10 + (c - '0');
        else if(c == '['){
            numStack.push(multi);
            strStack.push(res);
            multi = 0;
            res = "";
        }
        else if(c == ']'){
            int k = numStack.top();
            numStack.pop();
            string last_res = strStack.top();
            strStack.pop();
            string temp = "";
            for(int i = 0; i < k; i++){
                temp += res;
            }
            res = last_res + temp;
        }
        else res += c;
    }
    return res;
}

int main(){
    string s = "3[a2[c]]";
    cout << decodestring(s) << "\n";
    return 0;
}