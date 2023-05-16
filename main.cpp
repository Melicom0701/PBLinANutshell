#include <iostream>
#include "my_functions.h"

int main() {
    int graph[NMAX][NMAX];
    int path[NMAX];
    int n,m;
    int deg[NMAX];
    //more input options pleaseee
    input(n,m,graph,deg);
    output(n,graph);
    dijkstra(0,3,n,graph,path);
//    if (check_euler_graph(n,graph,deg))
//    printf("Do thi tren co chu trinh Euler\n");
//    else printf("Do thi tren khong co chu trinh Euler\n");
    primMST(n,graph);
    return 0;
}
