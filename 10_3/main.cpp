#include <iostream>
#include <math.h>


double fv(double x[]){
    x[0]=-3/4+1/4*cos(2*x[0]-x[1]);
    x[1]=-2/3+1/3*sin(x[0]);

return x[];
}


using namespace std;

//-3/4+1/4*cos(2*x1-x2)=x1
//-2/3+1/3*sin(x1)=x2

int main()
{
    double x0[2];
    double e;
    double x1;
    int maxit;
    cin>>x0[0];
    cin>>x0[1];
    cin>>e;
    cin>>maxit;

    for(int i=0;i<maxit;i++){
        x1=fv(x0);

        //||x1-x0|| vegtelen < e -> kilep

    }

    return 0;
}
