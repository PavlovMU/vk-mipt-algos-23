import queue

def is_subsequence(a, b):
    que = []*len(a)

    for i in range(len(a)):
        que.append(a[i])

    for i in range(len(b)):
        if(len(que) > 0 and que[0] == b[i]):
            que.pop(0)
    
    return len(que) == 0

first_string  = "ABC"
second_string = "ABCDE"

if(is_subsequence(first_string, second_string)):
    print(f'String "{second_string}" is subsequence of string "{first_string}".')
else:
    print(f'String "{second_string}" is not subsequence of string "{first_string}".')
    