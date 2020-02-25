问题：
   

    将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

    比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

    L   C   I   R
    E T O E S I I G
    E   D   H   N

    之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

    请你实现这个将字符串进行指定行数变换的函数：

    string convert(string s, int numRows);

    示例 1:

    输入: s = "LEETCODEISHIRING", numRows = 3
    输出: "LCIRETOESIIGEDHN"

    示例 2:

    输入: s = "LEETCODEISHIRING", numRows = 4
    输出: "LDREOEIIECIHNTSG"
    解释:

    L     D     R
    E   O E   I I
    E C   I H   N
    T     S     G

代码：
    

```
char* convert(char * s, int numRows)
{
      int n = strlen(s);
      char** temp = (char**)malloc(sizeof(char*)*numRows);
      for(int p = 0;p<numRows;p++)
      {
           temp[p] = (char*)calloc(1200,sizeof(char));
      }
      int j = 0,i = 0,at = 0,times = 1;
      while(times == 1)
      {
           for(;i<numRows-1;i++)
           {
               if(at==n)
               {
                    times = 0;
                    break;
               }
               temp[i][j] = s[at++];
           }
           if(times == 1)
           for(;i>0;j++)
            {
               if(at==n)
               {
                    times = 0;
                    break;
               }
               temp[i--][j] = s[at++];
            }
            if(numRows == 1)
                times = 0;
      }
      char* leap = (char*)malloc(sizeof(char)*1200);
      int l = 0;
      if(numRows>=2)
      for(int p = 0;p<numRows;p++)
            for(int q = 0;q<j+1;q++)
                if(temp[p][q]!=0)
		{
                     leap[l++] = temp[p][q];
		}
       leap[l] = 0;
       for(i=0;i<numRows;i++)
            free(temp[i]);
        free(temp);
       if(numRows==1)
          leap = s;
       return leap;
}
```

