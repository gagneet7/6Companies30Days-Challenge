int versionCompare(string v1, string v2)
{
    int num1 = 0, num2 = 0;

    for(int i=0,j=0;(i < v1.length()|| j < v2.length());)
    {
        num1=num2=0;//for calculating values of numbers before each . in v1 and v2
         while (i<v1.length()&&v1[i]!='.')
         {
             num1=num1*10+(v1[i] - '0');
             i++;
         }


        while (j < v2.length() && v2[j] != '.')
        {
            num2 = num2 * 10 + (v2[j] - '0');
            j++;
        }

        if (vnum1 > vnum2)
            return 1;
        if (vnum2 > vnum1)
            return -1;

        i++;
        j++;
    }
    return 0;
}
