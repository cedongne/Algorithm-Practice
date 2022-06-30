///////////////////////////////////////////////
//////////////////// Array ////////////////////
///////////////////////////////////////////////
#include <iostream>

class Node {
public:
	Node *child[26];	// 알파벳 26개
	bool last;

	Node() {
		for (int index = 0; index < 26; index++) {
			child[index] = NULL;
		}
		last = false;
	}
};

int n;

void insert(Node &node, std::string str, int index) {
	if (index == str.length()) {
		node.last = true;
		return;
	}

	int children = str[index] - 'a';

	if (node.child[children] == NULL) {
		node.child[children] = new Node();
	}

	insert(*node.child[children], str, index + 1);
}

bool find(Node& node, std::string str, int index) {
	if (index == str.length()) {
		return node.last;
	}
	if (node.child[str[index] - 'a'] == NULL) {
		return false;
	}
	return find(*node.child[str[index] - 'a'], str, index + 1);
}

void print_all(Node &node, std::string str, int index) {
	if (node.last) {
		std::cout << str << "\n";
	}

	for (int index = 0; index < 26; index++) {
		char ch;
		if (node.child[index] != NULL) {
			ch = index + 'a';

			print_all(*node.child[index], str + ch, index + 1);
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> n;

	Node root;

	std::string str;
	for (int count = 0; count < n; count++) {
		std::cin >> str;

		insert(root, str, 0);
	}

	std::string findStr;
	std::cin >> findStr;
	if (find(root, findStr, 0)) {
		std::cout << "YES\n";
	}
	else {
		std::cout << "NO\n";
	}

	print_all(root, "", 0);
}


///////////////////////////////////////////////
///////////////////// Map /////////////////////
///////////////////////////////////////////////
/*
#include <iostream>
#include <map>

class Node {
public:
	std::map<char, Node> child;
	bool last;

	Node() {
		last = false;
	}
};

int n;

void insert(Node& node, std::string str, int index) {
	if (index == str.length()) {
		node.last = true;
		return;
	}

	if (node.child.count(str[index]) == 0) {
		node.child[str[index]] = Node();
	}

	insert(node.child[str[index]], str, index + 1);
}

bool find(Node& node, std::string str, int index) {
	if (index == str.length()) {
		return node.last;
	}

	if (!node.child.count(str[index])) {
		return false;
	}

	return find(node.child[str[index]], str, index + 1);
}
void print_all(Node& node, std::string str, int index) {
	if (node.last) {
		std::cout << str << "\n";
	}

	for (auto children : node.child) {
		print_all(children.second, str + children.first, index + 1);
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> n;

	Node root;

	std::string str;
	for (int count = 0; count < n; count++) {
		std::cin >> str;

		insert(root, str, 0);
	}

	std::string findStr;
	std::cin >> findStr;
	if (find(root, findStr, 0)) {
		std::cout << "YES\n";
	}
	else {
		std::cout << "NO\n";
	}

	print_all(root, "", 0);
}
*/