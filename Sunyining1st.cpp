//2-5-9559
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int b[101]={0},c[201]={0};
	string s2;
	int len3;
	for(int i=1;i<=n;i++){
		cin>>s2;
		memset(b,0,sizeof(b));
		int len1=s2.size();
		len3 = max(len1, len3) + 1;
		for(int j=0;j<len1;j++){
			b[len1-j-1]=s2[j]-'0';
		}
		for(int j=0;j<len3;j++){
			c[j]+=b[j];
		}
		for(int j=0;j<len3-1;j++){
			c[j+1]+=c[j]/10;
			c[j]%=10;
		}
		while(len3>1&&c[len3-1]==0){
			len3--;
		}
	}
	len3+=3;
	for(int i=0;i<len3;i++){
		c[i]*=(n-1);
	}
	for(int i=0;i<len3-1;i++){
		c[i+1]+=c[i]/10;
		c[i]%=10;
	}
	while(len3>1&&c[len3-1]==0){
		len3--;
	}
	for(int i=0;i<len3;i++){
		cout<<c[len3-i-1];
	}
}


/*
//2-5-9559
#include<bits/stdc++.h>
using namespace std;
struct Place {
    double l;
    double r;
}p[15005];
bool cmp(struct Place p1, struct Place p2) {
    return p1.l<p2.l;
}
int main() {
    int T, n, L;
	double W;
    cin>>T;
    for(int t=1; t<=T; t++) {
    	cin>>n>>L>>W;
    	int cnt=0;
    	for(int i=1; i<=n; i++) {
    		int pos;
			double r;
    		cin>>pos>>r;
    		W/=2;
	    	p[cnt].l=pos-(sqrt(r*r-W*W));
	    	p[cnt].r=pos+(sqrt(r*r-W*W));
//			printf("l is %lf, r is %lf\n", (p[cnt].l), p[cnt].r);
			cnt++;
		}
	    sort(p, p+cnt, cmp);
	    int ans=0;
	    double start=0;
	    int idx=0;
	    bool flag=true;
	    double rmax;
    	while((idx<cnt)&&((double)start<L)) {
//			printf("again: l is %lf, r is %lf\n", (p[idx].l), p[idx].r);
			rmax=-1;
			if(p[idx].l>start) {
				flag=false;
				break;
			}
			for(int j=idx; j<cnt; j++) {
				if(p[j].l<=start) {
					rmax=max(rmax, p[j].r);
					idx++;
				} else{
					break;
				}
			}
			if(rmax==-1) {
				flag=false;
				break;
			}
			start=rmax;
			ans++;
		}
		
		if(start<L) flag=false;
		if(flag) {
		   cout<<ans<<endl;
	   	}else{
		   cout<<"-1"<<endl;
		}
    }
	return 0;
}
//2-5-9559
#include<bits/stdc++.h>
using namespace std;
struct Place {
    int l;
    int r;
}island[1005];
bool cmp(struct Place p1, struct Place p2) {
    return p1.r<p2.r;
}
int main() {
    int n, d;
    cin>>n>>d;
    int ans=0;
    for(int i=1; i<=n; i++) {
        int x,y;
        cin>>x>>y;
        if(y>d) {
            cout<<-1;
            return 0;
        }
        // 1 2 l=-3-genhao3, r=-3+genhao3
        // -3 1
        // l be larger, r be smaller
        island[i].l=x-floor(sqrt(d*d-y*y));
        island[i].r=x+floor(sqrt(d*d-y*y));
//        cout<<island[i].l<<" "<<island[i].r<<endl;
    }
    sort(island+1, island+n+1, cmp);
    int q=-999999;
    for(int i=1; i<=n; i++) {
    	// can't be ">="
        if(island[i].l>q) {
            q=island[i].r;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}

//2-5-8106
#include<bits/stdc++.h>
using namespace std;
struct Lesson {
	int begin;
	int end;
}lesson[1009];
bool cmp(struct Lesson x, struct Lesson y) {
	return x.end<y.end;
}
int main() {
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>lesson[i].begin>>lesson[i].end;
	}
	sort(lesson+1, lesson+n+1, cmp);
	int ans=1;
	int idx=1;
//	cout<<lesson[1].begin<<" "<<lesson[1].end<<endl;
	for(int i=2; i<=n; i++) {
//		cout<<lesson[i].begin<<" "<<lesson[i].end<<endl;
// 0 4; 0 6; 4 8
		if((lesson[i].begin) >= (lesson[idx].end)) {
			ans++;
			idx=i;
		}
	}
	cout<<ans;
	return 0;
}
//2-5-8106
#include<bits/stdc++.h>
using namespace std;
int main() {
	// 10 20->15 15
	// L10 R15
	// a [10,15] b[10,15] [20, 30]
	// 38 	1 	11 12 13 sum=75 [50, 75]
	// -14	+14	11	12	13 ans+=14
	// 24	15	11 12 13
	// 15	15	15	15	15 ans+=9
	// 5 6 8 21; 11, 6 
	// 
	int n;
	int a[60];
	cin>>n;
	int l, r;
	int sum=0;
	int sub=0, pluss=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	cin>>l>>r;
	for(int i=1; i<=n; i++) {
		sum+=a[i];
		if(a[i]>r) {
			sub+=a[i]-r;
		}else if(a[i]<l) {
			pluss+=l-a[i];
		}
	}	

	if((sum<n*l) || (sum>n*r)) {
		cout<<-1;
	} else {
		cout<<max(sub, pluss);
	}
	return 0;
}

//2-5-9853
#include<bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin>>s;
	int n;
	cin>>n;
	//175438 134578
	//8 7 5 4 3
	//100002 2 000012 delete 12, 
	//00002
	//1002 1 0012  delete 2
	//120005614 0001 12456 5
	//1000
	//12005614 1205614 
	//6775
	while(n!=0) {
		string s1="";
		int idx=s.size()-1;
		for(int i=1; i<s.size(); i++) {
			if(s[i]<s[i-1]) {
				idx=i-1;
				break;
			}
		}
//		if(idx==-1) {
//			cout<<s[s.size()-1];
//			return 0;
//		}
		for(int i=0; i<idx; i++) {
			s1+=s[i];
		}
		for(int i=idx+1; i<s.size(); i++) {
			s1+=s[i];
		}
		s=s1;
//		cout<<s1<<endl;
		n--;
	}
	bool leadingzero=true;
	for(int i=0; i<s.size(); i++) {
		if(s[i]=='0') {
			if(!leadingzero) cout<<s[i];
		} else {
			leadingzero=false;
			cout<<s[i];			
		}
	}
	if(leadingzero) cout<<0;
	return 0;
}

//2-5-8103
#include<bits/stdc++.h>
using namespace std;
int a[100001];
bool cmp(int x, int y) {
	return x>y;
}
int main() {
//7 1 400 2 2
// 1 2 7 400
// 7 1 400 --- 400 7 2
// 2 2 7 400
// 400 2 2 7
// 400 1 2 7
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a+1, a+n+1, cmp);
	int ans=0;
	for(int i=1; i<=n; i++) {
		//i=1, a[1]=400
		//i=2, a[2]=7
		//i=3, a[3]=2
		//i=4, a[4]=2
		if(i-1<=a[i]) {
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
//2-5-8103
#include<bits/stdc++.h>
using namespace std;
int ab[5001];
int main() {
	int n,s;
	int a,b;
	cin>>n>>s;
	cin>>a>>b;
	// a+b
	int cnt=1;
	for(int i=1; i<=n; i++) {
		int x1, y1;
		scanf("%d%d", &x1,&y1);
		if(x1>a+b) continue;
		ab[cnt]=y1;
		cnt++;
	}
	sort(ab+1, ab+cnt);
	int ans=0;
	for(int i=1; i<cnt; i++) {
		if(s>ab[i]) {
			s-=ab[i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

//2-5-8100
#include<bits/stdc++.h>
using namespace std;
int a[100001]={0};
int main() {
	int n,x;
	cin>>n>>x;
	for(int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
	}
	int eat=0;
	int sum=0;
	for(int i=2; i<=n; i++) {
		if(a[i]+a[i-1]>x) {
			eat=a[i]+a[i-1]-x;
			if(eat>a[i]) {
				a[i]=0;
				a[i-1]-=(eat-a[i]);
			} else{
				a[i]-=eat;
			}
			sum+=eat;
		}
	}
	cout<<sum;
}
//2-5-8100
#include<bits/stdc++.h>
using namespace std;
struct Data{
	int idx;
	int time;
}a[1001];
//10
//56 12 1 99 1000 234 33 55 99 812
//1 12 33 ...
//(n-1)a[1]+(n-2)a[2]
bool cmp(struct Data d1, struct Data d2) {
	if(d1.time<d2.time) {
		return true;
	}else if(d1.time==d2.time) {
		return d1.idx<d2.idx;
	}else{
		return false;
	}
}
int main() {
	int n;
	cin>>n;
	memset(a, 0, sizeof(a));
	for(int i=1; i<=n; i++) {
		a[i].idx=i;
		cin>>a[i].time;
	}
	sort(a+1, a+n+1, cmp);
	double sum=0;
	for(int i=1; i<=n; i++) {
		cout<<a[i].idx<<" ";
		sum+=(n-i)*a[i].time;
	}
	cout<<endl;
	printf("%.2f\n", sum/n);
	return 0;
}
//2-3-7719
#include<bits/stdc++.h>
using namespace std;
int a[5001];
int ac[500010]={0};
int c[5][500010];
int main() {
	int n;
	cin>>n;
	// 4			3		2		1
	// 1 2 3 4		1 2 3	1 2		1
	// 1 2 34		1 23
	// 1 234		12 3
	// 12 3 4		123
	// 12 34
	// 123 4
	// 1234
	// 8 4 2 1 
	// f(n)=2^(n-1) 2^5000
	ac[0]=1;
	int len=1;
	n--;
	while(n>0) {
		for(int i=0; i<len; i++) {
			ac[i]*=2;
		}
		len+=1;
		for(int i=0; i<len-1; i++) {
			ac[i+1]+=ac[i]/10;
			ac[i]%=10;
		}
		while(ac[len-1]==0&&len>1) len--;
		n--;
	}
	for(int i=len-1; i>=0; i--) {
		cout<<ac[i];
	}
	return 0;
}

//2-3-7712
#include<bits/stdc++.h>
using namespace std;
int a[5001];
int ac[500010]={0};
int c[5][500010];
int main() {
	int n;
	cin>>n;
	// i, n-i; n-i-j;
	// m*(m+1)/2=n
	// 12
	// 2 3 4 3 
	// 3 4 5
	int sum=0;
	int r;
	int i;
	for(i=2; i<=n; i++) {
		a[i]=i;
		sum+=i;
		if(sum>n) break;
	}
	int len=i-1;
	sum-=i;
	r=n-sum;
	while(r>0) {
		r--;
		a[len--]++;
	}
	len=i-1;	
	int len1=1;
	ac[0]=1;
	for(i=2; i<=len; i++) {
		cout<<a[i]<<" ";
		// gjd  multiply
		//98*99*100*101 b[5]
		int temp=a[i];
		int idx=0;
		int b[5]={0};
		while(temp!=0) {
			b[idx++]=temp%10;
			temp/=10;
		}
		// 1231*23
		//ans[]=[1,2,3,1]
		//c[0][]=[3,6,9,3]
		//c[1][]=[2,4,6,2,0]
		//c[0]=
		memset(c, 0, sizeof(c));
		for(int j=0; j<idx; j++) {
			for(int k=0; k<len1; k++) {
				c[j][k+j]+=b[j]*ac[k];
			}
		}
		len1+=idx+1;
		memset(ac, 0, sizeof(ac));
		for(int k=0; k<len1; k++) {
			for(int j=0; j<idx; j++) {
				ac[k]+=c[j][k];
			}
		}
		for(int j=0; j<len1-1; j++) {
			ac[j+1]+=ac[j]/10;
			ac[j]%=10;
		}
		while(ac[len1-1]==0&&len1>1) len1--;
	}
	cout<<endl;
	for(int j=len1-1; j>=0; j--) {
		cout<<ac[j];
	}
	return 0;
}
//2-3-7717
#include<bits/stdc++.h>
using namespace std;
string s[1001];
long long res[110]={0};
// 1000 100bits
// 2 100bits 101
// 100*1000
// 99+99=198
// 198+99=300
// 300+100=400
// 100+1000*100=1001*100=100000
// 
int a[105]={0};
long long ans[120]={0};
int main() {
	int n;
	cin>>n;
	int len=0;
	for(int i=1; i<=n; i++) {
		cin>>s[i];
		int sz=s[i].size();
		memset(a, 0, sizeof(a));
		for(int j=0; j<sz; j++) {
			a[sz-j-1] = s[i][j]-'0';
		}
		len=max(len, sz);
		for(int j=0; j<len; j++) {
			res[j]+=a[j];
		}
	}
	//1000*100
	len+=12;//1+4+4
	int factor=(n-1)*(n-2)/2;
	for(int i=0; i<len; i++) {
		ans[i]=res[i]*factor; // 1000*9*1000*1000=9000000000
	}
	for(int i=0; i<len-1; i++) {
		ans[i+1]+=ans[i]/10;
		ans[i]=ans[i]%10;
	}
	while(ans[len-1]==0&&len>1) len--;
	for(int i=len-1; i>=0; i--) {
		cout<<ans[i];
	}
	return 0;
	// 2 3 5
	// a1+a2+a3
	// 2 3 5 7
	// a1a2a3 a2a3a4 a1a2a4
	// a1 a2 a3 a4 a5
	// a1a2a3 a1a2a4 a1a2a5 a1a2a6 a1a3a4 a1a3a5 a1a3a6 a1a4a5 a1a4a6 a1a5a6 4
	// a2a3a4 a2a3a5 a2a3a6 a2a4a5 a2a4a6 a2a5a6 3
	// a3a4a5 a3a4a6 a3a5a6 2
	// a4a5a6 1
	// 1 3 n-1*n-2/2=1
	// 3 4 3*2/2=3
	// 6 5 4*3/2=6
	//10 6 5*4/2
	// a1 a2 a3 a4 a5 a6
	// 
	// 3*a1+3*a2+3a3+3a4=(n-1)(a1+a2+a3+a4)
	//
}
//2-3-7716
#include<bits/stdc++.h>
using namespace std;
string s[1001];
int res[110]={0};
int a[105]={0};
int ans[120]={0};
int main() {
	int n;
	cin>>n;
	int len=0;
	for(int i=1; i<=n; i++) {
		cin>>s[i];
		int sz=s[i].size();
		memset(a, 0, sizeof(a));
		for(int j=0; j<sz; j++) {
			a[sz-j-1] = s[i][j]-'0';
		}
		len=max(len, sz);
		for(int j=0; j<len; j++) {
			res[j]+=a[j];
		}
	}
	len+=4;
	for(int i=0; i<len; i++) {
		ans[i]=res[i]*(n-1);
	}
	for(int i=0; i<len-1; i++) {
		ans[i+1]+=ans[i]/10;
		ans[i]=ans[i]%10;
	}
	while(ans[len-1]==0&&len>1) len--;
	for(int i=len-1; i>=0; i--) {
		cout<<ans[i];
	}
	return 0;
	// 2 3 5
	// a1+a2+a2+a3+a1+a3=2*(a1+a2+a3)
	// 2 3 5 7
	// a1a2 a1a3 a1a4
	// a2a3 a2a4
	// a3a4
	// 3*a1+3*a2+3a3+3a4=(n-1)(a1+a2+a3+a4)
}

//2-3-7711
#include<bits/stdc++.h>
using namespace std;
// totallen = 1000*1001/2=500000
int b[500010]={0};
int main() {
	int n,a;
	cin>>n>>a;
	int curr=1;
	b[0]=1;
	int len=1;
	while(curr<=n) {
		int num=curr;
		int cnt=1;
		while(num!=0) {
			num/=10;
			cnt++;
		}
		len+=cnt;
		for(int i=0; i<len; i++) {
			b[i]=b[i]*curr;
		}
		for(int i=0; i<len-1; i++) {
			b[i+1]+=b[i]/10;
			b[i]%=10;
		}
		while(b[len-1]==0&&len>1) len--;
		curr++;
	}
	int ans=0;
	for(int i=0; i<len; i++) {
		if(b[i]==a) ans++;
	}
	cout<<ans;
}
//2-3-3281
#include<bits/stdc++.h>
using namespace std;
//string s[1010];
int pa[1005]={0};
int pb[1005][2010]={0};
int ac[2010]={0};
int main()
{
	string s1;
	string s2;
	cin>>s1>>s2;
	if(s1=="0"||s2=="0") {
		cout<<0;
		return 0;
	}
	if(s1.size()<s2.size()) {
		swap(s1,s2);
	}
	for(int j=0; j<s2.size(); j++) {
		int num=s2[s2.size()-j-1]-'0';
		for(int i=s1.size()-1; i>=0; i--){
			pa[i]=s1[s1.size()-i-1]-'0';
		}
		for(int i=0; i<s1.size(); i++) {
			pb[j][j+i]=pa[i]*num;
		}
	}
	// 9999*99
	// len=2+0+1
	//ac[0]+=pb[0][0] ac[0]+=pb[0][1];
	//ac[1]+=pb[0][1] ac[1]+=pb[0][1];
	int len=s1.size()+s2.size()+1;
	for(int j=0; j<s2.size(); j++) {		
		for(int i=0; i<len; i++) {
			ac[i]+=pb[j][i];	
		}
	}
	//b[0][1] b[0][2]
	//b[1][1] b[1][2]
	// 9*9*1000
	for(int j=0; j<len-1; j++) {
		ac[j+1]+=ac[j]/10;
		ac[j]%=10;
	}
	while(ac[len-1]==0&&len>1) len--;
	for(int j=len-1; j>=0; j--) {
		cout<<ac[j];	
	}
	return 0;
}

//2-3-7701
#include<bits/stdc++.h>
using namespace std;
// 1-2 1
// 1-3
string a[1001];
int b1[1001];
int b2[1001];
int c[1002];
string gjdAdd(string s1, string s2) {
	for(int i=s1.size()-1; i>=0; i--) {
		b1[i] = s1[s1.size()-1-i]-'0';
	}
	for(int i=s2.size()-1; i>=0; i--) {
		b2[i] = s2[s2.size()-1-i]-'0';
	}
	int len=max(s1.size(), s2.size())+1;
	for(int i=0; i<len-1; i++) {
		c[i]=b1[i]+b2[i];
	}
	for(int i=0; i<len-1; i++) {
		c[i+1]+=c[i]/10;
		c[i]%=10;
	}

	while(c[len-1]==0) len--;
	
	string ans="";
	for(int i=len-1; i>=0; i--) {
		ans+=c[i]+'0';
	}
//	cout<<"ans is "<<ans;
	return ans;
}
int main() {
	int m,n;
	cin>>m>>n;
	a[1]="1";
	a[2]="1";
	for(int i=3; i<=n-m+1; i++) {
		a[i]=gjdAdd(a[i-1],a[i-2]);
	}
	cout<<a[n-m+1];
	return 0;
}

//2-3-7704
#include<bits/stdc++.h>
using namespace std;
int main() {
	string s[11];
	int n;
	cin>>n;
	string maxs="";
	string mins="";
	for(int i=1; i<=101; i++) {
		mins+='1';
	}
	for(int i=1; i<=n; i++) {
		cin>>s[i];
		if((maxs.size()<s[i].size())||(maxs.size()==s[i].size()&&s[i]>maxs)) {
			maxs=s[i];
		}
		if((mins.size()>s[i].size())||(mins.size()==s[i].size()&&s[i]<mins)) {
			mins=s[i];
		}

	}
	int c[105]={0};
	int a[101]={0};
	int b[101]={0};
	int len=maxs.size();
	for(int i=maxs.size()-1; i>=0; i--) {
		a[i] = maxs[maxs.size()-1-i]-'0';
	}
	for(int i=mins.size()-1; i>=0; i--) {
		b[i]=mins[mins.size()-1-i]-'0';
	}
	for(int i=0; i<len; i++) {
		c[i]=a[i]-b[i];
	}
	for(int i=0; i<len; i++) {
		if(c[i]<0) {
			c[i+1]-=1;
			c[i]+=10;
		}	
	} 
	while(c[len-1]==0&&len>1) len--;
	for(int i=len-1; i>=0; i--) {
		cout<<c[i];
	}
	return 0;
}

//2-3-9163
#include<bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin>>s;
	int a[1005]={0};
	int b[1010]={0};
	int c[1020]={0};
	//100101010101010111111111000000000
	//10001
	for(int i=s.size()-1; i>=0; i--) {
		a[i]=s[s.size()-i-1]-'0';
		b[i+4]=s[s.size()-i-1]-'0';
	}
	int len=s.size()+5;
	
	for(int i=0; i<len; i++){
		c[i]=a[i]+b[i];
	}
	for(int i=0; i<len; i++){
		c[i+1]+=c[i]/2;
		c[i]%=2;
	}
	while(c[len-1]==0&&len>1) len--;
	for(int i=len-1;i>=0;i--){
		cout<<c[i];
	}
	return 0;
}
/*
//2-3-3280
#include<bits/stdc++.h>
using namespace std;
int a[1010]={0};
int b[1010]={0};
int c[1010]={0};
int main() {
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	bool flag=false;
	if((s1.size()<s2.size()) || (s1.size()==s2.size() && s1<s2)) {
		swap(s1, s2);
		flag=true;
	} 
	for(int i=s1.size()-1; i>=0; i--) {
		a[i] = s1[s1.size()-1-i]-'0';
	}
	for(int i=s2.size()-1; i>=0; i--) {
		b[i] = s2[s2.size()-1-i]-'0';
	}
	int len=max(s1.size(), s2.size());
	for(int i=0; i<len; i++) {
		c[i]=a[i]-b[i];
	}

	for(int i=0; i<len-1; i++) {
		if(c[i]<0) {
			c[i+1]-=1;
			c[i]+=10;
		}
	}
		
	while(c[len-1]==0&&len>1) len--;
	if(flag) cout<<'-';
	for(int i=len-1; i>=0; i--) {
		cout<<c[i];
	}
	return 0;
}

//2-3-7700
#include<bits/stdc++.h>
using namespace std;
string s[21];
int main() {
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>s[i];
	}
	string ans="";
	int idx=1;
	for(int i=1; i<=n; i++) {
		if((s[i].size()>ans.size()) || (s[i].size()==ans.size() && s[i]>ans)) {
			ans=s[i];
			idx=i;
		}
	}
	cout<<idx<<endl<<ans;
	return 0;
}

//2-3-3279
#include<bits/stdc++.h>
using namespace std;
int a[1010]={0};
int b[1010]={0};
int c[1010]={0};
int main() {
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	for(int i=s1.size()-1; i>=0; i--) {
		a[i] = s1[s1.size()-1-i]-'0';
	}
	for(int i=s2.size()-1; i>=0; i--) {
		b[i] = s2[s2.size()-1-i]-'0';
	}
	int len=max(s1.size(), s2.size())+1;
	for(int i=0; i<len-1; i++) {
		c[i]=a[i]+b[i];
	}
	for(int i=0; i<len-1; i++) {
		c[i+1]+=c[i]/10;
		c[i]%=10;
	}
	
	while(c[len-1]==0) len--;
	
	for(int i=len-1; i>=0; i--) {
		cout<<c[i];
	}
	return 0;
}

//2-2-3288
#include<bits/stdc++.h>
using namespace std;
int a[100001]={0};
int main() {
	int n;
	cin>>n;
	int idx=0;
	bool flag=true;
	for(int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
		if((a[i]<a[i-1])&&flag) {
			idx = i;
			flag=false;
		}
	}
	int ans=0;

	if(idx==n) {
		ans = (a[idx]<=a[1])?1:-1;
	} else if(idx!=0){
		ans=1;
		for(int i=idx; i<=n-1; i++) {
			if(a[i]<=a[i+1]&&a[i+1]<=a[1]) {
//			if(a[i]<=a[i+1]) {
				ans++;
			} else {
				ans = -1;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}

//2-2-1382
#include<bits/stdc++.h>
using namespace std;
char s[100001];
int main() {
	cin.getline(s, 100001);
	int len=strlen(s);
	sort(s, s+len);
	for(int i=0; i<len; i++) {
		if(s[i]!=' ') printf("%c", s[i]);
	}
	return 0;
}

//2-2-1613
#include<bits/stdc++.h>
using namespace std;
int score[11];
struct Student{
    int num;
    int a;
    int v;
}student[1001];
bool cmp(struct Student s1, struct Student s2) {
    if(((int(s1.a)==int(s2.a)))&&(int(s1.v)==int(s2.v))) {
        return s1.num<s2.num;
    }
    if(int(s1.a)==int(s2.a)) {
        return int(s1.v)<int(s2.v);
    }
    return int(s1.a)>int(s2.a);
}
int main() {
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++) {   
        int total=0,totalsquare=0;
        for(int j=1; j<=k; j++) {
            scanf("%d", &score[j]);
            total+=score[j];
            totalsquare+=score[j]*score[j];
        }
        student[i].num=i;
        student[i].a=total/k;
        student[i].v=(totalsquare-k*student[i].a*student[i].a)/k;
//        cout<<student[i].num<<" "<<student[i].a<<" "<<student[i].v<<" "<<endl;
    }
    sort(student+1, student+n+1, cmp);
    for(int i=1; i<=m; i++) {   
        printf("%d ", student[i].num);
    }
    return 0;
}

//2-2-9165
#include<bits/stdc++.h>
using namespace std;
int a[100001];
int b[1001]={0};	
struct Score{
	int chinese;
	int math;
}score[1010];
bool cmp(struct Score s1, struct Score s2) {
	int t1=s1.chinese+s1.math;
	int t2=s2.chinese+s2.math;
	if(t1==t2) {
		return s1.chinese>s2.chinese;
	}
	return t1>t2;
}
int main() {
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		scanf("%d%d", &score[i].chinese, &score[i].math);
	}
	sort(score+1, score+n+1, cmp);
	for(int i=1; i<=n; i++) {	
		printf("%d %d\n", score[i].chinese, score[i].math);
	}
	return 0;
}

//2-2-1415
#include<bits/stdc++.h>
using namespace std;
int a[100001];
int b[1001]={0};
struct Room{
	int num;
	int cnt;
}room[1010];
bool cmp(struct Room r1, struct Room r2) {
	if(r1.cnt==r2.cnt) {
		return r1.num<r2.num;
	}
	return r1.cnt>r2.cnt;
}
int main() {
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
		b[a[i]]++;
	}
	int sz=1;
	for(int i=1; i<=1000; i++) {
		if(b[i]!=0) {
			room[sz].cnt=b[i];
			room[sz].num=i;
			sz++;
		}
	}
	sz--;
	sort(room+1, room+sz+1, cmp);
	printf("%d", room[1].num);
	for(int j=2; j<=sz; j++) {
		printf("->%d", room[j].num);
	}
	return 0;
}

//2-2-1231
#include<bits/stdc++.h>
using namespace std;
int a[1010];
int main() {
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n-i; j++) {
			if(a[j+1]<a[j]) {
				swap(a[j], a[j+1]);
			}
		}
	}
	for(int i=1; i<=n; i++) {
		cout<<a[i]<<" ";
	}
	
	return 0;
}

//2-2-1230
#include<bits/stdc++.h>
using namespace std;
int a[1010];
int main() {
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=2; i<=n; i++) {
		int val=a[i];
		int j;
		for(j=i-1; j>=1; j--) {
			if(a[j]>val) {
				a[j+1]=a[j];
			} else {
				break;
			}
		}
		a[j+1]=val;
	}
	for(int i=1; i<=n; i++) {
		cout<<a[i]<<" ";
	}
	
	return 0;
}

//2-1-3590
#include<bits/stdc++.h>
using namespace std;
struct Data{
	int a;
	int b;
}data[100001];

bool datacmp(struct Data x, struct Data y) {
	if((x.a>y.a)||((x.a==y.a)&&(x.b>y.b))) {
//		cout<<"false: "<<x.a<<" "<<y.a<<endl;
		return false;
	} else {
//		cout<<"true: "<<x.a<<" "<<y.a<<endl;
		return true;
	}
}
int main() {
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%d%d",&(data[i].a), &(data[i].b));
	}
	sort(data+1, data+n+1, datacmp);
	for(int i=1; i<=n; i++) {
		printf("%d %d\n", data[i].a, data[i].b);
	}
	return 0;
}

//2-1-1345
#include<bits/stdc++.h>
using namespace std;
int a[500];
int mdays[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int main() {
	int n;
	cin>>n;
	if(n==0) {
		cout<<24*60*60;
		return 0;
	}
	for(int i=1; i<=12; i++) {
		mdays[i]+=mdays[i-1];
	}

	double ans=0;
	for(int i=1; i<=n; i++) {
		int m;
		int d;
		cin>>m>>d;
		//a[i] stores the days from 1.1
		a[i]=mdays[m-1]+d;

	}
	a[0]=1;
	a[n+1]=366;
//	for(int i=0; i<=n+1; i++) {
//		cout<<a[i]<<endl;
//	}
//	cout<<"Interval:"<<endl;
	// calc the interval
	for(int i=n+1;i>=1;i--) {
		a[i]=a[i]-a[i-1];
		if(i!=n+1&&i!=1) a[i]-=1;
		if(ans<a[i]) {
			ans=a[i];
		}
	}
	
//	for(int i=1; i<=n+1; i++) {
//		cout<<a[i]<<endl;
//	}
//	cout<<ans<<endl;

	
//	cout<<(24*3600*(ans-1)/366.0+0.5)<<" "<<int(24*3600*(ans-1)/366.0+0.5);
	ans=ans/366*24*3600;
	cout<<int(ans+0.5);
//	cout<<int(24*3600*(ans-1)/366.0+0.5);
	return 0;
}

//2-1-9551
#include<bits/stdc++.h>
using namespace std;
int a[100002];
int b[100002]={0};
int main() {
	int n;
//	cin>>n;
	scanf("%d", &n);
	if(n==1) {
		cout<<"no";
		return 0;
	}
	cin>>a[1]>>a[2];
	b[abs(a[2]-a[1])]=1;
	for(int i=3; i<=n; i++) {
		scanf("%d", &a[i]);
		if(b[abs(a[i]-a[i-1])]==0) {
			b[abs(a[i]-a[i-1])]=1;
		} else {
			printf("no");
			return 0;			
		}
	}

	for(int i=1; i<=n-1; i++) {
		if(b[i]!=1) {
			printf("no");
			return 0;			
		}
	}
	printf("yes");
	return 0;
}

//2-1-9553
#include<bits/stdc++.h>
using namespace std;
int a[100002];
int b[100002]={0};
int main() {
	int n;
//	cin>>n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
		if(b[a[i]]==0) {
			b[a[i]]=1;
		}
	}
	for(int i=1; i<=100000; i++) {
		if(b[i]!=0) {
			printf("%d ", i);
		}
	}
	return 0;
}

//2-1-9552
#include<bits/stdc++.h>
using namespace std;
int a[101][101];
int main() {
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cin>>a[i][j];
		}
	}
	for(int i=1; i<=n; i++) {
		int jMin=1;
		int iMax=1;
		for(int j=1; j<=n; j++) {
			// find i row minn: 11 12 13
			if(a[i][jMin]>a[i][j]) {
				jMin=j;
			}
			// find j colum minn: 11 21 31
			if(a[iMax][i]<a[j][i]) {
				iMax=j;
			}
		}
		printf("swap a[%d][%d] and a[%d][%d]\n", i, jMin, iMax, i);
		swap(a[i][jMin], a[iMax][i]);
		for(int p=1; p<=n; p++) {
			for(int k=1; k<=n-p; k++) {
				if(a[i][k]>a[i][k+1]) {
					swap(a[i][k], a[i][k+1]);
				}
			}
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

//2-1-1536
#include<bits/stdc++.h>
using namespace std;
int a[1001];
int main() {
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	// 2 1 3 4
	// 3 4 1 2 
	int cnt=0;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n-i; j++) {
			if(a[j]>a[j+1]) {
				swap(a[j], a[j+1]);
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}

//2-1-9950
#include<bits/stdc++.h>
using namespace std;
int a[1001];
int main() {
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	
	for(int i=1; i<=n; i++) {
		int idx=i;
		for(int j=i+1; j<=n; j++) {
			if(a[j]>a[idx]) {
				idx=j;
			}
		}
		swap(a[idx], a[i]);
	}
	for(int i=1; i<=n/2; i++) {
		cout<<a[i]<<endl<<a[n-i+1]<<endl;
	}
	if(n%2) {
		cout<<a[n/2+1];
	}
	return 0;
}

//2-1-1161
#include<bits/stdc++.h>
using namespace std;
string a[1001];
int main() {
	int n;
	cin>>n;
	getchar();
	for(int i=1; i<=n; i++) {
		//getline(cin, a[i]);
		cin>>a[i];
	}
	
	for(int i=1; i<=n; i++) {
		int idx=i;
		for(int j=i+1; j<=n; j++) {
			if(a[j]<a[idx]) {
				idx=j;
			}
		}
		swap(a[idx], a[i]);
	}
	for(int i=1; i<=n; i++) {
		cout<<a[i]<<endl;
	}
	return 0;
}

//2-1-9157
#include<bits/stdc++.h>
using namespace std;
int a[1001];
int main() {
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
	}
	for(int i=1; i<=n; i++) {
		int idx=i;
		for(int j=i+1; j<=n; j++) {
			if(a[j]<a[idx]) {
				idx=j;
			}
		}
		swap(a[idx], a[i]);
		if(i==(n+1)/2) {
			cout<<a[i];
			return 0;
		}

	}
	return 0;
}

//2-1-1160
#include<bits/stdc++.h>
using namespace std;
int a[1001];
int main() {
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
	}
	for(int i=1; i<=n; i++) {
		int idx=i;
		for(int j=i+1; j<=n; j++) {
			if(a[j]<a[idx]) {
				idx=j;
			}
		}
		swap(a[idx], a[i]);
	}
	for(int i=1; i<=n; i++) {
		cout<<a[i]<<" ";
	}
	return 0;
}

//1-7-1179
#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	for(int i=1; i<=n ;i++) {
		if(i%3!=0) continue;
		int m=i;
		while(m!=0) {
			if(m%10==5) {
				cout<<i<<endl;
				break;
			}
			m/=10;
		}
	}
	return 0;
}

//1-5-1179
#include<bits/stdc++.h>
using namespace std;
int main() {
	int a, b, s;
	cin>>a>>b>>s;
	a=abs(a);
	b=abs(b);
	if((s>=a+b)&&((s-a-b)%2==0)) {
		cout<<"Yes";
	} else {
		cout<<"No";
	}
	return 0;
}

//1-5-1176
#include<bits/stdc++.h>
using namespace std;
int main() {
	double a,b;
	int r;
	cin>>a>>b>>r;
	int d=2*r;
	if((a>=2*r)&&(b>=2*r)) {
		printf("Alice win\n");
	}else {
		printf("Bob win\n");
	}
	return 0;
}

//1-5-1180
#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,a,b;
	cin>>n>>a>>b;
	// 3 1 1
	int ans=0;
	for(int i=1; i<=n; i++) {
		if((i-1>=a)&&n-i<=b) {
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

//1-5-1178
#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,k;
	cin>>n>>k;
	if(k==0||k==n) {
		cout<<"0 0";
		return 0;
	}
	//		 k n s l
	// ***** 5 5 0 0 minn=0
	// ****? 4 5 1 1 maxx=min(2*k, n-k)
	// ***?? 3 5 1 2 maxx=min(2*k, n-k)	
	// **??? 2 5 1 3 maxx=min(2*k, n-k) ?*?*? 
	// *???? 1 5 1 2 maxx=min(2*k, n-k) ?*???
	// ????? 0 5 0 0
	// *?**?*2 6 1 4 maxx=2*k n>2k
	// *?*?*?
	cout<<min(1, n-k)<<" "<<min(2*k,n-k);
	return 0;
}

//1-5-1177
#include<bits/stdc++.h>
using namespace std;
int main() {
	double n,m,a;
	cin>>n>>m>>a;
	cout<<ceil(n/a)*ceil(m/a);
	return 0;
}
*/
