import { readFileSync } from 'node:fs';

const input = readFileSync('../input.txt', 'utf-8');

const rounds = input.split(/\r?\n/);

const Shapes = {
  ROCK_OP: 'A',
  ROCK: 'X',
  PAPER_OP: 'B',
  PAPER: 'Y',
  SCISSORS_OP: 'C',
  SCISSORS: 'Z'
};

function getShapeScore(move) {
  return move === Shapes.ROCK ? 1 : move === Shapes.PAPER ? 2 : 3;
}

function getScore(move1, move2) {
  let score = getShapeScore(move2);

  if (
    (move1 === Shapes.ROCK_OP && move2 === Shapes.ROCK) ||
    (move1 === Shapes.PAPER_OP && move2 === Shapes.PAPER) ||
    (move1 === Shapes.SCISSORS_OP && move2 === Shapes.SCISSORS)
  )
    score += 3;
  else if (
    (move1 === Shapes.ROCK_OP && move2 === Shapes.PAPER) ||
    (move1 === Shapes.PAPER_OP && move2 === Shapes.SCISSORS) ||
    (move1 === Shapes.SCISSORS_OP && move2 === Shapes.ROCK)
  )
    score += 6;

  return score;
}

let totalScore = 0;

for (const round of rounds) {
  if (round === '') break;

  const [opponentMove, currentMove] = round.split(' ');

  totalScore += getScore(opponentMove, currentMove);
}

console.log(totalScore);
