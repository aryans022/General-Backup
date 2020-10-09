#include <bits/stdc++.h>
using namespace std;

int main() {

     int row, col;                                                         //matrix dimension input
     cin>>row>>col;

     int mat1[row][col];                                                   //allocation of 2d arrays of required size
     int mat2[row][col];
     int finalmat[row][col];

     for (int i = 0; i < row; i++) {                                       //matrix inputs
          for (int j = 0; j < col; j++) {
               cin>>mat1[i][j];
          }
     }
     for (int i = 0; i < row; i++) {
          for (int j = 0; j < col; j++) {
               cin>>mat2[i][j];
          }
     }

     cout<<endl;
     for (int i = 0; i < row; i++) {                                       //adding matrices, storing them and printing answer
          for (int j = 0; j < col; j++) {
               finalmat[i][j] = mat1[i][j]+mat2[i][j];
               cout<<finalmat[i][j]<<" ";
          }
          cout<<endl;
     }
}
