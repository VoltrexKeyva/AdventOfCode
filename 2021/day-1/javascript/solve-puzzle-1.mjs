import { readFileSync } from 'node:fs';

const input = readFileSync('../input.txt', 'utf-8').split('\n');
const len = input.length;

let timesIncreased = 0;

for (let i = 0, first = true, previous = null; i < len; i++) {
  if (first) {
    first = false;
    previous = Number(input[i]);
    continue;
  }

  const num = Number(input[i]);

  if (num > previous) timesIncreased++;

  previous = num;
}

console.log(timesIncreased);
