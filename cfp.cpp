
// IMPORTANT MATHS CONCEPTS

// Sieve of Eratosthenes
// #include <bits/stdc++.h>
// using namespace std;
// void SieveOfEratosthenes(int n){
//     bool prime[n + 1];
//     memset(prime, true, sizeof(prime)); 
//     for(int p=2; p*p<=n; p++){
//         if(prime[p]==true){
//             for(int i=p*p; i<=n; i+=p){
//                 prime[i] = false;
//             }
//         }
//     }
//     for(int p=2; p<=n; p++){
//         if(prime[p]){
//             cout<<p<<" ";
//         }
//     }
// }
// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int n;
//         cin>>n;
//         SieveOfEratosthenes(n);

//     }
// }
// basically initialize ana array of size of n where all elements are initially marked prime, then you start iterating the array from index 2, and the moment you see that 2 is marked prime, you mark all of its multiples to be non-primes. Similarly we do the same for the next no. marked prime, and so on till we have reached sqrt(n).
// This method of finding prime has the least time complexity out of all the methods that we have for finding primes.
//  TC = O(n(log(log(n)))) => almost linear


// GCD => Euclidean Algorithm
// #include<bits/stdc++.h>
// using namespace std;
// int gcd(int a, int b){
//     if(a==0){
//         return b;
//     }
//     else{
//         return gcd(b%a, a);
//     }
// }
// int main(){
//     int a, b;
//     cin>>a>>b;
//     cout<<gcd(a, b)<<endl;
// }
// TC => log(max(a, b))
// exists as a prebuilt function already in c++... just use "__gcd(a, b)"



// Modular arithmetic
// most common = 1e9+7
// (a+b)%m = ((a%m)+(b%m))%m
// (a*b)%m = ((a%m)*(b%m))%m
// (a-b)%m = ((a%m)-(b%m)+m)%m    => so that the result is not -ve

// This is called Binary Exponentiation (or) BinPow()
// O(log(b))

// #include<bits/stdc++.h>
// using namespace std;
// int pw(int a, int b, int m){
//     if(b==0){
//         return 1%m;
//     }
//     if(b%2==0){
//         int t = pw(a, b/2, m);
//         return (1ll*t*t%m);
//     }
//     else{
//         int t = pw(a, (b-1)/2, m);
//         t = (1ll*t*t)%m;
//         return (1ll*a*t%m);
//     }
// }
// int main(){
//     int a, b, m;
//     cin>>a>>b>>m;
//     cout<<pw(a, b, m)<<endl;
// }

// VERY IMP: (a/b)%m
// We can't simply proceed with finding the modulo like we did for other arithmetics. Eg(6/2)%5 and see for yourself.
// This one requires Multiplicative Inverse
// Multiplicative inverse => MI of 5 is 1/5 for mod 1
// MI changes with modulo value. Since we cannot have decimal values for specific modulos, we use some other integer as the MI.
// Eg: 2%5; in order to make 2%5 equal to 1, we will multiply 2 by  
//          3, resulting in 6, and 6%5 = 1;
// In order to find the multiplicative inverse of b for mod m, there exists 1 condition;
            // gcd(b, m) = 1
            // basically they have to be coprimes, which is why we use 1e9+7 since it is prime.
            // if gcd(b,m) = 1, then MI of b for mod m is equal to 
            // b^(m-2)%m, which can be found in O(logn) time.
            // This is called the "Fermat's Little Theorem" for finding multiplicative inverse.


// Combinatorics:
// usually comes with modulo arithmetic


// STL
// Vectors
// vector<int> v;               => initializes an empty vector
// vector<int> v(10);           => 10 elements, all 0 (not specified)
// vector<int> v(10, h);        => 10 elements, all h

// v.push_back(x)      => inserts x
// v.emplace_back(x)   => sinserts x, but before inserting, it increases the size of the vector by 1.
// v.pop_back()        => removes the last element
// v.clear()           => truncates the entire vector
// v.size()            => returns the size of the vector
// sort(v.begin(), v.end())    => sorts the vector in O(nlogn)

// we use curvy brackets instead of square while initializing vectors, using square brackets instead results into something completely different

// vector<int> v[10]      => is actually an array of 10 vectors
// however for indexing we use square brackets.

