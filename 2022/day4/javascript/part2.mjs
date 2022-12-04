import { readFileSync } from 'node:fs';

const input = readFileSync('../input.txt', 'utf-8');

const pairs = input.split(/\r?\n/);

let overlappingPairs = 0;

for (const pair of pairs) {
  if (pair === '') break;

  const [section1, section2] = pair
    .split(',')
    .map((section) => section.split('-').map((range) => parseInt(range)));

  if (
    (section1[0] <= section2[0] && section1[1] >= section2[0]) ||
    (section2[0] <= section1[0] && section2[1] >= section1[0])
  )
    overlappingPairs++;
}

console.log(overlappingPairs);
