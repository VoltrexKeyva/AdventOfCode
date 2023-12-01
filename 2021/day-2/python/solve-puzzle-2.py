with open("../input.txt", "r") as handle:
    horizontal_position = 0
    depth = 0
    aim = 0

    for instruction in handle.read().splitlines():
        instruction_line = instruction.split(" ")
        arg = int(instruction_line[1])
        instruction_line = instruction_line[0]

        if instruction_line == "forward":
            horizontal_position += arg
            depth += aim * arg
        elif instruction_line == "up":
            aim -= arg
        elif instruction_line == "down":
            aim += arg

    print(horizontal_position * depth)
