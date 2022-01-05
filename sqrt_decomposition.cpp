// sqrt decomposition
// why to use ? 
// we can answer query like sum range , max , min etc..
// time complexity for each query answering will be sqrt(n)
// it requires preprocessing that will cost O(n) time complexity
// therefore overall time complexity : O(N) + O(Q * sqrt(N)) 

// Example: finding a minimum element for a given range
// arr : 1 2 3 5 6 1 2 
// create separate array of size = ceil ( sqrt( size_of_array ) )
// here , size_of_sqrt_array_ = len = ceil( sqrt(7) ) = 3 , for each index of arr , store min according to below relation:
// sqrt_arr[i] = arr[i / len]
// sqrt_arr[0] = min({1 , 2 , 3}) = 1 , 
// sqrt_arr[1] = min({5 , 6 , 1}) = 1 ,
// sqrt_arr[2] = 2,
// sqrt_arr : 1 1 2
// answer for query range of (1 , 6)
// find answer from by iterating from index 1 to 2 , then pickup the answer from sqrt_arr of index 1
// then again iterate from index 6 , to get final answer 

// code
int sqrt_decomposition(int q , vector<int> arr){
    int n = arr.size();
    int len = ceil ( double (sqrt(n)) );
    int sqrt_arr[len];
    for(int i = 0;i<len;i++) sqrt_arr[i] = 1e9;
    for(int i = 0;i<n;i++){
        int ind = i / len;
        sqrt_arr[ind] = min(sqrt_arr[ind] , arr[i]);
    } 
    while(q--){
        int l , r; cin>>l>>r;
        int start = l;
        int ans = 1e9;
        while(start <= r){
            if(start % len == 0){
                int end = start + len - 1;
                if(end <= r){
                    int ind = start / len;
                    ans = min(ans, sqrt_arr[ind]);
                    start = end + 1;
                }
                else{
                    ans = min(ans, arr[start]);
                    start++;
                }
            }
            else{
                ans = min(ans , arr[start]);
                start++;
            }
        }  
        cout << ans << "\n"; 
    }
}
