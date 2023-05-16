#include <iostream>
#include "my_functions.h"
bool visited[NMAX];
void dfs(int u,int n,int graph[NMAX][NMAX]){

    visited[u] = true;
    for (int i = 0 ;i<n;i++)
    if (!visited[i])
    if (graph[u][i]!=0)
    {
        dfs(i,n,graph);
    }
    return;


}
int count_connected_components(int n,int graph[NMAX][NMAX]) {
    int cnt = 0;

    for (int i = 0;i<n;i++)
    visited[i] = false;
    for (int i = 0;i<n;i++)
    {
        if (!visited[i])
        {cnt++;
        visited[i]= true;
        dfs(i,n,graph);
        }

    }

    return cnt;
}

void input(int &n,int &m,int graph[][NMAX],int deg[]){

    freopen("graph.inp","r",stdin);
    printf("Nhap so dinh ");
    scanf("%d",&n);
    printf("Nhap so canh ");
    scanf("%d",&m);
    int u,v,w;
    for(int i = 0; i < n; i++) {
    deg[i]=0;
    for(int j = 0; j < n; j++)
    graph[i][j] = 0;
    }
    printf("Nhap do thi \n");
    for (int i = 1 ;i<=m;i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        if (graph[u][v]==0)
        {
        deg[u]++;
        deg[v]++;
        }
        graph[u][v] = w;
        graph[v][u] = w;

    }

    return;
}

void output(int n,int graph[NMAX][NMAX]){
    for (int i = 0;i<n;i++)
    {
        for (int j = 0;j<n;j++)
        printf("%d ",graph[i][j]);
        cout<<endl;
    }
}
void print_path(int u,int path[NMAX])
{

    if (u==-1) return;
    print_path(path[u],path);
    printf("%d - ",u);

}
void track(int u,int path[NMAX])
{
    if (u==-1) return;
    track(path[u],path);
    printf("%d ",u);

}

void dijkstra(int start,int destination,int n,int graph[NMAX][NMAX],int path[]) {
    int dist[NMAX];
    bool visited[NMAX];
    //init
    for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
    if(i == j) graph[i][j] = 0;
    else if (graph[i][j]==0) graph[i][j] = inf;
    }
    }
    for(int i = 0; i < n; i++) {
        dist[i] = graph[start][i];
        visited[i] = false;
    }
    dist[start] = 0;
    visited[start] = true;
    for(int i = 1; i < n; i++) {

        int min_dist = inf, u;

        for(int j = 0; j < n; j++) {
            if(!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                u = j;

            }

        }
        visited[u] = true;
        for(int v = 0; v < n; v++) {
            if(!visited[v] && graph[u][v] < inf) {
                int new_dist = dist[u] + graph[u][v];
                if(new_dist < dist[v]) {
                    dist[v] = new_dist;
                    path[v] = u;
                }
            }
        }
    }

    if (dist[destination]==inf)
    printf("Khong co duong di tu dinh %d den dinh %d",start,destination);
    else
    {
    printf("Khoang cach ngan nhat tu dinh %d den dinh %d la: %d\n", start,destination, dist[destination]);
    printf("duong di : \n");
    path[start] = -1;
    track(destination,path);
    }
    printf("\n");

}

bool check_euler_graph(int n, int graph[NMAX][NMAX],int deg[])
{
    int cnt_comps = count_connected_components(n,graph);
    if (cnt_comps > 1)
        return false;
    for (int u = 0; u < n; u++)
        if (deg[u] % 2 == 1)
            return false;

    return true;
}


int printMST(int n,int parent[], int graph[NMAX][NMAX])
{
    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++)
        printf("%d - %d \t%d \n", parent[i], i,
               graph[i][parent[i]]);
}
int minKey(int n,int key[], bool mstSet[]) {
       int min = inf, min_index;
       for (int v = 0; v < n; v++)
         if (mstSet[v] == false && key[v] < min)
             min = key[v], min_index = v;

        return min_index;
     }

void primMST(int n,int graph[NMAX][NMAX]) {
       int parent[n]; // Lưu đỉnh cha của đỉnh V trong cây bao trùm nhỏ nhất
       int key[n];
       bool mstSet[n];  // Đánh dấu các đỉnh đã được thêm vào tập các đỉnh đã xét

   for (int i = 0; i < n; i++)
      key[i] = inf, mstSet[i] = false;

   key[0] = 0;
   parent[0] = -1;

   for (int cnt = 0; cnt < n-1; cnt++) {
      int u = minKey(n,key, mstSet);

      mstSet[u] = true;

    for (int v = 0; v < n; v++)
        if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
           parent[v]  = u, key[v] = graph[u][v];

    }
    printMST(n,parent, graph);

 }




