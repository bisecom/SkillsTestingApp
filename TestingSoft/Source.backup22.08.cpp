//��������� ��� ������������ ��������� "������ 2018"
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include <windows.h>
#include <io.h>
#include <conio.h>
#include <stdio.h>
#include "locale.h"
#include <string.h>
#include <cstdlib>
#include<fstream>
#include <random>
#include <algorithm>
#include <ctime>

using namespace std;


class Question // ����� ��� �������� ���������� �� ������� ������� �����
{
public:	
	char semi_subject[500];
	char question[500];
	char answers_arr[4][50];
	bool correct_answ_arr[4];
	
public:
	Question(){
		strcpy(semi_subject, "");
		strcpy(question, "");
		
		strcpy(answers_arr[0], "");
		correct_answ_arr[0] = false;
		strcpy(answers_arr[1], "");
		correct_answ_arr[1] = false;
		strcpy(answers_arr[2], "");
		correct_answ_arr[2] = false;
		strcpy(answers_arr[3], "");
		correct_answ_arr[3] = false;
	}

	void SetQuestion()//��������� ������� �������
	{
		string temp_str;
		char temp_quest[500], temp_answ[50];
		cout << "����������, ������� ����������� �����:" << endl;
		cout << "��������, ��������� ������.." << endl;
		gets_s(temp_quest);
		strcpy(semi_subject, temp_quest);
		cout << "������� ������ :" << endl;
		gets_s(temp_quest);
		strcpy(question, temp_quest);
		cout << "������� ������ ����� �1 �� ������ :" << endl;
		gets_s(temp_answ);
		strcpy(answers_arr[0], temp_answ);
		correct_answ_arr[0] = false;
		cout << "������� ������ ����� �2 �� ������ :" << endl;
		gets_s(temp_answ);
		strcpy(answers_arr[1], temp_answ);
		correct_answ_arr[1] = false;
		cout << "������� ������ ����� �3 �� ������ :" << endl;
		gets_s(temp_answ);
		strcpy(answers_arr[2], temp_answ);
		correct_answ_arr[2] = false;
		cout << "������� ���������� ����� �� ������ :" << endl << endl;
		gets_s(temp_answ);
		strcpy(answers_arr[3], temp_answ);
		correct_answ_arr[3] = true;
		
	}
	void SetQuestionArg(char * _semi_subject, char * _question, char * _answers_arr0, char * _answers_arr1,
		char * _answers_arr2, char * _answers_arr3, int _correct_answ)
	{
		strcpy(semi_subject, _semi_subject);
		strcpy(question, _question);
		strcpy(answers_arr[0], _answers_arr0);
		strcpy(answers_arr[1], _answers_arr1);
		strcpy(answers_arr[2], _answers_arr2);
		strcpy(answers_arr[3], _answers_arr3);
		for (int i = 0; i < 4; i++)
			correct_answ_arr[i] = false;
		correct_answ_arr[_correct_answ] = true;

	}

	void DisplayQuestion()// ����� ��������
	{
		cout << "��������� ������� : " << endl; cout << semi_subject << endl;
		cout << "������ �1" << endl;
		cout << question << endl;
		cout << "������� �1 " << answers_arr[0] << "        ������� �2 " << answers_arr[1] << endl;
		cout << "������� �3 " << answers_arr[2] << "        ������� �4 " << answers_arr[3] << endl <<endl;

	}

};

class Test : public Question //����� ����, ������� ����������� �� �����������. ����� ���� ������� �� 2� ��������
{
public:
	char subject_name[50], test_name[50]; // 
	Question array_of_questions_per_test[2];
	char temp_answ_arr1[4][50], temp_answ_arr2[4][50];
public:
	Test()
	{
		strcpy(subject_name, "");
	}

	void SetTest(char * str, char * str1)// ��������� ������� �����
	{
		strcpy(subject_name, str);
		strcpy(test_name, str1);
		for (int i = 0; i < 2; i++)
			array_of_questions_per_test[i].SetQuestion();

	}
	void SetTestName(char * str)
	{
		strcpy(test_name, str);
	}
	void SetArrQuestions(Question arr[2])
	{
		array_of_questions_per_test[0] = arr[0];
		array_of_questions_per_test[1] = arr[1];
	
	}
	
	void SetTestSubjName(char * _temp)
	{
		strcpy(subject_name, _temp);
	}

	const char * GetTestSubjName() const
	{
		return subject_name;
	}

	const char * GetTestName() const
	{
		return test_name;
	}
	char * GetTempAnswArr_1() 
	{
		return temp_answ_arr1[4];
	}
	char * GetTempAnswArr_2()
	{
		return temp_answ_arr2[4];
	}
	Question * GetQuestArr()
	{
		return array_of_questions_per_test;
	}

	void DisplayTest()// ����� �� ����� ����� ��� ��������������, � ������� �� ���������� �������
	{
		cout << "--------------------------------------------------------------------" << endl;
		cout << "������ ���� �� �������� " << subject_name << endl;
		cout << "--------------------------------------------------------------------" << endl;
		
			cout << "����������� �����:" << endl;
			cout << "..................................................................." << endl;
			cout << array_of_questions_per_test[0].semi_subject << endl;
			cout << "������ � "<<1<<" :" << endl;
			cout << array_of_questions_per_test[0].question << endl;
			
			for (int j = 0; j < 4; j++)
			{
				cout << "����� � "<<j+1<<" �� ������ �" << 0 + 1 << " :" << endl;
				cout << array_of_questions_per_test[0].answers_arr[j] << endl;
				
			}
			for (int k = 0; k < 4; k++)
			{
				if (array_of_questions_per_test[0].correct_answ_arr[k] == true)
					cout << "����� ����������� ������ �� ������ � " << 0 + 1 << " �������� � "<< k+1 << endl;
			}
		
			cout << endl;

			cout << "����������� �����:" << endl;
			cout << array_of_questions_per_test[1].semi_subject << endl;
			cout << "������ � " << 2 << " :" << endl;
			cout << array_of_questions_per_test[1].question << endl;

			for (int j = 0; j < 4; j++)
			{
				cout << "����� � " << j + 1 << " �� ������ �" << 0 + 2 << " :" << endl;
				cout << array_of_questions_per_test[1].answers_arr[j] << endl;
				
			}
			for (int k = 0; k < 4; k++)
			{
				if (array_of_questions_per_test[1].correct_answ_arr[k] == true)
					cout << "����� ����������� ������ �� ������ � " << 0 + 2 << " �������� � " << k + 1 << endl;
			}

			cout << "--------------------------------------------------------------------"<<endl;
	}
	
		void DisplayTestForPassing()// ����� �� ����� ����� ��� ������������ ��� ����������� �����
	{
			
		cout << "--------------------------------------------------------------------" << endl;
		cout << "������ ���� �� �������� : " << subject_name << endl;
		cout << "�������� �����          : " << test_name << endl;
		cout << "--------------------------------------------------------------------" << endl;
		
			cout << "����������� �����:" << endl;
			cout << "..................................................................." << endl;
			cout << array_of_questions_per_test[0].semi_subject << endl;
			cout << "������ � "<<1<<" :" << endl;
			cout << array_of_questions_per_test[0].question << endl;
			
			for (int j = 0; j < 4; j++)
				strcpy(&*temp_answ_arr1[j], array_of_questions_per_test[0].answers_arr[j]); 
			random_shuffle(temp_answ_arr1, temp_answ_arr1 + sizeof(temp_answ_arr1) / sizeof(*temp_answ_arr1));
			for (int j = 0; j < 4; j++)
			{
				cout << "������� ������ � "<<j+1<<" �� ������ �" << 0 + 1 << " :" << endl;
				cout << temp_answ_arr1[j] << endl;
			}
					
			cout << endl;
			for (int j = 0; j < 4; j++)
			{				
				strcpy(&*temp_answ_arr2[j], array_of_questions_per_test[1].answers_arr[j]);
			}
			random_shuffle(temp_answ_arr2, temp_answ_arr2 + sizeof(temp_answ_arr2) / sizeof(*temp_answ_arr2));// ������������� �������� ����� �������
			cout << "����������� �����:" << endl;
			cout << array_of_questions_per_test[1].semi_subject << endl;
			cout << "������ � " << 2 << " :" << endl;
			cout << array_of_questions_per_test[1].question << endl;

			for (int j = 0; j < 4; j++)
			{
				cout << "������� ������ � " << j + 1 << " �� ������ �" << 0 + 2 << " :" << endl;
				cout << temp_answ_arr2[j] << endl;
				
			}
		
			cout << "--------------------------------------------------------------------"<<endl;
	}
	
	
	
};

class Statistic// ����� ����������, ������� �������� ������ ����� ����� ������� �����
{
public:
	char stat_guest_login[50];
	char stat_subject_name[50];
	char stat_test_name[50];
	int correct_answ_qty; // max can be 2;
	int test_rate; //max can be 12;
	bool complete_test;

public:
	Statistic() {
		strcpy(stat_guest_login, "");
		strcpy(stat_subject_name, "");
		strcpy(stat_test_name, "");
		correct_answ_qty = 0;
		test_rate = 0;
		complete_test = false;
	}


};

class Guest : public Statistic // ����� �����, �������� ���� �� ������� ������������
{
	char guest_login[50];
	char guest_pass[50];
	char guest_surname[50];
	char guest_name[50];
	char guest_address[250];
	char guest_phone_number[50];
	bool guest_is_registered;

public:
	Guest() 
	{ 
		strcpy(guest_login, " ");
		strcpy(guest_pass, " ");
		strcpy(guest_surname, " ");
		strcpy(guest_name, " ");
		strcpy(guest_address, " ");
		strcpy(guest_phone_number, " ");
		guest_is_registered = false; 
	}

	void SetGLogin(char * _guest_login)
	{
		strcpy(guest_login, _guest_login);
	}
	
	void SetGPass(char * _guest_pass)
	{
		strcpy(guest_pass, _guest_pass);
	}

	void SetGSurname(char *_guest_surname)
	{
		strcpy(guest_surname, _guest_surname);
	}

	void SetGName(char *_guest_name)
	{
		strcpy(guest_name, _guest_name);
	}

	void SetGAddress(char *_guest_address)
	{
		strcpy(guest_address, _guest_address);
	}

	void SetGPhone(char *_guest_phone_number)
	{
		strcpy(guest_phone_number, _guest_phone_number);
	}

	void SetGIsRegistered(bool _guest_is_registered) {
		guest_is_registered = _guest_is_registered;
	}

	const char * GetGuestLogin() const
	{
		return guest_login;
	}
	const char * GetGuestPass() const
	{
		return guest_pass;
	}

	const char * GetGuestSurname() const
	{
		return guest_surname;
	}
	const char * GetGuestName() const
	{
		return guest_name;
	}

	const char * GetGuestAddress() const
	{
		return guest_address;
	}
	
	void ShowGuestDetails()//����� �� ����� ������ �� ������������
	{
		cout << "-----------------------------------------------------------" << endl;
		cout << "��� ������������             : " << guest_name << " " << guest_surname << endl;
		cout << "����� �������� ������������  : " << DeCodingStr(guest_login).c_str() << endl;
		cout << "������ �������� ������������ : " << DeCodingStr(guest_pass).c_str() << endl;
		cout << "�����                        : " << guest_address << endl;
		cout << "�������                      : " << guest_phone_number << endl;
		cout << "-----------------------------------------------------------" << endl;
	}

	string DeCodingStr(char * str)
	{
		string str_temp;
		str_temp = str;
		for (int i = 0; i <str_temp.size(); i++) {
			str_temp[i] = str_temp[i] - 3;
		}
		return str_temp;
	}


};


class Admin : public Statistic // �������� �����, ����� ������� �������������� ���� ���������� ���������
{								//������������� �������� ������ �������
private:

	Guest * myguest;
	Guest *p;
	Test * mytestobj;//��������� �� ������ ������ ����, ��� ���������� � ������ ������ �� �����
	vector <Test> VectTests; //������ �������� ������ ���� ��� �������� ������, �������� ������������� ������, ����������� ������� �������
	char subjectslab [20][50];// ������ ��������� / ���������
	int tests_qty;
	//int m;
	vector<Guest> VectGuests;//������ �������� ������ ����� ��� �������� ������, �������� ������������� ������, ����������� ������� �������
	Statistic * mystatistic_admin;//��������� �� ������ ������ ����������, ��� ���������� � ������ ������ �� �����
	vector<Statistic> StatVectAdmin;//������ �������� ������ ���������� ��� �������� ������, �������� ������������� ������, ����������� ������� �������
	char temp_login[50], temp_pass[100], guest_login_stat[50];
	struct AdmData {//��������� ��� ���������, ������ � ���������� ������ �� ������
		char admin_login[50];
		char admin_pass[100];
		char admin_surname[50];
		char admin_name[50];
		char admin_email[50];
		bool is_registered = false;
	} a_data;
	FILE * fp_adm_reg;

public:
	Admin(){}
	
	void MainMenu_draw()// ����� �� ����� ��������� ����
	{
		system("cls");
		SoftNameShow();
		printf("1. ����������� ��������������\n"); //��������� AdminRegistration()
		printf("2. ��������� ������ ��������������\n");//��������� AdminRegErasing()
		printf("3. �������� �������� ��������������\n");//��������� AdminRegErasing()
		printf("4. ����������� ������������\n");//�������� CreateGuest()
		printf("5. �������� �������� ������������\n"); // DeleteGuestAcc()
		printf("6. ���� � ������� ��������������\n");
		printf("7. ���� � ������� ������������\n"); //EnterToGuestAcc()
		printf("8. ����� �� ���������\n\n");
	}
	
