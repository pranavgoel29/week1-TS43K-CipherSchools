#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& it) {
        sort(it.begin(), it.end());
        vector<vector<int>> res;
        res.push_back(it[0]);

        int index=0;
        int n = it.size();

        for(int i=1; i<n; i++) {
            if(it[index][1] >= it[i][0]) {
                res[index][0] = min(it[index][0], it[i][0]);
                res[index][1] = max(it[index][1], it[i][1]);
            }
            else
            {
                res.push_back(it[i]);
                index++;
            }
        }
        return res;
    }

int main(){
    vector<vector<int>> it = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> matrix = merge(it);
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}