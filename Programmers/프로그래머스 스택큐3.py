def solution(progresses, speeds):
    answer = []
    day = 0
    cnt = 0
    while len(progresses) > 0:
        if (progresses[0] + day*speeds[0]) >= 100:
            progresses.pop(0)
            speeds.pop(0)
            cnt += 1
            #print(cnt)
        
        else:
            if cnt > 0:
                print(cnt)
                answer.append(cnt)
                cnt = 0
            day += 1
    answer.append(cnt)
    
    return answer

solution([93, 30, 55],[1, 30, 5])