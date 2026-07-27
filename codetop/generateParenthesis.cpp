#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> ans;

void backtrack(int n, int l, int r, string& path){
    if(l < n){
        path.push_back('(');
        backtrack(n, l + 1, r, path);
        path.pop_back();
    }
    if(r < l){
        path.push_back(')');
        backtrack(n , l, r + 1, path);
        path.pop_back();
    }
    if(path.size() == 2 * n){
        ans.push_back(path);
        return;
    }
}

vector<string> generateParenthesis(int n){
    ans.clear();
    string path = "";
    backtrack(n, 0, 0, path);
    return ans;
}

int main(){
    vector<string> strs = generateParenthesis(3);
    for(string str : strs) cout << str << ",";
    cout << "\n";
    return 0;
}