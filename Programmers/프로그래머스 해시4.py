def solution(genres, plays):
    answer = []
    num = []
    for i in range(len(genres)):
        num.append(i)
    match = list(zip(genres, plays, num))
    match.sort()
    match.reverse()

    rank_dict = {}
    for mat in match:
        if mat[0] not in rank_dict:
            rank_dict[mat[0]] = mat[1]
        else:
            rank_dict[mat[0]] += mat[1]
    rank_dict = sorted(rank_dict.items(), key=lambda x: x[1], reverse=True)

    for rank in rank_dict:
        for mat in range(len(match)):
            if match[mat][0] == rank[0]:
                answer.append(match[mat][2])
                answer.append(match[mat+1][2])
                i += 1
                break

    return answer

print(solution(["classic", "pop", "classic", "classic", "pop"], [500, 600, 150, 800, 2500]))