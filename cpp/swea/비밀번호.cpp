#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	
	// cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{   
        int N;
        string str;
        cin >> N >> str;
        
        stack<char> s;
        for (int i=0; i<N; i++) {
            if (s.empty()) {
                s.push(str[i]);
                continue;
            }

            int t = s.top();
            if (t == str[i]) s.pop();
            else s.push(str[i]);
        }

        string new_str = "";
        cout << "#" << test_case << " " ; 
        while(!s.empty()) {
            new_str += s.top();
            s.pop();
        }
        reverse(new_str.begin(), new_str.end());
        cout << new_str << "\n";
	}

	return 0;
}