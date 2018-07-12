/*
 * pat1027.cpp
 *
 *  Created on: Jul 11, 2018
 *      Author: ubuntu
 *      PAT Advanced:1027 Colors in Mars (20)
 */

#include <cstdio>

using namespace std;

int main() {
    char c[14] = {"0123456789ABC"};
    printf("#");
    for(int i = 0; i < 3; i++) {
        int num;	// 0-168
        scanf("%d", &num);
        printf("%c%c", c[num/13], c[num%13]);
    }
    return 0;
}
