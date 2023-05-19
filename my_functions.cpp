#include <iostream>
#include "my_functions.h"
#include <ctime>
#include <fstream>

bool visited[NMAX];
void dfs(int u,int n,int graph[NMAX][NMAX]){
    visited[u] = true;
    for (int i = 1 ;i<=n;i++)
    if (!visited[i])
    if (graph[u][i]!=inf)
    {
        dfs(i,n,graph);
    }
    return;
}
int count_connected_components(int n,int graph[NMAX][NMAX]) {
    int cnt = 0;

    for (int i = 1;i<=n;i++)
    visited[i] = false;
    for (int i = 1;i<=n;i++)
    {
        if (!visited[i])
        {cnt++;
        visited[i]= true;
        dfs(i,n,graph);
        }

    }
    return cnt;
}
//more input options pleaseee

void  adjacence_list(int &n,int &m,int graph[][NMAX],int deg[]){
    printf("-------------------------------------\n");
    printf("-    Nhap tu ban phim hoac file     -\n");
    printf("- 0 : nhap phim                     -\n");
    printf("- 1 : nhap file                     -\n");
    printf("-------------------------------------\n");
    int k;
    scanf("%d",&k);
    if (k==1)
    {

        FILE * file;
        file = fopen("graph.inp","r");
        fscanf(file, "%d", &n);
        fscanf(file, "%d", &m);
        int u,v,w;
        for(int i = 1; i <= n; i++) {
        deg[i]=0;
        }
        for (int i = 1 ;i<=m;i++)
        {

            fscanf(file, "%d", &u);
            fscanf(file, "%d", &v);
            fscanf(file, "%d", &w);
            if (graph[u][v]==inf)
            {
            deg[u]++;
            deg[v]++;
            }
            graph[u][v] = w;
            graph[v][u] = w;

        }
        fclose(file);




    }

    if (k==0)
    {

    printf("Nhap so dinh ");
    scanf("%d",&n);
    printf("Nhap so canh ");
    scanf("%d",&m);
    int u,v,w;
    for(int i = 1; i <= n; i++) {
    deg[i]=0;
    }
    printf("Nhap do thi (u,v,w)\n");
    for (int i = 1 ;i<=m;i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        if (graph[u][v]==inf)
        {
        deg[u]++;
        deg[v]++;
        }
        graph[u][v] = w;
        graph[v][u] = w;

    }
    }


}
void generateInput(int &n,int &m,int graph[][NMAX],int deg[]){
    srand(time(NULL));
    //generate n (2-> 15 )
     n = 2 + (rand() % 13);

    //generate m (2-> 200)
     m = n-1 + (rand() % 198);
    int u,v,w;
    for(int i = 1; i <= n; i++) {
    deg[i]=0;
    }
    for (int i = 1 ;i<=m;i++)
    {
        //scanf("%d %d %d",&u,&v,&w);
        //generate u v w -> u != v thuoc ( 0 - > n - 1) , w thuoc ( 1-> 500)
        u = 0 + rand()%(n);
        while (u==v)
        v = 0 + rand()%(n);
        w = 1 + rand()%199;


        if (graph[u][v]==inf)
        {
        deg[u]++;
        deg[v]++;
        }
        graph[u][v] = w;
        graph[v][u] = w;

    }

}

void input(int &n,int &m,int graph[][NMAX],int deg[]){

    int k =-1;
    for(int i = 1; i <= 20; i++) {
    for(int j = 1; j <= 20; j++) {
    if(i == j) graph[i][j] = 0;
    else graph[i][j] = inf;
    }
    }
    while (k<0 ||k>2)
    {
    printf("-------------------------------------\n");
    printf("-      chon phuong thuc nhap        -\n");
    printf("- 0: tu phat sinh ma tran trong so  -\n");
    printf("- 1 : nhap danh sach dinh ke        -\n");
    printf("-------------------------------------\n");
    printf("Nhap phuong thuc : ");
    scanf("%d",&k);

    switch(k)
    {
    case 0:
        generateInput(n,m,graph,deg);
        break;
    case 1:
        adjacence_list(n,m,graph,deg);
        break;
    }

    }


    return;
}

