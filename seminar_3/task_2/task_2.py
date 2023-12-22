def quicksort(nums):
   if len(nums) <= 1:
       return nums
   else:
       q = nums[len(nums) // 2] 
       s_nums = [] # меньше q
       g_nums = [] # больше q
       e_nums = [] # равные q
       for n in nums:
           if n < q:
               s_nums.append(n)
           elif n > q:
               g_nums.append(n)
           else:
               e_nums.append(n)
       return quicksort(s_nums) + e_nums + quicksort(g_nums)


#задача 2 накормить животных

def feedAnimals(animals, food):
    if len(animals) == 0 or len(food) == 0:
        return 0
    quicksort(animals)
    quicksort(food)
    
    count = 0 
    for f in food:
        if f >= animals[count]:
            count += 1
        
        if count == len(animals):
            break
        
        
    return count    

animals = [2, 1, 4, 9]
food = [3, 2, 5, 7]
print(feedAnimals(animals, food))