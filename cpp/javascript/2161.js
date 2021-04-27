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
    var numarr = []
    for (var i=0; i<Number(line); i++) {
        numarr[i] = i+1;
    }

    var result = "";
    while(numarr.length > 1) {
        var sn = numarr.shift();
        result += sn + " ";
        
        var en = numarr.shift();
        numarr.push(en);
    }

    var sn = numarr.shift();
    result += sn ;
    
    return result;
}