void output(int n,int graph[NMAX][NMAX]){
    for (int i = 1;i<=n;i++)
    {
        for (int j = 1;j<=n;j++)
        printf("%5d ",graph[i][j]);
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

void dijkstra(int start,int destination,int n,int G[NMAX][NMAX],int path[]) {
    int dist[NMAX];
    bool visited[NMAX];
    // Đường đi từ đỉnh i - > i = 0
    // Không có đường đi thì G[i][j] = inf
    //đường đi từ đỉnh start -> tất cả các đỉnh bằng inf
    //đường đi từ start -> start = 0


    for(int i = 1; i <= n; i++) {
        dist[i] = inf;
        visited[i] = false;
    }
    dist[start] = 0;
    //Duyet dinh cuoi cung ko duyet nua,

    for(int i = 1; i < n; i++) {

        int min_dist = inf;
        int u;
        //dist[u] = min(dist[i]) i =(0,n)
        // i is not Visited
        // tìm đỉnh u sao cho đỉnh u chưa được ghé thăm, đường đi từ gốc đến đỉnh u bé nhất.

        for(int j = 1; j <= n; j++) {
            if(!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                u = j;
            }

        }

        visited[u] = true;


        //lấy u làm gốc.
        //duyệt tất cả đỉnh trong N
        //nếu đỉnh V chưa ghé thăm và đường đi từ gốc - v (dist[u]+G[u][v]) ngắn hơn thì cải tiến
        for(int v = 1; v <= n; v++) {
            if(!visited[v] && G[u][v] < inf) {
                int new_dist = dist[u] + G[u][v];
                if(new_dist < dist[v]) {
                    dist[v] = new_dist;
                    // Lưu lại đỉnh kề trước nó để lát track lại đường đi
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
    for (int u = 1; u <= n; u++)
        if (deg[u] % 2 == 1)
            return false;

    return true;
}


int printMST(int n,int parent[], int graph[NMAX][NMAX])
{
    printf("Edge \tWeight\n");
    for (int i = 2; i <= n; i++)
        printf("%d - %d \t%d \n", parent[i], i,
               graph[i][parent[i]]);
}
int minKey(int n,int key[], bool mstSet[]) {
       int min = inf, min_index;
       for (int v = 1; v <= n; v++)
         if (mstSet[v] == false && key[v] < min)
             min = key[v], min_index = v;

        return min_index;
     }

void primMST(int n,int graph[NMAX][NMAX]) {
       int parent[n];
       int key[n];
       bool mstSet[n];

   for (int i = 1; i <= n; i++)
      key[i] = inf, mstSet[i] = false;

   key[1] = 1;
   parent[1] = -1;

   for (int cnt = 0; cnt < n-1; cnt++) {
      int u = minKey(n,key, mstSet);

      mstSet[u] = true;

    for (int v = 1; v <= n; v++)
        if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
           parent[v]  = u, key[v] = graph[u][v];

    }
    printMST(n,parent, graph);

 }
 void isEulerHandling(int n,int graph[NMAX][NMAX],int deg[NMAX])
 {
     bool isEulerGraph = check_euler_graph(n,graph,deg);
     if (isEulerGraph==true)
        printf("Do thi tren co chu trinh Euler\n");
     else printf("Do thi tren khong co chu trinh Euler\n");
     return;
 }

void dijkstraHandling(int n,int graph[NMAX][NMAX],int path[NMAX])
{
    int start,destination;
    printf("Nhap vao dinh bat dau (1-n)\n");
    scanf("%d",&start);
    printf("Nhap vao dinh den (1-n)\n");
    scanf("%d",&destination);

    if (start<1||start>n||destination<1||destination>n)
    {
        printf("Dinh nhap vao khong hop le \n");
        return;
        }

    dijkstra(start,destination,n,graph,path);
    return;
}
void primHandling(int n,int graph[NMAX][NMAX]){
    primMST(n,graph);
}
void printfHandling(int n,int graph[NMAX][NMAX])
{
    output(n,graph);
}
void functions(int n,int m,int graph[][NMAX],int deg[],int path[])
{
    int opt = -1;
    while (opt!=0)
    {
        printf("----------------------------------------------\n");
        printf("-              Chon chuc nang                -\n");
        printf("- 1 : Kiem tra do thi Euler                  -\n");
        printf("- 2 : Tim duong di ngan nhat                 -\n");
        printf("- 3 : Tim cay khung nho nhat                 -\n");
        printf("- 4 : In ra thong tin do thi                 -\n");
        printf("- 5 : nhap lai do thi                        -\n");
        printf("- 0 : Thoat chuong trinh                     -\n");
        printf("----------------------------------------------\n");
        printf("Chon chuc nang can thuc hien : ");
        scanf("%d",&opt);

        switch (opt)
        {
            case 1 : isEulerHandling(n,graph,deg);
            break;
            case 2 : dijkstraHandling(n,graph,path);
            break;
            case 3 : primHandling(n,graph);
            break;
            case 4 : printfHandling(n,graph);
            break;
            case 5 : input(n,m,graph,deg);
            break;
            default : opt = 0;


        }






    }




}
