import { createReadStream } from 'node:fs';

const input = createReadStream('../input.txt', 'utf-8');

const syntaxErrorScores = {
  ')': 3,
  ']': 57,
  '}': 1197,
  '>': 25137
};

let tokenHistory = [];

input.once('readable', () => {
  let token;
  let failed;
  let syntaxErrorHighScore = 0;

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
          else {
            syntaxErrorHighScore += syntaxErrorScores[token];

            failed = true;
          }

          continue;
      }
    }

    tokenHistory = [];
  } while (token !== null);

  console.log(syntaxErrorHighScore);
});