// create a vector of n elements, and print all their even elements in one line and odd elements in another line in sorted order.
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int n;
//         cin>>n;
//         vector<int> v(n);
//         for(int i=0; i<n; i++){
//             cin>>v[i];
//         }
//         sort(v.begin(), v.end());
//         for(int i=0; i<n; i++){
//             if(v[i]%2==0){
//                 cout<<v[i]<<" ";
//             }
//         }
//         cout<<endl;
//         for(int i=0; i<n; i++){
//             if(v[i]%2!=0){
//                 cout<<v[i]<<" ";
//             }
//         }
//     }
// }

// Also in strings, we use something similar to vector sort
// sort(s.begin(), s.end())   => is used to sort strings

// Pairs
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int x;
//     string s;
//     pair<int, string> v[5];  // this is how we make an array of pairs
//     for(int i=0; i<5; i++){
//         cin>>x>>s;
//         v[i].first = x;
//         v[i].second = s;
//     }
//     sort(v, v+5);   // sorted acc to the first element, if 1st element is equal then it looks for the second value.
//     for(int i=0; i<5; i++){
//         cout<<v[i].first<<" "<<v[i].second<<" ";
//     }
// }
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     vector<pair<int, string>> v;
//     sort(v.begin(), v.end());
// }

// Iterators: very similar to pointers
// auto it = v.begin();
// cout<<*it;      will print the first element
// it++;           will print the next element


// Set => is a container which keeps a unique copy of every element in sorted order.
// set<int> s;         will create an empty set of integers
// set<string> s;      will create an empty set of strings
// s.insert(x)     is used to insert element x
// s.erase(x)      is used to remove element x
// s.count(x)      counts the occurences of x in the set, usually only 1 or 0
// s.clear()     truncates all of the set
// s.size()      returns the size
// SETS DO NOT SUPPORT RANDOM ACCESS
// so using square brackets to access them will not work
// can only be traversed using iterators
// auto it = s.begin() will create an iterator pointing to the first element, also only it++, ++it, it--, and --it is allowed, you can't just write it+=5, since after each change in it, the set rearranges itself.

// s.find(x)    => returns an iterator poiting to x
// s.lower_bound(x)   => returns an iterator pointing to the first element >= x
// s.upper_bound(x)   => returns an iterator pointing to the first element <x
// s.end()    => just points to a non existing element, that is the element next to the last element
// s.erase(it)  => removes the element that the it is pointing at

// MAP
// its like a very special array, in which the indices of the elements can be negative, or very big or even strings.
// map<key_datatype, value_datatype> m;
// map<string, int> m   => creates a map in which keys are strings

// m["Jatin"] = 1;
// m["Kumar"] = 2;
// cout<<m["Jatin"];    => will return 1;
// In maps also the keys are unique and sorted

// Eg problem => Div 2->C btw :)
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int t;
//     cin>>t;
//     map<string, int> m;
//     while(t--){
//         string s;
//         cin>>s;
//         m[s]++;
//         if(m[s]==1){
//             cout<<"OK"<<endl;
//         }
//         else{
//             cout<<s<<m[s]-1<<endl;
//         }
//     }
// }

// Shorthand iterators
// 1. vectors   => for(int x: v){
// 
//                 }
// 2. sets      => for(int x: s){
// 
//                 }
// 3. maps      => for(pair<int, int> x: s){
// 
//                 }

// arrays are always passed as reference




// Suffix Array for Strings (Very high level stuff)

// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define vi vector<int> 
// #define vll vector<long long>
// #define pii pair<int, int> 
// #define pic pair<int, char> 
// #define mii map<int, int> 
// #define mll map<long long, long long>
// #define pb push_back
// #define mp make_pair
// #define sortv(v) sort(v.begin(), v.end())
// #define sumup(v) accumulate(v.begin(), v.end(), 0)
// #define ull unsigned long long int
// #define bs binary_search
// #define lb lower_bound
// #define ub upper_bound
// ll power(ll x, ull y){
//     if(y==0){
//         return 1;
//     }
//     ll temp = power(x, y/2);
//     if(y%2==0){
//         return temp*temp;
//     }
//     else{
//         return x*temp*temp;
//     }
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
    
