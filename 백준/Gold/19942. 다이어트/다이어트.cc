#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 16
#define INF 2e9
#define FASTIO cin.tie(0); cout.tie(0);

using namespace std;
struct INFO {
    int P, F, S, V, C;
};

int N, MP, MF, MS, MV;
vector<INFO> Vec;
bool visited[MAX];
int Answer = INF;
vector<int> Which;

void input() {
    cin >> N;
    cin >> MP >> MF >> MS >> MV;
    for (int i = 0; i < N; i++) {
        int P, F, S, V, C;
        cin >> P >> F >> S >> V >> C;
        Vec.push_back({ P,F,S,V,C });
    }
}

void checking(int P, int F, int S, int V, int C) {
    if ((P >= MP) && (F >= MF) && (S >= MS) && (V >= MV)) {
        if (Answer == INF) {
            Answer = C;
            for (int i = 0; i < N; i++) {
                if (visited[i]) {
                    Which.push_back(i + 1);
                }
            }
        }
        else {
            if (Answer == C) {
                vector<int> Tmp;
                for (int i = 0; i < N; i++) {
                    if (visited[i]) {
                        Tmp.push_back(i + 1);
                    }
                }
                string A = "";
                string B = "";
                for (int i = 0; i < Tmp.size(); i++) {
                    int Cur = Tmp[i];
                    if ((Cur >= 1) && (Cur <= 9)) {
                        A += to_string(Cur);
                    }
                    else {
                        A += (char)(55 + Cur);
                    }
                }
                for (int i = 0; i < Which.size(); i++) {
                    int Cur = Which[i];
                    if ((Cur >= 1) && (Cur <= 9)) {
                        B += to_string(Cur);
                    }
                    else {
                        B += (char)(55 + Cur);
                    }
                }
                if (A < B) {
                    Answer = C;
                    Which.clear();
                    Which = Tmp;
                }
            }
            else if (Answer > C) {
                Answer = C;
                Which.clear();
                for (int i = 0; i < N; i++) {
                    if (visited[i]) {
                        Which.push_back(i + 1);
                    }
                }
            }
        }
    }
}

void DFS(int Depth, int CurP, int CurF, int CurS, int CurV, int CurC) {
    if (Depth == N) {
        checking(CurP, CurF, CurS, CurV, CurC);
        return;
    }

    // 현재 식재료를 선택
    visited[Depth] = true;
    DFS(Depth + 1, CurP + Vec[Depth].P, CurF + Vec[Depth].F, CurS + Vec[Depth].S, CurV + Vec[Depth].V, CurC + Vec[Depth].C);

    // 선택 안 함
    visited[Depth] = false;
    DFS(Depth + 1, CurP, CurF, CurS, CurV, CurC);
}

void find_Answer() {
    if (Answer == INF) {
        cout << "-1\n";
    }
    else {
        cout << Answer << "\n";
        sort(Which.begin(), Which.end());
        for (int i = 0; i < Which.size(); i++) {
            cout << Which[i] << " ";
        }
        cout << "\n";
    }
}

int main() {
    FASTIO
    input();
    DFS(0, 0, 0, 0, 0, 0);
    find_Answer();

    return 0;
}