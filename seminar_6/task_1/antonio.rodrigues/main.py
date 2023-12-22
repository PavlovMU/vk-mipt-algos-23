def find_compnented_components(graph):
    visited = dict()

    for i in range(len(graph)):
        visited[i] = False

    connected_components = []

    for i in range(len(graph)):
        currentNode = graph[i]
        if visited[currentNode] is False:
            component = []
            dfs(graph, currentNode, visited, component)
            connected_components.append(component)
            

    return connected_components

def dfs(graph, v, visited, component):
    visited[v] = True
    component.append(v)

    for i in graph[v]:
        if visited[i] is False:
            dfs(graph, i, visited, component)

    
