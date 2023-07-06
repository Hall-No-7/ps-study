from collections import defaultdict


def solution(cacheSize, cities):
    answer = 0
    cache = defaultdict(int)

    for idx, city in enumerate(cities, 1):
        CITY = city.upper()
        if cache[CITY] == 0:
            cache[CITY] = idx
            answer += 5
            if len(cache) == cacheSize + 1:
                cache.pop(min(cache, key=cache.get))
        else:
            answer += 1
            cache[CITY] = idx
    return answer
