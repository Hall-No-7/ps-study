import re
from collections import defaultdict


def get_link_score(links, relationships):
    ret = 0
    for link in links:
        ret += relationships[link]["base"] / relationships[link]["out_link"]
    return ret


def solution(word, pages):
    answer = 0
    
    urls = []
    relationships = defaultdict(lambda: { "base": 0, "out_link": 0, "links": set() })
    
    word = word.lower()
    pages = map(lambda x: x.lower(), pages)
    for page in pages:
        url_pattern = '<meta property="og:url" content="(https://\S+[.]\S+)"/>'
        url = re.search(url_pattern, page).group(1)
        urls.append(url)

        cnt = re.findall("[a-z]+", page).count(word)
        relationships[url]["base"] += cnt
        
        link_pattern = '<a href="(https://\S+[.]\S+)">'
        for link in re.findall(link_pattern, page):
            relationships[link]["links"].add(url)
            relationships[url]["out_link"] += 1
    
    return sorted(map(
        lambda x: (x[0], relationships[x[1]]["base"] + get_link_score(
            relationships[x[1]]["links"], relationships
        )),
        enumerate(urls)
    ), key=lambda x: -x[1])[0][0]
