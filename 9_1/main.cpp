#include <iostream>
#include <math.h>

using namespace std;

double fv(double x){
    return sin(x);
}


int main()
{
    //egyszerû trapez

    /*double a,b;
    int m;
    cin>>a;
    cin>>b;
    cin>>m;
    double e=0;
    double h=(b-a)/m;
    double x=(fv(a)/2);
    e=e+x;
    for(int i=1;i<m;i++){
        x+=h;
        e=e+ fv(x);
    }
    e=e+(fv(b)/2);
    e=h*e;
    cout<<e;
    return 0;*/


    //osszetett simpson
    double a,b;
    int m;
    cin>>a;
    cin>>b;
    cin>>m;
    double e=0;
    double e1=0;
    double e2=0;
    double h=(b-a)/m;
    double x=a;
    e=e+fv(x);
    e1=e1+fv(x+h/2);
    for(int i=1;i<m;i++){
        x+=h;
        e1=e1+fv(x+(h/2));
    }
    e1=4*e1;
    x=a;
    for(int i=1;i<m;i++){
        x+=h;
        e2=e2+fv(x);
    }
    e2=2*e2;
    e=e+fv(b);
    e=e+e1+e2;
    e=(h/6)*e;
    cout<<e;
    return 0;
}
