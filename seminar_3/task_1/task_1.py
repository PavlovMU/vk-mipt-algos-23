# задача 1 

def ShellSort(array):
    n = len(array)
    gap = len(array) // 2
    while gap > 0:
        
        for curr_pos in range(n):
            m_gap = curr_pos
            
            while m_gap >= gap and array[m_gap] < array[m_gap - gap]:
                array[m_gap], array[m_gap - gap] = array[m_gap - gap], array[m_gap]
                m_gap -= gap
    
        gap = gap // 2
    
    return array    
    
""" array = [6,7,5,4,3,2,9,1,2,55,6,4,78]     
print(ShellSort(array))     """