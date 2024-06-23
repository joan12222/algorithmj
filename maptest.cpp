#include<bits/stdc++.h>
using namespace std;
map<int, int> color;

int main(){
	color.insert(make_pair(5, 11));
	color.insert(make_pair(7, 13));
	color.insert(make_pair(6, 21));
	color.insert(make_pair(8, 13));
	color.insert(make_pair(0, 12));
	color.insert(make_pair(12, 0));
	
	vector<pair<int, int>> ncolor(color.begin(), color.end());
	//按pair.first(即map.key)排序
	sort(ncolor.begin(), ncolor.end());
	cout<<"按key排序："<<endl;
	for(auto &p:ncolor) {
		cout<<p.first<<" "<<p.second<<endl;
	}
	//按pair.second(即map.value)排序
	sort(ncolor.begin(), ncolor.end(), 
		[](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
		});
	cout<<"按value排序："<<endl;
	for(auto &p:ncolor) {
		cout<<p.first<<" "<<p.second<<endl;
	} 
	//删除vector里的元素，删除后iterator值会变化，注意for循环写法和it的更新
	ncolor.erase(remove(ncolor.begin(), ncolor.end(), make_pair(5,11)), ncolor.end());
	cout<<"删除元素(5,11)："<<endl;
	for(auto &p:ncolor) {
		cout<<p.first<<" "<<p.second<<endl;
	}
	cout<<"删除0："<<endl;
	vector<pair<int, int>>::iterator it;
	for(it=ncolor.begin(); it!=ncolor.end();) {
		if((*it).first==0||(*it).second==0) {
			it=ncolor.erase(it);
		}else {
			it++;
		}
	}
	//几种遍历输出的写法
	for(it=ncolor.begin(); it!=ncolor.end(); it++) {
		cout<<(*it).first<<" "<<(*it).second<<endl;
	}
	cout<<endl;
	for(auto p:ncolor) {
		cout<<p.first<<" "<<p.second<<endl;
	}
	cout<<endl;
	for(auto &p:ncolor) {
		cout<<p.first<<" "<<p.second<<endl;
	}
	cout<<endl;
	return 0;
}
