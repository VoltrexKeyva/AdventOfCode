import { readFileSync } from 'node:fs';

const input = readFileSync('../input.txt', 'utf-8').split('\n');

let horizontalPosition = 0;
let depth = 0;
let aim = 0;

for (const instruction of input) {
  const instructionLine = instruction.split(' ');
  const arg = Number(instructionLine[1]);

  switch (instructionLine[0]) {
    case 'forward':
      horizontalPosition += arg;
      depth += aim * arg;
      break;
    case 'up':
      aim -= arg;
      break;
    case 'down':
      aim += arg;
  }
}

console.log(horizontalPosition * depth);
