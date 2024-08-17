/*

Binary Jumping :

Let suppose we want to reach 10th distance from 1

1-2-3-4-5-6-7-8-9-10-11-12-13-14

one way is to directly traverse it but it will take linear time O(N) 
for the query related problems we don't want linear time 
we can precompute the distances by binary jumps : 

So, 10th jump we want , 10 in binary form = 1010 => 8 + 2
we can go to 8th distance then the 8th distance then from there we can go to its 2nd distance. 

1->9->11

we can precompute all these binary jumps 

v -> node , j -> jth power of 2 
dp[v][0] = parent[v]
dp[v][1] = dp[dp[v][0]][0] // from 1 we want 2^1 = 2nd distance , we know the answer for 2nd - 1st parent , we can jump to 2nd 
dp[v][2] = dp[dp[v][1]][1];

....

dp[node][j] = parent[node] , if j == 0
dp[node][j] = dp[dp[node][j-1]][j-1] , if j > 0 

there are two way to implement in this , if ypu start iterating from nodes then make sure the order is correct 
always recommended to start iterating from jumps j

TC: O(N * LogN)

Application of Binary Jumping : 
- Sparse Table 
- Binary Lifting 

*/

void binary_jump(int n){
    for(int jumps = 0;jumps<32;jumps++){
        for(int node = 0;node<=n;i++){
            if(jumps == 0) dp[node][0] = parent[node];
            else dp[node][jump] = dp[dp[node][jump-1]][jump-1]; 
        }
    }
}