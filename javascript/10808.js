const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on("line", function(line) {
  console.log(solve(line));
  rl.close();
}).on("close", function() {
  process.exit();
});

function solve(line) {
    var alpha = [];

    for (var i=0; i<26; i++) {
        alpha[i] = 0;
    }
    
    for (var i=0; i<line.length; i++) {
        alpha[line.charCodeAt(i)-97] += 1;
    }

    // for (var i=0; i<26; i++) {
    //     result += alpha[i] + " ";
    // }
    
    return alpha.join(' ');
}