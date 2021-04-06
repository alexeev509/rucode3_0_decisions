#include<iostream>
#include<vector>

using namespace std;

long n, m, k, x, y;

void markVertexes(vector<vector<int>> & mass_schools, vector<pair<int, int>> & vertexes, int i, int j) {
    if(mass_schools[i][j]==0 || mass_schools[i][j]==2 || i<1 || j<1 || i>n || j>m)
        return;
    mass_schools[i][j]=2;
    markVertexes(mass_schools,vertexes,i+1,j);
    markVertexes(mass_schools,vertexes,i-1,j);
    markVertexes(mass_schools,vertexes,i,j+1);
    markVertexes(mass_schools,vertexes,i,j-1);
}

int main() {
    cin >> n >> m >> k;
    vector<vector<int>> mass_schools(n + 2, vector<int>(m + 2, 0));
    vector<pair<int, int>> vertexes(k, {0, 0});
    for (int i = 0; i < k; ++i) {
        cin >> x >> y;
        //1 - not visited school
        mass_schools[x][y] = 1;
        vertexes[i] = {x, y};
    }
    long count = 0;

    for (int i = 0; i < vertexes.size(); ++i) {
        int k = vertexes[i].first, j = vertexes[i].second;
        if (mass_schools[k][j] != 2) {
            ++count;
            markVertexes(mass_schools,vertexes,k,j);
        }
    }
    cout << count << endl;
    return 0;
}
