# include<iostream>
# include<cmath>
# include<iomanip>

using namespace std;

# define GREEN 0
# define ORANGE 1
# define RED 2
# define LAST_COLOR 0
# define LAST_TIME 1

void changeColor(int idx,int timeForColor[][3],int lastChange[][2]) {
	int lastColor = lastChange[idx][LAST_COLOR];
	lastChange[idx][LAST_TIME] += timeForColor[idx][lastColor];
	lastChange[idx][LAST_COLOR] = (lastChange[idx][LAST_COLOR] + 1)%3;
}

int getNextTime(int idx,int timeForColor[][3],int lastChange[][2]) {
	int lastColor = lastChange[idx][LAST_COLOR];
	return lastChange[idx][LAST_TIME] + timeForColor[idx][lastColor];
}

int main(void) {
	while(true) {	
		int timeForColor[100][3];
		int lastChange[100][2];
		int numTL = 0, secs = 0, green = 0, shortest = 0;
		int cycleTime[101] = { 0 };

		while(true) {
			cin >> cycleTime[numTL++];
			if(cycleTime[numTL-1] == 0) {
				break;
			} else {
				timeForColor[numTL-1][GREEN] = cycleTime[numTL-1] - 5;
				timeForColor[numTL-1][ORANGE] = 5;
				timeForColor[numTL-1][RED] = cycleTime[numTL-1];
				shortest = min(cycleTime[numTL-1],cycleTime[shortest]) == cycleTime[numTL-1] ? numTL-1 : shortest;
				lastChange[numTL-1][LAST_COLOR] = GREEN;
				lastChange[numTL-1][LAST_TIME] = 0;
			}
		}
		lastChange[shortest][LAST_COLOR] = ORANGE;
		lastChange[shortest][LAST_TIME] = timeForColor[shortest][GREEN];

		if(cycleTime[0] == 0) {
			break;
		}

		bool inSync = false;
		numTL -= 1;

		for(secs = 1; secs <= 60*60*5; secs++) {
			green = 0;
			for(int light = 0; light < numTL; light++) {
				if(secs == getNextTime(light,timeForColor,lastChange)) {
					changeColor(light,timeForColor,lastChange);
					//cout << "After change color: Light: " << light << " last color: " << lastChange[light][LAST_COLOR] << " last time: " << lastChange[light][LAST_TIME] << endl;
					inSync = lastChange[LAST_COLOR] != GREEN ? false : inSync;
				}
				if(lastChange[light][LAST_COLOR] == GREEN) {
					green++;
				}
			}
			if(green == numTL) {
				break;
			}
		}
		int hrs = secs/3600, mins = (secs - hrs * 3600) / 60;
		secs = secs - hrs * 3600 - mins * 60;
		if(green != numTL) {
			cout << "Signals fail to synchronise in 5 hours" << endl;
		} else {
			cout << setfill('0') << setw(2) << hrs << ":" << setfill('0') << setw(2) << mins << ":" << setfill('0') << setw(2) << secs << endl;
		}
	}
}
