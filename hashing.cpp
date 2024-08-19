/*

Hashing :

Suppose we have a set S : {a,b,c} -> {a, b , c are integers or can be converted to integer}

Then,

poynomial hash : 

S = a + bx + cx^2 , we take x as a prime number greater than current numbers 
S1 =  c + bx + ax^2 , along with that we generally take modulo M;

Hash value of S & S1 will not be same , so in polynomial hash order matters 


set hash :

S = (a + k)^h + (b + k)^h + (c + k)^h 
S1 = (c + k)^h + (b + k)^h + (a + k)^h

k & h , take larger number prime preferrable , along with that we generally take modulo M;

when we expnad this equations these are ultimately polynomial hash , but in this hash irrespective of order 
hash function give same value 

xor hash : 

s = (a + k) ^ (b + k) ^ (c + k);
s1 = (c + k) ^ (b + k) ^ (a + k);


k take larger number prime preferrable , don't take modulo in this case , as we are dealing with bits here 
in this hash irrespective of order hash function give same value 

Note : always prefer double hash , take 2 diff. variable values & calculate hash 2 times for single set & compare 2 times 


Problem : https://atcoder.jp/contests/abc367/tasks/abc367_f

*/

const ll mod = 1e9 + 7;
const ll k = 1e9 + 9;
const ll h = 5;

ll binpow(ll x, ll n){
    if(n == 0) return 1;
    if(n == 1) return x;
    ll u = binpow(x , n / 2) % mod;
    ll res = u * u; res %= mod;
    if(n % 2 != 0) res = res * x;
    return res % mod; 
}

void set_hash(){
    ll n,q; cin>>n>>q;
    vector<ll> a(n+1), b(n+1);
    for(ll i = 0;i<n;i++) cin>>a[i];
    for(ll i = 0;i<n;i++) cin>>b[i];
    
    vector<ll> hash1(n), hash2(n);

    for(ll i = 0;i<n;i++){
        hash1[i] = binpow((a[i] + k),5) % mod;
        if(i - 1 >= 0) hash1[i] += hash1[i-1]; 
    }

    for(ll i = 0;i<n;i++){
        hash2[i] = binpow((b[i] + k),5) % mod;
        if(i - 1 >= 0) hash2[i] += hash2[i-1]; 
    }

    // you can check for ranges if they have same hash or not 
}