	void FirstMenu()// ���������� ��������� ����
	{
		bool choice = false; char ch;
		while (!choice)
		{
			MainMenu_draw();Sleep(1000);
			if (kbhit())
			{
				ch = getch();
				switch (ch)
				{
				case 49:
				{	//printf("����������� ��������������\n");
				AdminRegistration();
				/*choice = true;*/
				Sleep(3000);
				break; }
				case 50:
				{//printf("��������� ������ ��������������\n");
				AdminLoginPassChange();
				/*choice = true;*/ break; }
				case 51:
				{//printf("�������� �������� ��������������\n");
				AdminRegErasing();
				/*choice = true;*/ break; }
				case 52:
				{//printf("����������� ������������\n");
				CreateGuest();
				/*choice = true;*/ break; }
				case 53:
				{//printf("�������� �������� ������������\n");
				DeleteGuestAcc();
				choice = true; break; }
				case 54:
				{//printf("���� � ������� ��������������\n");
				EnterToAdminAcc();
				choice = true; break; }
				case 55:
				{//printf("���� � ������� ������������\n");
				EnterToGuestAcc();
				choice = true; break; }
				case 56:
				{//printf("����� �� ���������\n");
				choice = true;
				cout << "\n������� �� ����������� ����������!" << endl;
				break; }

				}
			}
		}
				
	}
	
	void SoftNameShow()
	{
		for (int i = 0; i<55; i++) cout << "-";
		cout << endl;
		cout << "��������� �� ������������ ��������� �� ���������" << endl;
		cout << "����������, ������ � �.�." << endl;
		cout << "                                     <<������ 2018>>" << endl;
		for (int i = 0; i<55; i++) cout << "-";
		cout << endl;

	}

	void AdminRegistration()//����������� ��������������
	{
		cout << "-----------------------------------" << endl;
		cout << "����������� �������������� :" << endl;
		cout << "-----------------------------------" << endl;

		cout << "���������� �������� ����� :" << endl;

		gets_s(temp_login);
		fp_adm_reg = fopen("AdminDetails.dat", "a+b");
		if (fp_adm_reg == NULL) {
			perror("Open");
			return;
		}
		fread(&a_data, sizeof(AdmData), 1, fp_adm_reg);
		if (a_data.is_registered == true)//�������� ���� ������������� ��� ��������������� � ���������
		{
			cout << "��������, ������������� ��� ���������������!" << endl;
			return;
		}
		if (!a_data.is_registered)
		{
			strcpy(a_data.admin_login, CodingStr(temp_login).c_str());
			cout << "����������, ������� ������:" << endl;
			gets_s(temp_pass);
			strcpy(a_data.admin_pass, CodingStr(temp_pass).c_str());
			cout << "����������, ������� �������:" << endl;
			gets_s(a_data.admin_surname);
			cout << "����������, ������� ���:" << endl;
			gets_s(a_data.admin_name);
			cout << "����������, ������� EMAIL:" << endl;
			gets_s(a_data.admin_email);
			a_data.is_registered = true;
			cout << "�����������, ����������� ������ �������!" << endl;
			fwrite(&a_data, sizeof(AdmData), 1, fp_adm_reg);
			
		}

		fclose(fp_adm_reg);
		cout << "������� �������������� ������� ������!" << endl;
	}

	void AdminRegErasing()//�������� �������� ������
	{
		cout << "-----------------------------------" << endl;
		cout << "�������� �������� ��������������  :" << endl;
		cout << "-----------------------------------" << endl;
		fp_adm_reg = fopen("AdminDetails.dat", "a+b");
		if (fp_adm_reg == NULL) {
			perror("Open");
			return;
		}
		fread(&a_data, sizeof(AdmData), 1, fp_adm_reg);
		fclose(fp_adm_reg);
		cout << "��� �������� �������� ��������������, " << endl;
		cout << "������� ������ �������������� :" << endl;
		bool choice_ = false;
		do
		{
			gets_s(temp_pass);
			if (!strcmp(DeCodingStr(a_data.admin_pass).c_str(), temp_pass))//�������� ������ � ������
			{
				fp_adm_reg = fopen("AdminDetails.dat", "wb");
				if (fp_adm_reg == NULL) {
					perror("Open"); return; }
				cout << "������� �������������� ��� ������!" << endl;
				fclose(fp_adm_reg);
				break;
			}
			if (!strcmp("0", temp_pass)) choice_ = true;
			else
				cout << "������� ������ ������ ��� <<0>> ��� ������!" << endl;
		} while (!choice_);
		//cin.ignore(); 
		
		FirstMenu();
	}

	void AdminLoginPassChange()//��������� ������ ��������������
	{
		cout << "-----------------------------------" << endl;
		cout << "��������� ������ ��������������  :" << endl;
		cout << "-----------------------------------" << endl;
		fp_adm_reg = fopen("AdminDetails.dat", "r+b");
		if (fp_adm_reg == NULL) {
			cout << "�������� ������� ������ ��� �� ������!" << endl;;
			return;
		}
		fread(&a_data, sizeof(AdmData), 1, fp_adm_reg);
		fclose(fp_adm_reg);
		cout << "��� ��������� ������ ��������������, " << endl;
		cout << "������� ����������� ������ :" << endl;
		bool choice_ = false;
		do
		{
			//cin.ignore();
			gets_s(temp_pass);
			if (!strcmp(DeCodingStr(a_data.admin_pass).c_str(), temp_pass))
			{
				fp_adm_reg = fopen("AdminDetails.dat", "wb");
				if (fp_adm_reg == NULL) {
					perror("Open"); return;
				}
				strcpy(temp_pass, "");
				cout << "������� ����� ������ :" << endl;
				gets_s(temp_pass);
				strcpy(a_data.admin_pass, CodingStr(temp_pass).c_str());
				fwrite(&a_data, sizeof(AdmData), 1, fp_adm_reg);
				fclose(fp_adm_reg);
				cout << "������ �������������� ��� �������!" << endl;
				Sleep(3000);
				break;
			}
			if (!strcmp("0", temp_pass)) choice_ = true;
			else
				cout << "������� ������ ������ ��� <<0>> ��� ������!" << endl;
		} while (!choice_);

	}
	//-------------------------------------------------------------------
	void EnterToAdminAcc()// ���� � ������� ��������������
	{
		char temp[100];
		cout << "\n��� ����� � ������� ��������������, ������� ����� :" << endl;
		
		fp_adm_reg = fopen("AdminDetails.dat", "r+b"); // �������� ����� ��� ���������� ������
		if (fp_adm_reg == NULL) {
			cout << "�������� ������� ������ ��� �� ������!" << endl;
			return;
		}
		fread(&a_data, sizeof(AdmData), 1, fp_adm_reg);//���������� ���������
		fclose(fp_adm_reg);
		bool choice_ = false;
		do
		{
			//cin.ignore();
			gets_s(temp);
			if (!strcmp(DeCodingStr(a_data.admin_login).c_str(), temp))//�������������� ������ � ��� ��������� � ���������
			break;
			if (!strcmp("0", temp)) {
			choice_ = true;return;}	
			else
				cout << "������� ������ ����� ��� <<0>> ��� ������!" << endl;
		} while (!choice_);
		
		cout << "��� �����, ������� ���� ������ :" << endl;
		choice_ = false;
		do
		{
			//cin.ignore();
			gets_s(temp);
			if (!strcmp(DeCodingStr(a_data.admin_pass).c_str(), temp))//�������������� ������ � ��� ��������� � ���������
			{
				AdminMenu_1();
				break;
			}
			if (!strcmp("0", temp)) {
			choice_ = true;return;}
			else
				cout << "������� ������ ������ ��� <<0>> ��� ������!" << endl;
		} while (!choice_);


	}

	void EnterToGuestAcc()//���� � ������� ������������
	{
		char temp_pass[50], temp_login[50];
		bool data_is_ok = false;
		fstream file_read("GuestsLab.dat", ios::in | ios::binary);
		if (!file_read.is_open())
		{
			file_read.close();
			cout << "������������ ��� �� �������!" << endl;	Sleep(3000); return;
		}

		file_read.seekg(0, ios::end);
		int size_of_file_in_bytes = file_read.tellg();
		int size_of_array = size_of_file_in_bytes / sizeof(Guest); //���������� ������� �������� �� �����, ����������� ���������� ��������

		Guest *p = new Guest[size_of_array]; //��������� ������ ��� ������� �������� ������ ������������
		file_read.seekg(0, ios::beg);
		for (int k = 0; k < size_of_array; k++) {
			Guest * _temp_ = new Guest;
			file_read.read((char*)_temp_, sizeof(Guest));
			*(p + k) = *_temp_;
			delete _temp_;
		}
		file_read.close();

		for (int i = 0; i < size_of_array; i++)
		{	VectGuests.push_back(p[i]);		}//���������� ������� ��������, � ������� ������� �������� ������ ������������
		delete[] p;
		
		cout << "\n��� ����� � ������� ������������, ������� ����� :" << endl;
		
		do
		{
			//cin.ignore();
			//cin >> temp;
			gets_s(temp_login);
			for (int i = 0; i < VectGuests.size(); i++) {
				if (!strcmp(DeCodingStr((char *)VectGuests.at(i).GetGuestLogin()).c_str(), temp_login))//�������������� ������ � ��� ��������� � ���������
				{data_is_ok = true;	break;}
			}
			
			if (!strcmp("0", temp_login)) {
			data_is_ok = true; FirstMenu();}
			if(data_is_ok == false)
				cout << "������� ������ ����� ��� <<0>> ��� ������!" << endl;

		} while (!data_is_ok);
		
		cout << "��� �����, ������� ���� ������ :" << endl;
		data_is_ok = false;
		do
		{
			//cin.ignore();
			//cin >> temp;
			gets_s(temp_pass);
			for (int i = 0; i < VectGuests.size(); i++) {
				if (strcmp(DeCodingStr((char *)VectGuests.at(i).GetGuestPass()).c_str(), temp_pass) == 0)
				{
					GuestMenu_1();	break;
				}
			}
			if (!strcmp("0", temp_pass)) {
			data_is_ok = true; FirstMenu();}
			if (data_is_ok == false)
				cout << "������� ������ ����� ��� <<0>> ��� ������!" << endl;

		} while (!data_is_ok);
		
		strcpy(guest_login_stat, temp_login);
	}

	//-------------------------------------------------------------------
	void AdminMenu_1_draw() //���� �������� ������
	{
		system("cls");	SoftNameShow();
		printf("1. ���������� ��������������\n");
		printf("2. �������� ����������\n");
		printf("3. ���������� �������������\n");
		printf("4. ������� � ���������� ����\n");
	}

	void AdminMenu_1()
	{
		bool choice = false; char ch;
		while (!choice)
		{
			AdminMenu_1_draw(); Sleep(1000);
			if (kbhit())
			{
				ch = getch();
				switch (ch)
				{
				case 49:
				{//printf("���������� ��������������\n");
				AdminMenu_1_1();
					choice = true;  break; }
				case 50:
				{//printf("�������� ����������\n");
				AdminMenu_1_2();
				choice = true; break; }
				case 51:
				{//printf("���������� �������������\n");
				AdminMenu_1_3();
				choice = true; break; }
				case 52:
				{//printf("������� � ���������� ����\n");
				FirstMenu();
				choice = true; break; }
				}
			}
		}
	}

	//-------------------------------------------------------------------
	void AdminMenu_1_1_draw()// ���� ���������� ��������������
	{
		system("cls");	SoftNameShow();
		printf("1. �������� �������� ������������\n");//CreateGuest();
		printf("2. ��������� �������� ������������\n");//EditGuestAcc();
		printf("3. �������� �������� ������������\n");//DeleteGuestAcc();
		printf("4. ������� � ���������� ����\n");
	}

	void AdminMenu_1_1()
	{
		bool choice = false; char ch;
		while (!choice)
		{
			AdminMenu_1_1_draw(); Sleep(1000);
			if (kbhit())
			{
				ch = getch();
				switch (ch)
				{
				case 49:
				{//printf("�������� �������� ������������\n");
				CreateGuest();
				choice = false;  break; }
				case 50:
				{//printf("��������� �������� ������������\n");
				EditGuestAcc();
				choice = false; break; }
				case 51:
				{//printf("�������� �������� ������������\n");
				DeleteGuestAcc();
				choice = true; break; }
				case 52:
				{//printf("������� � ���������� ����\n");
				AdminMenu_1();
				choice = true; break; }
				}
			}
		}
	}

	//-------------------------------------------------------------------
	void AdminMenu_1_2_draw()// ���� �������� ����������
	{
		system("cls");	SoftNameShow();
		printf("1. �������� ���������� �� ���������\n"); //ShowStatisticForAdminCategory();
		printf("2. �������� ���������� �� ������������� �����\n");//ShowStatisticForAdminTest();
		printf("3. �������� ���������� �� ������������\n");//ShowStatisticForAdminbyGuest();
		printf("4. ����� ���������� � ����\n");//ExportStatisticToFile();
		printf("5. ������� � ���������� ����\n");
	}

