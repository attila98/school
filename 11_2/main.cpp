#include <iostream>
#include <math.h>

using namespace std;

double belsosz(int n,double x[],double y[]){
    double osszeg=0;
    for(int i=0;i<n;i++){
        osszeg+=x[i]*y[i];
    }
return osszeg;
}

double vektornorma(int n,double x[]){
    double osszeg=0;
    for(int i=0;i<n;i++){
        osszeg+=x[i]*x[i];
    }

return sqrt(osszeg);
}

double vektornorma2(int n,double x[]){
    double osszeg=0;
    for(int i=0;i<n;i++){
        osszeg+=x[i]*x[i];
    }

return osszeg;
}

int main()
{
    int n;
    cin>>n;
    double a[n][n];
    double y[n];
    double e;
    int maxit;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }

    for(int i=0;i<n;i++){
        cin>>y[i];
    }

    cin>>e;
    cin>>maxit;

    double x[n];
    double xnorma;
    double lambda=0;
    double regilambda=0;
    double asd[n];

    for(int i=0;i<maxit;i++){
        regilambda=lambda;
        for(int j=0;j<n;j++){
            x[j]=0;
            for(int k=0;k<n;k++){
                x[j]=x[j]+(a[j][k]*y[k]);
                }
            }

        xnorma=vektornorma(n,x);

        for(int j=0;j<n;j++){
            y[j]=x[j]/xnorma;
        }

        for(int j=0;j<n;j++){
            asd[j]=0;
            for(int k=0;k<n;k++){
                asd[j]=asd[j]+(a[j][k]*y[k]);
                }
            }

        lambda=belsosz(n,asd,y);
        if(i>1){
        if(abs(lambda-regilambda)<e){
            cout<<"lepes: "<<i<<endl;
            for(int j=0;j<n;j++){
                cout<<y[j]<<" "<<endl;
            }
            cout<<"lambda: "<<lambda<<endl;

            break;
            }


        }
    }

    double szam[n];
    double vec[n];

    for(int j=0;j<n;j++){
        szam[j]=lambda*y[j];
    }

    for(int j=0;j<n;j++){
        vec[j]=asd[j]-szam[j];
    }

    if(vektornorma2(n,vec)<e){
        cout<<"siker!";
    }
    else{
        cout<<"sikertelen";
    }

    return 0;
}
