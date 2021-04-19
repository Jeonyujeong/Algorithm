#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

map<char, string> rule_map;

bool find_map(char flag_name) {
    for (auto it=rule_map.begin(); it!= rule_map.end(); it++) {
        if (flag_name == it->first)
            return true;
    }
    return false;
}

void rules_init(vector<string>& flag_rules) {
    for (int i=0; i<flag_rules.size(); i++) {
        string rule = flag_rules[i];
        
        int space_idx = rule.find(' ');
        string flag = rule.substr(1, space_idx-1);
        string type = rule.substr(space_idx);
        rule_map[flag[0]] = type;
    }
    
//     for (auto it=m.begin(); it!= m.end(); it++) {
//         cout << it-> first << " " << it-> second << endl;
//     }
}

bool check_rule(string command) {

    vector<string> args;
    string arg = "";
    for (int i=0; command[i]!='\0'; i++) {
        if (command[i] == ' ') {
            args.push_back(arg);
            arg = "";
        }
        else arg += command[i];
    }
        
    // for (int i=0; i<args.size(); i++) {
    //     cout << args[i] << " " ;
    // }
    
    
    for (int i=0; i<args.size()-1; i++) {
        string arg = args[i];
        
        if (arg[0] == '-') {    // flag_name 일 때
            char flag_name = arg[1];
            
            // flag_name 이 rule_map 에 없는 것 일 때
            if (!find_map(flag_name)) 
                return false;
            
            string rule_type = rule_map[flag_name];
            string next_arg = args[i+1];
            
            if (rule_type == "NULL") {
                if (next_arg[0] == '-') return false;
            }
            else if (rule_type == "NUMBER") {
                if (atoi(rule_type.c_str()) == 0) return false;
            }
            else if (rule_type == "STIRNG") {
                if (next_arg[0] == '-') return false;
            }
        }
        else 
            return false;
    }
    
    return true;
}

vector<bool> solution(string program, vector<string> flag_rules, vector<string> commands) {
    vector<bool> answer;
    
    rules_init(flag_rules);
    for (int i=0; i<commands.size(); i++) {
        int space_idx = commands[i].find(' ');
        string cmd_program = commands[i].substr(0, space_idx);  // program 만 뽑아내기
        string flag_rule = commands[i].substr(space_idx+1);     // flag_rule 만 뽑아내기
        
        if (cmd_program == program) {
            answer.push_back(check_rule(flag_rule));   
        }
        else {
            answer.push_back(false);
        }
    }
    
    
    return answer;
}
int main(void) {
    string program = "line";
    vector<string> flag_rules =  {"-s STRING", "-n NUMBER", "-e NULL"};
    vector<string> commands = {"line -n 100 -s hi -e", "lien -s Bye"};

    solution(program, flag_rules, commands);
}