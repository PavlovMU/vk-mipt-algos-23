class HashTable:
    def __init__(self):
        self.table = {}

    def contains(self, key):
        return key in self.table

    def insert(self, key, value):
        self.table[key] = value

    def get(self, key):
        return self.table.get(key)


def twoSum(data, target):
    ht = HashTable()
    for i in range(len(data)):
        if ht.contains(data[i]): # среди ключей нашей таблицы ищем data[i]
            return [i, ht.table[data[i]]]
        diff = target - data[i]
        ht.table[diff] = i
    return []


""" a = [6, 4, 3, 2, 8, 5]
target = 11
print(twoSum(a, target)) """