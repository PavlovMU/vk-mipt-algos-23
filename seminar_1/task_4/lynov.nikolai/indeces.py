class Solution(object):
    def indeces(self, nums, target):
        dict = {}  # Создаем словарь для хранения чисел и их индексов

        for i, num in enumerate(nums):
            temp = target - num
            # Проверяем, есть ли уже в словаре число, которое дает сумму с текущим числом
            if temp in dict:
                return [dict[temp], i]
            dict[num] = i  # Добавляем текущее число в словарь
