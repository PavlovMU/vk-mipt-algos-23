'''
Поиск циклов в графе.

Можно решать через DFS, можно решать через BFS.
Алгоритм: нужно внутри dfs отслеживать родительские узлы. Можем передавать родительскую вершину в аргументах функции.
'''

def DFS(graph: dict, visited: list, start_top: int, parent: int):
    for top in graph[start_top]:

        if top != parent and top in visited:
            return True # нашли цикл
        
        if top not in visited:
            visited.append(top)
            DFS(graph, visited, top, top)
    
    return False # если не нашли цикл

def main():
    N = int(input()) # количество вершин в графе
    graph = {} # храним граф в виде списка связности
    # вводим список связности
    for i in range(1, N+1):
        graph[i] = list(map(int, input().split(" ")))

    visited = [] # массив посещенных вершин
    top_set = set(graph.keys())
    cycle_in_graph = False

    while set(graph.keys()) != set(visited):
        visited_set = set(visited)
        not_visited = top_set^visited_set
        if DFS(graph, visited, list(not_visited)[0], list(not_visited)[0]):
            cycle_in_graph = True
            break

    if cycle_in_graph:
        print("Cycle in graph")
    else:
        print("There are no cycles in graph")

if __name__ == '__main__':
    main()