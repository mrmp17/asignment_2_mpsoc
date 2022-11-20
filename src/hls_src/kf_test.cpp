#include "KF_kernel.h"

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define INPUT_FILENAME "<project directory>/src/sensor_and_control_measurements.txt"
#define OUTPUT_FILENAME "<project directory>/matlab/hls_output.txt"
#define DELIMITER ','

vector<vector<float>> parseFile(string filename) {
	vector <vector <float> > data;

	ifstream infile( INPUT_FILENAME );

	bool first_line = true;

	while(infile) {

		string s;
		if (!getline(infile, s)) break;

		if (first_line) {
			first_line = false;
			continue;
		}

		istringstream ss(s);
		vector<float> record;

		while(ss) {
			string s;
			if(!getline(ss,s,DELIMITER)) break;
			record.push_back(stof(s));
		}

		data.push_back(record);

	}

	if (!infile.eof()) {
		cerr << "Fooey!\n";
	}

	return data;
}

void writeDataToFile(float dout[N_SAMPLES*N_STATE_VARS], string filename) {

	ofstream f;
	f.open(filename);

	f << "x_hat_0,x_hat_1,x_hat_2,x_hat_3,x_hat_4,x_hat_5\n";

	for (int i = 0; i < N_SAMPLES; i++) {
		for (int j = 0; j < N_STATE_VARS; j++) {

			f << dout[i*N_STATE_VARS+j];

			if (j < N_STATE_VARS-1) {

				f << ",";

			}
		}

		if (i < N_SAMPLES-1) {

			f << "\n";

		}
	}
}

int main(int argc, char *argv[]) {

//	vector<vector<float>> data_vec = parseFile(INPUT_FILENAME);
//
//	float din[N_SAMPLES*(N_MEAS_VARS+N_CTRL_VARS)];
	float dout[N_SAMPLES*N_STATE_VARS];

//	for (int i = 0; i < N_SAMPLES; i++) {
//		for (int j = 0; j < (N_MEAS_VARS+N_CTRL_VARS); j++) {
//
//			din[i*(N_MEAS_VARS+N_CTRL_VARS)+j] = data_vec[i][j];
//		}
//	}

#include "data.h"

	KalmanFilterKernel(din, dout, 0.05, 0.95);

//	writeDataToFile(dout, OUTPUT_FILENAME);

	for (int i = 0; i < N_SAMPLES; i++) {
		for (int j = 0; j < N_STATE_VARS; j++) {
			cout << dout[i*N_STATE_VARS+j] << "\t";
		}
		cout << "\n";
	}

}











