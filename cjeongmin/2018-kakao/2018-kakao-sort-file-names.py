def parsing(files):
    tokens = []
    for file in files:
        tokens.append([])
        i = 0
        while not ('0' <= file[i] <= '9'):
            i += 1
        tokens[-1].append(file[:i])
        j = i
        while j < len(file) and '0' <= file[j] <= '9':
            j += 1
        tokens[-1].append(file[i:j])
        tokens[-1].append(file[j:])
    return tokens

def solution(files):
    answer = []
    tokens = sorted(parsing(files), key=lambda x: (x[0].lower(), int(x[1])))
    return ["".join(token) for token in tokens]
