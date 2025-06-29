#include <iostream>
#include <numeric>
using namespace std;

bool check(long long A[], long long B[],long long n){
    for (int i=0 ; i<n-1;i++)
    {
        if(gcd(B[i],B[i+1])==1){
            continue;
        }else
        {
            return false;
        }
    }
    return true;
}

void zero(long long B[],long long n,long long X){
    for(int i=0; i<n;i++){
        if(B[i]==0){
            B[i]=X;
        }
    }
}

int Brray(long long A[],long long B[],long long n,long long X){
    for(int i=0;i<n;i++){
        B[i]=A[i];
    }
    zero(B,n,X);
    if(check(A,B,n)){
        return X;
    }
    return Brray(A,B,n,X+1);
}

int name(){
    long long n;
    cin>>n;
    long long A[n],B[n];
    for(int i=0; i<n;i++){
        cin>>A[i];
        B[i]=A[i];
    }
    int t = Brray(A,B,n,2);
    cout<<t<<endl;
    return 0;
}
