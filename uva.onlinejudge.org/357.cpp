
#include <iostream> 
using namespace std; 
int main() { 
    long long change[30001]; 
    long i; 
    for (i=0;i<30001;i++) change[i] = 1; 
    for (i=5;i<30001;i++) change[i]+=change[i-5]; 
    for (i=10;i<30001;i++) change[i]+=change[i-10]; 
    for (i=25;i<30001;i++) change[i]+=change[i-25]; 
    for (i=50;i<30001;i++) change[i]+=change[i-50]; 
    while (cin>>i){ // must 0<=i<99 
        if (change[i]==1) 
              cout << "There is only 1 way to produce " << i << " cents change." << endl; 
        else 
              cout << "There are " << change[i] << " ways to produce " << i << " cents change. " << endl; 
    } 
    return 0; 
} 
