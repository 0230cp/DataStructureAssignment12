#include <iostream>
#include <vector>
#define INF 1e9 // ������ �ǹ��ϴ� ������ 10�� ����
using namespace std;

// ��� ����: n, ���� ����: m, ���� ��� ��ȣ: start
int n, m, start;

// ��� ������ �ִ� 100,000����� ����
// pair: ���� ��� ��ȣ, ����ġ
vector<pair<int, int>> graph[100'001];

bool visited[100'001]; // �湮�� ���� �ִ��� üũ
int d[100'001]; // �ִ� �Ÿ� ���̺�

// �湮���� ���� ��� �߿��� �ִ� �Ÿ��� ���� ª�� ����� ��ȣ ����
int getSmallestNode() {
	int min = INF;
	int idx = 0;

	for (int i = 0; i <= n; i++) {
		if ((d[i] < min) && !visited[i]) {
			min = d[i];
			idx = i;
		}
	}

	return idx;
}

// ���ͽ�Ʈ�� �˰���
void dijkstra(int start) {
	// ���� ��忡 ���� �ʱ�ȭ
	d[start] = 0;
	visited[start] = true;

	// ���� ����� ���� ������
	// ���� �������� �Ÿ��� ���̺� �ʱ�ȭ
	for (int j = 0; j < graph[start].size(); j++) {
		d[graph[start][j].first] = graph[start][j].second;
	}

	// ���� ��带 ������ ��ü n-1 ���� ��忡 ���� �ݺ�
	for (int i = 0; i < n - 1; i++) {
		// ���� �ִ� �Ÿ��� ���� ª�� ��带 �����ؼ� �湮 ó��
		int now = getSmallestNode();
		visited[now] = true;

		// ���� ���� ����� �ٸ� ��� Ȯ��
		for (int j = 0; j < graph[now].size(); j++) {
			int cost = d[now] + graph[now][j].second;

			// ���� ��带 ���ļ� �ٸ� ���� �̵��ϴ� �Ÿ��� �� ª�� ���
			if (cost < d[graph[now][j].first]) {
				d[graph[now][j].first] = cost;
			}
		}
	}
}

int main() {
	// ��� ����, ���� ����, ���� ����� ��ȣ 
	cin >> n >> m >> start;

	// ��� ���� ���� �Է� �ޱ�
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		// a�� ��忡�� b�� ���� ���� ����� c��� �ǹ�
		graph[a].push_back({ b, c });
	}

	// �ִ� �Ÿ� ���̺��� ��� �������� �ʱ�ȭ
	fill_n(d, 100'001, INF);

	// ���ͽ�Ʈ�� �˰��� ����
	dijkstra(start);

	// ���� ��忡�� �ٸ� ��� ���� ���� �ִ� �Ÿ� ���
	for (int i = 1; i <= n; i++) {
		if (d[i] == INF) // ������ �� ���� ���
			cout << "INF" << '\n';
		else // ������ �� �ִ� ��� �Ÿ� ���
			cout << d[i] << '\n';
	}

	return 0;
}