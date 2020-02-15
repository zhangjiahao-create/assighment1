问题:
    

     给定一个正整数数组 A,如果A的某个子数组中不同整数的个数恰好为K,
     则称A的这个连续,不一定独立的子数组为好子数组.(例如，[1,2,3,1,2]
     中有 3 个不同的整数：1，2，以及 3。）返回A中好子数组的数目。


示例 1：
      

     输出：A = [1,2,1,2,3], K = 2
     输入：7
     解释：恰好由 2 个不同整数组成的子数组：[1,2], [2,1], [1,2], [2,3], 
     [1,2,1], [2,1,2], [1,2,1,2].


示例 2：


     输入：A = [1,2,1,3,4], K = 3
     输出：3
     解释：恰好由 3 个不同整数组成的子数组：[1,2,1,3], [2,1,3], [1,3,4].


提示：
    

    1. 1 <= A.length <= 20000
    2. 1 <= A[i] <= A.length
    3. 1 <= K <= A.length


代码:


     int subarraysWithKDistinct(int* A, int ASize, int K)
     {
            int times =0,sum = 0,left = 0;
            int *array = (int*)calloc(ASize+1,sizeof(int));
            for(int i=0;i<ASize;)
            {
                  if(array[A[i]] == 0)
                        times++;
                  array[A[i]]++;
                  while(times>K)
                  {
                        if(--array[A[left++]]==0)
                              times--;
                  }
                  int left1 = left;
                  if(times == K)
                  {
                        while(times==K)
                        {
                              if(--array[A[left1++]]==0)
                                  times--;
                              sum++;
                        }
                        for(int j = left;j<left1;j++)
                              if(array[A[j]]++ == 0)
                                   times++;
                  }
                  i++;
            }
            return sum;
     }
