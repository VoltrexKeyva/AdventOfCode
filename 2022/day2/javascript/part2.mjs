import { readFileSync } from 'node:fs';

const input = readFileSync('../input.txt', 'utf-8');

const rounds = input.split(/\r?\n/);

let totalScore = 0;

for (const round of rounds) {
  if (round === '') break;

  let a = round.charCodeAt(0),
    b = round.charCodeAt(2);

  a -= 'A'.charCodeAt(0);
  b -= 'X'.charCodeAt(0);

  totalScore += ((2 + b + a) % 3) + 3 * b + 1;
}

console.log(totalScore);
