import { readFileSync } from 'node:fs';

const input = readFileSync('../input.txt', 'utf-8').split('\n');

let horizontalPosition = 0;
let depth = 0;

for (const instruction of input) {
  const instructionLine = instruction.split(' ');
  const arg = Number(instructionLine[1]);

  switch (instructionLine[0]) {
    case 'forward':
      horizontalPosition += arg;
      break;
    case 'up':
      depth -= arg;
      break;
    case 'down':
      depth += arg;
  }
}

console.log(horizontalPosition * depth);
