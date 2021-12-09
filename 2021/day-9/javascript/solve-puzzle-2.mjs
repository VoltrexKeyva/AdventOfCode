import { readFileSync } from 'node:fs';
import { EOL } from 'node:os';

const input = readFileSync('../input.txt', 'utf-8')
  .split(EOL)
  .map((row) => row.split('').map((n) => parseInt(n)));
const len = input.length;
const rowLen = input[0].length;

function traverse(
  row,
  index,
  rowIndex,
  basinParts = [
    {
      rowIndex,
      index,
      point: row[index]
    }
  ]
) {
  const len = row.length + 1;

  for (let i = index; i > -1; i--) {
    const point = row[i];

    if (point === undefined || point === 9) break;

    if (
      basinParts.some(
        (basinPart) => basinPart.rowIndex === rowIndex && basinPart.index === i
      )
    )
      continue;

    basinParts.push({
      rowIndex,
      index: i,
      point
    });

    const previousRow = input[rowIndex - 1];

    if (previousRow !== undefined && previousRow[i] !== 9)
      traverse(previousRow, i, rowIndex - 1, basinParts);

    const nextRow = input[rowIndex + 1];

    if (nextRow !== undefined && nextRow[i] !== 9)
      traverse(nextRow, i, rowIndex + 1, basinParts);
  }

  for (let i = index + 1; i < len; i++) {
    const point = row[i];

    if (point === undefined || point === 9) break;

    if (
      basinParts.some(
        (basinPart) => basinPart.rowIndex === rowIndex && basinPart.index === i
      )
    )
      continue;

    basinParts.push({
      rowIndex,
      index: i,
      point
    });

    const previousRow = input[rowIndex - 1];

    if (previousRow !== undefined && previousRow[i] !== 9)
      traverse(previousRow, i, rowIndex - 1, basinParts);

    const nextRow = input[rowIndex + 1];

    if (nextRow !== undefined && nextRow[i] !== 9)
      traverse(nextRow, i, rowIndex + 1, basinParts);
  }

  return basinParts;
}

const basinSizes = [];

for (let i = 0; i < len; i++)
  for (let j = 0; j < rowLen; j++) {
    const currentRow = input[i];
    const current = currentRow[j];
    const aboveCurrent = current + 1;
    const up = input[i - 1]?.[j] ?? aboveCurrent;
    const down = input[i + 1]?.[j] ?? aboveCurrent;
    const left = currentRow[j - 1] ?? aboveCurrent;
    const right = currentRow[j + 1] ?? aboveCurrent;

    if (up > current && down > current && left > current && right > current) {
      const basinParts = traverse(currentRow, j, i);

      basinSizes.push(basinParts.length);
    }
  }

const largestThreeBasins = basinSizes.sort((a, b) => b - a).slice(0, 3);

console.log(
  largestThreeBasins[0] * largestThreeBasins[1] * largestThreeBasins[2]
);
