import { readFileSync } from 'node:fs';

const input = readFileSync('../input.txt', 'utf-8').split(/\r?\n/);

const len = input.length;

const directions = [
  [-1, -1],
  [-1, 0],
  [-1, 1],
  [0, -1],
  [0, 1],
  [1, -1],
  [1, 0],
  [1, 1]
];
const directionsLen = directions.length;

const octopuses = {
  dumbos: input.map((row) => row.split('').map((n) => parseInt(n))),
  flashies: []
};

function flash(i, j) {
  if (octopuses.flashies.some((flashed) => flashed.i === i && flashed.j === j))
    return;

  octopuses.flashies.push({ i, j });

  for (let k = 0, x, y; k < directionsLen; k++) {
    x = i + directions[k][0];
    y = j + directions[k][1];

    if (x >= 0 && y >= 0 && x < len && y < len && ++octopuses.dumbos[x][y] > 9)
      flash(x, y);
  }
}

let totalFlashes = 0;

for (let i = 0; i < 100; i++) {
  octopuses.flashies = [];

  for (let j = 0; j < len; j++)
    for (let k = 0; k < len; k++) if (++octopuses.dumbos[j][k] > 9) flash(j, k);

  for (const coordinates of octopuses.flashies)
    octopuses.dumbos[coordinates.i][coordinates.j] = 0;

  totalFlashes += octopuses.flashies.length;
}

console.log(totalFlashes);
