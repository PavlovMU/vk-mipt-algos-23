'''
Алгоритм Дейкстры
'''

def find_min_unviseted(visit_matrix, N):
    min_unviseted = -1
    min_length = float('inf')

    for i in range(1, N+1):
        if visit_matrix[i][0] == True:
            continue
        if visit_matrix[i][1] < min_length:
            min_length = visit_matrix[i][1]
            min_unviseted = i
    
    return min_unviseted

def process_current_top(adjacency_matrix, N, visit_matrix, current_top_idx):
    for i in range(1, N+1):
        if i == current_top_idx:
            continue
        
        if (adjacency_matrix[current_top_idx][i] == -1):
            continue

        path_to_i_top = visit_matrix[current_top_idx][1] + adjacency_matrix[current_top_idx][i]
        if path_to_i_top < visit_matrix[i][1]:
            visit_matrix[i][1] = path_to_i_top

    visit_matrix[current_top_idx][0] = True

def find_min_path(adjacency_matrix, N, start, end):
    visit_matrix = [[False, float('inf')] for _ in range(N+1)]
    visit_matrix[0][0] = True

    visit_matrix[start][0] = True
    visit_matrix[start][1] = 0
    
    current_top_idx = start

    while True:
        process_current_top(adjacency_matrix, N, visit_matrix, current_top_idx)
        min_unviseted = find_min_unviseted(visit_matrix, N)
        if (min_unviseted == -1):
            break
        else:
            current_top_idx = min_unviseted

    return visit_matrix[end][1]


def main():
    N, start, end = map(int, input().split())

    # input adjacency matrix
    adjacency_matrix = []
    for i in range(N+1):
        if (i == 0):
            adjacency_list = [0 for _ in range(N+1)]
            adjacency_matrix.append(adjacency_list)
            continue

        adjacency_list = [0] + list(map(int, input().split()))
        adjacency_matrix.append(adjacency_list)
    
    ans = find_min_path(adjacency_matrix, N, start, end)
    if ans == float('inf'):
        print(-1)
    else:
        print(ans)

    
if __name__ == '__main__':
    main()