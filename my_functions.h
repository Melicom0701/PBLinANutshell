#ifndef MY_FUNCTIONS_H
#define MY_FUNCTIONS_H
using namespace std;
const int NMAX=100;
const int inf = 9999;
void input(int &n,int &m,int graph[][NMAX],int deg[]);
void output(int n,int graph[NMAX][NMAX]);
void dijkstra(int start,int destination,int n,int G[NMAX][NMAX],int path[]);
void print_path(int u,int path[NMAX]);
bool check_euler_graph(int n, int graph[NMAX][NMAX],int deg[]);
void primMST(int n,int graph[NMAX][NMAX]);
void functions(int n,int m,int graph[NMAX][NMAX],int deg[NMAX],int path[NMAX]);
void printfHandling(int n,int graph[NMAX][NMAX]);
void findEulerCycle(int n,int graph[NMAX][NMAX]);

#endif
