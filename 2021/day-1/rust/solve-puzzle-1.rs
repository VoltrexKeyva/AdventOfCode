use std::fs::File;
use std::io::{BufRead, BufReader};
fn main() {
    let filename = "day1/input.txt";
    let file = File::open(filename).unwrap();
    let reader = BufReader::new(file);
    let lines: Vec<u32> = reader
        .lines()
        .map(|x| x.unwrap().trim().parse::<u32>().unwrap())
        .collect();
    let mut counter: u32 = 0;
    for (index, _) in lines.iter().enumerate() {
        if index == 0 {
            continue;
        }

        if lines[index] > lines[index - 1] {
            counter += 1;
        }
    }
    println!("{}", counter);
}
