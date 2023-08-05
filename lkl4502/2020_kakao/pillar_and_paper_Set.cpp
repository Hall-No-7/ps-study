// By Hongs
#include <bits/stdc++.h>
#define endl "\n"
#define fast_io                                                                \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);
using namespace std;

set<tuple<int, int, int>> building;

bool cmp(tuple<int, int, int> &t1, tuple<int, int, int> &t2) {
    if (get<0>(t1) == get<0>(t2)) {
        if (get<1>(t1) == get<1>(t2)) {
            return get<2>(t1) < get<2>(t2);
        } else
            return get<1>(t1) < get<1>(t2);
    } else
        return get<0>(t1) < get<0>(t2);
}

bool InstallItem(int col, int row, int type) {
    if (type == 0) {  // 기둥
        if (row == 0) // 바닥 설치
            return true;
        if (building.find(make_tuple(col - 1, row, 1)) != building.end() ||
            building.find(make_tuple(col, row, 1)) !=
                building.end()) // 보의 한 쪽 끝에 위치
            return true;
        if (building.find(make_tuple(col, row - 1, type)) != building.end())
            return true;
    } else { // 보
        if (building.find(make_tuple(col, row - 1, 0)) != building.end() ||
            building.find(make_tuple(col + 1, row - 1, 0)) !=
                building.end()) // 한 쪽 부분이 기둥에 있는가
            return true;
        if (building.find(make_tuple(col - 1, row, type)) != building.end() &&
            building.find(make_tuple(col + 1, row, type)) !=
                building.end()) // 양 쪽 모두 보와 연결
            return true;
    }
    return false;
}

bool CheckDelete(int col, int row, int type) {
    building.erase(make_tuple(col, row, type));
    for (auto &it : building)
        if (!InstallItem(get<0>(it), get<1>(it), get<2>(it)))
            return false;
    return true;
}

int main() {
    fast_io;
    vector<vector<int>> build_frame = {{1, 0, 0, 1}, {1, 1, 1, 1}, {2, 1, 0, 1},
                                       {2, 2, 1, 1}, {5, 0, 0, 1}, {5, 1, 0, 1},
                                       {4, 2, 1, 1}, {3, 2, 1, 1}};

    for (auto &it : build_frame) {
        int x = it[0], y = it[1], type = it[2];
        bool install = it[3] ? true : false;
        if (install) { // 설치
            if (InstallItem(x, y, type))
                building.insert(make_tuple(x, y, type));
        } else {
            if (CheckDelete(x, y, type))
                continue;
            building.insert(make_tuple(x, y, type));
        }
    }

    vector<vector<int>> answer;

    for (auto &it : building) {
        vector<int> v;
        v.push_back(get<0>(it));
        v.push_back(get<1>(it));
        v.push_back(get<2>(it));
        answer.push_back(v);
    }
}