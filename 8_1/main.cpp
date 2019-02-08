#include <iostream>

using namespace std;

//lagrange
//bemenet 4 -2 -1 1 2 -5 3 -5 -9
//y: 5 -1.8 -1.3 0.0 1.0 1.5
int main()
{
    int n;
    cin>>n;
    double x[n];
    double f[n];
    double F[n][n];
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    for(int i=0;i<n;i++){
        cin>>f[i];
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            F[i][j]=0;
        }
    }

    for(int i=0;i<n;i++){
        F[i][0]=f[i];
    }

    for(int k=1;k<=n;k++){
        for(int i=k;i<n;i++){
            F[i][k]=(F[i][k-1]-F[i-1][k-1])/(x[i]-x[i-k]);
        }
    }

      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<F[i][j]<<" ";
        }
        cout<<endl;
    }

    int m;
    cin>>m;
    double y[m];
    double b[n];
    double c;

    for(int i=0;i<m;i++){
        cin>>y[i];
    }

    for(int i=0;i<n;i++){
        b[i]=F[i][i];
    }

    for(int i=0;i<m;i++){
        c=b[n];
        for(int k=1; k<=n;k++){
            c=c*(y[i]-x[n-k])+b[n-k];
        }
        cout<<c<<" ";
    }

    return 0;
}
