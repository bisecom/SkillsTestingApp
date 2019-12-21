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
using namespace std;


class Question
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

	void SetQuestion()
	{
		string temp_str;
		char temp_quest[500], temp_answ[50];
		cout << "ÏÎÆÀËÓÉÑÒÀ, ÓÊÀÆÈÒÅ ÍÀÏĞÀÂËÅÍÈÅ ÒÅÑÒÀ:" << endl;
		cout << "ÍÀÏĞÈÌÅĞ, ÊÂÀÍÒÎÂÀß ÔÈÇÈÊÀ.." << endl;
		cin.ignore();
		gets_s(temp_quest);
		//cin >> temp_str;
		strcpy(semi_subject, temp_quest);
		cout << "ÓÊÀÆÈÒÅ ÂÎÏĞÎÑ :" << endl;
		gets_s(temp_quest);
		//cin >> temp_str;
		strcpy(question, temp_quest);
		cout << "ÓÊÀÆÈÒÅ ËÎÆÍÛÉ ÎÒÂÅÒ ¹1 ÍÀ ÂÎÏĞÎÑ :" << endl;
		gets_s(temp_answ);
		//cin >> temp_str;
		strcpy(answers_arr[0], temp_answ);
		correct_answ_arr[0] = false;
		cout << "ÓÊÀÆÈÒÅ ËÎÆÍÛÉ ÎÒÂÅÒ ¹2 ÍÀ ÂÎÏĞÎÑ :" << endl;
		gets_s(temp_answ);
		//cin >> temp_str;
		strcpy(answers_arr[1], temp_answ);
		correct_answ_arr[1] = false;
		cout << "ÓÊÀÆÈÒÅ ËÎÆÍÛÉ ÎÒÂÅÒ ¹3 ÍÀ ÂÎÏĞÎÑ :" << endl;
		gets_s(temp_answ);
		//cin >> temp_str;
		strcpy(answers_arr[2], temp_answ);
		correct_answ_arr[2] = false;
		cout << "ÓÊÀÆÈÒÅ ÊÎĞĞÅÊÒÍÛÉ ÎÒÂÅÒ ÍÀ ÂÎÏĞÎÑ :" << endl << endl;
		gets_s(temp_answ);
		//cin >> temp_str;
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

	void SetQuestion_TEST()
	{
		strcpy(semi_subject, "Äèñêğåòíàÿ ìàòåìàòèêà");
		strcpy(question, "2 + 2 =");
		strcpy(answers_arr[0], " 5");
		correct_answ_arr[0] = false;
		strcpy(answers_arr[1], " 6");
		correct_answ_arr[1] = false;
		strcpy(answers_arr[2], " 7");
		correct_answ_arr[2] = false;
		strcpy(answers_arr[3], " 4");
		correct_answ_arr[3] = true;
	}


	void DisplayQuestion()
	{
		cout << "ÊÀÒÅÃÎĞÈß ÂÎÏĞÎÑÀ : " << endl; cout << semi_subject << endl;
		cout << "ÂÎÏĞÎÑ ¹1" << endl;
		cout << question << endl;
		cout << "Âàğèàíò ¹1 " << answers_arr[0] << "        Âàğèàíò ¹2 " << answers_arr[1] << endl;
		cout << "Âàğèàíò ¹3 " << answers_arr[2] << "        Âàğèàíò ¹4 " << answers_arr[3] << endl <<endl;

	}

};

class Test : public Question
{
private:
	char subject_name[50], test_name[50]; // 
	Question array_of_questions_per_test[2];

public:
	Test()
	{
		strcpy(subject_name, "");
	}

	void SetTest(char * str, char * str1)
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
		/*array_of_questions_per_test[0].semi_subject;
		array_of_questions_per_test[0].question;
		array_of_questions_per_test[0].answers_arr[0];
		array_of_questions_per_test[0].answers_arr[1];
		array_of_questions_per_test[0].answers_arr[2];
		array_of_questions_per_test[0].answers_arr[3];
		array_of_questions_per_test[0].correct_answ_arr[0];
		array_of_questions_per_test[0].correct_answ_arr[1];
		array_of_questions_per_test[0].correct_answ_arr[2];
		array_of_questions_per_test[0].correct_answ_arr[3];

		array_of_questions_per_test[1].semi_subject;
		array_of_questions_per_test[1].question;
		array_of_questions_per_test[1].answers_arr[0];
		array_of_questions_per_test[1].answers_arr[1];
		array_of_questions_per_test[1].answers_arr[2];
		array_of_questions_per_test[1].answers_arr[3];
		array_of_questions_per_test[1].correct_answ_arr[0];
		array_of_questions_per_test[1].correct_answ_arr[1];
		array_of_questions_per_test[1].correct_answ_arr[2];
		array_of_questions_per_test[1].correct_answ_arr[3];*/
	}
	
	void SetTestSubjName(char * _temp)
	{
		strcpy(subject_name, _temp);
	}

	const char * GetTestSubjName() const
	{
		return subject_name;
	}

	Question * GetQuestArr()
	{
		return array_of_questions_per_test;
	}

	void SetTest_TEST()
	{
		strcpy(subject_name, "ÌÀÒÅÌÀÒÈÊÀ");
		for (int i = 0; i < 2; i++)
			array_of_questions_per_test[i].SetQuestion_TEST();

	}

	void DisplayTest()
	{
		cout << "--------------------------------------------------------------------" << endl;
		cout << "ÄÀÍÍÛÉ ÒÅÑÒ ÏÎ ÏĞÅÄÌÅÒÓ " << subject_name << endl;
		cout << "--------------------------------------------------------------------" << endl;
		
			cout << "ÍÀÏĞÀÂËÅÍÈÅ ÒÅÑÒÀ:" << endl;
			cout << "..................................................................." << endl;
			cout << array_of_questions_per_test[0].semi_subject << endl;
			cout << "ÂÎÏĞÎÑ ¹ "<<1<<" :" << endl;
			cout << array_of_questions_per_test[0].question << endl;
			
			for (int j = 0; j < 4; j++)
			{
				cout << "ÎÒÂÅÒ ¹ "<<j+1<<" ÍÀ ÂÎÏĞÎÑ ¹" << 0 + 1 << " :" << endl;
				cout << array_of_questions_per_test[0].answers_arr[j] << endl;
				
			}
			for (int k = 0; k < 4; k++)
			{
				if (array_of_questions_per_test[0].correct_answ_arr[k] == true)
					cout << "ÍÎÌÅĞ ÏĞÀÂÈËÜÍÎÃÎ ÎÒÂÅÒÀ ÍÀ ÂÎÏĞÎÑ ¹ " << 0 + 1 << " ßÂËßÅÒÑß ¹ "<< k+1 << endl;
			}
		
			cout << endl;

			cout << "ÍÀÏĞÀÂËÅÍÈÅ ÒÅÑÒÀ:" << endl;
			cout << array_of_questions_per_test[1].semi_subject << endl;
			cout << "ÂÎÏĞÎÑ ¹ " << 2 << " :" << endl;
			cout << array_of_questions_per_test[1].question << endl;

			for (int j = 0; j < 4; j++)
			{
				cout << "ÎÒÂÅÒ ¹ " << j + 1 << " ÍÀ ÂÎÏĞÎÑ ¹" << 0 + 2 << " :" << endl;
				cout << array_of_questions_per_test[1].answers_arr[j] << endl;
				
			}
			for (int k = 0; k < 4; k++)
			{
				if (array_of_questions_per_test[1].correct_answ_arr[k] == true)
					cout << "ÍÎÌÅĞ ÏĞÀÂÈËÜÍÎÃÎ ÎÒÂÅÒÀ ÍÀ ÂÎÏĞÎÑ ¹ " << 0 + 2 << " ßÂËßÅÒÑß ¹ " << k + 1 << endl;
			}

			cout << "--------------------------------------------------------------------"<<endl;
	}
	
};

class Statistic
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

class Guest : public Statistic
{
	char guest_login[50];
	char guest_pass[50];
	char guest_surname[50];
	char guest_name[50];
	char guest_address[250];
	char guest_phone_number[50];
	bool guest_is_registered;
	//Statistic * mystatistic_guest;
	//vector<Statistic> StatVectGuest;

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

	const char * GetGuestAddress() const
	{
		return guest_address;
	}


	void FirstTimeRegistration()
	{

	}

	void ShowStatistic()
	{

	}

	void TakeATestMaths()
	{

	}

	void TakeATestPysics()
	{

	}

	void SaveCurrentTest()
	{

	}



};




class Admin : public Statistic
{
private:

	Guest * myguest;
	Guest *p;
	Test * mytestobj;
	vector <Test> VectTests;
	char subjectslab [20][50];
	int tests_qty;
	//int m;
	vector<Guest> VectGuests;
	Statistic * mystatistic_admin;
	vector<Statistic> StatVectAdmin;
	char temp_login[50], temp_pass[100];
	struct AdmData {
		char admin_login[50];
		char admin_pass[100];
		char admin_surname[50];
		char admin_name[50];
		char admin_email[50];
		bool is_registered = false;
	} a_data;
	FILE * fp_adm_reg;

public:
	//Admin(){}
	Admin()
	{
		//mytestobj = new Test;
		
		/*
		strcpy(a_data.admin_login, " ");
		strcpy(a_data.admin_pass, " ");
		strcpy(a_data.admin_surname, " hello world");
		strcpy(a_data.admin_name, " ");
		strcpy(a_data.admin_email, " ");
		fp_adm_reg = fopen("AdminDetails.dat", "wb");
		fwrite(&a_data, sizeof(AdmData), 1, fp_adm_reg);
		fclose(fp_adm_reg);
		*/
	}

