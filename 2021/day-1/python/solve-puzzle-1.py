with open('../input.txt', 'r') as handle:
    text = handle.read().splitlines()
    times_increased = 0
    i = 0
    text_len = len(text)
    first = True
    previous = None
    
    while i < text_len:
        if first:
            first = False
            previous = int(text[i])
            continue
        
        num = int(text[i])
        if num > previous:
            times_increased += 1

        previous = num
        i += 1
    
    print(times_increased)