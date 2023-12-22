import heapq

def dijkstra(graph, start):
    distances = {vertex: float('inf') for vertex in graph}
    distances[start] = 0
    queue = [(0, start)]

    while queue:
        current_distance, current_vertex = heapq.heappop(queue)

        if current_distance > distances[current_vertex]:
            continue

        for neighbor, weight in graph[current_vertex].items():
            distance = current_distance + weight

            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(queue, (distance, neighbor))

    return distances


graph = {
        'A': {'B': 5, 'C': 2},
        'B': {'A': 5, 'D': 1, 'E': 4},
        'C': {'A': 2, 'D': 6},
        'D': {'B': 1, 'C': 6, 'E': 3},
        'E': {'B': 4, 'D': 3}
    }

distances = dijkstra(graph, 'A')
print(distances)