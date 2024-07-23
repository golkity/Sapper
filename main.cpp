#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector <vector<int>> t(n+2, vector<int>(m+2,0));
    for(int i = 0;i<k;++i){
        int mi,mj;
        cin>>mi>>mj;
        t[mi][mj] = -1;
    }
    vector<int> di = {-1, -1, -1,  0, 0,  1, 1, 1};
    vector<int> dj = {-1,  0,  1, -1, 1, -1, 0, 1};
    for (int i = 1; i < t.size() - 1; ++i){
        for (int j = 1; j < t[i].size() - 1; ++j){
            if (t[i][j] == -1){
                for (int k = 0; k < 8; ++k){
                    int ni = i + di[k];
                    int nj = j + dj[k];
                    if (t[ni][nj] != -1)
                        ++t[ni][nj];
                }
            }
        }
    }
    for (int i = 1; i < t.size() - 1; ++i){
        for (int j = 1; j < t[i].size() - 1; ++j){
            if (t[i][j] == -1){
                cout << "*";
            }
            else if (t[i][j] == 0){
                cout << ".";
            }
            else{
                cout << t[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}
