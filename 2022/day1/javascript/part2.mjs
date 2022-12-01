import { readFileSync } from 'node:fs';

const input = readFileSync('../input.txt', 'utf-8');

const calorieGroups = input.split(/(?:\r?\n){2}/);

const mostCaloriesTop3 = calorieGroups
  .map((calories) =>
    calories
      .split(/\r?\n/)
      .reduce((total, calorie) => total + parseInt(calorie), 0)
  )
  .sort((a, b) => b - a)
  .slice(0, 3)
  .reduce((all, calorie) => all + calorie, 0);

console.log(mostCaloriesTop3);
