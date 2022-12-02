import { readFileSync } from 'node:fs';

const input = readFileSync('../input.txt', 'utf-8');

const rounds = input.split(/\r?\n/);

const Shapes = {
  ROCK: 'A',
  PAPER: 'B',
  SCISSORS: 'C'
};

function getShapeScore(move) {
  return move === Shapes.ROCK ? 1 : move === Shapes.PAPER ? 2 : 3;
}

function getScore(move, outcome) {
  switch (outcome) {
    case 'X': // Lose
      return getShapeScore(
        move === Shapes.ROCK
          ? Shapes.SCISSORS
          : move === Shapes.PAPER
          ? Shapes.ROCK
          : Shapes.PAPER
      );
    case 'Y': // Draw
      return getShapeScore(move) + 3;
    case 'Z': // Win
      return (
        getShapeScore(
          move === Shapes.ROCK
            ? Shapes.PAPER
            : move === Shapes.PAPER
            ? Shapes.SCISSORS
            : Shapes.ROCK
        ) + 6
      );
    default: // Unknown
      return 0;
  }
}

let totalScore = 0;

for (const round of rounds) {
  if (round === '') break;

  const [opponentMove, currentMove] = round.split(' ');

  totalScore += getScore(opponentMove, currentMove);
}

console.log(totalScore);
