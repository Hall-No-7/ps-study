import sys

input = lambda: sys.stdin.readline().strip()


class Node:
    def __init__(self) -> None:
        self.children: dict[str, Node] = {}
        self.is_word = False


class Trie:
    def __init__(self) -> None:
        self.root = Node()

    def insert(self, word: str) -> None:
        curr = self.root
        for c in word:
            if c not in curr.children:
                curr.children[c] = Node()
            curr = curr.children[c]
        curr.is_word = True

    def find(self, word: str) -> bool:
        curr = self.root
        for c in word:
            if c not in curr.children:
                return False
            curr = curr.children[c]
        return curr.is_word


def dfs(trie: Trie, board: list[list[str]]) -> tuple[int, str, int]:
    def _dfs(point: tuple[int, int], length, word):
        nonlocal found_words, score, max_length_word, count

        y, x = point
        if word not in found_words and trie.find(word):
            found_words |= {word}
            count += 1
            score += score_by_length[length]
            if len(max_length_word) <= len(word):
                max_length_word = (
                    word
                    if len(max_length_word) < len(word)
                    else min(max_length_word, word)
                )

        if length == 8:
            return

        for i in range(8):
            nx, ny = x + dx[i], y + dy[i]
            if not (0 <= nx < 4 and 0 <= ny < 4):
                continue
            if visited[ny][nx]:
                continue
            visited[ny][nx] = 1
            _dfs((ny, nx), length + 1, word + board[ny][nx])
            visited[ny][nx] = 0

    dx = [-1, -1, 0, 1, 1, 1, 0, -1]
    dy = [0, -1, -1, -1, 0, 1, 1, 1]
    visited = [[0 for _ in range(4)] for _ in range(4)]
    score_by_length = {0: 0, 1: 0, 2: 0, 3: 1, 4: 1, 5: 2, 6: 3, 7: 5, 8: 11}
    found_words: set[str] = set()
    score = 0
    max_length_word = ""
    count = 0
    for r in range(4):
        for c in range(4):
            visited[r][c] = 1
            _dfs((r, c), 1, board[r][c])
            visited[r][c] = 0
    return score, max_length_word, count


W = int(input())
trie = Trie()
for _ in range(W):
    trie.insert(input())
input()

B = int(input())
for t in range(B):
    board = [list(input()) for _ in range(4)]
    print(*dfs(trie, board), sep=" ")
    if t != B - 1:
        input()
