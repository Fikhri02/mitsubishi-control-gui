#pragma once

#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>

#include<thread>
#include<chrono>
#include<cmath>
#include<WS2tcpip.h>
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <fstream> //file stream
#include <sstream> //string stream
#include "strdef.h"
#include"MyForm1.h"
#using<system.dll>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")

#define NO_FLAGS_SET 0
#define MAXBUFLEN 512

WSADATA Datas;
SOCKADDR_IN destSockAddr;
SOCKET destSocket;
unsigned long destAddr;
bool connect_stat;
bool connect_block = 0;
bool execute = false;
int execloop = 0;

int execloopy = 0;
int execloopz = 0;

int status;
int numsnt;
int numrcv;
char sendText[MAXBUFLEN];
char recvText[MAXBUFLEN];
char dst_ip_address[MAXBUFLEN];
unsigned short port;
char msg[MAXBUFLEN];
char buf[MAXBUFLEN];
char type, type_mon[4];
float delta = (float)0.0;
float delta2 = (float)0.0;
float delta3 = (float)0.0;

float alpha = (float)0.0;
float beta = (float)0.0;
float gamma = (float)0.0;
float aratio  = 3.141592 / 180.0;

long nratio = 0.25;
unsigned short IOSendType = 0; // Send input/output signal data designation
unsigned short IORecvType = 0; // Reply input/output signal data designation
unsigned short IOBitTop = 0;
unsigned short IOBitMask = 0xffff;
unsigned short IOBitData = 0;

int keyp = 0;
float xcor[700];

float compx=0;

int xcount = 1;
float curx;

float ycor[700];

float compy = 0;

int ycount = 1;
float cury;

int movx = 0;

MXTCMD MXTsend;
MXTCMD MXTrecv;
JOINT jnt_now;
POSE pos_now;
PULSE pls_now;


int retry;
fd_set SockSet; // Socket group used with select
timeval sTimeOut; // For timeout setting

unsigned long counter = 0;
int loop = 1;
int disp = 0;
int disp_data = 0;
int ch;

float xcoord, ycoord, zcoord, acoord, bcoord, ccoord;
float x[700], y[700], z[700], a[700], b[700], c[700];
int linecount = 0;


namespace multithreadtest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std::chrono_literals;
	using namespace System::Threading;
	using namespace System::IO;

	using namespace std;
	using namespace cv;


	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::TrackBar^ track_incx;
	private: System::Windows::Forms::TrackBar^ track_incy;


	private: System::Windows::Forms::TextBox^ target_IP;
	private: System::Windows::Forms::ComboBox^ Target_PORT;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ BT_Connect;
	private: System::Windows::Forms::Button^ BT_Disconnect;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ x_plus;
	private: System::Windows::Forms::Button^ x_minus;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ Conn_stat;
	private: System::Windows::Forms::Label^ status_t;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ labelX;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ Pos_x;
	private: System::Windows::Forms::TextBox^ Pos_y;
	private: System::Windows::Forms::TextBox^ Pos_z;



	private: System::Windows::Forms::Timer^ pos_polling;
	private: System::Windows::Forms::Button^ y_plus;
	private: System::Windows::Forms::Button^ y_minus;
	private: System::Windows::Forms::Button^ z_plus;
	private: System::Windows::Forms::Button^ z_minus;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton3;
	private: System::Windows::Forms::RadioButton^ radioButton4;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ Pos_A;
	private: System::Windows::Forms::TextBox^ Pos_B;
	private: System::Windows::Forms::TextBox^ Pos_C;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;



	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::RadioButton^ sim_0;
	private: System::Windows::Forms::RadioButton^ sim_1;
	private: System::Windows::Forms::RadioButton^ sim_2;
	private: System::Windows::Forms::RadioButton^ sim_3;
	private: System::Windows::Forms::RadioButton^ sim_4;
	private: System::Windows::Forms::RadioButton^ sim_5;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::RadioButton^ sim_none;
	private: System::Windows::Forms::TextBox^ sim_status;
	private: System::Windows::Forms::Label^ Status_disp;
	private: System::Windows::Forms::Button^ simact_but;
	private: System::Windows::Forms::Button^ simdeact_but;
	private: System::Windows::Forms::TextBox^ rob_move;
	private: System::Windows::Forms::Button^ start_but;
	private: System::Windows::Forms::Button^ stop_but;


	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Button^ pause_but;

	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Button^ pause_pb;

	private: System::Windows::Forms::Button^ stop_pb;

private: System::Windows::Forms::Button^ start_pb;


private: System::Windows::Forms::TextBox^ mode_text;
private: System::Windows::Forms::Label^ label17;
private: System::Windows::Forms::Label^ label18;
private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;


private: System::Windows::Forms::Label^ label19;
private: System::Windows::Forms::TextBox^ text_res;

private: System::Windows::Forms::TextBox^ text_zero;
private: System::Windows::Forms::TextBox^ text_one;
private: System::Windows::Forms::TextBox^ text_two;
private: System::Windows::Forms::TextBox^ text_three;
private: System::Windows::Forms::TextBox^ text_four;
private: System::Windows::Forms::TextBox^ text_five;
private: System::Windows::Forms::TextBox^ remarks_text;
private: System::Windows::Forms::RichTextBox^ Datastream;

