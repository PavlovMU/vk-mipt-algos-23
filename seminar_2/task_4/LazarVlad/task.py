# Найти наименьшее время распечатки N листов двумя 
# принтерами с временами печати x (мин.) и y (мин.)

def printout_time(N, x, y):
    l, r = 0, (N - 1)*max(x, y)

    while(l + 1 < r):
        middle = (l + r) // 2

        if(middle/x + middle/y < N - 1):
            l = middle
        else:
            r = middle

    return r + min(x, y)


N = 6
x = 1
y = 1

print(f"The shortest printout time is {printout_time(N, x, y)} minutes.")