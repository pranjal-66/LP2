/*rollno:35
name : Pranjal Karande
exp2: Implement A* algorithm for any game search problem(8 puzzle)
*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_set>
using namespace std;
#define N 3
//Goal state
vector<vector<int>> goal = { 
	{1,2,3},
	{4,5,6},
	{7,8,0}
};
//Node structure
struct Node{
	vector<vector<int>> mat;
	int x, y;	//blank position
	int g, h;	//cost
	Node* parent;
};
//Manhattan heuristic
int calculateH(vector<vector<int>> &mat) {
	int h = 0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(mat[i][j] != 0) {
				int val = mat[i][j] - 1;
				int gx = val/N;
				int gy = val%N;
				h += abs(i - gx) + abs(j - gy);
			}
		}
	}
	return h;
}
//Comparator for priority queue
struct cmp{
	bool operator()(Node* a, Node* b) {
		return( a-> g + a->h) > (b->g + b->h);
	}
};
//print board
void printMatrix(vector<vector<int>> mat) {
	for(auto row:mat) {
		for(int x : row)
			cout<< x <<" ";
		cout<<"\n";
	}
	cout<<"------\n";
}
//print path						
void printPath(Node* node) {
	if(node == NULL)
		return;
	printPath(node -> parent);
	printMatrix(node -> mat);
}
//convert matrix to string (for visited set)
string toString(vector<vector<int>> mat) {
	string s = "";
	for(auto r:mat)
		for(int x:r)
			s += char(x+'0');
		return s;
}
//A* algorithm
void solve(vector<vector<int>> start, int x, int y) {
	priority_queue<Node*, vector<Node*>, cmp>pq;
	unordered_set<string>visited;
	Node* root = new Node{start, x, y, 0, calculateH(start), NULL};
	pq.push(root);
	int dx[] = {1,-1,0,0};
	int dy[] = {0,0,1,-1};
	while(!pq.empty()) {
	Node* cur = pq.top();
	pq.pop();
	string key = toString(cur->mat);
	if(visited.count(key)) continue;
	visited.insert(key);
	//Goal reached
	if(cur->h == 0){
		cout<<"Solution Found!\n\n";
		printPath(cur);
		return;
	}
	//Generate children
	for(int k = 0;k<4;k++) {
		int nx = cur -> x + dx[k];
		int ny = cur -> y + dy[k];
		if(nx >= 0 && ny >= 0 && nx < N && ny < N) {
			vector<vector<int>> newMat = cur->mat;
			swap(newMat[cur->x][cur->y], newMat[nx][ny]);
			Node* child = new Node{
				newMat,
				nx, ny,
				cur->g + 1,
				calculateH(newMat),
				cur
			};
			pq.push(child);
		}
	}
}
cout<<"No solution\n";
}	
//DRiver
int main() {
	vector<vector<int>> start = {
		{1,2,3},
		{4,0,5},
		{6,7,8}
	};
	solve(start, 1, 1);
	return 0;
}

