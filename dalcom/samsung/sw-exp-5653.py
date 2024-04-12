# 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
# 아래 표준 입출력 예제 필요시 참고하세요.

# 표준 입력 예제
'''
a = int(input())                        정수형 변수 1개 입력 받는 예제
b, c = map(int, input().split())        정수형 변수 2개 입력 받는 예제
d = float(input())                      실수형 변수 1개 입력 받는 예제
e, f, g = map(float, input().split())   실수형 변수 3개 입력 받는 예제
h = input()                             문자열 변수 1개 입력 받는 예제
'''

# 표준 출력 예제
'''
a, b = 6, 3
c, d, e = 1.0, 2.5, 3.4
f = "ABC"
print(a)                                정수형 변수 1개 출력하는 예제
print(b, end = " ")                     줄바꿈 하지 않고 정수형 변수와 공백을 출력하는 예제
print(c, d, e)                          실수형 변수 3개 출력하는 예제
print(f)                                문자열 1개 출력하는 예제
'''

# import sys


'''
      아래의 구문은 input.txt 를 read only 형식으로 연 후,
      앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
      여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
      아래 구문을 이용하면 이후 입력을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.

      따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 구문을 사용하셔도 좋습니다.
      아래 구문을 사용하기 위해서는 import sys가 필요합니다.

      단, 채점을 위해 코드를 제출하실 때에는 반드시 아래 구문을 지우거나 주석 처리 하셔야 합니다.
'''
# sys.stdin = open("input.txt", "r")


from collections import deque


class Plant:
    def __init__(self, r, c, life):
        self.r = r
        self.c = c
        self.life = life
        self.wake_time = 0
        self.immutable = False
        self.active = False  # 활성 상태 인지 비활성 상태 인지
        self.spread = False  # 번식을 했는지 안 했는지
        self.die = False     # 죽은 상태 인지

    def __str__(self):
        return f"식물 ({self.r}, {self.c}) 활성: {self.active} 죽음: {self.die} 생명력: {self.life}"


def wake_plants(non_active_plants: deque):
    cnt = len(non_active_plants)
    result = []  # 활성화 상태가 될 plants

    for _ in range(cnt):
        plant = non_active_plants.popleft()
        plant.wake_time += 1
        if plant.life == plant.wake_time:
            plant.wake_time = 0
            result.append(plant)
            continue
        non_active_plants.append(plant)

    return result


def activation(active_plants: deque, non_active_plants: deque):
    cnt = len(active_plants)

    next_non_active_plants_cord = []

    for _ in range(cnt):
        plant = active_plants.popleft()
        plant.wake_time += 1
        # 번식
        if not plant.spread:
            plant.spread = True
            for d in d4:
                rr = plant.r + d[0]
                cc = plant.c + d[1]

                if board[rr][cc] is None:
                    next_non_active_plants_cord.append((rr, cc))
                    board[rr][cc] = Plant(rr, cc, plant.life)
                    continue

                if not board[rr][cc].immutable and board[rr][cc].life < plant.life:
                    board[rr][cc] = Plant(rr, cc, plant.life)
                    continue
        # 죽음
        if plant.wake_time == plant.life:
            plant.active = False
            plant.die = True
            continue

        active_plants.append(plant)

    for r, c in next_non_active_plants_cord:
        board[r][c].immutable = True
        non_active_plants.append(board[r][c])


d4 = [(-1, 0), (0, 1), (1, 0), (0, -1)]

T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    # ///////////////////////////////////////////////////////////////////////////////////
    N, M, K = map(int, input().split())

    board = [[None for _ in range(800)] for _ in range(800)]
    non_active_plants = deque()
    active_plants = deque()

    for i in range(N):
        inputs = list(map(int, input().split()))
        for j in range(M):
            if inputs[j] == 0:
                continue
            new_plant = Plant(375 + i, 375 + j, inputs[j])
            new_plant.immutable = True
            board[375+i][375+j] = new_plant
            non_active_plants.append(new_plant)

    for t in range(1, K + 1):
        next_active_plants = wake_plants(non_active_plants)
        activation(active_plants, non_active_plants)
        active_plants.extend(next_active_plants)

    print(f"#{test_case} {len(non_active_plants) + len(active_plants)}")
    # ///////////////////////////////////////////////////////////////////////////////////
