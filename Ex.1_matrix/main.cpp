#include<iostream>
using namespace std;

class Matrix{
    int **ptr;
    int rows,columns;

public:
    Matrix(int x,int y){
        rows=x;
        columns=y;
        ptr=new int*[x];
        int i,j;
        float determinant = 0;
        for(i=0;i<x;i++){
            ptr[i]=new int[y];
        }
        for(i=0;i<x;i++){
            for(j=0;j<y;j++){
                ptr[i][j]=0;
            }
        }
    }
    /*
    matrix:: ~matrix(){
        int i;
        for(i=0;i<m;i++){
            delete a[i];
        }
    }*/

    void initialize(){
        //cout<<"Enter the elements of the matrix..";
        int i,j;
        for(i=0;i<rows;i++){
            for(j=0;j<columns;j++){
                cin>>ptr[i][j];
            }
        }
    }

    void add(Matrix p,Matrix q){
        int i,j;
        for(i=0;i<rows;i++){
            for(j=0;j<columns;j++){
                    ptr[i][j]=p.ptr[i][j]+q.ptr[i][j];
            }
        }
    }

    void transpose(Matrix p){
        int i,j;
        for(i=0;i<rows;i++){
            for(j=0;j<columns;j++){
                    ptr[i][j]= p.ptr[j][i];
            }
        }
    }

    void inverse(Matrix p)
    {
        int i,j;
        float determinant;
        for(i=0;i<rows;i++)
            {
            determinant = determinant + (p.ptr[0][i] * (p.ptr[1][(i+1)%3] * p.ptr[2][(i+2)%3] - p.ptr[1][(i+2)%3] * p.ptr[2][(i+1)%3]));
            cout<<"Your determinant is: "<<determinant<<endl;
            cout<<"The Inverse of matrix is:"<<endl;
            for(i = 0; i < rows; i++)
                {
                    for(j = 0; j < columns; j++)
                    {
                    cout<<((p.ptr[(j+1)%3][(i+1)%3] * p.ptr[(j+2)%3][(i+2)%3]) - (p.ptr[(j+1)%3][(i+2)%3] * p.ptr[(j+2)%3][(i+1)%3]))/ determinant<<", ";
                    }
                }
            }
        cout<<endl;
    }

    void multiply(Matrix p,Matrix q){
        int i,j,k;
        for(i=0; i<p.rows; i++){
            for(j=0;j<q.columns; j++){
                ptr[i][j]=0;
                for (k=0; k <q.rows; k++) {
                    ptr[i][j] += p.ptr[i][k]*q.ptr[k][j];
                }
                cout<<"["<<ptr[i][j]<<"]";
            }
             cout<<endl;
        }
    }

    void print(){
         int i,j;
         for(i=0;i<rows;i++){
            for(j=0;j<columns;j++){
                cout<<"["<<ptr[i][j]<<"]";
            }
            cout<<endl;
        }
    }
};

int main()
{
    int p,q,x,y,operation,loop = 1,selector;
    //Select operation 1-Addition, 2-Multiplication, 3-Find transpose, 4-Inversion
    cout<<"Select operation 1-Addition, 2-Multiplication, 3-Find transpose, 4-Inversion"<<endl;
    cin>>operation;
    while (loop == 1)
    {
        switch (operation)
        {
        case 1:{
            cout<<"Enter the number of rows..";
            cin>>x;
            cout<<"Enter the no of columns..";
            cin>>y;
            cout<<"Enter the elements of the first matrix..";
            Matrix a(x,y);
            a.initialize();
            cout<<"Enter the elements of the second matrix..";
            Matrix b(x,y);
            b.initialize();
            cout<<"Your workspace is:"<<endl;
            a.print();
            cout<<"and"<<endl;
            b.print();
            Matrix c(x,y);
            c.add(a,b);
            cout<<"The sum of the two is.."<<endl;
            c.print();

            cout<<"New operation? Select operation 1-Addition, 2-Multiplication, 3-Find transpose, 4-Inversion, Anything else-END"<<endl;
            cin>>selector;
            if(selector == 0 || selector > 5)
            {
              loop = 0;
              break;
            }
            else{operation = selector;}
        }break;
        case 2:{
            cout<<"Enter the no of rows first matrix..";
            cin>>x;
            cout<<"Enter the no of columns of first matrix..";
            cin>>y;
            Matrix a(x,y);
            a.initialize();
            p = y;
            cout<<"The no of rows in second matrix is automatically set to "<< p <<endl;
            cout<<"Enter the no of columns of second matrix..";
            cin>>q;
            Matrix b(p,q);
            b.initialize();
            cout<<"Your workspace is:"<<endl;
            a.print();
            cout<<"and"<<endl;
            b.print();
            cout<<"The multiplication of the two is.."<<endl;
            Matrix c(x,y);
            c.multiply(a,b);
            //cout<<"The multiplication of the two is.."<<endl;
            //c.print();
            cout<<"New operation? Select operation 1-Addition, 2-Multiplication, 3-Find transpose, 4-Inversion, Anything else-END"<<endl;
            cin>>selector;
            if(selector == 0 || selector > 5)
            {
              loop = 0;
              break;
            }
            else{operation = selector;}
        }break;
        case 3:{
            cout<<"Enter the no of rows and columns for your matrix..";
            cin>>x;
            Matrix a(x,x);
            cout<<"Enter the elements of the matrix..";
            a.initialize();
            cout<<"Your workspace is:"<<endl;
            a.print();
            cout<<"Your transpose is:"<<endl;
            Matrix c(x,x);
            c.transpose(a);
            c.print();
            cout<<"New operation? Select operation 1-Addition, 2-Multiplication, 3-Find transpose, 4-Inversion, Anything else-END"<<endl;
            cin>>selector;
            if(selector == 0 || selector > 5)
            {
              loop = 0;
              break;
            }
            else{operation = selector;}
        }break;
        case 4:{
            cout<<"Enter the elements of the matrix..";
            Matrix a(3,3);
            a.initialize();
            cout<<"Your workspace is:"<<endl;
            a.print();
            Matrix c(3,3);
            c.inverse(a);

            cout<<"New operation? Select operation 1-Addition, 2-Multiplication, 3-Find transpose, 4-Inversion, Anything else-END"<<endl;
            cin>>selector;
            if(selector == 0 || selector > 5)
            {
              loop = 0;
              break;
            }
            else{operation = selector;}
        }break;
        }
    }

    return 0;
}
