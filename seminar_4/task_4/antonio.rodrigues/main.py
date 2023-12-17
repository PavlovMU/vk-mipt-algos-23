
def maxMinMultiplication(data):
    if len(data) < 2:
        return -1

    if len(data) == 2:
        return data[0] * data[1]

    min_index = 1
    max_index = 2
    
    i = 1
    while i < len(data):

        min_index = data[i]
        i = 2 * i + 1

    i = 2

    while i < len(data):

        max_index = data[i]
        i = 2 * i + 2

    return data[min_index] * data[max_index]

