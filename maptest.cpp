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
	//��pair.first(��map.key)����
	sort(ncolor.begin(), ncolor.end());
	cout<<"��key����"<<endl;
	for(auto &p:ncolor) {
		cout<<p.first<<" "<<p.second<<endl;
	}
	//��pair.second(��map.value)����
	sort(ncolor.begin(), ncolor.end(), 
		[](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
		});
	cout<<"��value����"<<endl;
	for(auto &p:ncolor) {
		cout<<p.first<<" "<<p.second<<endl;
	} 
	//ɾ��vector���Ԫ�أ�ɾ����iteratorֵ��仯��ע��forѭ��д����it�ĸ���
	ncolor.erase(remove(ncolor.begin(), ncolor.end(), make_pair(5,11)), ncolor.end());
	cout<<"ɾ��Ԫ��(5,11)��"<<endl;
	for(auto &p:ncolor) {
		cout<<p.first<<" "<<p.second<<endl;
	}
	cout<<"ɾ��0��"<<endl;
	vector<pair<int, int>>::iterator it;
	for(it=ncolor.begin(); it!=ncolor.end();) {
		if((*it).first==0||(*it).second==0) {
			it=ncolor.erase(it);
		}else {
			it++;
		}
	}
	//���ֱ��������д��
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
