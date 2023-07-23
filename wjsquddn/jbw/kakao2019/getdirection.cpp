#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Tree {
    int idx;
    int x;
    int y;
    Tree* left;
    Tree* right;
};
bool compare(Tree A, Tree B) {
    if (A.y >= B.y) {
        if (A.y == B.y) {
            if (A.x < B.y) {
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}
void makebin(Tree* root, Tree* child) {
    if (root->x > child->x) {
        if (root->left == NULL) {
            root->left = child;
            return;
        }
        makebin(root->left, child);
    } else {
        if (root->right == NULL) {
            root->right = child;
            return;
        }
        makebin(root->right, child);
    }
}
void preorder(Tree* root, vector<int>& answer) {
    if (root == NULL) return;
    answer.push_back(root->idx);
    preorder(root->left, answer);
    preorder(root->right, answer);
}
void postorder(Tree* root, vector<int>& answer) {
    if (root == NULL) return;
    postorder(root->left, answer);
    postorder(root->right, answer);
    answer.push_back(root->idx);
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<Tree> T;
    for (int i = 0; i < nodeinfo.size(); i++) {
        int x = nodeinfo[i][0];
        int y = nodeinfo[i][1];
        int idx = i + 1;
        T.push_back({idx, x, y, NULL, NULL});
    }
    sort(T.begin(), T.end(), compare);
    Tree* root = &T[0];
    for (int i = 1; i < T.size(); i++) {
        makebin(root, &T[i]);
    }
    vector<int> pre;
    vector<int> post;
    preorder(root, pre);
    postorder(root, post);
    answer.push_back(pre);
    answer.push_back(post);
    return answer;
}

int main() {
    vector<vector<int>> strVector = {{5, 3}, {11, 5}, {13, 3}, {3, 5}, {6, 1}, {1, 3}, {8, 6}, {7, 2}, {2, 2}};
    vector<vector<int>> Vector = solution(strVector);
    for (const auto& row : Vector) {
        for (const auto& element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}