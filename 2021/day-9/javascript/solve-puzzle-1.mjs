import { readFileSync } from 'node:fs';
import { EOL } from 'node:os';

const input = readFileSync('../input.txt', 'utf-8')
  .split(EOL)
  .map((row) => row.split('').map((n) => parseInt(n)));
const len = input.length;
const rowLen = input[0].length;

const lowPoints = [];

for (let i = 0; i < len; i++)
  for (let j = 0; j < rowLen; j++) {
    const currentRow = input[i];
    const current = currentRow[j];
    const aboveCurrent = current + 1;
    const up = input[i - 1]?.[j] ?? aboveCurrent;
    const down = input[i + 1]?.[j] ?? aboveCurrent;
    const left = currentRow[j - 1] ?? aboveCurrent;
    const right = currentRow[j + 1] ?? aboveCurrent;

    if (up > current && down > current && left > current && right > current)
      lowPoints.push(current);
  }

let riskLevel = 0;

for (const lowPoint of lowPoints) riskLevel += lowPoint + 1;

console.log(riskLevel);
