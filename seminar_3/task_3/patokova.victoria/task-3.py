def extra_letter(src_str, new_str):

    hash_map_b = { letter : 0 for letter in new_str}
    for letter in new_str:
        hash_map_b[letter] += 1

    for letter in src_str:
        hash_map_b[letter] -= 1
        
    for letter, count in hash_map_b.items():
        if count > 0:
            return letter
        
    return ""