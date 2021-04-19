//  2383. [모의 SW 역량테스트] 점심 식사시간
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int N;
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};

int simulation(vector<pair<int,int>> using_str1, pair<int,int> s, int stime) {
    int pos[11][11] = {0};
    for (int i=0; i<using_str1.size(); i++) {
        pos[using_str1[i].first][using_str1[i].second] = i+1;
    }

    int visit[11][11] = {0};
    queue<pair<int,int>> sq;
    queue<pair<int,int>> fq;
    fq.push(s);
    
    while(!fq.empty()) {
        int y = fq.front().first;
        int x = fq.front().second;
        fq.pop();

        int waitTime = visit[y][x];
        if (pos[y][x] > 0) {
            if (sq.size() == 3) {
                while(sq.front().second + stime > waitTime) waitTime++;
                sq.pop();
            }
            // printf("%d %d\n", pos[y][x], waitTime);
            sq.push({pos[y][x], waitTime});
        }

        for (int i=0; i<4; i++) {
            int ny = y+dy[i];
            int nx = x+dx[i];

            if (ny<0 || nx<0 || ny>=N|| nx>=N || visit[ny][nx]) continue;
            fq.push({ny, nx});
            visit[ny][nx] = visit[y][x]+1;
        }        
    }

    int maxTime = 0;
    while(!sq.empty()) {
        maxTime = max(sq.front().second + stime, maxTime);
        sq.pop();
    }
    return maxTime;
}

int main(void) {
    int T;
    scanf("%d", &T);

    for (int test_case=0; test_case<T; test_case++) {
        scanf("%d", &N);

        int min_time = 1e9;
        vector<vector<int>> room(N, vector<int>(N,0));
        vector<pair<int,int>> person_pos;
        vector<pair<int,int>> stairs_pos;
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                scanf("%d", &room[i][j]);
                if (room[i][j] == 1) person_pos.push_back({i, j});
                else if (room[i][j] > 1) stairs_pos.push_back({i, j});
            }
        }

        int psnlen = person_pos.size();
        for (int i=0; i<(1<<psnlen); i++) {
            vector<pair<int,int>> using_str1;
            vector<pair<int,int>> using_str2;

            // if (i != 60) continue;

            for (int j=0; j<psnlen; j++) {
                if (i &(1<<j)) using_str1.push_back({person_pos[j].first, person_pos[j].second});
                else using_str2.push_back({person_pos[j].first, person_pos[j].second});
            }

            int result1 = simulation(using_str1, stairs_pos[0], room[stairs_pos[0].first][stairs_pos[0].second]);
            int result2 = simulation(using_str2, stairs_pos[1], room[stairs_pos[1].first][stairs_pos[1].second]);
            int total_time = max(result1, result2);
            min_time = min(total_time, min_time);
        }

        printf("#%d %d\n", test_case+1, min_time+1);
    }
    return 0;
}