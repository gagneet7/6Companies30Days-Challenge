string FirstNonRepeating(string s){
		    // Code here
		    string res="";
		    int freq[26]={0};
		    queue<char> q;


		    for(int i=0;i<s.length();i++)
		    {

		        if(freq[s[i]-97]==0){q.push(s[i]);freq[s[i]-97]++;}
		        else
		        {   //if a char occurs more than once then we will only pop it if it is at begin
                    freq[s[i]-97]++;
                    while(!q.empty()&&freq[q.front()-97]>1)q.pop();//if freq <=1 the no need to pop else we need to pop that element
		        }

		        if(q.empty())res+='#';
		        else res+=q.front();
		    }


		    return res;
		}