	void AdminMenu_1_2()
	{
		bool choice = false; char ch;
		while (!choice)
		{
			AdminMenu_1_2_draw(); Sleep(1000);
			if (kbhit())
			{
				ch = getch();
				switch (ch)
				{
				case 49:
				{//printf("�������� ���������� �� ���������\n");
				ShowStatisticForAdminCategory();
				choice = false;  break; }
				case 50:
				{//printf("�������� ���������� �� ������������� �����\n");
				ShowStatisticForAdminTest();
				choice = false; break; }
				case 51:
				{//printf("�������� ���������� �� ������������\n");
				choice = false; ShowStatisticForAdminbyGuest();
				break; }
				case 52:
				{//printf("����� ���������� � ����\n");
				choice = false; ExportStatisticToFile();
				break; }
				case 53:
				{//printf("������� � ���������� ����\n");
				AdminMenu_1();
				choice = true; break; }
			}
			}
		}
	}
	
	//-------------------------------------------------------------------
	void AdminMenu_1_3_draw()// ���� ���������� �������������
	{
		system("cls");	SoftNameShow();
		printf("1. ���������� ��������� �����\n"); //void CreateCategory()
		printf("2. ���������� �����\n"); //void CreateTest()
		printf("3. ������������� �����\n"); //void EditTest()
		printf("4. ������� ��������� ������ � ����\n"); //ExportCatToFile()
		printf("5. ������ ��������� ������ �� �����\n"); //ImportCatFromFile()
		printf("6. ������� ������ � ����\n"); //void ExportTestToFile()
		printf("7. ������ ����� �� �����\n");//ImportTestFromFile();
		printf("8. ������� � ���������� ����\n");
	}

	void AdminMenu_1_3()
	{
		bool choice = false; char ch;
		while (!choice)
		{
			AdminMenu_1_3_draw(); Sleep(1000);
			if (kbhit())
			{
				ch = getch();
				switch (ch)
				{
				case 49:
				{//printf("���������� ��������� �����\n");
				CreateCategory();
				choice = false;  break; }
				case 50:
				{//printf("���������� �����\n");
				CreateTest();
				choice = false; break; }
				case 51:
				{//printf("������������� �����\n");
				EditTest();
				choice = false; break; }
				case 52:
				{//printf("������� ��������� ������ � ����\n");
				ExportCatToFile();
				choice = false; break; }
				case 53:
				{//printf("������ ��������� ������ �� �����\n");
				ImportCatFromFile();
				choice = false; break; }
				case 54:
				{//printf("������� ������ � ����\n");
				ExportTestToFile();
				choice = false; break; }
				case 55:
				{//printf("������ ����� �� �����\n");
				ImportTestFromFile();
				choice = false; break; }
				case 56:
				{//printf("������� � ���������� ����\n");
				AdminMenu_1();
				choice = true; break; }
				}

			}
		}
		AdminMenu_1();
	}

	//-------------------------------------------------------------------
	void GuestMenu_1_draw()// ���� ������� ������������
	{
		system("cls");	SoftNameShow();
		printf("1. ���������� ������������\n");//ShowStatisticForGuest(guest_login);
		printf("2. ������ ����\n"); //TestPassing(guest_login);
		printf("3. ��������� �� ���������� ����\n");
		printf("4. ������� � ���������� ����\n");
	}

	void GuestMenu_1()
	{
		bool choice = false; char ch;
		while (!choice)
		{
			GuestMenu_1_draw(); Sleep(1000);
			if (kbhit())
			{
				ch = getch();
				switch (ch)
				{
				case 49:
				{//printf("���������� ������������\n");
				ShowStatisticForGuest(guest_login_stat);
				choice = false;  break; }
				case 50:
				{//printf("������ ����\n");
				TestPassing(guest_login_stat);
				choice = false; break; }
				case 51:
				{printf("\n��������� �� ���������� ����\n");
				Sleep(5000);
				choice = false; break; }
				case 52:
				{//printf("������� � ���������� ����\n");
				FirstMenu();
				choice = true; break; }
				}

			}
		}
	}
	
	//-------------------------------------------------------------------
		
	void CreateGuest()//�������� ������� ������������
	{
		bool if_log_exist = false;
		bool file_absence = false;
		char temp[50];
		char temp_address[250];
		myguest = new Guest;
		
		cout << "-----------------------------------" << endl;
		cout << "����������� ������������ :" << endl;
		cout << "-----------------------------------" << endl;
		fstream file_read("GuestsLab.dat", ios::in | ios::binary);//���������� �� ����� ������� �������� ������������
		
		do
		{
			cout << "���������� ������� ����� :" << endl;
			//cin.ignore();
			gets_s(temp);

			if (!file_read.is_open())
			{
				file_absence = true;
			}
			else
			{
				file_read.seekg(0, ios::end);
				int size_of_file_in_bytes = file_read.tellg();
				int size_of_array = size_of_file_in_bytes / sizeof(Guest);// ����������� ������� �������

				Guest *p = new Guest[size_of_array];
				if_log_exist = false;
				
				file_read.seekg(0, ios::beg);
				for (int k = 0; k < size_of_array; k++) {
					Guest * _temp_ = new Guest;
					file_read.read((char*)_temp_, sizeof(Guest));
					*(p + k) = *_temp_;//���������� ���������� ������� ������� �� �����
					delete _temp_;
				}
				

				for (int i = 0; i < size_of_array; i++)
				{
					if (!strcmp(DeCodingStr((char *)p->GetGuestLogin()).c_str(), temp))//�������� �� ������� ������� ���������� ������ � �������
					{
						cout << "��������, ������ ����� ��� ������������!" << endl;
						if_log_exist = true;
						break;
					}
				}
				delete[] p;
			}
		} while (if_log_exist);
		file_read.close();

				myguest->SetGLogin((char *)CodingStr(temp).c_str());//���������� ������� ������������ ������ ��������
				cout << "����������, ������� ������:" << endl;
				gets_s(temp);
				myguest->SetGPass((char *)CodingStr(temp).c_str());
				cout << "����������, ������� �������:" << endl;
				gets_s(temp);
				myguest->SetGSurname(temp);
				cout << "����������, ������� ���:" << endl;
				gets_s(temp);
				myguest->SetGName(temp);
				cout << "����������, ������� �����:" << endl;
				gets_s(temp_address);
				myguest->SetGAddress(temp_address);
				cout << "����������, ������� ����� �������� :" << endl;
				gets_s(temp);
				myguest->SetGPhone(temp);
				myguest->SetGIsRegistered(true);
								
				if (file_absence)
				{
					fstream file_write("GuestsLab.dat", ios::out | ios::trunc | ios::binary);//������ � ����, ���� ��� ������ ������
					if (!file_write.is_open())
					{cout << "Error to open for writing!" << endl;	}
					file_write.write((char*)(myguest), sizeof(Guest));
					file_write.flush();
					file_write.close();
				}
				if (!file_absence)
				{
					fstream file_read("GuestsLab.dat", ios::in | ios::binary);//� ������ ���� ������������ ��� ������, 
					file_read.seekg(0, ios::end);								//��������� ������ �� �����, ���������� ������ ������� � �������� �� ���� ������� ������.
					int size_of_file_in_bytes = file_read.tellg();
					int size_of_array = size_of_file_in_bytes / sizeof(Guest);

					Guest *p = new Guest[size_of_array+1];//�������� �� ���� ������� ������
					file_read.seekg(0, ios::beg);
					for (int k = 0; k < size_of_array; k++) {
						Guest * _temp_ = new Guest;
						file_read.read((char*)_temp_, sizeof(Guest));
						*(p + k) = *_temp_;
						delete _temp_;
					}
					p[size_of_array] = *myguest;
					file_read.close();
					
					fstream file_write("GuestsLab.dat", ios::out | ios::trunc | ios::binary);
					if (!file_write.is_open())
					{
						cout << "Error to open for writing!" << endl;
					}
					
					for (int k = 0; k < size_of_array+1; k++)
					{
						file_write.write((char*)(p + k), sizeof(Guest));
					}
					file_write.flush();
					file_write.close();
					delete[] p;
				}
				
				delete myguest;
				cout << "�����������, ����������� ������ �������!" << endl; 
				Sleep(3000);
	}
	
	//-----------------------------
	
	void DeleteGuestAcc()// �������� �������� ������������
	{
		char templog[50], temppass[50];
		bool if_acc_deleted = false;
		
		fstream file_read("GuestsLab.dat", ios::in | ios::binary);
		if (!file_read.is_open())
		{	file_read.close();
			cout << "������������ ��� �� �������!" << endl;	Sleep(3000); return;	}

		file_read.seekg(0, ios::end);
		int size_of_file_in_bytes = file_read.tellg();
		int size_of_array = size_of_file_in_bytes / sizeof(Guest);

		Guest *p = new Guest[size_of_array];
		file_read.seekg(0, ios::beg);
		for (int k = 0; k < size_of_array; k++) {
			Guest * _temp_ = new Guest;
			file_read.read((char*)_temp_, sizeof(Guest));
			*(p + k) = *_temp_;
			delete _temp_;
		}
		file_read.close();

		for (int i = 0; i < size_of_array; i++)
		{VectGuests.push_back(p[i]);	}
		delete[] p;
		
		do
		{
			cout << "������� ����� ��� �������� : ";
			//cin.ignore();
			gets_s(templog);
			cout << "������� ������ ������������ : ";
			gets_s(temppass);
			
			if (!strcmp("0", templog) && !strcmp("0", temppass))
			{
				if_acc_deleted = true;
				AdminMenu_1_1(); 
			}
			for (int i = 0; i < VectGuests.size(); i++)//�������� ���������� ������ � ������� �� ������� � ����, ����� ���������.
			{
				if (!strcmp(DeCodingStr((char *)VectGuests.at(i).GetGuestLogin()).c_str(), templog)  &&
					!strcmp(DeCodingStr((char *)VectGuests.at(i).GetGuestPass()).c_str(), temppass))
				{
					VectGuests.erase(VectGuests.begin() + i);
					if_acc_deleted = true; break;
				}
				
			}
			if (!if_acc_deleted)
			{
				cout << "��������, ��������� ������ �� ������������� ������ ��� ������!" << endl;
				cout << "��������� ������� ��� ������� <<0>> ��� ������!" << endl;
				Sleep(3000);
			}

		} while (!if_acc_deleted);
		
		p = new Guest[VectGuests.size()];
		for (int i = 0; i < VectGuests.size(); i++)
		{
			*(p+i) = VectGuests.at(i);
		}
		

		fstream file_write("GuestsLab.dat", ios::out | ios::trunc | ios::binary);
		if (!file_write.is_open())
		{	cout << "Error to open for writing!" << endl;
		}

		for (int k = 0; k < VectGuests.size(); k++)
		{
			file_write.write((char*)(p + k), sizeof(Guest));
		}
		file_write.flush();
		file_write.close();
		delete[]p;
		VectGuests.clear();
		cout << "������� ������������ ��� ������� ������!"<<endl;
		Sleep(3000);
		AdminMenu_1_1();
	}
	//-------------------------
	
