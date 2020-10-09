#define PROBAB 40
#define NUM_EXP 100
#define GRID_SIZE 512
#include <bits/stdc++.h>
using namespace std;

class WeightedQuickUnionUF {

     private:
          int *sz;

          int root(int p) {
               while (base[p] != p) {
                    base[p] = base[base[p]];
                    p = base[p];
               }
               return p;
          }

     public:
          int *base;

          WeightedQuickUnionUF(int n) {
               base = new int[n];
               sz = new int[n];
               for (int i = 0; i < n; i++) {
                    base[i] = i;
                    sz[i] = 1;
               }
          }

          bool connected(int p, int q) {
               return (root(p) == root(q));
          }

          void join(int p, int q) {
               if (!connected(p, q)) {
                    int rp = root(p);
                    int rq = root(q);
                    if (sz[p] < sz[q]) {
                         base[rp] = rq;
                    }
                    else {
                         base[rq] = rp;
                    }
               }
          }

          ~WeightedQuickUnionUF() {
               delete []base;
               delete []sz;
          }

};

int main() {

	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = NUM_EXP, percolates = 0;
	while (t--) {

		int n = GRID_SIZE;
		int **arr = new int*[n];
		for (int i = 0; i < n; i++) {
               arr[i] = new int[n];
		}
		for (int i = 0; i < n; i++) {
               for (int j = 0; j < n; j++) {
                    if (rand()%100 > PROBAB) {
                         arr[i][j] = 1;
                    }
                    else {
                         arr[i][j] = 0;
                    }
               }
		}

		WeightedQuickUnionUF dsu(n*n+2);

		for (int i = 0; i < n; i++) {
               for (int j = 0; j < n; j++) {
                    if (arr[i][j] == 1) {
                         if (j>0 && arr[i][j-1] == 1) {                        //left join
                              dsu.join((n*i)+j+1, (n*i)+j);
                         }
                         if (j<n-1 && arr[i][j+1] == 1) {                    //right join
                              dsu.join((n*i)+j+1, (n*i)+j+2);
                         }
                         if (i==0) {                                            //top join
                              dsu.join((n*i)+j+1, 0);
                              if (arr[i+1][j] == 1) {
                                   dsu.join((n*i)+j+1, (n*i)+n+j+1);            //down join
                              }
                         }
                         else if (i == n-1) {                                   //bottom join
                              dsu.join((n*i)+j+1, n*n+1);
                              if (arr[i-1][j] == 1) {
                                   dsu.join((n*i)+j+1, (n*i)-n+j+1);            //up join
                              }
                         }
                         else {
                              if (arr[i+1][j] == 1) {
                                   dsu.join((n*i)+j+1, (n*i)+n+j+1);            //down join
                              }
                              if (arr[i-1][j] == 1) {
                                   dsu.join((n*i)+j+1, (n*i)-n+j+1);            //up join
                              }
                         }
                    }
               }
		}

		if (dsu.connected(0, n*n+1)) {
               percolates++;
		}


		for (int i = 0; i < n; i++) {
               delete []arr[i];
		}
		delete []arr;

	}

	cout<<percolates<<'/'<<NUM_EXP<<endl;
}
