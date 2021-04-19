#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int n, m;
    int pick_cnt[101]= {0};
    vector<int> picture;

    scanf("%d%d", &n, &m);
    for (int i=0; i<m; i++) {
        int num;
        scanf("%d", &num);

        // 4- 추천수 증가
        if (pick_cnt[num] > 0) {
            pick_cnt[num]++;
            continue;
        }

        // 3- 빈 틀이 없으면 삭제하고 새로운 학생 추가
        if (picture.size() >= n) {
            int idx = 0;
            int min_cnt = pick_cnt[picture[0]];

            for (int j=1; j<n; j++) {
                int cur = picture[j];
                if (pick_cnt[cur] < min_cnt) {
                    idx = j;
                    min_cnt = pick_cnt[cur];
                }
            }
            pick_cnt[picture[idx]] = 0;
            picture.erase(picture.begin() + idx);

            picture.push_back(num);
            pick_cnt[num]++;
        }
        else {
            picture.push_back(num);
            pick_cnt[num]++;
        }

    }

    sort(picture.begin(), picture.end());
    for (int i=0; i<n; i++) {
        printf("%d ", picture[i]);
    }
}