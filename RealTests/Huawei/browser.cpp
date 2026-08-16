/*
小明正在开发浏览器地址栏功能，支持四种操作:visit(访问网页)、back(返回上一页)、forward(前进到下一页)、print(输出当前地址)

初始状态：
当前页面为Blank，历史记录中只有1个Blank页面;最多保存$max_{history}$个历史记录;每次访问新页面时清空前进记录。

操作说明：
- `visit`:当前页面更新为该网页，加入历史记录;若超过$max_{history}$个历史记录，则删除最早记录;清空前进记录;网址url为小写字母、数字和点的组合，长度≤100，用例数据均为合法输入。
- `back`:若历史记录至少有两个页面，切换到上一页，原当前页面加入前进记录;否则不做操作。
- `forward`:若前进记录不为空，切换到下一页，该页面加入历史记录;否则不做操作。
- `print`:输出当前页面地址，若为Blank则输出Blank。

输入描述：
第一行整数n(操作数，$1≤n≤200$);第二行整数max_history($0<max_{history}<100$)；接下来n行操作命令。
*/
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    int max_history;
    cin >> max_history;
    deque<string> hist;
    vector<string> fwd;
    hist.push_back("Blank");
    for(int i = 0; i < n; i++){
        if(hist.size() > max_history) hist.pop_front();
        string op;
        cin >> op;
        if(op == "visit"){
            string url;
            cin >> url;
            hist.push_back(url);
            fwd.clear();
            while(hist.size() > max_history) hist.pop_front();
        }
        if(op == "back"){
            if(hist.size() >= 2){
                fwd.push_back(hist.back());
                hist.pop_back();
            }
        }
        if(op == "forward"){
            if(!fwd.empty()){
                hist.push_back(fwd.back());
                fwd.pop_back();
            }
        }
        if(op == "print"){
            if(!hist.empty()) cout << hist.back() << "\n";
            else cout << "Blank" << "\n";
        }
    }
    return 0;
}