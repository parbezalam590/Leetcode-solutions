class Solution {
public:

     typedef long long ll;
    ll gcd(ll a, ll b){
        if (b==0) return a;
        return gcd(b,a%b);
    }
    string fun(ll tem,int fs){
        string str;
        for (int i=9;i>=2;i--){
            while(tem%i==0){
                str.push_back(i+'0');
                tem/=i;
            }
        }
        while(str.size()<fs){
            str.push_back('1');
        }
        reverse(str.begin(),str.end());
        return str;
    }
    
    string smallestNumber(string num, long long tem) {
        int n= num.size();
        ll t= tem;
        while(t>1){
            if (t%2==0){
                t/=2;
            }
            else if (t%3==0){
                t/=3;
            }
            else if (t%5==0){
                t/=5;
            }
            else if (t%7==0){
                t/=7;
            }
            else {
                break;
            }
        }
        if (t!=1) return "-1";
        vector<ll> remfact(n+1,tem);
        for (int i=0;i<n;i++){
            int cur=num[i]-'0';
            if (cur==0) break;
            remfact[i+1]= remfact[i]/gcd(remfact[i],cur);//precomputation
        }

        if (remfact[n]==1) return num;//if no factor remains return the given string
        int zidx=n-1;
        int zero= num.find('0');
        if (zero!=-1){
            zidx= zero;
        }
        for (int i= zidx; i>=0;i--){
            ll req= remfact[i];
            int fs= n-i-1;
            for (int d= (num[i]-'0')+1;d<=9;d++){
                ll freq= req/gcd(d,req);
                string temp= fun(freq,fs);
                if (temp.size()==fs) return num.substr(0,i)+char(d+'0')+temp;
            }

        }
        return fun(tem,n+1);


    }
};