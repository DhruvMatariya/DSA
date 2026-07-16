class Solution {
public:
    int secondsBetweenTimes(string a, string b) {
        string x1=a.substr(0,2);
         string x2=b.substr(0,2);
         string y1=a.substr(3,2);
         string y2=b.substr(3,2);
         string z1=a.substr(6,2);
         string z2=b.substr(6,2);
         int sum=0;
         sum+=(60*60*(stoi(x2)-stoi(x1)));
         sum+=(60*(stoi(y2)-stoi(y1)));
         sum+=(stoi(z2)-stoi(z1));
         return sum;



    }
};