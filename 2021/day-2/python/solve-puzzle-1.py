with open("../input.txt", "r") as handle:
    horizontal_position = 0
    depth = 0

    for instruction in handle.read().splitlines():
        instruction_line = instruction.split(" ")
        arg = int(instruction_line[1])

        instruction_line = instruction_line[0]

        if instruction_line == "forward":
            horizontal_position += arg
        elif instruction_line == "up":
            depth -= arg
        elif instruction_line == "down":
            depth += arg

    print(horizontal_position * depth)
