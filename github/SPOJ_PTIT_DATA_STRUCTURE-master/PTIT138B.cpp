#include<bits/stdc++.h>
#define alpha "abcdefghijklmnopqrstuvwxyz"
#define ALPHA "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define mp make_pair
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int,int> pii;
const ld pi=2*acos(0);
const ll inf  = LLONG_MAX;
const ll ninf = LLONG_MIN;
struct giaPha{
	string cha;
	string con;
	int tuoi;
};
struct tenTuoi{
	string name;
	int age;
};

vector <tenTuoi> kq;
vector <giaPha> a;

void timNguoiThan(string tmp,int Tuoi){
	for(int i=0;i<a.size();i++){
		if(a[i].cha==tmp){
			if(tmp=="Ted"){
				tenTuoi kk;
				kk.name=a[i].con; kk.age=100-a[i].tuoi;
				kq.push_back(kk);
				Tuoi=100-a[i].tuoi;
				timNguoiThan(a[i].con,Tuoi);
			}
			else{
				tenTuoi kk;
				kk.name=a[i].con; kk.age=Tuoi-a[i].tuoi;
				kq.push_back(kk);
				timNguoiThan(a[i].con,Tuoi-a[i].tuoi);
			}
		}
	}
}

bool sapxep(tenTuoi u,tenTuoi v){
	if(u.age>v.age) return true;
	if(u.age == v.age && u.name < v.name) return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	int t;
	cin>>t;
	for(int k=1;k<=t;k++){
		int n; cin>>n;
		for(int i=1;i<=n;i++){
			giaPha tmp;
			cin>>tmp.cha>>tmp.con>>tmp.tuoi;
			cin.ignore();
			a.push_back(tmp);
		}
		timNguoiThan("Ted",0);
		sort(kq.begin(),kq.end(),sapxep);
		cout<<"DATASET "<<k<<endl;
		for(int i=0;i<kq.size();i++) cout<<kq[i].name<<" "<<kq[i].age<<endl;
		a.clear(); kq.clear();
	}
	return 0;
}
