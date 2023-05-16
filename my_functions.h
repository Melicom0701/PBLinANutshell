#ifndef MY_FUNCTIONS_H
#define MY_FUNCTIONS_H
using namespace std;
const int NMAX=1000;
const int inf = 9999999;
void input(int &n,int &m,int graph[][NMAX],int deg[]);
void output(int n,int graph[NMAX][NMAX]);
void dijkstra(int start,int destination,int n,int graph[NMAX][NMAX],int path[]);
void print_path(int u,int path[NMAX]);
bool check_euler_graph(int n, int graph[NMAX][NMAX],int deg[]);
void primMST(int n,int graph[NMAX][NMAX]);

#endif
