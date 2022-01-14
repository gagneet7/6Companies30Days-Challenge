string encode(string str)
{
  //Your code here
  int f=1;
  char c=str[0];
  string result="";
  result+=c;

  for(int i=1;i<str.length();i++)
  {
      if(str[i]==c)f++;
      else
      {
          result+=to_string(f);
          c=str[i];
          f=1;
          result+=c;
      }
  }
  result+=to_string(f);
  return result;
}