	void CreateCategory()//�������� ��������� / �������� 
	{
		char temp[50];
		bool if_subj_avail = false;
		cout << "\n��������� � ������� ��������� :" << endl;

		fstream file_read("SubjLab.dat", ios::in | ios::binary);//�������� � ���������� �� ����� ������� ��� � ���������� ��������� / ���������
		if (!file_read.is_open())
		{
			file_read.close();
			cout << "� ������� ��� ��� ���������..." << endl;
			cout << "\n������� �������� �������� ��� ������������ : ";
			//cin.ignore();
			gets_s(temp);
			for (int i = 0; i < 50; i++) temp[i] = toupper(temp[i]);
			fstream file_write("SubjLab.dat", ios::out | ios::trunc | ios::binary);
			if (!file_write.is_open())
			{
				cout << "Error to open for writing!" << endl;
			}
			file_write.write(temp, sizeof(char) * 50);
			file_write.close();
			cout << "��������� / ������� ������� �������!" << endl;

		}
		else
		{
			file_read.seekg(0, ios::end);
			int size_of_file_in_bytes = file_read.tellg();
			int size_of_array = size_of_file_in_bytes / (sizeof(char) * 50);

			file_read.seekg(0, ios::beg);
			for (int k = 0; k < size_of_array; k++) {
				char _temp_[50];
				strcpy(_temp_, "");
				file_read.read(_temp_, sizeof(char) * 50);
				strcpy(subjectslab[k], _temp_);

			}
			file_read.close();


			for (int i = 0; i < size_of_array; i++)
				cout << "No " << i << "  " << subjectslab[i] << endl;

			do {
				if_subj_avail = false;
				cout << "\n������� �������� �������� ��� ������������ : ";
				//cin.ignore();
				gets_s(temp);
				for (int i = 0; i < 50; i++) temp[i] = toupper(temp[i]);
				for (int i = 0; i < size_of_array; i++)
				{
					if (strcmp(subjectslab[i], temp) == 0)
					{
						cout << "��������, ��������� " << subjectslab[i] << " ��� �������!" << endl;
						cout << "�������� ������ ��������� ��������!" << endl;
						if_subj_avail = true;

					}
				}
			} while (if_subj_avail);

			strcpy(subjectslab[size_of_array], temp);


			fstream file_write("SubjLab.dat", ios::out | ios::trunc | ios::binary);
			if (!file_write.is_open())
			{
				cout << "Error to open for writing!" << endl;
			}
			for (int k = 0; k < size_of_array + 1; k++)
			{
				file_write.write((subjectslab[k]), sizeof(char) * 50);
			}
			file_write.flush();
			file_write.close();
			cout << "��������� / ������� ������� �������!" << endl;

		}
	}

				
	void CreateTest()//�������� �����
{
	char temp[50];
	char temp_coice;
	char test_name_temp[50];
	char test_name_temp_index[10];
	
	cout << "���������� �����.." << endl;
	cout << "��������� � ������� ��������� / �������� :" << endl;
	
	fstream file_read("SubjLab.dat", ios::in | ios::binary); // �������� � ���������� ������� ��� ���������.
	if (!file_read.is_open())
	{	cout << "������ ��� �������� �����!" << endl;	}
	else
	{
		file_read.seekg(0, ios::end);
		int size_of_file_in_bytes = file_read.tellg();
		int size_of_array = size_of_file_in_bytes / (sizeof(char) * 50); //����������� ������� �������

		file_read.seekg(0, ios::beg);
		for (int k = 0; k < size_of_array; k++) {
			char _temp_[50];
			file_read.read(_temp_, sizeof(char) * 50);
			strcpy(subjectslab[k], _temp_);// ������ ����� � ������ ��� ������

		}
		file_read.close();

		for (int i = 0; i < size_of_array; i++)
			cout << "No " << i << "  " << subjectslab[i] << endl;// ����� �� ����� ��������� ��������� /���������

		cout << "������� ����� �������� ��� ���������� ����� :" << endl;//����������� ������������� ��������
		cout << "������� ��� �������� ����������� �������� - 9 :";
		for (;;) {
		cin >> temp_coice; cin.ignore(100, '\n');
			if (temp_coice == '9' || ((temp_coice - '0' >= 0) && (temp_coice - '0' < size_of_array)))
				break;
			else 
				cout << "�������� ���������� �����!" << endl; 
		}

		if (temp_coice == '9')
		{
			Sleep(2000);
			AdminMenu_1_3();
		}

		if ((temp_coice - '0' >= 0) && (temp_coice - '0' < size_of_array))
		{
			fstream file_read("TestsLab.dat", ios::in | ios::binary);//���� ���� �� �����������, ������ ������ ��� ���..
			if (!file_read.is_open())
			{
				file_read.close();
				cout << "� �������� ��� ��� ������..." << endl;
				Test * firstsign = new Test;
				strcpy(test_name_temp, "");
				strcat(test_name_temp, subjectslab[temp_coice - '0']);//�������� ����� �����
				strcat(test_name_temp, "-");
				strcat(test_name_temp, "1");
				//itoa( test3,  test3_ch, 10 ); 
				firstsign->SetTest(subjectslab[temp_coice - '0'], test_name_temp);
				fstream file_write("TestsLab.dat", ios::out | ios::trunc | ios::binary);
				if (!file_write.is_open())
				{	cout << "Error to open for writing!" << endl;}
				file_write.write((char*)firstsign, sizeof(Test));
				file_write.close();
				delete[]firstsign;
				cout << "���� ������� ������!" << endl;
			}
			else
			{
				file_read.seekg(0, ios::end);
				int size_of_file_in_bytes = file_read.tellg();
				int size_of_array = size_of_file_in_bytes / sizeof(Test);//���� ���� ������, ��������� ������, ���������� ������ �������

				Test *p = new Test[size_of_array];
				file_read.seekg(0, ios::beg);
				for (int k = 0; k < size_of_array; k++) {
					Test * _temp_ = new Test;
					file_read.read((char*)_temp_, sizeof(Test));//���������� ������ � ������ �������� ������ ����
					*(p + k) = *_temp_;
					delete _temp_;
				}
				file_read.close();

				for (int i = 0; i < size_of_array; i++)// ��� ����������� ������, ��������� ������ ������� �� ������� ��������
				{	VectTests.push_back(p[i]);	}
				
				mytestobj = new Test; // ������� ������ ������ ����
				strcpy(test_name_temp, ""); // ��������� ���������� �������� �����
				strcat(test_name_temp, subjectslab[temp_coice - '0']);
				strcat(test_name_temp, "-");
				itoa((size_of_array+1), test_name_temp_index, 10);
				strcat(test_name_temp, test_name_temp_index);
				mytestobj ->SetTest(subjectslab[temp_coice - '0'], test_name_temp); // ������ ������ �� ������� �����
				VectTests.push_back(*mytestobj);//���������� ������� ������ � ����� �������

				Test *p_out = new Test[VectTests.size()];//��� ������ � ����, �������� ������ ��� ������ ��������, ���������� ���������� ����� ������ �������

				for (int i = 0; i < VectTests.size(); i++)
				{	*(p_out + i) = VectTests.at(i);	}

				fstream file_write("TestsLab.dat", ios::out | ios::trunc | ios::binary);
				if (!file_write.is_open())
				{	cout << "Error to open for writing!" << endl;	}
				for (int k = 0; k < VectTests.size(); k++)
				{
					file_write.write((char*)(p_out + k), sizeof(Test));//���������� ������ � ����
				}
				file_write.flush();
				file_write.close();
				
				delete[]p;
				delete[]mytestobj;
				delete[]p_out;
				cout << "���� ������� ��������!" << endl;

			}
		}
		Sleep(5000);
		AdminMenu_1_3();

	}
	
}
//--------------------------------------------------------------------------------

