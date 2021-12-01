import { readFileSync } from 'node:fs';

const input: string[] = readFileSync('../input.txt', 'utf-8').split('\n');
const len: number = input.length;
const nums: number[] = [];

let timesIncreased: number = 0;

for (
  let i: number = 0, first: boolean = true, previousSum: number | null = null;
  i < len;
  i++
) {
  if (first) {
    first = false;

    nums.push(Number(input[i]), Number(input[i + 1]), Number(input[i + 2]));

    previousSum = nums[0] + nums[1] + nums[2];
    continue;
  }

  nums.push(Number(input[i + 2]));

  const currentSum: number = nums[i] + nums[i + 1] + nums[i + 2];

  if (currentSum > previousSum) timesIncreased++;

  previousSum = currentSum;
}

console.log(timesIncreased);
