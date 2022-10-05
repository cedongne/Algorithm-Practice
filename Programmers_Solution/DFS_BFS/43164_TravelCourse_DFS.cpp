#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> cityList;

bool dfs(string source, vector<vector<string>> tickets, vector<bool> use){
    vector<pair<string, int>> destList;
    
    // All ticket use test
    int useCnt = 0;
    for(auto ticket : use){
        if(ticket){
            useCnt++;
        }
    }
    if(useCnt == tickets.size()){
        return true;
    }
    
    // make destination list
    for(int index = 0; index < tickets.size(); index++){
        if((tickets[index][0] == source) && !use[index]){
            destList.push_back({tickets[index][1], index});
        }
    }
    sort(destList.begin(), destList.end());
    
    // test all destination
    for(auto dest : destList){
        if(use[dest.second]){
            continue;
        }
        use[dest.second] = true;
        cityList.push_back(dest.first);
        if(dfs(dest.first, tickets, use)){
            return true;
        }
        else{
            use[dest.second] = false;
            cityList.pop_back();
        }
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<bool> use(tickets.size(), false);
    
    cityList.push_back("ICN");
    dfs("ICN", tickets, use);
    return cityList;
}