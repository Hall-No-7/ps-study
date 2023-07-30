from sys import stdin as input

input = open("/Volumes/Program/ps-study/dalcom/6549/input.txt", "rt")


def solutions(arr):
    answer = 0

    st = []
    for i in range(len(arr)):
        while len(st) and arr[st[-1]] > arr[i]:
            height = arr[st[-1]]
            st.pop()
            width = i - st[-1] - 1 if len(st) else i
            answer = max(answer, height * width)
        st.append(i)

    while len(st):
        height = arr[st[-1]]
        st.pop()
        width = len(arr) - st[-1] - 1 if len(st) else len(arr)
        answer = max(answer, height * width)

    return answer


while True:
    inputs = list(map(int, input.readline().split()))
    if inputs[0] == 0:
        break

    n, *arr = inputs
    print(solutions(arr))
