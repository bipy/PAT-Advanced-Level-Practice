#include<iostream>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<vector>
#include<deque>
//���볡
#define IN true
#define OUT false
using namespace std;
//һ����¼
struct record {
	string id;
	int second;
	bool io;
};
//һ����
struct car {
	string id;
	//��������ͣ��ʱ���ܺ�
	int stay = 0;
	//�����������н�����¼
	vector<record> list;	
};
//���м�¼
vector<record> allRecord;
//���в�ѯ
deque<int> checkPoint;
//����ͣ�����ڳ���
unordered_map<string, record> park;
//���г���
unordered_map<string, car> carList;

//ת��Ϊ����
int getTime(string& time) {
	int h = stoi(time.substr(0, 2));
	int m = stoi(time.substr(3, 2));
	int s = stoi(time.substr(6, 2));
	return h * 3600 + m * 60 + s;
}
//�Ƚ���
bool cmp(const record& a, const record& b) {
	return a.second < b.second;
}
bool alphabet(const car& a, const car& b) {
	return a.id < b.id;
}
int main() {
	//��ȡ����
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		string id, time, act;
		cin >> id >> time >> act;
		allRecord.push_back(record{ id,getTime(time),act == "in" ? IN : OUT });
		car temp;
		temp.id = id;
		carList[id] = temp;
	}
	for (int i = 0; i < K; i++) {
		string t;
		cin >> t;
		checkPoint.push_back(getTime(t));
	}
	//�����м�¼��ʱ��˳������
	sort(allRecord.begin(), allRecord.end(), cmp);
	//��¼ÿ�������ԵĽ���
	for (auto it = allRecord.begin(); it != allRecord.end(); it++) {
		carList[it->id].list.push_back(*it);
	}
	//��ʱ��˳��������
	for (int i = 0; i < allRecord.size(); i++) {
		record cur = allRecord[i];
		while (!checkPoint.empty() && cur.second > checkPoint.front()) {
			cout << park.size() << endl;
			checkPoint.pop_front();
		}
		if (cur.io == IN) {
			//���ڽ���������������һ����¼�Ƿ�Ϊ����
			for (auto it = carList[cur.id].list.begin(); it != carList[cur.id].list.end(); it++) {
				if (cur.second < it->second) {
					if (it->io == OUT) {
						//����������ͣ��ͣ����
						park[cur.id] = cur;
					}
					break;
				}
			}

		}
		else if (cur.io == OUT) {
			//���ڳ�����������鳡���Ƿ��иó�
			if (park.count(cur.id) != 0) {
				//����ͣ��ʱ��
				int t = cur.second - park[cur.id].second;
				carList[cur.id].stay += t;
				//����
				park.erase(cur.id);
			}
		}
	}
	//���ʣ�µļ���
	while (!checkPoint.empty()) {
		cout << park.size() << endl;
		checkPoint.pop_front();
	}
	//��ͣ��ʱ����ģ����
	int max = -1;
	for (auto it = carList.begin(); it != carList.end(); it++) {
		if (max < it->second.stay) {
			max = it->second.stay;
		}
	}
	vector<car> ans;
	for (auto it = carList.begin(); it != carList.end(); it++) {
		if (max == it->second.stay) {
			ans.push_back(it->second);
		}
	}
	sort(ans.begin(), ans.end(), alphabet);
	for (auto it = ans.begin(); it != ans.end(); it++) {
		cout << it->id + " ";
	}
	printf("%02d:%02d:%02d", max / 3600, max % 3600 / 60, max % 60);
	return 0;
}