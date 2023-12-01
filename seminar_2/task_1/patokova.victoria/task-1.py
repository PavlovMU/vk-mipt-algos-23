from queue import Queue


def is_subsequence(a, b):
    q = Queue()

    for el in a:
        q.put(el)

    for el in b:
        if q.queue[0] == el:
            q.get()

            if q.qsize() == 0:
                return True

    return False


def is_subsequence_dpointers(a, b):
    i = 0

    for j in range(len(b)):
        if a[i] == b[j]:
            i += 1

            if i == len(a):
                return True

    return False