from queue import Queue

def subseq(a, b):
    q = Queue()
    for char in a:
        q.put(char)
    for char in b:
        if q.queue[0] == char:
            q.get()
            if q.qsize() == 0:
                return True
    return False
  
def subseq_2pointers(a, b):
    i = 0
    for j in range(len(b)):
        if a[i] == b[j]:
            i += 1
            if i == len(a):
                return True
    return False
