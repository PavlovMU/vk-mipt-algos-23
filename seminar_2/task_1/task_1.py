class Queue:
    def __init__(self):
        self.items = []

    def enqueue(self, item):
        self.items.append(item)

    def dequeue(self):
        if not self.is_empty():
            return self.items.pop(0)
    
    def peek(self):
        if not self.is_empty():
            return self.items[0]

    def is_empty(self):
        return len(self.items) == 0

    def size(self):
        return len(self.items)

def is_subsequence(a, b):
    
    if not a or not b:
        return False

    subseq_queue = Queue()

    for item in a:
        subseq_queue.enqueue(item)
    
    for item in b:
        if item == subseq_queue.peek():
            subseq_queue.dequeue()
    
    
    return subseq_queue.is_empty()


a = 'abcdef'
b = 'abcdefghabcdefgh'

print(is_subsequence(a, b))
