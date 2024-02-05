def is_tree(graph, start):
    visited = []
    queue = [start]
    parent = {start: None}

    while(queue):
        v = queue.pop()
        visited.append(v)

        for neib in graph[v]:
            if neib not in visited:
                queue.append(neib)
                parent[neib] = v

            else:
                if not parent[v] == neib:
                    return False


    return len(visited) == len(graph)


