
// fenwick tree / binary indexed tree
// used in range query 
// create a fenwick array and it stores information
// till its first set bit
// for finding answer for particular index keep on subtracting the
// index with its bitwise and between its 2's complement and the bit
// for updating (point update) , keep on adding the index with its
// its bitwise and between its 2's complement and the bit

int BIT[100005];
int query(int l ,int r){
    return prefix(r) - prefix(l-1); 
}
int prefix(int idx){
    int sum = 0;
    while(idx > 0){
        sum += BIT[idx];
        idx -= (idx & -idx) 
        // -idx gives 2's complement and
        // (idx & -idx) gives a binary number with only lsb of idx
    }
    return sum;
}
void update(int idx, int len,int val){
    while(idx < len){
        BIT[idx] += val;
        idx += (idx & -idx);
    }
}
void preprocessing(vector<int> a){
    // can be done better with the help of prefix sums
    for(int i = 0;i<arr.size();i++){
        update(i,n,arr[i]);
    }
}
