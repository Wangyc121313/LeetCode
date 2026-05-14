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