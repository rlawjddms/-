//dfs
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> graph[9];
bool visited[9];


void dfs(int x) {
	visited[x] = true;
	cout << x << " ";
	//����Լ� ���
	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if (!visited[y]) dfs(y);
	}
}

void bfs(int start) {
	//���� ��带 ť�� �����ϰ� �湮 ó���� �Ѵ�.
	queue<int> queue;
	queue.push(start);
	visited[start] = true;
	//ť���� start ��带 ���� �湮���� ���� ���� ��带 ť�� �����ϰ�
	//�湮 ó���� �Ѵ�.
	while (!queue.empty()) {
		int x = queue.front();
		queue.pop();
		cout << x << " ";
		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];
			if (!visited[y]) {
				queue.push(y);
				visited[y] = true;
			}
		}
	}
}

int main(void) {
	graph[1].push_back(2);
	graph[1].push_back(3);
	graph[1].push_back(8);

	graph[2].push_back(1);
	graph[2].push_back(7);

	graph[3].push_back(1);
	graph[3].push_back(4);
	graph[3].push_back(5);

	graph[4].push_back(3);
	graph[4].push_back(5);

	graph[5].push_back(3);
	graph[5].push_back(4);

	graph[6].push_back(7);

	graph[7].push_back(2);
	graph[7].push_back(6);
	graph[7].push_back(8);

	graph[8].push_back(1);
	graph[8].push_back(7);

	bfs(1);
}