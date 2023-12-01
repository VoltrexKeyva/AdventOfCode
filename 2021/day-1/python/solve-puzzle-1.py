with open("../input.txt", "r") as handle:
    text = handle.read().splitlines()
    text_len = len(text)
    times_increased = 0
    i = 1

    while i < text_len:
        if int(text[i]) > int(text[i - 1]):
            times_increased += 1

        i += 1

    print(times_increased)
