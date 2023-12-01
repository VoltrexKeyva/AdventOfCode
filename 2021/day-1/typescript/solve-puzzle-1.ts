import { readFileSync } from 'node:fs';

const input: string[] = readFileSync('../input.txt', 'utf-8').split('\n');
const len: number = input.length;

let timesIncreased: number = 0;

for (let i: number = 1; i < len; i++)
  if (Number(input[i]) > Number(input[i - 1])) timesIncreased++;

console.log(timesIncreased);
