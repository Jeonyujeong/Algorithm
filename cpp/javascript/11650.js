const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let input = []

rl.on("line", function(line) {
    input.push(line)    // input 배열에 한 줄씩 저장
}).on("close", function() {
    solve();    // 함수 호출
    rl.close(); // EOF 이면 더이상 읽을 것 없으므로 종료, terminal 에서는 ctrl+c 사용
    process.exit();
});

function solve() {
    var n = input[0];
    var posArr = [];

    for (var i=1; i<=Number(n); i++) {
        var pos = input[i].split(' ');
        posArr[i] = pos;
    }

    posArr.sort(function(a, b){
        if (a[0] != b[0]) return a[0] - b[0];
        else return a[1] - b[1];
    });

    var result = "";
    posArr.forEach(function(item){
        result += item[0] + " " + item[1] + "\n";
    });
    console.log(result);

    return;
}