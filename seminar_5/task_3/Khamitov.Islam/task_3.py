# Задача 3
# Нарисовать треугольник Паскаля 

def pascal_triangle(rows):
    dp = []
    
    for i in range(rows):
        row = [1]
        
        if i > 0:
            prev_row = dp[i - 1]
            for j in range(1, i):
                row.append(prev_row[j-1] + prev_row[j])
            row.append(1)

        dp.append(row)
    return dp

# example
pascal_triangle = pascal_triangle(6)
for row in pascal_triangle:
    print(row)