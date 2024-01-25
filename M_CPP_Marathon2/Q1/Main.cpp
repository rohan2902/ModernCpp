#include<iostream>
#include<array>
#include<functional>

int main(){
    
    int val;

    const int a = 2;//rows
    const int b = 2;//columns

    using Matrix = std::array<std::array<int,a>,b>;
    
    Matrix MatrixArray;
    
    for (int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++){
            std::cin>>val;
            MatrixArray[i][j]=val;
        }   
    }
    
    std::cout<<"\n--------------------\n";
    std::function<void(Matrix &)> SumOfRows = [](Matrix& MatrixArr){

        for (int i=0;i<a;i++)
        {
            int sum = 0;
            for(int j=0;j<b;j++){   
                sum=sum+MatrixArr[i][j];   
            } 
            std::cout<<"Sum of row "<<i+1<<" is "<<sum<<"\n";
        }
    };
    SumOfRows(MatrixArray);

    std::cout<<"\n--------------------\n";
    std::function<void(Matrix &)> Max = [&](Matrix& MatrixArr){

        int max = MatrixArr[0][0];
        for (int i=0;i<a;i++)
        {
            for(int j=0;j<b;j++){
                if(max<MatrixArr[i][j]){
                    max=MatrixArr[i][j];
                }   
 
            } 
        }

        std::cout<<"\nMaximum = "<<max;
    };

    Max(MatrixArray);

    std::cout<<"\n--------------------\n";
    std::function<void(Matrix &)> SquareOfLast = [&](Matrix& MatrixArr){

        int i;
        int j;

        for (i=0;i<a;i++)
        {
            for(j=0;j<b;j++){
               
            } 
        } 
        std::cout<<"\nSquare of last element =  "<<MatrixArr[a-1][b-1]*MatrixArr[a-1][b-1];
 
    };

    SquareOfLast(MatrixArray);

    std::cout<<"\n--------------------\n";

    std::function<void(Matrix &)> MaxInRow = [&](Matrix& MatrixArr){  
        int max = MatrixArr[0][0];
        for (int i=0;i<a;i++)
        {
            for(int j=0;j<b;j++){     
                if(max<MatrixArr[i][j]){
                    max=MatrixArr[i][j];
                }
            } 
            std::cout<<"Max in row = "<<max<<"\n";
        }
    };

    MaxInRow(MatrixArray);

    
}