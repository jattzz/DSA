// Space Complexity => Auxillary Space + Input Space

// vector iterator can also be initialized as
// vector<int> v;
// vector<int>::iterator beginit = v.begin()
// or vector<int>::iterator endit = v.end() for the pointer to point at the end

// using this we can iterate the vector as

// for(vector<int>::iterator i = beginit; i<endit; i++){
    // cout<<*i<<endl;    
// }
// similarly we also have reverse iterators, just write v.rbegin() in place of v.begin() to use them

// very important, similar to rstrip and lstrip in python, in vectors also we can just make a subvector for a specified l and r value.

// vector<int> v;
// vector<int> copy_of_v(v.begin(), v.begin()+3)
// will create a subvector of the first 3 elements of the original vector.

// similarly we can use the erase function to erase a range from the vector.
// v.erase(v.begin(), v.end()) wil erase the entire vector

// v.clear()  removes all the elements.

// we can also use the v.begin() to insert an element at a specified position.

// LIST: another stl tool, similar to vector, but a very distinguishing property is list allows insertion at front, by just using l.emplace_front() or push_front()

// queue is also similar however a very important type of queue is... Priority queue and how it can be customised into being used as a min heap.

#include<bits/stdc++.h>
using namespace std;
void explainPQ(){
    priority_queue<int> pq;
    // this queue just stores the highest element at the front... acts like a max heap

    priority_queue<int, vector<int>, greater<int>> pq2; // This is very important and this acts like a min heap... it keeps the smallest element at the front.
}
void explainSet(){
    set<int> s;   //also keeps unique elements only in a sorted fashion
    s.insert(7);
    s.insert(3);
    s.insert(9);
    s.insert(2);
    s.insert(23);
    for(auto it: s){
        cout<<it<<" ";
    }
    auto it = s.find(2); // will return a pointer pointing at 2;
    cout<<endl<<*it<<endl;

    cout<<s.count(3)<<endl; // returns the no. of occurences, usually 1 since set only keeps unique elements

    // we also have lower bound and upper bound, both of them basically returns the first index greater than or smalled than the passed parameter.

    // we also have multisets, which allow duplicate elements

    // similarly, there's also unordered_set, which stores unique elements, but not in an sorted order.

    // similarly we can also use maps, and multimaps, there also exists a map.equal_range(x) function, which will just return a pair, where the first index stores the first index of the first key that is equal to x and the 2nd index stores the index of the second key that is equal to x. 
}
// int main(){
//     explainPQ();
//     explainSet();
// }

// we also have an accumulate function for arrays, which basically returns the sum of the array. syntax: sum = accumulate(arr, arr+n, 0);
// n is the size of the array, and 0 is the starting value of the sum, if we write 5 in place of 1, it wil return the sum of array + 5;

// basic program to return the no. of odd elements in an array
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n, no;
//     cin>>n;
//     int arr[n];
//     for(int i=0; i<n; i++){
//         cin>>arr[i];
//         arr[i]%=2;
//     }
//     no = count(arr, arr+n, 1);
//     cout<<no<<" "<<accumulate(arr, arr+n, 0)<<endl;
// }


// VERY IMP: NEXT PERMUTATION
// can be used in any linear DS, for eg string;
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         string s;
//         cin>>s;
//         do{
//             cout<<s<<endl;
//         }while(next_permutation(s.begin(), s.end()));
//     }
// }

// basically returns the next permutation of the string.
// also very imp; it only works in a sorted order fashion, if we give bac input, in place of abc, it will only print 3 permutations; bca, cab and cba;
// we also use this to permutate only a part of the string.
// in STL, we also have min_element(arr, arr+n) and max_element(arr, arr+n) functions to return the min and max element respectively.

// the sort function works by using an internal comparator, which tells him whether a should be before b or not for any pair a, b belonging to the array.

// we can modify the internal_comparator to sort an array in descending order also,

// bool internalComparator(int a, int b){
//     if(a<b){
//         return false;
//     }
//     else{
//         return true;
//     }
// }
// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int n; cin>>n;
//         int arr[n];
//         for(int i=0; i<n; i++){
//             cin>>arr[i];
//         }
//         sort(arr, arr+n, internalComparator);
//         for(auto i: arr){
//             cout<<i<<" ";
//         }
//     }
// }
// now at first, we might think that why would we write such a complex function to just sort in desceding order, when we can just pass greater<int> and it will do the same thing...
// This manipulation of internalComparator comes in handy when we want to sort an array of pairs, on the basis of the value of the second element, but if there are elements with same value of the second elements, then sort them in the reverse order based on their 1st element, meaning if the vector is going to be sorted in descending order based on 2nd elements, sort the "equal second element" cases in ascending order;

