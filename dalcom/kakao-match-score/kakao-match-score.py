import re


def solution(word, pages):
    answer = 20

    meta_tag_parser = re.compile("<meta(.+?)/>")
    a_tag_parser = re.compile("<a(.+?)>")
    url_parser = re.compile('"https://(.+?)"')

    data = dict()

    for idx, page in enumerate(pages):
        html = page.lower()

        my_url = ""
        meta_data = meta_tag_parser.findall(html)
        for md in meta_data:
            url = url_parser.search(md).group()
            if url:
                my_url = url

        base_score = re.sub("[^a-z]+", " ", html).split().count(word.lower())

        a_tags = a_tag_parser.findall(html)
        link_cnt = len(a_tags)

        for a_tag in a_tags:
            link = url_parser.search(a_tag).group()
            if data.get(link):
                data[link] = (data[link][0], data[link][1] + base_score / link_cnt)
            else:
                data[link] = (-1, base_score / link_cnt)

        if data.get(my_url):
            data[my_url] = (idx, data[my_url][1] + base_score)
        else:
            data[my_url] = (idx, base_score)

    max_score = -1
    for key, val in data.items():
        print(key, val)
        if val[0] == -1:
            continue
        if max_score > val[1]:
            continue
        elif max_score == val[1]:
            answer = min(answer, val[0])
        else:
            answer = val[0]
        max_score = val[1]

    return answer
