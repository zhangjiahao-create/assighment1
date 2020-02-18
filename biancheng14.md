问题：

     n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
    上图为 8 皇后问题的一种解法。给定一个整数 n，返回 n 皇后不同的解决方案的数量。


示例:

    输入: 4
    输出: 2
    解释: 4 皇后问题存在如下两个不同的解法。


图案：   
      
       ".Q..",  
       "...Q",
       "Q...",
       "..Q."；
       
       
       "..Q.",  
       "Q...",
       "...Q",
       ".Q.."。
      


代码：



    int sample[3][2] = {{-1,0},{-1,-1},{-1,1}};
    bool temp[100][100];
    bool judge_1(int i,int j,int dx,int dy,int n)
    {
        while(1)
        {
            if(i<0||i>=n||j<0||j>=n)
                return true;
            if(temp[i][j]==true)
                return false;
            i = i+dx;
            j = j+dy;
        }
    }
    bool judge(int heng,int zong,int n)
    {
        for(int i=0;i<3;i++)
        {
             if(judge_1(heng,zong,sample[i][0],sample[i][1],n)==false)
                  return false;
        }
        return true;  
    }
    void dif(int heng,int n,int *returnSize)
    {
        int i;
        if(heng>=n)
        {
             (*returnSize)++;
             return;
        }
        else
        {
             for(i=0;i<n;i++)
             {
                  if(judge(heng,i,n)==false)
                  {
                        continue;
                  }
                  temp[heng][i] = true;
                  dif(heng+1,n,returnSize);
                  temp[heng][i] = false;
             }
        } 
    }
    void solveNQueens(int n, int* returnSize)  
    {
        *returnSize = 0;
         memset(temp,0,sizeof(temp));
         dif(0,n,returnSize); 
    }
    int totalNQueens(int n)
    {
         int returnSize; 
         solveNQueens(n,&returnSize);
         return returnSize;
    }


   
