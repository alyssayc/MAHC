#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/*class Bull{
    protected:
        int id; // Contains the specific bull's id
        double speed; // Contain its speed after calculation
        int laps; // Contains the number of laps assigned to that bull
        int lane; // Contains the lane length of the bull.
        int time; // Total time the bull takes to finish the race
        int length; // The value of M to see how far the bull travelled
    public:
        Bull(int ident, int lane_pos, int num_laps, int tot_time, int hay_length){
            id = ident;
            lane = lane_pos;
            laps = num_laps;
            time = tot_time;
            length = hay_length;
	    speed = this->getSpeed();
        }

        int getSpeed() { 
            return ((laps * (length * (10 + (lane - 1)))) / (time));
        }
    private:
};*/

/*
int* separate(string str){ // Splits the input line into tokens of integers
    char seps[] = " ";
    char* token;
    int var;
    int* input = new int[str.length()];
    int i = 0;
    cout << "str: " << str;
    //printf("str: %s\n", str);

    token = strtok(str, seps);
    cout << "token: " << token;
    //printf("token: %s\n", token);
    while(token != NULL){
        sscanf(token, "%d", &var);
        input[i++] = var;
        cout << "var: " << var;
        //printf("var: %d\n", var);
        token = strtok(NULL, seps);
    }
    delete(token);
    return input;
} */ 

double speed_of_cow(int hay_length, int lane_pos, int num_laps, int tot_time){
    return (double)(hay_length * (10 + (lane_pos - 1)) * num_laps)/(tot_time);
}



int main(){
    int best_cow_id; double best_cow_speed = 0.0; double temp; // counter to keep track of the info of the best bull
    long int M, K;
    int N, L, B, R, timekeep, idCount = 0, idTemp, timetok;
    char *line;
    int* cowLine;
    //cout << "Please enter the details of this race event" << endl;
    //printf("Please enter the details of this race event");
    cin >> N >> M >> L;
    //cout << "N: " << N << endl;
    //cin >> M;
    //cout << "M: " << M << endl;
    //cin >> L;
    //cout << "L: " << L << endl;
    for (int i = 0; i < N; i++){
        //cout << "i: " << i << endl;
        //cout << "Please enter B and R for this race: ";
        cin >> B >> R;
        //cin >> R;
        //cout << "B: " << B << endl;
        //cout << "R: " << R << endl;
        for (int j = 0; j < B; j++){
            timekeep = 0;
            //cout << "j: " << j << endl;
            idCount++;
            //cout << "idCount: " << idCount << endl;
            //cout << "Please enter your cow line: ";
            cin >> idTemp;
            for (int k = 0; k < R; k++){
                //cout << "k: " << k << endl;
                cin >> timetok;
                timekeep += timetok;
                //cout << "timekeep: " << timekeep << endl;
            }
            temp = speed_of_cow(M, (j + 1), R, timekeep);
            //cout << "speed_of_cow: " << temp;
            if ((temp > best_cow_speed) || (abs(temp - best_cow_speed) <= .000001)){
                //cout << "best_cow_id: " << best_cow_id << endl;
                best_cow_id = idTemp;
                best_cow_speed = temp;
            }
        }
    }
    //cout << "The best cow is: " << best_cow_id << endl;
    cout << best_cow_id << endl;
} 
