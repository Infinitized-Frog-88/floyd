#include <iostream>

using namespace std;

int main() {
    int dist[30][30];
    for (int i = 0; i < 30; ++i) {
        fill(dist[i], dist[i] + 26, 100000);
        dist[i][i] = 0;
    }
    int m;
    cin >> m;

    while (m--) {
        char u;
        char v;
        int w;
        cin >> u >> v >> w;
        dist[u - 97][v - 97] = w;
    }

    for (int k = 0; k < 26; ++k) {
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    cout << dist['a' - 'a']['z' - 'a'] << endl;
    return 0;
}
