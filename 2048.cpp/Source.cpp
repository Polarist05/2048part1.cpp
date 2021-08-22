#include <stdio.h>
#include<iostream>
#include<string>
using namespace std;
enum  moveDirection{Up,Down,Left,Right};
int m[4][4];
int si = 4;
int DiY(moveDirection mo) {
	if (mo == moveDirection::Up)
		return -1;
	if (mo == moveDirection::Down)
		return 1;
	return 0;
}
int DiX(moveDirection mo) {
	if (mo == moveDirection::Left)
		return -1;
	if (mo == moveDirection::Right)
		return 1;
	return 0;
}
void Move(moveDirection mo, int x, int y) {
	int dix = DiX(mo), diy = DiY(mo);
	if (dix+x >= 0 && diy+y >= 0 && dix+x < si && diy+y < si) {
		if (m[y + diy][x + dix] == 0)
		{
			m[y + diy][x + dix] = m[y][x];
			m[y][x] = 0;
			Move(mo, x + dix, y + diy );
		}
		else if (m[y + diy][x + dix] == m[y][x])
		{
			m[y + diy][x + dix] *= 2;
			m[y][x] = 0;
		}
	}
}
int  main() {
	for (int i = 0; i < si; i++) {
		for (int j = 0; j < si; j++) {
			scanf_s("%d", &m[i][j]);
		}
	}
	string s;
	cin >> s;
	for (int i = 0; (unsigned int)i < s.size(); i++) {
		switch (s[i])
		{
		case('U'):
			for (int j = 0; j < si; j++) {
				for (int k = 0; k < si; k++) {
					if (m[j][k] != 0) {
						Move(moveDirection::Up, k , j);
					}
				}
			}
			break;
		case('D'):
			for (int j = si - 1; j >= 0; j--) {
				for (int k = 0; k < si; k++) {
					if (m[j][k] != 0) {
						Move(moveDirection::Down, k, j);
					}
				}
			}
			break;
		case('L'):
			for (int j = 0; j < si; j++) {
				for (int k = 0; k < si; k++) {
					if (m[k][j] != 0) {
						Move(moveDirection::Left, j, k);
					}
				}
			}
			break;
		case('R'):
			for (int j = si - 1; j >= 0; j--) {
				for (int k = 0; k < si; k++) {
					if (m[k][j] != 0) {
						Move(moveDirection::Right, j, k);
					}
				}
			}
			break;
		}
	}
	for (int i = 0; i < si; i++) {
		for (int j = 0; j < si; j++) {
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
}