	void TestPassing(char * guest_login_stat)//����������� �����
	{
		char temp[50];
		char temp_coice;
		srand(time(0));
		cout << "������������..." << endl;
		cout << "��������� � ������� ��������� / �������� :" << endl;

		fstream file_read("SubjLab.dat", ios::in | ios::binary);//���������� ������� ��������� �� �����
		if (!file_read.is_open())
		{
			cout << "��������� / �������� ��� �� �������!!" << endl;
			Sleep(5000); AdminMenu_1_3();
		}
		else
		{
			file_read.seekg(0, ios::end);
			int size_of_file_in_bytes = file_read.tellg();
			int size_of_array = size_of_file_in_bytes / (sizeof(char) * 50);

			file_read.seekg(0, ios::beg);
			for (int k = 0; k < size_of_array; k++) {
				char _temp_[50];
				file_read.read(_temp_, sizeof(char) * 50);
				strcpy(subjectslab[k], _temp_);

			}
			file_read.close();

			for (int i = 0; i < size_of_array; i++)
				cout << "No " << i << "  " << subjectslab[i] << endl;//����� �� ����� ��������� ���������

			cout << "������� ����� �������� ��� ������ ���� ������ �� ��������:" << endl;
			cout << "��� ������ � ���������� ���� - 9 : ";
			for (;;) {
				cin >> temp_coice; cin.ignore(100, '\n');
				if (temp_coice == '9' || ((temp_coice - '0' >= 0) && (temp_coice - '0' < size_of_array)))
					break;
				else
					cout << "�������� ���������� �����!" << endl;
			}

			if (temp_coice == '9')
			{
				Sleep(2000);
				AdminMenu_1_3();
			}

			if ((temp_coice - '0' >= 0) && (temp_coice - '0' < size_of_array))
			{
				fstream file_read("TestsLab.dat", ios::in | ios::binary);//���� ������������ ������ ����� � ������ �������, 
				if (!file_read.is_open())								// ��������� ���� ������ 
				{
					file_read.close();
					cout << "� ������� ��� ��� ������..." << endl;
					Sleep(2000);
					AdminMenu_1_3();

				}
				else
				{
					file_read.seekg(0, ios::end);
					int size_of_file_in_bytes = file_read.tellg();
					int size_of_array = size_of_file_in_bytes / sizeof(Test); // ��������� ������ ������� �������� ����

					Test *p = new Test[size_of_array];
					file_read.seekg(0, ios::beg);
					for (int k = 0; k < size_of_array; k++) {
						Test * _temp_ = new Test;
						file_read.read((char*)_temp_, sizeof(Test));
						*(p + k) = *_temp_;
						delete _temp_;
					}
					file_read.close();

					for (int i = 0; i < size_of_array; i++)
					{
						if (!strcmp((p + i)->GetTestSubjName(), subjectslab[temp_coice - '0']))//������ �������� � ������ ��� ����������� �����
							VectTests.push_back(p[i]);
					}
					delete[]p;

					for (int i = 0; i < VectTests.size(); i++)//����� �� ����� ������ ��� ����������� ����� ���� ������
					{
						cout << "\n����� ����� " << i << ":" << endl;
						cout << "-------------------------------------------------------------------" << endl;
						VectTests.at(i).DisplayTest();
					}
					cout << "������� ����� ����� ����������� :" << endl;

					for (;;) {
						cin >> temp_coice; 
						if ((temp_coice - '0' >= 0) && (temp_coice - '0' < VectTests.size()))
							break;
						else
							cout << "�������� ���������� �����!" << endl;
					}
					//--------------------------------------------------------------
					
					Statistic * my_test_stat = new Statistic;//�������� ������� ������ ����������
					//--------------------------------------------------------------
					char temp_answ1, temp_answ2;
					int counter_corr_answ = 0;
					int temp_test_rate = 0;
					cout << "������������..." << endl;
					VectTests.at(temp_coice - '0').DisplayTestForPassing();// test in work
					cout << "\n������� ����� ���������� ������ �� ������ �1 :" << endl; //������ �� ������� �� ���������� �����
					for (;;) {
						cin >> temp_answ1; 
						if ((temp_answ1 - '0' > 0) && (temp_answ1 - '0' <= 4))
							break;
						else
							cout << "�������� ���������� �����!" << endl;
					}
					cout << "������� ����� ���������� ������ �� ������ �2 :" << endl;
					for (;;) {
						cin >> temp_answ2; cin.ignore(100, '\n');
						if ((temp_answ2 - '0' > 0) && (temp_answ2 - '0' <= 4))
							break;
						else
							cout << "�������� ���������� �����!" << endl;
					}
					
					cout << "-------------------------------------------" << endl;//����� �� ����� ����������� ����� �����
					cout << "��������� �� ������� ����� :" << endl;

					cout << "����� �� ������ �1 :" << endl;
					int temp_c = 0;
					for (int i = 0; i < 4; i++)
					{
						if (!strcmp(VectTests.at(temp_coice - '0').GetQuestArr()[0].answers_arr[i],
							VectTests.at(temp_coice - '0').temp_answ_arr1[temp_answ1 - '0' - 1]	)	)
							temp_c = i; //break;
					}
					
					if (VectTests.at(temp_coice - '0').GetQuestArr()[0].correct_answ_arr[temp_c] == true )
					{
						cout << "�����!" << endl;
						counter_corr_answ++;	
					}
					else cout << "�� �����!" << endl;
					
					cout << "����� �� ������ �2 :" << endl;
					
					for (int i = 0; i < 4; i++)
					{
						if (!strcmp(VectTests.at(temp_coice - '0').GetQuestArr()[1].answers_arr[i],
							VectTests.at(temp_coice - '0').temp_answ_arr2[temp_answ2 - '0' - 1]))
							temp_c = i; //break;
					}

					if (VectTests.at(temp_coice - '0').GetQuestArr()[1].correct_answ_arr[temp_c] == true)
					{
						cout << "�����!" << endl;
						counter_corr_answ++;
					}
					else cout << "�� �����!" << endl;


					cout << "���������� ������ ������� : "<< counter_corr_answ<<" ! "<< endl;
					
					cout << "������ �� ������� ����� : " << endl;
					if (counter_corr_answ == 0)
					{
						temp_test_rate = 2;
						cout << temp_test_rate <<" �����!" << endl;
					}
					if (counter_corr_answ == 1)
					{
						temp_test_rate = 6; 
						cout << temp_test_rate <<" ������!" << endl;
					}
					if (counter_corr_answ == 2)
					{
						temp_test_rate = 11; 
						cout << temp_test_rate <<" ������!" << endl;
					}
										
					cout << "-------------------------------------------" << endl;
				strcpy((char *)CodingStr(my_test_stat->stat_guest_login).c_str(), guest_login_stat);//������ ������ �� ����������� ����� � ������ ����������
				strcpy(my_test_stat->stat_subject_name, subjectslab[temp_coice - '0']);
				strcpy(my_test_stat->stat_test_name, VectTests.at(temp_coice - '0').GetTestName());	
				my_test_stat->correct_answ_qty = counter_corr_answ;
				my_test_stat->test_rate = temp_test_rate;
				my_test_stat->complete_test = true;	
				
				
				fstream file_read("StatLab.dat", ios::in | ios::binary);//������ ������� �������� ���������� � ����
					if (!file_read.is_open())
					{
						file_read.close();
						fstream file_write("StatLab.dat", ios::out | ios::trunc | ios::binary);
						if (!file_write.is_open())
						{
							cout << "Error to open for writing!" << endl;
						}
						file_write.write((char*)(my_test_stat), sizeof(Statistic));
						file_write.flush();
						file_write.close();
					}
					else {
						file_read.seekg(0, ios::end);
						int size_of_file_in_bytes = file_read.tellg();
						int size_of_array = size_of_file_in_bytes / sizeof(Statistic);

						Statistic *p_stat = new Statistic[size_of_array];
						file_read.seekg(0, ios::beg);
						for (int k = 0; k < size_of_array; k++) {
							Statistic * _temp_ = new Statistic;
							file_read.read((char*)_temp_, sizeof(Statistic));
							*(p_stat + k) = *_temp_;
							delete _temp_;
						}
						file_read.close();

						for (int i = 0; i < size_of_array; i++)
						{
							StatVectAdmin.push_back(p_stat[i]);
						}
						delete[] p_stat;
					}
					StatVectAdmin.push_back(*my_test_stat);
					Statistic *p_stat = new Statistic[StatVectAdmin.size()];
					
					for (int i = 0; i < StatVectAdmin.size(); i++)
					*(p_stat + i) = StatVectAdmin.at(i);
					
					// statistic record
					fstream file_write("StatLab.dat", ios::out | ios::trunc | ios::binary);
					if (!file_write.is_open())
					{	cout << "Error to open for writing!" << endl;}

					for (int k = 0; k < StatVectAdmin.size(); k++)
					{
						file_write.write((char*)(p_stat + k), sizeof(Statistic));
					}
					file_write.flush();
					file_write.close();
						
					delete[] p_stat;
				}
			}
		}
	}

	
	void ShowStatisticForGuest(char * guest_login_stat)// ����� ���������� �� ������������� ������������
	{
		char temp[50];
		char temp_coice;
		int pass_tests_counter = 0, correct_answ_counter = 0, aver_rate_counter = 0;
		bool test_passed = false;
		cout << "���������� ������������..." << endl;
		cout << "\n��������� � ������� ��������� / �������� :" << endl;

		fstream file_read("SubjLab.dat", ios::in | ios::binary);
		if (!file_read.is_open())
		{
			cout << "��������� / �������� ��� �� �������!!" << endl;
			Sleep(5000); GuestMenu_1();
		}
		else
		{
			file_read.seekg(0, ios::end);
			int size_of_file_in_bytes = file_read.tellg();
			int size_of_array = size_of_file_in_bytes / (sizeof(char) * 50);

			file_read.seekg(0, ios::beg);
			for (int k = 0; k < size_of_array; k++) {
				char _temp_[50];
				file_read.read(_temp_, sizeof(char) * 50);
				strcpy(subjectslab[k], _temp_);

			}
			file_read.close();

			for (int i = 0; i < size_of_array; i++)
				cout << "No " << i << "  " << subjectslab[i] << endl;

			cout << "������� ����� �������� ��� ������ ���� ���������� �� ��������:" << endl;
			cout << "��� ������ � ���������� ���� - 9 : ";
			for (;;) {
				cin >> temp_coice;cin.ignore(100, '\n');
				if (temp_coice == '9' || ((temp_coice - '0' >= 0) && (temp_coice - '0' < size_of_array)))
					break;
				else
					cout << "�������� ���������� �����!" << endl;
			}

			if (temp_coice == '9')
			{
				Sleep(2000);
				GuestMenu_1();
			}

			if ((temp_coice - '0' >= 0) && (temp_coice - '0' < size_of_array))
			{
				fstream file_read("StatLab.dat", ios::in | ios::binary);
				if (!file_read.is_open())
				{
					file_read.close();
					cout << "� ������� ��� ��� ����������..." << endl;
					Sleep(2000);
					GuestMenu_1();

				}
				else
				{
					file_read.seekg(0, ios::end);
					int size_of_file_in_bytes = file_read.tellg();
					int size_of_array = size_of_file_in_bytes / sizeof(Statistic);

					Statistic *p = new Statistic[size_of_array];
					file_read.seekg(0, ios::beg);
					for (int k = 0; k < size_of_array; k++) {
						Statistic * _temp_ = new Statistic;
						file_read.read((char*)_temp_, sizeof(Statistic));
						*(p + k) = *_temp_;
						delete _temp_;
					}
					file_read.close();

					for (int i = 0; i < size_of_array; i++)
					{
						if (!strcmp(DeCodingStr((p + i)->stat_guest_login).c_str(), guest_login_stat))
							StatVectAdmin.push_back(p[i]);
					}
					delete[]p;

					cout << "-------------------------------------------------------------------" << endl;
					cout << "���������� ������������ �� �������� " << subjectslab[temp_coice - '0'] << endl;


					int pass_tests_counter = 0, correct_answ_counter = 0, aver_rate_counter = 0;
					bool test_passed = false;

					for (int i = 0; i < StatVectAdmin.size(); i++)
					{
						if (!strcmp(StatVectAdmin.at(i).stat_subject_name, subjectslab[temp_coice - '0']) &&
							StatVectAdmin.at(i).complete_test == true)
						{
							correct_answ_counter = correct_answ_counter + StatVectAdmin.at(i).correct_answ_qty;
							aver_rate_counter = aver_rate_counter + StatVectAdmin.at(i).test_rate;
							pass_tests_counter++;
							test_passed = true;
						}
					}
					if (test_passed == true)
					{
						cout << "\n���������� ���������� ������ : " << pass_tests_counter << endl;
						cout << "���������� ������ �������    : " << correct_answ_counter << endl;
						cout << "\n������� ������ �� ��������   : " << aver_rate_counter / pass_tests_counter << endl;
						cout << "-------------------------------------------------------------------" << endl;
					}
					else
					{
						cout << "\n�� ������� �������� ��� ��� ����������!" << endl;
						cout << "-------------------------------------------------------------------" << endl;
					}

					//--------------------------------------------------------------
				//Sleep(5000); AdminMenu_1_3();
				}
			}
		}
		
	}
	void ShowStatisticForAdminCategory()//����� ���������� �� ������������� ��������
	{
		char temp[50];
		char temp_coice;
		int tests_counter, aver_rate_counter = 0;
		vector<Statistic>StatVectAdmin_Temp;
		cout << "���������� ��������������..." << endl;
		cout << "\n��������� � ������� ��������� / �������� :" << endl;

		fstream file_read("SubjLab.dat", ios::in | ios::binary);
		if (!file_read.is_open())
		{
			cout << "��������� / �������� ��� �� �������!!" << endl;
			Sleep(5000); AdminMenu_1_3();
		}
		else
		{
			file_read.seekg(0, ios::end);
			int size_of_file_in_bytes = file_read.tellg();
			int size_of_array = size_of_file_in_bytes / (sizeof(char) * 50);

			file_read.seekg(0, ios::beg);
			for (int k = 0; k < size_of_array; k++) {
				char _temp_[50];
				file_read.read(_temp_, sizeof(char) * 50);
				strcpy(subjectslab[k], _temp_);

			}
			file_read.close();

			for (int i = 0; i < size_of_array; i++)
				cout << "No " << i << "  " << subjectslab[i] << endl;

			cout << "������� ����� �������� ��� ������ ���� ���������� �� ��������:" << endl;
			cout << "��� ������ � ���������� ���� - 9 : ";
			for (;;) {
				cin >> temp_coice;cin.ignore(100, '\n');
				if (temp_coice == '9' || ((temp_coice - '0' >= 0) && (temp_coice - '0' < size_of_array)))
					break;
				else
					cout << "�������� ���������� �����!" << endl;
			}

			if (temp_coice == '9')
			{
				Sleep(2000);
				AdminMenu_1_3();
			}

			if ((temp_coice - '0' >= 0) && (temp_coice - '0' < size_of_array))
			{
				fstream file_read("StatLab.dat", ios::in | ios::binary);
				if (!file_read.is_open())
				{
					file_read.close();
					cout << "� ������� ��� ��� ����������..." << endl;
					Sleep(2000);
					AdminMenu_1_3();

				}
				else
				{
					file_read.seekg(0, ios::end);
					int size_of_file_in_bytes = file_read.tellg();
					int size_of_array = size_of_file_in_bytes / sizeof(Statistic);

					Statistic *p = new Statistic[size_of_array];
					file_read.seekg(0, ios::beg);
					for (int k = 0; k < size_of_array; k++) {
						Statistic * _temp_ = new Statistic;
						file_read.read((char*)_temp_, sizeof(Statistic));
						*(p + k) = *_temp_;
						delete _temp_;
					}
					file_read.close();

					for (int i = 0; i < size_of_array; i++)
					{
						if (!strcmp((p + i)->stat_subject_name, subjectslab[temp_coice - '0']))
							StatVectAdmin.push_back(p[i]);
					}
					delete[]p;

					cout << "-------------------------------------------------------------------" << endl;
					cout << "���������� �������������� �� �������� " << subjectslab[temp_coice - '0'] << endl;//����� �� ����� ���������� �� ������������

					for (int i = 0; i<StatVectAdmin.size(); i++)//����� �������� � ������ �� � ������ �� ������������� ������������
					{
						bool flag = false;
						for (int j = StatVectAdmin.size() - 1; j>i; j--)
						{
							if (!strcmp(StatVectAdmin.at(i).stat_guest_login, StatVectAdmin.at(j).stat_guest_login))
							{
								flag = true;
							}
						}
						if (!flag)
						{
							StatVectAdmin_Temp.push_back(StatVectAdmin.at(i));
						}
					}
										
					if (StatVectAdmin.size())
					{
						cout << "-------------------------------------------------------------------" << endl;
						cout << "\n���������� ���������� ������ : " << StatVectAdmin.size() << endl;
						for (int i = 0; i < StatVectAdmin_Temp.size(); i++)
						{
							tests_counter = 0;
							cout << "���������� ���������� ������ ������������ � ������� : " << DeCodingStr(StatVectAdmin_Temp.at(i).stat_guest_login) << endl;
							for (int j = 0; j < StatVectAdmin.size(); j++)
							{
								if (!strcmp(StatVectAdmin_Temp.at(i).stat_guest_login, StatVectAdmin.at(j).stat_guest_login))
									tests_counter++;
							}
							cout << tests_counter << " ��." <<endl;

						}
						
						for (int i = 0; i< StatVectAdmin.size(); i++)
						{	aver_rate_counter = aver_rate_counter + StatVectAdmin.at(i).test_rate;					
						}
						cout << "������� ���� �� ���������� ������ : ";
						cout << aver_rate_counter / tests_counter << " ������."<< endl;
						cout << "-------------------------------------------------------------------" << endl;
					}
					else
					{
						cout << "\n�� ������� �������� ��� ��� ����������!" << endl;
						cout << "-------------------------------------------------------------------" << endl;
					}
										
					Sleep(3000); 
				}
			}
		}
	}
	
	void ShowStatisticForAdminTest()//����� ���������� �� ������������� �����.
	{
		char temp[50];
		char temp_coice;
		int tests_counter = 0;
		vector<string>VectTempLogins;
		cout << "���������� ��������������..." << endl;
		
		fstream file_read("TestsLab.dat", ios::in | ios::binary);//���������� ������ �� ��������� ������
		if (!file_read.is_open())
		{
			file_read.close();
			cout << "� ������� ��� ��� ������..." << endl;
			Sleep(2000);
			AdminMenu_1_3();

		}
		else
		{
			file_read.seekg(0, ios::end);
			int size_of_file_in_bytes = file_read.tellg();
			int size_of_array = size_of_file_in_bytes / sizeof(Test);

			Test *p = new Test[size_of_array];
			file_read.seekg(0, ios::beg);
			for (int k = 0; k < size_of_array; k++) {
				Test * _temp_ = new Test;
				file_read.read((char*)_temp_, sizeof(Test));
				*(p + k) = *_temp_;
				delete _temp_;
			}
			file_read.close();

			for (int i = 0; i < size_of_array; i++)
			{	VectTests.push_back(p[i]);	}
		}
		cout << "��������� ����� :" << endl;
		for (int i = 0; i < VectTests.size(); i++)
		{
			cout << "No "<<i<<"  "<<VectTests.at(i).GetTestName() << endl;//����� ������ �� ������� � �������� �����
		}
		
			cout << "������� ����� ����� ��� ������ ����������:" << endl;//����������� �� ������ ������ ����� ���������� ����������
			cout << "��� ������ � ���������� ���� - n : ";
			for (;;) {
				cin >> temp_coice;cin.ignore(100, '\n');
				if (temp_coice == 'n' || ((temp_coice - '0' >= 0) && (temp_coice - '0' < VectTests.size())))
					break;
				else
					cout << "�������� ���������� �����!" << endl;
			}

			if (temp_coice == 'n')
			{
				Sleep(2000);
				AdminMenu_1_3();
			}

			if ((temp_coice - '0' >= 0) && (temp_coice - '0' < VectTests.size()))
			{
				fstream file_read("StatLab.dat", ios::in | ios::binary);
				if (!file_read.is_open())
				{
					file_read.close();
					cout << "� ������� ��� ��� ����������..." << endl;
					Sleep(2000);
					AdminMenu_1_3();

				}
				else
				{
					file_read.seekg(0, ios::end);
					int size_of_file_in_bytes = file_read.tellg();
					int size_of_array = size_of_file_in_bytes / sizeof(Statistic);

					Statistic *p = new Statistic[size_of_array];
					file_read.seekg(0, ios::beg);
					for (int k = 0; k < size_of_array; k++) {
						Statistic * _temp_ = new Statistic;
						file_read.read((char*)_temp_, sizeof(Statistic));
						*(p + k) = *_temp_;
						delete _temp_;
					}
					file_read.close();

					for (int i = 0; i < size_of_array; i++)
					{	StatVectAdmin.push_back(p[i]);	}
					delete[]p;

					cout << "-------------------------------------------------------------------" << endl;
					cout << "���������� �� ����� : " << VectTests.at(temp_coice - '0').GetTestName() << endl;
					
					for (int i = 0; i < StatVectAdmin.size(); i++)
					{
						if (!strcmp(StatVectAdmin.at(i).stat_test_name, VectTests.at(temp_coice - '0').GetTestName()))
						{
							tests_counter++;
						}
						
					}
				
					for (int i = 0; i<StatVectAdmin.size(); i++)
					{
						bool flag = false;
						for (int j = StatVectAdmin.size() - 1; j>i; j--)
						{
							if (!strcmp(StatVectAdmin.at(i).stat_guest_login, StatVectAdmin.at(j).stat_guest_login))
							{
								flag = true;
							}
						}
						if (!flag)
						{
							VectTempLogins.push_back(StatVectAdmin.at(i).stat_guest_login);
						}
					}

					
						cout << "-------------------------------------------------------------------" << endl;
						cout << "\n���������� ���������� ������ : " << tests_counter << endl;
						
						for (int i = 0; i < VectTempLogins.size(); i++)
						{
							tests_counter = 0;
							cout << "���������� ���������� ������ ������������ � ������� : " << DeCodingStr((char *)VectTempLogins.at(i).c_str()) << endl;
							for (int j = 0; j < StatVectAdmin.size(); j++)
							{
								if (!strcmp(VectTempLogins.at(i).c_str(), StatVectAdmin.at(j).stat_guest_login))
									tests_counter++;
							}
							cout << tests_counter << " ��." << endl;

						}
						cout << "��������� ������������ � �������� ����� ���� ���� 10 : "<<endl;
						bool higher_then_10 = false;
						for (int i = 0; i< StatVectAdmin.size(); i++)
						{
							if (StatVectAdmin.at(i).test_rate > 10)
							{
								cout << DeCodingStr(StatVectAdmin.at(i).stat_guest_login) << " : " << StatVectAdmin.at(i).test_rate << " ������" << endl;
								higher_then_10 = true;
							}
						}
					if (!higher_then_10) cout << "��� ������� ���� 10 ������! " << endl;
						cout << "-------------------------------------------------------------------" << endl;
					
					Sleep(3000);
				}
			}
		}
	
