#include <iostream>
#include <queue>

using namespace std;

int n;

queue<int> q;
bool notPrime[4000001] = { 0, };

int answer = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int count = 2; count <= n / 2; count++) {
		if (notPrime[count]) {
			continue;
		}
		for (int temp = count * 2; temp <= n; temp += count) {
			notPrime[temp] = true;
		}
	}

	int sum = 0;

	for (int count = n; count >= 2; count--) {
		if (notPrime[count]) {
			continue;
		}
		q.push(count);
		sum += count;
		if (sum == n) {
			answer++;
		}
		if (sum >= n) {
			sum -= q.front();
			q.pop();
		}
	}

	cout << answer << endl;
}