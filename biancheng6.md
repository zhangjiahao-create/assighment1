问题：
    给定一个未排序的整数数组，找出其中没有出现的最小的正整数。

    示例 1:

    输入: [1,2,0]
    输出: 3

    示例 2:

    输入: [3,4,-1,1]
    输出: 2

    示例 3:

    输入: [7,8,9,11,12]
    输出: 1
代码：
    int firstMissingPositive(int* nums, int numsSize)
    {
          int i;
          //标记数组
          int *B = (int*)malloc(sizeof(int)*(numsSize+1));
          //赋初值为0
          memset(B,0,sizeof(int)*(numsSize+1));
          //若nums[i]的值介于1~numsSize，则标记数组
          for(i = 0;i<numsSize;i++)
          {
                if(nums[i]>0 && nums[i]<=numsSize)
                {
                      B[nums[i]]=1;
                }
          }
          //遍历数组
          for(i=1;i<=numsSize;i++)
          {
                 if(B[i]==0) break;
          }
          return i;
      }
