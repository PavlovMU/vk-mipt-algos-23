'''
Является ли граф деревом?

Не должно быть циклов и граф должен состоять из 1 компоненты связности.
1) Ищем циклы
2) Проверяем visited со списком вершин. Если они равны, то у нас одна компонента связности.

Немного проще теперь сделать BFS.
'''

def BFS(graph: dict, start_top: int):
    visited = [start_top]
    queue = [start_top]
    parent = {start_top: None}
    
    while len(queue) != 0:
        cur_top = queue[0]
        queue.pop(0)
        for top in graph[cur_top]:
            if top in visited and parent[cur_top] != top and parent[top] != None:
                return False # there is a cycle (we have some another parent for this top)
            elif top not in visited:
                visited.append(top)
                queue.append(top)
                parent[top] = cur_top

    return set(visited) == set(graph.keys())

def main():
    N = int(input()) # количество вершин в графе
    graph = {} # храним граф в виде списка связности
    # вводим список связности
    for i in range(1, N+1):
        graph[i] = list(map(int, input().split(" ")))

    if BFS(graph, list(graph.keys())[0]):
        print("Tree")
    else:
        print("Not a tree")

if __name__ == '__main__':
    main()