# Задача 3
# Является ли граф деревом ?
# Необходимо и достаточно ,чтобы граф не имел зацикливаний и был одной компонентой связности.

def is_tree(graph):
    visited = []
    queue = ['A']
    parent = {}
    
    while queue:
        vertex = queue.pop(0)
        visited.append(vertex)
        for neighbor in graph[vertex]:
            if neighbor not in visited:
                queue.append(neighbor)
                parent[neighbor] = vertex
            else:
                if parent[vertex] != neighbor:
                    return False
                
                
    return len(visited) == len(graph)        
    

# test___________________________


graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F', 'G'],
    'D': [],
    'E': [],
    'F': [],
    'G': [], 
}


print(is_tree(graph)) #     