#include <iostream>

//Horner algoritmus

using namespace std;

int main()
{
    int n=4;
    double a[n+1]={1.1,2.3,-1.0,3.0,1.0};
    double c;
    double x=-3.3;
    c=a[n];
    for(int k=1; k<=n;k++){
        c=c*x+a[n-k];
    }
    cout <<c<< endl;
    return 0;
}
