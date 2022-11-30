#include <systemc>
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <stdint.h>
#include "SysCFileHandler.h"
#include "ap_int.h"
#include "ap_fixed.h"
#include <complex>
#include <stdbool.h>
#include "autopilot_cbe.h"
#include "hls_stream.h"
#include "hls_half.h"
#include "hls_signal_handler.h"

using namespace std;
using namespace sc_core;
using namespace sc_dt;

// wrapc file define:
#define AUTOTB_TVIN_din "../tv/cdatafile/c.KalmanFilterKernel.autotvin_din.dat"
#define AUTOTB_TVOUT_din "../tv/cdatafile/c.KalmanFilterKernel.autotvout_din.dat"
// wrapc file define:
#define AUTOTB_TVIN_dout "../tv/cdatafile/c.KalmanFilterKernel.autotvin_dout.dat"
#define AUTOTB_TVOUT_dout "../tv/cdatafile/c.KalmanFilterKernel.autotvout_dout.dat"
// wrapc file define:
#define AUTOTB_TVIN_counter "../tv/cdatafile/c.KalmanFilterKernel.autotvin_counter.dat"
#define AUTOTB_TVOUT_counter "../tv/cdatafile/c.KalmanFilterKernel.autotvout_counter.dat"
// wrapc file define:
#define AUTOTB_TVIN_q "../tv/cdatafile/c.KalmanFilterKernel.autotvin_q.dat"
#define AUTOTB_TVOUT_q "../tv/cdatafile/c.KalmanFilterKernel.autotvout_q.dat"
// wrapc file define:
#define AUTOTB_TVIN_r "../tv/cdatafile/c.KalmanFilterKernel.autotvin_r.dat"
#define AUTOTB_TVOUT_r "../tv/cdatafile/c.KalmanFilterKernel.autotvout_r.dat"

#define INTER_TCL "../tv/cdatafile/ref.tcl"

// tvout file define:
#define AUTOTB_TVOUT_PC_din "../tv/rtldatafile/rtl.KalmanFilterKernel.autotvout_din.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_dout "../tv/rtldatafile/rtl.KalmanFilterKernel.autotvout_dout.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_counter "../tv/rtldatafile/rtl.KalmanFilterKernel.autotvout_counter.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_q "../tv/rtldatafile/rtl.KalmanFilterKernel.autotvout_q.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_r "../tv/rtldatafile/rtl.KalmanFilterKernel.autotvout_r.dat"

class INTER_TCL_FILE {
  public:
INTER_TCL_FILE(const char* name) {
  mName = name; 
  din_depth = 0;
  dout_depth = 0;
  counter_depth = 0;
  q_depth = 0;
  r_depth = 0;
  trans_num =0;
}
~INTER_TCL_FILE() {
  mFile.open(mName);
  if (!mFile.good()) {
    cout << "Failed to open file ref.tcl" << endl;
    exit (1); 
  }
  string total_list = get_depth_list();
  mFile << "set depth_list {\n";
  mFile << total_list;
  mFile << "}\n";
  mFile << "set trans_num "<<trans_num<<endl;
  mFile.close();
}
string get_depth_list () {
  stringstream total_list;
  total_list << "{din " << din_depth << "}\n";
  total_list << "{dout " << dout_depth << "}\n";
  total_list << "{counter " << counter_depth << "}\n";
  total_list << "{q " << q_depth << "}\n";
  total_list << "{r " << r_depth << "}\n";
  return total_list.str();
}
void set_num (int num , int* class_num) {
  (*class_num) = (*class_num) > num ? (*class_num) : num;
}
void set_string(std::string list, std::string* class_list) {
  (*class_list) = list;
}
  public:
    int din_depth;
    int dout_depth;
    int counter_depth;
    int q_depth;
    int r_depth;
    int trans_num;
  private:
    ofstream mFile;
    const char* mName;
};

static void RTLOutputCheckAndReplacement(std::string &AESL_token, std::string PortName) {
  bool no_x = false;
  bool err = false;

  no_x = false;
  // search and replace 'X' with '0' from the 3rd char of token
  while (!no_x) {
    size_t x_found = AESL_token.find('X', 0);
    if (x_found != string::npos) {
      if (!err) { 
        cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port" 
             << PortName << ", possible cause: There are uninitialized variables in the C design."
             << endl; 
        err = true;
      }
      AESL_token.replace(x_found, 1, "0");
    } else
      no_x = true;
  }
  no_x = false;
  // search and replace 'x' with '0' from the 3rd char of token
  while (!no_x) {
    size_t x_found = AESL_token.find('x', 2);
    if (x_found != string::npos) {
      if (!err) { 
        cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' on port" 
             << PortName << ", possible cause: There are uninitialized variables in the C design."
             << endl; 
        err = true;
      }
      AESL_token.replace(x_found, 1, "0");
    } else
      no_x = true;
  }
}
struct __cosim_s4__ { char data[4]; };
extern "C" void KalmanFilterKernel_hw_stub_wrapper(volatile void *, volatile void *, __cosim_s4__*, float, float);

