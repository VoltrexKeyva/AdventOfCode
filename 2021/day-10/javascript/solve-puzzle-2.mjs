import { createReadStream } from 'node:fs';

const input = createReadStream('../input.txt', 'utf-8');

const incompleteScores = {
  ')': 1,
  ']': 2,
  '}': 3,
  '>': 4
};

const numbers = [];
let tokenHistory = [];

input.once('readable', () => {
  let token;
  let failed;

  do {
    failed = false;

    while (
      (token = input.read(1)) !== null &&
      !(token === '\r' || token === '\n')
    ) {
      if (failed) continue;

      switch (token) {
        case '(':
          tokenHistory.push(')');
          break;
        case '[':
          tokenHistory.push(']');
          break;
        case '{':
          tokenHistory.push('}');
          break;
        case '<':
          tokenHistory.push('>');
          break;
        default:
          if (tokenHistory.at(-1) === token) tokenHistory.pop();
          else failed = true;

          continue;
      }
    }

    if (!failed && tokenHistory.length !== 0) {
      let num = 0;

      for (let i = tokenHistory.length - 1; i > -1; i--) {
        num *= 5;
        num += incompleteScores[tokenHistory[i]];
      }

      numbers.push(num);
    }

    tokenHistory = [];
  } while (token !== null);

  numbers.sort((a, b) => a - b);

  console.log(numbers[Math.floor(numbers.length * 0.5)]);
});
