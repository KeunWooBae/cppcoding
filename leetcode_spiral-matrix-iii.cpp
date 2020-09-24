#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int isFull(int **arr, int R, int C)
    {   
        if (R == 1)
        {
            if (arr[0][0] != 0 && arr[0][C - 1] != 0) return 1;
        }
        else if (arr[0][0] != 0 && arr[R - 1][C - 1] != 0 && arr[0][C - 1] != 0 && arr[R - 1][0] != 0)
        {
            return 1;
        }
        else return 0;
        
        return 0;
    }
     
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {

        int cnt = 1;
        int t = 0;
        int x, y, z, a;
        int check, flag;
        int index1, index2;
        int** arr = new int* [R];
        vector<vector<int>> result;

        int direct[4][2] =
        {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };

        for (x= 0; x < R; ++x)         
            arr[x] = new int[C];

        for (x = 0; x < R; x++)
        {
            for (y = 0; y < C; y++)
            {
                arr[x][y] = 0;
            }
        }
                
        arr[r0][c0] = cnt;
        cnt++;
        result.push_back({r0, c0});

        while (1)
        {
            for (x = 0; x < 4; x++)
            {
                z = t / 2 + 1;
                flag = 0;
                index1 = direct[x][0];
                index2 = direct[x][1];
                for (a = 1; a < z + 1; a++)
                {
                    if (r0 + index1 * a < 0 || r0 + index1 * a >= R || c0 + index2 * a < 0 || c0 + index2 * a >= C)
                    {
                        flag = 1;
                        continue;
                    }
                    arr[r0 + index1 * a][c0 + index2 * a] = cnt;
                    cnt++;
                    result.push_back({ r0 + index1 * a, c0 + index2 * a });
                    
                }

                
                r0 += index1 * (a - 1);
                c0 += index2 * (a - 1);
                
                t++;
                check = isFull(arr, R, C);
                if (check == 1) break;                             
            }
            if (check == 1) break;
        }
        return result;
    }
};


int main()
{
    Solution t = Solution();

    t.spiralMatrixIII(1, 4, 0, 0);


    return 0;
}
