'''
Раскраска графа

Для каждой компоненты связности нужно определить свой цвет.
Теперь мы не просто прохидимся по графу и записываем компоненты связности, но присваиваем каждой вершине
цвет, который соответствует компоненте связности.
'''

def DFS(graph: dict, visited: dict, start_top: int, color=1):
    for top in graph[start_top]:
        if top not in visited.keys():
            visited[top] = color
            DFS(graph, visited, top, color)
    return

def main():
    N = int(input()) # количество вершин в графе
    graph = {} # храним граф в виде списка связности
    # вводим список связности
    for i in range(1, N+1):
        graph[i] = list(map(int, input().split(" ")))

    color = 0 # current color
    visited = {} # the dictionary of посещенных вершин
    top_set = set(graph.keys())
    while set(graph.keys()) != set(visited.keys()):
        visited_set = set(visited.keys())
        not_visited = top_set^visited_set
        DFS(graph, visited, list(not_visited)[0], color)
        color+=1
    
    print(visited)

if __name__ == '__main__':
    main()