private: System::Windows::Forms::Label^ label20;
private: System::Windows::Forms::Label^ label21;
private: System::Windows::Forms::Panel^ panel5;
private: System::Windows::Forms::Label^ label22;
private: System::Windows::Forms::CheckBox^ hsvcheck;
private: System::Windows::Forms::CheckBox^ ycbcrcheck;
private: System::Windows::Forms::CheckBox^ bgcheck;
private: System::Windows::Forms::Button^ capbg;
private: System::Windows::Forms::TextBox^ outext;
private: System::Windows::Forms::Label^ label23;
private: System::Windows::Forms::TextBox^ textBox2;










































	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->track_incx = (gcnew System::Windows::Forms::TrackBar());
			this->track_incy = (gcnew System::Windows::Forms::TrackBar());
			this->target_IP = (gcnew System::Windows::Forms::TextBox());
			this->Target_PORT = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->BT_Connect = (gcnew System::Windows::Forms::Button());
			this->BT_Disconnect = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->x_plus = (gcnew System::Windows::Forms::Button());
			this->x_minus = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Conn_stat = (gcnew System::Windows::Forms::TextBox());
			this->status_t = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->labelX = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->Pos_x = (gcnew System::Windows::Forms::TextBox());
			this->Pos_y = (gcnew System::Windows::Forms::TextBox());
			this->Pos_z = (gcnew System::Windows::Forms::TextBox());
			this->pos_polling = (gcnew System::Windows::Forms::Timer(this->components));
			this->y_plus = (gcnew System::Windows::Forms::Button());
			this->y_minus = (gcnew System::Windows::Forms::Button());
			this->z_plus = (gcnew System::Windows::Forms::Button());
			this->z_minus = (gcnew System::Windows::Forms::Button());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->Pos_A = (gcnew System::Windows::Forms::TextBox());
			this->Pos_B = (gcnew System::Windows::Forms::TextBox());
			this->Pos_C = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->sim_0 = (gcnew System::Windows::Forms::RadioButton());
			this->sim_1 = (gcnew System::Windows::Forms::RadioButton());
			this->sim_2 = (gcnew System::Windows::Forms::RadioButton());
			this->sim_3 = (gcnew System::Windows::Forms::RadioButton());
			this->sim_4 = (gcnew System::Windows::Forms::RadioButton());
			this->sim_5 = (gcnew System::Windows::Forms::RadioButton());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->sim_none = (gcnew System::Windows::Forms::RadioButton());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->sim_status = (gcnew System::Windows::Forms::TextBox());
			this->Status_disp = (gcnew System::Windows::Forms::Label());
			this->simact_but = (gcnew System::Windows::Forms::Button());
			this->simdeact_but = (gcnew System::Windows::Forms::Button());
			this->rob_move = (gcnew System::Windows::Forms::TextBox());
			this->start_but = (gcnew System::Windows::Forms::Button());
			this->stop_but = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->pause_but = (gcnew System::Windows::Forms::Button());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->pause_pb = (gcnew System::Windows::Forms::Button());
			this->stop_pb = (gcnew System::Windows::Forms::Button());
			this->start_pb = (gcnew System::Windows::Forms::Button());
			this->mode_text = (gcnew System::Windows::Forms::TextBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->text_zero = (gcnew System::Windows::Forms::TextBox());
			this->text_one = (gcnew System::Windows::Forms::TextBox());
			this->text_two = (gcnew System::Windows::Forms::TextBox());
			this->text_three = (gcnew System::Windows::Forms::TextBox());
			this->text_four = (gcnew System::Windows::Forms::TextBox());
			this->text_five = (gcnew System::Windows::Forms::TextBox());
			this->remarks_text = (gcnew System::Windows::Forms::TextBox());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->text_res = (gcnew System::Windows::Forms::TextBox());
			this->Datastream = (gcnew System::Windows::Forms::RichTextBox());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->hsvcheck = (gcnew System::Windows::Forms::CheckBox());
			this->ycbcrcheck = (gcnew System::Windows::Forms::CheckBox());
			this->bgcheck = (gcnew System::Windows::Forms::CheckBox());
			this->capbg = (gcnew System::Windows::Forms::Button());
			this->outext = (gcnew System::Windows::Forms::TextBox());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->track_incx))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->track_incy))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->flowLayoutPanel1->SuspendLayout();
			this->panel5->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(649, 362);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"External Cam";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(79, 294);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(178, 20);
			this->textBox1->TabIndex = 2;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(124, 320);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Capture";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(23, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(276, 276);
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(205, 320);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 6;
			this->button3->Text = L"Close Cam";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// track_incx
			// 
			this->track_incx->Location = System::Drawing::Point(7, 25);
			this->track_incx->Maximum = 20;
			this->track_incx->Name = L"track_incx";
			this->track_incx->Size = System::Drawing::Size(129, 45);
			this->track_incx->TabIndex = 7;
			// 
			// track_incy
			// 
			this->track_incy->Location = System::Drawing::Point(4, 76);
			this->track_incy->Maximum = 20;
			this->track_incy->Name = L"track_incy";
			this->track_incy->Size = System::Drawing::Size(132, 45);
			this->track_incy->TabIndex = 8;
			// 
			// target_IP
			// 
			this->target_IP->Location = System::Drawing::Point(332, 42);
			this->target_IP->Name = L"target_IP";
			this->target_IP->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->target_IP->Size = System::Drawing::Size(100, 20);
			this->target_IP->TabIndex = 9;
			this->target_IP->Text = L"192.168.0.25";
			// 
			// Target_PORT
			// 
			this->Target_PORT->FormattingEnabled = true;
			this->Target_PORT->Location = System::Drawing::Point(332, 85);
			this->Target_PORT->Name = L"Target_PORT";
			this->Target_PORT->Size = System::Drawing::Size(121, 21);
			this->Target_PORT->TabIndex = 10;
			this->Target_PORT->Text = L"10000";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(329, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(54, 13);
			this->label1->TabIndex = 11;
			this->label1->Text = L"Target IP:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(332, 69);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(43, 13);
			this->label2->TabIndex = 12;
			this->label2->Text = L"PORT :";
			// 
			// BT_Connect
			// 
			this->BT_Connect->Location = System::Drawing::Point(332, 126);
			this->BT_Connect->Name = L"BT_Connect";
			this->BT_Connect->Size = System::Drawing::Size(75, 23);
			this->BT_Connect->TabIndex = 13;
			this->BT_Connect->Text = L"Connect";
			this->BT_Connect->UseVisualStyleBackColor = true;
			this->BT_Connect->Click += gcnew System::EventHandler(this, &MyForm::BT_Connect_Click);
			// 
			// BT_Disconnect
			// 
			this->BT_Disconnect->Location = System::Drawing::Point(413, 126);
			this->BT_Disconnect->Name = L"BT_Disconnect";
			this->BT_Disconnect->Size = System::Drawing::Size(75, 23);
			this->BT_Disconnect->TabIndex = 14;
			this->BT_Disconnect->Text = L"Disconnect";
			this->BT_Disconnect->UseVisualStyleBackColor = true;
			this->BT_Disconnect->Click += gcnew System::EventHandler(this, &MyForm::BT_Disconnect_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(329, 222);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(46, 13);
			this->label3->TabIndex = 15;
			this->label3->Text = L"Axis Jog";
			// 
			// x_plus
			// 
			this->x_plus->Location = System::Drawing::Point(349, 238);
			this->x_plus->Name = L"x_plus";
			this->x_plus->Size = System::Drawing::Size(18, 23);
			this->x_plus->TabIndex = 16;
			this->x_plus->Text = L"+";
			this->x_plus->UseVisualStyleBackColor = true;
			this->x_plus->Click += gcnew System::EventHandler(this, &MyForm::x_plus_Click);
			// 
			// x_minus
			// 
			this->x_minus->Location = System::Drawing::Point(371, 238);
			this->x_minus->Name = L"x_minus";
			this->x_minus->Size = System::Drawing::Size(18, 23);
			this->x_minus->TabIndex = 17;
			this->x_minus->Text = L"-";
			this->x_minus->UseVisualStyleBackColor = true;
			this->x_minus->Click += gcnew System::EventHandler(this, &MyForm::x_minus_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(329, 243);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(14, 13);
			this->label4->TabIndex = 18;
			this->label4->Text = L"X";
			// 
			// Conn_stat
			// 
			this->Conn_stat->Location = System::Drawing::Point(332, 180);
			this->Conn_stat->Name = L"Conn_stat";
			this->Conn_stat->Size = System::Drawing::Size(100, 20);
			this->Conn_stat->TabIndex = 19;
			this->Conn_stat->Text = L"Disconnected!!!";
			// 
			// status_t
			// 
			this->status_t->AutoSize = true;
			this->status_t->Location = System::Drawing::Point(329, 164);
			this->status_t->Name = L"status_t";
			this->status_t->Size = System::Drawing::Size(37, 13);
			this->status_t->TabIndex = 20;
			this->status_t->Text = L"Status";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(325, 336);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(68, 13);
			this->label5->TabIndex = 21;
			this->label5->Text = L"Current Pos :";
			this->label5->Click += gcnew System::EventHandler(this, &MyForm::label5_Click);
			// 
			// labelX
			// 
			this->labelX->AutoSize = true;
			this->labelX->Location = System::Drawing::Point(329, 362);
			this->labelX->Name = L"labelX";
			this->labelX->Size = System::Drawing::Size(14, 13);
			this->labelX->TabIndex = 22;
			this->labelX->Text = L"X";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(329, 388);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(14, 13);
			this->label6->TabIndex = 23;
			this->label6->Text = L"Y";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(329, 415);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(14, 13);
			this->label7->TabIndex = 24;
			this->label7->Text = L"Z";
			// 
			// Pos_x
			// 
			this->Pos_x->Location = System::Drawing::Point(349, 359);
			this->Pos_x->Name = L"Pos_x";
			this->Pos_x->Size = System::Drawing::Size(44, 20);
			this->Pos_x->TabIndex = 25;
			// 
			// Pos_y
			// 
			this->Pos_y->Location = System::Drawing::Point(349, 385);
			this->Pos_y->Name = L"Pos_y";
			this->Pos_y->Size = System::Drawing::Size(44, 20);
			this->Pos_y->TabIndex = 26;
			// 
			// Pos_z
			// 
			this->Pos_z->Location = System::Drawing::Point(349, 412);
			this->Pos_z->Name = L"Pos_z";
			this->Pos_z->Size = System::Drawing::Size(44, 20);
			this->Pos_z->TabIndex = 27;
			// 
			// pos_polling
			// 
			this->pos_polling->Enabled = true;
			this->pos_polling->Interval = 50;
			this->pos_polling->Tick += gcnew System::EventHandler(this, &MyForm::pos_polling_Tick);
			// 
			// y_plus
			// 
			this->y_plus->Location = System::Drawing::Point(349, 267);
			this->y_plus->Name = L"y_plus";
			this->y_plus->Size = System::Drawing::Size(18, 23);
			this->y_plus->TabIndex = 28;
			this->y_plus->Text = L"+";
			this->y_plus->UseVisualStyleBackColor = true;
			this->y_plus->Click += gcnew System::EventHandler(this, &MyForm::y_plus_Click);
			// 
			// y_minus
			// 
			this->y_minus->Location = System::Drawing::Point(371, 267);
			this->y_minus->Name = L"y_minus";
			this->y_minus->Size = System::Drawing::Size(18, 23);
			this->y_minus->TabIndex = 29;
			this->y_minus->Text = L"-";
			this->y_minus->UseVisualStyleBackColor = true;
			this->y_minus->Click += gcnew System::EventHandler(this, &MyForm::y_minus_Click);
			// 
			// z_plus
			// 
			this->z_plus->Location = System::Drawing::Point(349, 296);
			this->z_plus->Name = L"z_plus";
			this->z_plus->Size = System::Drawing::Size(17, 23);
			this->z_plus->TabIndex = 30;
			this->z_plus->Text = L"+";
			this->z_plus->UseVisualStyleBackColor = true;
			this->z_plus->Click += gcnew System::EventHandler(this, &MyForm::z_plus_Click);
			// 
			// z_minus
			// 
			this->z_minus->Location = System::Drawing::Point(371, 296);
			this->z_minus->Name = L"z_minus";
			this->z_minus->Size = System::Drawing::Size(18, 23);
			this->z_minus->TabIndex = 31;
			this->z_minus->Text = L"-";
			this->z_minus->UseVisualStyleBackColor = true;
			this->z_minus->Click += gcnew System::EventHandler(this, &MyForm::z_minus_Click);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(3, 32);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(46, 17);
			this->radioButton1->TabIndex = 32;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"0.25";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(3, 56);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(40, 17);
			this->radioButton2->TabIndex = 33;
			this->radioButton2->Text = L"0.5";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(3, 80);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(46, 17);
			this->radioButton3->TabIndex = 34;
			this->radioButton3->Text = L"0.75";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(3, 103);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(40, 17);
			this->radioButton4->TabIndex = 35;
			this->radioButton4->Text = L"1.0";
			this->radioButton4->UseVisualStyleBackColor = true;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(0, 5);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(57, 13);
			this->label8->TabIndex = 36;
			this->label8->Text = L"Resolution";
			// 
			// Pos_A
			// 
			this->Pos_A->Location = System::Drawing::Point(421, 359);
			this->Pos_A->Name = L"Pos_A";
			this->Pos_A->Size = System::Drawing::Size(46, 20);
			this->Pos_A->TabIndex = 37;
			// 
			// Pos_B
			// 
			this->Pos_B->Location = System::Drawing::Point(421, 385);
			this->Pos_B->Name = L"Pos_B";
			this->Pos_B->Size = System::Drawing::Size(46, 20);
			this->Pos_B->TabIndex = 38;
			// 
			// Pos_C
			// 
			this->Pos_C->Location = System::Drawing::Point(421, 412);
			this->Pos_C->Name = L"Pos_C";
			this->Pos_C->Size = System::Drawing::Size(46, 20);
			this->Pos_C->TabIndex = 39;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(401, 362);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(14, 13);
			this->label9->TabIndex = 40;
			this->label9->Text = L"A";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(401, 388);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(14, 13);
			this->label10->TabIndex = 41;
			this->label10->Text = L"B";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(401, 415);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(14, 13);
			this->label11->TabIndex = 42;
			this->label11->Text = L"C";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(329, 272);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(14, 13);
			this->label12->TabIndex = 45;
			this->label12->Text = L"Y";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(329, 301);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(14, 13);
			this->label13->TabIndex = 46;
			this->label13->Text = L"Z";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(0, 3);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(64, 13);
			this->label14->TabIndex = 47;
			this->label14->Text = L"Gesture Sim";
			// 
			// sim_0
			// 
			this->sim_0->AutoSize = true;
			this->sim_0->Location = System::Drawing::Point(3, 44);
			this->sim_0->Name = L"sim_0";
			this->sim_0->Size = System::Drawing::Size(31, 17);
			this->sim_0->TabIndex = 48;
			this->sim_0->Text = L"0";
			this->sim_0->UseVisualStyleBackColor = true;
			// 
			// sim_1
			// 
			this->sim_1->AutoSize = true;
			this->sim_1->Location = System::Drawing::Point(3, 67);
			this->sim_1->Name = L"sim_1";
			this->sim_1->Size = System::Drawing::Size(31, 17);
			this->sim_1->TabIndex = 49;
			this->sim_1->Text = L"1";
			this->sim_1->UseVisualStyleBackColor = true;
			// 
			// sim_2
			// 
			this->sim_2->AutoSize = true;
			this->sim_2->Location = System::Drawing::Point(3, 91);
			this->sim_2->Name = L"sim_2";
			this->sim_2->Size = System::Drawing::Size(31, 17);
			this->sim_2->TabIndex = 50;
			this->sim_2->Text = L"2";
			this->sim_2->UseVisualStyleBackColor = true;
			// 
			// sim_3
			// 
			this->sim_3->AutoSize = true;
			this->sim_3->Location = System::Drawing::Point(3, 115);
			this->sim_3->Name = L"sim_3";
			this->sim_3->Size = System::Drawing::Size(31, 17);
			this->sim_3->TabIndex = 51;
			this->sim_3->Text = L"3";
			this->sim_3->UseVisualStyleBackColor = true;
			// 
			// sim_4
			// 
			this->sim_4->AutoSize = true;
			this->sim_4->Location = System::Drawing::Point(3, 139);
			this->sim_4->Name = L"sim_4";
			this->sim_4->Size = System::Drawing::Size(31, 17);
			this->sim_4->TabIndex = 52;
			this->sim_4->Text = L"4";
			this->sim_4->UseVisualStyleBackColor = true;
			// 
			// sim_5
			// 
			this->sim_5->AutoSize = true;
			this->sim_5->Location = System::Drawing::Point(3, 163);
			this->sim_5->Name = L"sim_5";
			this->sim_5->Size = System::Drawing::Size(31, 17);
			this->sim_5->TabIndex = 53;
			this->sim_5->Text = L"5";
			this->sim_5->UseVisualStyleBackColor = true;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->sim_none);
			this->panel1->Controls->Add(this->sim_3);
			this->panel1->Controls->Add(this->sim_5);
			this->panel1->Controls->Add(this->label14);
			this->panel1->Controls->Add(this->sim_4);
			this->panel1->Controls->Add(this->sim_0);
			this->panel1->Controls->Add(this->sim_1);
			this->panel1->Controls->Add(this->sim_2);
			this->panel1->Location = System::Drawing::Point(513, 102);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(79, 193);
			this->panel1->TabIndex = 54;
			// 
			// sim_none
			// 
			this->sim_none->AutoSize = true;
			this->sim_none->Checked = true;
			this->sim_none->Location = System::Drawing::Point(3, 21);
			this->sim_none->Name = L"sim_none";
			this->sim_none->Size = System::Drawing::Size(51, 17);
			this->sim_none->TabIndex = 54;
			this->sim_none->TabStop = true;
			this->sim_none->Text = L"None";
			this->sim_none->UseVisualStyleBackColor = true;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->radioButton3);
			this->panel2->Controls->Add(this->radioButton1);
			this->panel2->Controls->Add(this->radioButton2);
			this->panel2->Controls->Add(this->radioButton4);
			this->panel2->Controls->Add(this->label8);
			this->panel2->Location = System::Drawing::Point(404, 222);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(61, 126);
			this->panel2->TabIndex = 55;
			// 
			// sim_status
			// 
			this->sim_status->Location = System::Drawing::Point(473, 42);
			this->sim_status->Name = L"sim_status";
			this->sim_status->Size = System::Drawing::Size(119, 20);
			this->sim_status->TabIndex = 56;
			this->sim_status->Text = L"Simulation Deactivated";
			this->sim_status->TextChanged += gcnew System::EventHandler(this, &MyForm::sim_status_TextChanged);
			// 
			// Status_disp
			// 
			this->Status_disp->AutoSize = true;
			this->Status_disp->Location = System::Drawing::Point(473, 24);
			this->Status_disp->Name = L"Status_disp";
			this->Status_disp->Size = System::Drawing::Size(55, 13);
			this->Status_disp->TabIndex = 57;
			this->Status_disp->Text = L"Sim status";
			// 
			// simact_but
			// 
			this->simact_but->Location = System::Drawing::Point(473, 69);
			this->simact_but->Name = L"simact_but";
			this->simact_but->Size = System::Drawing::Size(75, 23);
			this->simact_but->TabIndex = 58;
			this->simact_but->Text = L"Activate";
			this->simact_but->UseVisualStyleBackColor = true;
			this->simact_but->Click += gcnew System::EventHandler(this, &MyForm::simact_but_Click);
			// 
			// simdeact_but
			// 
			this->simdeact_but->Location = System::Drawing::Point(555, 69);
			this->simdeact_but->Name = L"simdeact_but";
			this->simdeact_but->Size = System::Drawing::Size(75, 23);
			this->simdeact_but->TabIndex = 59;
			this->simdeact_but->Text = L"Deactivate";
			this->simdeact_but->UseVisualStyleBackColor = true;
			this->simdeact_but->Click += gcnew System::EventHandler(this, &MyForm::simdeact_but_Click);
			// 
			// rob_move
			// 
			this->rob_move->Location = System::Drawing::Point(492, 302);
			this->rob_move->Name = L"rob_move";
			this->rob_move->Size = System::Drawing::Size(100, 20);
			this->rob_move->TabIndex = 60;
			// 
			// start_but
			// 
			this->start_but->Location = System::Drawing::Point(3, 3);
			this->start_but->Name = L"start_but";
			this->start_but->Size = System::Drawing::Size(75, 23);
			this->start_but->TabIndex = 61;
			this->start_but->Text = L"Start";
			this->start_but->UseVisualStyleBackColor = true;
			this->start_but->Click += gcnew System::EventHandler(this, &MyForm::start_but_Click);
			// 
			// stop_but
			// 
			this->stop_but->Location = System::Drawing::Point(81, 3);
			this->stop_but->Name = L"stop_but";
			this->stop_but->Size = System::Drawing::Size(75, 23);
			this->stop_but->TabIndex = 62;
			this->stop_but->Text = L"Stop";
			this->stop_but->UseVisualStyleBackColor = true;
			this->stop_but->Click += gcnew System::EventHandler(this, &MyForm::stop_but_Click);
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->pause_but);
			this->panel3->Controls->Add(this->start_but);
			this->panel3->Controls->Add(this->stop_but);
			this->panel3->Location = System::Drawing::Point(473, 345);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(159, 60);
			this->panel3->TabIndex = 63;
			// 
			// pause_but
			// 
			this->pause_but->Location = System::Drawing::Point(40, 32);
			this->pause_but->Name = L"pause_but";
			this->pause_but->Size = System::Drawing::Size(75, 23);
			this->pause_but->TabIndex = 63;
			this->pause_but->Text = L"Pause";
			this->pause_but->UseVisualStyleBackColor = true;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(476, 329);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(56, 13);
			this->label15->TabIndex = 64;
			this->label15->Text = L"Recording";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(476, 412);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(51, 13);
			this->label16->TabIndex = 65;
			this->label16->Text = L"Playback";
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->pause_pb);
			this->panel4->Controls->Add(this->stop_pb);
			this->panel4->Controls->Add(this->start_pb);
			this->panel4->Location = System::Drawing::Point(473, 429);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(159, 62);
			this->panel4->TabIndex = 66;
			// 
			// pause_pb
			// 
			this->pause_pb->Location = System::Drawing::Point(40, 33);
			this->pause_pb->Name = L"pause_pb";
			this->pause_pb->Size = System::Drawing::Size(75, 23);
			this->pause_pb->TabIndex = 2;
			this->pause_pb->Text = L"Pause";
			this->pause_pb->UseVisualStyleBackColor = true;
			// 
			// stop_pb
			// 
			this->stop_pb->Location = System::Drawing::Point(82, 4);
			this->stop_pb->Name = L"stop_pb";
			this->stop_pb->Size = System::Drawing::Size(75, 23);
			this->stop_pb->TabIndex = 1;
			this->stop_pb->Text = L"Stop";
			this->stop_pb->UseVisualStyleBackColor = true;
			// 
			// start_pb
			// 
			this->start_pb->Location = System::Drawing::Point(6, 4);
			this->start_pb->Name = L"start_pb";
			this->start_pb->Size = System::Drawing::Size(75, 23);
			this->start_pb->TabIndex = 0;
			this->start_pb->Text = L"Start";
			this->start_pb->UseVisualStyleBackColor = true;
			this->start_pb->Click += gcnew System::EventHandler(this, &MyForm::start_pb_Click);
			// 
			// mode_text
			// 
			this->mode_text->BackColor = System::Drawing::Color::Aqua;
			this->mode_text->ForeColor = System::Drawing::SystemColors::MenuText;
			this->mode_text->Location = System::Drawing::Point(43, 3);
			this->mode_text->Name = L"mode_text";
			this->mode_text->Size = System::Drawing::Size(154, 20);
			this->mode_text->TabIndex = 69;
			this->mode_text->Text = L"Manual gesture control";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(3, 0);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(34, 13);
			this->label17->TabIndex = 70;
			this->label17->Text = L"Mode";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(3, 26);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(56, 13);
			this->label18->TabIndex = 71;
			this->label18->Text = L"Guidelines";
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->label17);
			this->flowLayoutPanel1->Controls->Add(this->mode_text);
			this->flowLayoutPanel1->Controls->Add(this->label18);
			this->flowLayoutPanel1->Controls->Add(this->text_zero);
			this->flowLayoutPanel1->Controls->Add(this->text_one);
			this->flowLayoutPanel1->Controls->Add(this->text_two);
			this->flowLayoutPanel1->Controls->Add(this->text_three);
			this->flowLayoutPanel1->Controls->Add(this->text_four);
			this->flowLayoutPanel1->Controls->Add(this->text_five);
			this->flowLayoutPanel1->Controls->Add(this->remarks_text);
			this->flowLayoutPanel1->Controls->Add(this->label19);
			this->flowLayoutPanel1->Controls->Add(this->text_res);
			this->flowLayoutPanel1->Location = System::Drawing::Point(649, 18);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(214, 277);
			this->flowLayoutPanel1->TabIndex = 72;
			// 
			// text_zero
			// 
			this->text_zero->BackColor = System::Drawing::SystemColors::Window;
			this->text_zero->Location = System::Drawing::Point(3, 42);
			this->text_zero->Name = L"text_zero";
			this->text_zero->Size = System::Drawing::Size(194, 20);
			this->text_zero->TabIndex = 77;
			// 
			// text_one
			// 
			this->text_one->Location = System::Drawing::Point(3, 68);
			this->text_one->Name = L"text_one";
			this->text_one->Size = System::Drawing::Size(194, 20);
			this->text_one->TabIndex = 78;
			// 
			// text_two
			// 
			this->text_two->Location = System::Drawing::Point(3, 94);
			this->text_two->Name = L"text_two";
			this->text_two->Size = System::Drawing::Size(194, 20);
			this->text_two->TabIndex = 79;
			// 
			// text_three
			// 
			this->text_three->Location = System::Drawing::Point(3, 120);
			this->text_three->Name = L"text_three";
			this->text_three->Size = System::Drawing::Size(194, 20);
			this->text_three->TabIndex = 80;
			// 
			// text_four
			// 
			this->text_four->Location = System::Drawing::Point(3, 146);
			this->text_four->Name = L"text_four";
			this->text_four->Size = System::Drawing::Size(194, 20);
			this->text_four->TabIndex = 81;
			// 
			// text_five
			// 
			this->text_five->Location = System::Drawing::Point(3, 172);
			this->text_five->Name = L"text_five";
			this->text_five->Size = System::Drawing::Size(194, 20);
			this->text_five->TabIndex = 82;
			// 
			// remarks_text
			// 
			this->remarks_text->Location = System::Drawing::Point(3, 198);
			this->remarks_text->Name = L"remarks_text";
			this->remarks_text->Size = System::Drawing::Size(194, 20);
			this->remarks_text->TabIndex = 83;
			this->remarks_text->Text = L"No remarks";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(3, 221);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(57, 13);
			this->label19->TabIndex = 75;
			this->label19->Text = L"Resolution";
			// 
			// text_res
			// 
			this->text_res->Location = System::Drawing::Point(3, 237);
			this->text_res->Name = L"text_res";
			this->text_res->Size = System::Drawing::Size(194, 20);
			this->text_res->TabIndex = 76;
			// 
			// Datastream
			// 
			this->Datastream->Location = System::Drawing::Point(649, 302);
			this->Datastream->Name = L"Datastream";
			this->Datastream->Size = System::Drawing::Size(102, 48);
			this->Datastream->TabIndex = 75;
			this->Datastream->Text = L"";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(4, 5);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(35, 13);
			this->label20->TabIndex = 77;
			this->label20->Text = L"X-axis";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(4, 58);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(35, 13);
			this->label21->TabIndex = 78;
			this->label21->Text = L"Y-axis";
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->label20);
			this->panel5->Controls->Add(this->label21);
			this->panel5->Controls->Add(this->track_incx);
			this->panel5->Controls->Add(this->track_incy);
			this->panel5->Location = System::Drawing::Point(43, 368);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(156, 123);
			this->panel5->TabIndex = 79;
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(43, 352);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(62, 13);
			this->label22->TabIndex = 80;
			this->label22->Text = L"ROI Control";
			// 
			// hsvcheck
			// 
			this->hsvcheck->AutoSize = true;
			this->hsvcheck->Location = System::Drawing::Point(217, 385);
			this->hsvcheck->Name = L"hsvcheck";
			this->hsvcheck->Size = System::Drawing::Size(48, 17);
			this->hsvcheck->TabIndex = 81;
			this->hsvcheck->Text = L"HSV";
			this->hsvcheck->UseVisualStyleBackColor = true;
			// 
			// ycbcrcheck
			// 
			this->ycbcrcheck->AutoSize = true;
			this->ycbcrcheck->Location = System::Drawing::Point(217, 407);
			this->ycbcrcheck->Name = L"ycbcrcheck";
			this->ycbcrcheck->Size = System::Drawing::Size(56, 17);
			this->ycbcrcheck->TabIndex = 82;
			this->ycbcrcheck->Text = L"YCbCr";
			this->ycbcrcheck->UseVisualStyleBackColor = true;
			// 
			// bgcheck
			// 
			this->bgcheck->AutoSize = true;
			this->bgcheck->Location = System::Drawing::Point(217, 431);
			this->bgcheck->Name = L"bgcheck";
			this->bgcheck->Size = System::Drawing::Size(84, 17);
			this->bgcheck->TabIndex = 83;
			this->bgcheck->Text = L"Bg Removal";
			this->bgcheck->UseVisualStyleBackColor = true;
			// 
			// capbg
			// 
			this->capbg->Enabled = false;
			this->capbg->Location = System::Drawing::Point(217, 455);
			this->capbg->Name = L"capbg";
			this->capbg->Size = System::Drawing::Size(75, 23);
			this->capbg->TabIndex = 84;
			this->capbg->Text = L"Capture Bg";
			this->capbg->UseVisualStyleBackColor = true;
			this->capbg->Click += gcnew System::EventHandler(this, &MyForm::capbg_Click);
			// 
			// outext
			// 
			this->outext->Location = System::Drawing::Point(263, 294);
			this->outext->Name = L"outext";
			this->outext->Size = System::Drawing::Size(38, 20);
			this->outext->TabIndex = 85;
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(787, 308);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(41, 13);
			this->label23->TabIndex = 86;
			this->label23->Text = L"label23";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(649, 393);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(197, 20);
			this->textBox2->TabIndex = 87;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(877, 659);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label23);
			this->Controls->Add(this->outext);
			this->Controls->Add(this->capbg);
			this->Controls->Add(this->bgcheck);
			this->Controls->Add(this->ycbcrcheck);
			this->Controls->Add(this->hsvcheck);
			this->Controls->Add(this->label22);
			this->Controls->Add(this->panel5);
			this->Controls->Add(this->Datastream);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->rob_move);
			this->Controls->Add(this->simdeact_but);
			this->Controls->Add(this->simact_but);
			this->Controls->Add(this->Status_disp);
			this->Controls->Add(this->sim_status);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->Pos_C);
			this->Controls->Add(this->Pos_B);
			this->Controls->Add(this->Pos_A);
			this->Controls->Add(this->z_minus);
			this->Controls->Add(this->z_plus);
			this->Controls->Add(this->y_minus);
			this->Controls->Add(this->y_plus);
			this->Controls->Add(this->Pos_z);
			this->Controls->Add(this->Pos_y);
			this->Controls->Add(this->Pos_x);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->labelX);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->status_t);
			this->Controls->Add(this->Conn_stat);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->x_minus);
			this->Controls->Add(this->x_plus);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->BT_Disconnect);
			this->Controls->Add(this->BT_Connect);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Target_PORT);
			this->Controls->Add(this->target_IP);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"Mitsubishi Robot Gesture Control";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->track_incx))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->track_incy))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->PerformLayout();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}


