#include<bits/stdc++.h>
using namespace std;

const int MAX = 100;

struct file{
	string name;
	int size;
	string time;
	string address;
	file* next;
};

struct folder{
	file* head;
	folder* next;
};

void copy(folder*& D, folder* C, string address){
	file* head = C->head;
	file* cop = NULL;
	while(head != NULL){
		if(head->address == address){
			cop = head;
			break;
		}
		head = head->next;
	}
	if(cop == NULL){
		cout << "khong tim thay file\n";
		return;
	}
	else{
		file* headD = D->head;
		file* prev = NULL;
		while(headD != NULL){
			if(headD->time < cop->time){
				prev = headD;
				headD = headD->next;
			}
			else{
				if(prev == NULL){
					cop->next = headD;
					headD = cop;
					return;
				}
				else{
					prev->next = cop;
					cop->next = headD;
					return;
				}
			}
		}
		prev->next = cop; //truong hop phai them vao cuoi
	}
}

void my_swap(file* a, file* b){
	swap(a->name, b->name);
	swap(a->size, b->size);
	swap(a->time, b->time);
	swap(a->address, b->address);
}

void sort(folder*& D){
	file* head = D->head;
	for(file* i = head; i->next != NULL; i = i->next){
		file* maxSize = i;
		for(file* j = i->next; j != NULL; j = j->next){
			if(maxSize->size < j->size){
				maxSize = j;
			}
			else if(maxSize->size == j->size){
				if(maxSize->time > j->time) maxSize = j;
			}
		}
		my_swap(i, maxSize);
	}
}

void saveToUSB(folder* D){
	sort(D);	
	int size = 0;
	file* head = D->head;
	while(head != NULL){
		if((size + head->size) / 1000 > 32){ //size ở đây tính bằng MB
			head->next = NULL; //xoá hết các node đằng sau vì cộng vào sẽ > 32GB
			return;
		}
		size += head->size;
		head = head->next;
	}
}

int calculateTotalSize(folder* D){
	file* head = D->head;
	int size = 0;
	while(head != NULL){
		size += head->size;
		head = head->next;
	}
	return size;
}

int main(){
	
	return 0;
}