	void ShowStatisticForAdminbyGuest()//����� ���������� �� ������������� ������������
	{
		char temp[50];
		char temp_coice;
		int tests_counter = 0;
		int avar_rate;
		vector<string>VectTempSubj;
		
		cout << "���������� �������������� �� ������������� ������������..." << endl;

		fstream file_read("GuestsLab.dat", ios::in | ios::binary);
				
		file_read.seekg(0, ios::end);
		int size_of_file_in_bytes = file_read.tellg();
		int size_of_array = size_of_file_in_bytes / sizeof(Guest);

		Guest *p = new Guest[size_of_array];
		file_read.seekg(0, ios::beg);
		for (int k = 0; k < size_of_array; k++) {
			Guest * _temp_ = new Guest;
			file_read.read((char*)_temp_, sizeof(Guest));
			*(p + k) = *_temp_;
			delete _temp_;
		}

		for (int i = 0; i < size_of_array; i++)
		{
			VectGuests.push_back(p[i]);
		}
		delete[] p;
			
		file_read.close();
		cout << "��������� � ���� ������ ������������� :" <<endl;
		for (int i = 0; i < VectGuests.size(); i++)
		{
			cout << "No" << i << " - " << DeCodingStr((char *)VectGuests.at(i).GetGuestLogin()).c_str() << " ; ";
		}
		
		//----------------------------------------------------------------------------

		cout << "������� ���������� � ������������ ��� ������ ����������:" << endl;
		cout << "��� ������ � ���������� ���� - n : ";
		for (;;) {
			cin >> temp_coice;cin.ignore(100, '\n');
			if (temp_coice == 'n' || ((temp_coice - '0' >= 0) && (temp_coice - '0' < VectGuests.size())))
				break;
			else
				cout << "�������� ���������� �����!" << endl;
		}

		if (temp_coice == 'n')
		{
			Sleep(2000);
			AdminMenu_1_3();
		}

		if ((temp_coice - '0' >= 0) && (temp_coice - '0' < VectGuests.size()))
		{
			fstream file_read("StatLab.dat", ios::in | ios::binary);
			if (!file_read.is_open())
			{
				file_read.close();
				cout << "� ������� ��� ��� ����������..." << endl;
				Sleep(2000);
				AdminMenu_1_3();

			}
			else
			{
				file_read.seekg(0, ios::end);
				int size_of_file_in_bytes = file_read.tellg();
				int size_of_array = size_of_file_in_bytes / sizeof(Statistic);

				Statistic *p = new Statistic[size_of_array];
				file_read.seekg(0, ios::beg);
				for (int k = 0; k < size_of_array; k++) {
					Statistic * _temp_ = new Statistic;
					file_read.read((char*)_temp_, sizeof(Statistic));
					*(p + k) = *_temp_;
					delete _temp_;
				}
				file_read.close();

				for (int i = 0; i < size_of_array; i++)
				{
					StatVectAdmin.push_back(p[i]);
				}
				delete[]p;

				cout << "-------------------------------------------------------------------" << endl;
				cout << "���������� �� ������������ : " << DeCodingStr((char *)VectGuests.at(temp_coice - '0').GetGuestLogin()).c_str() << endl;
				cout << VectGuests.at(temp_coice - '0').GetGuestName()<<" "<< VectGuests.at(temp_coice - '0').GetGuestSurname() << endl;
				
				
				for (int i = 0; i < StatVectAdmin.size(); i++)
				{
					if (!strcmp(StatVectAdmin.at(i).stat_guest_login, VectGuests.at(temp_coice - '0').GetGuestLogin()))
					{	tests_counter++;}
				}


					
				for (int i = 0; i<StatVectAdmin.size(); i++)
				{
					if (!strcmp(StatVectAdmin.at(i).stat_guest_login, VectGuests.at(temp_coice - '0').GetGuestLogin()))
					{
					bool flag = false;
					for (int j = StatVectAdmin.size() - 1; j > i; j--)
						{
							if (!strcmp(StatVectAdmin.at(i).stat_guest_login, StatVectAdmin.at(j).stat_guest_login))
							{	flag = true;}
						}
						if (!flag)
						{VectTempSubj.push_back(StatVectAdmin.at(i).stat_guest_login);	}
					}
					
				}
				
				cout << "-------------------------------------------------------------------" << endl;
				cout << "\n���������� ���������� ������ : " << tests_counter << endl;

				for (int i = 0; i < VectTempSubj.size(); i++)
				{
					tests_counter = 0; avar_rate = 0;
					for (int j = 0; j < StatVectAdmin.size(); j++)
					{
						if (!strcmp(VectTempSubj.at(i).c_str(), StatVectAdmin.at(j).stat_subject_name))
						{
							tests_counter++;
							avar_rate = avar_rate + StatVectAdmin.at(j).test_rate;
						}
					}
					cout << "���������� ���������� ������ �� �������� : " << VectTempSubj.at(i) << endl;
					cout << tests_counter << " ��." << endl;
					cout << "������� ���� �� ��������                 : " << endl;
					cout << avar_rate << " ������" << endl;
				}
								
				cout << "-------------------------------------------------------------------" << endl;

				Sleep(3000);
			}
		}

	}
	
	void ExportStatisticToFile()//������� ���������� � ����
	{
		char temp[50];
		char temp_coice;
		int tests_counter = 0;
		int avar_rate;
		vector<string>VectTempSubj;

		cout << "����� � ���� ���������� �� ������������� ������������..." << endl;

		fstream file_read("GuestsLab.dat", ios::in | ios::binary);//��������� ������ �� ����� �� �������������

		file_read.seekg(0, ios::end);
		int size_of_file_in_bytes = file_read.tellg();
		int size_of_array = size_of_file_in_bytes / sizeof(Guest);

		Guest *p = new Guest[size_of_array];
		file_read.seekg(0, ios::beg);
		for (int k = 0; k < size_of_array; k++) {
			Guest * _temp_ = new Guest;
			file_read.read((char*)_temp_, sizeof(Guest));
			*(p + k) = *_temp_;
			delete _temp_;
		}

		for (int i = 0; i < size_of_array; i++)
		{
			VectGuests.push_back(p[i]);//��������� ������ ��������� ���� �����������
		}
		delete[] p;

		file_read.close();
		cout << "��������� � ���� ������ ������������� :" << endl;
		for (int i = 0; i < VectGuests.size(); i++)//����������� ���� ������������� ��� ������
		{
			cout << "No" << i << " - " << DeCodingStr((char *)VectGuests.at(i).GetGuestLogin()) << " ; ";
		}

		//----------------------------------------------------------------------------

		cout << "������� ���������� � ������������ ��� ������ ����������:" << endl;
		cout << "��� ������ � ���������� ���� - n : ";
		for (;;) {
			cin >> temp_coice;cin.ignore(100, '\n');
			if (temp_coice == 'n' || ((temp_coice - '0' >= 0) && (temp_coice - '0' < VectGuests.size())))
				break;
			else
				cout << "�������� ���������� �����!" << endl;
		}

		if (temp_coice == 'n')
		{
			Sleep(2000);
			AdminMenu_1_3();
		}

		if ((temp_coice - '0' >= 0) && (temp_coice - '0' < VectGuests.size()))
		{
			fstream file_read("StatLab.dat", ios::in | ios::binary);
			if (!file_read.is_open())
			{
				file_read.close();
				cout << "� ������� ��� ��� ����������..." << endl;
				Sleep(2000);
				AdminMenu_1_3();

			}
			else
			{
				file_read.seekg(0, ios::end);
				int size_of_file_in_bytes = file_read.tellg();
				int size_of_array = size_of_file_in_bytes / sizeof(Statistic);

				Statistic *p = new Statistic[size_of_array];
				file_read.seekg(0, ios::beg);
				for (int k = 0; k < size_of_array; k++) {
					Statistic * _temp_ = new Statistic;
					file_read.read((char*)_temp_, sizeof(Statistic));
					*(p + k) = *_temp_;
					delete _temp_;
				}
				file_read.close();

				for (int i = 0; i < size_of_array; i++)
				{
					StatVectAdmin.push_back(p[i]);// ��������� ������ ��������� ������ ����������
				}
				delete[]p;

				cout << "-------------------------------------------------------------------" << endl;//����� ���������� �� ������������� ������������
				cout << "���������� �� ������������ : " << DeCodingStr((char *)VectGuests.at(temp_coice - '0').GetGuestLogin()) << endl;
				cout << VectGuests.at(temp_coice - '0').GetGuestName() << " " << VectGuests.at(temp_coice - '0').GetGuestSurname() << endl;


				for (int i = 0; i < StatVectAdmin.size(); i++)
				{
					if (!strcmp(StatVectAdmin.at(i).stat_guest_login, VectGuests.at(temp_coice - '0').GetGuestLogin()))
					{
						tests_counter++;
					}
				}



				for (int i = 0; i<StatVectAdmin.size(); i++)
				{
					if (!strcmp(StatVectAdmin.at(i).stat_guest_login, VectGuests.at(temp_coice - '0').GetGuestLogin()))
					{
						bool flag = false;
						for (int j = StatVectAdmin.size() - 1; j > i; j--)
						{
							if (!strcmp(StatVectAdmin.at(i).stat_guest_login, StatVectAdmin.at(j).stat_guest_login))
							{
								flag = true;
							}
						}
						if (!flag)
						{
							VectTempSubj.push_back(StatVectAdmin.at(i).stat_guest_login);
						}
					}

				}


				cout << "\n������� ��� ����� ��� ������� ��������� / ���������: " << endl;
				cout << "��������, C:\\Categories.txt :" << endl;
				//cin.ignore();
				gets_s(temp);
				

				fstream file_write(temp, ios::out | ios::trunc);//������ ���������� � ��������� ����

				if (!file_write.is_open())
				{cout << "Error to open for writing!" << endl;	}
				file_write << "=========================================================" << endl;
				file_write << "��������� �� ������������ ��������� �� ���������" << endl;
				file_write << "����������, ������ � �.�." << endl;
				file_write << "                                          <<������ 2018>>" << endl;
				file_write << "=========================================================" << endl;
				file_write << "-------------------------------------------------------------------------------------------" << endl;
				file_write << "������� ���������� �� ��������� �� ������������ :" << endl; 
				file_write << VectGuests.at(temp_coice - '0').GetGuestName() << " " << VectGuests.at(temp_coice - '0').GetGuestSurname() << endl;
				file_write << "-------------------------------------------------------------------------------------------" << endl<<endl;
				file_write << "���������� ���������� ������ : " << tests_counter << endl;

				for (int i = 0; i < VectTempSubj.size(); i++)
				{
					tests_counter = 0; avar_rate = 0;
					for (int j = 0; j < StatVectAdmin.size(); j++)
					{
						if (!strcmp(VectTempSubj.at(i).c_str(), StatVectAdmin.at(j).stat_subject_name))
						{
							tests_counter++;
							avar_rate = avar_rate + StatVectAdmin.at(j).test_rate;
						}
					}
					file_write << "���������� ���������� ������ �� �������� : " << VectTempSubj.at(i) << endl;
					file_write << tests_counter << " ��." << endl;
					file_write << "������� ���� �� ��������                 : " << endl;
					file_write << avar_rate << " ������" << endl;
				}
				file_write << "-------------------------------------------------------------------------------------------" << endl;

				file_write.flush();
				file_write.close();

				cout << "���������� ������� �������������� � ��������� ����!" << endl;
				Sleep(5000);

			}
		}

	
	}
	void EditGuestAcc()//������������� �������� ������������
	{
		char templog[50], temppass[50], tempguest_address[250];
		bool if_acc_match = false;

		cout << "\n��������� ������ �� ������������..." << endl;

		fstream file_read("GuestsLab.dat", ios::in | ios::binary);
		if (!file_read.is_open())
		{
			file_read.close();
			cout << "\n������������ ��� �� �������!" << endl;	Sleep(3000); return;
		}

		file_read.seekg(0, ios::end);
		int size_of_file_in_bytes = file_read.tellg();
		int size_of_array = size_of_file_in_bytes / sizeof(Guest);

		Guest *p = new Guest[size_of_array];
		file_read.seekg(0, ios::beg);
		for (int k = 0; k < size_of_array; k++) {
			Guest * _temp_ = new Guest;
			file_read.read((char*)_temp_, sizeof(Guest));
			*(p + k) = *_temp_;
			delete _temp_;
		}
		file_read.close();

		for (int i = 0; i < size_of_array; i++)
		{
			VectGuests.push_back(p[i]);
		}
		delete[] p;
		int guest_number = 0;
		do
		{
			cout << "������� ����� ��� ������������� ������ : ";
			//cin.ignore();
			gets_s(templog);
			for (int i = 0; i < VectGuests.size(); i++)
			{
				if (!strcmp(DeCodingStr((char *)VectGuests.at(i).GetGuestLogin()).c_str(), templog))
				{	if_acc_match = true; guest_number = i;	}
			}
			if (!if_acc_match)
			{
				cout << "��������, ��������� ������ �� ������������� ������!" << endl;
				cout << "��������� �������!" << endl;
			}


		} while (!if_acc_match);

		cout << "������ ������������ � ������� ��������� :" << endl;
		VectGuests.at(guest_number).ShowGuestDetails();
		cout << "\n������� ����� ������ �� ������������ : " << endl;
		cout << "��� ������������                     : ";
		cin.ignore(100, '\n');
		gets_s(templog); VectGuests.at(guest_number).SetGSurname(templog);
		cout << "������� ������������                 : ";
		gets_s(templog); VectGuests.at(guest_number).SetGSurname(templog);
		cout << "����� �������� ������������          : " ;
		gets_s(templog); VectGuests.at(guest_number).SetGLogin((char *)CodingStr(templog).c_str());
		cout << "������ �������� ������������         : " ;
		gets_s(templog); VectGuests.at(guest_number).SetGPass((char *)CodingStr(templog).c_str());
		cout << "�������                              : ";
		gets_s(templog); VectGuests.at(guest_number).SetGPhone(templog);
		cout << "�����                                : ";
		gets_s(tempguest_address); VectGuests.at(guest_number).SetGAddress(tempguest_address);
		cout << "-----------------------------------------------------------------------------------" << endl;
		
		p = new Guest[VectGuests.size()];
		for (int i = 0; i < VectGuests.size(); i++)
		{*(p + i) = VectGuests.at(i);}

		fstream file_write("GuestsLab.dat", ios::out | ios::trunc | ios::binary);
		if (!file_write.is_open())
		{	cout << "Error to open for writing!" << endl;	}

		for (int k = 0; k < VectGuests.size(); k++)
		{
			file_write.write((char*)(p + k), sizeof(Guest));
		}
		file_write.flush();
		file_write.close();
		delete[]p;
		cout << "\n������� ������������ ��� ������� ��������!" << endl;
		Sleep(3000);
	}
	