#pragma endregion
		System::String^ text = "";
		VideoCapture* cap;
		bool camloop = false, capbgbt = false;
		//bool cam2loop;

		bool xp_click = false;
		int res = 0;

		float delta2 = 0;

		float pdeltax = 0.0;
		float pdeltay = 0.0;
		float pdeltaz = 0.0;

		bool pdeltal = true;

		bool sim_bool = false;

		bool record_stat = false;
		bool playback_bool = false;

		int start_rec = 1;
		int num1 = 0;
		int num2 = 0;

		System::String^ fileName = "recorded_file.txt";
		int rec_count = 0;

		StreamWriter^ sw = gcnew StreamWriter(fileName);

		//Simulation substitutes:

		int temp = 0;
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		ThreadStart^ Thread1 = gcnew ThreadStart(this, &MyForm::function1);
		Thread^ MyThread1 = gcnew Thread(Thread1);
		MyThread1->Start();
		
	}

		   void function1() {
			   //Invoke(gcnew System::Action(this, &MyForm::Add1));
			   //initialize winsock
			   WSADATA wsData; //data structure
			   WORD ver = MAKEWORD(2, 2); //winsock version

			   int wsOk = WSAStartup(ver, &wsData); //0 for succesful
			   if (wsOk != 0)
			   {

				   System::Windows::Forms::MessageBox::Show("Can't initialize winsock! Quitting");
				   return;
			   }
			   // create a socket
			   SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);//V4,TCP SOCKET, (AF_INET for TCP or UDP) (type: SOCK_STREAN or SOCK_DGRAM)(IPPPROTO_TCP for TCP)
			   //0 if success
			   //if (listening == INVALID_SOCKET)
			   if (listening == 0)
			   {
				   System::Windows::Forms::MessageBox::Show("Can't create a socket! Quitting");
				   WSACleanup(); //WSAGetLastError() for error checking
				   WSAGetLastError();
				   System::Windows::Forms::MessageBox::Show(WSAGetLastError().ToString());
				   //free resource
				   return;
			   }

			   //bind the ip address and port to a socket
			   sockaddr_in hint;
			   hint.sin_family = AF_INET;
			   hint.sin_port = htons(9999); //host to network short//host to network short (little indian format ot network byte order format)
			   hint.sin_addr.S_un.S_addr = INADDR_ANY;

			   if(::bind(listening, (sockaddr*)&hint, sizeof(hint))<0); //1. Socket type,2. struccture in sockaddr_in,3.size of the structure 
			   //0 if succesful
			   exstats = 2;
			   // Tell winsock the socket is listening
			   listen(listening, SOMAXCONN); //listen to incoming clients SOMAXCONN to specify limit client.
			   //0 if succesful SOCKET_ERROR if error

			   //Wait for a connection
			   sockaddr_in client;
			   int clientSize = sizeof(client);

			   SOCKET clientSocket = accept(listening, (sockaddr*)&client, &clientSize); //permits an incoming connection on a socket addr:optional structure containing the client address information
			   char host[NI_MAXHOST];
			   char service[NI_MAXHOST];

			   ZeroMemory(host, NI_MAXHOST);
			   ZeroMemory(service, NI_MAXHOST);

			   if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0)
			   {
				   exstats = 1;
			   }
			   else
			   {
				   inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
				   System::Windows::Forms::MessageBox::Show("else" + ntohs(client.sin_port));
			   }

			   //close listening socket
			   closesocket(listening);
			   //while loop: accept and echo message abck to client
			   char buf[4096];

			   while (true)
			   {
				   ZeroMemory(buf, 4096);

				   //wait for client to send data
				   int bytesReceived = recv(clientSocket, buf, 4096, 0);
				   if (bytesReceived == SOCKET_ERROR)
				   {
					   System::Windows::Forms::MessageBox::Show("Error in recv(). Quitting");
					   System::Windows::Forms::MessageBox::Show(WSAGetLastError().ToString());
					   break;
				   }
				   if (bytesReceived == 0)
				   {
					   System::Windows::Forms::MessageBox::Show("Client disconnected");
					   exstats = 3;
					   break;
				   }

				   //BYTE bytesReceived[5] = { 0x48, 0x65, 0x6C, 0x6C, 0x6F };
				   temp = bytesReceived;


				   string str(buf);
				   text = gcnew System::String(str.data());
				   send(clientSocket, buf, bytesReceived, 0);

				   //Echo message back to client
			   }
			   exstats = 0;
			   //Close the socket
			   closesocket(clientSocket);
			   //shutdown winsock
			   WSACleanup();
		   }
		   

		   int l = 0;
		   int cntr=0;
		   bool startcntr = false;

		   int exstats = 0;

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

		VideoCapture cap(0);

		if (!cap.isOpened()) {
			textBox1->Text = "Error opening video stream";
		}
		else {
			textBox1->Text = "Video stream opened";
		}
		vector<cv::Rect> Rectangles_for_objects1;

		Mat reframe;

		int ind = 0;

		double Hl = 0, Sl = 23, Vl = 89, Hu = 50, Su = 255, Vu = 255;
		double Yl = 0, Cbl = 134, Crl = 100, Yu = 255, Cbu = 200, Cru = 150;
		
		double a = 0, b = 0, c = 0, s = 0, ar = 0, d = 0, angle = 0;

		Mat image1;
		Mat copyimage1;
		Mat procimage1;
		Mat fgmask;

		Mat ftd_hsv;
		Mat ftd_ycbcr;

		Mat graydiff, grayinv;
		Mat hsvframe;
		Mat yccframe;

		Mat bgref, diff, diff1, diff2;

		Mat yccsegmented, hsvsegmented, bgsegmented;

		//Mat subtractedImg = Mat::zeros(cv::Size(1280, 720), CV_8UC3);
		//Mat subtractedImg2 = Mat::zeros(cv::Size(1280, 720), CV_8UC3);
		//Mat frameGlobal;

		//int frameCounter = 0;
		//Mat frame, hsv, hsvPrev, framePrev, subtractedImgGray, bg;


		int incx, incy;

		int hsvwind = 0, yccwind = 0, bgsubwind = 0;

		std::vector<std::vector<cv::Point>> contours;

		camloop = true;

		int p1height = pictureBox1->Height;
		int p1width = pictureBox1->Width;

		//std::this_thread::sleep_for(std::chrono::milliseconds(200));
		cap.open(0);

		while (camloop)
		{
			/*
			double Hl = lhtk->Value, Sl = lstk->Value, Vl = lvtk->Value, Hu = htk->Value, Su = stk->Value, Vu = vtk->Value;
			double Yl = lytk->Value, Cbl = lcbtk->Value, Crl = lcrtk->Value, Yu = ytk->Value, Cbu = cbtk->Value, Cru = crtk->Value;

			label23->Text = lhtk->Value.ToString();
			label24->Text = lstk->Value.ToString();
			label25->Text = lvtk->Value.ToString();
			label26->Text = htk->Value.ToString();
			label27->Text = stk->Value.ToString();
			label28->Text = vtk->Value.ToString();

			label29->Text = lytk->Value.ToString();
			label30->Text = lcbtk->Value.ToString();
			label31->Text = lcrtk->Value.ToString();
			label32->Text = ytk->Value.ToString();
			label33->Text = cbtk->Value.ToString();
			label34->Text = crtk->Value.ToString();
			*/
			cap.read(image1);
			flip(image1, image1, 1);
			procimage1 = image1.clone();

				
			int imrows = image1.rows;
			int imcols = image1.cols;
			int percx = 3;
			int percy = 4;

			int x1 = 0 + (track_incx->Value) * 0.035 * imcols;
			int y1 = 0 + (track_incy->Value) * 0.03 * imrows;
			int x2 = 0.1 * percx * imcols + (track_incx->Value) * 0.035 * imcols;
			int y2 = 0.1 * percy * imrows + (track_incy->Value) * 0.03 * imrows;

			int width = x2 - x1, height = y2 - y1;

			Mat segmented, kernel = getStructuringElement(MORPH_RECT, cv::Size(3, 3));
			cv::Point pt3(x1, y1);
			cv::Point pt4(x2, y2);
			Rect rect_seg(x1, y1, width, height);
			copyimage1 = image1.clone();
			cv::rectangle(copyimage1, pt3, pt4, cv::Scalar(255, 0, 255), 2);

			resize(copyimage1, reframe, cv::Size(p1height, p1width));


			Bitmap^ bmp = gcnew System::Drawing::Bitmap(
				reframe.cols, reframe.rows, reframe.step,
				System::Drawing::Imaging::PixelFormat::Format24bppRgb,
				(System::IntPtr)reframe.ptr());

			pictureBox1->Image = bmp;
			waitKey(1); //will display a frame for 1 ms, after which display will be automatically closed
			pictureBox1->Refresh();

			segmented = procimage1(rect_seg);

			Mat hsvcanv(segmented.rows, segmented.cols, CV_8UC1, cv::Scalar(255, 255, 255));
			Mat ycccanv(segmented.rows, segmented.cols, CV_8UC1, cv::Scalar(255, 255, 255));
			Mat bgcanv(segmented.cols, segmented.rows, CV_8UC1, cv::Scalar(255, 255, 255));

			Mat merge1, merge2;

			if (hsvcheck->Checked)
			{
				cvtColor(image1, hsvframe, COLOR_BGR2HSV);
				inRange(hsvframe, Scalar(Hl, Sl, Vl), Scalar(Hu, Su, Vu), ftd_hsv);
				imshow("HSV", ftd_hsv);
				hsvsegmented = ftd_hsv(rect_seg);
				hsvcanv = hsvsegmented.clone();
				hsvwind = 1;


			}
			else
			{
				if (hsvwind == 1)
				{
					destroyWindow("HSV");
				}
				hsvwind = 0;
			}


			if (ycbcrcheck->Checked)
			{
				cvtColor(image1, yccframe, COLOR_BGR2YCrCb);
				inRange(yccframe, Scalar(Yl, Cbl, Crl), Scalar(Yu, Cbu, Cru), ftd_ycbcr);
				imshow("YCbCr", ftd_ycbcr);
				yccsegmented = ftd_ycbcr(rect_seg);
				ycccanv = yccsegmented.clone();
				yccwind = 1;
			}
			else
			{
				if (yccwind == 1)
				{
					destroyWindow("YCbCr");
				}
				yccwind = 0;
			}

			if (bgcheck->Checked)
			{
				capbg->Enabled = true;
				if (!bgref.empty())
				{

					subtract(procimage1, bgref, diff1);
					subtract(bgref, procimage1, diff2);
					diff = diff1 + diff2;
					bgsubwind = 1;
					threshold(diff, diff, 20, 255, THRESH_BINARY);
					imshow("bgsub", diff);
					cvtColor(diff, graydiff, COLOR_BGR2GRAY);
					threshold(graydiff, graydiff, 10, 255, 1);
					for (int h = 0; h++; h < 3)
					{
						erode(graydiff, graydiff, kernel);
					}

					for (int h = 0; h++; h < 5000)
					{
						dilate(graydiff, graydiff, kernel);
					}
					bitwise_not(graydiff, grayinv);
					erode(grayinv, grayinv, kernel);
					dilate(grayinv, grayinv, kernel);
					dilate(grayinv, grayinv, kernel);
					imshow("Graythresh", grayinv);

					bgsegmented = grayinv(rect_seg);

					erode(bgsegmented, bgsegmented, kernel);
					bgcanv = bgsegmented.clone();
				}
			}
			else
			{
				capbg->Enabled = false;
				if (bgsubwind == 1)
				{
					destroyWindow("bgsub");
					destroyWindow("Graythresh");
				}
				bgsubwind = 0;
			}
			if (capbgbt)
			{
				cap.read(bgref);
				flip(bgref, bgref, 1);
				imshow("ref", bgref);
				capbgbt = false;
			}

			if (hsvcheck->Checked|| ycbcrcheck->Checked || bgcheck->Checked)
			{
				int deger = 8;

				if (!hsvsegmented.empty() || !yccsegmented.empty() || !bgsegmented.empty())
				{

					bitwise_and(ycccanv, hsvcanv, merge1);

					Mat contourOutput;
					try
					{
						bitwise_and(merge1, bgcanv, merge2);
						contourOutput = merge2.clone();
						imshow("Resultant", merge2);
					}
					catch (exception ex)
					{
						contourOutput = merge1.clone();
					}

					//imshow("result2", bgcanv);

					std::vector<std::vector<cv::Point>> contours;
					vector<Vec4i> hierarchy;
					findContours(contourOutput, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

					Mat black(320, 240, CV_8UC3, cv::Scalar(0, 0, 0));
					resize(black, black, cv::Size(segmented.cols, segmented.rows));

					//Mat frame_copy = black.clone();
					Mat cizim = black.clone();

					Mat frame_copy(segmented.cols, segmented.rows, CV_8UC1, cv::Scalar(0, 0, 0));

					Canny(merge2, frame_copy, deger, deger * 2, 3);
					drawContours(cizim, contours, -1, Scalar(0, 255, 0), 2);

					Mat black2 = black.clone();
					Mat hulldraw = black.clone();

					//erode(prochsv, prochsv, kernel);
					//erode(prochsv, prochsv, kernel);
					//dilate(prochsv, prochsv, kernel);

					Mat canvas = Mat::zeros(segmented.size(), CV_8UC3);
					if (contours.size() > 0) {
						size_t indexOfBiggestContour = -1;
						size_t sizeOfBiggestContour = 0;
						for (size_t i = 0; i < contours.size(); i++) {
							if (contours[i].size() > sizeOfBiggestContour) {
								sizeOfBiggestContour = contours[i].size();
								indexOfBiggestContour = i;
							}
						}
						vector<vector<int> >hull(contours.size());
						vector<vector<cv::Point> >hullPoint(contours.size()); //elin hareketine göre eli çevreleyen çokgen	
						vector<vector<cv::Vec4i> > defects(contours.size()); //parmak uclarindaki yesil noktalar..multi dimensional matrix
						vector<vector<cv::Point> >defectPoint(contours.size()); //point olarak parmak ucu noktalarýný x,y olarak tutuyor
						vector<vector<cv::Point> >contours_poly(contours.size()); //eli çevreleyen hareketli dikdörtgen		
						Point2f rect_point[4];
						vector<RotatedRect>minRect(contours.size());
						vector<Rect> boundRect(contours.size());

						if (num2 == 0)
						{
							l = 0;
						}
						else if (num2 == 1)
						{
							num1 = 0;
						}
						try {
							for (size_t i = 0; i < contours.size(); i++) {
								if (contourArea(contours[i]) > 5000) {
									convexHull(contours[i], hull[i], true);
									convexityDefects(contours[i], hull[i], defects[i]);
									if (indexOfBiggestContour == i) {
										minRect[i] = minAreaRect(contours[i]);
										for (size_t k = 0; k < hull[i].size(); k++) {
											int ind = hull[i][k];
											hullPoint[i].push_back(contours[i][ind]);
										}

										for (size_t k = 0; k < defects[i].size(); k++) {
											if (defects[i][k][3] > 13 * 256) {
												int p_start = defects[i][k][0];
												int p_end = defects[i][k][1];
												int p_far = defects[i][k][2];

												cv::Point startPoint = contours[i][p_start];
												cv::Point endPoint = contours[i][p_end];
												cv::Point farPoint = contours[i][p_far];

												line(frame_copy, startPoint, endPoint, Scalar(255), 2);


												a = sqrt(pow(endPoint.x - startPoint.x, 2) + pow(endPoint.y - startPoint.y, 2));
												b = sqrt(pow(farPoint.x - startPoint.x, 2) + pow(farPoint.y - startPoint.y, 2));
												c = sqrt(pow(endPoint.x - farPoint.x, 2) + pow(endPoint.y - farPoint.y, 2));
												s = (a + b + c) / 2;
												ar = sqrt(s * (s - a) * (s - b) * (s - c));

												d = (2 * ar) / a;
												angle = acos((pow(b, 2) + pow(c, 2) - pow(a, 2)) / (2 * b * c)) * 57;


												if (angle <= 90 && d > 10)
												{
													if(num2==0)
													{
													l = l + 1;
													}
													if (num2 == 1)
													{
														num1 = num1 + 1;
													}
													circle(frame_copy, farPoint, 3, Scalar(255, 0, 0), -1);
												}

												if (i == 1)
												{
													//label10->Text = p_start.ToString();
													//label9->Text = p_end.ToString();
												}

												defectPoint[i].push_back(contours[i][p_far]);
												circle(frame_copy, contours[i][p_end], 3, Scalar(0, 255, 0), 2); //i ydi
											}

										}



										//putText(frame_copy, a, cv::Point(75, 450), FONT_HERSHEY_SIMPLEX, 3, Scalar(0, 255, 0), 3, 8, false);

										//drawContours(frame_copy, contours, i, Scalar(255, 255, 0), 2, 8, vector<Vec4i>(), 0, cv::Point());
										//drawContours(frame_copy, hullPoint, i, Scalar(255, 255, 0), 1, 8, vector<Vec4i>(), 0, cv::Point());
										drawContours(frame_copy, hullPoint, i, Scalar(0, 0, 255), 2, 8, vector<Vec4i>(), 0, cv::Point());
										approxPolyDP(contours[i], contours_poly[i], 3, false);
										boundRect[i] = boundingRect(contours_poly[i]);
										rectangle(frame_copy, boundRect[i].tl(), boundRect[i].br(), Scalar(255, 0, 0), 2, 8, 0);
										minRect[i].points(rect_point);
										for (size_t k = 0; k < 4; k++) {
											line(frame_copy, rect_point[k], rect_point[(k + 1) % 4], Scalar(0, 255, 0), 2, 8);
										}
										//int heightrect = boundRect[i].tl().y - boundRect[i].br().y;
										//int widthrect = boundRect[i].br().x - boundRect[i].tl().x;
										//float ratio = heightrect / widthrect;

										double hullarea = contourArea(hullPoint[i]);
										double cntarea = contourArea(contours[i]);

										double arearatio = hullarea / cntarea;

										//label23->Text = hullarea.ToString();
										//label24->Text = arearatio.ToString();
										

										//x_movestats->Text = widthrect.ToString();
										//y_movestats->Text = heightrect.ToString();
										//z_movestats->Text = ratio.ToString();
										if (startcntr == true)
										{
											cntr++;
											//y_movestats->Text = "counter running";
										}
										else
										{
											//y_movestats->Text = "counter stopped";
										}
										if (cntr == 10)
										{
											cntr = 0;
											startcntr = false;

										}
										if (l != num1)
										{
											startcntr = true;
											cntr = 0;
	
										}
										else
										{
											//x_movestats->Text = "Not changing";
										}
										if (startcntr == false)
										{

											if (num2 == 0)
											{
												if (l == 0 && abs(arearatio) >= 1.15)
												{
													outext->Text = "1";
													sim_1->Checked = true;
												}
												else if (l == 0 && abs(arearatio) < 1.15)
												{
													outext->Text = "0";
													sim_0->Checked = true;
												}
												else if (l == 1)
												{
													outext->Text = "2";//strcpy_s(a, "1");
													sim_2->Checked = true;
												}
												else if (l == 2)
												{
													outext->Text = "3";
													sim_3->Checked = true;
												}
												else if (l == 3)
												{
													outext->Text = "4";
													sim_4->Checked = true;
												}
												else if (l == 4)
												{
													outext->Text = "5";
													sim_5->Checked = true;
												}
												else if (l == 5 || l == 6)
												{
													outext->Text = "6";
												}
												else if (l > 6)
												{
													outext->Text = "unrecognized";
												}
											}
											else if (num2 == 1)
											{
												if (num1 == 0 && abs(arearatio) >= 1.15)
												{
													outext->Text = "1";
													sim_1->Checked = true;
												}
												else if (num1 == 0 && abs(arearatio) < 1.15)
												{
													outext->Text = "0";
													sim_0->Checked = true;
												}
												else if (num1 == 1)
												{
													outext->Text = "2";//strcpy_s(a, "1");
													sim_2->Checked = true;
												}
												else if (num1 == 2)
												{
													outext->Text = "3";
													sim_3->Checked = true;
												}
												else if (num1 == 3)
												{
													outext->Text = "4";
													sim_4->Checked = true;
												}
												else if (num1 == 4)
												{
													outext->Text = "5";
													sim_5->Checked = true;
												}
												else if (num1 == 5 || num1 == 6)
												{
													outext->Text = "6";
												}
												else if (num1 > 6)
												{
													outext->Text = "unrecognized";
												}
											}
										}
										else
										{
											outext->Text = "buffer";
											sim_none->Checked = true;
										}
										if (num2 == 0)
										{
											num2 = 1;
										}
										else if (num2 == 1)
										{
											num2 = 0;
										}
										
									}
								}
								else {
									outext->Text = "None";
									frame_copy = black.clone();
									sim_none->Checked = true;
								}

							}
					

						}
						catch (exception ex)
						{
						}


						//imshow("wtav", cizim);
						try {
							imshow("wtv", frame_copy);
						}
						catch(exception ex)
						{}
						//frame_copy = black.clone();
						//imshow("wtsdv", canvas);


					}
				}
			}
			imshow("ROI", segmented);

			waitKey(1);
			imshow("show", copyimage1);


		}
		if (camloop==false)
		{
			destroyWindow("ROI");
			destroyWindow("show");
		}
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		camloop = false;
		//cam2loop = true;
	}
	private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
		   bool con_stat=false;

	   private: System::Void BT_Connect_Click(System::Object^ sender, System::EventArgs^ e) {
			
		   con_stat = true;

		   System::String^ IP = target_IP->Text;
		   System::String^ SPort = Target_PORT->Text;
		   int Port = System::Convert::ToInt16(SPort);
		   status = WSAStartup(MAKEWORD(1, 1), &Datas);
		   if (status != 0)
			   Conn_stat->Text = "WSAstartup ERR!!";
		   memset(&destSockAddr, 0, sizeof(destSockAddr));
		   const char* chars = (const char*)(Runtime::InteropServices::Marshal::StringToHGlobalAnsi(IP)).ToPointer();
		   strcpy(dst_ip_address, chars);
		   //strcpy(dst_ip_address, "192.168.0.25");
		   destAddr = inet_addr(dst_ip_address);
		   memcpy(&destSockAddr.sin_addr, &destAddr, sizeof(destAddr));
		   destSockAddr.sin_port = htons(Port);
		   //port = 10000;// eddy Port;
		   //destSockAddr.sin_port = htons(port);
		   destSockAddr.sin_family = AF_INET;
		   // Socket creation
		   destSocket = socket(AF_INET, SOCK_DGRAM, 0);
		   if (destSocket == INVALID_SOCKET) {
			   Conn_stat->Text = "socket ERR!!";
			   status = WSACleanup();
			   if (status == SOCKET_ERROR)
				   Conn_stat->Text = "Cleanup ERR!!";
		   }

		   //first time init connection
		   Target_PORT->Text = System::Convert::ToString(Port);
		   memset(&MXTsend, 0, sizeof(MXTsend));
		   memset(&jnt_now, 0, sizeof(JOINT));
		   memset(&pos_now, 0, sizeof(POSE));
		   memset(&pls_now, 0, sizeof(PULSE));
		   //memset(&MXTsend, 0, sizeof(MXTsend));
		   memset(&MXTrecv, 0, sizeof(MXTrecv)); //initilize all para to 0


		   MXTsend.Command = MXT_CMD_NULL;
		   MXTsend.SendType = MXT_TYP_NULL;
		   MXTsend.RecvType = 7;  //in POSE mode
		   MXTsend.SendIOType = MXT_IO_NULL;
		   MXTsend.RecvIOType = MXT_IO_IN; // eddy IOSendType;
		   MXTsend.CCount = counter = 0;
		   remarks_text->Text = "Program connected";
		   remarks_text->BackColor = SystemColors::Window;
		   remarks_text->ForeColor = SystemColors::WindowText;
		   Conn_stat->Text = "Connected!!";

		   memset(sendText, 0, MAXBUFLEN);
		   memcpy(sendText, &MXTsend, sizeof(MXTsend));
		   numsnt = sendto(destSocket, sendText, sizeof(MXTCMD), NO_FLAGS_SET, (LPSOCKADDR)&destSockAddr, sizeof(destSockAddr));
		   if (numsnt != sizeof(MXTCMD)) {
			   Conn_stat->Text = "Send ERR!!";
			   status = closesocket(destSocket);
			   if (status == SOCKET_ERROR)
				   Conn_stat->Text = "close socket ERR!!";
			   status = WSACleanup();
			   if (status == SOCKET_ERROR)
				   Conn_stat->Text = "Clenup ERR!!";
		   }


		   memset(recvText, 0, MAXBUFLEN);
		   retry = 1; // No. of reception retries
		   while (retry)
		   {
			   FD_ZERO(&SockSet); // SockSet initialization
			   FD_SET(destSocket, &SockSet); // Socket registration
			   sTimeOut.tv_sec = 1; // Transmission timeout setting (sec)
			   sTimeOut.tv_usec = 0; // (micro sec)
			   status = select(0, &SockSet, (fd_set*)NULL, (fd_set*)NULL, &sTimeOut);
			   if (status == SOCKET_ERROR) {
				   //return(1);
			   }
			   if ((status > 0) && (FD_ISSET(destSocket, &SockSet) != 0)) { // If it receives by the time-out
				   numrcv = recvfrom(destSocket, recvText, MAXBUFLEN, NO_FLAGS_SET, NULL, NULL);
				   if (numrcv == SOCKET_ERROR) {
					   Conn_stat->Text = "rcv ERR!!";
					   status = closesocket(destSocket);
					   if (status == SOCKET_ERROR)
						   Conn_stat->Text = "close socket ERR!!";
					   status = WSACleanup();
					   if (status == SOCKET_ERROR)
						   Conn_stat->Text = "Clenup ERR!!";
					   //return(1);
				   }
				   memcpy(&MXTrecv, recvText, sizeof(MXTrecv));

				   char str[10];
				   if (MXTrecv.SendIOType == MXT_IO_IN) sprintf(str, "IN%04x", MXTrecv.IoData);
				   else if (MXTrecv.SendIOType == MXT_IO_OUT) sprintf(str, "OT%04x", MXTrecv.IoData);
				   else sprintf(str, "------");

				   int DispType;
				   void* DispData = NULL;
				   switch (disp_data)
				   {
				   case 0:
					   DispType = MXTrecv.RecvType;
					   DispData = &MXTrecv.dat;
					   break;
				   case 1:
					   DispType = MXTrecv.RecvType1;
					   DispData = &MXTrecv.dat1;
					   break;
				   case 2:
					   DispType = MXTrecv.RecvType2;
					   DispData = &MXTrecv.dat2;
					   break;
				   case 3:
					   DispType = MXTrecv.RecvType3;
					   DispData = &MXTrecv.dat3;
					   break;
				   default:
					   break;
				   }
				   switch (DispType) {
				   case MXT_TYP_JOINT:
				   case MXT_TYP_FJOINT:
				   case MXT_TYP_FB_JOINT:
					   if (loop == 1) {
						   memcpy(&jnt_now, DispData, sizeof(JOINT));
						   loop = 2;
					   }
					   if (disp) {
						   JOINT* j = (JOINT*)DispData;
						   sprintf(buf, "Receive (%ld): TCount=%d Type(JOINT) = %d\n %7.2f, %7.2f, %7.2f, %7.2f, %7.2f, %7.2f, %7.2f, %7.2f (%s)"
							   , MXTrecv.CCount, MXTrecv.TCount, DispType
							   , j->j1, j->j2, j->j3, j->j4, j->j5, j->j6, j->j7, j->j8, str);
						   //cout << buf << endl;
					   }
					   break;
				   case MXT_TYP_POSE:
				   case MXT_TYP_FPOSE:
				   case MXT_TYP_FB_POSE:
					   if (loop == 1) {
						   memcpy(&pos_now, &MXTrecv.dat.pos, sizeof(POSE));
						   POSE* p = (POSE*)DispData;
						   Pos_x->Text = System::Convert::ToString(p->w.x);
						   Pos_y->Text = System::Convert::ToString(p->w.y);
						   Pos_z->Text = System::Convert::ToString(p->w.z);
						   Pos_A->Text = System::Convert::ToString(p->w.a);
						   Pos_B->Text = System::Convert::ToString(p->w.b);
						   Pos_C->Text = System::Convert::ToString(p->w.c);
						   loop = 2;
					   }
					   if (disp) {
						   POSE* p = (POSE*)DispData;
						   sprintf(buf, "Receive (%ld): TCount=%d Type(POSE) = %d\n %7.2f, %7.2f, %7.2f, %7.2f, %7.2f, %7.2f, % 04x, % 04x(%s)"
							   , MXTrecv.CCount, MXTrecv.TCount, DispType
							   , p->w.x, p->w.y, p->w.z, p->w.a, p->w.b, p->w.c, p->sflg1, p->sflg2, str);
					   }
					   break;
				   case MXT_TYP_PULSE:
				   case MXT_TYP_FPULSE:
				   case MXT_TYP_FB_PULSE:
				   case MXT_TYP_CMDCUR:
				   case MXT_TYP_FBKCUR:
					   if (loop == 1) {
						   memcpy(&pls_now, &MXTrecv.dat.pls, sizeof(PULSE));
						   loop = 2;
					   }
					   if (disp) {
						   PULSE* l = (PULSE*)DispData;
						   sprintf(buf, "Receive (%ld): TCount=%d Type(PULSE / OTHER) = %d\n %ld, %ld, %ld, %ld, %ld, %ld, %ld, %ld(%s)"
							   , MXTrecv.CCount, MXTrecv.TCount, DispType
							   , l->p1, l->p2, l->p3, l->p4, l->p5, l->p6, l->p7, l->p8, str);
						   //cout << buf << endl;
					   }
					   break;
				   case MXT_TYP_NULL:
					   if (loop == 1) {
						   loop = 2;
					   }
					   if (disp) {
						   sprintf(buf, "Receive (%ld): TCount=%d Type(NULL)=%d\n (%s)"
							   , MXTrecv.CCount, MXTrecv.TCount, DispType, str);
					   }
					   break;
				   default:
					   Conn_stat->Text = "bad data";
					   break;
				   }
				   counter++; // Count up only when communication is successful
				   retry = 0; // Leave reception loop
			   }
			   else { // Reception timeout
				   remarks_text->Text = "Program not connected";
				   remarks_text->BackColor = Color::Red;
				   remarks_text->ForeColor = Color::White;
				   Conn_stat->Text = "rcv timeout";
				   retry--; // No. of retries subtraction
				   if (retry == 0) loop = 0; // End program if No. of retries is 0
			   }
		   }

		   BT_Disconnect->Enabled = TRUE;
		   BT_Connect->Enabled = FALSE;
		   connect_stat = TRUE;
	   }

	   private: System::Void BT_Disconnect_Click(System::Object^ sender, System::EventArgs^ e) {
		   
		   con_stat = false;

		   memset(&MXTsend, 0, sizeof(MXTsend));
		   MXTsend.Command = MXT_CMD_END;
		   loop = 0;
		   memcpy(sendText, &MXTsend, sizeof(MXTsend));
		   numsnt = sendto(destSocket, sendText, sizeof(MXTCMD), NO_FLAGS_SET, (LPSOCKADDR)&destSockAddr,
			   sizeof(destSockAddr));
		   status = closesocket(destSocket);
		   if (status == SOCKET_ERROR)
			   Conn_stat->Text = "ERROR: closesocket unsuccessful";
		   status = WSACleanup();
		   if (status == SOCKET_ERROR)
			   Conn_stat->Text = "ERROR: WSACleanup unsuccessful";
		   Conn_stat->Text = "Disconnected!!";
		   BT_Connect->Enabled = TRUE;
	   }

			  int x_ind = 0;
			  float x_odd =0,x_even=0, x_comp = 0;
			  bool x_moving = false;

			  int sv_coord = 0;

			  float total_comp = 0;
			  float y_odd = 0, y_even = 0, y_comp = 0;
			  float z_odd = 0, z_even = 0, z_comp = 0;
			  float a_odd = 0, a_even = 0, a_comp = 0;
			  float b_odd = 0, b_even = 0, b_comp = 0;
			  float c_odd = 0, c_even = 0, c_comp = 0;

			  System::String^ posy;
			  System::String^ posx;
			  System::String^ posz;

			  float res1 = 0.25, res2 = 0.5, res3 = 0.75, res4 = 1.0;
			  float res_stat = 0.0;

			  int rec_pl = 0; //0:not recording, 1:recording, 2:stop recording, 3:playback, 4: stop playback

			  int opt_stat = 0, menu_disp = 0;

			  int printext = 0;
			  float diffx = 0;
			  int k = 0;

			  bool grip = true;

			  bool opt_change=false;

			  void strip(std::string& str)
			  {
				  if (str.length() == 0) {
					  return;
				  }

				  auto start_it = str.begin();
				  auto end_it = str.rbegin();
				  while (std::isspace(*start_it)) {
					  ++start_it;
					  if (start_it == str.end()) break;
				  }
				  while (std::isspace(*end_it)) {
					  ++end_it;
					  if (end_it == str.rend()) break;
				  }
				  int start_pos = start_it - str.begin();
				  int end_pos = end_it.base() - str.begin();
				  str = start_pos <= end_pos ? std::string(start_it, end_it.base()) : "";
			  }

			  int stoi = 7;

	private: System::Void pos_polling_Tick(System::Object^ sender, System::EventArgs^ e) {

		msclr::interop::marshal_context context;
		std::string standardString = context.marshal_as<std::string>(text);


		switch (exstats)
		{
		case 0:
			textBox2->Text = "Not connected";
			textBox2->BackColor=SystemColors::Window;
			break;
		case 1:
			textBox2->Text = "Connected";
			textBox2->BackColor = Color::Lime;

			try
			{
				strip(standardString);
				stoi = std::stoi(standardString);

				if (num2 == 0)
				{
					l = stoi;
				}
				else if (num2 == 1)
				{
					num1 = stoi;
				}

				if (startcntr == true)
				{
					cntr++;
					//y_movestats->Text = "counter running";
				}
				else
				{
					//y_movestats->Text = "counter stopped";
				}
				if (cntr == 3)
				{
					cntr = 0;
					startcntr = false;

				}
				if (l != num1)
				{
					startcntr = true;
					cntr = 0;

				}
				else
				{
					//x_movestats->Text = "Not changing";
				}
				if (startcntr == false)
				{

					if (num2 == 0)
					{
						if (stoi == 0)
						{
							sim_0->Checked = true;
						}
						else if (stoi == 1)
						{
							sim_1->Checked = true;
						}
						else if (stoi == 2)
						{
							sim_2->Checked = true;
						}
						else if (stoi == 3)
						{
							sim_3->Checked = true;
						}
						else if (stoi == 4)
						{
							sim_4->Checked = true;
						}
						else if (stoi == 5)
						{
							sim_5->Checked = true;
						}
						else if (stoi == 7)
						{
							sim_none->Checked = true;
						}
						else
						{
							sim_none->Checked = true;
						}
					}
				}
				else
				{
					outext->Text = "buffer";
					sim_none->Checked = true;
				}
				if (num2 == 0)
				{
					num2 = 1;
				}
				else if (num2 == 1)
				{
					num2 = 0;
				}
			}
			catch (exception ex)
			{
			}
			break;
		case 2:
			textBox2->Text = "Connecting";
			textBox2->BackColor = Color::Aquamarine;
			break;
		case 3:
			textBox2->Text = "Connection lost";
			textBox2->BackColor = Color::Red;
			break;
		}

		label23->Text = text;
#pragma region textboxes display
		
		switch(menu_disp) {
		case 0:
			if (opt_change) {
				text_zero->Text = "Change gesture/Remove hand";
			}
			else {
				text_zero->Text = "Gest. 0: Stop";
			}
			text_one->Text = "Gest. 1: Move positive x axis";
			text_two->Text = "Gest. 2: Move negative x axis";
			text_three->Text = "Gest. 3: Move positive y axis";
			text_four->Text = "Gest. 4: Move negative y axis";
			text_five->Text = "Gest. 5: Option menu";
			break;
		case 1:
			text_zero->Text = "Gest. 0: Stop";
			if (opt_change) {
				text_one->Text = "Change gesture/Remove hand";
			}
			else {
				text_one->Text = "Gest. 1: Move positive z axis";
			}
			text_two->Text = "Gest. 2: Move negative z axis";
			text_three->Text = "Gest. 3: Rotations (c,b)";
			text_four->Text = "Gest. 4: Rotations (a)";
			text_five->Text = "Gest. 5: Option menu";
			break;
		case 2:

			text_zero->Text = "Gest. 0: 0.5";
			text_one->Text = "Gest. 1: 2.0";
			if (opt_change) {
				text_two->Text = "Change gesture/Remove hand";
			}
			else {
				text_two->Text = "Gest. 2: 3.5";
			}
			text_three->Text = "Gest. 3: 4.0";
			text_four->Text = "Gest. 4: 4.5";
			text_five->Text = "Gest. 5: Option menu";
			break;
		case 3:
			text_zero->Text = "Gest. 0: Playback";
			text_one->Text = "Gest. 1: null";
			text_two->Text = "Gest. 2: Pause";
			if (opt_change) {
				text_three->Text = "Change gesture/Remove hand";
			}
			else {
				text_three->Text = "Gest. 2: null";
			}
			text_four->Text = "Gest. 4: Stop";
			text_five->Text = "Gest. 5: Option menu";
			break;
		case 4:
			text_zero->Text = "Gest. 0: Robot movement 1 (x, y)";
			text_one->Text = "Gest. 1: Robot movement 2 (z, Rot)";
			text_two->Text = "Gest. 2: Resolution changes";
			text_three->Text = "Gest. 3: Playback functions";
			text_four->Text = "Gest. 4: Record function";
			text_five->Text = "Gest. 5: Option menu";
			break;
		case 5:
			text_zero->Text = "Gest. 0: Pause Recording";
			text_one->Text = "Gest. 1: Save Coordinate";
			text_two->Text = "Gest. 2: Start Recording";
			text_three->Text = "Gest. 3: Buffer";
			if (opt_change) {
				text_four->Text = "Change gesture/Remove hand";
			}
			else {
				text_four->Text = "Gest. 4: Stop Recording";
			}
			text_five->Text = "Gest. 5: Option menu";
			break;
		case 7:
			text_zero->Text = "Gest. 0: Rotate c +ve";
			text_one->Text = "Gest. 1: Rotate c -ve";
			text_two->Text = "Gest. 2: Rotate b +ve";
			text_four->Text = "Gest. 4: Rotations a";
			if (opt_change) {
				text_three->Text = "Change gesture/Remove hand";
			}
			else {
				text_three->Text = "Gest. 3: Rotate b -ve";
			}
			text_five->Text = "Gest. 5: Option menu";
			break;
		case 8:
			text_zero->Text = "Gest. 0: Rotate a +ve";
			text_one->Text = "Gest. 1: Rotate a -ve";
			text_two->Text = "Gest. 2: empty slot";
			text_three->Text = "Gest. 3: empty slot";
			if (opt_change) {
				text_four->Text = "Change gesture/Remove hand";
			}
			else {
				text_four->Text = "Gest. 4: empty slot";
			}
			text_five->Text = "Gest. 5: Option menu";
			break;
		default:
			remarks_text->Text = "Program Error";
		}
		
		text_res->Text = res_stat.ToString();
		//switch()
		if (!con_stat)
		{
			remarks_text->Text = "Program not connected";
			remarks_text->BackColor = Color::Red;
			remarks_text->ForeColor = Color::White;
		}

#pragma endregion

		bool none = sim_none->Checked;
		bool gzero = sim_0->Checked;
		bool gone = sim_1->Checked;
		bool gtwo = sim_2->Checked;
		bool gthree = sim_3->Checked;
		bool gfour = sim_4->Checked;
		bool gfive = sim_5->Checked;

		if (sim_bool)
		{
			if (none)
			{
				opt_stat = 0;
				text_zero->BackColor = SystemColors::Window;
				text_one->BackColor = SystemColors::Window;
				text_two->BackColor = SystemColors::Window;
				text_three->BackColor = SystemColors::Window;
				text_four->BackColor = SystemColors::Window;
				text_five->BackColor = SystemColors::Window;

				opt_change = false;

			}
			else if (gzero)
			{
				opt_stat = 6;
				text_zero->BackColor = Color::Lime;
				text_one->BackColor = SystemColors::Window;
				text_two->BackColor = SystemColors::Window;
				text_three->BackColor = SystemColors::Window;
				text_four->BackColor = SystemColors::Window;
				text_five->BackColor = SystemColors::Window;
			}
			else if (gone)
			{
				opt_stat = 1;
				text_one->BackColor = Color::Lime;
				text_zero->BackColor = SystemColors::Window;
				text_two->BackColor = SystemColors::Window;
				text_three->BackColor = SystemColors::Window;
				text_four->BackColor = SystemColors::Window;
				text_five->BackColor = SystemColors::Window;
			}
			else if (gtwo)
			{
				opt_stat = 2;
				text_two->BackColor = Color::Lime;
				text_one->BackColor = SystemColors::Window;
				text_zero->BackColor = SystemColors::Window;
				text_three->BackColor = SystemColors::Window;
				text_four->BackColor = SystemColors::Window;
				text_five->BackColor = SystemColors::Window;
			}
			else if (gthree)
			{
				opt_stat = 3;
				text_three->BackColor = Color::Lime;
				text_one->BackColor = SystemColors::Window;
				text_two->BackColor = SystemColors::Window;
				text_zero->BackColor = SystemColors::Window;
				text_four->BackColor = SystemColors::Window;
				text_five->BackColor = SystemColors::Window;
			}
			else if (gfour)
			{
				opt_stat = 4;
				text_four->BackColor = Color::Lime;
				text_one->BackColor = SystemColors::Window;
				text_two->BackColor = SystemColors::Window;
				text_three->BackColor = SystemColors::Window;
				text_zero->BackColor = SystemColors::Window;
				text_five->BackColor = SystemColors::Window;
			}
			else if (gfive)
			{
				opt_stat = 5;
				text_five->BackColor = Color::Lime;
				text_one->BackColor = SystemColors::Window;
				text_two->BackColor = SystemColors::Window;
				text_three->BackColor = SystemColors::Window;
				text_four->BackColor = SystemColors::Window;
				text_zero->BackColor = SystemColors::Window;
			}

			if (gfive) 
			{
				menu_disp = 4;
			}

			if (menu_disp == 4)
			{
				opt_change = true;
				if (gzero)
				{
					menu_disp = 0;
				}
				else if (gone)
				{
					menu_disp = 1;
				}
				else if (gtwo)
				{
					menu_disp = 2;
				}
				else if (gthree)
				{
					menu_disp = 3;
				}
				else if (gfour)
				{
					menu_disp = 5;
					sv_coord = 0;
				}
			}

		}

		if (radioButton1->Checked == true)
		{
			res_stat = res1;
		}
		else if (radioButton2->Checked == true)
		{
			res_stat = res2;
		}
		else if (radioButton3->Checked == true)
		{
			res_stat = res3;
		}
		else if (radioButton4->Checked == true)
		{
			res_stat = res4;
		}

		if (sim_bool) {

			if (menu_disp == 0) {
				if (sim_none->Checked == true) {
					rob_move->Text = "No movement";
				}
				if (opt_change&&gzero) {
					rob_move->Text = "Change";
				}
				if (!opt_change && gzero) {
					rob_move->Text = "Stop";
				}

				if (gone) {
					rob_move->Text = "Positive x-axis";
					delta += (float)res_stat;
					opt_change = false;
				}
				if (gtwo) {
					rob_move->Text = "Negative x-axis";
					delta -= (float)res_stat;
					opt_change = false;
				}
				if (gthree) {
					rob_move->Text = "Positive y-axis";
					delta2 += (float)res_stat;
					opt_change = false;
				}
				if (gfour) {
					rob_move->Text = "Negative y-axis";
					delta2 -= (float)res_stat;
					opt_change = false;
				}
				if (gfive) {
					rob_move->Text = "Other";
				}
			}

			if (menu_disp == 1) 
			{
				if (sim_none->Checked == true) {
					rob_move->Text = "No movement";
				}

				if (gzero) {
					rob_move->Text = "Stop";
					opt_change = false;
				}
				if (opt_change && gone) {
					rob_move->Text = "Change";
				}
				if (!opt_change && gone) {
					rob_move->Text = "Positive z-axis";
					delta3 += (float)res_stat;
				}

				if (gtwo) {
					rob_move->Text = "Negative z-axis";
					delta3 -= (float)res_stat;
					opt_change = false;
				}
				if (gthree) {
					rob_move->Text = "(ip resolution change)";
					menu_disp = 7;
					opt_change = true;
				}
				if (gfour) {
					rob_move->Text = "Negative y-axis";
					delta2 -= (float)res_stat;
					opt_change = false;
				}
				if (gfive) {
					rob_move->Text = "Other";
				}
			}
			if (menu_disp == 2)
			{
				if (sim_none->Checked == true) {
					rob_move->Text = "No res changes";
				}

				if (gzero) {
					rob_move->Text = "0.25";
					res_stat = 0.25;
					radioButton1->Checked = true;
					opt_change = false;
				}

				if (gone) {
					rob_move->Text = "0.5";
					res_stat = 0.5;
					radioButton2->Checked = true;
					opt_change = false;
				}
				if (opt_change && gtwo) {
					rob_move->Text = "Change";
				}
				if (!opt_change && gtwo) {
					rob_move->Text = "0.75";
					radioButton3->Checked = true;
					res_stat = 0.75;
				}

				if (gthree) {
					rob_move->Text = "1.0";
					res_stat = 1.0;
					radioButton4->Checked = true;
					opt_change = false;
				}
				if (gfour) {
					rob_move->Text = "1.0";
					//res_stat = 4.5;
					opt_change = false;
				}
				if (gfive) {
					rob_move->Text = "Other";
				}
			}
			if (menu_disp == 3)
			{
				if (sim_none->Checked == true) {
					rob_move->Text = "Nothing";
					opt_change = false;
				}

				if (gzero) {
					rob_move->Text = "Playback";
					playback_bool = true;
					opt_change = false;
					if (printext == 0)
					{
						k = 0;
						printext = 1;
					}
				}

				if (gone) {
					rob_move->Text = "null";
					opt_change = false;
				}
				if (opt_change && gthree) {
					rob_move->Text = "Change";
				}
				if (!opt_change && gthree) {
					rob_move->Text = "null";
				}

				if (gtwo) {
					rob_move->Text = "Pause";
					opt_change = false;
				}
				if (gfour) {
					rob_move->Text = "Stop";
					opt_change = false;
				}
				if (gfive) {
					rob_move->Text = "Other";
				}
			}
			if (menu_disp == 5)
			{
				if (sim_none->Checked == true) {
					rob_move->Text = "Not recording";
				}

				if (gzero) {
					rob_move->Text = "Pause";
					//record_stat = false;
					opt_change = false;
				}

				if (gone) {
					if (sv_coord == 0)
					{
						text_one->Text = "Save coordinate";
						sv_coord = 1;
					}
					else if (sv_coord == 2)
					{
						text_one->Text = "Coordinate saved";
					}
					opt_change = false;
				}

				if (gtwo) {
					rob_move->Text = "Start";
					record_stat = true;
					opt_change = false;
					rec_pl = 1;
				}

				if (gthree) {
					rob_move->Text = "Buffer";
					opt_change = false;
					sv_coord = 0;
				}

				if (opt_change && gfour) {
					rob_move->Text = "Change";
				}
				if (!opt_change && gfour) {
					rob_move->Text = "Stop";
					//record_stat = true;
					rec_pl = 2;
				}
				if (gfive) {
					rob_move->Text = "Other";
				}
			}
			if (menu_disp == 7)
			{
				if (sim_none->Checked == true) {
					rob_move->Text = "Not recording";
				}

				if (gzero) {
					rob_move->Text = "c +ve";
					gamma += (float)0.25*aratio;
					opt_change = false;
				}

				if (gone) {
					rob_move->Text = "c -ve";
					gamma -= (float)0.25 * aratio;
					opt_change = false;
				}

				if (gtwo) {
					rob_move->Text = "b +ve";
					beta += (float)0.25 * aratio;
					opt_change = false;
				}

				if (gfour) {
					opt_change = true;
					menu_disp = 8;
				}

				if (opt_change && gthree) {
					rob_move->Text = "Change";
				}
				if (!opt_change && gthree) {
					rob_move->Text = "b -ve";
					beta -= (float)0.25 * aratio;
				}
				if (gfive) {
					rob_move->Text = "Other";
				}
			}
			if (menu_disp == 8)
			{
				if (sim_none->Checked == true) {
					opt_change = false;
				}

				if (gzero) {
					rob_move->Text = "a +ve";
					alpha += (float)0.25 * aratio;
					opt_change = false;
				}

				if (gone) {
					rob_move->Text = "a -ve";
					alpha -= (float)0.25 * aratio;
					opt_change = false;
				}

				if (gtwo) {
					rob_move->Text = "a -ve";
					opt_change = false;
				}

				if (gthree) {
					rob_move->Text = "Buffer";
					opt_change = false;
				}

				if (opt_change && gfour) {
					rob_move->Text = "Change";
				}
				if (!opt_change && gfour) {
					rob_move->Text = "Stop";
				}
				if (gfive) {
					rob_move->Text = "Other";
				}
			}
		}


			if (connect_stat) {

				memset(&MXTsend, 0, sizeof(MXTsend));
				memset(&MXTrecv, 0, sizeof(MXTrecv));
				MXTsend.Command = MXT_CMD_MOVE;
				MXTsend.SendType = 1;
				MXTsend.RecvType = 7;
				MXTsend.RecvType1 = 0;
				MXTsend.RecvType2 = 0;
				MXTsend.RecvType3 = 0;
				type = 1;
				int test = 0;
				if (test == 0) {
					switch (type) {
					case MXT_TYP_JOINT:
						memcpy(&MXTsend.dat.jnt, &jnt_now, sizeof(JOINT));
						MXTsend.dat.jnt.j1 += (float)(delta * 3.141592 / 180.0);
						//test = 1;
						break;
					case MXT_TYP_POSE:
						memcpy(&MXTsend.dat.pos, &pos_now, sizeof(POSE));
						if (execute)
						{
							if (execloop < linecount && linecount != 0)
							{
								delta = x[execloop] - MXTsend.dat.pos.w.x;
								delta2 = y[execloop] - MXTsend.dat.pos.w.y;
								delta3 = z[execloop] - MXTsend.dat.pos.w.z;
								execloop++;
							}
							else
							{
								execloop = 0;
								execute = false;
							}
						}

						//MXTsend.dat.pos.w.x += (delta * nratio);

						if (!playback_bool) {


							//delta_text->Text = pdeltax.ToString();
							
							pdeltax += 0.15 * (delta - pdeltax);
							MXTsend.dat.pos.w.x += (pdeltax);

							if (x_ind == 0)
							{
								x_odd = MXTsend.dat.pos.w.x;
								y_odd = MXTsend.dat.pos.w.y;
								z_odd = MXTsend.dat.pos.w.z;
								a_odd = MXTsend.dat.pos.w.a;
								b_odd = MXTsend.dat.pos.w.b;
								c_odd = MXTsend.dat.pos.w.c;
								
								x_ind = 1;
							}
							else if (x_ind == 1)
							{
								x_even = MXTsend.dat.pos.w.x;
								y_even = MXTsend.dat.pos.w.y;
								z_even = MXTsend.dat.pos.w.z;
								a_even = MXTsend.dat.pos.w.a;
								b_even = MXTsend.dat.pos.w.b;
								c_even = MXTsend.dat.pos.w.c;
								
								x_ind = 0;
							}


							x_comp = x_even - x_odd;
							y_comp = y_even - y_odd;
							z_comp = z_even - z_odd;
							a_comp = a_even - a_odd;
							b_comp = b_even - b_odd;
							c_comp = c_even - c_odd;
							
							total_comp = abs(x_comp + y_comp + z_comp + a_comp + b_comp + c_comp);

							\

							pdeltay += 0.15 * (delta2 - pdeltay);
							MXTsend.dat.pos.w.y += pdeltay;

							pdeltaz += 0.15 * (delta3 - pdeltaz);
							MXTsend.dat.pos.w.z += pdeltaz;

							MXTsend.dat.pos.w.c += gamma;
							MXTsend.dat.pos.w.a += alpha;
							MXTsend.dat.pos.w.b += beta;
							//y_movestats->Text = sv_coord.ToString();

							if (record_stat&&rec_pl==1) {
								remarks_text->Text = "Recording";
								remarks_text->ForeColor = Color::Red;

								if (sv_coord == 1)
								{	
									/*
									float z_rec = MXTsend.dat.pos.w.z - 56.987;
									float a_rec = MXTsend.dat.pos.w.a - 182.826;
									float b_rec = MXTsend.dat.pos.w.b + 10.218;
									float c_rec = MXTsend.dat.pos.w.c + 174.255;
									*/
									float z_rec = float::Parse(Pos_z->Text);
									float a_rec = float::Parse(Pos_A->Text)*(180/3.141592);
									float b_rec = float::Parse(Pos_B->Text)*(180 / 3.141592);
									float c_rec = float::Parse(Pos_C->Text)*(180 / 3.141592);
									//sw->WriteLine("Position"+rec_count+"\t" + MXTsend.dat.pos.w.x + "\t" + MXTsend.dat.pos.w.y + "\t"+ z_rec+ "\t"+ a_rec+ "\t" + b_rec + "\t" + c_rec + "\t\t\t"+7+"\t" + 0);
									sw->WriteLine("Position" + rec_count + "\t" + float::Parse(Pos_x->Text) + "\t" + float::Parse(Pos_y->Text) + "\t" + z_rec + "\t" + a_rec + "\t" + b_rec + "\t" + c_rec + "\t\t\t" + 7 + "\t" + 0);

									rec_count++;
									sv_coord = 2;
								}

							}
							else if (record_stat && rec_pl == 2) {
								record_stat = false;
								sw->WriteLine("\nOvrd 10\nServo On");
								for (int j=0; j < rec_count; j++)
								{
									sw->WriteLine("Mov Position" + j);
								}
								sw->WriteLine("Servo Off");
								sw->Close();
								sim_status->Text = "Simulation Recorded";
							}
							else {
								remarks_text->Text = "Notrecording";
								remarks_text->ForeColor = SystemColors::WindowText;
							}
						}
						else {

							string name;
							float num1;

							if (printext == 1) {
								Datastream->Clear();
								//float xcor[100];
								ifstream myfile("recorded_file2.txt");
								if (myfile.is_open())
								{
									int lop = 0;
									while (!myfile.eof())
									{
										getline(myfile, name, '\n');
										stringstream(name) >> num1;
										xcor[lop] = num1;
										lop++; 
									}
									keyp = (lop - 1) / 4;



									myfile.close();
								}

								for (int i = 0, j = 1; i < keyp; i++) {
									Datastream->AppendText("Coordinate x" + i.ToString() + ":" + xcor[j] + Environment::NewLine);
									//Datastream->AppendText("Current x" + i.ToString() + ":" + MXTsend.dat.pos.w.x + Environment::NewLine);
									Datastream->AppendText("Coordinate y" + i.ToString() + ":" + xcor[j + 1] + Environment::NewLine);
									Datastream->AppendText("Coordinate z" + i.ToString() + ":" + xcor[j + 2] + Environment::NewLine + Environment::NewLine);

									diffx = MXTsend.dat.pos.w.x - xcor[j];
									
									j += 4;
								}
								printext = 2;
							}

							//curx = Convert::ToFloat(Pos_x->Text);
							curx = float::Parse(Pos_x->Text);
							compx = curx - xcor[xcount];


							if (movx == 0)
							{
								if (compx < 0)
								{
									movx = 1;
								}
								if (compx > 0)
								{
									movx = 2;
								}
							}
							if (movx==1)
							{
								delta += 0.5;
								pdeltax += 0.15 * (delta - pdeltax);

								if (compx > 0)
								{
									delta += 0.5;
									pdeltax += 0.15 * (delta - pdeltax);
									xcount=xcount+4;
									//Sleep(1000);
									movx = 2;
								}
							}
							else if (movx==2)
							{
								delta -= 0.5;
								pdeltax += 0.15 * (delta - pdeltax);

								if (compx < 0)
								{
									delta += 0;
									pdeltax += 0.15 * (delta - pdeltax);
									xcount++;
									Sleep(1000);
									movx = 2;
								}
							}
							MXTsend.dat.pos.w.x += (pdeltax);
							

								if (xcount == keyp) 
								{
									xcount = 0;
								}

							



							//diffx = MXTsend.dat.pos.w.x - xcor[k];
								//if()
								//MXTsend.dat.pos.w.x += (pdeltax);
								//y_movestats->Text = MXTsend.dat.pos.w.x.ToString();
								
					
						}

						//x_movestats->Text = MXTsend.dat.pos.w.z.ToString();

						break;
					case MXT_TYP_PULSE:
						memcpy(&MXTsend.dat.pls, &pls_now, sizeof(PULSE));
						MXTsend.dat.pls.p1 += (long)(delta  * 10);
						break;
					default:
						break;
					}
				}
				MXTsend.SendIOType = IOSendType;
				MXTsend.RecvIOType = IORecvType;
				MXTsend.BitTop = IOBitTop;
				MXTsend.BitMask = IOBitMask;
				MXTsend.IoData = IOBitData;
				MXTsend.CCount = counter;

				memset(sendText, 0, MAXBUFLEN);
				memcpy(sendText, &MXTsend, sizeof(MXTsend));


				numsnt = sendto(destSocket, sendText, sizeof(MXTCMD), NO_FLAGS_SET, (LPSOCKADDR)&destSockAddr, sizeof(destSockAddr));
				if (numsnt != sizeof(MXTCMD)) {
					Conn_stat->Text = "Send failed!!";
					status = closesocket(destSocket);
					if (status == SOCKET_ERROR)
						Conn_stat->Text = "socket close failed!!";
					status = WSACleanup();
					if (status == SOCKET_ERROR)
						Conn_stat->Text = "WSA cleanup failed!!";
				}
				memset(recvText, 0, MAXBUFLEN);
				retry = 1; // No. of reception retries
				while (retry) {
					FD_ZERO(&SockSet); // SockSet initialization
					FD_SET(destSocket, &SockSet); // Socket registration
					sTimeOut.tv_sec = 1; // Transmission timeout setting (sec)
					sTimeOut.tv_usec = 0; // (micro sec)
					status = select(0, &SockSet, (fd_set*)NULL, (fd_set*)NULL, &sTimeOut);
					if (status == SOCKET_ERROR) {
						//return(1);
					}
					if ((status > 0) && (FD_ISSET(destSocket, &SockSet) != 0)) { // If it receives by the time-out
						numrcv = recvfrom(destSocket, recvText, MAXBUFLEN, NO_FLAGS_SET, NULL, NULL);
						if (numrcv == SOCKET_ERROR) {
							Conn_stat->Text = "rcv ERR!!";
							status = closesocket(destSocket);
							if (status == SOCKET_ERROR)
								Conn_stat->Text = "close socket ERR!!";
							status = WSACleanup();
							if (status == SOCKET_ERROR)
								Conn_stat->Text = "Clenup ERR!!";
							//return(1);
						}
						memcpy(&MXTrecv, recvText, sizeof(MXTrecv));
						char str[10];
						if (MXTrecv.SendIOType == MXT_IO_IN) sprintf(str, "IN%04x", MXTrecv.IoData);
						else if (MXTrecv.SendIOType == MXT_IO_OUT) sprintf(str, "OT%04x", MXTrecv.IoData);
						else sprintf(str, "------");
						int DispType;
						void* DispData = NULL;
						switch (disp_data) {
						case 0:
							DispType = MXTrecv.RecvType;
							DispData = &MXTrecv.dat;
							break;
						case 1:
							DispType = MXTrecv.RecvType1;
							DispData = &MXTrecv.dat1;
							break;
						case 2:
							DispType = MXTrecv.RecvType2;
							DispData = &MXTrecv.dat2;
							break;
						case 3:
							DispType = MXTrecv.RecvType3;
							DispData = &MXTrecv.dat3;
							break;
						default:
							break;
						}
						switch (DispType) {
						case MXT_TYP_JOINT:
						case MXT_TYP_FJOINT:
						case MXT_TYP_FB_JOINT:
							if (loop == 1) {
								memcpy(&jnt_now, DispData, sizeof(JOINT));
								loop = 2;
							}
							if (disp) {
								JOINT* j = (JOINT*)DispData;
								sprintf(buf, "Receive (%ld): TCount=%d Type(JOINT) = %d\n %7.2f, %7.2f, %7.2f, %7.2f, %7.2f, %7.2f, %7.2f, %7.2f (%s)"
									, MXTrecv.CCount, MXTrecv.TCount, DispType
									, j->j1, j->j2, j->j3, j->j4, j->j5, j->j6, j->j7, j->j8, str);
								//cout << buf << endl;
							}
							break;
						case MXT_TYP_POSE:
						case MXT_TYP_FPOSE:
						case MXT_TYP_FB_POSE:
						{
							POSE* p = (POSE*)DispData;
							Pos_x->Text = System::Convert::ToString(p->w.x);
							Pos_y->Text = System::Convert::ToString(p->w.y);
							Pos_z->Text = System::Convert::ToString(p->w.z);
							Pos_A->Text = System::Convert::ToString(p->w.a);
							Pos_B->Text = System::Convert::ToString(p->w.b);
							Pos_C->Text = System::Convert::ToString(p->w.c);
							loop = 2;
						}

						if (disp)
						{
							POSE* p = (POSE*)DispData;
							sprintf(buf, "Receive (%ld): TCount=%d Type(POSE) = %d\n %7.2f, %7.2f, %7.2f, %7.2f, %7.2f, %7.2f, % 04x, % 04x(%s)"
								, MXTrecv.CCount, MXTrecv.TCount, DispType
								, p->w.x, p->w.y, p->w.z, p->w.a, p->w.b, p->w.c, p->sflg1, p->sflg2, str);

							//cout << buf << endl;
						}
						break;
						case MXT_TYP_PULSE:
						case MXT_TYP_FPULSE:
						case MXT_TYP_FB_PULSE:
						case MXT_TYP_CMDCUR:
						case MXT_TYP_FBKCUR:
							if (loop == 1) {
								memcpy(&pls_now, &MXTrecv.dat.pls, sizeof(PULSE));
								loop = 2;
							}
							if (disp) {
								PULSE* l = (PULSE*)DispData;
								sprintf(buf, "Receive (%ld): TCount=%d Type(PULSE / OTHER) = %d\n %ld, %ld, %ld, %ld, %ld, %ld, %ld, %ld(%s)"
									, MXTrecv.CCount, MXTrecv.TCount, DispType
									, l->p1, l->p2, l->p3, l->p4, l->p5, l->p6, l->p7, l->p8, str);
								//cout << buf << endl;
							}
							break;
						case MXT_TYP_NULL:
							if (loop == 1) {
								loop = 2;
							}
							if (disp) {
								sprintf(buf, "Receive (%ld): TCount=%d Type(NULL)=%d\n (%s)"
									, MXTrecv.CCount, MXTrecv.TCount, DispType, str);
								//cout << buf << endl;
							}
							break;
						default:
							Conn_stat->Text = "bad data";
							break;
						}
						counter++; // Count up only when communication is successful
						retry = 0; // Leave reception loop
					}
					else { // Reception timeout
						Conn_stat->Text = "rcv timeout";
						retry--; // No. of retries subtraction
						if (retry == 0) loop = 0; // End program if No. of retries is 0
					}
				}
			}
		
	}

	private: System::Void y_plus_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!sim_bool) {
			if (radioButton1->Checked == true)
			{
				delta2 += (float)0.5;
			}
			else if (radioButton2->Checked == true)
			{
				delta2 += (float)2.0;
			}
			else if (radioButton3->Checked == true)
			{
				delta2 += (float)3.5;
			}
			else if (radioButton4->Checked == true)
			{
				delta2 += (float)4.0;
			}
		}
	}


	private: System::Void y_minus_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!sim_bool) {
			if (radioButton1->Checked == true)
			{
				delta2 -= (float)0.5;
			}
			else if (radioButton2->Checked == true)
			{
				delta2 -= (float)2.0;
			}
			else if (radioButton3->Checked == true)
			{
				delta2 -= (float)3.5;
			}
			else if (radioButton4->Checked == true)
			{
				delta2 -= (float)4.0;
			}
		}
	}

	private: System::Void z_plus_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!sim_bool) {
			if (radioButton1->Checked == true)
			{
				delta3 += (float)0.5;
			}
			else if (radioButton2->Checked == true)
			{
				delta3 += (float)2.0;
			}
			else if (radioButton3->Checked == true)
			{
				delta3 += (float)3.5;
			}
			else if (radioButton4->Checked == true)
			{
				delta3 += (float)4.0;
			}
		}
	}
	private: System::Void z_minus_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!sim_bool) {
			if (radioButton1->Checked == true)
			{
				delta3 -= (float)0.5;
			}
			else if (radioButton2->Checked == true)
			{
				delta3 -= (float)2.0;
			}
			else if (radioButton3->Checked == true)
			{
				delta3 -= (float)3.5;
			}
			else if (radioButton4->Checked == true)
			{
				delta3 -= (float)4.0;
			}
		}
	}

