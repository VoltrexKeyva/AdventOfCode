import { readFileSync } from 'node:fs';

const input: string[] = readFileSync('../input.txt', 'utf-8').split('\n');
const len: number = input.length;

let timesIncreased: number = 0;

for (
  let i: number = 0, first: boolean = true, previous: number | null = null;
  i < len;
  i++
) {
  if (first) {
    first = false;
    previous = Number(input[i]);
    continue;
  }

  const num: number = Number(input[i]);

  if (num > previous) timesIncreased++;

  previous = num;
}

console.log(timesIncreased);
