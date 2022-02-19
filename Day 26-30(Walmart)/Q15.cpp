 int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        int sign;
        if(dividend<0&&divisor<0)sign=1;
        else if(dividend<0||divisor<0)sign=-1;
        else sign=1;

        long dvd = labs(dividend), dvs = labs(divisor), ans = 0;//labs is used for taks abs value of long

        while (dvd >= dvs)
        {
            long temp = dvs, m = 1;
            while( (temp << 1) <= dvd)
            {
                temp <<= 1;
                m <<= 1;
            }
            dvd -= temp;
            ans += m;
        }
        return sign * ans;
    }
