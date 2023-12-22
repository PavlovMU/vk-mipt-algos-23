class HashTable:
    def __init__(self):
        self.table = {}

    def contains(self, key):
        return key in self.table

    def insert(self, key, value):
        self.table[key] = value

    def get(self, key):
        return self.table.get(key)


def ExtraLetter(a, b):
    
    hash_table = HashTable()

    for char in a:
        if hash_table.contains(char):
            hash_table.insert(char, hash_table.get(char) + 1)
        else:
            hash_table.insert(char, 1)    

    for char in b:
        if hash_table.contains(char):
            hash_table.insert(char, hash_table.get(char) - 1)
        else:
            hash_table.insert(char, -1)

    diff_char = None
    for char, count in hash_table.table.items():
        if count == 1 or count == -1:
            if diff_char is not None:
                return None
            diff_char = char

    return diff_char


a = 'abcderf'
b = 'abtcdref'
print(ExtraLetter(a, b))
