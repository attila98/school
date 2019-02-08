#include <iostream>
#include <math.h>

double fv(double x){
return ((x*x*x)-(3*x)-2);
}

using namespace std;

int main()
{
    double x0,x1,e;
    cin>>x0;
    cin>>e;
    int maxit=1000;
    for(int i=1;i<maxit;i++){
        x1=x0-(fv(x0)/(3*(x0*x0)-3));
        cout<<"x1: "<<x1<<endl;

        if(abs(x1-x0)<e){
            cout<<"lepes: "<<i;
            return 0;
        }
        x0=x1;
    }
    return 0;
}
