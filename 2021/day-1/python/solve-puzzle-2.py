with open('../input.txt', 'r') as handle:
    text = handle.read().splitlines()
    nums = [ int(text[0]), int(text[1]), int(text[2]) ]
    previous_sum = sum(nums)
    times_increased = 0
    size = len(text)
    i = 1
    
    while i < size:
        try:
            nums.append(int(text[i + 2]))
        except IndexError:
            i += 1
            continue
        
        current_sum = nums[i] + nums[i + 1] + nums[i + 2]
        if current_sum > previous_sum:
            times_increased += 1
        
        previous_sum = current_sum
        i += 1
    
    print(times_increased)