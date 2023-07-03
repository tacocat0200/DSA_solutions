//73.Set Matrix Zeroes - https://leetcode.com/problems/set-matrix-zeroes/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>

using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size()
    int n = matrix[0].size();
    bool firstRowZero = false;
    bool firstColZero = false;

    //check if the first row contains zero
    for(int j = 0; j < n; j++){
        if(matrix[0][j] == 0){
            firstRowZero = true;
            break;
        }
    }

    //check if the first column contains zero
    for(int i = 0; i < m; i++){
        if(matrix[i][0] == 0){
            firstColZero = true;
            break;
        }
    }

    //Mark zeroes on the first row and column
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    //Set rows to zero based on first column
    for(int i = 1; i < m; i++){
        if(matrix[i][0] == 0){
            for(int j = 1; j < n; j++){
                matrix[i][j] = 0;
            }
        }
    }

    //set columns to zero based on first row
    for(int j = 1; j < n; j++){
        if(matrix[0][j] == 0){
            for(int i = 1; i < m; i++){
                matrix[i][j] = 0;
            }
        }
    }

    //set first row to zero if needed
    if(firstRowZero){
        for(int j = 0; j < n; j++){
            matrix[0][j] = 0;
        }
    }

    //set first column to zero if needed
    if(firstColZero){
        for(int i = 0; i < m; i++){
            matrix[i][0] = 0;
        }
    }

}

int main(){
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};

    cout << "original Matrix:" << endl;
    for(const auto& row : matrix) {
        for(int num : row){
            cout << num << " ";
        }
        cout << endl;
    }

    setZeroes(matrix);

    cout << "\nMatrix after setting zeroes:" << endl;
    for (const auto& row : matrix){
        for(int num : row){
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;

}