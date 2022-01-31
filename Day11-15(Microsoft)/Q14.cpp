 int minSteps(int D){
        // code here
        int steps = 0, sum = 0;

        while(true){
            sum = sum + steps;
            if(sum == D){
                return steps;
                break;
            }
            if(sum > D and (sum-D)%2 == 0){
                return steps;
                break;
            }
             steps++;
        }
        return 0;
    }
