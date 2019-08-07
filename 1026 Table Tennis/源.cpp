#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node {	//�˿�
	int arr;
	int cost;
	int wait;
	int vip;
	bool skip = false;
};
struct table {	//����
	int curtime = 8 * 3600;
	int id;
	int vip = 0;
	int served = 0;
};
vector<node> users;
vector<table> tables;
bool cmp(node a, node b) {	//�˿Ͱ�������������
	return a.arr < b.arr;
}
bool tablecmp(table a, table b) {	//���Ӱ������ȿ�������
	return a.curtime < b.curtime;
}
bool tableorder(table a, table b) {		//���Ҫ���˳�򣬰�id��С
	return a.id < b.id;
}
bool userorder(node a, node b) {	//���Ҫ���˳�򣬰���ʼʱ��
	return a.arr + a.wait < b.arr + b.wait;
}
void todate(int t) {
	printf("%02d:%02d:%02d ", t / 3600, t % 3600 / 60, t % 60);
}
void serve(int index, int arr, int cost) {	//����
	if (tables[index].curtime < arr) {
		tables[index].curtime = arr;
	}
	if (tables[index].curtime < 21 * 3600) {
		tables[index].served++;
	}
	tables[index].curtime += cost;
}
int findtable(node* usr) {	//�ҵ����������б����С�ģ����û��vip����vip����С�ŵ���ͨ��
	int min = 0;
	for (int i = 0; i < tables.size(); i++) {
		if (usr->vip == 1 && tables[i].curtime <= usr->arr && tables[i].vip == 1) {
			if (min == 0 || tables[i].id < tables[min].id) {
				min = i;
			}
		}
		else if (usr->vip != 1 && tables[i].curtime <= usr->arr) {
			if (tables[i].id < tables[min].id) {
				min = i;
			}
		}
		if (tables[i].curtime > usr->arr) {
			break;
		}
	}
	if (usr->vip == 1 && min == 0 && tables[0].vip == 0) {	// û��vip������vip��Ϊ��ͨ�û�����һ��
		usr->vip = 0;
		min = findtable(usr);
	}
	return min;
}
int main() {
	//׼���׶Σ���������
	freopen("Text.txt", "r", stdin);
	int n, k, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		node temp;
		int hour, minute, second, cost;
		scanf("%02d:%02d:%02d %d %d", &hour, &minute, &second, &cost, &temp.vip);
		temp.arr = hour * 3600 + minute * 60 + second;
		cost > 120 ? temp.cost = 120 * 60 : temp.cost = cost * 60;
		users.push_back(temp);
	}
	cin >> k >> m;
	tables.resize(k);
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		tables[t - 1].vip = 1;
	}
	for (int i = 0; i < k; i++) {
		tables[i].id = i;
	}
	//׼���׶ν���
	sort(users.begin(), users.end(), cmp);
	for (auto it = users.begin(); it != users.end(); it++) {	//��ÿһ���˿�
		if (it->vip == 1 && !it->skip) {	//�������vip��û�������
			sort(tables.begin(), tables.end(), tablecmp);
			int min = findtable(&*it);
			serve(min, it->arr, it->cost);
			it->wait = tables[min].curtime - it->cost - it->arr;
		}
		else if (!it->skip) {	//�����û�������
			bool flag = false;
			while (true) {
				sort(tables.begin(), tables.end(), tablecmp);
				int min = findtable(&*it);
				if (tables[min].vip == 1) {	//�����ͨ������vip��
					for (auto ir = it; ir != users.end(); ir++) {	//�ҵ���һ���ܵ���vip���������С��vip��
						if (ir->vip == 1 && !ir->skip) {
							if (ir->arr <= tables[min].curtime) {
								serve(min, ir->arr, ir->cost);
								ir->wait = tables[min].curtime - ir->cost - ir->arr;
								ir->skip = true;
								flag = true;	//�ɹ��ҵ���ӵ�vip������flag
								break;
							}
						}
					}
					if (flag) {	//��flag���ٴ�Ϊ����ͨ��������
						continue;
					}
				}	//��ͨ�� + ��ͨ�� = ֱ����
				serve(min, it->arr, it->cost);
				it->wait = tables[min].curtime - it->cost - it->arr;
				break;
			}
		}
	}
	//���
	sort(users.begin(), users.end(), userorder);
	for (auto it = users.begin(); it != users.end(); it++) {
		if (it->arr + it->wait < 21 * 3600) {
			todate(it->arr);
			todate(it->arr + it->wait);
			cout << (it->wait + 30) / 60 << endl;
		}
	}
	sort(tables.begin(), tables.end(), tableorder);
	for (int i = 0; i < tables.size() - 1; i++) {
		cout << tables[i].served << " ";
	}
	cout << tables[tables.size() - 1].served;
	return 0;
}