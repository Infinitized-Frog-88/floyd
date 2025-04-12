#include <iostream>

using namespace std;

int main() {
    int dist[30][30];
    int next[30][30];
    for (int i = 0; i < 30; ++i) {
        fill(dist[i], dist[i] + 26, 100000);
        fill(next[i], next[i] + 26, 0);
        dist[i][i] = 0;
    }

    int m;
    cin >> m;
    while (m--) {
        char u;
        char v;
        int w;
        cin >> u >> v >> w;
        dist[u - 'a'][v - 'a'] = w;
        dist[v - 'a'][u - 'a'] = w;
        next[u - 'a'][v - 'a'] = v - 'a';
        next[v - 'a'][u - 'a'] = u - 'a';
    }

    for (int k = 0; k < 26; ++k) {
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }

    cout << "USE LOWER CASE!" << endl;
    char s;
    char t; 
    while (cin >> s >> t) {
        s -= 'a';
        t -= 'a';
        cout << dist[s][t] << endl;
        char i = s;
        while (i != t) {
            cout << char(i + 'a') << ' ';
            i = next[i][t];
        }
        cout << char(t + 'a') << endl;;
    }
    return 0;
}
