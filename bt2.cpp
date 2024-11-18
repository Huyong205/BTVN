#include<bits/stdc++.h>
using namespace std;

struct Node{
	string word;
	Node* next;
};

Node* makeWord(string s){
	Node* newNode = new Node;
	newNode->word = s;
	newNode->next = NULL;
	return newNode;
}

//hàm tách xâu s thành các từ, trả về 1 danh sách liên kết với mỗi node có thông tin là 1 từ
Node* taoList(string s){ 
	Node* head = NULL;
	stringstream ss(s);
	string tmp;
	while(ss >> tmp){
		if(head == NULL){
			head = makeWord(tmp);
		}
		else{
			Node* duyet = head;
			while(duyet->next != NULL) duyet = duyet->next;
			duyet->next = makeWord(tmp);
		}
	}
	return head;
}

void duyet(Node* head){
	while(head != NULL){
		cout << head->word << ' ';
		head = head->next;
	}
}

//hàm tìm từ xhien nhiều nhất
string findMax(Node* head){
	map<string, int> mp;
	string res = head->word;
	while(head != NULL){
		mp[head->word]++;
		head = head->next;
	}
	for(auto it : mp){
		if(mp[res] < it.second){
			res = it.first;
		}
	}
	return res;
}

//hàm xoá từ 1 từ láy
void Delete(Node*& head){
	Node* truoc = head;
	Node* sau = head->next;
	while(sau != NULL){
		if(truoc->word == sau->word){
			Node* del = sau;
			truoc->next = sau->next;
			sau = truoc->next;
			delete del;
		}
		else{
			truoc = sau;
			sau = sau->next;
		}
	}
}

int size(Node* head){
	multiset<string> se;
	while(head != NULL){
		se.insert(head->word);
		head = head->next;
	}
	return se.size();
}

int main(){
		
	string s = "Duong Van Huong dien tu 05 Huong Van Duong 05 dien tu xanh xanh dien tu 05";
	Node* head = taoList(s);
	Delete(head);
	duyet(head);
	return 0;
}