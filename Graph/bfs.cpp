#include <iostream>
#include <cstring>

using namespace std;

int a[100][100];
int v,e;
////////////////////////////
int q[105];
int front=0, rear=0;
void enque(int val){
	rear++;
	q[rear]=val;
}
void printq(){
	for(int i=front; i<=rear; i++){
		cout<<q[i]<<' ';
	}
	cout<<endl;
}

int deque(){
	int abc=q[front];
	front++;
	return abc;
}

bool isEmpty(){return (front==rear+1);}

void bfs(int s){
	enque(s);
	int visited[100];
	memset(visited, 0, sizeof visited);
	visited[s]=1;
	while(!isEmpty()){
		int p;
		p=deque();
		cout<<p<<" ";;
		//printq();
		for(int i=0; i<v; i++){
			if(visited[i]==0 && a[p][i]>0){
				enque(i);
				visited[i]=1;
			}
		}
		
	}
}



void input(){
	cin>>v>>e;
	for(int i=0; i<e; i++){
		int p,q,r;
		cin>>p>>q>>r;
		a[p][q]=r;
		a[q][p]=r; //bidirectional
	}
	for(int i=0; i<100; i++){q[i]=-1;}
	for(int i=0; i<v; i++){
		for(int j=0; j<v; j++){
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
}

int main(){
	input();
	bfs(0);
	
	return 0;
}
