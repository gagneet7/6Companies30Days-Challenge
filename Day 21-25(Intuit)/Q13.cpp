int zerosAtEnd(vector<int> &a) {
        int ans = 0;
        int n = a.size();
        int i=n-1;
        while (i >= 0 && a[i] == 0) {
            ans++;
            i--;
        }
        return ans;
    }

    int minSwaps(vector<int> &a) {
        int n = a.size();
        int ans = 0;
        for (int i=0; i<n; i++)
        {
            if (a[i] < (n-i-1))//means this ith row must be swapped
            {
                int j=i;
                while (j < n && a[j] < (n-i-1)) j++;//finding idx with 0's =n-i-1

				 if (j == n)  return -1;   // Did not find any number greater than or equal to n-i-1.
                                           // so its impossible to get the answer.

                while (j>i) //bringing jth row to ith pos by swapping one row upwards
                {
                    swap(a[j], a[j-1]);
                    ans++;
                    j--;
                }
            }
        }
        return ans;
    }

    int minSwaps(vector<vector<int>>& grid) {
        vector<int> a ;
        for (auto &x: grid) {
            a.push_back(zerosAtEnd(x));
        }
        return minSwaps(a);
    }
