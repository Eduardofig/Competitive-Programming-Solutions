use std::io;

fn solve(input: &Vec<usize>)
{
    let mut curr_arg: usize = 1;  

    for _ in 0..input[0] {
        let m: usize = input[curr_arg];
        let coins: &[usize] = &input[(curr_arg + 1)..(curr_arg + m + 1)];

        let mut dp = [[false; 50000]; 101];
        let mut sum: usize = 0;
        dp[0][0] = true;

        for i in 0..m {
            sum += coins[i];
            for j in 0..(sum + 1) {
                if dp[i][j] {
                    dp[i + 1][j + coins[i]] = true;
                    dp[i + 1][(j as i32 - coins[i] as i32).abs() as usize] = true;
                }
            }
        }

        for i in 0..(sum + 1) {
            if dp[m][i] {
                println!("{}", i);
                break;
            }
        }

        curr_arg += m + 1;
    }
}

fn main()
{
    let mut buffer = String::new();
    io::stdin().read_line(&mut buffer).unwrap();
    let buffer = buffer.trim();

    let inputs: Vec<usize> = buffer
        .split(" ").map(|x| x.parse().unwrap())
        .collect();

    solve(&inputs);
}
