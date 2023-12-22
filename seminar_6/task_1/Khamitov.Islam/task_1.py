def find_connected_components(adj_matrix):
    n = len(adj_matrix)
    color = 0
    visited = [color] * n
    components = dict()

    def dfs(vertex, component, color):
        visited[vertex] = color
        component.append(vertex)

        for neighbor in range(n):
            if adj_matrix[vertex][neighbor] == 1 and not visited[neighbor]:
                dfs(neighbor, component, color)

    for vertex in range(n):
        if not visited[vertex]:
            color += 1
            component = []
            dfs(vertex, component, color)
            components[color] = component
            


    return components

# test________________________

matrix = [
    [1, 1, 1, 0, 0, 0, 0, 0],
    [1, 1, 1, 1, 0, 0, 0, 0],
    [1, 1, 1, 1, 0, 0, 0, 0],
    [0, 1, 1, 1, 1, 0, 0, 0],
    [0, 0, 0, 1, 1, 1, 0, 0],
    [0, 0, 0, 0, 1, 1, 0, 0],
    [0, 0, 0, 0, 0, 0, 1, 1],
    [0, 0, 0, 0, 0, 0, 1, 1]
]

components = find_connected_components(matrix)
print(components)