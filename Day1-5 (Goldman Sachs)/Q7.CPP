int findPosition(int N , int M , int K) {
        // code here
        if(M<=N-K+1)return M+K-1;//if remaining toys can be adjusted in remaining circle in first distribution

        M=M-(N-K+1);//now starting position of circle is 1 and we just need to check where the last toy will be delivered
        return M%N==0?N:M%N;
    }
