import { readFileSync } from 'node:fs';

const input = readFileSync('../input.txt', 'utf-8');

const calorieGroups = input.split(/(?:\r?\n){2}/);

let mostCalories = 0;

for (const calorieGroup of calorieGroups) {
  const calories = calorieGroup
    .split(/\r?\n/)
    .reduce((total, calorie) => total + parseInt(calorie), 0);

  if (calories > mostCalories) mostCalories = calories;
}

console.log(mostCalories);
