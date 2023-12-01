import { readFileSync } from 'node:fs';
import { EOL } from 'node:os';

const input = readFileSync('../input.txt', 'utf-8')
  .split(EOL)
  .map((line) =>
    line
      .split(' -> ')
      .map((coordinates) => coordinates.split(',').map((n) => parseInt(n)))
      .map(([x, y]) => ({ x, y }))
      .sort((a, b) => (a.x !== b.x ? a.x - b.x : a.y - b.y))
  )
  .map(([from, to]) => ({ from, to }));

const diagramDimensionX =
  Math.max(...input.map((ent) => [ent.from.x, ent.to.x]).flat()) + 1;
const diagramDimensionY =
  Math.max(...input.map((ent) => [ent.from.y, ent.to.y]).flat()) + 1;

const diagram = Array.from({ length: diagramDimensionY }, () =>
  new Array(diagramDimensionX).fill(0)
);

for (const line of input) {
  const direction =
    line.from.x !== line.to.x && line.from.y === line.to.y
      ? { x: 1, y: 0 }
      : line.from.x === line.to.x && line.from.y !== line.to.y
        ? { x: 0, y: 1 }
        : line.from.x < line.to.x && line.from.y < line.to.y
          ? { x: 1, y: 1 }
          : line.from.x < line.to.x && line.from.y > line.to.y
            ? { x: 1, y: -1 }
            : null;
  const keys = Array.from(
    Array(
      Math.max(
        Math.abs(line.from.x - line.to.x),
        Math.abs(line.from.y - line.to.y)
      ) + 1
    ).keys()
  );

  for (const index of keys)
    diagram[line.from.y + index * direction.y][
      line.from.x + index * direction.x
    ]++;
}

console.log(diagram.flat().filter((n) => n > 1).length);
