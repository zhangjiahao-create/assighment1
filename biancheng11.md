问题:


     给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
     示例 1:
     输入: "abcabcbb"
     输出: 3 
     解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
     示例 2:
     输入: "bbbbb"
     输出: 1
     解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
     示例 3:
     输入: "pwwkew"
     输出: 3


解释: 
     

     因为无重复字符的最长子串是 "wke"，所以其长度为 3。请注意，你
     的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。


代码:
     

      int lengthOfLongestSubstring(char * s)
      {
             int n=0;
             while(s[n++]!='\0');
             n--;
             int times = 1,sum = 0,temp=0,k=0,i,j;
             for(i=0;i<n-1;i++)
             {
                      if(s[i]!=s[i+1])
	              {
                              for(j=i;j>=k;j--)
                                       if(s[i+1]==s[j])
		                       {
                                               temp = 1;
                                               break;
		                       }
		              if(temp==1)
		                       temp = 0;
		              else
		                       temp = 1;
	              }
	              else 
	              {
	                      j=i;
	              }  
                      if(temp==1)
                      {
                              times ++;
                              if(times>sum)
                                       sum = times;
                              temp = 0;
                      }
                      else if(temp==0)
                      {
                              if(times>sum)
                              {
                                       sum = times;
                              }
                              k = j+1;
                              i=j;
                              times = 1;
                      }    
             }
             if(n==1)
                      sum = 1;
             else if(n==0)
                      sum = 0;
             return sum;               
      }
