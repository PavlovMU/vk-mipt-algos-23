class Queue:
    def __init__(self):
        self.data = []

    def push_el(self, element):
        self.data.append(element)

    def peek(self):
        return self.data[0]

    def pop_el(self):
        self.data.pop(0)

    def get_size(self):
        return len(self.data)

a = input()
b = input()
queue = Queue()
for i in a:
    queue.push_el(i)

for i in b:
    if queue.peek() == i:
        queue.pop_el()

if queue.get_size() == 0:
    print(f'Строка "{a}" полностью содержится в строке "{b}"')
else:
    print(f'Строка "{a}" не содержится в строке "{b}"')

