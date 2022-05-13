from collections import deque

def solution(n, edge):
    answer = 0
    edge.sort()
    distance = [0] * (n+1)
    graph = [[] for i in range(n+1)]
    
    for e in edge:
        graph[e[0]].append(e[1])
        graph[e[1]].append(e[0])

    queue = deque()

    queue.append(1)
    distance[1] = 1

    while queue:
        element = queue.popleft()
        
        for i in graph[element]:
            if distance[i] == 0:
                queue.append(i) 
                distance[i] = distance[element] + 1
            
    max_ele = max(distance)
    for i in distance:
        if i == max_ele:
            answer += 1
        
    return answer
print(solution(6,[[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2]]))