#include <iostream> 
using namespace std; 
#define M 4 
#define N 5 
int preProcess(int mat[M][N], int aux[M][N]){
	int temp=0;
	for(int j=0; j<N; ++j)
	{
		temp += mat[0][j];
		aux[0][j] = temp;
	}

	for(int i=1; i<M; ++i){
		temp =0;
		for(int j=0; j< N; ++j){
			temp += mat[i][j] ;
			aux[i][j] = (aux[i-1][j] + temp);
		}
	}

	return 1;
}

// A O(1) time function to compute sum of submatrix 
// between (tli, tlj) and (rbi, rbj) using aux[][] 
// which is built by the preprocess function 
int sumQuery(int aux[M][N], int tli, int tlj, int rbi, 
                                              int rbj) 
{ 
    // result is now sum of elements between (0, 0) and 
    // (rbi, rbj) 
    int res = aux[rbi][rbj]; 
  
    // Remove elements between (0, 0) and (tli-1, rbj) 
    if (tli > 0) 
       res = res - aux[tli-1][rbj]; 
  
    // Remove elements between (0, 0) and (rbi, tlj-1) 
    if (tlj > 0) 
       res = res - aux[rbi][tlj-1]; 
  
    // Add aux[tli-1][tlj-1] as elements between (0, 0) 
    // and (tli-1, tlj-1) are subtracted twice 
    if (tli > 0 && tlj > 0) 
       res = res + aux[tli-1][tlj-1]; 
  
    return res; 
} 
  
// Driver program 
int main() 
{ 
   int mat[M][N] = {{1, 2, 3, 4, 6}, 
                    {5, 3, 8, 1, 2}, 
                    {4, 6, 7, 5, 5}, 
                    {2, 4, 8, 9, 4} }; 
   int aux[M][N]; 
  
   preProcess(mat, aux); 
  
   int tli = 2, tlj = 2, rbi = 3, rbj = 4; 
   cout << "\nQuery1: " << sumQuery(aux, tli, tlj, rbi, rbj); 
  
   tli = 0, tlj = 0, rbi = 1, rbj = 1; 
   cout << "\nQuery2: " << sumQuery(aux, tli, tlj, rbi, rbj); 
  
   tli = 1, tlj = 2, rbi = 3, rbj = 3; 
   cout << "\nQuery3: " << sumQuery(aux, tli, tlj, rbi, rbj); 
  
   return 0; 
}