	void MainMenu_draw(int iItem)
	{
		system("cls");
		SoftNameShow();
		printf("%s1. ĞÅÃÈÑÒĞÀÖÈß ÀÄÌÈÍÈÑÒĞÀÒÎĞÀ\n", iItem == 1 ? ">" : " "); //âûïîëíåíî AdminRegistration()
		printf("%s2. ÈÇÌÅÍÅÍÈÅ ÏÀĞÎËß ÀÄÌÈÍÈÑÒĞÀÒÎĞÀ\n", iItem == 2 ? ">" : " ");//âûïîëíåíî AdminRegErasing()
		printf("%s3. ÓÄÀËÅÍÈÅ ÀÊÊÀÓÍÒÀ ÀÄÌÈÍÈÑÒĞÀÒÎĞÀ\n", iItem == 3 ? ">" : " ");//âûïîëíåíî AdminRegErasing()
		printf("%s4. ĞÅÃÈÑÒĞÀÖÈß ÏÎËÜÇÎÂÀÒÅËß\n", iItem == 4 ? ">" : " ");//âûïîëåíî CreateGuest()
		printf("%s5. ÓÄÀËÅÍÈÅ ÀÊÊÀÓÍÒÀ ÏÎËÜÇÎÂÀÒÅËß\n", iItem == 5 ? ">" : " "); // DeleteGuestAcc()
		printf("%s6. ÂÕÎÄ Â ÑÈÑÒÅÌÓ ÀÄÌÈÍÈÑÒĞÀÒÎĞÀ\n", iItem == 6 ? ">" : " ");
		printf("%s7. ÂÕÎÄ Â ÑÈÑÒÅÌÓ ÏÎËÜÇÎÂÀÒÅËß\n", iItem == 7 ? ">" : " "); //EnterToGuestAcc()
		printf("%s8. ÂÛÕÎÄ ÈÇ ÏĞÎÃĞÀÌÌÛ\n\n", iItem == 8 ? ">" : " ");
	}
	
