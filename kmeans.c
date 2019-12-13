#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define sqr(x) ((x)*(x))

double calc_euclideanDist(int n, int k, float coordx[n],float coordy[n],float clus_centx[k],float clus_centy[k])
    {
        int i,j,p=0,q=0,r=0;
        float mean1x=0,mean1y=0, mean2x=0, mean2y=0, mean3x=0, mean3y=0;
        float sum1x=0,sum1y=0,sum2x=0,sum2y=0,sum3x=0,sum3y=0;
        float cluster1x[n],cluster1y[n],cluster2x[n],cluster2y[n],cluster3x[n],cluster3y[n];
        float clus_centxnew[k], clus_centynew[k];
        double euclideanDistA[n],euclideanDistB[n],euclideanDistC[n];
        for (i=0; i<n; i++)
        {
            euclideanDistA[i]=sqrt(sqr(coordx[i]-clus_centx[0])+sqr(coordy[i]-clus_centy[0]));

        }
         for (i=0; i<n; i++)
        {
            euclideanDistB[i]=sqrt(sqr(coordx[i]-clus_centx[1])+sqr(coordy[i]-clus_centy[1]));

        }
         for (i=0; i<n; i++)
        {
            euclideanDistC[i]=sqrt(sqr(coordx[i]-clus_centx[2])+sqr(coordy[i]-clus_centy[2]));

        }
        printf("Distance of all position coordinates from 1st cluster center \n");
        for(i=0;i<n;i++)
        {
            printf("%lf\n",euclideanDistA[i]);

        }
        printf("Distance of all position coordinates from 2nd cluster center \n");
        for(i=0;i<n;i++)
        {
            printf("%lf\n",euclideanDistB[i]);

        }
        printf("Distance of all position coordinates from 3rd cluster center \n");
        for(i=0;i<n;i++)
        {

            printf("%lf\n",euclideanDistC[i]);
        }

        for(i=0; i<n ; i++)
        {

            if(euclideanDistA[i]<euclideanDistB[i]&&euclideanDistA[i]<euclideanDistC[i])
            {
              cluster1x[i]= coordx[i];
              cluster1y[i]= coordy[i];
               printf("%d th coordinate in cluster 1 \n( %f , %f)\n", i+1,cluster1x[i],cluster1y[i]);
                sum1x=sum1x+cluster1x[i];
                sum1y=sum1y+cluster1y[i];
               p++;

            }
            else if(euclideanDistB[i]<euclideanDistA[i]&&euclideanDistB[i]<euclideanDistC[i])
            {
              cluster2x[i]= coordx[i];
              cluster2y[i]= coordy[i];
               printf("%d th coordinate in cluster 2 \n ( %f , %f)\n",i+1, cluster2x[i],cluster2y[i]);
               sum2x=sum2x+cluster2x[i];
                sum2y=sum2y+cluster2y[i];
               q++;

            }
            else
            {
              cluster3x[i]= coordx[i];
              cluster3y[i]= coordy[i];
              printf("%d th coordinate in cluster 3 \n ( %f , %f )\n", i+1, cluster3x[i],cluster3y[i]);
              sum3x=sum3x+cluster3x[i];
              sum3y=sum3y+cluster3y[i];
              r++;
            }
        }

        mean1x=sum1x/p;
        mean1y=sum1y/p;
        mean2x=sum2x/q;
        mean2y=sum2y/q;
        mean3x=sum3x/r;
        mean3y=sum3y/r;
        clus_centxnew[0]=mean1x;
        clus_centxnew[1]=mean2x;
        clus_centxnew[2]=mean3x;
        clus_centynew[0]=mean1y;
        clus_centynew[1]=mean2y;
        clus_centynew[2]=mean3y;
        for(i=0;i<k;i++)
        {
            printf("The new cluster-centers are (%f %f)\n",clus_centxnew[i],clus_centynew[i]);
        }
        for(j=0;j<15;j++)
        {
            if(clus_centxnew[0]!=clus_centx[0] && clus_centynew[0]!=clus_centy[0]||clus_centxnew[1]!=clus_centx[1] && clus_centynew[1]!=clus_centy[1]||clus_centxnew[2]!=clus_centx[2] && clus_centynew[2]!=clus_centy[2])
          {
              clus_centx[0]=clus_centxnew[0];
              clus_centx[1]=clus_centxnew[1];
              clus_centx[2]=clus_centxnew[2];
              clus_centy[0]=clus_centynew[0];
              clus_centy[1]=clus_centynew[1];
              clus_centy[2]=clus_centynew[2];
              calc_euclideanDist(n,k,coordx,coordy,clus_centx,clus_centy);

          }
          break;
        }



            return 0;
    }


int main()
{
    int n,k=3;
    printf("Enter the no. of position coordinate you want to enter\n");
    scanf("%d",&n);
    float coordx[n];
    float coordy[n];
    float clus_centx[k];
    float clus_centy[k];
    int i;
    printf("Enter the x-coordinates of position \n");
    for(i=0; i<n; i++)
    {
          scanf("%f",&coordx[i]);
    }
    printf("Enter the y-coordinates of position \n");

    for(i=0; i<n; i++)
    {
          scanf("%f",&coordy[i]);
    }
    printf("Enter the x-coordinate of cluster centers you want to assume\n");
    for(i=0; i<k; i++)
    {
          scanf("%f",&clus_centx[i]);

    }
    printf("Enter the y-coordinate of cluster centers you want to assume\n");
    for(i=0; i<k; i++)
    {
          scanf("%f",&clus_centy[i]);

    }
    printf("The position coordinates are\n");
    for(i=0; i<n; i++)
    {
          printf("%f  %f\n", coordx[i],coordy[i]);
    }
    printf("The cluster centers are\n");
    for(i=0; i<k; i++)
    {

          printf("%f  %f\n",clus_centx[i],clus_centy[i]);

    }
    calc_euclideanDist(n,k,coordx,coordy,clus_centx,clus_centy);
   return 0;
}
