'''
Поиск компонент связности: дан граф, надо найти компоненты связности

Запускаем ДФС от любой вершины, заводим массив visited, если есть какая-то непройденная вершина -- опять запускаем дфс.
'''

def DFS(graph: dict, visited: list, start_top: int):
    for top in graph[start_top]:
        if top not in visited:
            visited.append(top)
            DFS(graph, visited, top)
    return

def main():
    N = int(input()) # количество вершин в графе
    graph = {} # храним граф в виде списка связности
    # вводим список связности
    for i in range(1, N+1):
        graph[i] = list(map(int, input().split(" ")))

    count = 0 # счетчик компонент связности
    visited = [] # массив посещенных вершин
    top_set = set(graph.keys())
    while set(graph.keys()) != set(visited):
        visited_set = set(visited)
        not_visited = top_set^visited_set
        DFS(graph, visited, list(not_visited)[0])
        count+=1
    
    print(count)

if __name__ == '__main__':
    main()