private: System::Void x_plus_Click(System::Object^ sender, System::EventArgs^ e) {

	if(!sim_bool){
		if (radioButton1->Checked == true)
		{
			delta += (float)0.5;
		}
		else if (radioButton2->Checked == true)
		{
			delta += (float)2.0;
		}
		else if (radioButton3->Checked == true)
		{
			delta += (float)3.5;
		}
		else if (radioButton4->Checked == true)
		{
			delta += (float)4.0;
		}
	}
}
private: System::Void x_minus_Click(System::Object^ sender, System::EventArgs^ e) {
	
	if (!sim_bool) {
		if (radioButton1->Checked == true)
		{
			delta -= (float)0.5;
		}
		else if (radioButton2->Checked == true)
		{
			delta -= (float)2.0;
		}
		else if (radioButton3->Checked == true)
		{
			delta -= (float)3.5;
		}
		else if (radioButton4->Checked == true)
		{
			delta -= (float)4.0;
		}
	}
}
private: System::Void simact_but_Click(System::Object^ sender, System::EventArgs^ e) {
	sim_bool = true;
	sim_status->Text = "Simulation Activated";
}
private: System::Void simdeact_but_Click(System::Object^ sender, System::EventArgs^ e) {
	sim_bool = false;
	sim_status->Text = "Simulation Deactivated";
	rob_move->Text = "Sim closed";
}
private: System::Void sim_status_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void start_but_Click(System::Object^ sender, System::EventArgs^ e) {
	if (sim_bool) {
		record_stat = true;
		sim_status->Text = "Recording Simulation";
	}
}
private: System::Void stop_but_Click(System::Object^ sender, System::EventArgs^ e) {
	if (sim_bool) {
		record_stat = false;
		sw->Close();
		sim_status->Text = "Simulation Recorded";
	}
}

