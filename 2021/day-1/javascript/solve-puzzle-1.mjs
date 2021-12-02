import { readFileSync } from 'node:fs';

const input = readFileSync('../input.txt', 'utf-8').split('\n');
const len = input.length;

let timesIncreased = 0;

for (let i = 1; i < len; i++)
  if (Number(input[i]) > Number(input[i - 1]))
	timesIncreased++;

console.log(timesIncreased);