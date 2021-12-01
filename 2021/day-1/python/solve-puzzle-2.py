with open('../input.txt', 'r') as handle:
    text = handle.read().splitlines()
    times_increased = 0
    nums = []
    i = 0
    first = True
    previous_sum = None
    size = len(text)
    
    while i < size:
        if first:
            first = False
            nums.extend([ int(text[i]), int(text[i + 1]), int(text[i + 2]) ])
            previous_sum = nums[0] + nums[1] + nums[2]
            i += 1
            continue
        
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