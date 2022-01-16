#include <bits/stdc++.h>
using namespace std;

const int N = 9; 

bool boxCheck(int grid[N][N], int row, int col, int num){
	int startingRow = row - row % 3;
	int startingCol = col - col % 3;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(grid[startingRow+i][startingCol+j] == num){
				return true;
			}
		}
	}
	return false;
}

bool isValid(int grid[N][N], int row, int col, int num){

	if(grid[row][col] != 0 or grid[row][col] == num){ // grid validity check
		return false;
	}
	for(int i = 0; i < 9;i++){ // row validity check
		if(grid[row][i] == num){
			return false;
		}
	}
	for(int i = 0; i < 9;i++){ // column validity check
		if(grid[i][col] == num){
			return false;
		}
	}
	if(boxCheck(grid, row, col, num)){
		return false;
	}
	return true;

}


bool findUnassignedLocation(int grid[N][N], int &row, int &col){
	for(row = 0; row < 9; row++){
		for(col = 0; col < 9; col++){
			if(grid[row][col] == 0){
				return true;
			}
		}
	}
	return false;
}

void displayGrid(int grid[N][N]){
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			cout << grid[i][j] << " ";
		}
		cout << "\n";
	}
}

bool solve(int grid[N][N]){
	int row, col;
	if(findUnassignedLocation(grid, row, col) == false){
		return true;
	}
	for(int i = 1; i  <= 9; i++){
		if(isValid(grid, row, col, i)){
			grid[row][col] = i;
			if(solve(grid)){
				return true;
			}
			grid[row][col] = 0;
		}

	}
	return false;

}

int main(){
	int grid[N][N];
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			cin >> grid[i][j];
		}
	}
	if(solve(grid)){
		cout << "Solution is: " << "\n";
		displayGrid(grid);
	}
	else{
		cout << "Simply IMPOSSIBLE" << "\n";
	}
	return 0;
}