#include <iostream>
using namespace std;
/*
  A solved sudoku puzzle is a matrix of typically 9*9 in which   every row, every column and every block contains every number from 1 to 9 exactly once.
*/

void stack(int a[9][9],int vri,int vci,int val,int &bvalid)
{
  int r,c;
  for(r=vri/3*3;r<=vri/3*3+2;r++){
    for(c=vci/3*3;c<=vci/3*3+2;c++){
      if(vri==r && vci==c)
        continue;
      if(val==a[r][c])
        bvalid=0;
    }
  }
}
void CheckSudoku(int a[9][9])
{
 int i,j,vri,vci,brk=0,r,c;   // vci= value's column index
                              // vri= value's row index
 int val,rvalid,cvalid,bvalid;
  rvalid=1; cvalid=1; bvalid=1;
  for(i=0;i<9;i++)
  {
   for(j=0;j<9;j++)
   {
     val=a[i][j];
     vri=i;  vci=j;
  // Row checking
     for(c=0;c<9;c++){
       if(c==vci)
        continue;
       if(a[i][c]==val)
        rvalid=0;
      }
  // Column checking
     for(r=0;r<9;r++){
       if(r==vri)
        continue;
       if(a[r][j]==val)
        cvalid=0;
      }
  // Block Checking
    if(vri>=0 && vri<=2)          //Stack 1.  Row 0 to 2
      stack(a,vri,vci,val,bvalid);
    else if(vri>=3 && vri<=5)     //Stack 2.  Row 3 to 5
      stack(a,vri,vci,val,bvalid);
    else if(vri>=6 && vri<=8)     //Stack 3.  Row 6 to 8
      stack(a,vri,vci,val,bvalid);

   if(!(rvalid && cvalid && bvalid)){ brk=1; break; }
   }
   if(brk) break;
  }
   if(rvalid && cvalid && bvalid)
    cout<<"-> VALID SUDOKU.";
   else
    cout<<"-> INVALID SUDOKU.";
}

void PrintSudoku(int a[9][9])
{
 int i,j;
  for(i=0;i<9;i++)
  {
   for(j=0;j<9;j++)
   {
    cout<<a[i][j]<<" ";
   }
    cout<<endl;
  }

  cout<<endl;
}

int main()
{
 //INVALID
 int a1[9][9]={{1,2,3,4,5,6,7,8,9},
               {9,1,2,3,4,5,6,7,8},
               {8,9,1,2,3,4,5,6,7},
               {7,8,9,1,2,3,4,5,6},
               {6,7,8,9,1,2,3,4,5},
               {5,6,7,8,9,1,2,3,4},
               {4,5,6,7,8,9,1,2,3},
               {3,4,5,6,7,8,9,1,2},
               {2,3,4,5,6,7,8,9,1}};
 //INVALID
 int a2[9][9]={{3,5,2,9,1,8,6,7,4},
               {8,9,7,2,4,6,5,1,3},
               {6,4,1,7,5,3,2,8,9},
               {7,8,3,5,6,9,4,2,1},
               {9,2,6,1,3,4,7,5,8},
               {4,1,5,8,2,7,9,3,6},
               {8,6,4,3,7,5,8,9,2},
               {2,7,8,4,9,1,3,6,5},
               {5,3,9,6,8,2,1,4,7}};
  //VALID
 int a3[9][9]={{3,5,2,9,1,8,6,7,4},
               {8,9,7,2,4,6,5,1,3},
               {6,4,1,7,5,3,2,8,9},
               {7,8,3,5,6,9,4,2,1},
               {9,2,6,1,3,4,7,5,8},
               {4,1,5,8,2,7,9,3,6},
               {1,6,4,3,7,5,8,9,2},
               {2,7,8,4,9,1,3,6,5},
               {5,3,9,6,8,2,1,4,7}};

 int a4[9][9]={{1,2,3,4,5,6,7,8,9},
               {2,3,4,5,6,7,8,9,1},
               {5,6,7,8,9,1,2,3,4},
               {6,7,8,9,1,2,3,4,5},
               {9,1,2,3,4,5,6,7,8},
               {3,4,5,6,7,8,9,1,2},
               {4,5,6,7,8,9,1,2,3},
               {7,8,9,1,2,3,4,5,6},
               {8,9,1,2,3,4,5,6,7}};

 int a5[9][9]={{1,2,3,4,5,6,7,8,9},
               {9,1,2,3,4,5,6,7,8},
               {8,9,1,2,3,4,5,6,7},
               {7,8,9,1,2,3,4,5,6},
               {6,7,8,9,1,2,3,4,5},
               {5,6,7,8,9,1,2,3,4},
               {4,9,6,7,8,9,1,2,3},
               {3,4,5,6,7,8,9,1,2},
               {2,3,4,5,6,7,8,9,1}};
 //VALID
 int a6[9][9]={{7,3,5,6,1,4,8,9,2},
               {8,4,2,9,7,3,5,6,1},
               {9,6,1,2,8,5,3,7,4},
               {2,8,6,3,4,9,1,5,7},
               {4,1,3,8,5,7,9,2,6},
               {5,7,9,1,2,6,4,3,8},
               {1,5,7,4,9,2,6,8,3},
               {6,9,4,7,3,8,2,1,5},
               {3,2,8,5,6,1,7,4,9}};

 int a7[9][9]={{5,3,4,6,7,8,9,1,2},
               {6,7,2,1,9,5,3,4,8},
               {1,9,8,3,4,2,5,6,7},
               {8,5,9,7,6,1,4,2,3},
               {4,2,6,8,5,3,7,9,1},
               {7,1,3,9,2,4,8,5,6},
               {9,6,1,5,3,7,2,8,4},
               {2,8,7,4,1,9,6,3,5},
               {3,4,5,2,8,6,1,7,9}};

  cout<<"Sudoku Matrix --> 1"<<endl<<endl;
  PrintSudoku(a1);
  CheckSudoku(a1);
  cout<<endl<<endl<<endl;

  cout<<"Sudoku Matrix --> 2"<<endl<<endl;
  PrintSudoku(a2);
  CheckSudoku(a2);
  cout<<endl<<endl<<endl;

  cout<<"Sudoku Matrix --> 3"<<endl<<endl;
  PrintSudoku(a3);
  CheckSudoku(a3);
  cout<<endl<<endl<<endl;

  cout<<"Sudoku Matrix --> 4"<<endl<<endl;
  PrintSudoku(a4);
  CheckSudoku(a4);
  cout<<endl<<endl<<endl;

  cout<<"Sudoku Matrix --> 5"<<endl<<endl;
  PrintSudoku(a5);
  CheckSudoku(a5);
  cout<<endl<<endl<<endl;

  cout<<"Sudoku Matrix --> 6"<<endl<<endl;
  PrintSudoku(a6);
  CheckSudoku(a6);
  cout<<endl<<endl<<endl;

  cout<<"Sudoku Matrix --> 7"<<endl<<endl;
  PrintSudoku(a7);
  CheckSudoku(a7);
  cout<<endl<<endl<<endl;
 return 0;
}
