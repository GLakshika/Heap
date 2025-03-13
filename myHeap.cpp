#include<iostream>
#include<vector>
#include<sstream>

using namespace std;
void Max_Heap(vector<int> &A,int i,int n){
    int left=2*i+1;
    int right=2*i+2;
    int largest=i;
    if(left<n && A[left]>A[largest]){
        largest=left;
    }
    if(right<n && A[right]>A[largest]){
        largest=right;
    }
    if(largest!=i)
    {
        swap(A[largest],A[i]);
        Max_Heap(A,largest,n);
    }
}
void Build_Max_Heap(vector<int> &A)
{
    int n=A.size();
    for(int i=(n/2)-1;i>=0;i--)
    {
        Max_Heap(A,i,n);
    }
}
void Heapsort(vector<int> &A){
    Build_Max_Heap(A);
    for(int i=A.size()-1;i>=1;i--){
        swap(A[0],A[i]);
        Max_Heap(A,0,i);
    }
}
int main()
{
    vector<int> A;
    string nums;
    getline(cin,nums);
    stringstream ss(nums);
    int num;
    while(ss>>num){
        A.push_back(num);
    }
    Heapsort(A);
    for(int i:A)
    {
        cout<<i<<" ";
    }
    return 0;
}
