#include <mpi.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int rank; 
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    //printf("Hello from %d\n",rank);
        printf("\nCreating an array of 100 and choosing 99 a number to search a>
    if (rank == 0)
    {   char recievedata[2];
        char sdata[101];
        MPI_Status status;
        for(int i=0;i<100;i++){
                sdata[i]=i;
        }
        sdata[100]=99;
	MPI_Send(sdata, 101, MPI_CHAR, 1,99, MPI_COMM_WORLD);
        sleep(2);
        MPI_Recv(recievedata, 2, MPI_CHAR, 1, 99, MPI_COMM_WORLD,&status);
printf("\nThe number recieved is: \n");
        printf("%d",recievedata[0]);
        printf("\nThe number is at the index: \n");
        printf("%d",recievedata[1]);
    } 
    else if (rank==1)
     {  
        char rdata[]="";
        char senddata[]="";
        MPI_Status status;
        int totalRec=0;
        int user_num;
        MPI_Recv(rdata, 101, MPI_CHAR, 0, 99, MPI_COMM_WORLD,&status);
        printf("\nI am a slave and I received %s message from my master...\n",r>
        MPI_Get_count(&status,MPI_CHAR,&totalRec);
        printf("\nSlave process received %d characters from process %d, with ta>
        printf("\nThe number you want to search\n");
        user_num=rdata[100];
        printf("%d",rdata[100]);
        for(int i=0;i<101;i++){
        if(rdata[i]==user_num)
        {
        senddata[0]=user_num;
        senddata[1]=i;
        //printf("%d",senddata[0]);
        printf("\n");
        }
        }
        sleep(1);
        MPI_Send(senddata, 2, MPI_CHAR, 0,99, MPI_COMM_WORLD);

     }
    printf("\nBye...\n");
    MPI_Finalize();
    return 0;
}