//     string s; cin>>s;
//     s += "$";
//     int n = s.size();
//     vector<int> p(n), c(n);
//     {
//         vector<pair<char, int>> a(n);
//         for(int i=0; i<n; i++){
//             a[i] = {s[i], i};
//         }
//         sort(a.begin(), a.end());
//         for(int i=0; i<n; i++){
//             p[i] = a[i].second;
//         }
//         c[p[0]] = 0;
//         for(int i=1; i<n; i++){
//             if(a[i].first == a[i-1].first){
//                 c[p[i]] = c[p[i-1]];
//             }
//             else{
//                 c[p[i]] = c[p[i-1]]+1;
//             }
//         }
//     }
    
//     int k = 0;
//     while((1<<k)<n){
//         vector<pair<pair<int, int>, int>> a(n);
//         for(int i=0; i<n; i++){
//             a[i] = {{c[i], c[(i+(1<<k))%n]}, i};
//         }
//         k++;
//         sort(a.begin(), a.end());
//         for(int i=0; i<n; i++){
//             p[i] = a[i].second;
//         }
//         c[p[0]] = 0;
//         for(int i=1; i<n; i++){
//             if(a[i].first == a[i-1].first){
//                 c[p[i]] = c[p[i-1]];
//             }
//             else{
//                 c[p[i]] = c[p[i-1]]+1;
//             }
//         }
//     }

//     for(int i=0; i<n; i++){
//         cout<<p[i]<<" "<<s.substr(p[i], n-p[i])<<endl;
//     }
// }

// learnt that (1<<x) => 2^x in c++;
// also suffix array for strings are very useful for a variety of high level problems.


// Fibonacci Series using dp...
// brings TC from 2^n to n;

// ll cache[50];
// ll f(ll n){
//     if(n<2) return n;
//     if(cache[n] != -1) return cache[n];
//     cache[n] = f(n-1) + f(n-2);
//     return cache[n];
// }
// this is memoization; also called recursive dp (it is top down)

// we can also just start finding the values of f(0) all the way to f(n) whilst storing the intermediate results. This is called iterative dp. (it is bottom up)
// eg code for iterative is as follows:
// ll fnc(ll n){
//     ll f[50];
//     f[0] = 0;
//     f[1] = 1;
//     for(int i=2; i<=n; i++){
//        f[i] = f[i-1] + f[i-2]; 
//     }
//     return f[n];
// }



// Bitwise operators

// (x & 1) => compares the least significant bit, and tells the parity of 'x' in O(1) time (much faster than (x%2))

// all the powers of 2 when written in binary form, contains only 1 set bit (ie 1), and all others are just 0s... also the 1 is not the least significant bit.
// eg: x = 01000 => 8
// lets do (x-1) => 00111 => 7
// now we'll do (x & x(x-1))... if it is equal to 0, which it is in this case, then the original no. x is a power of 2.
// hence we can also check whether a number is a power of 2, in O(1), rather than using log() operation, which is much slower.
// edge case is when x = 0, which we can just handle in if statement.

// we can also check whether the kth bit is set or not, by
// (x & (1<<k))

// we can also toggle the kth bit, 1 to 0 and 0 to 1, by
// (x ^ (1<<k))

// Now that we know whether kth bit is set, and how to toggle it, we can also intentionally set or unset the kth bit.
// set;   (x | (1<<k))
// unset; (x & (n(1<<k)));  where n() is used to denote not operation

// Multiplying or Dividing a number by 2^k
// when we divide a number by k power of 2, what happens in binary form is that k bits from the right are discared. 
// eg: 10 => 1010 => 101, 0
//        => 101 => 5
//      9 => 1001 => 100, 1
//        => 100 => 4
// hence, for dividing by powers of 2, we can say that k bits from the right are shifted... 
// hence, for dividing x by 2^k, we can just write => (x>>k)
// and similarly, multiplying x by 2^k, can be written as (x<<k)

// Modulo 2^k
// we can find the modulo 2^k of a number x, by 
// (x & (1<<k - 1))
// which is nothing but (x & (2^k - 1))
// this also works in O(1)

// if we have a case where we have to swap the value of x in the following manner:
// x = b, if x==a;
// & x = a, if x==b;
// then we can do that in just one line using bitwise ops.
// x = a^b^x;
// ie because x^x is equal to 0;

// finding the total no. of set bits in a number x in O(1)
// __builtin_popcount(x) => for int
// __builtin_popcountll(x) => for ll