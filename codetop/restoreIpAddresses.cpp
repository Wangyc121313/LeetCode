#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
vector<string> ans;
string s;
int path[4];//每段的下标+1

void restoreIpAddresses(int i, int j, int ipVal){
    if(i == n){
        if(j == 4){
            int a = path[0], b = path[1], c = path[2];
            ans.push_back(s.substr(0, a) + '.' + s.substr(a, b - a) + '.' + s.substr(b, c - b) + '.' + s.substr(c));
        }
        return;
    }
    if(j == 4) return;
    ipVal = ipVal * 10 + (s[i] - '0');
    if(ipVal > 255) return;
    if(ipVal > 0) restoreIpAddresses(i + 1, j, ipVal);//不分割
    path[j] = i + 1;
    restoreIpAddresses(i + 1, j + 1, 0);
}

int main(){
    s = "25525511135";
    n = s.length();
    if(n >= 4 && n <= 12) restoreIpAddresses(0, 0, 0);
    for(const string& ip : ans) cout << ip << "\n";
    return 0;
}