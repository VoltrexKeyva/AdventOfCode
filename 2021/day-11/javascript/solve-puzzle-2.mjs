import { readFileSync } from 'node:fs';

const input = readFileSync('../input.txt', 'utf-8').split(/\r?\n/);

const len = input.length;
const lenFull = len * len;

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

let fullSimultanenousFlashStep = 0;

do {
  octopuses.flashies = [];

  for (let i = 0; i < len; i++)
    for (let j = 0; j < len; j++) if (++octopuses.dumbos[i][j] > 9) flash(i, j);

  for (const coordinates of octopuses.flashies)
    octopuses.dumbos[coordinates.i][coordinates.j] = 0;

  fullSimultanenousFlashStep++;
} while (octopuses.flashies.length !== lenFull);

console.log(fullSimultanenousFlashStep);