// bool internalComparator(pair<int, int> a, pair<int, int> b){
//     if(a.second>b.second){
//         return true;
//     }
//     if(a.second<b.second){
//         return false;
//     }
//     if(a.first<b.first){
//         return true;
//     }
//     else{
//         return false;
//     }
// }
// void explainOperator(){
//     pair<int , int> arr[] = {{1, 6}, {1, 5}, {2, 6}, {2, 9}, {3, 9}};
//     sort(arr, arr+5);
//     for(auto i: arr){
//         cout<<"{"<<i.first<<", "<<i.second<<"} ";
//     } // returns elements sorted on the basis of the first element
//     cout<<endl;
//     sort(arr, arr+5, internalComparator);
//     for(auto i: arr){
//         cout<<"{"<<i.first<<", "<<i.second<<"} ";
//     }
// }
// int main(){
//     explainOperator();
// }

// STRINGS: (strings are mutable in C++, but immutable in java and python)
// for some reason, in C++, string s = s + 'a' takes way more time compared to s += 'a';     so, an advice for competitive programming is, using the latter rather than the first one.

// bool isomorphicString(string s, string t) {
//     if(s.length()!=t.length()) return false;
//     map<char, char> m;
//     for(int i=0; i<s.length(); i++){                                => optimized code to find whether 2 strings are isomorphic, meaning they can 
//         if(m.find(s[i])==m.end()){                                     be made the same if we just replace one of them's characters.
//             m[s[i]] = t[i];
//         }
//         else{
//             if(m[s[i]]==t[i]){
//             continue;
//             }
//             else{
//                 return false;
//             }
//         }
//     }
//     return true;
// }

// bool rotateString(string& s,string& goal){
// 	    if(s.length()!=goal.length()) return false;
// 	    s += s;                                                      => optimized code to find whether a string can be rotated into becoming equal to some 
// 	    return s.find(goal)!=-1;                                        other string
// }



// Sorting characters of a string by frequency

// bool internalComparator(pair<char, int> a, pair<char, int> b){
//     	if(a.second>b.second){
//         	return true;
//     	}
//     	if(a.second<b.second){
//         	return false;
//     	}
//     	if(a.first<b.first){
//         	return true;
//     	}
//     	else{
//         	return false;
//     	}
// 	}
// 	vector<char> frequencySort(string& s){
// 		map<char, int> m;
// 		for(int i=0; i<s.length(); i++){
// 			m[s[i]]++;
// 		}
// 		vector<pair<char, int>> res;
// 		for(auto i: m){
// 			res.push_back(i);
// 		}
// 		sort(res.begin(), res.end(), internalComparator);
// 		vector<char> ans;
// 		for(auto i: res){
// 			ans.push_back(i.first);
// 		}
// 		return ans;
// 	}
//     int main(){
//         string chars = "abbsabcca";
//         vector<char> characters = frequencySort(chars);
//         for(auto i: characters){
//             cout<<i<<" ";
//         }
//     }



// Selection Sort: 
//  -> as the name suggests... we have to select... which element we have to select? => the smallest one.

// -> step 1: get the minimum, and insert it at the front of the array
// -> now since the minimum is at the first place... we can say that the the array till the 1st index is sorted
// -> hence, the next smallest element will be put next to the prev smallest element
// for n elements... we can sort the entire array in n-1 steps, appending the smallest element at the front in each step
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n; cin>>n;
//     int arr[n];
//     for(int i=0; i<n; i++){
//         cin>>arr[i];
//     }
//     for(int i=0; i<n-1; i++){
//         int min = i;
//         for(int j=i; j<n; j++){
//             if(arr[j]<arr[min]){
//                 min = j;
//             }
//         }
//         swap(arr[i], arr[min]);
//     }
//     for(int i=0; i<n; i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
// }
// time complexity of selection sort is O(n^2) in every case


