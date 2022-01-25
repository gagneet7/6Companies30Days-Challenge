long long countWays(int m)
    {
        // your code here
        return m/2+1;
        //since order does not matter then there will be 1 case when all 1s are used
        //else we need 2s ie using one 2,then two 2's,then three 2's...
        //so at max we can use m/2 2's
    }
