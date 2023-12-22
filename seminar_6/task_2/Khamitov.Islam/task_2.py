# Задача 2
# Поиск зацикливаний 
def has_cycle(graph):
    visited = []
    for vertex in graph:
        if vertex not in visited:
            if dfs(graph, vertex, None, visited):
                return True
 
    return False


def dfs(graph, vertex, parent, visited):
    visited.append(vertex)
    for neighbor in graph[vertex]:
        if neighbor != parent:
            if neighbor in visited or dfs(graph, neighbor, vertex, visited):
                return True
    
    return False


# test___________________________

graph = {
    'A': ['B', 'C'],
    'B': ['C'],
    'C': ['A']
}

print(has_cycle(graph)) # True