def is_palindrome(s):
    stack = list()

    for char in s:
        stack.push(char)

    for char in s:
        if char != stack.pop():
            return False

    return True


def is_palindrome_dpointers(s):
    l = 0
    r = len(s) - 1

    while l <= r:
        if s[l] != s[r]:
            return False
        l += 1
        r -= 1

    return True
