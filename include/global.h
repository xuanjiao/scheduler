#pragma once

#include <string>
#include <map>

//#include "Robot.h"
//#include "EnterRoomTask.h"

using namespace std;

typedef struct room_info {
	int id;
	int  occupy_posibility;
	friend bool operator < (room_info a, room_info b)
	{
		return a.occupy_posibility > b.occupy_posibility;   // if a.posibility > b.posibility, a > b, a is near the top
	}
} Room_info;

typedef struct Room_Time {
	int room_id;
	int day_of_week;
	int time;
	time_t calendar_time;
	friend bool operator < (Room_Time rt1, Room_Time rt2) {
		if (rt1.day_of_week < rt2.day_of_week) {
			return true;
		}
		else if (rt1.day_of_week == rt2.day_of_week) {
			return rt1.time < rt2.time; // ealier time will be in the frount
		}
	else {
			return false;
		}
		
	}
}Room_Time;

typedef struct {
	int closed_count;
	int opened_count;
}Door_cnt;

typedef void (*outFunc)(string s); // function pointer to lock_print function

class Util {
	
public:
	Util(outFunc out);
	static bool GetDoorStatusFromFile(Room_Time rt, const char* path);
	static map<string, int>  day_of_weeks_map;
	static map<string, int> months_map;
	static std::string day_of_weeks[7];
	static void Generate_simulation_door_status(int num_of_rooms, int num_of_measurements, time_t start_time);
private:
	static outFunc global_print;
};

