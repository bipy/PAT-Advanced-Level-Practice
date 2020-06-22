#include<iostream>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<vector>
#include<deque>
//出入场
#define IN true
#define OUT false
using namespace std;
//一条记录
struct record {
	string id;
	int second;
	bool io;
};
//一辆车
struct car {
	string id;
	//这辆车的停车时间总和
	int stay = 0;
	//这辆车的所有进出记录
	vector<record> list;	
};
//所有记录
vector<record> allRecord;
//所有查询
deque<int> checkPoint;
//所有停车场内车辆
unordered_map<string, record> park;
//所有车辆
unordered_map<string, car> carList;

//转化为秒数
int getTime(string& time) {
	int h = stoi(time.substr(0, 2));
	int m = stoi(time.substr(3, 2));
	int s = stoi(time.substr(6, 2));
	return h * 3600 + m * 60 + s;
}
//比较器
bool cmp(const record& a, const record& b) {
	return a.second < b.second;
}
bool alphabet(const car& a, const car& b) {
	return a.id < b.id;
}
int main() {
	//读取数据
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
	//将所有记录以时间顺序排序
	sort(allRecord.begin(), allRecord.end(), cmp);
	//记录每辆车各自的进出
	for (auto it = allRecord.begin(); it != allRecord.end(); it++) {
		carList[it->id].list.push_back(*it);
	}
	//按时间顺序处理数据
	for (int i = 0; i < allRecord.size(); i++) {
		record cur = allRecord[i];
		while (!checkPoint.empty() && cur.second > checkPoint.front()) {
			cout << park.size() << endl;
			checkPoint.pop_front();
		}
		if (cur.io == IN) {
			//对于进场车辆，查找下一条记录是否为出场
			for (auto it = carList[cur.id].list.begin(); it != carList[cur.id].list.end(); it++) {
				if (cur.second < it->second) {
					if (it->io == OUT) {
						//符合条件，停入停车场
						park[cur.id] = cur;
					}
					break;
				}
			}

		}
		else if (cur.io == OUT) {
			//对于出场车辆，检查场内是否有该车
			if (park.count(cur.id) != 0) {
				//计算停车时间
				int t = cur.second - park[cur.id].second;
				carList[cur.id].stay += t;
				//出场
				park.erase(cur.id);
			}
		}
	}
	//输出剩下的检查点
	while (!checkPoint.empty()) {
		cout << park.size() << endl;
		checkPoint.pop_front();
	}
	//找停车时间最长的，输出
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