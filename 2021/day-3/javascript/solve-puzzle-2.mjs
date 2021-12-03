import { readFileSync } from 'node:fs';
import { EOL } from 'node:os';

const input = readFileSync('../input.txt', 'utf-8').split(EOL);
const lineLen = input[0].length;

let oxygenGeneratorRating = null;
let c02ScrubberRating = null;

{
  let matchingMost = [...input];

  for (let i = 0, _0 = 0, _1 = 0; i < lineLen; i++) {
    for (const binaryReport of matchingMost)
      if (binaryReport[i] === '0') _0++;
      else _1++;

    let mostCommonBit = _0 > _1 ? '0' : '1';

    if (_0 === _1) mostCommonBit = '1';

    if (matchingMost.length !== 1)
      matchingMost = matchingMost.filter(
        (binaryReport) => binaryReport[i] === mostCommonBit
      );

    _0 = 0;
    _1 = 0;
  }

  matchingMost = matchingMost[0];
  oxygenGeneratorRating = parseInt(matchingMost, 2);

  let matchingLeast = [...input];

  for (let i = 0, _0 = 0, _1 = 0; i < lineLen; i++) {
    for (const binaryReport of matchingLeast)
      if (binaryReport[i] === '0') _0++;
      else _1++;

    let mostCommonBit = _0 > _1 ? '0' : '1';

    if (_0 === _1) mostCommonBit = '1';

    if (matchingLeast.length !== 1)
      matchingLeast = matchingLeast.filter(
        (binaryReport) => binaryReport[i] !== mostCommonBit
      );

    _0 = 0;
    _1 = 0;
  }

  matchingLeast = matchingLeast[0];
  c02ScrubberRating = parseInt(matchingLeast, 2);
}

console.log(oxygenGeneratorRating * c02ScrubberRating);
