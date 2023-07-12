def solution(cacheSize, cities):
    answer = 0
    
    cache = {}
    for idx, city in enumerate(cities):
        city = city.lower()
        if city in cache:
            cache[city] = idx
            answer += 1
        else:
            if len(cache) and len(cache) + 1 > cacheSize:
                item = sorted(cache.items(), key=lambda x: x[1])[0]
                cache.pop(item[0])
            if len(cache) + 1 <= cacheSize:
                cache[city] = idx
            answer += 5
    
    return answer
