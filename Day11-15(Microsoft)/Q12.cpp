vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        sort(arr.begin(),arr.end());
        unordered_set<string> m;
        vector<vector<int> > ans;
        int n=arr.size();

        for(int i=0;i<=n-4;i++)
        {
            for(int j=i+1;j<=n-3;j++)
            {
                    int s=j+1,e=n-1;

                    int sum=arr[i]+arr[j];
                    int r=k-sum;
                    while(s<e)//find pair with sum=r from rest of the array
                    {
                        if(arr[s]+arr[e]==r)
                        {
                            string a="";
                            a+=arr[i];
                            a+=arr[j];
                            a+=arr[s];
                            a+=arr[e];

                            if(m.find(a)==m.end())
                            {
                                vector<int> t;
                                m.insert(a);
                                t.push_back(arr[i]);
                                t.push_back(arr[j]);
                                t.push_back(arr[s]);
                                t.push_back(arr[e]);
                                ans.push_back(t);
                            }
                            s++;
                            e--;
                        }

                        else if(r>arr[s]+arr[e])s++;
                        else e--;
                    }

                }
            }

        return ans;
    }
