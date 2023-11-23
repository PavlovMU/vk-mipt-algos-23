def extra_etter(a:str, b:str):
    hash = set(a)

    res = ''
    for k in b:
        if not k in hash:
            hash.remove(k)
            res += k

    return res


