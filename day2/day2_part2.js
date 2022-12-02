const readline = require('readline');
const fs = require('fs');

const file = readline.createInterface({
    input: fs.createReadStream('input_day2.txt'),
    output: process.stdout,
    terminal: false
});

let total_points = 0;
file.on('line', line => {
    let moves = line.split(' ');
    switch (moves[0]) {
        case 'A':
            switch (moves[1]) {
                case 'X':
                    total_points += 3;
                    break;
                case 'Y':
                    total_points += 4;
                    break;
                case 'Z':
                    total_points += 8;
                    break;
            }
            break;
        case 'B':
            switch (moves[1]) {
                case 'X':
                    total_points += 1;
                    break;
                case 'Y':
                    total_points += 5;
                    break;
                case 'Z':
                    total_points += 9;
                    break;
            }
            break;
        case 'C':
            switch (moves[1]) {
                case 'X':
                    total_points += 2;
                    break;
                case 'Y':
                    total_points += 6;
                    break;
                case 'Z':
                    total_points += 7;
                    break;
            }
            break;
    }
    console.log(total_points);
})

