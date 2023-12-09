def feed_animals(animals, food):
    animals.sort()
    food.sort()

    i = 0
    count = 0

    for i in range(len(food)):

        if food[i] >= animals[count]:
            count += 1

            if count == len(animals):
                return count

    return count