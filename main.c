#include <stdio.h>
#include <stdbool.h>

int departments[5][5] = {
    {3,1,2,5,4},
    {4,3,1,5,2},
    {2,5,4,1,3},
    {4,5,2,1,3},
    {3,2,1,5,4}
};

int programmers[5][5] = {
    {1,5,3,2,4},
    {1,3,4,2,5},
    {3,4,2,5,1},
    {3,1,2,4,5},
    {4,3,1,2,5}
};

int matches[5] = {-1, -1, -1, -1, -1};
bool free[5] = {true, true, true, true, true};

void find_match() {
    while (true) {
        bool all_matched = true;
        for (int i = 0; i < 5; i++) {
            if (matches[i] == -1) { 
                all_matched = false;
                for (int j = 0; j < 5; j++) {
                    int department = programmers[i][j] - 1;
                    if (free[department]) { 
                        matches[i] = department;
                        free[department] = false;
                        break;
                    } else {
                        int cur_match = matches[department];
                        int cur_rank = 0, new_rank = 0;
                        for (int k = 0; k < 5; k++) {
                            if (departments[department][k] == i + 1) {
                                new_rank = k;
                            }
                            if (departments[department][k] == cur_match + 1) {
                                cur_rank = k;
                            }
                        }
                        if (new_rank < cur_rank) { 
                            matches[i] = department;
                            free[department] = false;
                            matches[cur_match] = -1;
                            break;
                        }
                    }
                }
            }
        }
        if (all_matched) {
            break;
        }
    }
}

int main() {
    find_match();
    for (int i = 0; i < 5; i++) {
        printf("Department #%d will get Programmer #%d\n", i + 1, matches[i] + 1);
    }
    return 0;
}