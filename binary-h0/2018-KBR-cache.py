from collections import deque

def deleteCityInQue(city, que):
    tmp_que = deque()
    while que:
        item = que.popleft()
        if item == city:
            continue
        tmp_que.append(item)
    return tmp_que
        

def solution(cacheSize, cities):
    answer = 0
    que = deque()
    cache = set()
    for city in cities:
        city = city.lower()
        if city in cache:
            answer += 1
            que = deleteCityInQue(city, que)
            que.append(city)
            continue
        else:
            answer += 5
            if 0 <= len(que) < cacheSize:
                cache.add(city)
                que.append(city)
            else:
                if len(que) != 0:
                    item = que.popleft()
                    cache.remove(item)
                    que.append(city)
                    cache.add(city)
            
    return answer
