def has_cycle(graph):
    visited = []

    for i in range(len(graph)):
        currentNode = graph[i]
        if currentNode not in visited:
            if dfs(graph, currentNode, None, visited):
                return True

        return False
            
    return False

def dfs(graph, v, parent, visited):
    visited.append(v) 
    for neib in graph[v]:
        if not neib == parent:
            if neib in visited or dfs(graph, neib, v, visited):
                return True

    return False





    
