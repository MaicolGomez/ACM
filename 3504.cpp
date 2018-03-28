#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<climits>
#include<set>
#include<deque>
#include<queue>
#include<map>
#include<climits>
#include<string>
#include<stack>
#include<sstream>
using namespace std;
#define pi (2.0*acos(0.0))
#define eps 1e-6
#define ll long long
#define inf (1<<29)
#define vi vector<int>
#define vll vector<ll>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define all(v) v.begin() , v.end()
#define me(a,val) memset( a , val ,sizeof(a) )
#define pb(x) push_back(x)
#define pii pair<int,int> 
#define mp(a,b) make_pair(a,b)
#define Q(x) (x) * (x)
#define L(x) ((x<<1) + 1)
#define R(x) ((x<<1) + 2)
#define M(x,y) ((x+y)>>1)
#define fi first
#define se second
#define MOD 10009
#define ios ios::sync_with_stdio(0);
#define N 2500005

bool t[11][N] , done[11][N];

bool h(int B,int n){
    int nn = 0 , r = n , it = 0;
    while( r != 1 ){
        if( it++ > 1000 )break;
        while( r > 0 ){
            int g = (r%B);
            nn += g * g;
            r /= B;
        }
        r = nn;
    }
    return it > 999;
}

bool f(int B,int n){
    if( n == 1 ) return 1;
    if( done[B][n] ) return t[B][n];
    done[B][n] = 1;
    t[B][n] = 0;
    int nn = 0 , r = n;
    while( r > 0 ){
        int g = (r%B);
        nn += g * g;
        r /= B;
    }
    return t[B][n] = f( B , nn );
}

vi adj[11];
int R[N] , A[2000];

