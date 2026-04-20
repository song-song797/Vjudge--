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

    for (int shiftA_row = -10; shiftA_row <= 10; shiftA_row++) {
        for (int shiftA_col = -10; shiftA_col <= 10; shiftA_col++) {
            for (int shiftB_row = -10; shiftB_row <= 10; shiftB_row++) {
                for (int shiftB_col = -10; shiftB_col <= 10; shiftB_col++) {
                    vector<string> C(HX, string(WX, '.'));
                    bool valid = true;

                    for (int i = 0; i < HA; i++) {
                        for (int j = 0; j < WA; j++) {
                            if (paperA[i][j] == '#') {
                                int r = i + shiftA_row;
                                int c = j + shiftA_col;
                                if (r >= 0 && r < HX && c >= 0 && c < WX) {
                                    C[r][c] = '#';
                                } else {
                                    valid = false;
                                }
                            }
                        }
                    }

                    if (!valid)
                        continue;

                    for (int i = 0; i < HB; i++) {
                        for (int j = 0; j < WB; j++) {
                            if (paperB[i][j] == '#') {
                                int r = i + shiftB_row;
                                int c = j + shiftB_col;
                                if (r >= 0 && r < HX && c >= 0 && c < WX) {
                                    C[r][c] = '#';
                                } else {
                                    valid = false;
                                }
                            }
                        }
                    }

                    if (!valid)
                        continue;

                    bool match = true;
                    for (int i = 0; i < HX; i++) {
                        for (int j = 0; j < WX; j++) {
                            if (C[i][j] != paperX[i][j]) {
                                match = false;
                                break;
                            }
                        }
                        if (!match)
                            break;
                    }

                    if (match) {
                        cout << "Yes\n";
                        return 0;
                    }
                }
            }
        }
    }

    cout << "No\n";
    return 0;
}