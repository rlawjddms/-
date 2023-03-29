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
	//재귀함수 사용
	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if (!visited[y]) dfs(y);
	}
}

void bfs(int start) {
	//시작 노드를 큐에 삽입하고 방문 처리를 한다.
	queue<int> queue;
	queue.push(start);
	visited[start] = true;
	//큐에서 start 노드를 꺼내 방문하지 않은 인접 노드를 큐에 삽입하고
	//방문 처리를 한다.
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