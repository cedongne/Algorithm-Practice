#include <iostream>
#include <vector>
#define MAX(a, b) ((a > b) ? a : b)

int t, n, k;
int buildings[1001];
std::vector<int> graph[1001];
std::vector<int> prev[1001];

int targetBuilding;
int spendingTime[1001];

void init() {
    for (int index = 0; index <= n; index++) {
        buildings[index] = 0;
        graph[index].clear();
        prev[index].clear();
    }
}

void trace_prev(int buildingNumber) {
    int additionalTime = 0;
    for (auto previousBuilding : prev[buildingNumber]) {
        if (spendingTime[previousBuilding] == buildings[previousBuilding]) {
            trace_prev(previousBuilding);
        }
        int temp = spendingTime[previousBuilding];
        additionalTime = MAX(temp, additionalTime);
    }
    spendingTime[buildingNumber] += additionalTime;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> t;
    for (int cases = 0; cases < t; cases++) {
        std::cin >> n >> k;

        init();

        for (int count = 1; count <= n; count++) {
            std::cin >> buildings[count];
            spendingTime[count] = buildings[count];
        }

        int firstBuild, secondBuild;
        for (int count = 1; count <= k; count++) {
            std::cin >> firstBuild >> secondBuild;
            graph[firstBuild].push_back(secondBuild);
            prev[secondBuild].push_back(firstBuild);
        }

        std::cin >> targetBuilding;
        int max = 0;
        for (auto previousBuilding : prev[targetBuilding]) {
            if (spendingTime[previousBuilding] == buildings[previousBuilding]) {
                trace_prev(previousBuilding);
            }
            int result = spendingTime[previousBuilding];
            max = MAX(result, max);
        }
        std::cout << max + buildings[targetBuilding] << std::endl;
    }
}