	void ImportCatFromFile()// ������ ��������� / ��������� �� ����� ��������������� �����
	{
		char temp[50];
		bool if_subj_avail = false;
		string bufStr;
		vector<string> TempVect;
		vector<string> TempVectWithoutDupl;
		cout << "������ ��������� �� �����..." << endl;
		cout << "��������� � ������� ��������� :" << endl;

		fstream file_read("SubjLab.dat", ios::in | ios::binary);
		if (!file_read.is_open())
		{
			file_read.close();
			cout << "� ������� ��� ��� ���������..." << endl;
			cout << "������� ��� ����� ��� ������� ��������� / ���������: " << endl;
			cout << "��������, C:\\Categories.txt " << endl;
			cout << "�������� ������ ���� � ��������� �����, ������ ������� � ����� ������.. :" << endl;
			gets_s(temp);
			//gets_s(temp);

			ifstream inp(temp, ios::in);
			inp.seekg(0);
			if (!inp)
			{
				cout << "����� ���\n";
				//system("pause"); 
			}

			while (!inp.eof())
			{
				getline(inp, bufStr, '\n');
				TempVect.push_back(bufStr);
			}
			inp.close();

			for (int i = 0; i< TempVect.size(); i++)
			{
				strcpy(temp, "");
				strcpy(temp, TempVect.at(i).c_str());
				for (int i = 0; i < 50; i++) temp[i] = toupper(temp[i]);
				strcpy(subjectslab[i], temp);
			}
			fstream file_write("SubjLab.dat", ios::out | ios::trunc | ios::binary);
			if (!file_write.is_open())
			{
				cout << "Error to open for writing!" << endl;
			}
			for (int k = 0; k < TempVect.size(); k++)
			{
				file_write.write((subjectslab[k]), sizeof(char) * 50);
			}
			file_write.flush();
			file_write.close();
			cout << "��������� ������� ������������� � ��������� � �����!" << endl;

		}
		else
		{
			file_read.seekg(0, ios::end);
			int size_of_file_in_bytes = file_read.tellg();
			int size_of_array = size_of_file_in_bytes / (sizeof(char) * 50);

			file_read.seekg(0, ios::beg);
			for (int k = 0; k < size_of_array; k++) {
				char _temp_[50];
				file_read.read(_temp_, sizeof(char) * 50);
				strcpy(subjectslab[k], _temp_);
			}
			file_read.close();

			for (int k = 0; k < size_of_array; k++) {
				cout << "������� � " << k << " " << subjectslab[k] << endl;
			}

			//��������� �� ����� ���������
			cout << "������� ��� ����� ��� ������� ��������� / ���������: " << endl;
			cout << "��������, C:\\Categories.txt " << endl;
			cout << "�������� ������ ���� � ��������� �����, ������ ������� � ����� ������.. :" << endl;
			gets_s(temp);
			//gets_s(temp);

			ifstream inp(temp, ios::in);
			inp.seekg(0);
			if (!inp)
			{
				cout << "����� ���\n";
				//system("pause"); 
			}

			while (!inp.eof())
			{
				getline(inp, bufStr, '\n');
				strcpy(temp, "");
				strcpy(temp, bufStr.c_str());
				for (int i = 0; i < 50; i++) temp[i] = toupper(temp[i]);
				TempVect.push_back(temp);
			}
			inp.close();
			for (int i = 0; i< size_of_array; i++)
			{
				TempVect.push_back(subjectslab[i]);
			}
			
			//������� ��������� ��������� �� ����

			for (int i = 0; i<TempVect.size(); i++)
			{
				bool flag = false;
				for (int j = TempVect.size() - 1; j>i; j--)
				{
					if (TempVect.at(i) == TempVect.at(j))
					{
						flag = true;
					}
				}
				if (!flag)
				{
					TempVectWithoutDupl.push_back(TempVect.at(i));
				}
			}

			fstream file_write("SubjLab.dat", ios::out | ios::trunc | ios::binary);
			if (!file_write.is_open())
			{
				cout << "Error to open for writing!" << endl;
			}
			for (int k = 0; k < TempVectWithoutDupl.size(); k++)
			{
				file_write.write((TempVectWithoutDupl.at(k).c_str()), sizeof(char) * 50);
			}
			file_write.flush();
			file_write.close();

			cout << "��������� ������� ������������� � ����� � ���������!" << endl;

		}
	}

	
	void ExportCatToFile()//������� ��������� / ��������� � ����
	{

		char temp[50];
		cout << "������� ��������� / ��������� � ����..." << endl;
		cout << "��������� � ������� ��������� / �������� :" << endl;

		fstream file_read("SubjLab.dat", ios::in | ios::binary);
		if (!file_read.is_open())
		{
			cout << "��������� ��� �� ����� ���������!!" << endl;
			Sleep(3000); AdminMenu_1_3();
		}
		else
		{
			file_read.seekg(0, ios::end);
			int size_of_file_in_bytes = file_read.tellg();
			int size_of_array = size_of_file_in_bytes / (sizeof(char) * 50);

			file_read.seekg(0, ios::beg);
			for (int k = 0; k < size_of_array; k++) {
				char _temp_[50];
				file_read.read(_temp_, sizeof(char) * 50);
				strcpy(subjectslab[k], _temp_);

			}
			file_read.close();

			for (int i = 0; i < size_of_array; i++)
				cout << "No " << i << "  " << subjectslab[i] << endl;

			cout << "\n������� ��� ����� ��� �������� ��������� / ���������: " << endl;
			cout << "��������, C:\\Categories.txt :" << endl;
			gets_s(temp);
			//gets_s(temp);

			fstream file_write(temp, ios::out | ios::trunc);

			if (!file_write.is_open())
			{
				cout << "Error to open for writing!" << endl;
			}
			file_write << "=========================================================" << endl;
			file_write << "��������� �� ������������ ��������� �� ���������" << endl;
			file_write << "����������, ������ � �.�." << endl;
			file_write << "                                          <<������ 2018>>" << endl;
			file_write << "=========================================================" << endl;
			file_write << "-------------------------------------------------------------------------------------------" << endl;
			file_write << "������� ��������� / ��������� �� ���������" << endl;
			file_write << "-------------------------------------------------------------------------------------------" << endl;
			for (int i = 0; i< size_of_array; i++)
			{
				file_write << "������� � " << i + 1 << "  " << subjectslab[i] << endl;
			}
			file_write << "-------------------------------------------------------------------------------------------" << endl;
			file_write.flush();
			file_write.close();
						
			cout << "�������� ������� �������������� � ��������� ����!" << endl;

			Sleep(5000); AdminMenu_1_3();	
		}


	}


	void EditTest()//��������� ������������� � ��������� ����� 
	{
		char temp[50];
		char temp_coice;

		cout << "������������� �����.." << endl;
		cout << "��������� � ������� ��������� / �������� :" << endl;

		fstream file_read("SubjLab.dat", ios::in | ios::binary); //����������� ������� ��������� �� ����� � ������
		if (!file_read.is_open())
		{
			cout << "������ �������� �����!" << endl;
			Sleep(5000); AdminMenu_1_3();	
		}
		else
		{
			file_read.seekg(0, ios::end);
			int size_of_file_in_bytes = file_read.tellg();
			int size_of_array = size_of_file_in_bytes / (sizeof(char) * 50);

			file_read.seekg(0, ios::beg);
			for (int k = 0; k < size_of_array; k++) {
				char _temp_[50];
				file_read.read(_temp_, sizeof(char) * 50);
				strcpy(subjectslab[k], _temp_);

			}
			file_read.close();

			for (int i = 0; i < size_of_array; i++)
				cout << "No " << i << "  " << subjectslab[i] << endl;//����� ��������� ���������

			cout << "������� ����� �������� ��� ������ ���� ������ �� ��������:" << endl;
			cout << "��� ������ � ���������� ���� - 9 : ";
			for (;;) {
				cin >> temp_coice;
				if (temp_coice == '9' || ((temp_coice - '0' >= 0) && (temp_coice - '0' < size_of_array)))
					break;
				else
					cout << "�������� ���������� �����!" << endl;
			}

			if (temp_coice == '9')
			{
				Sleep(2000);
				AdminMenu_1_3();
			}

			if ((temp_coice - '0' >= 0) && (temp_coice - '0' < size_of_array))
			{
				fstream file_read("TestsLab.dat", ios::in | ios::binary);
				if (!file_read.is_open())
				{
					file_read.close();
					cout << "� ������� ��� ��� ������..." << endl;
					Sleep(2000);
					AdminMenu_1_3();

				}
				else
				{
					file_read.seekg(0, ios::end);
					int size_of_file_in_bytes = file_read.tellg();
					int size_of_array = size_of_file_in_bytes / sizeof(Test);

					Test *p = new Test[size_of_array];
					file_read.seekg(0, ios::beg);
					for (int k = 0; k < size_of_array; k++) {
						Test * _temp_ = new Test;
						file_read.read((char*)_temp_, sizeof(Test));
						*(p + k) = *_temp_;
						delete _temp_;
					}
					file_read.close();

					for (int i = 0; i < size_of_array; i++)
					{
						if (!strcmp((p + i)->GetTestSubjName(), subjectslab[temp_coice - '0']))
							VectTests.push_back(p[i]);
					}

					for (int i = 0; i < VectTests.size(); i++)//����� �� ����� ������
					{
						cout << "����� ����� " << i << ":" << endl;
						cout << "-------------------------------------------------------------------" << endl;
						VectTests.at(i).DisplayTest();
					}
					cout << "������� ����� ����� ��� �������������  :" << endl;

					for (;;) {
						cin >> temp_coice;
						if ((temp_coice - '0' >= 0) || (temp_coice - '0' < VectTests.size()))
							break;
						else
							cout << "�������� ���������� �����!" << endl;
					}

					//������������� �����!	
					char temp_semi_subj[500], temp_quest[500], temp_answ[4][50];
					int temp_cor_answ;
					Test obj;
					VectTests.at(temp_coice - '0').DisplayTest();//����� �� ����� ����� ��� �������������
					obj = VectTests.at(temp_coice - '0');
					Question temp_arr[2];
					for (int i = 0; i < 2; i++)
					{
						
						cout << "����������, ������� ����� ����������� �����:" << endl;
						cout << "��������, ��������� ������.." << endl;
						cin.ignore(100, '\n');
						gets_s(temp_semi_subj);
						//cin >> temp_str;
						cout << "������� ������ :" << endl;
						gets_s(temp_quest);
						//cin >> temp_str;
						cout << "������� ������ ����� �1 �� ������ :" << endl;
						gets_s(temp_answ[0]);
						//cin >> temp_str;
						cout << "������� ������ ����� �2 �� ������ :" << endl;
						gets_s(temp_answ[1]);
						//cin >> temp_str;
						cout << "������� ������ ����� �3 �� ������ :" << endl;
						gets_s(temp_answ[2]);
						//cin >> temp_str;
						cout << "������� ���������� ����� �� ������ :" << endl << endl;
						gets_s(temp_answ[3]);
						//cin >> temp_str;
						temp_cor_answ = 3;
						temp_arr[i].SetQuestionArg(temp_semi_subj, temp_quest, temp_answ[0], temp_answ[1],
							temp_answ[2], temp_answ[3], temp_cor_answ);

					}
					obj.SetArrQuestions(temp_arr);
					VectTests.erase(VectTests.begin() + (temp_coice - '0'));
					VectTests.push_back(obj);
					//������ ������ ������ � ����
					Test *p_out = new Test[VectTests.size()];

					for (int i = 0; i < VectTests.size(); i++)
					{
						*(p_out + i) = VectTests.at(i);
					}

					fstream file_write("TestsLab.dat", ios::out | ios::trunc | ios::binary);
					if (!file_write.is_open())
					{
						cout << "Error to open for writing!" << endl;
					}
					for (int k = 0; k < VectTests.size(); k++)
					{
						file_write.write((char*)(p_out + k), sizeof(Test));
					}
					file_write.flush();
					file_write.close();

					delete[]p_out;
					cout << "���� ������� ��������������!!!" << endl;

				}
			}
			Sleep(5000);
			AdminMenu_1_3();

		}

	}

