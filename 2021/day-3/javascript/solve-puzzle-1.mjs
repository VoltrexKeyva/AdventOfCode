import { readFileSync } from 'node:fs';
import { EOL } from 'node:os';

const input = readFileSync('../input.txt', 'utf-8').split(EOL);
const lineLen = input[0].length;

let gammaRate = '';
let epsilonRate = '';

for (let i = 0, _0 = 0, _1 = 0; i < lineLen; i++) {
  for (const binaryReport of input)
    if (binaryReport[i] === '0') _0++;
    else _1++;

  gammaRate += _0 > _1 ? '0' : '1';

  _0 = 0;
  _1 = 0;
}

epsilonRate = parseInt(
  gammaRate
    .split('')
    .map((digit) => (1 - digit).toString())
    .join(''),
  2
);
gammaRate = parseInt(gammaRate, 2);

console.log(gammaRate * epsilonRate);
