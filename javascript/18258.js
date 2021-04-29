const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let input = [];

rl.on("line", function(line) {
    input.push(line);
}).on("close", function() {
    solve();
    rl.close();
    process.exit();
});

class Queue{
    constructor() {
        this.arr = [];
        this.rear = 0;
        this.head = 0;
        this.len = 0;
    }
    push(item) {
        this.arr[this.rear] = item;
        this.rear = this.rear + 1;
        this.len = this.len + 1;
    }
    pop() {
        if (!this.empty()) {
            this.head = this.head + 1;
            this.len = this.len - 1;
            return this.arr[this.head-1];
        }
        return -1;
    }
    size() {
        return this.len;
    }
    empty() {
        return (this.len == 0) ? 1: 0;
    }
    front() {
        return (this.empty())? -1 : this.arr[this.head];
    }
    back() {
        return (this.empty())? -1 : this.arr[this.rear -1];
    }
}

function solve() {
    const queue = new Queue();
     
    var N = input[0];
    var result = "";

    for (var i=1; i<=N; i++) {
        var order = input[i].split(' ');
        
        if (order[0] == "push") {
            queue.push(order[1]);
        }
        else if (order[0] == "pop") {
            result += queue.pop() + "\n";
        }
        else if (order[0] == "size") {
            result += queue.size() + "\n";
        }
        else if (order[0] == "empty") {
            result += queue.empty() + "\n";
        }
        else if (order[0] == "front") {
            result += queue.front() + "\n";
        }
        else if (order[0] == "back") {
            result += queue.back() + "\n";
        }
    }

    console.log(result);
}