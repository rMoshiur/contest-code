#include<cstdio>

using namespace std;

int main(){    
    int T;
    long long M[3][4];
    long long A,A1,A2,A3;
    double x1,x2,x3;
    
    scanf("%d",&T);
    
    for(int i=1;i<=T;i++){
        for(int j=0;j<3;j++)
            for(int k=0;k<4;k++) scanf("%lld",&M[j][k]);
        
        A=(M[0][0]*M[1][1]*M[2][2]+M[1][0]*M[2][1]*M[0][2]+M[2][0]*M[0][1]*M[1][2])-(M[0][2]*M[1][1]*M[2][0]+M[1][2]*M[2][1]*M[0][0]+M[2][2]*M[0][1]*M[1][0]);
        A1=(M[0][3]*M[1][1]*M[2][2]+M[1][3]*M[2][1]*M[0][2]+M[2][3]*M[0][1]*M[1][2])-(M[0][2]*M[1][1]*M[2][3]+M[1][2]*M[2][1]*M[0][3]+M[2][2]*M[0][1]*M[1][3]);
        A2=(M[0][0]*M[1][3]*M[2][2]+M[1][0]*M[2][3]*M[0][2]+M[2][0]*M[0][3]*M[1][2])-(M[0][2]*M[1][3]*M[2][0]+M[1][2]*M[2][3]*M[0][0]+M[2][2]*M[0][3]*M[1][0]);
        A3=(M[0][0]*M[1][1]*M[2][3]+M[1][0]*M[2][1]*M[0][3]+M[2][0]*M[0][1]*M[1][3])-(M[0][3]*M[1][1]*M[2][0]+M[1][3]*M[2][1]*M[0][0]+M[2][3]*M[0][1]*M[1][0]);
                
        printf("%lld %lld %lld %lld\n",A1,A2,A3,A);
        
        if(A==0) printf("No unique solution\n\n");
        else{
            x1=A1*1.0/A;
            x2=A2*1.0/A;
            x3=A3*1.0/A;
            
            if(-0.0005<x1 && x1<0.0005) x1=0.0;
            if(-0.0005<x2 && x2<0.0005) x2=0.0;
            if(-0.0005<x3 && x3<0.0005) x3=0.0;
            
            printf("Unique solution: %.3f %.3f %.3f\n\n",x1,x2,x3);
        }
    }
    
    return 0;
}
