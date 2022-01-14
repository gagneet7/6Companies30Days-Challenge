int doOverlap(int L1[], int R1[], int L2[], int R2[]) {
        // code here


       if(L1[0]>R2[0]||L2[0]>R1[0])return 0;//if rect 1 is completely on right of rect 2
                                              //if rect 1 is completely on left of rect 2

       if(R1[1]>L2[1]||R2[1]>L1[1])return 0;//if rect 1 is completely above rect 2
                                              //if rect 1 is completely below rect 2

       return 1;


    }