	void ExportTestToFile()//������� ����� � ����
	{
		char temp[50];
		char temp_coice;

		cout << "������� ����� � ����.." << endl;
		cout << "��������� � ������� ��������� / �������� :" << endl;

		fstream file_read("SubjLab.dat", ios::in | ios::binary);
		if (!file_read.is_open())
		{cout << "������ ��� �������� �����!" << endl;	}
		else
		{
			file_read.seekg(0, ios::end);
			int size_of_file_in_bytes = file_read.tellg();
			int size_of_array = size_of_file_in_bytes / (sizeof(char) * 50);

			file_read.seekg(0, ios::beg);
			for (int k = 0; k < size_of_array; k++) {
				char _temp_[50];
				file_read.read(_temp_, sizeof(char) * 50);
				strcpy(subjectslab[k], _temp_);

			}
			file_read.close();

			for (int i = 0; i < size_of_array; i++)
				cout << "No " << i << "  " << subjectslab[i] << endl;

			cout << "������� ����� �������� ��� ������ ���� ������ �� �������� :" << endl;
			cout << "��� ������ � ���������� ���� - 9 : ";
			for (;;) {
				cin >> temp_coice;
				if (temp_coice == '9' || ((temp_coice - '0' >= 0) && (temp_coice - '0' < size_of_array)))
					break;
				else
					cout << "�������� ���������� �����!" << endl;
			}

			if (temp_coice == '9')
			{
				Sleep(2000);
				AdminMenu_1_3();
			}

			if ((temp_coice - '0' >= 0) && (temp_coice - '0' < size_of_array))
			{
				fstream file_read("TestsLab.dat", ios::in | ios::binary);
				if (!file_read.is_open())
				{
					file_read.close();
					cout << "� �������� ��� ��� ������..." << endl;
					Sleep(2000);
					AdminMenu_1_3();
										
				}
				else
				{
					file_read.seekg(0, ios::end);
					int size_of_file_in_bytes = file_read.tellg();
					int size_of_array = size_of_file_in_bytes / sizeof(Test);

					Test *p = new Test[size_of_array];
					file_read.seekg(0, ios::beg);
					for (int k = 0; k < size_of_array; k++) {
						Test * _temp_ = new Test;
						file_read.read((char*)_temp_, sizeof(Test));
						*(p + k) = *_temp_;
						delete _temp_;
					}
					file_read.close();

					for (int i = 0; i < size_of_array; i++)
					{
						if (!strcmp((p + i)->GetTestSubjName(), subjectslab[temp_coice - '0']) )
						VectTests.push_back(p[i]);
					}

					for (int i = 0; i < VectTests.size(); i++)
					{
						cout << "����� ����� � "<<i <<":"<< endl;
						cout << "-------------------------------------------------------------------" << endl;
						VectTests.at(i).DisplayTest();
					}
					cout << "������� ����� ����� ��� ������ � ���� �  :" << endl;
					
					for (;;) {
						cin >> temp_coice;  cin.ignore(100, '\n');
						if ( (temp_coice - '0' >= 0) || (temp_coice - '0' < VectTests.size()) )
							break;
						else
							cout << "�������� ���������� �����!" << endl;
					}

					mytestobj = new Test[1];
					*mytestobj = VectTests.at(temp_coice - '0');
					
					fstream file_write("TestsExport.txt", ios::out | ios::trunc); //����� ����� � ����� ������������ ����
					
					if (!file_write.is_open())
					{
						cout << "Error to open for writing!" << endl;
					}
					file_write << "=========================================================" << endl;
					file_write << "��������� �� ������������ ��������� �� ���������" << endl;
					file_write << "����������, ������ � �.�." << endl;
					file_write << "                                          <<������ 2018>>" << endl;
					file_write << "=========================================================" << endl;
					file_write << "������ ����� � " << temp_coice << endl;
					file_write << "---------------------------------------------------------------------------" << endl;
					file_write << "������� ����� - " << mytestobj->GetTestSubjName() << endl;

					file_write<<"����������� ������� �1 :"<<endl;
					file_write<< mytestobj->GetQuestArr()[0].semi_subject<<endl;
					file_write<<"������ �1 :"<<endl;
					file_write<< mytestobj->GetQuestArr()[0].question<<endl;

					for (int i = 0 ; i< 4; i++)
					{
					file_write<<"����� � "<< i+1<< " �� ������ �1 :"<<endl;
					file_write<< mytestobj->GetQuestArr()[0].answers_arr[i]<<endl;
	
					if (mytestobj->GetQuestArr()[0].correct_answ_arr[i] == true)
					file_write<<"\n���������� ����� � "<< i+1<< " �� ������ �1."<<endl;

					}

					file_write<<"\n����������� ������� �2 :"<<endl;
					file_write<< mytestobj->GetQuestArr()[1].semi_subject<<endl;
					file_write<<"������ �2 :"<<endl;
					file_write<< mytestobj->GetQuestArr()[1].question<<endl;

					for (int i = 0 ; i< 4; i++)
					{
					file_write<<"����� � "<< i+1<< " �� ������ �2 :"<<endl;
					file_write<< mytestobj->GetQuestArr()[1].answers_arr[i]<<endl;
										
					if (mytestobj->GetQuestArr()[1].correct_answ_arr[i] == true)
					file_write<<"\n���������� ����� � "<< i+1<< " �� ������ �2"<<endl;

					}
					file_write<<"---------------------------------------------------------------------------"<<endl;
					file_write.flush();
					file_write.close();

					delete[]mytestobj;
					cout << "���� ������� ������������ � ��������� ����!" << endl;

				}
			}
			Sleep(5000);
			AdminMenu_1_3();

		}




	}

	void ImportTestFromFile()//������ ����� �� ����� ��������������� �����
	{
		char temp[50];
		char temp_coice;

		cout << "������ ����� �� �����.." << endl;
		cout << "��������� � ������� ��������� / �������� :" << endl;

		fstream file_read("SubjLab.dat", ios::in | ios::binary);//���������� ��������� � ������� ��������� ��� ����������� ���������
		if (!file_read.is_open())
		{
			cout << "������ ��� �������� �����!" << endl;
		}
		else
		{
			file_read.seekg(0, ios::end);
			int size_of_file_in_bytes = file_read.tellg();
			int size_of_array = size_of_file_in_bytes / (sizeof(char) * 50);

			file_read.seekg(0, ios::beg);
			for (int k = 0; k < size_of_array; k++) {
				char _temp_[50];
				file_read.read(_temp_, sizeof(char) * 50);
				strcpy(subjectslab[k], _temp_);

			}
			file_read.close();

			for (int i = 0; i < size_of_array; i++)
				cout << "No " << i << "  " << subjectslab[i] << endl;

			cout << "������� ����� �������� ��� ������� ����� � ���� :" << endl;
			cout << "��� ������ � ���������� ���� - 9 : ";
			for (;;) {
				cin >> temp_coice;cin.ignore(100, '\n');
				if (temp_coice == '9' || ((temp_coice - '0' >= 0) && (temp_coice - '0' < size_of_array)))
					break;
				else
					cout << "�������� ���������� �����!" << endl;
			}

			if (temp_coice == '9')
			{
				Sleep(2000);
				AdminMenu_1_3();
			}

			if ((temp_coice - '0' >= 0) && (temp_coice - '0' < size_of_array))
			{
				mytestobj = new Test[1];
				Question temp_quest_arr[2];
				string _semi_subject = "";
				char temp_semi_subj[500], temp_question[500], temp_answ0[50], temp_answ1[50],
					temp_answ2[50], temp_answ3[50];
				char correct_answ;
				int temp_corr_answ;
				ifstream import("ImportTest.txt", ios::in);
				import.seekg(0);
				if (!import)
				{	cout << "������ �������� �����\n";	system("pause");}

					getline(import, _semi_subject);//���������� ������ �� ����� �� ��������� ����������
					strcpy(temp_semi_subj, _semi_subject.c_str());//����������� ������ � ���� ������� 
					getline(import, _semi_subject);
					strcpy(temp_question, _semi_subject.c_str());
					getline(import, _semi_subject);
					strcpy(temp_answ0, _semi_subject.c_str());
					getline(import, _semi_subject);
					strcpy(temp_answ1, _semi_subject.c_str());
					getline(import, _semi_subject);
					strcpy(temp_answ2, _semi_subject.c_str());
					getline(import, _semi_subject);
					strcpy(temp_answ3, _semi_subject.c_str());
					getline(import, _semi_subject);
					correct_answ = _semi_subject.c_str()[0];
					temp_corr_answ = ((correct_answ - '0')-1);
					temp_quest_arr[0].SetQuestionArg(temp_semi_subj, temp_question, temp_answ0, temp_answ1,
						temp_answ2, temp_answ3, temp_corr_answ);

					getline(import, _semi_subject);
					strcpy(temp_semi_subj, _semi_subject.c_str());
					getline(import, _semi_subject);
					strcpy(temp_question, _semi_subject.c_str());
					getline(import, _semi_subject);
					strcpy(temp_answ0, _semi_subject.c_str());
					getline(import, _semi_subject);
					strcpy(temp_answ1, _semi_subject.c_str());
					getline(import, _semi_subject);
					strcpy(temp_answ2, _semi_subject.c_str());
					getline(import, _semi_subject);
					strcpy(temp_answ3, _semi_subject.c_str());
					getline(import, _semi_subject);
					correct_answ = _semi_subject.c_str()[0];
					temp_corr_answ = ((correct_answ - '0') - 1);
					temp_quest_arr[1].SetQuestionArg(temp_semi_subj, temp_question, temp_answ0, temp_answ1,
						temp_answ2, temp_answ3, temp_corr_answ);
			
				import.close();
				mytestobj->SetTestSubjName(subjectslab[temp_coice - '0']);
				mytestobj->SetArrQuestions(temp_quest_arr);
				
				mytestobj->DisplayTest();


				delete[]mytestobj;
			}
		}
	}
	
string CodingStr(char * str)//����������� ������
{
	string str_temp;
	str_temp = str;
	for (int i = 0; i <str_temp.size(); i++) {
		str_temp[i] = str_temp[i] + 3;
	}
	return str_temp;
}

string DeCodingStr(char * str)//�������������� ������
{
	string str_temp;
	str_temp = str;
	for (int i = 0; i <str_temp.size(); i++) {
		str_temp[i] = str_temp[i] - 3;
	}
	return str_temp;
}

	~Admin() { //delete mytestobj; 
	}
};



int main()

{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Admin myadmin;

	//myadmin.SoftNameShow();
	myadmin.FirstMenu();
	//myadmin.EnterToGuestAcc();
	//myadmin.CreateGuest();
	//myadmin.DeleteGuestAcc();
	
	//myadmin.AdminMenu_1_3();+++
	//myadmin.DeleteGuestAcc();
	
	
	//myadmin.CreateCategory();//+
	//myadmin.ImportCatFromFile();
	//myadmin.CreateTest();//+
	//myadmin.ShowStatisticForAdminCategory();
	//myadmin.TestPassing("mather");
	//myadmin.ShowStatisticForGuest("mather");
	//myadmin.ExportTestToFile(); +
	//myadmin.EditTest();//+
	//myadmin.ImportTestFromFile();//+ �������� ������ � ����..
	//myadmin.ShowStatisticForAdminTest();
	//myadmin.ShowStatisticForAdminbyGuest();
	//myadmin.ExportStatisticToFile();
	//myadmin.ExportCatToFile();


	//	system ("pause");
	return 0;
}
