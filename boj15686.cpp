#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;

int map[51][51];
int n, chicken, answer = 9999;
vector<int> dist[51][51];
vector<pair<int, int>> chicken_coord;

int ChickenDistance(int fromX, int fromY, int toX, int toY);
void pickElements(int size, vector<int>& picked, int toPick);
int TotalDistance(vector<int> &picked);

int main() {
	cin >> n >> chicken;

	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			cin >> map[y][x];
			if (map[y][x] == 2) {
				chicken_coord.push_back(make_pair(y,x));
			}
		}
	}

	// calc distance
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			if (map[y][x] == 1) {
				for (pair<int, int> coord : chicken_coord) {
					dist[y][x].push_back(ChickenDistance(
						x, y, coord.second, coord.first
					));
				}
			}
			else {
				for (int i = 0; i < chicken_coord.size(); i++) {
					dist[y][x].push_back(0);
				}
			}
		}
	}

	// del chicken
	vector<int> picked;
	pickElements(chicken_coord.size(), picked, chicken);

	cout << answer;

	return 0;
}

int ChickenDistance(int fromX, int fromY, int toX, int toY) {
	return abs(fromX - toX) + abs(fromY - toY);
}

void pickElements(int size, vector<int>& picked, int toPick) {
	if (toPick == 0) {
		int temp = TotalDistance(picked);
		answer = temp < answer ? temp : answer;
		return;
	}
	int min = picked.empty() ? 0 : picked.back() + 1;
	for (int next = min; next < size; next++) {
		picked.push_back(next);
		pickElements(size, picked, toPick - 1);
		picked.pop_back();
	}
}

int TotalDistance(vector<int> &picked) {
	int totaldist = 0;
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			int min_dist = 999999;
			for (int idx : picked) {
				min_dist = dist[y][x][idx] < min_dist ? dist[y][x][idx] : min_dist;
			}
			totaldist += min_dist;
		}
	}
	return totaldist;
}

// 3.31 ~ 4.4