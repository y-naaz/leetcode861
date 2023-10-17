#leetcode problem number 861.
class Solution {
public:
    void reverse_grid(vector<int> &oned ){//fliping each rows whose first elemnt is zero
       int m=oned.size();
        for(int i =0;i<m;i++){
            if(oned[i]==0){
                oned[i]=1;
            }
            else{
                oned[i]=0;
            }
        }
        
    }
    void flip_column(vector<int> &oned ){//flipping column which have number of zero's greater than one's
       int n=oned.size();
        for(int i =0;i<n;i++){
            if(oned[i]==0){
                oned[i]=1;
            }
            else{
                oned[i]=0;
            }
        }
    }
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
       
        for(int i = 0;i<m;i++){
            if(grid[i][0]==0){
            //  vector<int> oned=grid[i];
            reverse_grid(grid[i]);//passing each row to a function for flipping
            }
            
        }
        int noo=0;
        int noz=0;
        for(int j =0;j<n;j++){
            for(int i =0;i<m;i++){
                if(grid[i][j]==0) noz++;
                else noo++;
            }
        }
        if(noz>=noo){
           for(int j = 0;j<n;j++){
               vector<int> column;
               for(int i =0;i<m;i++){
                   column.push_back(grid[i][j]);
           }
           flip_column(column);
             //passing each column for flipping
           }
        }
        int sum=0;
        
        for(int i = 0;i<n;i++){
            int x=1;
            for(int j=n-1;j>=0;j--){
                sum+=grid[i][j]*x;   //calculating score
                x*=2;
            }
        }
        return sum;
    }
};
//check where  is the problem with memory alignment 
