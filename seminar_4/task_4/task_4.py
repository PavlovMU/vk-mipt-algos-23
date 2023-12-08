# 4 задача
# Найти произведения минимального и максимального элементов дерева 

def maxMinMultiplication(data):
    if len(data) == 2:
        return data[0] * data[1] 
    
    if len(data) < 2:
        return -1
    
    min_index = 1
    max_index = 2
    
    i = 1
    while i < len(data):
        min_index = i
        i = 2 * i + 1
    
    i = 1
    while i < len(data):
        max_index = i
        i = 2 * i + 2
    
    result = data[min_index] * data[max_index]
    return result

data = [8, 9, 9, 6, 1, 1, 6, 4, 4, 4, 4]
print(maxMinMultiplication(data))