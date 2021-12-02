import { readFileSync } from 'node:fs';

const input = readFileSync('../input.txt', 'utf-8').split('\n');
const len = input.length;

let timesIncreased = 0;

for (let i = 1, previous = Number(input[0]); i < len; i++) {
  const num = Number(input[i]);

  if (num > previous) timesIncreased++;

  previous = num;
}

console.log(timesIncreased);
