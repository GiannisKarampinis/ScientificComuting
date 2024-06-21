#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int main(){
 double A[3][3]={
        {-261, 209, -49},
        {-530, 422, -98},
        {-800, 631,-144}};
 double x[3]={0,0,0}, x_old[3]={1,1,1}, y[3], error=1.0,eps=0.0001,maxValue;
 int i,j,maxIters=1000,iters=0,n=3;
 
 do{
     // Multiplication A*x_old
     for(i=0;i<n;i++){
       y[i]=0.0;
       for(j=0;j<n;j++)
          y[i]+=A[i][j]*x_old[j];
     }
     
      // Compute max norm of vector y
      maxValue=y[0];
      for(i=1;i<n;i++){
         if(maxValue<y[i])
           maxValue=y[i];              
      }
                       
      // normalize vector y and store it to x
      for(i=0;i<n;i++)
        x[i]=y[i]/maxValue;
     
     
     //compute error
     error=fabs(x[0]-x_old[0]);
     for(i=1;i<n;i++){
         if(error<fabs(x[i]-x_old[i]))
           error=fabs(x[i]-x_old[i]);              
      }
     
     //udate vector x_old
     for(i=0;i<n;i++){
        x_old[i]=x[i];              
     }
     iters++;
     printf("Iteration: %d, approximate eigenvalue: %.10f\n",iters,maxValue);
 }while(iters<maxIters && error>=eps);
 return 0;   
}



