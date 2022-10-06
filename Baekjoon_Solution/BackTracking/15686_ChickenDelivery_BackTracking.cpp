#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#define MAX 1000000000

int N, M;

std::pair<int, int> housePos[100];
std::pair<int, int> chickenPos[13];

int dist[100][13];

int houseNum = 0;
int chickenNum = 0;


void get_dist() {
	for (int houseCnt = 0; houseCnt < houseNum; houseCnt++) {
		for (int chickenCnt = 0; chickenCnt < chickenNum; chickenCnt++) {
			dist[houseCnt][chickenCnt] = std::abs(housePos[houseCnt].first - chickenPos[chickenCnt].first) + std::abs(housePos[houseCnt].second - chickenPos[chickenCnt].second);
		}
	}
}

int combination() {
	std::vector<int> combiTemp(chickenNum, 0);
	for (int index = chickenNum - 1; M > 0; index--, M--) {
		combiTemp[index] = 1;
	}

	int distSumMin = MAX;
	do {
		int distSum = 0;
		for (int houseCnt = 0; houseCnt < houseNum; houseCnt++) {
			int min = MAX;
			for (int chickenCnt = 0; chickenCnt < chickenNum; chickenCnt++) {
				if (combiTemp[chickenCnt] && min > dist[houseCnt][chickenCnt]) {
					min = dist[houseCnt][chickenCnt];
				}
			}
			distSum += min;
		}
		if (distSumMin > distSum) {
			distSumMin = distSum;
		}
	} while (std::next_permutation(combiTemp.begin(), combiTemp.end()));

	return distSumMin;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;

	int node;
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			std::cin >> node;
			if (node == 1) {
				housePos[houseNum++] = {row, col};
			}
			else if (node == 2) {
				chickenPos[chickenNum++] = {row, col};
			}
		}
	}
	get_dist();

	std::cout << combination() << std::endl;
}