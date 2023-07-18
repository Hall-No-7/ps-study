#include <bits/stdc++.h>
#define endl "\n"
#define fast_io                                                                \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);
using namespace std;

struct Node {
    int number, x, y;
    Node *left, *right;
};

vector<vector<int>> answer(2);

Node *makeNode(int &num, int &x, int &y) {
    Node *node = new Node();
    if (!node)
        return NULL;
    node->number = num;
    node->x = x;
    node->y = y;
    node->left = node->right = NULL;
    return node;
}

Node *insertNode(Node *root, int &num, int &x, int &y) {
    if (root == NULL) {
        return makeNode(num, x, y);
    }

    if (x < root->x) // x가 root->x보다 작은 경우(왼쪾)
        root->left = insertNode(root->left, num, x, y);
    else // x가 root->x보다 큰 경우(오른쪽), 같은 경우는 없다.
        root->right = insertNode(root->right, num, x, y);

    return root;
}

void preOrder(Node *root) { // root, left, right;
    if (root == NULL)
        return;

    cout << root->number << " ";
    answer[0].push_back(root->number);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root) { // left, right, root
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->number << " ";
    answer[1].push_back(root->number);
}

int main() {
    fast_io;
    // x값이 비교할 value이고, y는 깊이
    // y가 가장 높은 node가 root로 주어진다.
    vector<vector<int>> nodeinfo = {{5, 3}, {11, 5}, {13, 3}, {3, 5}, {6, 1},
                                    {1, 3}, {8, 6},  {7, 2},  {2, 2}};
    for (int i = 0; i < nodeinfo.size(); i++)
        nodeinfo[i].push_back(i + 1); // 노드 번호를 추가

    sort(nodeinfo.begin(), nodeinfo.end(),
         [](const vector<int> &v1, const vector<int> &v2) {
             return v1[1] > v2[1];
         }); // y값 기준으로 내림 차순 정렬

    Node *root = makeNode(nodeinfo[0][2], nodeinfo[0][0], nodeinfo[0][1]);

    for (int i = 1; i < nodeinfo.size(); i++)
        root = insertNode(root, nodeinfo[i][2], nodeinfo[i][0], nodeinfo[i][1]);

    preOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;

    for (int i = 0; i < answer[0].size(); i++)
        cout << answer[0][i] << " ";
    cout << endl;

    for (int i = 0; i < answer[1].size(); i++)
        cout << answer[1][i] << " ";
    cout << endl;
}