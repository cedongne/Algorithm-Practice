#include <iostream>
#include <map>
#include <vector>

int n;
int level;

struct Node {
	std::map<std::string, Node> child;
};

Node root;

void insert(Node& node, std::vector<std::string> vec, int lv) {
	if (lv == vec.size()) {
		return;
	}

	if (node.child.count(vec[lv]) == 0) {
		node.child[vec[lv]] = Node();
	}

	insert(node.child[vec[lv]], vec, lv + 1);
}

void print(Node &node, int lv) {
	if (node.child.empty()) {
		return;
	}
	for (auto children : node.child) {
		for (int count = 0; count < lv; count++) {
			std::cout << "--";
		}
		std::cout << children.first << "\n";

		print(children.second, lv + 1);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> n;

	for (int count = 0; count < n; count++) {
		std::cin >> level;

		std::vector<std::string> v(level);
		for (int levelCnt = 0; levelCnt < level; levelCnt++) {
			std::cin >> v[levelCnt];
		}
		insert(root, v, 0);
	}
	print(root, 0);
}