int main(){

    for(int i = 3 ; i <= 10 ; i++)
        for(int j = 2 ; j < N ; j++)
            if( f( i , j ) ) adj[i].pb( j );
    
    for(int i = 0 ; i < 8 ; i++){
        for(int j = 0 ; j < adj[i+3].size() ; j++){
            //if( adj[i+3][j] == 3 ) cout << i + 3 << endl;
            R[ adj[i+3][j] ] |= (1<<i);
        }
    }
    
    for(int i = 1 ; i < 1<<8 ; i++){
        for(int j = 2 ; j < N ; j++)
            if( (R[j]&i) == i ){
                A[i] = j;
                //if( i&(1<<6) ) cout << "A[" << i << "] = " << j << ";" << endl; 
                break;
            }
    }
    A[64] = 3;
    A[65] = 3;
    A[66] = 3;
    A[67] = 3;
    A[68] = 27;
    A[69] = 27;
    A[70] = 27;
    A[71] = 27;
    A[72] = 415;
    A[73] = 707;
    A[74] = 415;
    A[75] = 707;
    A[76] = 415;
    A[77] = 1695;
    A[78] = 415;
    A[79] = 1695;
    A[80] = 125;
    A[81] = 143;
    A[82] = 125;
    A[83] = 143;
    A[84] = 125;
    A[85] = 143;
    A[86] = 125;
    A[87] = 143;
    A[88] = 2753;
    A[89] = 37131;
    A[90] = 2753;
    A[91] = 37131;
    A[92] = 37131;
    A[93] = 37131;
    A[94] = 37131;
    A[95] = 37131;
    A[96] = 27;
    A[97] = 27;
    A[98] = 27;
    A[99] = 27;
    A[100] = 27;
    A[101] = 27;
    A[102] = 27;
    A[103] = 27;
    A[104] = 4977;
    A[105] = 10089;
    A[106] = 4977;
    A[107] = 10089;
    A[108] = 4977;
    A[109] = 23117;
    A[110] = 4977;
    A[111] = 23117;
    A[112] = 6393;
    A[113] = 35785;
    A[114] = 6393;
    A[115] = 35785;
    A[116] = 6393;
    A[117] = 128821;
    A[118] = 6393;
    A[119] = 128821;
    A[120] = 569669;
    A[121] = 569669;
    A[122] = 569669;
    A[123] = 569669;
    A[124] = 569669;
    A[125] = 569669;
    A[126] = 569669;
    A[127] = 569669;
    A[128] = 7;
    A[129] = 13;
    A[130] = 7;
    A[131] = 13;
    A[132] = 7;
    A[133] = 23;
    A[134] = 7;
    A[135] = 23;
    A[136] = 44;
    A[137] = 79;
    A[138] = 44;
    A[139] = 79;
    A[140] = 49;
    A[141] = 79;
    A[142] = 49;
    A[143] = 79;
    A[144] = 7;
    A[145] = 167;
    A[146] = 7;
    A[147] = 167;
    A[148] = 7;
    A[149] = 7895;
    A[150] = 7;
    A[151] = 7895;
    A[152] = 49;
    A[153] = 6307;
    A[154] = 49;
    A[155] = 6307;
    A[156] = 49;
    A[157] = 7895;
    A[158] = 49;
    A[159] = 7895;
    A[160] = 97;
    A[161] = 219;
    A[162] = 97;
    A[163] = 219;
    A[164] = 219;
    A[165] = 219;
    A[166] = 219;
    A[167] = 219;
    A[168] = 608;
    A[169] = 3879;
    A[170] = 608;
    A[171] = 3879;
    A[172] = 3879;
    A[173] = 3879;
    A[174] = 3879;
    A[175] = 3879;
    A[176] = 34527;
    A[177] = 48041;
    A[178] = 34527;
    A[179] = 48041;
    A[180] = 34527;
    A[181] = 120407;
    A[182] = 34527;
    A[183] = 120407;
    A[184] = 245035;
    A[185] = 697563;
    A[186] = 245035;
    A[187] = 697563;
    A[188] = 245035;
    A[189] = 2688153;
    A[190] = 245035;
    A[191] = 2688153;
    A[192] = 91;
    A[193] = 91;
    A[194] = 91;
    A[195] = 91;
    A[196] = 91;
    A[197] = 91;
    A[198] = 91;
    A[199] = 91;
    A[200] = 1033;
    A[201] = 6073;
    A[202] = 1033;
    A[203] = 6073;
    A[204] = 4577;
    A[205] = 6073;
    A[206] = 4577;
    A[207] = 6073;
    A[208] = 1337;
    A[209] = 1337;
    A[210] = 1337;
    A[211] = 1337;
    A[212] = 29913;
    A[213] = 120149;
    A[214] = 29913;
    A[215] = 120149;
    A[216] = 71735;
    A[217] = 613479;
    A[218] = 71735;
    A[219] = 613479;
    A[220] = 218301;
    A[221] = 711725;
    A[222] = 218301;
    A[223] = 711725;
    A[224] = 1177;
    A[225] = 1177;
    A[226] = 1177;
    A[227] = 1177;
    A[228] = 1177;
    A[229] = 1177;
    A[230] = 1177;
    A[231] = 1177;
    A[232] = 9867;
    A[233] = 28099;
    A[234] = 9867;
    A[235] = 28099;
    A[236] = 28099;
    A[237] = 28099;
    A[238] = 28099;
    A[239] = 28099;
    A[240] = 48041;
    A[241] = 48041;
    A[242] = 48041;
    A[243] = 48041;
    A[244] = 246297;
    A[245] = 346719;
    A[246] = 246297;
    A[247] = 346719;
    A[248] = 2662657;
    A[249] = 4817803;
    A[250] = 2662657;
    A[251] = 4817803;
    A[252] = 11814485;
    A[253] = 11814485;
    A[254] = 11814485;
    A[255] = 11814485;
    
    for(int i = 2 ; i < 11 ; i++)
        cout << i << " " << h( i , 29113769 ) << endl;
    
    char s[100];
    int tc , test = 0;
    sc(tc);
    gets(s);
    while(tc--){
        gets(s);
        int x , mask = 0;
        stringstream in(s);
        while( in >> x ){
            if( x == 2 ) continue;
            mask |= (1<<(x-3));
        }
        //cout << "mask " << mask << endl;
        if( mask == 0 ) printf("Case #%d: %d\n",++test, 2 );
        //else if( mask == 255 ) printf("Case #%d: %d\n",++test, 29113769 );
        else printf("Case #%d: %d\n",++test,A[mask]);
    }
    return 0;
}
