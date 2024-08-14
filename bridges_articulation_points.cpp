/*

Bridge -> removing an edge from a grpah disconnects the graph , then that edge is called as bridge 
Articulation points -> All such vertex which removal can disconnects the grpah 

-> Trajan's Algorithm is well known for this , but not intuitive, instead dfs tree seems to be better way 

Select a particular node as a root & then create a dfs tree 
-> there can be two types of edges , 
-> direct edge between u & v -> span edge 
-> back edges , for the edge u -> v , v has some edge connecting to ancestor of u 

Observations : 
-> all the back edges are always connect with its descendant
-> back edge can never be the bridge 
-> span edge can be bridge if there is no back edge connecting the descendant of (u - v) to ancestors of (u - v)

we can use dp for each node to track the no of back edges connecting to ancestors 

dp[node] = #back edge connecting to ancestor - #back edge connecting to descendants + sum(dp[child_node]);

*/

int dp[20005], level[20005];
// Make sure to make level of start node 0
void isBridge(int x, int y){
    // process as per requirement
}

void dfs(int node, int par){
    dp[node] = 0;
    for(auto child : adj[node]){
        if(level[child] == 0){
            level[child] = level[node] + 1;
            dfs(child, node);
            dp[node] += dp[child];
        }
        else if(level[child] < level[node]){
            // upward edge 
            dp[node]++;
        }
        else if(level[child] > level[node]){
            // downward edge
            dp[node]--;
        }
    } 

    // have to remove parent edge as it is not backward edge 
    dp[node]--;

    if(level[node] > 1 && dp[node] == 0){
        isBridge(par, node);
    }
}