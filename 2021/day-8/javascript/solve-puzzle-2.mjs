import { readFileSync } from 'node:fs';
import { EOL } from 'node:os';

const input = readFileSync('../input.txt', 'utf-8')
  .split(EOL)
  .map((row) =>
    row.split(' ').map((signalPattern) => Array.from(signalPattern).sort())
  );

let decodedDigits = 0;

for (const row of input) {
  const signalPatterns = row.slice(0, 10);
  const outputPatterns = row
    .slice(11)
    .map((outputPattern) => outputPattern.join(''));

  let digits = [];

  digits[1] = signalPatterns.find(
    (signalPattern) => signalPattern.length === 2
  );
  digits[7] = signalPatterns.find(
    (signalPattern) => signalPattern.length === 3
  );
  digits[4] = signalPatterns.find(
    (signalPattern) => signalPattern.length === 4
  );
  digits[8] = signalPatterns.find(
    (signalPattern) => signalPattern.length === 7
  );

  digits[6] = signalPatterns.find(
    (signalPattern) =>
      signalPattern.length === 6 &&
      digits[1].some((segment) => !signalPattern.includes(segment))
  );
  digits[0] = signalPatterns.find(
    (signalPattern) =>
      signalPattern.length === 6 &&
      signalPattern !== digits[6] &&
      digits[4].some((segment) => !signalPattern.includes(segment))
  );
  digits[9] = signalPatterns.find(
    (signalPattern) =>
      signalPattern.length === 6 &&
      signalPattern !== digits[6] &&
      signalPattern !== digits[0]
  );

  digits[3] = signalPatterns.find(
    (signalPattern) =>
      signalPattern.length === 5 &&
      digits[1].every((segment) => signalPattern.includes(segment))
  );
  digits[5] = signalPatterns.find(
    (signalPattern) =>
      signalPattern.length === 5 &&
      signalPattern.every((segment) => digits[6].includes(segment))
  );
  digits[2] = signalPatterns.find(
    (signalPattern) =>
      signalPattern.length === 5 &&
      signalPattern !== digits[3] &&
      signalPattern !== digits[5]
  );

  digits = digits.map((signalPattern) => signalPattern.join(''));

  decodedDigits += parseInt(
    outputPatterns
      .map((outputPattern) => digits.indexOf(outputPattern))
      .join('')
  );
}

console.log(decodedDigits);
