#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair<int,int>
#define dii pair<pii,pii>
#define tii pair<pii,int>
#define mx 200001
#define fs first
#define sc second
#define sq 500

int P[mx],ager[mx],pore[mx],ager2[mx],pore2[mx];
pii ara[mx];
vector<pii>my;
vector<tii>vc[600]; // array of vectors
vector<int>ac;

ll sum=0;
inline void func(int x,int y)
{

	if(x<0||y<0)return ;
	sum+=abs(P[x]-P[y]);
}
inline void func2(int x,int y)
{

	if(x<0||y<0)return ;
	sum-=abs(P[x]-P[y]);
}
void rst(int n)
{
   memset(ager,-1,sizeof ager);
   memset(ager2,-1,sizeof ager2);
   memset(pore,-1,sizeof pore);
    memset(pore2,-1,sizeof pore2);

}
inline void linkagesmall(int x,int y,int z)
{
      if(x!=-1)
      {

      	  pore[x]=y;
      	  pore2[x]=z;
      }
      if(y!=-1)
      {
          pore[y]=z;
          ager[y]=x;
      }
      if(z!=-1)
      {
          ager[z]=y;
          ager2[z]=x;
      }
}
inline void linkage(int x,int y,int z,int a)
{
     linkagesmall(x,y,z);
     linkagesmall(y,z,a);
}
int suru[mx],shes[mx],blc[mx];
ll ans[mx];
int main()
{
    int i,j,k,l,m,n;
    scanf("%d",&n);
    //cout<<n<<endl;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&l,&k);
        P[i]=k;
        my.pb(mp(l,i));
      //  cout<<
    }
    sort(my.begin(),my.end());
    for(int i=0;i<n;i++)
    {
        ara[i+1]=my[i];
    }
    int q,bl=0;
    scanf("%d",&q);

    for(int i=1;i<=n;i+=sq)
    {
    	bl++;
       suru[bl]=i;
       shes[bl]=min(i+sq-1,n);
       for(int j=i;j<=shes[bl];j++)blc[j]=bl;//blc contains 1 to 500 as 1 and 501 to 1000 as 2 and so on
    }
        for(int i=1;i<=q;i++)
    {

    	scanf("%d%d",&l,&k);
    	vc[blc[l]].pb(mp(mp(k,l),i));
    }

    for(int b=1;b<600;b++) //the entire vc array size
    {
    	sort(vc[b].rbegin(),vc[b].rend());//reverse sort
    	if(vc[b].size()==0)continue;;
    	rst(n);
    	ac.clear();
       for(int j=1;j<=n;j++){

          if(ara[j].sc<suru[b])continue; //second of ara the 1 indexed beauty sorted vector array
          ac.pb(ara[j].sc);
       }// therefore ac contains all entries whose index is larger than suru[b]
       sum=0;
     //   cout<<"sf"<<" "<<ac.size()<<endl;
       for(int i=0;i<ac.size();i++)
       {
       	 //  cout<<i<<endl;
       	   int indx=ac[i];

           if(i-1>=0){
           	ager[indx]=ac[i-1];
           	//func(ac[i],ac[i-1]);
           }
          // cout<<i<<endl;
           if(i-2>=0){
           	ager2[indx]=ac[i-2];
           	func(ac[i-2],indx);
           }
           if(i+1<ac.size())pore[indx]=ac[i+1];
           if(i+2<ac.size())pore2[indx]=ac[i+2];
       }
     //  cout<<sum<<endl;
        //  cout<<"sf"<<endl;
       int po=n;
       for(int j=0;j<vc[b].size();j++){
           tii ps=vc[b][j];
           int lft=ps.fs.sc;
           int rgt=ps.fs.fs;
           int qs=ps.sc;
           while(po>rgt)
           {
               func2(po,ager2[po]);
               func2(po,pore2[po]);
               func2(ager[po],pore[po]);
               func(ager[po],pore2[po]);
               func(ager2[po],pore[po]);
               linkage(ager2[po],ager[po],pore[po],pore2[po]);
               po--;
           }
           vector<dii>rem;
           vector<int>con;
             int g=lft-suru[b];
           rem.resize(g);
           con.resize(g);
           int id=0;
           for(int p=suru[b];p<lft;p++)
           {
                   func2(p,ager2[p]);
               func2(p,pore2[p]);
               func2(ager[p],pore[p]);
               func(ager[p],pore2[p]);
               func(ager2[p],pore[p]);
               linkage(ager2[p],ager[p],pore[p],pore2[p]);
               rem[id]=(mp(mp(ager2[p],ager[p]),mp(pore[p],pore2[p])));
               con[id++]=p;
          }

           ans[qs]=sum;
           for(int x=id-1;x>=0;x--)
           {
              dii rs=rem[x];
              int c=con[x];
              int age2=rs.fs.fs,age=rs.fs.sc,por=rs.sc.fs,por2=rs.sc.sc;
              func2(age2,por);
              func2(age,por2);
              func(age,por);
              func(c,por2);
              func(c,age2);
              linkagesmall(age2,age,c);
              linkagesmall(age,c,por);
              linkagesmall(c,por,por2);
           }
         //  cout<<qs<<endl;

       }

    }
    for(int i=1;i<=q;i++)
    {

    	printf("%lld\n",ans[i]);
    }

}
////////////////////**********************************///////////////////////////////
//correct but slow code below
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct person{
  int id,beauty,politeness;
};

bool comp(person a, person b){
  return a.beauty < b.beauty;
};

int main(){
  int n,i,a,b,q,l,r,prevOdd,prevEven;
  long int sum;
  bool flag;
  cin >> n;
  person arr[n];
  for(i = 0; i < n; i++){
    cin >> a >> b;
    arr[i] = {i+1,a,b};
  }
  sort(arr,arr+n,comp);
  cin >> q;
  while(q--){
    cin >> l >> r; //only numbers in this range
    prevOdd = -1, prevEven = -1;
    flag = false;
    sum = 0;
    for(i = 0; i < n; i++){
      if(arr[i].id >= l && arr[i].id <= r){
        flag = !flag;
        if(flag){
          if(prevOdd != -1){
            sum += abs(arr[i].politeness - prevOdd);
            prevOdd = arr[i].politeness;
          }
          else{
            prevOdd = arr[i].politeness;
          }
        }
        else{
          if(prevEven != -1){
            sum += abs(arr[i].politeness - prevEven);
            prevEven = arr[i].politeness;
          }
          else{
            prevEven = arr[i].politeness;
          }
        }
      }
    }
    cout << sum << "\n";
  }
  return 0;
}
