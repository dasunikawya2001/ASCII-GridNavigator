#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

//Declare a array to create the Map
char mapArray[50][50];

//Checkinh Validity of the input array
int checkValid(char arr[]){
    int found=1;
    int i=0;
    while (arr[i] != '\0')
    {
        if (!((int)arr>64 && (int)arr<91))
        {
            found = 0;
            //printf("Invalid String.");
            break;
        }
        else {
            found=1;
            i++;
        }
        
    }
    return  found;
}

//Function to create two dimensional array for the Map
void createMap (char arr[], int rows,int cols){
    int i=0,j=0,k=0;

    for ( i = 0; i < rows; i++)
    {
        for ( j = 0; j < cols; j++)
        {
            mapArray[i][j] = arr[k]; //Assinging characters from the array
            //printf("%c" , mapArray[i][j]);
            k++;
        
            if (arr[k] == '\0')
            {
                break;
            }
        }
        if (arr[k] == '\0')
        {
            break;
        }
        //printf("\n");   
    }
    //printf("\n");
}

//Introducing cell as a data type
typedef struct _ {
    int i;
    int j;
}Cell;

//Declare a array to track the path
int minDistance[50][50] ;

//Direction vector: Climbinfg,Going down,Forward,Backward
int dirVector [][2] = {{-1,0},{1,0},{0,1},{0,-1}};

//To handle visited cells
bool visitedMatrix[50][50] = {0}; 

//Introducing a queue to handle all possible paths 
Cell queue[200];

//Initially assinging indexes to first and last elements of the queue
int front=0 , end=-1;

//Function to check whether the queue is empty
bool isEmpty(){
    return front>end;
}

//Adding cells to the queue
void adding_elements(int i, int j){
    queue[++end].i=i;
    queue[end].j=j;
}

//Removing Cells from the queue
Cell removing_elements(){
    if(isEmpty()){
        return (Cell){-1,-1};
    }
    return queue[front++];
}

//Function to find whether a valid move
bool isValidMove(char array[][50],int rows,int columns,int i,int j,int prev_i,int prev_j){
    int asciiDiff_1=abs((int)mapArray[i][j]-(int)mapArray[prev_i][prev_j]);
    if(i < 0 || i>=rows || j < 0 || j>=columns || visitedMatrix[i][j])// Checking boundary conditions and the visited cells cases
    {
        return false;
    }
    else if ((int)mapArray[i][j]==(int)mapArray[prev_i][prev_j])
    {
        return true;
    }
    else if ((int)mapArray[i][j]>(int)mapArray[prev_i][prev_j] && asciiDiff_1 <= 2)
    {
        return true;
    }
    else if ((int)mapArray[i][j]<(int)mapArray[prev_i][prev_j] && asciiDiff_1 <=3)
    {
        return true;   
    }
    return false;
}

//Finding Shortest Path to the destination
int Shortest_Path (char array[][50],int rows,int columns,int start_i,int start_j,int end_i,int end_j){
    adding_elements(start_i,start_j); //Adding start cell to the queue
    visitedMatrix[start_i][start_j]; // Marking starting cell as visited
    minDistance[start_i][start_j]= 0 ; //At the begining distance is 0

    while (!isEmpty())
    {
         //Declare a variable called present and it assing to the cell whicth is removing form the queue
        Cell present = removing_elements();

        if ((present.i == end_i) && (present.j == end_j) && (present.i>=0) && (present.i < rows) && (present.j >= 0) && (present.j <columns))
        {
            //printf("The minimum distance from %c to %c is %d\n" , mapArray[start_i][start_j],mapArray[end_i][end_j]  , minDistance[end_i][end_j]);
            return minDistance[end_i][end_j];
        }
        
        //Explore all posibble neighbours to move
        for (int m = 0; m < 4 ; m++)
        {
            int di = dirVector[m][0];
            int dj = dirVector[m][1];
            int next_i = present.i + di;
            int next_j = present.j + dj;


            if ((isValidMove(mapArray,rows , columns , next_i , next_j , present.i , present.j)) && !visitedMatrix[next_i][next_j])
            {
                //If it is a valid move then add that cell to the queue
                adding_elements(next_i,next_j);
                //Mark is as a visited cell
                visitedMatrix[next_i][next_j] = true;
                //Assign the distance to that cell from the start
                minDistance[next_i][next_j] = minDistance[present.i][present.j] + 1 ; 
            }
        } 
    }
    //printf("There is no possible path from %c to %c -1 \n ", mapArray[start_i][start_j],mapArray[end_i][end_j]);  
    //printf("-1 ");
    return -1;
} 

//An array to store calculated fibonacchi numbers
//Initially assining all the values to 0
long int storedArray[200]= {0};

//Recursion function to calculate fibonacchi numbers
int fib(int num){
    if (num<=1)
    {
        return num;
    }
    else if (storedArray[num] != 0)
    {
        return storedArray[num];
    }
    else{
        storedArray[num] = fib(num-1)+fib(num-2);
        return storedArray[num];
    }
    return storedArray[num];
}

