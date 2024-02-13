def draw_pattern(n):
    if n == 1:
        return ["*"]
    
    stars = draw_pattern(n//3)

    result = []

    for star in stars:
        result.append(star*3)
    for star in stars:
        result.append(star + " "*(n//3) + star)
    for star in stars:
        result.append(star*3)

    return result

if __name__ == "__main__":
    n = int(input())

    stars = draw_pattern(n)
    print("\n".join(stars))
