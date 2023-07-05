#include <iostream>

int char_to_int(char c) {
    return c - '0';
}

struct TrieNode {
    TrieNode *children[10];
    bool isEndOfNumber;
};

void insert(TrieNode *root, char *phoneNumber, int idx) {
    TrieNode *current = root;
    if (phoneNumber[idx] == '\0') {
        current->isEndOfNumber = true;
        return;
    } else {
        int digit = char_to_int(phoneNumber[idx]);
        if (current->children[digit] == NULL) {
            current->children[digit] = new TrieNode();
            current->children[digit]->isEndOfNumber = false;
        }
        insert(current->children[digit], phoneNumber, idx + 1);
    }
}

bool isConsistency(TrieNode *root, int depth) {
    TrieNode *current = root;
    bool ans = true;
    for (int i = 0; i < 10; i++) {
        if (current->children[i] != NULL) {
            if (current->isEndOfNumber == true) {
                return false;
            }
            ans = isConsistency(current->children[i], depth + 1);
            if (ans == false) {
                return false;
            }
        }
    }
    return ans;
}

int main() {
    int t, n;
    char phoneNumber[11];
    std::cin >> t;
    for (int _ = 0; _ < t; _++) {
        std::cin >> n;
        TrieNode *root = new TrieNode();
        for (int i = 0; i < n; i++) {
            std::cin >> phoneNumber;
            insert(root, phoneNumber, 0);
        }
        if (isConsistency(root, 0)) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    
    
}