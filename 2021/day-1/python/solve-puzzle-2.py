with open('../input.txt', 'r') as handle:
    text = handle.read().splitlines()
    nums = [ int(text[0]), int(text[1]), int(text[2]) ]
    previous_sum = sum(nums)
    times_increased = 0
    limit = len(text) - 2
    i = 1
    #print(limit)
    while i < limit:
        nums.append(int(text[i + 2]))
        #print(i, end=">")
   
        current_sum = nums[i] + nums[i + 1] + nums[i + 2]
        if current_sum > previous_sum:
            #print(len(nums), end=" ")
            times_increased += 1
        
        previous_sum = current_sum
        i += 1
    #print()
    print(times_increased)