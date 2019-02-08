#include <iostream>
#include <math.h>

using namespace std;

//PLU

int main()
{
    int n;
    cin>>n;
    double a[n][n];
    double be[n];
    int p[n];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin>>a[i][j];

    for(int i=0;i<n;i++){
        cin>>be[i];
    }

    for(int i=0;i<n;i++){
        p[i]=i;
    }

    for(int k=0; k<n;k++){
        int maxi=k;
        double maxertek=abs(a[k][k]);
        for(int i=k;i<n;i++){
            if(abs(a[i][k])>maxertek){
                maxertek=abs(a[i][k]);
                maxi=i;
            }
        }

        if(maxertek<=1e-15){
                cout<<"szingularis";
            return 0;
        }

        double seged[n];
        for(int i=0;i<n;i++)
            seged[i]=a[k][i];

        for(int i=0;i<n;i++){
            a[k][i]=a[maxi][i];
            a[maxi][i]=seged[i];
        }




        int segedp;
        segedp=p[k];
        p[k]=p[maxi];
        p[maxi]=segedp;


        cout<<"csere\n";
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
            cout<<a[i][j]<<" ";}
        cout<<"\n";
        }
        cout<<"-----------------\n";


        for(int i=k+1;i<n;i++){
            a[i][k]=a[i][k]/a[k][k];

            for(int j=k+1;j<n;j++){
                a[i][j]=a[i][j]-a[i][k]*a[k][j];
            }
        }
        cout<<"szamolas: \n";
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
            cout<<a[i][j]<<" ";}
        cout<<"\n";
        }
        cout<<"-----------------\n";
    }

    /*for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<a[i][j]<<" ";}
        cout<<"\n";
    }*/
    double b[n];

    for(int i=0; i<n;i++){
        b[i]=be[p[i]];
    }

    for(int i=1; i<n;i++){
        for(int j=0; j<i;j++){
            b[i]=b[i]-a[i][j]*b[j];
        }
    }

    /*for(int i=0;i<n;i++){
        cout<<b[i]<<"\n";
    }*/

    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<n;j++){
            b[i]=b[i]-a[i][j]*b[j];
        }
        b[i]=b[i]/a[i][i];
    }

     for(int i=0;i<n;i++){
        cout<<b[i]<<"\n";
    }

    return 0;
}