extern "C" void apatb_KalmanFilterKernel_hw(volatile void * __xlx_apatb_param_din, volatile void * __xlx_apatb_param_dout, __cosim_s4__* __xlx_apatb_param_counter, float __xlx_apatb_param_q, float __xlx_apatb_param_r) {
  refine_signal_handler();
  fstream wrapc_switch_file_token;
  wrapc_switch_file_token.open(".hls_cosim_wrapc_switch.log");
  int AESL_i;
  if (wrapc_switch_file_token.good())
  {

    CodeState = ENTER_WRAPC_PC;
    static unsigned AESL_transaction_pc = 0;
    string AESL_token;
    string AESL_num;{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_dout);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<32> > dout_pc_buffer(6);
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "dout");
  
            // push token into output port buffer
            if (AESL_token != "") {
              dout_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 6; j < e; j += 1, ++i) {
            ((int*)__xlx_apatb_param_dout)[j] = dout_pc_buffer[i].to_int64();
          }}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  
    AESL_transaction_pc++;
    return ;
  }
static unsigned AESL_transaction;
static AESL_FILE_HANDLER aesl_fh;
static INTER_TCL_FILE tcl_file(INTER_TCL);
std::vector<char> __xlx_sprintf_buffer(1024);
CodeState = ENTER_WRAPC;
//din
aesl_fh.touch(AUTOTB_TVIN_din);
aesl_fh.touch(AUTOTB_TVOUT_din);
//dout
aesl_fh.touch(AUTOTB_TVIN_dout);
aesl_fh.touch(AUTOTB_TVOUT_dout);
//counter
aesl_fh.touch(AUTOTB_TVIN_counter);
aesl_fh.touch(AUTOTB_TVOUT_counter);
//q
aesl_fh.touch(AUTOTB_TVIN_q);
aesl_fh.touch(AUTOTB_TVOUT_q);
//r
aesl_fh.touch(AUTOTB_TVIN_r);
aesl_fh.touch(AUTOTB_TVOUT_r);
CodeState = DUMP_INPUTS;
unsigned __xlx_offset_byte_param_din = 0;
// print din Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_din, __xlx_sprintf_buffer.data());
  {  __xlx_offset_byte_param_din = 0*4;
  if (__xlx_apatb_param_din) {
    for (int j = 0  - 0, e = 6 - 0; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)__xlx_apatb_param_din)[j];

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_din, __xlx_sprintf_buffer.data()); 
      }
  }
}
  tcl_file.set_num(6, &tcl_file.din_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_din, __xlx_sprintf_buffer.data());
}
unsigned __xlx_offset_byte_param_dout = 0;
// print dout Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_dout, __xlx_sprintf_buffer.data());
  {  __xlx_offset_byte_param_dout = 0*4;
  if (__xlx_apatb_param_dout) {
    for (int j = 0  - 0, e = 6 - 0; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)__xlx_apatb_param_dout)[j];

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_dout, __xlx_sprintf_buffer.data()); 
      }
  }
}
  tcl_file.set_num(6, &tcl_file.dout_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_dout, __xlx_sprintf_buffer.data());
}
// print counter Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_counter, __xlx_sprintf_buffer.data());
  {
    sc_bv<32> __xlx_tmp_lv = *((int*)__xlx_apatb_param_counter);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_counter, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.counter_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_counter, __xlx_sprintf_buffer.data());
}
// print q Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_q, __xlx_sprintf_buffer.data());
  {
    sc_bv<32> __xlx_tmp_lv = *((int*)&__xlx_apatb_param_q);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_q, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.q_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_q, __xlx_sprintf_buffer.data());
}
// print r Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_r, __xlx_sprintf_buffer.data());
  {
    sc_bv<32> __xlx_tmp_lv = *((int*)&__xlx_apatb_param_r);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_r, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.r_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_r, __xlx_sprintf_buffer.data());
}
CodeState = CALL_C_DUT;
KalmanFilterKernel_hw_stub_wrapper(__xlx_apatb_param_din, __xlx_apatb_param_dout, __xlx_apatb_param_counter, __xlx_apatb_param_q, __xlx_apatb_param_r);
CodeState = DUMP_OUTPUTS;
// print dout Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_dout, __xlx_sprintf_buffer.data());
  {  __xlx_offset_byte_param_dout = 0*4;
  if (__xlx_apatb_param_dout) {
    for (int j = 0  - 0, e = 6 - 0; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)__xlx_apatb_param_dout)[j];

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVOUT_dout, __xlx_sprintf_buffer.data()); 
      }
  }
}
  tcl_file.set_num(6, &tcl_file.dout_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_dout, __xlx_sprintf_buffer.data());
}
CodeState = DELETE_CHAR_BUFFERS;
AESL_transaction++;
tcl_file.set_num(AESL_transaction , &tcl_file.trans_num);
}
