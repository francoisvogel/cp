#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define pii pair<int, int>

pii dirs [4] = {pii(0, 1), pii(0, -1), pii(-1, 0), pii(1, 0)};

int main() {
    int height, width;
    cin >> height >> width;
    char grid [height][width];
    for (int i = 0; i < height; i++) for (int j = 0; j < width; j++) cin >> grid[i][j];
    bool visited [height][width];
    for (int i = 0; i < height; i++) for (int j = 0; j < width; j++) visited[i][j] = false;
    int counter = 0;
    for (int i = 0; i < height; i++) for (int j = 0; j < width; j++) {
        if (grid[i][j] == '.' and !visited[i][j]) {
            queue<pii> q;
            q.push(pii(i, j));
            visited[i][j] = true;
            while (!q.empty()) {
                int curX = q.front().first;
                int curY = q.front().second;
                q.pop();
                for (pii dir : dirs) {
                    int newX = curX+dir.first;
                    int newY = curY+dir.second;
                    if (0 <= newX and 0 <= newY and newX < height and newY < width and grid[newX][newY] == '.' and !visited[newX][newY]) {
                        q.push(pii(newX, newY));
                        visited[newX][newY] = true;
                    }
                }
            }
            counter++;
        }
    }
    cout << counter;
    int d = 0;
    d++;
}