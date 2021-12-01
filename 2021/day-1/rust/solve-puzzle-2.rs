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
    let mut prev = u32::MAX;

    for window in lines.windows(3) {
        let cur: u32 = window.iter().sum();
        if cur > prev {
            counter += 1;
        }
        prev = cur;
    }

    println!("{}", counter);
}
