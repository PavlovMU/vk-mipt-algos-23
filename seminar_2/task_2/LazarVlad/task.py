import queue

def is_palindrome(name):
    name_len = len(name)
    que = []*name_len

    for i in range(name_len):
        que.append(name[i])

    for i in range(name_len):
        if(que[name_len - 1 - i] != name[i]):
            return False
        
    return True

name = "AABOBAA"

if(is_palindrome(name)):
    print(f"Word {name} is a palindrome.")
else:
    print(f"Word {name} isn't a palindrome")
