#include <iostream>
#include <math.h>

double fv (double x){
return (cos(x)-(3*x));
}

using namespace std;

int main()
{
    double a,b,e;
    cin>>a;
    cin>>b;
    cin>>e;
    double x0,x1,x2;
    x0=a;
    x1=b;
    int lepes=0;
    int maxi=1000;

    double oldx2;

    if((fv(a)*fv(b))<0){

    for(int i=0;i<maxi;i++){
        x2=x1-fv(x1)*((x1-x0)/(fv(x1)-fv(x0)));
        cout<<x2<<" x2"<<endl;
        if(x2==0){
            cout<<x2<<" gyok"<<endl;
            cout<<"lepes: "<<lepes<<endl;
            return 0;
        }
        if((fv(x2)*fv(x0))<0){
            x1=x2;
        }
        else{
            x0=x2;
        }
        if(lepes>1){
        if(abs(x2-oldx2)<e){
            cout<<x2<<endl;
            cout<<"lepes "<<lepes<<endl;
            return 0;
        }
        }
        lepes++;
        oldx2=x2;
    }
    }
    else
    {
        cout<<"hiba"<<endl;
        return 0;
    }
    return 0;
}
