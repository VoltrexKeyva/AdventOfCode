import { readFileSync } from 'node:fs';
import { EOL } from 'node:os';

const input = readFileSync('../input.txt', 'utf-8')
  .split(EOL)
  .map((row) => row.split(' | ')[1].split(' '));

const uniqueSegments = [2, 3, 4, 7];

let unqiueSymbolDigitCount = 0;

for (const digitRow of input)
  for (const fourOutputDigit of digitRow)
    if (uniqueSegments.includes(fourOutputDigit.length))
      unqiueSymbolDigitCount++;

console.log(unqiueSymbolDigitCount);
