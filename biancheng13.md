# 问题：


    n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
    给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。每一种解法包含一个明确的 n 皇后
    问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。


# 示例:


    输入: 4
    输出:[
         [".Q..",  // 解法 1
          "...Q",
          "Q...",
          "..Q."],
         ["..Q.",  // 解法 2
          "Q...",
          "...Q",
          ".Q.."]
        ]
    解释: 4 皇后问题存在两个不同的解法。


# 代码：
    
    
    #define N 100
    #define MAX 120000
    int sample[3][2] = {{-1,0},{-1,-1},{-1,1}};
    bool temp[N][N];
    char ***res = NULL;
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
              char **res1 = (char**)malloc(sizeof(int*)*n);
              //*returnSize +=1;
              (*returnSize)++;
              for(int q=0,p;q<n;q++)
              {
                   res1[q] = (char*)malloc(sizeof(char)*(n+1));
                   for(p =0;p<n;p++)
                   {
                        if(temp[q][p]==0)
                        res1[q][p] = '.';
                        else if(temp[q][p]==1)
                        res1[q][p] = 'Q';
                   }
                   res1[q][p] = '\0';
              } 
              res[*returnSize-1] = res1;
              //(*returnSize)+=1;
              return;
         }
         else
         {
              for(i=0;i<n;i++)
              {
                   temp[heng][i] = true;
                   if(judge(heng,i,n)==false)
                   {
                        temp[heng][i] = false;
                        continue;
                   }
                   //temp[heng][i] = true;
                   dif(heng+1,n,returnSize);
                   temp[heng][i] = false;
             }
         }
    }
    char *** solveNQueens(int n, int* returnSize, int** returnColumnSizes)
    {
         *returnSize = 0;
         memset(temp,0,sizeof(temp));
         res = (char ***)malloc(MAX * sizeof(char **));
         dif(0,n,returnSize);
         *returnColumnSizes = (int*)malloc(sizeof(int)*(*returnSize));
         for(int l=0;l<*returnSize;l++)
         (*returnColumnSizes)[l] = n;
         return res;
     }
