// Vjudge 第七周4

#include <bits/stdc++.h>
using namespace std;

bool visited[15][15];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int HA, WA;
    cin >> HA >> WA;
    vector<string> paperA(HA);
    for (int i = 0; i < HA; i++) {
        cin >> paperA[i];
    }

    int HB, WB;
    cin >> HB >> WB;
    vector<string> paperB(HB);
    for (int i = 0; i < HB; i++) {
        cin >> paperB[i];
    }

    int HX, WX;
    cin >> HX >> WX;
    vector<string> paperX(HX);
    for (int i = 0; i < HX; i++) {
        cin >> paperX[i];
    }

    for (int rowX = 0; rowX < HX; rowX++) {
        for (int colX = 0; colX < WX; colX++) {
            for (int i = 0; i < 15; i++)
                fill(visited[i], visited[i] + 15, false);
            for (int rowA = 0; rowA < HA; rowA++) {
                for (int colA = 0; colA < WA; colA++) {
                    if (paperX[rowX][colX] != paperA[rowA][colA])
                        continue;
                    for (int row_offset = 0; row_offset + rowX < HX; row_offset++) {
                        for (int col_offset = 0; col_offset + colX < WX; col_offset++) {
                            if (row_offset + rowA < HA && col_offset + colA < WA) {
                                if (paperX[rowX + row_offset][colX + col_offset] == paperA[rowA + row_offset][colA + col_offset]) {
                                    visited[rowX + row_offset][colX + col_offset] = true;
                                }
                            } else {
                                if (paperX[rowX + row_offset][colX + col_offset] == '.') {
                                    visited[rowX + row_offset][colX + col_offset] = true;
                                }
                            }
                        }
                    }
                }
            }
            for (int rowX1 = 0; rowX1 < HX; rowX1++) {
                for (int colX1 = 0; colX1 < WX; colX1++) {
                    for (int rowB = 0; rowB < HB; rowB++) {
                        for (int colB = 0; colB < WB; colB++) {
                            if (paperX[rowX1][colX1] != paperB[rowB][colB])
                                continue;
                            for (int row_offset = 0; row_offset + rowX1 < HX && row_offset + rowB < HB; row_offset++) {
                                for (int col_offset = 0; col_offset + colX1 < WX && col_offset + colB < WB; col_offset++) {
                                    if (row_offset + rowB < HB && col_offset + colB < WB) {
                                        if (paperX[rowX1 + row_offset][colX1 + col_offset] == paperB[rowB + row_offset][colB + col_offset]) {
                                            visited[rowX1 + row_offset][colX1 + col_offset] = true;
                                        }
                                    } else {
                                        if (paperX[rowX1 + row_offset][colX1 + col_offset] == '.') {
                                            visited[rowX1 + row_offset][colX1 + col_offset] = true;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            bool valid = true;
            for (int i = 0; i < HX; i++) {
                for (int j = 0; j < WX; j++) {
                    if (!visited[i][j]) {
                        valid = false;
                    }
                }
            }
            if (valid) {
                cout << "Yes" << '\n';
                return 0;
            }
        }
    }
    cout << "No" << '\n';
    return 0;
}
