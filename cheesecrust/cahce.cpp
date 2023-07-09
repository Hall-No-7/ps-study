#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    map<string, int> m;
    
    for(int i = 0; i < cities.size(); i++){
        string city = cities[i];
        
        transform(city.begin(), city.end(), city.begin(), [](char const &c) {
                    return toupper(c);
        });

        auto value = m.find(city);

        if(value == m.end()){
            
            answer += 5;
            if(cacheSize == 0) continue;
            if(m.size() == cacheSize){
                
                auto pr = min_element(m.begin(), m.end(), [](const auto &x, const auto &y) {
                    return x.second < y.second;
                });
                
                m.erase(m.find(pr->first));
                
            }
            m[city] = i;
        }else {
            answer += 1;
            m[city] = i;
        }
    }
    
    return answer;
}
