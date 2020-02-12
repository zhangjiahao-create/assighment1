问题：
    

    给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
    示例 1：
    输入: "babad"
    输出: "bab"
    注意: "aba" 也是一个有效答案。
    示例 2：
    输入: "cbbd"
    输出: "bb"


代码：
   

      char * longestPalindrome(char * s)
      {
            int n = strlen(s);
            int start = 0;
            int temp = 0;
            int sum = 0;
            for(int i=0;i<n;i++)
                  for(int j=n-1;j>=i+1;j--)
                      if(s[i]==s[j])
                      {
                              for(int p=i,q=j;p<=q;)
                                     if(s[p++]!=s[q--])
                                     { 
                                           temp = 1;
                                           break;
                                     }
                             if(temp == 0)
                             {
                                     if(j-i+1>sum)
                                     {
                                          sum = j-i+1;
                                          start = i;
                                     }
                                    break;
                             }
                            else  if(temp == 1)
                                    temp =0;
                     }
             if(sum==0&&n!=0)
                    s[start+1]='\0';
             else
                    s[start+sum]='\0';
             return s+start;
      }
