import { readFileSync } from 'node:fs';
import { EOL } from 'node:os';

const input = readFileSync('../input.txt', 'utf-8').split(EOL + EOL);

const winningNums = input.shift().split(',');

const boards = input.map((board) =>
  board.split(EOL).map((boardLine) => boardLine.match(/\d+/g))
);

let winningBoard;
let winningDraw;

draw: for (const winningNum of winningNums)
  for (const board of boards)
    for (const boardLine of board) {
      const index = boardLine.indexOf(winningNum);

      if (index !== -1) boardLine[index] = true;

      if (boardLine.every((n) => n === true)) {
        winningBoard = board;
        winningDraw = winningNum;
        break draw;
      }

      const len = board[0].length;

      for (let i = 0; i < len; i++)
        if (board.every((line) => line[i] === true)) {
          winningBoard = board;
          winningDraw = winningNum;
          break draw;
        }
    }

let sum = 0;

for (const boardLine of winningBoard)
  for (const n of boardLine) if (n !== true) sum += Number(n);

console.log(sum * winningDraw);
