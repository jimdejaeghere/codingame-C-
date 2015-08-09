#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
using namespace std;
struct El{int fl;int po;bool operator()(El i, El j){return (i.fl < j.fl);}}el;
int main(){
vector<El> le;
int a,b,c,d,e,f,g,h;
cin>>a>>b>>c>>d>>e>>f>>g>>h;
for(int i=0;i<h;i++){
El elv;
cin>>elv.fl>>elv.po;
le.push_back(elv);
sort(le.begin(), le.end(), el);	}
while (1){string k="WAIT",n;int l,m;cin>>l>>m>>n;if(l!=-1){if(l==d){if(m>e&&n=="RIGHT"){k="BLOCK";}if(m<e&&n=="LEFT"){k="BLOCK";}}
else{if(m>le[l].po&&n=="RIGHT"){k="BLOCK";}if(m<le[l].po&&n=="LEFT"){k="BLOCK";}}}cout<<k<<endl;}}