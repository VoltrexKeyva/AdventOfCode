import { readFileSync } from 'node:fs';

const input = readFileSync('../input.txt', 'utf-8')
  .split(',')
  .map((n) => parseInt(n));

let ages = new Map();

for (const n of input) ages.set(n, (ages.get(n) ?? 0) + 1);

for (let i = 0; i < 80; i++) {
  const newAges = new Map();

  for (const [key, value] of ages)
    if (key === 0) {
      newAges.set(6, (newAges.get(6) ?? 0) + value);
      newAges.set(8, (newAges.get(8) ?? 0) + value);
    } else newAges.set(key - 1, (newAges.get(key - 1) ?? 0) + value);

  ages = newAges;
}

let newFishes = 0;

for (const value of ages.values()) newFishes += value;

console.log(newFishes);
