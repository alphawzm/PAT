// 1006. Sign In and Sign Out (25)
#include <iostream>
#include <string>
using namespace std;

int main() {
	string unlockedTime = "23:59:59", lockedTime = "00:00:00";
	int n;
	cin >> n;
	string unlockedID, lockedID;
	for (int i = 0; i < n; i++) {
		string ID_number, Sign_in_time, Sign_out_time;
		cin >> ID_number >> Sign_in_time >> Sign_out_time;
		
		if (Sign_in_time < unlockedTime) {
			unlockedTime = Sign_in_time;
			unlockedID = ID_number;
		}
		if (Sign_out_time > lockedTime) {
			lockedTime = Sign_out_time;
			lockedID = ID_number;
		}
	}
	cout << unlockedID << " " << lockedID;
	return 0;
}