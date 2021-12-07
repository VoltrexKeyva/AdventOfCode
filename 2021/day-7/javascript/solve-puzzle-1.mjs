import { readFileSync } from 'node:fs';

const input = readFileSync('../input.txt', 'utf-8')
  .split(',')
  .map((n) => parseInt(n));
const len = input.length;

const highestPosition = Math.max(...input);

let leastFuelUsage = Infinity;

for (let i = 0; i < highestPosition; i++) {
  let fuelUsage = 0;

  for (let j = 0; j < len; j++) {
    let position = input[j];

    if (position > i)
      while (position !== i) {
        fuelUsage++;
        position--;
      }
    else
      while (position !== i) {
        fuelUsage++;
        position++;
      }
  }

  if (leastFuelUsage > fuelUsage) leastFuelUsage = fuelUsage;
}

console.log(leastFuelUsage);