// Bubble sort
// 1. pushes the max element to the last by comparing adjacent elements
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int t;
//     cin>>t;
//     int arr[t];
//     for(int i=0; i<t; i++){
//         cin>>arr[i];
//     }
//     for(int i=0; i<t; i++){
//         int sw = 0;
//         for(int j=0; j<t-i-1; j++){
//             if(arr[j]>arr[j+1]){
//                 swap(arr[j], arr[j+1]);
//                 sw = 1;
//             }
//         }
//         if(sw == 0){
//             break;
//         }
//     }
//     for(auto i: arr){
//         cout<<i<<" ";
//     }
//     cout<<endl;
// }
// since it just swaps the elements when the i+1th element is lesser than ith... and it does so n times... hence bringing the WC TC to O(n^2)
// worst case = avg case = O(n^2)
// Best case is O(n), which is when we use a variable to check whether there were any swaps.


// Insertion sort 
// takes an element and places it at its correct position
// selects an element and keeps switching it to the left until the left of the element is smaller than it. It kind of maintains a sorted array and keeps increasing its size by 1 at each iteration.
// worst case time complexity is when the entire array is sorted in descending order. Also the average case time complexity is O(n^2);
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0; i<n; i++){
//         cin>>arr[i];
//     }
//     for(int i=0; i<n; i++){
//         int j = i;
//         while(j>0 && arr[j-1]>arr[j]){
//             swap(arr[j-1], arr[j]);
//             j--;
//         }
//     }
//     for(auto i: arr){
//         cout<<i<<" ";
//     }
//     cout<<endl;
// }
// BC TC => O(n)      -> arr is sorted
// WC TC => O(n^2)    -> arr is in descending order
// AC TC => O(n^2)    


// Quick Sort 
// -> easily one of the most important sorting algorithms
// when we use the inbuilt sort function of algorithms library, it is sort function only that gets called in the backend.
// quick sort has the same TC as merge sort, but doesn't use any auxillary space (merge sort maintains an array), instead it uses recursive calls to sort the array, SC = O(1). It uses two pointers, namely low and high
// however, quicksort is not a stable sorting algorithm since it changes the relative indexing of the elements.
// Algo:
//  -> Pick a pivot element -> can be any element
//  -> place it in its correct position
//  -> in order to place an element at its correct position, what we have to do is put all the elements smaller than that element to its left, and all the elements greater than it to its right, hence at the end of the iteration, the element itself would be at the correct place.
//  -> initialize two pointers => low = 0; high = n-1
//  -> from low(or i), start iterating the array and stop at the first element greater than piot, at the same time, from high(or j), start reverse iterating and stop at the first element smaller than the pivot; now swap arr[i] and arr[j];
//  -> now repeat this step until i>j, if i is greater than j then, swap pivot and arr[j]
//  -> now since our pivot is at the correct position, the index of pivot is can be referred to as the partition index, since all the elements to the left are smaller than pivot and all the elements to right are greater than pivot.
//  -> let's say that the pivot is at index p, so now, all we have to do is to perform quick sort again on arr[0] to arr[p-1] and arr[p-1] to arr[n-1];
//  -> this is the recursive algo to sort the array.
// #include<bits/stdc++.h>
// using namespace std;
// int partition(vector<int> &arr, int low, int high){
//     int pivot = arr[low], i = low, j = high;
//     while(i<j){                            // this function is where all the magic happens, this is the function that determines the pindex for all the sent 
//         while(arr[i]<=pivot && i<high){    // subarrays
//             i++;
//         }
//         while(arr[j]>pivot && j>low){      // this function takes log(n) time to return the partition index
//             j--;
//         }
//         if(i<j){
//             swap(arr[i], arr[j]);
//         }
//     }
//     swap(arr[low], arr[j]);
//     return j;
// }
// void qs(vector<int> &arr, int low, int high){
//     if(low<high){                                 // this function calls the function to determine the partition index, and recursively calls itself to sort 
//         int pIndex = partition(arr, low, high);   // halves 0 to pindex and pindex to the last element, since this sorting algo also uses DnC technique, it  
//         qs(arr, low, pIndex-1);                   // keeps on dividing the array based on the new subarrays as per the partitions and returns the fully sorted 
//         qs(arr, pIndex+1, high);                  // array.
//     }                                             // this fucntion runs n times
// }
// vector<int> quickSort(vector<int> &arr){
//     qs(arr, 0, arr.size()-1);                     // nothing is happening in this function, we are just calling the function which actually sorts the array
//     return arr;
// }
// int main(){
//     int n, x;
//     cin>>n;
//     vector<int> v;
//     for(int i=0; i<n; i++){
//         cin>>x;
//         v.push_back(x);
//     }
//     v = quickSort(v);
//     for(auto i: v){
//         cout<<i<<" ";
//     }
//     cout<<endl;
// }
// TC:
//  -> Best case: O(nlog(n))
//  -> Avg case: O(nlog(n))
//  -> Worst case: O(n^2)


// Merge Sort
// Most important sorting algorithm, is easily the most optimized sorting algorithm that is stable.
// Divide and Conquer and Merge
// keeps dividing the array into subarrays until the subarrays are of length 1 (or) are atomic values.
// also uses two pointers to keep track of the starting and ending point of all the subarrays
// Algo;
// -> initialize arr, low, high
// -> determine the value of mid; (low+high/2);
// -> mergesort(arr, low, mid);
// -> mergesort(arr, mid+1, high);
// -> merge(arr, low, mid, high);
// #include<bits/stdc++.h>
// using namespace std;
// void merge(vector<int> &arr, int low, int mid, int high){
//     vector<int> temp;
//     int left = low, right = mid+1;
//     while(left<=mid && right<=high){
//         if(arr[left] <= arr[right]){
//             temp.push_back(arr[left]);
//             left++;
//         }
//         else{
//             temp.push_back(arr[right]);
//             right++;
//         }
//     }
//     while(left<=mid){
//         temp.push_back(arr[left]);
//         left++;
//     }
//     while(right<=high){
//         temp.push_back(arr[right]);
//         right++;
//     }
//     for(int i = low; i<=high; i++){
//         arr[i] = temp[i-low];
//     }
// }
// void ms(vector<int> &arr, int low, int high){
//     if(low == high){
//         return;
//     }                                       // this function is basically dividing the array into atomic values
//     int mid = (low+high)/2;
//     ms(arr, low, mid);
//     ms(arr, mid+1, high);
//     merge(arr, low, mid, high);
// }
// void mergeSort(vector<int> &arr, int n){
//     ms(arr, 0, n-1);
// }
// int main(){
//     int n, x;
//     cin>>n;
//     vector<int> arr;
//     for(int i=0; i<n; i++){
//         cin>>x;
//         arr.push_back(x);
//     }
//     mergeSort(arr, n);
//     for(auto i: arr){
//         cout<<i<<" ";
//     }
//     cout<<endl;
// }
// Time Complexity Analysis
// Best Case = Worst Case = Average Case = O(nlog(n));
// Space Complexity => O(n) => arbitary temp array in the merge function

// Pascal Triangle
// 3 types:
//     - Given row and column, return the element
//     - Given the nth row for input n
//     - Given n, print the entire triangle till nth row

// For type 1; there's a simple formula, that is, for any given value of r and c, the element at that position is equal to (r-1)C(c-1), where C is combination
// eg: 4C2 => 4!/(2!2!) => 6 which is the element at 5th row and 3rd column
//           1
//         1   1
//       1   2   1 
//     1   3   3   1
//   1   4  '6'  4   1
// hence, by just making a function to calculate the value of factorials, we can determine the element at the specified location
// however, this is just the brute force solution, a slightly optimised solution will be to optimize the Combination calculator
// nCr => is just n*(n-1)*(n-2)... r terms
// whereas the denominator will be just r*(r-1)*(r-2)...*1

// #include<bits/stdc++.h>
// using namespace std;                // VARIETY 1
// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int r, c, res=1; cin>>r>>c;          // this is still brute force btw
//         r--; c--;           // to fit into our formula of finding the element
//         for(int i=0; i<c; i++){
//             res*=(r-i);
//             res/=(i+1);
//         }
//         cout<<res<<endl;
//     }
// }

// VARIETY 2: return the nth row
// extreme brute force will be to determine each element of the row using the above method
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int n; cin>>n;
//         int cnt = n-1, deno = 1, mul = cnt, div = 1;
//         for(int i=0; i<n; i++){                        // this function works on the pattern that first and last element is always 1 and the next element is 
//             if(i==0 || i==n-1){                        // always (n-1)/1, and after that it is just... (n-1)*(n-2)/1*2 and so on till n-1... after which the
//                 cout<<1<<" ";                          // nth element is one again
//                 continue;
//             }
//             cout<<cnt/deno<<" ";
//             cnt*=(mul-1);
//             deno*=(div+1);
//             mul--;
//             div++;
//         }
//         cout<<endl;
//     }
// }                                            // TC => O(n) => where n is the no. of rows, and m is the variable length of each row

// #include<bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//     vector<int> rowcreater(int n){
//         vector<int> v;
//         int num = n-1, cnt = num, deno = 1, div = deno;
//         int res = num/deno;
//         for(int i=0; i<n; i++){
//             if(i==0 || i==(n-1)){
//                 v.push_back(1);
//                 continue;
//             }
//             v.push_back(res);
//             res *= (cnt-1);
//             res /= (div+1);
//             cnt--;
//             div++;
//         }
//         return v;
//     }
//     vector<vector<int>> pascalTriangle(int numRows) {
//         if(numRows==0){
//             return {{}};
//         }
//         else if(numRows==1){
//             return {{1}};
//         }
//         vector<vector<int>> res;
//         vector<int> temp;
//         for(int i=1; i<=numRows; i++){
//             temp = rowcreater(i);
//             res.push_back(temp);
//         }
//         return res;
//     }
// };
// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         Solution ob;
//         int n; cin>>n;
//         vector<vector<int>> ans = ob.pascalTriangle(n);
//         for(auto i: ans){
//             for(auto j: i){
//                 cout<<j<<" ";
//             }
//             cout<<endl;
//         }
//     }
// }

// 3 Sum => trying using 3 pointers => turns out it is wrong, since we wont be able to cover all the triplets of 3 elements.
// a better appraoch is to do it like 2 sum, where the third element is the target sum, this will take place in O((n^2)*log(m)), just store all the elements in the map. (where m is the no. of unique triplets)
// and for each pair of 2 elements look for their remainder in the map.
// Optimal => sort the vector, and then for each index i, start a variable l from i+1 and r from v.size()-1;
// for each index, start from the i, l, r, and calculate their sum.
// if sum<0 => l++;
// if sum>0 => r--;
// else push the triplets into the ans vector

// #include<bits/stdc++.h>
// using namespace std;
// vector<vector<int>> threesum(vector<int> v){
//     if(v.size()<3){
//         return {};
//     }
//     vector<vector<int>> ans;
//     sort(v.begin(), v.end());
//     for(int i=0; i<v.size()-2; i++){
//         if(i>0 && v[i]==v[i-1]){
//             continue;
//         }
//         int l, r;
//         l = i+1;
//         r = v.size()-1;
//         while(l<r){
//             int sum = v[i] + v[l] + v[r];
//             if(sum==0){
//                 ans.push_back({v[i], v[l++], v[r--]});
//                 while(l<r && v[l] == v[l-1]){
//                     l++;
//                 }
//                 while(l<r && v[r] == v[r+1]){
//                     r--;
//                 }
//             }
//             else{
//                 if(sum<0){
//                     l++;
//                 }
//                 else{
//                     r--;
//                 }
//             }
//         }
//     }
//     return ans;
// }
// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int n; cin>>n;
//         vector<int> v;
//         for(int i=0; i<n; i++){
//             int x; cin>>x;
//             v.push_back(x);
//         }
//         vector<vector<int>> res =  threesum(v);
//         for(auto i: res){
//             for(auto j: i){
//                 cout<<j<<" ";
//             }
//             cout<<endl;
//         }
//     }
// }

// 4 sum => med-hard
// Brute force => O(n^4) => ez 2 LPA
// Better approach => we can do it in O((n^3)*log(n)) where we will look for the ramainder in the hashset to see whether the 4th needed element is present in the set.
// we can solve it similar to 3 sum, where we will see whether target - (sum of 3 elements) is present in the hashset
// vector<vector<int>> fourSum(vector<int>& v, int target){  
//     int n = v.size();
//     set<vector<int>> st;
//     for(int i=0; i<n; i++){
//         for(int j=i+1; j<n; j++){
//             set<long long> hashset;
//             for(int k = j+1; k<n; k++){
//                 long long sum = v[i] + v[j];
//                 sum += v[k];
//                 long long fourth = target - sum;
//                 if(hashset.find(fourth)!=hashset.end()){
//                     vector<int> temp = {v[i], v[j], v[k], int(fourth)}; 
//                     sort(temp.begin(), temp.end());
//                     st.insert(temp);
//                 }
//                 hashset.insert(v[k]);
//             }
//         }
//     }
//     vector<vector<int>> res(st.begin(), st.end());
//     return res;
// }
// Optimal solution => the TC of the optimal solution is also O(n^3) however it does not have that extra logn multiplied to it, reducing its time complexity by a factor of log(n)
// we need to get rid of the extra data stuctures we used such as the set, where insertion occurs in O(logn), so in order to counter it, we'll just sort our array first.
// [ 1, 2, 3, 4, 5, 6, 7, 8]
//   i  j  k              l 
// and now we apply the same logic as before, iterate through the array based on the value of the sum and target, and move on to the elements with different data values
// vector<vector<int>> fourSum(vector<int>& v, int target){
//     int n = v.size();
//     sort(v.begin(), v.end());
//     vector<vector<int>> res;
//     for (int i=0; i<n; i++){
//         if(i>0 && v[i]==v[i-1]){
//             continue;
//         }
//         for(int j = i+1; j<n; j++){
//             if(j>(i+1) && v[j]==v[j-1]){
//                 continue;
//             }
//             int k = j+1, l = n-1;
//             while(k<l){
//                 long long sum = v[i];
//                 sum += v[j];                 // the thing is, that we have a vector of int datatype, hence if we write v[i] + v[j] + v[k] + v[l] in one line
//                 sum += v[k];                 // only, then there's a chance that it will cross the int limit, and garbage value will be assigned to sum.
//                 sum += v[l];
//                 if(sum == target){
//                     vector<int> temp = {v[i], v[j], v[k], v[l]};
//                     res.push_back(temp);
//                     k++;
//                     l--;
//                     while(k<l && v[k]==v[k-1]){
//                         k++;
//                     }
//                     while(k<l && v[l]==v[l+1]){
//                         l--;
//                     }
//                 }
//                 else if(sum < target){
//                     k++;
//                 }
//                 else{
//                     l--;
//                 }
//             }
//         }
//     }
//     return res;                       // since, the vector of vectors was used only to store the results, not to solve the problem, we can say that from a
// }                                     // perspective, the space complexity is O(1)

// Kadane's Algorithm (Max sum subrarray in O(n))
// #include<bits/stdc++.h>
// using namespace std;
// vector<int> maxSubArray(vector<int>& nums) {
//     int sum = 0, maxsum = INT_MIN;
//     int start, anstart, ansend;
//     vector<int> res;
//     for(int i=0; i<nums.size(); i++){
//         if(sum==0){
//             start = i;
//         }
//         sum += nums[i];
//         if(sum>maxsum){
//             anstart = start;
//             ansend = i;
//             maxsum = sum;
//         }
//         if(sum<0){
//             sum = 0;
//         }
//     }
//     res.push_back(maxsum);
//     for(int i = anstart; i<=ansend; i++){
//         res.push_back(nums[i]);
//     }
//     return res;
// }
// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int n, x; cin>>n;
//         vector<int> v;
//         vector<int> ans;
//         for(int i=0; i<n; i++){
//             cin>>x;
//             v.push_back(x);
//         }
//         ans = maxSubArray(v);
//         for(int i=0; i<ans.size(); i++){
//             if(i==0){
//                 cout<<"MaxSum = "<<ans[i]<<endl;
//                 cout<<"SubArray: ";
//             }
//             else{
//                 cout<<ans[i]<<" ";
//             }
//         }
//         cout<<endl<<endl;
//     }
// }


// Moore's Voting System
// used for finding majority element (occurs more than n/2 times)
// 1st approach => HashMap => O(n) TC, O(n) SC
// 2nd approach => Moore's Voting System => O(n) TC, O(1) SC
// initialize a count variable and a el variable, and if the next element is same, increment cnt, whereas if the next element is different, decrement the cnt, if at any point cnt<0, change the el to the current element
// int majorityElement(vector<int>& nums) {
//     int cnt = 0, el = nums[0];
//     for(int i=0; i<nums.size(); i++){
//         if(nums[i]==el){
//             cnt++;
//         }
//         else{
//             cnt--;
//         }
//         if(cnt<0){
//             el = nums[i];
//             cnt = 0;
//         }
//     }
//     return el;
// }

// Majority Element II:
// return all the elements that occur more than n/3 times, in an array of size of n;
// on closer observation we can see that the array will have a max. of 2 elements only that occur more than n/3 times.
// 2 solutions:
//        1. decent solution => using hashmap => O(n) TC, O(n) SC
//        2. optimal solution => almost the same as majority element I, we just have to take into account 2 count variables.
// vector<int> majorityElementTwo(vector<int>& nums) {
//     int cnt1 = 0, cnt2 = 0;
//     int el1 = INT_MIN, el2 = INT_MIN;
//     for(int i=0; i<nums.size(); i++){
//         if(cnt1<=0 && el2!=nums[i]){
//             cnt1++;
//             el1 = nums[i];
//         }
//         else if(cnt2<=0 && el1!=nums[i]){
//             cnt2++;
//             el2 = nums[i];
//         }
//         else if(el1==nums[i]){
//             cnt1++;
//         }
//         else if(el2==nums[i]){
//             cnt2++;
//         }
//         else{
//             cnt1--;
//             cnt2--;
//         }
//     }
//     vector<int> res;
//     cnt1 = 0, cnt2 = 0;
//     for(int i=0; i<nums.size(); i++){
//         if(el1==nums[i]){
//             cnt1++;
//         }
//         if(el2==nums[i]){
//             cnt2++;
//         }
//     }
//     if(cnt1>(nums.size()/3)){
//         res.push_back(el1);
//     }
//     if(cnt2>(nums.size()/3)){
//         res.push_back(el2);
//     }
//     if(el1>el2 && res.size()==2){
//         swap(res[0], res[1]);
//     }
//     return res;
// }

// Find the missing and repeating numbers
// 2 optimal solutions; 
//         1. maths
//         2. XOR (very complex)
// 1. Using maths; let x be the repeating no., and y be the missing no.
//                   - now take the sum of the elements in the array, and sum of first n natural no.s
//                   - their difference will be the difference between missing no. and the repeating no.  
//                   - now take the sum of square of the elements in the array and the sum of first n squares
//                   - now their difference will give the difference between x^2 and y^2
//   So, now we have to equations, one for x-y, and one for x^2-y^2, which is equal to (x+y)(x-y)... dividing them will give us x+y;
//   Now, we have two elements and two equations, so we can find the values of x and y easily through substituion

// Hard => Reverse Pair
// uses the skeleton of merge sort since it compares all the elementes in O(nlogn) TC, the code is as follows.

// Hard => Subarray with Max Product
// actually falls around easy to medium
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define vi vector<int> 
// #define vll vector<long long>
// #define pii pair<int, int> 
// #define pic pair<int, char> 
// #define mii map<int, int> 
// #define pb push_back
// #define mp make_pair
// #define sortv(v) sort(v.begin(), v.end())
// #define sumup(v) accumulate(v.begin(), v.end(), 0)

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int t; cin>>t;
//     while(t--){
//         int n; cin>>n;
//         vi v(n);
//         for(auto &i: v){
//             cin>>i;
//         }
//         long long suff = 1, pre = 1, res;
//         for(int i=0; i<n; i++){
//             if(!suff) suff = 1;
//             if(!pre) pre = 1;
//             pre *= v[i];
//             suff *= v[n-1-i];
//             res = max(res, max(pre, suff));
//         }
//         return res;
//     }
// }
// for each index, the answer will either be its prefix or its suffix
// ans in case of encountering 0, the next index will start afresh from 1;


// Binary Search
// basically searches for an element in the sorted array in logn time complexity
// uses 3 variables, low, mid, and high
// pseudu code: (using iterations)
// int targetIndex(vector<int> v, int n, int target){
//     int low = 0, high = n-1;
//     while(low<=high){
//         int mid = (low+high)/2;
//         if(v[mid]==target) return mid;
//         else if(target>v[mid]) low = mid+1;
//         else high = mid-1;
//     }
//     return -1;                 // if the target was never found in the vector, it means it is not present in the vector, hence returning -1;
// }

// (using recursion)  => used when we have to perform the same task repeatedly.
// int targetIndexUsingRecursion(vector<int> v, int low, int high, int target){                    // uses the low and high parameters instead of n);
//     if(low>high) return -1;
//     int mid = (low+high)/2;
//     if(v[mid]==target) return mid;
//     else if(target>v[mid]) targetIndexUsingRecursion(v, mid+1, high, target);
//     else targetIndexUsingRecursion(v, low, mid-1, target);
// }
// Overflow case => if the datatype of mid is int, and the value of high is INT_MAX, then in the process of assigning (low+high)/2 to the mid variable, we will face int_overflow, in order to avoid that, we can instead write mid = low + (high-low)/2... the reason this works is because on taking common denominator out eqn will look like mid = (2*low + high - low)/2... which is just (low+high)/2;

// Lower Bound; returns the first element that is greater or equal to the given element;
// int lowerBound(vector<int> v, int target){
//     int low = 0, high = v.size()-1;
//     int res = v.size();
//     while(low<=high){
//         int mid = (low+high)/2;
//         if(v[mid]>=target){
//             res = mid;
//             high = mid-1; 
//         }
//         else{
//             low = mid+1;
//         }
//         return res;
//     }
// }

// Upper Bound; returns the first element that is greater than the given element;
// int upperBound(vector<int> v, int target){
//     int low = 0, high = v.size()-1;
//     int res = v.size();
//     while(low<=high){
//         int mid = (low+high)/2;
//         if(v[mid]<target){
//             res = mid;
//             high = mid-1; 
//         }
//         else{
//             low = mid+1;
//         }
//         return res;
//     }
// }

// Smallest sum of divisor
// basically you are given a threshold and you have to return the element(divisor) which when used to divide the elements, leaves a sum greater than or equal to the threshold value.

// int sumofdivided(vector<int> &nums, int div){
// int sum = 0;
// for(int i=0; i<nums.size(); i++){
//     sum += ceil((double)(nums[i])/(double)(div));
// }
// return sum;    
// }
// int smallestDivisor(vector<int> &nums, int limit) {
// int low = 1, high = *max_element(nums.begin(), nums.end());
// while(low<=high){
//     int mid = (low + high)/2;                                    // done using binary search
//     if(sumofdivided(nums, mid) <= limit){
//     high = mid-1;
//     }
//     else{
//     low = mid+1;
//     }
// }
// return low;
// }

// Koko eating banana
// you are given an array, where at each index, some bananas are present, and you are given h hrs to finish all of them, now you have to determine the minimum no. of bananas you have to eat in order to finish all of them within the time constraint.
// int possibilityCheck(vector<int> nums, int k){
//     int cnt = 0;
//     for(int i=0; i<nums.size(); i++){
//         cnt += ceil((double)(nums[i])/(double)(k));
//     }
//     return cnt;
// }
// int minimumRateToEatBananas(vector<int> nums, int h) {
//     int n = nums.size();
//     int low = 1, high = *max_element(nums.begin(), nums.end());
//     while(low<=high){
//         int mid = (low + high)/2;
//         int hrs = possibilityCheck(nums, mid);
//         if(hrs <= h){
//             high = mid - 1;
//         }
//         else{
//             low = mid + 1;
//         }
//     }
//     return low;
// }


// Aggressive Cows:
// Just create a function that checks whether it is possible to place cows at a distance that is greater than or equal to some specified integer x. Iterating through the entire range will leave us with the max possible value of x, which will be out answer.

// class Solution {
// public:
//     bool possibilityCheck(vector<int> nums, int k, int x){
//         int cnt = 1;
//         int prev = nums[0];
//         for(int i=1; i<nums.size(); i++){
//             if((nums[i]-prev)>=x){
//                 cnt++;
//                 prev = nums[i];
//             }
//         }
//         return cnt >= k;
//     }
//     int aggressiveCows(vector<int> &nums, int k) {
//         sort(nums.begin(), nums.end());
//         int low = 1, high = *max_element(nums.begin(), nums.end()) - *min_element(nums.begin(), nums.end());
//         int res = 0;
//         while(low <= high){
//             int mid = (low + high)/2;
//             if(possibilityCheck(nums, k, mid)){
//                 res = max(res, mid);
//                 low = mid+1;
//             }
//             else{
//                 high = mid-1;
//             }
//         }
//         return res;
//     }
// };


// Book Allocation System
// is easily one of the most difficult questions to solve with binary search. The approach is to apply BS over x from (highest element) to the total sum, where the x determines the no. of pages a student can hold (at max). Create a function to determine the no. of students required, and in case the required student's strength is more than the no. of students we have, we eliminate the left half, since it will be more than that for all those elements too. Similarly, if the required is equal or more importantly "less than", we eliminate the right half.

// class Solution {
// public:
//     int StudentCount(vector<int> nums, int k){
//         int students = 1;
//         int PagesPerStudent = 0;
//         for(int i = 0; i<nums.size(); i++){
//             if(PagesPerStudent + nums[i] <= k){
//                 PagesPerStudent += nums[i];
//             }
//             else{
//                 students++;
//                 PagesPerStudent = nums[i];
//             }
//         }
//         return students;
//     }
//     int findPages(vector<int> &nums, int m)  {
//         if(m>nums.size()){
//             return -1;
//         }
//         int low = *max_element(nums.begin(), nums.end());
//         int high = accumulate(nums.begin(), nums.end(), 0);
//         while(low<=high){
//             int mid = (low + high)/2;
//             int temp = StudentCount(nums, mid);
//             if(temp > m){
//                 low = mid + 1;
//             }
//             else{
//                 high = mid - 1;
//             }
//         }
//         return low;
//     }
// };