//Function to matching the calculated fibonacci number
bool findEqualty(int number, int target01, int target02){
    if (number==target01 || number==target02)
        {
            return true;
        }
    else{
        return false;
    }
    return true;
} 

//Function to calculated the number=ROW*MAPWIDTH+COL
int calcNumber(int mapWidth, int rowNum , int colNum){
    return rowNum*mapWidth+colNum;
}

//Function to print the shortest distance
int printDis(int array[5]){
    for (int i = 0; i < 5; i++)
    {
        if (array[i]==-1)
        {
            array[i]=1000;
        }  
    }
    
    int min = array[0];
    if (array[1]+array[4]<min)
    {
        min = array[1]+array[4];
    }
    if (array[2]+array[3]<min)
    {
        min = array[2]+array[3];
    }
    return min;    
}


//Main Function
int main(){

    int S1, S2, E1, E2;
    char inputArray[250];

    //Getting Map height and width form the user
    int rows , cols;
    scanf("%d %d" , &rows , &cols);

    //Strating point
    scanf("%d %d" , &S1 , &S2);

    //Ending point
    scanf("%d %d" , &E1 , &E2);
    
    //Gettin the input character array from the user
    scanf("%s" , inputArray);

    //Matching Numbers
    int M1 , M2;
    scanf("%i %i" , &M1, &M2);

    //Number of door cells
    int ND;
    scanf("%i" , &ND);

    Cell *cellArray;
    cellArray=(Cell*)malloc(sizeof(Cell)*ND);
    

    //Getting door cell positions
    for (int k = 0; k < ND; k++)
    {
        scanf("%i %i" , &cellArray[k].i , &cellArray[k].j);
        //printf("element1 - %i element2 - %i" , cellArray[i].i , cellArray[i].j);
    }

    Cell *tDoors;
    tDoors=(Cell*)calloc(ND,sizeof(Cell)*ND);

    //Get the Calculated number, fibonacci num and match 
    int count=0;
    for (int l = 0; l < ND; l++)
    {
        int calc = calcNumber(cols, cellArray[l].i, cellArray[l].j);
        int fibNum = fib(calc);
        if (findEqualty(fibNum,M1,M2))
        {
            tDoors[l].i = cellArray[l].i;
            tDoors[l].j = cellArray[l].j;
            count ++;
        }   
        else{
            tDoors[l].i = -1;
            tDoors[l].j = -1;
        }
    }
    //printf("count = %i \n" , count);
    
    //Considering the number of telepotation doors
    //int TR1 , TC1 , TR2 , TC2;
    int tele_i[2]={0};
    int tele_j[2]={0};
    int index1=0 , index2=0;
    if (count==2)
    {
        for (int k = 0; k < ND; k++)
        {
            if ((tDoors[k].i!=-1) && (tDoors[k].j!=-1))
            {
                tele_i[index1++]=tDoors[k].i;
                tele_j[index2++]=tDoors[k].j;
            }
        }
        
    }
    

    //Checking Validity of the input Array
    int check = checkValid(inputArray);
    
    //Creating the Map
    createMap(inputArray, rows, cols); 

    //To Find the shortest path through the telepotation doors
    int distances[5];
    if (count==2)
    {
        //Defining array including the starting and ending cell indexes
        int startCells_i[5] = {S1,S1,S1,tele_i[0],tele_i[1]};
        int startCells_j[5] = {S2,S2,S2,tele_j[0],tele_j[1]};

        int endCells_i[5] = {E1,tele_i[0],tele_i[1],E1,E1};
        int endCells_j[5] = {E2,tele_j[0],tele_j[1],E2,E2};

        //Loop to to find the shortest paths
        for (int i = 0; i < 5; i++)
        {
            distances[i]= Shortest_Path(mapArray,rows,cols,startCells_i[i],startCells_j[i],endCells_i[i],endCells_j[i]);
            //Reset visited array, minDistance array and the queue
            memset(visitedMatrix, 0, sizeof(visitedMatrix));
            memset(minDistance, 0, sizeof(minDistance));
            front=0 , end=-1;
        }

        //Printing the shortest distance
        int minDis1 = printDis(distances);
        if (minDis1>=1000)
        {
            printf("There is no possible path from %c to %c",mapArray[S1][S2],mapArray[E1][E2]);
        }
        else{
            printf("The minimum distance from %c to %c is %d",mapArray[S1][S2],mapArray[E1][E2] , minDis1);
        }
        
    }
    else{
        int minDis2 = Shortest_Path(mapArray,rows,cols,S1,S2,E1,E2);
        if (minDis2==-1)
        {
            printf("There is no possible path from %c to %c" , mapArray[S1][S2],mapArray[E1][E2]);
        }
        else{
            printf("The minimum distance from %c to %c is %d",mapArray[S1][S2],mapArray[E1][E2] , minDis2);
        }
        
    }
    return 0;
}