	void FirstMenu()
	{
		int iItem = 1;//Îòâå÷àåò êàêîé ïóíêò ìåíş àêòèâåí â äàííûé ìîìåíò
		int nLast = 8;//Îòâå÷àåò êàêîé èíäåêñ ó ïîñëåäíåãî ïóíêòà ìåíş
		SoftNameShow();
		MainMenu_draw(iItem);
		int y = 1;
		bool choice = false;
		while (!choice)
		{
			if (GetAsyncKeyState(VK_UP))
			{
				keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);//Îòæèìàåì êíîïêó
				if (0 < iItem - 1)
					iItem = iItem - 1;
				else
					iItem = nLast;
				SoftNameShow();
				MainMenu_draw(iItem);
			}
			if (GetAsyncKeyState(VK_DOWN))
			{
				keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);//Îòæèìàåì êíîïêó
				if (iItem < nLast)
					iItem = iItem + 1;
				else
					iItem = 1;
				SoftNameShow();
				MainMenu_draw(iItem);
			}
			if (GetAsyncKeyState(VK_RETURN))
			{
				keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);//Îòæèìàåì êíîïêó
				SoftNameShow();
				MainMenu_draw(iItem);
				switch (iItem)
				{
				case 1:
				{	//printf("ĞÅÃÈÑÒĞÀÖÈß ÀÄÌÈÍÈÑÒĞÀÒÎĞÀ\n");
				AdminRegistration();
				/*choice = true;*/  break; }
				case 2:
				{//printf("ÈÇÌÅÍÅÍÈÅ ÏÀĞÎËß ÀÄÌÈÍÈÑÒĞÀÒÎĞÀ\n");
				AdminLoginPassChange();
				/*choice = true; */break; }
				case 3:
				{//printf("ÓÄÀËÅÍÈÅ ÀÊÊÀÓÍÒÀ ÀÄÌÈÍÈÑÒĞÀÒÎĞÀ\n"); 
				AdminRegErasing();
				choice = true; break; }
				case 4:
				{//printf("ĞÅÃÈÑÒĞÀÖÈß ÏÎËÜÇÎÂÀÒÅËß\n");
				CreateGuest();
				choice = true; break; }
				case 5:
				{//printf("ÓÄÀËÅÍÈÅ ÀÊÊÀÓÍÒÀ ÏÎËÜÇÎÂÀÒÅËß\n");
				DeleteGuestAcc();
				choice = true; break; }
				case 6:
				{//printf("ÂÕÎÄ Â ÑÈÑÒÅÌÓ ÀÄÌÈÍÈÑÒĞÀÒÎĞÀ\n");
				EnterToAdminAcc();
				choice = true; break; }
				case 7:
				{//printf("ÂÕÎÄ Â ÑÈÑÒÅÌÓ ÏÎËÜÇÎÂÀÒÅËß\n");
				EnterToGuestAcc();
				//GuestMenu_1();
				choice = true; break; }
				case 8:
				{//printf("ÂÛÕÎÄ ÈÇ ÏĞÎÃĞÀÌÌÛ\n");
				choice = true; 
				cout << "ÑÏÀÑÈÁÎ ÇÀ ÏÎËÜÇÎÂÀÍÈÅ ÏĞÎÃĞÀÌÌÎÉ!" << endl; 
				break; }

				}
			}
		}
		
	}
	
	void SoftNameShow()
	{
		for (int i = 0; i<55; i++) cout << "-";
		cout << endl;
		cout << "ÏĞÎÃĞÀÌÌÀ ÏÎ ÒÅÑÒÈĞÎÂÀÍÈŞ ÑÒÓÄÅÍÒÎÂ ÏÎ ÏĞÅÄÌÅÒÀÌ" << endl;
		cout << "ÌÀÒÅÌÀÒÈÊÀ, ÔÈÇÈÊÀ È Ò.Ä." << endl;
		cout << "                                     <<ÒÅÑÒÎĞ 2018>>" << endl;
		for (int i = 0; i<55; i++) cout << "-";
		cout << endl;

	}

	void AdminRegistration()
	{
		cout << "-----------------------------------" << endl;
		cout << "ĞÅÃÈÑÒĞÀÖÈß ÀÄÌÈÍÈÑÒĞÀÒÎĞÀ :" << endl;
		cout << "-----------------------------------" << endl;

		cout << "ÏÎÆÀËÓÉÑÒÀ ÂÂÈÅÄÈÒÅ ËÎÃÈÍ :" << endl;

		cin >> temp_login;
		fp_adm_reg = fopen("AdminDetails.dat", "a+b");
		if (fp_adm_reg == NULL) {
			// ???? ?? ??????? ???????
			perror("Open");
			return;
		}
		fread(&a_data, sizeof(AdmData), 1, fp_adm_reg);
		if (a_data.is_registered == true)
		{
			cout << "ÈÇÂÈÍÈÒÅ, ÀÄÌÈÍÈÑÒĞÀÒÎĞ ÓÆÅ ÇÀĞÅÃÈÑÒĞÈĞÎÂÀÍ!" << endl;
			return;
		}
		if (!a_data.is_registered)
		{
			strcpy(a_data.admin_login, temp_login);
			cout << "ÏÎÆÀËÓÉÑÒÀ, ÂÂÅÄÈÒÅ ÏÀĞÎËÜ:" << endl;
			cin >> temp_pass;
			strcpy(a_data.admin_pass, temp_pass);
			cout << "ÏÎÆÀËÓÉÑÒÀ, ÂÂÅÄÈÒÅ ÔÀÌÈËÈŞ:" << endl;
			cin >> a_data.admin_surname;
			cout << "ÏÎÆÀËÓÉÑÒÀ, ÂÂÅÄÈÒÅ ÈÌß:" << endl;
			cin >> a_data.admin_name;
			cout << "ÏÎÆÀËÓÉÑÒÀ, ÂÂÅÄÈÒÅ EMAIL:" << endl;
			cin >> a_data.admin_email;
			a_data.is_registered = true;
			cout << "ÏÎÇÄĞÀÂËßÅÌ, ĞÅÃÈÑÒĞÀÖÈß ÏĞÎØËÀ ÓÑÏÅØÍÎ!" << endl;
			fwrite(&a_data, sizeof(AdmData), 1, fp_adm_reg);
			
		}

		fclose(fp_adm_reg);
		cout << "ÀÊÊÀÓÍÒ ÀÄÌÈÍÈÑÒĞÀÒÎĞÀ ÓÑÏÅØÍÎ ÑÎÇÄÀÍ!" << endl;
	}

	void AdminRegErasing()
	{
		cout << "-----------------------------------" << endl;
		cout << "ÓÄÀËÅÍÈÅ ÀÊÊÀÓÍÒÀ ÀÄÌÈÍÈÑÒĞÀÒÎĞÀ  :" << endl;
		cout << "-----------------------------------" << endl;
		fp_adm_reg = fopen("AdminDetails.dat", "a+b");
		if (fp_adm_reg == NULL) {
			perror("Open");
			return;
		}
		fread(&a_data, sizeof(AdmData), 1, fp_adm_reg);
		fclose(fp_adm_reg);
		cout << "ÄËß ÓÄÀËÅÍÈß ÀÊÊÀÓÍÒÀ ÀÄÌÈÍÈÑÒĞÀÒÎĞÀ, " << endl;
		cout << "ÂÂÅÄÈÒÅ ÏÀĞÎËÜ ÀÄÌÈÍÈÑÒĞÀÒÎĞÀ :" << endl;
		do
		{
			cin >> temp_pass;
			if (!strcmp(a_data.admin_pass, temp_pass))
			{
				fp_adm_reg = fopen("AdminDetails.dat", "wb");
				if (fp_adm_reg == NULL) {
					perror("Open"); return; }
				cout << "ÀÊÊÀÓÍÒ ÀÄÌÈÍÈÑÒĞÀÒÎĞÀ ÁÛË ÓÄÀËÅÍ!" << endl;
				fclose(fp_adm_reg);
				break;
			}
			else
				cout << "ÓÊÀÆÈÒÅ ÂÅĞÍÛÉ ÏÀĞÎËÜ ÈËÈ <<ESC>> ÄËß ÂÛÕÎÄÀ!" << endl;
		} while ((_kbhit() == 0) && (_getch() != 27));
		//cin.ignore(); 
		
		FirstMenu();
	}

	void AdminLoginPassChange()
	{
		cout << "-----------------------------------" << endl;
		cout << "ÈÇÌÅÍÅÍÈÅ ÏÀĞÎËß ÀÄÌÈÍÈÑÒĞÀÒÎĞÀ  :" << endl;
		cout << "-----------------------------------" << endl;
		fp_adm_reg = fopen("AdminDetails.dat", "r+b");
		if (fp_adm_reg == NULL) {
			cout << "ÂÍÈÌÀÍÈÅ ÀÊÊÀÓÍÒ ÀÄÌÈÍÀ ÅÙÅ ÍÅ ÑÎÇÄÀÍ!" << endl;;
			return;
		}
		fread(&a_data, sizeof(AdmData), 1, fp_adm_reg);
		fclose(fp_adm_reg);
		cout << "ÄËß ÈÇÌÅÍÅÍÈß ÏÀĞÎËß ÀÄÌÈÍÈÑÒĞÀÒÎĞÀ, " << endl;
		cout << "ÂÂÅÄÈÒÅ ÄÅÉÑÒÂÓŞÙÈÉ ÏÀĞÎËÜ :" << endl;
		do
		{
			//cin.ignore();
			cin>>temp_pass;
			if (!strcmp(a_data.admin_pass, temp_pass))
			{
				fp_adm_reg = fopen("AdminDetails.dat", "wb");
				if (fp_adm_reg == NULL) {
					perror("Open"); return;
				}
				strcpy(temp_pass, "");
				cout << "ÂÂÅÄÈÒÅ ÍÎÂÛÉ ÏÀĞÎËÜ :" << endl;
				cin >> temp_pass;
				strcpy(a_data.admin_pass, temp_pass);
				fwrite(&a_data, sizeof(AdmData), 1, fp_adm_reg);
				fclose(fp_adm_reg);
				cout << "ÏÀĞÎËÜ ÀÄÌÈÍÈÑÒĞÀÒÎĞÀ ÁÛË ÈÇÌÅÍÅÍ!" << endl;
				Sleep(3000);
				break;
			}
			else
				cout << "ÓÊÀÆÈÒÅ ÂÅĞÍÛÉ ÏÀĞÎËÜ ÈËÈ <<ESC>> ÄËß ÂÛÕÎÄÀ!" << endl;
		} while ((_kbhit() == 0) && (_getch() != 27));

	}
	//-------------------------------------------------------------------
	void EnterToAdminAcc()
	{
		char temp[100];
		cout << "\nÄËß ÂÕÎÄÀ Â ÀÊÊÀÓÍÒ ÀÄÌÈÍÈÑÒĞÀÒÎĞÀ, ÂÂÅÄÈÒÅ ËÎÃÈÍ :" << endl;
		cin >> temp;
		fp_adm_reg = fopen("AdminDetails.dat", "r+b");
		if (fp_adm_reg == NULL) {
			cout << "ÂÍÈÌÀÍÈÅ ÀÊÊÀÓÍÒ ÀÄÌÈÍÀ ÅÙÅ ÍÅ ÑÎÇÄÀÍ!" << endl;;
			return;
		}
		fread(&a_data, sizeof(AdmData), 1, fp_adm_reg);
		fclose(fp_adm_reg);

		do
		{
			//cin.ignore();
			cin >> temp;
			if (!strcmp(a_data.admin_login, temp))
			break;	
			else
				cout << "ÓÊÀÆÈÒÅ ÂÅĞÍÛÉ ËÎÃÈÍ ÈËÈ <<ESC>> ÄËß ÂÛÕÎÄÀ!" << endl;
		} while ((_kbhit() == 0) && (_getch() != 27));
		
		cout << "ÄËß ÂÕÎÄÀ, ÂÂÅÄÈÒÅ ÑÂÎÉ ÏÀĞÎËÜ :" << endl;
		do
		{
			//cin.ignore();
			cin >> temp;
			if (!strcmp(a_data.admin_pass, temp))
			{
				AdminMenu_1();
				break;
			}
			else
				cout << "ÓÊÀÆÈÒÅ ÂÅĞÍÛÉ ÏÀĞÎËÜ ÈËÈ <<ESC>> ÄËß ÂÛÕÎÄÀ!" << endl;
		} while ((_kbhit() == 0) && (_getch() != 27));


	}

	//-------------------------------------------------------------------
	void EnterToGuestAcc()
	{
		char temp[50];
		bool data_is_ok = false;
		fstream file_read("GuestsLab.dat", ios::in | ios::binary);
		if (!file_read.is_open())
		{
			file_read.close();
			cout << "ÏÎËÜÇÎÂÀÒÅËÈ ÅÙÅ ÍÅ ÑÎÇÄÀÍÛ!" << endl;	Sleep(3000); return;
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
		{	VectGuests.push_back(p[i]);		}
		delete[] p;
		
		cout << "\nÄËß ÂÕÎÄÀ Â ÀÊÊÀÓÍÒ ÏÎËÜÇÎÂÀÒÅËß, ÂÂÅÄÈÒÅ ËÎÃÈÍ :" << endl;
		
		do
		{
			//cin.ignore();
			//cin >> temp;
			gets_s(temp);
			for (int i = 0; i < VectGuests.size(); i++) {
				if (strcmp(VectGuests.at(i).GetGuestLogin(), temp) == 0)
				{
					data_is_ok = true;
					break;
				}
			}
			if (!data_is_ok)
				cout << "ÓÊÀÆÈÒÅ ÂÅĞÍÛÉ ËÎÃÈÍ ÈËÈ <<ESC>> ÄËß ÂÛÕÎÄÀ!" << endl;

		} while ((_kbhit() == 0) && (_getch() != 27) || !data_is_ok);
		
		cout << "ÄËß ÂÕÎÄÀ, ÂÂÅÄÈÒÅ ÑÂÎÉ ÏÀĞÎËÜ :" << endl;
		do
		{
			//cin.ignore();
			//cin >> temp;
			gets_s(temp);
			for (int i = 0; i < VectGuests.size(); i++) {
				if (strcmp(VectGuests.at(i).GetGuestPass(), temp) == 0)
				{
					GuestMenu_1();	break;
				}
			}

			cout << "ÓÊÀÆÈÒÅ ÂÅĞÍÛÉ ÏÀĞÎËÜ ÈËÈ <<ESC>> ÄËß ÂÛÕÎÄÀ!" << endl;

		} while ((_kbhit() == 0) && (_getch() != 27));
		
	}

	//-------------------------------------------------------------------
	void AdminMenu_1_draw(int iItem) //Ìåíş àêêàóíòà àäìèíà
	{
		system("cls");
		SoftNameShow();
		printf("%s1. ÓÏĞÀÂËÅÍÈÅ ÏÎËÜÇÎÂÀÒÅËßÌÈ\n", iItem == 1 ? ">" : " ");
		printf("%s2. ÏĞÎÑÌÎÒĞ ÑÒÀÒÈÑÒÈÊÈ\n", iItem == 2 ? ">" : " ");
		printf("%s3. ÓÏĞÀÂËÅÍÈÅ ÒÅÑÒÈĞÎÂÀÍÈÅÌ\n", iItem == 3 ? ">" : " ");
		printf("%s4. ÂÎÇÂĞÀÒ Â ÏĞÅÄÛÄÓÙÅÅ ÌÅÍŞ\n", iItem == 4 ? ">" : " ");
	}

	void AdminMenu_1()
	{
		int iItem = 1;//Îòâå÷àåò êàêîé ïóíêò ìåíş àêòèâåí â äàííûé ìîìåíò
		int nLast = 4;//Îòâå÷àåò êàêîé èíäåêñ ó ïîñëåäíåãî ïóíêòà ìåíş
		SoftNameShow();
		AdminMenu_1_draw(iItem);
		int y = 1;
		bool choice = true;
		while (choice)
		{
			if (GetAsyncKeyState(VK_UP))
			{
				keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);//Îòæèìàåì êíîïêó
				if (0 < iItem - 1)
					iItem = iItem - 1;
				else
					iItem = nLast;
				SoftNameShow();
				AdminMenu_1_draw(iItem);
			}
			if (GetAsyncKeyState(VK_DOWN))
			{
				keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);//Îòæèìàåì êíîïêó
				if (iItem < nLast)
					iItem = iItem + 1;
				else
					iItem = 1;
				SoftNameShow();
				AdminMenu_1_draw(iItem);
			}
			if (GetAsyncKeyState(VK_RETURN))
			{
				keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);//Îòæèìàåì êíîïêó
				SoftNameShow();
				AdminMenu_1_draw(iItem);
				switch (iItem)
				{
				case 1:
				{//printf("ÓÏĞÀÂËÅÍÈÅ ÏÎËÜÇÎÂÀÒÅËßÌÈ\n");
				AdminMenu_1_1();
					choice = false;  break; }
				case 2:
				{//printf("ÏĞÎÑÌÎÒĞ ÑÒÀÒÈÑÒÈÊÈ\n");
				AdminMenu_1_2();
				choice = false; break; }
				case 3:
				{//printf("ÓÏĞÀÂËÅÍÈÅ ÒÅÑÒÈĞÎÂÀÍÈÅÌ\n");
				AdminMenu_1_3();
				choice = false; break; }
				case 4:
				{//printf("ÂÎÇÂĞÀÒ Â ÏĞÅÄÛÄÓÙÅÅ ÌÅÍŞ\n");
				FirstMenu();
				choice = false; break; }
				}
			}
		}
	}

	//-------------------------------------------------------------------
	void AdminMenu_1_1_draw(int iItem)// Ìåíş óïğàâëåíèå ïîëüçîâàòåëÿìè
	{
		system("cls");
		SoftNameShow();
		printf("%s1. ÑÎÇÄÀÍÈÅ ÀÊÊÀÓÍÒÀ ÏÎËÜÇÎÂÀÒÅËß\n", iItem == 1 ? ">" : " ");
		printf("%s2. ÈÇÌÅÍÅÍÈÅ ÀÊÊÀÓÍÒÀ ÏÎËÜÇÎÂÀÒÅËß\n", iItem == 2 ? ">" : " ");
		printf("%s3. ÓÄÀËÅÍÈÅ ÀÊÊÀÓÍÒÀ ÏÎËÜÇÎÂÀÒÅËß\n", iItem == 3 ? ">" : " ");
		printf("%s4. ÂÎÇÂĞÀÒ Â ÏĞÅÄÛÄÓÙÅÅ ÌÅÍŞ\n", iItem == 4 ? ">" : " ");
	}

	void AdminMenu_1_1()
	{
		int iItem = 1;//Îòâå÷àåò êàêîé ïóíêò ìåíş àêòèâåí â äàííûé ìîìåíò
		int nLast = 4;//Îòâå÷àåò êàêîé èíäåêñ ó ïîñëåäíåãî ïóíêòà ìåíş
		SoftNameShow();
		AdminMenu_1_1_draw(iItem);
		int y = 1;
		bool choice = true;
		while (choice)
		{
			if (GetAsyncKeyState(VK_UP))
			{
				keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);//Îòæèìàåì êíîïêó
				if (0 < iItem - 1)
					iItem = iItem - 1;
				else
					iItem = nLast;
				SoftNameShow();
				AdminMenu_1_1_draw(iItem);
			}
			if (GetAsyncKeyState(VK_DOWN))
			{
				keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);//Îòæèìàåì êíîïêó
				if (iItem < nLast)
					iItem = iItem + 1;
				else
					iItem = 1;
				SoftNameShow();
				AdminMenu_1_1_draw(iItem);
			}
			if (GetAsyncKeyState(VK_RETURN))
			{
				keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);//Îòæèìàåì êíîïêó
				SoftNameShow();
				AdminMenu_1_1_draw(iItem);
				switch (iItem)
				{
				case 1:
				{printf("ÑÎÇÄÀÍÈÅ ÀÊÊÀÓÍÒÀ ÏÎËÜÇÎÂÀÒÅËß\n");
				choice = false;  break; }
				case 2:
				{printf("ÈÇÌÅÍÅÍÈÅ ÀÊÊÀÓÍÒÀ ÏÎËÜÇÎÂÀÒÅËß\n");
				choice = false; break; }
				case 3:
				{printf("ÓÄÀËÅÍÈÅ ÀÊÊÀÓÍÒÀ ÏÎËÜÇÎÂÀÒÅËß\n");
				choice = false; break; }
				case 4:
				{//printf("ÂÎÇÂĞÀÒ Â ÏĞÅÄÛÄÓÙÅÅ ÌÅÍŞ\n");
				AdminMenu_1();
				choice = false; break; }
				}
			}
		}
	}

	//-------------------------------------------------------------------
	void AdminMenu_1_2_draw(int iItem)// Ìåíş ïğîñìîòğ ñòàòèñòèêè
	{
		system("cls");
		SoftNameShow();
		printf("%s1. ÏĞÎÑÌÎÒĞ ÑÒÀÒÈÑÒÈÊÈ ÏÎ ÊÀÒÅÃÎĞÈÈ\n", iItem == 1 ? ">" : " ");
		printf("%s2. ÏĞÎÑÌÎÒĞ ÑÒÀÒÈÑÒÈÊÈ ÏÎ ÎÏĞÅÄÅËÅÍÍÎÌÓ ÒÅÑÒÓ\n", iItem == 2 ? ">" : " ");
		printf("%s3. ÏĞÎÑÌÎÒĞ ÑÒÀÒÈÑÒÈÊÈ ÏÎ ÏÎËÜÇÎÂÀÒÅËŞ\n", iItem == 3 ? ">" : " ");
		printf("%s4. ÂÛÂÎÄ ÑÒÀÒÈÑÒÈÊÈ Â ÔÀÉË\n", iItem == 4 ? ">" : " ");
		printf("%s5. ÂÎÇÂĞÀÒ Â ÏĞÅÄÛÄÓÙÅÅ ÌÅÍŞ\n", iItem == 5 ? ">" : " ");
	}

	void AdminMenu_1_2()
	{
		int iItem = 1;//Îòâå÷àåò êàêîé ïóíêò ìåíş àêòèâåí â äàííûé ìîìåíò
		int nLast = 5;//Îòâå÷àåò êàêîé èíäåêñ ó ïîñëåäíåãî ïóíêòà ìåíş
		SoftNameShow();
		AdminMenu_1_2_draw(iItem);
		int y = 1;
		bool choice = true;
		while (choice)
		{
			if (GetAsyncKeyState(VK_UP))
			{
				keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);//Îòæèìàåì êíîïêó
				if (0 < iItem - 1)
					iItem = iItem - 1;
				else
					iItem = nLast;
				SoftNameShow();
				AdminMenu_1_2_draw(iItem);
			}
			if (GetAsyncKeyState(VK_DOWN))
			{
				keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);//Îòæèìàåì êíîïêó
				if (iItem < nLast)
					iItem = iItem + 1;
				else
					iItem = 1;
				SoftNameShow();
				AdminMenu_1_2_draw(iItem);
			}
			if (GetAsyncKeyState(VK_RETURN))
			{
				keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);//Îòæèìàåì êíîïêó
				SoftNameShow();
				AdminMenu_1_2_draw(iItem);
				switch (iItem)
				{
				case 1:
				{printf("ÏĞÎÑÌÎÒĞ ÑÒÀÒÈÑÒÈÊÈ ÏÎ ÊÀÒÅÃÎĞÈÈ\n");
				choice = false;  break; }
				case 2:
				{printf("ÏĞÎÑÌÎÒĞ ÑÒÀÒÈÑÒÈÊÈ ÏÎ ÎÏĞÅÄÅËÅÍÍÎÌÓ ÒÅÑÒÓ\n");
				choice = false; break; }
				case 3:
				{printf("ÏĞÎÑÌÎÒĞ ÑÒÀÒÈÑÒÈÊÈ ÏÎ ÏÎËÜÇÎÂÀÒÅËŞ\n");
				choice = false; break; }
				case 4:
				{printf("ÂÛÂÎÄ ÑÒÀÒÈÑÒÈÊÈ Â ÔÀÉË\n");
				choice = false; break; }
				case 5:
				{//printf("ÂÎÇÂĞÀÒ Â ÏĞÅÄÛÄÓÙÅÅ ÌÅÍŞ\n");
				AdminMenu_1();
				choice = false; break; }
			}
			}
		}
	}
	
	//-------------------------------------------------------------------
	void AdminMenu_1_3_draw(int iItem)// Ìåíş óïğàâëåíèå òåñòèğîâàíèåì
	{
		system("cls");
		SoftNameShow();
		printf("%s1. ÄÎÁÀÂËÅÍÈÅ ÊÀÒÅÃÎĞÈÈ ÒÅÑÒÀ\n", iItem == 1 ? ">" : " "); //void CreateCategory()
		printf("%s2. ÄÎÁÀÂËÅÍÈÅ ÒÅÑÒÀ\n", iItem == 2 ? ">" : " "); //void CreateTest()
		printf("%s3. ÊÎĞĞÅÊÒÈĞÎÂÊÀ ÒÅÑÒÀ\n", iItem == 3 ? ">" : " "); //void EditTest()
		printf("%s4. İÊÑÏÎĞÒ ÊÀÒÅÃÎĞÈÉ ÒÅÑÒÎÂ Â ÔÀÉË\n", iItem == 4 ? ">" : " "); //ExportCatToFile()
		printf("%s5. ÈÌÏÎĞÒ ÊÀÒÅÃÎĞÈÉ ÒÅÑÒÎÂ ÈÇ ÔÀÉËÀ\n", iItem == 5 ? ">" : " "); //ImportCatFromFile()
		printf("%s6. İÊÑÏÎĞÒ ÒÅÑÒÎÂ Â ÔÀÉË\n", iItem == 6 ? ">" : " "); //void ExportTestToFile()
		printf("%s7. ÈÌÏÎĞÒ ÒÅÑÒÀ ÈÇ ÔÀÉËÀ\n", iItem == 7 ? ">" : " ");
		printf("%s8. ÂÎÇÂĞÀÒ Â ÏĞÅÄÛÄÓÙÅÅ ÌÅÍŞ\n", iItem == 8 ? ">" : " ");
	}

	void AdminMenu_1_3()
	{
		int iItem = 1;//Îòâå÷àåò êàêîé ïóíêò ìåíş àêòèâåí â äàííûé ìîìåíò
		int nLast = 8;//Îòâå÷àåò êàêîé èíäåêñ ó ïîñëåäíåãî ïóíêòà ìåíş
		SoftNameShow();
		AdminMenu_1_3_draw(iItem);
		int y = 1;
		bool choice = true;
		while (choice)
		{
			if (GetAsyncKeyState(VK_UP))
			{
				keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);//Îòæèìàåì êíîïêó
				if (0 < iItem - 1)
					iItem = iItem - 1;
				else
					iItem = nLast;
				SoftNameShow();
				AdminMenu_1_3_draw(iItem);
			}
			if (GetAsyncKeyState(VK_DOWN))
			{
				keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);//Îòæèìàåì êíîïêó
				if (iItem < nLast)
					iItem = iItem + 1;
				else
					iItem = 1;
				SoftNameShow();
				AdminMenu_1_3_draw(iItem);
			}
			if (GetAsyncKeyState(VK_RETURN))
			{
				keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);//Îòæèìàåì êíîïêó
				SoftNameShow();
				AdminMenu_1_3_draw(iItem);
				switch (iItem)
				{
				case 1:
				{//printf("ÄÎÁÀÂËÅÍÈÅ ÊÀÒÅÃÎĞÈÈ ÒÅÑÒÀ\n");
				CreateCategory();
				choice = false;  break; }
				case 2:
				{//printf("ÄÎÁÀÂËÅÍÈÅ ÒÅÑÒÀ\n");
				CreateTest();
				choice = false; break; }
				case 3:
				{//printf("ÊÎĞĞÅÊÒÈĞÎÂÊÀ ÒÅÑÒÀ\n");
				EditTest();
				choice = false; break; }
				case 4:
				{//printf("İÊÑÏÎĞÒ ÊÀÒÅÃÎĞÈÉ ÒÅÑÒÎÂ Â ÔÀÉË\n");
				ExportCatToFile();
				choice = false; break; }
				case 5:
				{//printf("ÈÌÏÎĞÒ ÊÀÒÅÃÎĞÈÉ ÒÅÑÒÎÂ ÈÇ ÔÀÉËÀ\n");
				ImportCatFromFile();
				choice = false; break; }
				case 6:
				{//printf("İÊÑÏÎĞÒ ÒÅÑÒÎÂ Â ÔÀÉË\n");
				ExportTestToFile();
				choice = false; break; }
				case 7:
				{//printf("ÈÌÏÎĞÒ ÒÅÑÒÀ ÈÇ ÔÀÉËÀ\n");
				ImportTestFromFile();
				choice = false; break; }
				case 8:
				{//printf("ÂÎÇÂĞÀÒ Â ÏĞÅÄÛÄÓÙÅÅ ÌÅÍŞ\n");
				AdminMenu_1();
				choice = false; break; }
				}

			}
		}
		AdminMenu_1();
	}

	//-------------------------------------------------------------------
	void GuestMenu_1_draw(int iItem)// Ìåíş àêêàóíò ïîëüçîâàòåëÿ
	{
		system("cls");
		SoftNameShow();
		printf("%s1. ÑÒÀÒÈÑÒÈÊÀ ÒÅÑÒÈĞÎÂÀÍÈß\n", iItem == 1 ? ">" : " ");
		printf("%s2. ÏĞÎÉÒÈ ÒÅÑÒ\n", iItem == 2 ? ">" : " ");
		printf("%s3. ÇÀÂÅĞØÈÒÜ ÍÅ ÎÊÎÍ×ÅÍÍÛÉ ÒÅÑÒ\n", iItem == 3 ? ">" : " ");
		printf("%s4. ÂÎÇÂĞÀÒ Â ÏĞÅÄÛÄÓÙÅÅ ÌÅÍŞ\n", iItem == 4 ? ">" : " ");
	}

	void GuestMenu_1()
	{
		int iItem = 1;//Îòâå÷àåò êàêîé ïóíêò ìåíş àêòèâåí â äàííûé ìîìåíò
		int nLast = 4;//Îòâå÷àåò êàêîé èíäåêñ ó ïîñëåäíåãî ïóíêòà ìåíş
		SoftNameShow();
		GuestMenu_1_draw(iItem);
		bool choice = true;
		while (choice)
		{
			if (GetAsyncKeyState(VK_UP))
			{
				keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);//Îòæèìàåì êíîïêó
				if (0 < iItem - 1)
					iItem = iItem - 1;
				else
					iItem = nLast;
				SoftNameShow();
				GuestMenu_1_draw(iItem);
			}
			if (GetAsyncKeyState(VK_DOWN))
			{
				keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);//Îòæèìàåì êíîïêó
				if (iItem < nLast)
					iItem = iItem + 1;
				else
					iItem = 1;
				SoftNameShow();
				GuestMenu_1_draw(iItem);
			}
			if (GetAsyncKeyState(VK_RETURN))
			{
				keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);//Îòæèìàåì êíîïêó
				SoftNameShow();
				GuestMenu_1_draw(iItem);
				switch (iItem)
				{
				case 1:
				{printf("ÑÒÀÒÈÑÒÈÊÀ ÒÅÑÒÈĞÎÂÀÍÈß\n");
				choice = false;  break; }
				case 2:
				{printf("ÏĞÎÉÒÈ ÒÅÑÒ\n");
				choice = false; break; }
				case 3:
				{printf("ÇÀÂÅĞØÈÒÜ ÍÅ ÎÊÎÍ×ÅÍÍÛÉ ÒÅÑÒ\n");
				choice = false; break; }
				case 4:
				{//printf("ÂÎÇÂĞÀÒ Â ÏĞÅÄÛÄÓÙÅÅ ÌÅÍŞ\n");
				FirstMenu();
				choice = false; break; }
				}

			}
		}
	}
	
	//-------------------------------------------------------------------
		
	void CreateGuest()
	{
		bool if_log_exist = false;
		bool file_absence = false;
		char temp[50];
		char temp_address[250];
		//vector<Guest> GuestVect;
		myguest = new Guest;
		
		cout << "-----------------------------------" << endl;
		cout << "ĞÅÃÈÑÒĞÀÖÈß ÏÎËÜÇÎÂÀÒÅËß :" << endl;
		cout << "-----------------------------------" << endl;
		fstream file_read("GuestsLab.dat", ios::in | ios::binary);
		
		do
		{
			cout << "ÏÎÆÀËÓÉÑÒÀ ÂÂÈÅÄÈÒÅ ËÎÃÈÍ :" << endl;
			gets_s(temp);

			if (!file_read.is_open())
			{
				 //cout << "Error open file:" << err << endl;
				//return;
				file_absence = true;
			}
			else
			{
				file_read.seekg(0, ios::end);
				int size_of_file_in_bytes = file_read.tellg();
				int size_of_array = size_of_file_in_bytes / sizeof(Guest);

				Guest *p = new Guest[size_of_array];
				if_log_exist = false;
				
				file_read.seekg(0, ios::beg);
				for (int k = 0; k < size_of_array; k++) {
					Guest * _temp_ = new Guest;
					file_read.read((char*)_temp_, sizeof(Guest));
					*(p + k) = *_temp_;
					delete _temp_;
				}
				

				for (int i = 0; i < size_of_array; i++)
				{
					if (strcmp(p->GetGuestLogin(), temp) == 0)
					{
						cout << "ÈÇÂÈÍÈÒÅ, ÄÀÍÍÛÉ ËÎÃÈÍ ÓÆÅ ÈÑÏÎËÜÇÓÅÒÑß!" << endl;
						if_log_exist = true;
						break;
					}
				}
				delete[] p;
			}
		} while (if_log_exist);
		file_read.close();

				myguest->SetGLogin(temp);
				cout << "ÏÎÆÀËÓÉÑÒÀ, ÂÂÅÄÈÒÅ ÏÀĞÎËÜ:" << endl;
				gets_s(temp);
				myguest->SetGPass(temp);
				cout << "ÏÎÆÀËÓÉÑÒÀ, ÂÂÅÄÈÒÅ ÔÀÌÈËÈŞ:" << endl;
				gets_s(temp);
				myguest->SetGSurname(temp);
				cout << "ÏÎÆÀËÓÉÑÒÀ, ÂÂÅÄÈÒÅ ÈÌß:" << endl;
				gets_s(temp);
				myguest->SetGName(temp);
				cout << "ÏÎÆÀËÓÉÑÒÀ, ÂÂÅÄÈÒÅ ÀÄĞÅÑ:" << endl;
				gets_s(temp_address);
				myguest->SetGAddress(temp_address);
				cout << "ÏÎÆÀËÓÉÑÒÀ, ÂÂÅÄÈÒÅ ÍÎÌÅĞ ÒÅËÅÔÎÍÀ :" << endl;
				gets_s(temp);
				myguest->SetGPhone(temp);
				myguest->SetGIsRegistered(true);
								
				if (file_absence)
				{
					fstream file_write("GuestsLab.dat", ios::out | ios::trunc | ios::binary);
					if (!file_write.is_open())
					{cout << "Error to open for writing!" << endl;	}
					file_write.write((char*)(myguest), sizeof(Guest));
					file_write.flush();
					file_write.close();
				}
				if (!file_absence)
				{
					fstream file_read("GuestsLab.dat", ios::in | ios::binary);
					file_read.seekg(0, ios::end);
					int size_of_file_in_bytes = file_read.tellg();
					int size_of_array = size_of_file_in_bytes / sizeof(Guest);

					Guest *p = new Guest[size_of_array+1];//âûäåëÿåì íà îäèí ıëåìåíò áîëüøå
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
				cout << "ÏÎÇÄĞÀÂËßÅÌ, ĞÅÃÈÑÒĞÀÖÈß ÏĞÎØËÀ ÓÑÏÅØÍÎ!" << endl;
	}
	
	//-----------------------------
	
	void DeleteGuestAcc()
	{
		char templog[50], temppass[50];
		bool if_acc_deleted = false;
		
		fstream file_read("GuestsLab.dat", ios::in | ios::binary);
		if (!file_read.is_open())
		{	file_read.close();
			cout << "ÏÎËÜÇÎÂÀÒÅËÈ ÅÙÅ ÍÅ ÑÎÇÄÀÍÛ!" << endl;	Sleep(3000); return;	}

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
			cout << "ÓÊÀÆÈÒÅ ËÎÃÈÍ ÄËß ÓÄÀËÅÍÈß : ";
			cin.ignore();
			gets_s(templog);
			cout << "ÓÊÀÆÈÒÅ ÏÀĞÎËÜ ÏÎËÜÇÎÂÀÒÅËß : ";
			gets_s(temppass);
			for (int i = 0; i < VectGuests.size(); i++)
			{
				if (strcmp(VectGuests.at(i).GetGuestLogin(), templog) != 0 &&
					strcmp(VectGuests.at(i).GetGuestPass(), temppass) != 0)
				{
					cout << "ÈÇÂÈÍÈÒÅ, ÂÂÅÄÅÍÍÛÅ ÄÀÍÍÛÅ ÍÅ ÑÎÎÒÂÅÒÑÒÂÓŞÒ ËÎÃÈÍÓ ÈËÈ ÏÀĞÎËŞ!" << endl;
					cout << "ÏÎÂÒÎĞÈÒÅ ÏÎÏÛÒÊÓ!" << endl;
					break;
				}
				else
				{
					VectGuests.erase(VectGuests.begin() + i);
					if_acc_deleted = true;
				}
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
		cout << "ÂÀØ ÀÊÊÀÓÍÒ ÁÛË ÓÑÏÅØÅÎ ÓÄÀËÅÍ!"<<endl;
		
	}
	//-------------------------
	
	void CreateCategory()//ñîçäàíèå êàòåãîğèè / ïğåäìåòà (ğàáîòàåò áåç cin.ignore )
	{
		char temp[50];
		bool if_subj_avail = false;
		cout << "\nÈÌÅŞÙÈÅÑß Â ÍÀËÈ×ÈÈ ÊÀÒÅÃÎĞÈÈ :" << endl;

		fstream file_read("SubjLab.dat", ios::in | ios::binary);
		if (!file_read.is_open())
		{
			file_read.close();
			cout << "Â ÍÀËÈ×ÈÈ ÅÙÅ ÍÅÒ ÏĞÅÄÌÅÒÎÂ..." << endl;
			cout << "\nÂÂÅÄÈÒÅ ÍÀÇÂÀÍÈÅ ÏĞÅÄÌÅÒÀ ÄËß ÒÅÑÒÈĞÎÂÀÍÈß : ";
			//cin.ignore();
			gets_s(temp);
			//cout<<"TEST = "<<temp<<endl;// this is test
			for (int i = 0; i < 50; i++) temp[i] = toupper(temp[i]);
			//	cout<<"TEST = "<<temp<<endl;// this is test
			fstream file_write("SubjLab.dat", ios::out | ios::trunc | ios::binary);
			if (!file_write.is_open())
			{
				cout << "Error to open for writing!" << endl;
			}
			file_write.write(temp, sizeof(char) * 50);
			file_write.close();
			cout << "ÊÀÒÅÃÎĞÈß / ÏĞÅÄÌÅÒ ÓÑÏÅØÍÎ ÑÎÇÄÀÍÛ!" << endl;

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
				cout << "\nÂÂÅÄÈÒÅ ÍÀÇÂÀÍÈÅ ÏĞÅÄÌÅÒÀ ÄËß ÒÅÑÒÈĞÎÂÀÍÈß : ";
				//cin.ignore();
				gets_s(temp);
				//cout<<"TEST = "<<temp<<endl;// this is test
				for (int i = 0; i < 50; i++) temp[i] = toupper(temp[i]);
				//cout<<"TEST = "<<temp<<endl;// this is test
				for (int i = 0; i < size_of_array; i++)
				{
					if (strcmp(subjectslab[i], temp) == 0)
					{
						cout << "ÈÇÂÈÍÈÒÅ, ÊÀÒÅÃÎĞÈß " << subjectslab[i] << " ÓÆÅ ÈÌÅÅÒÑß!" << endl;
						cout << "ÂÛÁÈĞÈÒÅ ÄĞÓÃÓŞ ÊÀÒÅÃÎĞÈŞ ÏĞÅÄÌÅÒÀ!" << endl;
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
			cout << "ÊÀÒÅÃÎĞÈß / ÏĞÅÄÌÅÒ ÓÑÏÅØÍÎ ÑÎÇÄÀÍÛ!" << endl;

		}
	}

				
	void CreateTest()
{
	char temp[50];
	char temp_coice;
	char test_name_temp[50];
	char test_name_temp_index[10];
	
	cout << "ÄÎÁÀÂËÅÍÈÅ ÒÅÑÒÀ.." << endl;
	cout << "ÈÌÅŞÙÈÅÑß Â ÍÀËÈ×ÈÈ ÊÀÒÅÃÎĞÈÈ / ÏĞÅÄÌÅÒÛ :" << endl;
	
	fstream file_read("SubjLab.dat", ios::in | ios::binary);
	if (!file_read.is_open())
	{	cout << "ÎØÈÁÊÀ ÏĞÈ ÎÒÊĞÛÒÈÈ ÔÀÉËÀ!" << endl;	}
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

		cout << "ÓÊÀÆÈÒÅ ÍÎÌÅĞ ÏĞÅÄÌÅÒÀ ÄËß ÇÀÏÎËÍÅÍÈß ÒÅÑÒÀ :" << endl;
		cout << "ÓÊÀÆÈÒÅ ÄËß ÑÎÇÄÀÍÈß ÏÎÄÕÎÄßÙÅÃÎ ÏĞÅÄÌÅÒÀ - 9 :";
		for (;;) {
		cin >> temp_coice;
			if (temp_coice == '9' || ((temp_coice - '0' >= 0) && (temp_coice - '0' < size_of_array)))
				break;
			else 
				cout << "ÑÄÅËÀÉÒÅ ÏĞÀÂÈËÜÍÛÉ ÂÛÁÎĞ!" << endl; 
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
				cout << "Â ÍÀËÈÈ×ÈÈ ÅÙÅ ÍÅÒ ÒÅÑÒÎÂ..." << endl;
				Test * firstsign = new Test[1];
				
				strcat(test_name_temp, subjectslab[temp_coice - '0']);//ñîçäàíèå èìåíè òåñòà
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
				cout << "ÒÅÑÒ ÓÑÏÅØÍÎ ÑÎÇÄÀÍ!" << endl;
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
				
				mytestobj = new Test[1];
				strcat(test_name_temp, subjectslab[temp_coice - '0']);
				strcat(test_name_temp, "-");
				itoa(VectTests.size(), test_name_temp_index, 10);
				strcat(test_name_temp, test_name_temp_index);
				mytestobj ->SetTest(subjectslab[temp_coice - '0'], test_name_temp);
				VectTests.push_back(*mytestobj);

				Test *p_out = new Test[VectTests.size()];

				for (int i = 0; i < VectTests.size(); i++)
				{	*(p_out + i) = VectTests.at(i);	}

				fstream file_write("TestsLab.dat", ios::out | ios::trunc | ios::binary);
				if (!file_write.is_open())
				{	cout << "Error to open for writing!" << endl;	}
				for (int k = 0; k < VectTests.size(); k++)
				{
					file_write.write((char*)(p_out + k), sizeof(Test));
				}
				file_write.flush();
				file_write.close();
				
				delete[]p;
				delete[]mytestobj;
				delete[]p_out;
				cout << "ÒÅÑÒ ÓÑÏÅØÍÎ ÄÎÁÀÂËÅÍ!" << endl;

			}
		}
		Sleep(5000);
		AdminMenu_1_3();

	}

	
	
}
//--------------------------------------------------------------------------------

	void TestPassing()
	{
		char temp[50];
		char temp_coice;

		cout << "ÒÅÑÒÈĞÎÂÀÍÈÅ..." << endl;
		cout << "ÈÌÅŞÙÈÅÑß Â ÍÀËÈ×ÈÈ ÊÀÒÅÃÎĞÈÈ / ÏĞÅÄÌÅÒÛ :" << endl;

		fstream file_read("SubjLab.dat", ios::in | ios::binary);
		if (!file_read.is_open())
		{
			cout << "ÎØÈÁÊÀ ÎÒÊĞÛÒÈß ÔÀÉËÀ!" << endl;
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

			cout << "ÓÊÀÆÈÒÅ ÍÎÌÅĞ ÏĞÅÄÌÅÒÀ ÄËß ÂÛÂÎÄÀ ÂÑÅÕ ÒÅÑÒÎÂ ÏÎ ÏĞÅÄÌÅÒÓ:" << endl;
			cout << "ÄËß ÂÛÕÎÄÀ Â ÏĞÅÄÛÄÓÙÅÅ ÌÅÍŞ - 9 : ";
			for (;;) {
				cin >> temp_coice;
				if (temp_coice == '9' || ((temp_coice - '0' >= 0) && (temp_coice - '0' < size_of_array)))
					break;
				else
					cout << "ÑÄÅËÀÉÒÅ ÏĞÀÂÈËÜÍÛÉ ÂÛÁÎĞ!" << endl;
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
					cout << "Â ÍÀËÈ×ÈÈ ÅÙÅ ÍÅÒ ÒÅÑÒÎÂ..." << endl;
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
					delete[]p;

					for (int i = 0; i < VectTests.size(); i++)
					{
						cout << "\nÍÎÌÅĞ ÒÅÑÒÀ " << i << ":" << endl;
						cout << "-------------------------------------------------------------------" << endl;
						VectTests.at(i).DisplayTest();
					}
					cout << "ÓÊÀÆÈÒÅ ÍÎÌÅĞ ÒÅÑÒÀ ÏĞÎÕÎÆÄÅÍÈß :" << endl;

					for (;;) {
						cin >> temp_coice;
						if ((temp_coice - '0' >= 0) || (temp_coice - '0' < VectTests.size()))
							break;
						else
							cout << "ÑÄÅËÀÉÒÅ ÏĞÀÂÈËÜÍÛÉ ÂÛÁÎĞ!" << endl;
					}
					//--------------------------------------------------------------
					
					
					Statistic * my_test_stat = new Statistic;
						
					/*fstream file_read("StatLab.dat", ios::in | ios::binary);
					if (!file_read.is_open())
					{
						file_read.close();
						fstream file_write("StatLab.dat", ios::out | ios::trunc | ios::binary);
						if (!file_write.is_open())
						{
							cout << "Error to open for writing!" << endl;
						}
						file_write.write((char*)(myguest), sizeof(Statistic));
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
					}*/
					
					//// statistic record
					//fstream file_write("StatLab.dat", ios::out | ios::trunc | ios::binary);
					//if (!file_write.is_open())
					//{	cout << "Error to open for writing!" << endl;}

					//for (int k = 0; k < size_of_array; k++)
					//{
					//	file_write.write((char*)(p_stat + k), sizeof(Statistic));
					//}
					//file_write.flush();
					//file_write.close();
						
		//--------------------------------------------------------------
					cout << "ÒÅÑÒÈĞÎÂÀÍÈÅ..." << endl;
					VectTests.at(temp_coice - '0').DisplayTest();

					cout << "ÓÊÀÆÈÒÅ ÍÎÌÅĞ ÏĞÀÂËÜÍÎÃÎ ÎÒÂÅÒÀ ÍÀ ÂÎÏĞÎÑ ¹1 :" << endl;

					cout << "ÓÊÀÆÈÒÅ ÍÎÌÅĞ ÏĞÀÂËÜÍÎÃÎ ÎÒÂÅÒÀ ÍÀ ÂÎÏĞÎÑ ¹2 :" << endl;
					
					cout << "-------------------------------------------" << endl;
					cout << "ĞÅÇÓËÜÒÀÒ ÏÎ ÄÀÍÍÎÌÓ ÒÅÑÒÓ :" << endl;

					cout << "ÎÒÂÅÒ ÍÀ ÂÎÏĞÎÑ ¹1 :" << endl;

					cout << "ÎÒÂÅÒ ÍÀ ÂÎÏĞÎÑ ¹2 :" << endl;

					cout << "ÊÎËÈ×ÅÑÒÂÎ ÂÅĞÍÛÕ ÎÒÂÅÒÎÂ : " << endl;

					cout << "ÎÖÅÍÊÀ ÏÎ ÄÀÍÍÎÌÓ ÒÅÑÒÓ : " << endl;
					cout << "-------------------------------------------" << endl;

				}
			}
		}
	}

	void EditGuest()
	{

	}

	
	void ShowStatistic()
	{

	}

	void SaveStatisticToFile()
	{

	}

	void ImportCatFromFile()// Ğàáîòàåò!
	{
		char temp[50];
		bool if_subj_avail = false;
		string bufStr;
		vector<string> TempVect;
		vector<string> TempVectWithoutDupl;
		cout << "ÈÌÏÎĞÒ ÊÀÒÅÃÎĞÈÉ ÈÇ ÔÀÉËÀ..." << endl;
		cout << "ÈÌÅŞÙÈÅÑß Â ÍÀËÈ×ÈÈ ÊÀÒÅÃÎĞÈÈ :" << endl;

		fstream file_read("SubjLab.dat", ios::in | ios::binary);
		if (!file_read.is_open())
		{
			file_read.close();
			cout << "Â ÍÀËÈ×ÈÈ ÅÙÅ ÍÅÒ ÏĞÅÄÌÅÒÎÂ..." << endl;
			cout << "ÓÊÀÆÈÒÅ ÈÌß ÔÀÉËÀ ÄËß ÈÌÏÎĞÒÀ ÊÀÒÅÃÎĞÈÉ / ÏĞÅÄÌÅÒÎÂ: " << endl;
			cout << "ÍÀÏĞÈÌÅĞ, C:\\Categories.txt " << endl;
			cout << "ÏĞÅÄÌÅÒÛ ÄÎËÆÍÛ ÁÛÒÜ Â ÒÅÊÑÒÎÂÎÌ ÔÀÉËÅ, ÊÀÆÄÛÉ ÏĞÅÄÌÅÒ Ñ ÍÎÂÎÉ ÑÒĞÎÊÈ.. :" << endl;
			gets_s(temp);
			//gets(temp);

			ifstream inp(temp, ios::in);
			inp.seekg(0);
			if (!inp)
			{
				cout << "Ôàéëà íåò\n";
				//system("pause"); 
			}

			while (!inp.eof())
			{
				getline(inp, bufStr, '\n');
				TempVect.push_back(bufStr);
			}
			inp.close();

			//	for (int i = 0; i< TempVect.size(); i++)
			//	cout<<TempVect.at(i)<<endl;
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
			for (int k = 0; k < TempVect.size() + 1; k++)
			{
				file_write.write((subjectslab[k]), sizeof(char) * 50);
			}
			file_write.flush();
			file_write.close();
			cout << "ÊÀÒÅÃÎĞÈÈ ÓÑÏÅØÍÎ ÈÌÏÎĞÒÈĞÎÂÀÍÛ Â ÏĞÎÃĞÀÌÌÓ Ñ ÔÀÉËÀ!" << endl;

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
				cout << "ÏĞÅÄÌÅÒ ¹ " << k << " " << subjectslab[k] << endl;
			}

			//Ñ÷èòûâàåì èç ôàéëà êàòåãîğèè
			cout << "ÓÊÀÆÈÒÅ ÈÌß ÔÀÉËÀ ÄËß ÈÌÏÎĞÒÀ ÊÀÒÅÃÎĞÈÉ / ÏĞÅÄÌÅÒÎÂ: " << endl;
			cout << "ÍÀÏĞÈÌÅĞ, C:\\Categories.txt " << endl;
			cout << "ÏĞÅÄÌÅÒÛ ÄÎËÆÍÛ ÁÛÒÜ Â ÒÅÊÑÒÎÂÎÌ ÔÀÉËÅ, ÊÀÆÄÛÉ ÏĞÅÄÌÅÒ Ñ ÍÎÂÎÉ ÑÒĞÎÊÈ.. :" << endl;
			gets_s(temp);
			//gets(temp);

			ifstream inp(temp, ios::in);
			inp.seekg(0);
			if (!inp)
			{
				cout << "Ôàéëà íåò\n";
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


			//Óäàëÿåì äóáëèêàòû êàòåãîğèé èç áàçû

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

			cout << "ÊÀÒÅÃÎĞÈÈ ÓÑÏÅØÍÎ ÈÌÏÎĞÒÈĞÎÂÀÍÛ Ñ ÔÀÉËÀ Â ÏĞÎÃĞÀÌÌÓ!" << endl;

		}
	}

	
	void ExportCatToFile()
	{

		char temp[50];
		cout << "İÊÑÏÎĞÒ ÊÀÒÅÃÎĞÈÉ / ÏĞÅÄÌÅÒÎÂ Â ÔÀÉË..." << endl;
		cout << "ÈÌÅŞÙÈÅÑß Â ÍÀËÈ×ÈÈ ÊÀÒÅÃÎĞÈÈ / ÏĞÅÄÌÅÒÛ :" << endl;

		fstream file_read("SubjLab.dat", ios::in | ios::binary);
		if (!file_read.is_open())
		{
			cout << "ÏĞÎÃĞÀÌÌÀ ÅÙÅ ÍÅ ÈÌÅÅÒ ÊÀÒÅÃÎĞÈÉ!!" << endl;
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

			cout << "\nÓÊÀÆÈÒÅ ÈÌß ÔÀÉËÀ ÄËß ÈÌÏÎĞÒÀ ÊÀÒÅÃÎĞÈÉ / ÏĞÅÄÌÅÒÎÂ: " << endl;
			cout << "ÍÀÏĞÈÌÅĞ, C:\\Categories.txt :" << endl;
			gets_s(temp);
			//gets(temp);

			fstream file_write(temp, ios::out | ios::trunc);

			if (!file_write.is_open())
			{
				cout << "Error to open for writing!" << endl;
			}
			file_write << "=========================================================" << endl;
			file_write << "ÏĞÎÃĞÀÌÌÀ ÏÎ ÒÅÑÒÈĞÎÂÀÍÈŞ ÑÒÓÄÅÍÒÎÂ ÏÎ ÏĞÅÄÌÅÒÀÌ" << endl;
			file_write << "ÌÀÒÅÌÀÒÈÊÀ, ÔÈÇÈÊÀ È Ò.Ä." << endl;
			file_write << "                                          <<ÒÅÑÒÎĞ 2018>>" << endl;
			file_write << "=========================================================" << endl;
			file_write << "-------------------------------------------------------------------------------------------" << endl;
			file_write << "İÊÑÏÎĞÒ ÊÀÒÅÃÎĞÈÉ / ÏĞÅÄÌÅÒÎÂ ÈÇ ÏĞÎÃĞÀÌÌÛ" << endl;
			file_write << "-------------------------------------------------------------------------------------------" << endl;
			for (int i = 0; i< size_of_array; i++)
			{
				file_write << "ÏĞÅÄÌÅÒ ¹ " << i + 1 << "  " << subjectslab[i] << endl;
			}
			file_write << "-------------------------------------------------------------------------------------------" << endl;
			file_write.flush();
			file_write.close();
						
			cout << "ÏĞÅÄÌÅÒÛ ÓÑÏÅØÍÎ İÊÑÏÎĞÒÈĞÎÂÀÍÛ Â ÓÊÀÇÀÍÍÛÉ ÔÀÉË!" << endl;

			Sleep(5000); AdminMenu_1_3();	
		}


	}


	void EditTest()
	{
		char temp[50];
		char temp_coice;

		cout << "ÊÎĞĞÅÊÒÈĞÎÂÊÀ ÒÅÑÒÀ.." << endl;
		cout << "ÈÌÅŞÙÈÅÑß Â ÍÀËÈ×ÈÈ ÊÀÒÅÃÎĞÈÈ / ÏĞÅÄÌÅÒÛ :" << endl;

		fstream file_read("SubjLab.dat", ios::in | ios::binary);
		if (!file_read.is_open())
		{
			cout << "ÎØÈÁÊÀ ÎÒÊĞÛÒÈß ÔÀÉËÀ!" << endl;
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

			cout << "ÓÊÀÆÈÒÅ ÍÎÌÅĞ ÏĞÅÄÌÅÒÀ ÄËß ÂÛÂÎÄÀ ÂÑÅÕ ÒÅÑÒÎÂ ÏÎ ÏĞÅÄÌÅÒÓ:" << endl;
			cout << "ÄËß ÂÛÕÎÄÀ Â ÏĞÅÄÛÄÓÙÅÅ ÌÅÍŞ - 9 : ";
			for (;;) {
				cin >> temp_coice;
				if (temp_coice == '9' || ((temp_coice - '0' >= 0) && (temp_coice - '0' < size_of_array)))
					break;
				else
					cout << "ÑÄÅËÀÉÒÅ ÏĞÀÂÈËÜÍÛÉ ÂÛÁÎĞ!" << endl;
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
					cout << "Â ÍÀËÈ×ÈÈ ÅÙÅ ÍÅÒ ÒÅÑÒÎÂ..." << endl;
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

					for (int i = 0; i < VectTests.size(); i++)
					{
						cout << "ÍÎÌÅĞ ÒÅÑÒÀ " << i << ":" << endl;
						cout << "-------------------------------------------------------------------" << endl;
						VectTests.at(i).DisplayTest();
					}
					cout << "ÓÊÀÆÈÒÅ ÍÎÌÅĞ ÒÅÑÒÀ ÄËß ÊÎĞĞÅÊÒÈĞÎÂÊÈ  :" << endl;

					for (;;) {
						cin >> temp_coice;
						if ((temp_coice - '0' >= 0) || (temp_coice - '0' < VectTests.size()))
							break;
						else
							cout << "ÑÄÅËÀÉÒÅ ÏĞÀÂÈËÜÍÛÉ ÂÛÁÎĞ!" << endl;
					}

					//êîğğåêòèğîâêà òåñòà!	
					char temp_semi_subj[500], temp_quest[500], temp_answ[4][50];
					int temp_cor_answ;
					Test obj;
					VectTests.at(temp_coice - '0').DisplayTest();
					obj = VectTests.at(temp_coice - '0');
					Question temp_arr[2];
					for (int i = 0; i < 2; i++)
					{
						
						cout << "ÏÎÆÀËÓÉÑÒÀ, ÓÊÀÆÈÒÅ ÍÎÂÎÅ ÍÀÏĞÀÂËÅÍÈÅ ÒÅÑÒÀ:" << endl;
						cout << "ÍÀÏĞÈÌÅĞ, ÊÂÀÍÒÎÂÀß ÔÈÇÈÊÀ.." << endl;
						cin.ignore();
						gets_s(temp_semi_subj);
						//cin >> temp_str;
						cout << "ÓÊÀÆÈÒÅ ÂÎÏĞÎÑ :" << endl;
						gets_s(temp_quest);
						//cin >> temp_str;
						cout << "ÓÊÀÆÈÒÅ ËÎÆÍÛÉ ÎÒÂÅÒ ¹1 ÍÀ ÂÎÏĞÎÑ :" << endl;
						gets_s(temp_answ[0]);
						//cin >> temp_str;
						cout << "ÓÊÀÆÈÒÅ ËÎÆÍÛÉ ÎÒÂÅÒ ¹2 ÍÀ ÂÎÏĞÎÑ :" << endl;
						gets_s(temp_answ[1]);
						//cin >> temp_str;
						cout << "ÓÊÀÆÈÒÅ ËÎÆÍÛÉ ÎÒÂÅÒ ¹3 ÍÀ ÂÎÏĞÎÑ :" << endl;
						gets_s(temp_answ[2]);
						//cin >> temp_str;
						cout << "ÓÊÀÆÈÒÅ ÊÎĞĞÅÊÒÍÛÉ ÎÒÂÅÒ ÍÀ ÂÎÏĞÎÑ :" << endl << endl;
						gets_s(temp_answ[3]);
						//cin >> temp_str;
						temp_cor_answ = 3;
						temp_arr[i].SetQuestionArg(temp_semi_subj, temp_quest, temp_answ[0], temp_answ[1],
							temp_answ[2], temp_answ[3], temp_cor_answ);

					}
					obj.SetArrQuestions(temp_arr);
					VectTests.erase(VectTests.begin() + (temp_coice - '0'));
					VectTests.push_back(obj);
					//çàïèñü ìàñèâà òåñòîâ â ôàéë
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
					cout << "ÒÅÑÒ ÓÑÏÅØÍÎ ÎÒĞÅÄÀÊÒÈĞÎÂÀÍ!!!" << endl;

				}
			}
			Sleep(5000);
			AdminMenu_1_3();

		}

	}

	void ExportTestToFile()
	{
		char temp[50];
		char temp_coice;

		cout << "İÊÑÏÎĞÒ ÒÅÑÒÀ Â ÔÀÉË.." << endl;
		cout << "ÈÌÅŞÙÈÅÑß Â ÍÀËÈ×ÈÈ ÊÀÒÅÃÎĞÈÈ / ÏĞÅÄÌÅÒÛ :" << endl;

		fstream file_read("SubjLab.dat", ios::in | ios::binary);
		if (!file_read.is_open())
		{cout << "ÎØÈÁÊÀ ÏĞÈ ÎÒÊĞÛÒÈÈ ÔÀÉËÀ!" << endl;	}
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

			cout << "ÓÊÀÆÈÒÅ ÍÎÌÅĞ ÏĞÅÄÌÅÒÀ ÄËß ÂÛÂÎÄÀ ÂÑÅÕ ÒÅÑÒÎÂ ÏÎ ÏĞÅÄÌÅÒÓ :" << endl;
			cout << "ÄËß ÂÛÕÎÄÀ Â ÏĞÅÄÛÄÓÙÅÅ ÌÅÍŞ - 9 : ";
			for (;;) {
				cin >> temp_coice;
				if (temp_coice == '9' || ((temp_coice - '0' >= 0) && (temp_coice - '0' < size_of_array)))
					break;
				else
					cout << "ÑÄÅËÀÉÒÅ ÏĞÀÂÈËÜÍÛÉ ÂÛÁÎĞ!" << endl;
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
					cout << "Â ÍÀËÈÈ×ÈÈ ÅÙÅ ÍÅÒ ÒÅÑÒÎÂ..." << endl;
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
						cout << "ÍÎÌÅĞ ÒÅÑÒÀ ¹ "<<i <<":"<< endl;
						cout << "-------------------------------------------------------------------" << endl;
						VectTests.at(i).DisplayTest();
					}
					cout << "ÓÊÀÆÈÒÅ ÍÎÌÅĞ ÒÅÑÒÀ ÄËß ÂÛÂÎÄÀ Â ÔÀÉË ¹  :" << endl;
					
					for (;;) {
						cin >> temp_coice;
						if ( (temp_coice - '0' >= 0) || (temp_coice - '0' < VectTests.size()) )
							break;
						else
							cout << "ÑÄÅËÀÉÒÅ ÏĞÀÂÈËÜÍÛÉ ÂÛÁÎĞ!" << endl;
					}

					mytestobj = new Test[1];
					*mytestobj = VectTests.at(temp_coice - '0');
					
					fstream file_write("TestsExport.txt", ios::out | ios::trunc);
					//	fstream file_write("TestsExport.txt", ios::out);

					if (!file_write.is_open())
					{
						cout << "Error to open for writing!" << endl;
					}
					file_write << "=========================================================" << endl;
					file_write << "ÏĞÎÃĞÀÌÌÀ ÏÎ ÒÅÑÒÈĞÎÂÀÍÈŞ ÑÒÓÄÅÍÒÎÂ ÏÎ ÏĞÅÄÌÅÒÀÌ" << endl;
					file_write << "ÌÀÒÅÌÀÒÈÊÀ, ÔÈÇÈÊÀ È Ò.Ä." << endl;
					file_write << "                                          <<ÒÅÑÒÎĞ 2018>>" << endl;
					file_write << "=========================================================" << endl;
					file_write << "ÏÅ×ÀÒÜ ÒÅÑÒÀ ¹ " << temp_coice << endl;
					file_write << "---------------------------------------------------------------------------" << endl;
					file_write << "ÏĞÅÄÌÅÒ ÒÅÑÒÀ - " << mytestobj->GetTestSubjName() << endl;

					file_write<<"ÍÀÏĞÀÂËÅÍÈÅ ÂÎÏĞÎÑÀ ¹1 :"<<endl;
					file_write<< mytestobj->GetQuestArr()[0].semi_subject<<endl;
					file_write<<"ÂÎÏĞÎÑ ¹1 :"<<endl;
					file_write<< mytestobj->GetQuestArr()[0].question<<endl;

					for (int i = 0 ; i< 4; i++)
					{
					file_write<<"ÎÒÂÅÒ ¹ "<< i+1<< " ÍÀ ÂÎÏĞÎÑ ¹1 :"<<endl;
					file_write<< mytestobj->GetQuestArr()[0].answers_arr[i]<<endl;
	
					if (mytestobj->GetQuestArr()[0].correct_answ_arr[i] == true)
					file_write<<"\nÏĞÀÂÈËÜÍÛÉ ÎÒÂÅÒ ¹ "<< i+1<< " ÍÀ ÂÎÏĞÎÑ ¹1."<<endl;

					}

					file_write<<"\nÍÀÏĞÀÂËÅÍÈÅ ÂÎÏĞÎÑÀ ¹2 :"<<endl;
					file_write<< mytestobj->GetQuestArr()[1].semi_subject<<endl;
					file_write<<"ÂÎÏĞÎÑ ¹2 :"<<endl;
					file_write<< mytestobj->GetQuestArr()[1].question<<endl;

					for (int i = 0 ; i< 4; i++)
					{
					file_write<<"ÎÒÂÅÒ ¹ "<< i+1<< " ÍÀ ÂÎÏĞÎÑ ¹2 :"<<endl;
					file_write<< mytestobj->GetQuestArr()[1].answers_arr[i]<<endl;
										
					if (mytestobj->GetQuestArr()[1].correct_answ_arr[i] == true)
					file_write<<"\nÏĞÀÂÈËÜÍÛÉ ÎÒÂÅÒ ¹ "<< i+1<< " ÍÀ ÂÎÏĞÎÑ ¹2"<<endl;

					}
					file_write<<"---------------------------------------------------------------------------"<<endl;
					file_write.flush();
					file_write.close();

					delete[]mytestobj;
					cout << "ÒÅÑÒ ÓÑÏÅØÍÎ İÊÑÏÎĞÒĞÎÂÀÍ Â ÓÊÀÇÀÍÍÛÉ ÔÀÉË!" << endl;

				}
			}
			Sleep(5000);
			AdminMenu_1_3();

		}




	}

	void ImportTestFromFile()
	{
		char temp[50];
		char temp_coice;

		cout << "ÈÌÏÎĞÒ ÒÅÑÒÀ ÈÇ ÔÀÉËÀ.." << endl;
		cout << "ÈÌÅŞÙÈÅÑß Â ÍÀËÈ×ÈÈ ÊÀÒÅÃÎĞÈÈ / ÏĞÅÄÌÅÒÛ :" << endl;

		fstream file_read("SubjLab.dat", ios::in | ios::binary);
		if (!file_read.is_open())
		{
			cout << "ÎØÈÁÊÀ ÏĞÈ ÎÒÊĞÛÒÈÈ ÔÀÉËÀ!" << endl;
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

			cout << "ÓÊÀÆÈÒÅ ÍÎÌÅĞ ÏĞÅÄÌÅÒÀ ÄËß ÈÌÏÎĞÒÀ ÒÅÑÒÀ Â ÁÀÇÓ :" << endl;
			cout << "ÄËß ÂÛÕÎÄÀ Â ÏĞÅÄÛÄÓÙÅÅ ÌÅÍŞ - 9 : ";
			for (;;) {
				cin >> temp_coice;
				if (temp_coice == '9' || ((temp_coice - '0' >= 0) && (temp_coice - '0' < size_of_array)))
					break;
				else
					cout << "ÑÄÅËÀÉÒÅ ÏĞÀÂÈËÜÍÛÉ ÂÛÁÎĞ!" << endl;
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
				//, answers0 = "", answers1 = "", answers2 = "", answers3 = "",
				//correct_answ = "";
				char temp_semi_subj[500], temp_question[500], temp_answ0[50], temp_answ1[50],
					temp_answ2[50], temp_answ3[50];
				char correct_answ;
				int temp_corr_answ;
				ifstream import("ImportTest.txt", ios::in);
				import.seekg(0);
				if (!import)
				{	cout << "ÎØÈÁÊÀ ÎÒÊĞÛÒÈß ÔÀÉËÀ\n";	system("pause");}

				/*while (!import.eof())
				{*/
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
				/*}*/
				import.close();
				mytestobj->SetTestSubjName(subjectslab[temp_coice - '0']);
				mytestobj->SetArrQuestions(temp_quest_arr);
				
				mytestobj->DisplayTest();


				delete[]mytestobj;
			}
		}
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
	//myadmin.FirstMenu();
	myadmin.EnterToGuestAcc();
	//myadmin.CreateGuest();
	//myadmin.DeleteGuestAcc();

	//myadmin.AdminMenu_1_3();+++
	//myadmin.CreateGuest();
	//myadmin.CreateGuest();
	//myadmin.DeleteGuestAcc();
	
	//myadmin.CreateTest();+
	//myadmin.ExportTestToFile(); +
	//myadmin.EditTest();//+
	//myadmin.ImportTestFromFile();//+ äîäåëàòü çàïèñü â ôàéë..
	//myadmin.CreateCategory();//+
	//myadmin.ExportCatToFile();
	//myadmin.ImportCatFromFile();
	
	
	//	system ("pause");
	return 0;
}