#include <bits/stdc++.h>
#define N 200005
using namespace std;
// Problem : Max , Min , Sum , Xor on Intervals
class Segment_Tree{
    private:
    // creating segment tree array of size 4 * n
    int tree[4*N];
    public:
    // build will require three paramters : 
    // 1. index of node , 2. start of range it will cover and,
    // 3. end of range it will cover

    // always start with node 1 , it is preferrable but not 
    // neccessary
    void build(int node , int start ,int end,vector<int> &a){
        // base condition : start == end then whatever array values
        // that will corresponds to tree value
        if(start == end){
            tree[node] = a[start];
            return;
        }
        // take mid value and then build it for left and right
        // subtree
        int left = node * 2, right = left + 1;
        int mid = (start +  end) / 2;
        build(left , start , mid,a);
        build(right, mid + 1 , end,a);
        // store answer for current node
        tree[node] = tree[left] + tree[right];
    }

    // range query function 
    // parameters: 
    // 1. index of node , start of range it covers , end of range it covers, 
    // 3. l => start of query range and , r => end of query range
    int query(int node ,int start ,int end ,int l ,int r){
        // base conditions:
        // query range is completely oustide then return the required
        // for sum it is 0 , for max return INT_MIN and so on ...
        if( l > end || r < start) return INT_MIN;
        // if start == end then just return node
        if(start == end) return tree[node];
        // if query range lies completely inside then just return node
        if( l <= start && r >= end) return tree[node];
        // partial lies just find left right and then do required calculation
        int mid = (start + end) / 2;
        int left = query(node * 2 , start , mid , l , r);
        int right = query( ( node * 2 ) + 1 , mid + 1 , end , l , r);
        return max(left , right);
    }

    // Point update in segment tree
    // Parameters:
    // 1. index of node , 2. start of the range it covers 
    // 3. end of range it will covers , 4. position that has to be 
    // update , 5. value that is to be applied on that position

    void update(int node ,int start , int end, int pos, int val,vector<int> &a){
        // base condition :
        // start == end , then update direct node
        if(start == end){
            a[start] = val; tree[node] = val;
        }
        else{
            int mid = (start + end) / 2;
            // update the part in which pos lies
            if(pos >= start && pos <= mid) update(node * 2 , start , mid , pos , val,a);
            else update( (node * 2) + 1 , mid + 1 , end , pos, val,a);
            tree[node] = max( tree[node * 2] , tree[ ( node * 2 ) + 1]);   
        }
    }
};
int main(){
    return 0;
}

