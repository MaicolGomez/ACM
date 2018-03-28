long long cuenta(long long n){
    if(n == 0) return 1;
        vector<long long>dev(10,0); 
        for(long long i=1;i<=n;i*=10){ 
            long long a=(n/i)/10;
            for(long long j=0;j<10;j++)dev[j]+=a*i;
            dev[0]-=i;
            for(long long j=0;j<(n/i)%10;j++)dev[j]+=i; 
            dev[(n/i)%10]+= (n%i)+1; 
        }
        return dev[0] + 1;
}

int main(){
    long long m , n;
    while( cin>>m>>n ){
        if(m < 0 && n < 0)break;
        if( m == 0 ){
             if( n == 0 ){ cout<<"1"<<endl; continue; }
             cout<<cuenta( n  )<<endl; continue; 
        }
        cout<<cuenta( n  ) - cuenta( m - 1) <<endl;
    }    
}