private: System::Void start_pb_Click(System::Object^ sender, System::EventArgs^ e) {
	if (sim_bool) {
		sw->Close();
		playback_bool = true;
		sim_status->Text = "Playback";
	}
}


private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {


}

private: System::Void capbg_Click(System::Object^ sender, System::EventArgs^ e) {
	capbgbt = true;
}
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}



/*
					bg = bgref.clone();
					frame = image1.clone();
					frameGlobal = frame;
					cvtColor(frame, hsv, COLOR_BGR2HSV);
					cvtColor(frame, frame, COLOR_BGR2GRAY);
					vector<Mat>hsvChannels;
					split(hsv, hsvChannels);
					hsv = hsvChannels[1];

					if (frameCounter == 0 || frameCounter == 1)
					{
						framePrev = frame;
						hsvPrev = hsv;
					}
					else
					{
						medianBlur(frame, frame, 3);
						medianBlur(framePrev, framePrev, 3);

						for (int i = 0; i < frame.rows; i += 5)
						{
							for (int j = 0; j < frame.cols; j += 5)
							{
								int sumFirst = 0, sumSecond = 0;


								if (j + 5 < frame.cols && i + 5 < frame.rows)
								{
									sumFirst += (int)frame.at<uchar>(cv::Point(j, i)) + (int)frame.at<uchar>(cv::Point(j + 1, i)) + (int)frame.at<uchar>(cv::Point(j + 2, i)) + (int)frame.at<uchar>(cv::Point(j + 3, i))
										+ (int)frame.at<uchar>(cv::Point(j + 4, i)) + (int)frame.at<uchar>(cv::Point(j, i + 1)) + (int)frame.at<uchar>(cv::Point(j + 1, i + 1))
										+ (int)frame.at<uchar>(cv::Point(j + 2, i + 1)) + (int)frame.at<uchar>(cv::Point(j + 3, i + 1)) + (int)frame.at<uchar>(cv::Point(j + 4, i + 1)) + (int)frame.at<uchar>(cv::Point(j, i + 2))
										+ (int)frame.at<uchar>(cv::Point(j + 1, i + 2)) + (int)frame.at<uchar>(cv::Point(j + 2, i + 2)) + (int)frame.at<uchar>(cv::Point(j + 3, i + 2)) + (int)frame.at<uchar>(cv::Point(j + 4, i + 2))
										+ (int)frame.at<uchar>(cv::Point(j, i + 3)) + (int)frame.at<uchar>(cv::Point(j + 1, i + 3)) + (int)frame.at<uchar>(cv::Point(j + 2, i + 3)) + (int)frame.at<uchar>(cv::Point(j + 3, i + 3))
										+ (int)frame.at<uchar>(cv::Point(j + 4, i + 3)) + (int)frame.at<uchar>(cv::Point(j, i + 4)) + (int)frame.at<uchar>(cv::Point(j + 1, i + 4)) + (int)frame.at<uchar>(cv::Point(j + 2, i + 4))
										+ (int)frame.at<uchar>(cv::Point(j + 3, i + 4)) + (int)frame.at<uchar>(cv::Point(j + 4, i + 4));

									sumSecond += (int)framePrev.at<uchar>(cv::Point(j, i)) + (int)framePrev.at<uchar>(cv::Point(j + 1, i)) + (int)framePrev.at<uchar>(cv::Point(j + 2, i)) + (int)framePrev.at<uchar>(cv::Point(j + 3, i))
										+ (int)framePrev.at<uchar>(cv::Point(j + 4, i)) + (int)framePrev.at<uchar>(cv::Point(j, i + 1)) + (int)framePrev.at<uchar>(cv::Point(j + 1, i + 1))
										+ (int)framePrev.at<uchar>(cv::Point(j + 2, i + 1)) + (int)framePrev.at<uchar>(cv::Point(j + 3, i + 1)) + (int)framePrev.at<uchar>(cv::Point(j + 4, i + 1)) + (int)framePrev.at<uchar>(cv::Point(j, i + 2))
										+ (int)framePrev.at<uchar>(cv::Point(j + 1, i + 2)) + (int)framePrev.at<uchar>(cv::Point(j + 2, i + 2)) + (int)framePrev.at<uchar>(cv::Point(j + 3, i + 2)) + (int)framePrev.at<uchar>(cv::Point(j + 4, i + 2))
										+ (int)framePrev.at<uchar>(cv::Point(j, i + 3)) + (int)framePrev.at<uchar>(cv::Point(j + 1, i + 3)) + (int)framePrev.at<uchar>(cv::Point(j + 2, i + 3)) + (int)framePrev.at<uchar>(cv::Point(j + 3, i + 3))
										+ (int)framePrev.at<uchar>(cv::Point(j + 4, i + 3)) + (int)framePrev.at<uchar>(cv::Point(j, i + 4)) + (int)framePrev.at<uchar>(cv::Point(j + 1, i + 4)) + (int)framePrev.at<uchar>(cv::Point(j + 2, i + 4))
										+ (int)framePrev.at<uchar>(cv::Point(j + 3, i + 4)) + (int)framePrev.at<uchar>(cv::Point(j + 4, i + 4));

									int avgFirst = sumFirst / 25;
									int avgSecond = sumSecond / 25;

									if (abs(avgFirst - avgSecond) > 25)
									{
										subtractedImg.at<Vec3b>(cv::Point(j, i))[0] = 0;
										subtractedImg.at<Vec3b>(cv::Point(j + 1, i))[0] = 0;
										subtractedImg.at<Vec3b>(cv::Point(j + 2, i))[0] = 0;
										subtractedImg.at<Vec3b>(cv::Point(j + 3, i))[0] = 0;
										subtractedImg.at<Vec3b>(cv::Point(j + 4, i))[0] = 0;
										subtractedImg.at<Vec3b>(cv::Point(j, i + 1))[0] = 0;
										subtractedImg.at<Vec3b>(cv::Point(j + 1, i + 1))[0] = 0;
										subtractedImg.at<Vec3b>(cv::Point(j + 2, i + 1))[0] = 0;
										subtractedImg.at<Vec3b>(cv::Point(j + 3, i + 1))[0] = 0;
										subtractedImg.at<Vec3b>(cv::Point(j + 4, i + 1))[0] = 0;
										subtractedImg.at<Vec3b>(cv::Point(j, i + 2))[0] = 0;
										subtractedImg.at<Vec3b>(cv::Point(j + 1, i + 2))[0] = 0;
										subtractedImg.at<Vec3b>(cv::Point(j + 2, i + 2))[0] = 0;
										subtractedImg.at<Vec3b>(cv::Point(j + 3, i + 2))[0] = 0;
										subtractedImg.at<Vec3b>(cv::Point(j + 4, i + 2))[0] = 0;
										subtractedImg.at<Vec3b>(cv::Point(j, i + 3))[0] = 0;
										subtractedImg.at<Vec3b>(cv::Point(j + 1, i + 3))[0] = 0;
										subtractedImg.at<Vec3b>(cv::Point(j + 2, i + 3))[0] = 0;
										subtractedImg.at<Vec3b>(cv::Point(j + 3, i + 3))[0] = 0;
										subtractedImg.at<Vec3b>(cv::Point(j + 4, i + 3))[0] = 0;
										subtractedImg.at<Vec3b>(cv::Point(j, i + 4))[0] = 0;
										subtractedImg.at<Vec3b>(cv::Point(j + 1, i + 4))[0] = 0;
										subtractedImg.at<Vec3b>(cv::Point(j + 2, i + 4))[0] = 0;
										subtractedImg.at<Vec3b>(cv::Point(j + 3, i + 4))[0] = 0;
										subtractedImg.at<Vec3b>(cv::Point(j + 4, i + 4))[0] = 0;

										subtractedImg.at<Vec3b>(cv::Point(j, i))[1] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j + 1, i))[1] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j + 2, i))[1] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j + 3, i))[1] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j + 4, i))[1] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j, i + 1))[1] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j + 1, i + 1))[1] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j + 2, i + 1))[1] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j + 3, i + 1))[1] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j + 4, i + 1))[1] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j, i + 2))[1] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j + 1, i + 2))[1] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j + 2, i + 2))[1] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j + 3, i + 2))[1] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j + 4, i + 2))[1] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j, i + 3))[1] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j + 1, i + 3))[1] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j + 2, i + 3))[1] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j + 3, i + 3))[1] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j + 4, i + 3))[1] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j, i + 4))[1] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j + 1, i + 4))[1] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j + 2, i + 4))[1] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j + 3, i + 4))[1] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j + 4, i + 4))[1] = 255;

										subtractedImg.at<Vec3b>(cv::Point(j, i))[2] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j + 1, i))[2] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j + 2, i))[2] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j + 3, i))[2] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j + 4, i))[2] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j, i + 1))[2] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j + 1, i + 1))[2] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j + 2, i + 1))[2] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j + 3, i + 1))[2] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j + 4, i + 1))[2] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j, i + 2))[2] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j + 1, i + 2))[2] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j + 2, i + 2))[2] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j + 3, i + 2))[2] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j + 4, i + 2))[2] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j, i + 3))[2] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j + 1, i + 3))[2] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j + 2, i + 3))[2] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j + 3, i + 3))[2] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j + 4, i + 3))[2] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j, i + 4))[2] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j + 1, i + 4))[2] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j + 2, i + 4))[2] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j + 3, i + 4))[2] = 255;
										subtractedImg.at<Vec3b>(cv::Point(j + 4, i + 4))[2] = 255;

									}
								}
							}
						}
						Mat resultSourceImg = subtractedImg;

						medianBlur(hsv, hsv, 3);
						medianBlur(hsvPrev, hsvPrev, 3);

						for (int i = 0; i < hsv.rows; i += 5)
						{
							for (int j = 0; j < hsv.cols; j += 5)
							{
								int sumFirst = 0, sumSecond = 0;


								if (j + 5 < hsv.cols && i + 5 < hsv.rows)
								{
									sumFirst += (int)hsv.at<uchar>(cv::Point(j, i)) + (int)hsv.at<uchar>(cv::Point(j + 1, i)) + (int)hsv.at<uchar>(cv::Point(j + 2, i)) + (int)hsv.at<uchar>(cv::Point(j + 3, i))
										+ (int)hsv.at<uchar>(cv::Point(j + 4, i)) + (int)hsv.at<uchar>(cv::Point(j, i + 1)) + (int)hsv.at<uchar>(cv::Point(j + 1, i + 1))
										+ (int)hsv.at<uchar>(cv::Point(j + 2, i + 1)) + (int)hsv.at<uchar>(cv::Point(j + 3, i + 1)) + (int)hsv.at<uchar>(cv::Point(j + 4, i + 1)) + (int)hsv.at<uchar>(cv::Point(j, i + 2))
										+ (int)hsv.at<uchar>(cv::Point(j + 1, i + 2)) + (int)hsv.at<uchar>(cv::Point(j + 2, i + 2)) + (int)hsv.at<uchar>(cv::Point(j + 3, i + 2)) + (int)hsv.at<uchar>(cv::Point(j + 4, i + 2))
										+ (int)hsv.at<uchar>(cv::Point(j, i + 3)) + (int)hsv.at<uchar>(cv::Point(j + 1, i + 3)) + (int)hsv.at<uchar>(cv::Point(j + 2, i + 3)) + (int)hsv.at<uchar>(cv::Point(j + 3, i + 3))
										+ (int)hsv.at<uchar>(cv::Point(j + 4, i + 3)) + (int)hsv.at<uchar>(cv::Point(j, i + 4)) + (int)hsv.at<uchar>(cv::Point(j + 1, i + 4)) + (int)hsv.at<uchar>(cv::Point(j + 2, i + 4))
										+ (int)hsv.at<uchar>(cv::Point(j + 3, i + 4)) + (int)hsv.at<uchar>(cv::Point(j + 4, i + 4));

									sumSecond += (int)hsvPrev.at<uchar>(cv::Point(j, i)) + (int)hsvPrev.at<uchar>(cv::Point(j + 1, i)) + (int)hsvPrev.at<uchar>(cv::Point(j + 2, i)) + (int)hsvPrev.at<uchar>(cv::Point(j + 3, i))
										+ (int)hsvPrev.at<uchar>(cv::Point(j + 4, i)) + (int)hsvPrev.at<uchar>(cv::Point(j, i + 1)) + (int)hsvPrev.at<uchar>(cv::Point(j + 1, i + 1))
										+ (int)hsvPrev.at<uchar>(cv::Point(j + 2, i + 1)) + (int)hsvPrev.at<uchar>(cv::Point(j + 3, i + 1)) + (int)hsvPrev.at<uchar>(cv::Point(j + 4, i + 1)) + (int)hsvPrev.at<uchar>(cv::Point(j, i + 2))
										+ (int)hsvPrev.at<uchar>(cv::Point(j + 1, i + 2)) + (int)hsvPrev.at<uchar>(cv::Point(j + 2, i + 2)) + (int)hsvPrev.at<uchar>(cv::Point(j + 3, i + 2)) + (int)hsvPrev.at<uchar>(cv::Point(j + 4, i + 2))
										+ (int)hsvPrev.at<uchar>(cv::Point(j, i + 3)) + (int)hsvPrev.at<uchar>(cv::Point(j + 1, i + 3)) + (int)hsvPrev.at<uchar>(cv::Point(j + 2, i + 3)) + (int)hsvPrev.at<uchar>(cv::Point(j + 3, i + 3))
										+ (int)hsvPrev.at<uchar>(cv::Point(j + 4, i + 3)) + (int)hsvPrev.at<uchar>(cv::Point(j, i + 4)) + (int)hsvPrev.at<uchar>(cv::Point(j + 1, i + 4)) + (int)hsvPrev.at<uchar>(cv::Point(j + 2, i + 4))
										+ (int)hsvPrev.at<uchar>(cv::Point(j + 3, i + 4)) + (int)hsvPrev.at<uchar>(cv::Point(j + 4, i + 4));

									int avgFirst = sumFirst / 25;
									int avgSecond = sumSecond / 25;

									if (abs(avgFirst - avgSecond) > 25)
									{
										subtractedImg2.at<Vec3b>(cv::Point(j, i))[0] = 0;
										subtractedImg2.at<Vec3b>(cv::Point(j + 1, i))[0] = 0;
										subtractedImg2.at<Vec3b>(cv::Point(j + 2, i))[0] = 0;
										subtractedImg2.at<Vec3b>(cv::Point(j + 3, i))[0] = 0;
										subtractedImg2.at<Vec3b>(cv::Point(j + 4, i))[0] = 0;
										subtractedImg2.at<Vec3b>(cv::Point(j, i + 1))[0] = 0;
										subtractedImg2.at<Vec3b>(cv::Point(j + 1, i + 1))[0] = 0;
										subtractedImg2.at<Vec3b>(cv::Point(j + 2, i + 1))[0] = 0;
										subtractedImg2.at<Vec3b>(cv::Point(j + 3, i + 1))[0] = 0;
										subtractedImg2.at<Vec3b>(cv::Point(j + 4, i + 1))[0] = 0;
										subtractedImg2.at<Vec3b>(cv::Point(j, i + 2))[0] = 0;
										subtractedImg2.at<Vec3b>(cv::Point(j + 1, i + 2))[0] = 0;
										subtractedImg2.at<Vec3b>(cv::Point(j + 2, i + 2))[0] = 0;
										subtractedImg2.at<Vec3b>(cv::Point(j + 3, i + 2))[0] = 0;
										subtractedImg2.at<Vec3b>(cv::Point(j + 4, i + 2))[0] = 0;
										subtractedImg2.at<Vec3b>(cv::Point(j, i + 3))[0] = 0;
										subtractedImg2.at<Vec3b>(cv::Point(j + 1, i + 3))[0] = 0;
										subtractedImg2.at<Vec3b>(cv::Point(j + 2, i + 3))[0] = 0;
										subtractedImg2.at<Vec3b>(cv::Point(j + 3, i + 3))[0] = 0;
										subtractedImg2.at<Vec3b>(cv::Point(j + 4, i + 3))[0] = 0;
										subtractedImg2.at<Vec3b>(cv::Point(j, i + 4))[0] = 0;
										subtractedImg2.at<Vec3b>(cv::Point(j + 1, i + 4))[0] = 0;
										subtractedImg2.at<Vec3b>(cv::Point(j + 2, i + 4))[0] = 0;
										subtractedImg2.at<Vec3b>(cv::Point(j + 3, i + 4))[0] = 0;
										subtractedImg2.at<Vec3b>(cv::Point(j + 4, i + 4))[0] = 0;

										subtractedImg2.at<Vec3b>(cv::Point(j, i))[1] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j + 1, i))[1] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j + 2, i))[1] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j + 3, i))[1] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j + 4, i))[1] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j, i + 1))[1] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j + 1, i + 1))[1] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j + 2, i + 1))[1] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j + 3, i + 1))[1] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j + 4, i + 1))[1] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j, i + 2))[1] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j + 1, i + 2))[1] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j + 2, i + 2))[1] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j + 3, i + 2))[1] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j + 4, i + 2))[1] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j, i + 3))[1] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j + 1, i + 3))[1] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j + 2, i + 3))[1] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j + 3, i + 3))[1] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j + 4, i + 3))[1] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j, i + 4))[1] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j + 1, i + 4))[1] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j + 2, i + 4))[1] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j + 3, i + 4))[1] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j + 4, i + 4))[1] = 255;

										subtractedImg2.at<Vec3b>(cv::Point(j, i))[2] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j + 1, i))[2] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j + 2, i))[2] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j + 3, i))[2] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j + 4, i))[2] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j, i + 1))[2] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j + 1, i + 1))[2] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j + 2, i + 1))[2] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j + 3, i + 1))[2] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j + 4, i + 1))[2] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j, i + 2))[2] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j + 1, i + 2))[2] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j + 2, i + 2))[2] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j + 3, i + 2))[2] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j + 4, i + 2))[2] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j, i + 3))[2] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j + 1, i + 3))[2] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j + 2, i + 3))[2] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j + 3, i + 3))[2] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j + 4, i + 3))[2] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j, i + 4))[2] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j + 1, i + 4))[2] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j + 2, i + 4))[2] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j + 3, i + 4))[2] = 255;
										subtractedImg2.at<Vec3b>(cv::Point(j + 4, i + 4))[2] = 255;

									}
								}
							}
						}

						Mat resultSourceImg2 = subtractedImg2;


						Mat resultSourceImg3 = resultSourceImg.clone();
						Mat element = getStructuringElement(MORPH_ELLIPSE,
							cv::Size(2 * 3 + 1, 2 * 3 + 1),
							cv::Point(5, 5));
						Mat element2 = getStructuringElement(MORPH_ELLIPSE,
							cv::Size(2 * 3 + 1, 2 * 3 + 1),
							cv::Point(5, 5));

						erode(resultSourceImg, resultSourceImg, element);

						dilate(resultSourceImg, resultSourceImg, element2);

						erode(resultSourceImg2, resultSourceImg2, element);

						dilate(resultSourceImg2, resultSourceImg2, element2);


						for (int m = 0; m < frameGlobal.rows; m++)
						{
							for (int n = 0; n < frameGlobal.cols; n++)
							{
								if ((int)resultSourceImg.at<Vec3b>(cv::Point(n, m))[1] != 0)
								{
									resultSourceImg.at<Vec3b>(cv::Point(n, m))[0] = frameGlobal.at<Vec3b>(cv::Point(n, m))[0];
									resultSourceImg.at<Vec3b>(cv::Point(n, m))[1] = frameGlobal.at<Vec3b>(cv::Point(n, m))[1];
									resultSourceImg.at<Vec3b>(cv::Point(n, m))[2] = frameGlobal.at<Vec3b>(cv::Point(n, m))[2];

									resultSourceImg3.at<Vec3b>(cv::Point(n, m))[0] = frameGlobal.at<Vec3b>(cv::Point(n, m))[0];
									resultSourceImg3.at<Vec3b>(cv::Point(n, m))[1] = frameGlobal.at<Vec3b>(cv::Point(n, m))[1];
									resultSourceImg3.at<Vec3b>(cv::Point(n, m))[2] = frameGlobal.at<Vec3b>(cv::Point(n, m))[2];


								}

								else if ((int)resultSourceImg2.at<Vec3b>(cv::Point(n, m))[1] != 0)
								{
									resultSourceImg.at<Vec3b>(cv::Point(n, m))[0] = frameGlobal.at<Vec3b>(cv::Point(n, m))[0];
									resultSourceImg.at<Vec3b>(cv::Point(n, m))[1] = frameGlobal.at<Vec3b>(cv::Point(n, m))[1];
									resultSourceImg.at<Vec3b>(cv::Point(n, m))[2] = frameGlobal.at<Vec3b>(cv::Point(n, m))[2];

									resultSourceImg3.at<Vec3b>(cv::Point(n, m))[0] = frameGlobal.at<Vec3b>(cv::Point(n, m))[0];
									resultSourceImg3.at<Vec3b>(cv::Point(n, m))[1] = frameGlobal.at<Vec3b>(cv::Point(n, m))[1];
									resultSourceImg3.at<Vec3b>(cv::Point(n, m))[2] = frameGlobal.at<Vec3b>(cv::Point(n, m))[2];

								}
								else {
									resultSourceImg3.at<Vec3b>(cv::Point(n, m))[0] = bg.at<Vec3b>(cv::Point(n, m))[0];
									resultSourceImg3.at<Vec3b>(cv::Point(n, m))[1] = bg.at<Vec3b>(cv::Point(n, m))[1];
									resultSourceImg3.at<Vec3b>(cv::Point(n, m))[2] = bg.at<Vec3b>(cv::Point(n, m))[2];
								}

							}
						}

						imshow("Result", resultSourceImg);

						imshow("WithBackground", resultSourceImg3);

						imshow("Source", frameGlobal);

						subtractedImg = Mat::zeros(cv::Size(1280, 720), CV_8UC3);
						subtractedImg2 = Mat::zeros(cv::Size(1280, 720), CV_8UC3);
					}

					frameCounter++;
					*/