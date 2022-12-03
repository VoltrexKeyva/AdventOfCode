import { readFileSync } from 'node:fs';

const input = readFileSync('../input.txt', 'utf-8');

const itemLists = input.split(/\r?\n/);

let prioritySum = 0;

const lowerAlphaAscii = 'a'.charCodeAt(0) - 1;
const upperAlphaAscii = 'A'.charCodeAt(0) - 27;

for (const itemList of itemLists) {
  const halfLen = itemList.length / 2,
    firstCompartment = itemList.slice(0, halfLen),
    secondCompartment = itemList.slice(-halfLen);

  for (let i = 0; i < firstCompartment.length; i++) {
    const item = firstCompartment[i];

    if (secondCompartment.includes(item)) {
      const asciiValue = item.charCodeAt(0);

      prioritySum +=
        asciiValue -
        (asciiValue < lowerAlphaAscii ? upperAlphaAscii : lowerAlphaAscii);
      break;
    }
  }
}

console.log(prioritySum);
