class Stek:
    def __init__(self):
        self.data = []

    def push_el(self, element):
        self.data.append(element)

    def peek(self):
        return self.data[-1]

    def pop_el(self):
        self.data.pop(-1)

    def get_size(self):
        return len(self.data)


a = input()
stek = Stek()
for i in a:
    stek.push_el(i)

for i in a:
    if stek.peek() != i:
        print('False')
        break
    stek.pop_el()
else:
    print('True')

