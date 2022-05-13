
num_dict = {'zero':0, 'one': 1, 'two': 2, 'three': 3, 'four': 4, 'five': 5, 'six':6, 'seven':7, 'eight': 8, 'nine':9}

def solution(s):
    cnt = len(s)
    s += '     '
    num = ''
    i = 0
    while i < cnt:
        temp = ''
        for j in num_dict:
            if s[i:i+len(j)] == j:
                temp = str(num_dict[j])
                i += len(j)-1
                #print(i)
                break
        
        if temp == '':
            temp = s[i]
        num += temp
        i += 1
    
    answer = int(num)
    return answer
print(solution('2three45sixseven'))
