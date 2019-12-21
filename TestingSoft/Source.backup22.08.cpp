//Ïğîãğàììà äëÿ òåñòèğîâàíèÿ ñòóäåíòîâ "Òåñòîğ 2018"
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


class Question // êëàññ äëÿ õğàíåíèÿ èíôîğìàöèè ïî êàæäîìó âîïğîñó òåñòà
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

	void SetQuestion()//Çàïîëåíèå äàííûìè âîïğîñà
	{
		string temp_str;
		char temp_quest[500], temp_answ[50];
		cout << "ÏÎÆÀËÓÉÑÒÀ, ÓÊÀÆÈÒÅ ÍÀÏĞÀÂËÅÍÈÅ ÒÅÑÒÀ:" << endl;
		cout << "ÍÀÏĞÈÌÅĞ, ÊÂÀÍÒÎÂÀß ÔÈÇÈÊÀ.." << endl;
		gets_s(temp_quest);
		strcpy(semi_subject, temp_quest);
		cout << "ÓÊÀÆÈÒÅ ÂÎÏĞÎÑ :" << endl;
		gets_s(temp_quest);
		strcpy(question, temp_quest);
		cout << "ÓÊÀÆÈÒÅ ËÎÆÍÛÉ ÎÒÂÅÒ ¹1 ÍÀ ÂÎÏĞÎÑ :" << endl;
		gets_s(temp_answ);
		strcpy(answers_arr[0], temp_answ);
		correct_answ_arr[0] = false;
		cout << "ÓÊÀÆÈÒÅ ËÎÆÍÛÉ ÎÒÂÅÒ ¹2 ÍÀ ÂÎÏĞÎÑ :" << endl;
		gets_s(temp_answ);
		strcpy(answers_arr[1], temp_answ);
		correct_answ_arr[1] = false;
		cout << "ÓÊÀÆÈÒÅ ËÎÆÍÛÉ ÎÒÂÅÒ ¹3 ÍÀ ÂÎÏĞÎÑ :" << endl;
		gets_s(temp_answ);
		strcpy(answers_arr[2], temp_answ);
		correct_answ_arr[2] = false;
		cout << "ÓÊÀÆÈÒÅ ÊÎĞĞÅÊÒÍÛÉ ÎÒÂÅÒ ÍÀ ÂÎÏĞÎÑ :" << endl << endl;
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

	void DisplayQuestion()// ïîêàç âîïğîñîâ
	{
		cout << "ÊÀÒÅÃÎĞÈß ÂÎÏĞÎÑÀ : " << endl; cout << semi_subject << endl;
		cout << "ÂÎÏĞÎÑ ¹1" << endl;
		cout << question << endl;
		cout << "Âàğèàíò ¹1 " << answers_arr[0] << "        Âàğèàíò ¹2 " << answers_arr[1] << endl;
		cout << "Âàğèàíò ¹3 " << answers_arr[2] << "        Âàğèàíò ¹4 " << answers_arr[3] << endl <<endl;

	}

};

class Test : public Question //Êëàññ òåñò, êîòîğûé íàñëåäóåòñÿ îò ïğåäûäóùåãî. Êëàññ Òåñò ñîñòîèò èç 2õ âîïğîñîâ
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

	void SetTest(char * str, char * str1)// çàïîëåíèå äàííûìè Òåñòà
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

	void DisplayTest()// âûâîä íà ıêğàí òåñòà äëÿ àäìèíèñòğàòîğà, ñ äàííûìè ïî ïğàâèëüíûì îòâåòàì
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
	
		void DisplayTestForPassing()// âûâîä íà ıêğàí òåñòà äëÿ ïîëüçîâàòåëÿ ïğè ïğîõîæäåíèè òåñòà
	{
			
		cout << "--------------------------------------------------------------------" << endl;
		cout << "ÄÀÍÍÛÉ ÒÅÑÒ ÏÎ ÏĞÅÄÌÅÒÓ : " << subject_name << endl;
		cout << "ÍÀÇÂÀÍÈÅ ÒÅÑÒÀ          : " << test_name << endl;
		cout << "--------------------------------------------------------------------" << endl;
		
			cout << "ÍÀÏĞÀÂËÅÍÈÅ ÒÅÑÒÀ:" << endl;
			cout << "..................................................................." << endl;
			cout << array_of_questions_per_test[0].semi_subject << endl;
			cout << "ÂÎÏĞÎÑ ¹ "<<1<<" :" << endl;
			cout << array_of_questions_per_test[0].question << endl;
			
			for (int j = 0; j < 4; j++)
				strcpy(&*temp_answ_arr1[j], array_of_questions_per_test[0].answers_arr[j]); 
			random_shuffle(temp_answ_arr1, temp_answ_arr1 + sizeof(temp_answ_arr1) / sizeof(*temp_answ_arr1));
			for (int j = 0; j < 4; j++)
			{
				cout << "ÂÀĞÈÀÍÒ ÎÒÂÅÒÀ ¹ "<<j+1<<" ÍÀ ÂÎÏĞÎÑ ¹" << 0 + 1 << " :" << endl;
				cout << temp_answ_arr1[j] << endl;
			}
					
			cout << endl;
			for (int j = 0; j < 4; j++)
			{				
				strcpy(&*temp_answ_arr2[j], array_of_questions_per_test[1].answers_arr[j]);
			}
			random_shuffle(temp_answ_arr2, temp_answ_arr2 + sizeof(temp_answ_arr2) / sizeof(*temp_answ_arr2));// ïåğåìåøèâàíèå âîïğîñîâ ïåğåä âûâîäîì
			cout << "ÍÀÏĞÀÂËÅÍÈÅ ÒÅÑÒÀ:" << endl;
			cout << array_of_questions_per_test[1].semi_subject << endl;
			cout << "ÂÎÏĞÎÑ ¹ " << 2 << " :" << endl;
			cout << array_of_questions_per_test[1].question << endl;

			for (int j = 0; j < 4; j++)
			{
				cout << "ÂÀĞÈÀÍÒ ÎÒÂÅÒÀ ¹ " << j + 1 << " ÍÀ ÂÎÏĞÎÑ ¹" << 0 + 2 << " :" << endl;
				cout << temp_answ_arr2[j] << endl;
				
			}
		
			cout << "--------------------------------------------------------------------"<<endl;
	}
	
	
	
};

class Statistic// êëàññ ñòàòèñòèêà, êîòîğûé ñîäåğæèò äàííûå ïîñëå ñäà÷è êàæäîãî Òåñòà
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

class Guest : public Statistic // Êëàññ ãîñòü, ñîäåğæèò èíôî ïî êàæäîìó ïîëüçîâàòåëş
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
	
	void ShowGuestDetails()//âûâîä íà ıêğàí äàííûå ïî ïîëüçîâàòåëş
	{
		cout << "-----------------------------------------------------------" << endl;
		cout << "ÔÈÎ ÏÎËÜÇÎÂÀÒÅËß             : " << guest_name << " " << guest_surname << endl;
		cout << "ËÎÃÈÍ ÀÊÊÀÓÍÒÀ ÏÎËÜÇÎÂÀÒÅËß  : " << DeCodingStr(guest_login).c_str() << endl;
		cout << "ÏÀĞÎËÜ ÀÊÊÀÓÍÒÀ ÏÎËÜÇÎÂÀÒÅËß : " << DeCodingStr(guest_pass).c_str() << endl;
		cout << "ÀÄĞÅÑ                        : " << guest_address << endl;
		cout << "ÒÅËÅÔÎÍ                      : " << guest_phone_number << endl;
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


class Admin : public Statistic // îñíîâíîé êëàññ, ÷åğåç êîòîğûé îñóùåñòâëÿåòñÿ âåñü ôóíêöèîíàë ïğîãğàììû
{								//àãğåãèğîâàíèå îáúåêòîâ äğóãèõ êëàññîâ
private:

	Guest * myguest;
	Guest *p;
	Test * mytestobj;//óêàçàòåëü íà îáúåêò êëààñà Òåñò, äëÿ ñ÷èòûâàíèÿ è çàïèñè äàííûõ èç ôàéëà
	vector <Test> VectTests; //âåêòîğ îáúåêòîâ êëàññà Òåñò äëÿ áûñòğîãî ïîèñêà, óäàëåíèÿ êîğğåêòèğîâêè äàííûõ, îïğåäåëåíèÿ ğàçìåğà ìàññèâà
	char subjectslab [20][50];// ìàññèâ êàòåãîğèé / ïğåäìåòîâ
	int tests_qty;
	//int m;
	vector<Guest> VectGuests;//âåêòîğ îáúåêòîâ êëàññà Ãîñòü äëÿ áûñòğîãî ïîèñêà, óäàëåíèÿ êîğğåêòèğîâêè äàííûõ, îïğåäåëåíèÿ ğàçìåğà ìàññèâà
	Statistic * mystatistic_admin;//óêàçàòåëü íà îáúåêò êëààñà Ñòàòèñòèêà, äëÿ ñ÷èòûâàíèÿ è çàïèñè äàííûõ èç ôàéëà
	vector<Statistic> StatVectAdmin;//âåêòîğ îáúåêòîâ êëàññà Ñòàòèñòèêà äëÿ áûñòğîãî ïîèñêà, óäàëåíèÿ êîğğåêòèğîâêè äàííûõ, îïğåäåëåíèÿ ğàçìåğà ìàññèâà
	char temp_login[50], temp_pass[100], guest_login_stat[50];
	struct AdmData {//ñòğóêòóğà äëÿ ïîëó÷åíèÿ, çàïèñè è ñ÷èòûâàíèÿ äàííûõ ïî àäìèíó
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
	
	void MainMenu_draw()// âûâîä íà ıêğàí îñíîâíîãî ìåíş
	{
		system("cls");
		SoftNameShow();
		printf("1. ĞÅÃÈÑÒĞÀÖÈß ÀÄÌÈÍÈÑÒĞÀÒÎĞÀ\n"); //âûïîëíåíî AdminRegistration()
		printf("2. ÈÇÌÅÍÅÍÈÅ ÏÀĞÎËß ÀÄÌÈÍÈÑÒĞÀÒÎĞÀ\n");//âûïîëíåíî AdminRegErasing()
		printf("3. ÓÄÀËÅÍÈÅ ÀÊÊÀÓÍÒÀ ÀÄÌÈÍÈÑÒĞÀÒÎĞÀ\n");//âûïîëíåíî AdminRegErasing()
		printf("4. ĞÅÃÈÑÒĞÀÖÈß ÏÎËÜÇÎÂÀÒÅËß\n");//âûïîëåíî CreateGuest()
		printf("5. ÓÄÀËÅÍÈÅ ÀÊÊÀÓÍÒÀ ÏÎËÜÇÎÂÀÒÅËß\n"); // DeleteGuestAcc()
		printf("6. ÂÕÎÄ Â ÑÈÑÒÅÌÓ ÀÄÌÈÍÈÑÒĞÀÒÎĞÀ\n");
		printf("7. ÂÕÎÄ Â ÑÈÑÒÅÌÓ ÏÎËÜÇÎÂÀÒÅËß\n"); //EnterToGuestAcc()
		printf("8. ÂÛÕÎÄ ÈÇ ÏĞÎÃĞÀÌÌÛ\n\n");
	}
	
	void FirstMenu()// ôóíêöèîíàë îñíîâíîãî ìåíş
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
				{	//printf("ĞÅÃÈÑÒĞÀÖÈß ÀÄÌÈÍÈÑÒĞÀÒÎĞÀ\n");
				AdminRegistration();
				/*choice = true;*/
				Sleep(3000);
				break; }
				case 50:
				{//printf("ÈÇÌÅÍÅÍÈÅ ÏÀĞÎËß ÀÄÌÈÍÈÑÒĞÀÒÎĞÀ\n");
				AdminLoginPassChange();
				/*choice = true;*/ break; }
				case 51:
				{//printf("ÓÄÀËÅÍÈÅ ÀÊÊÀÓÍÒÀ ÀÄÌÈÍÈÑÒĞÀÒÎĞÀ\n");
				AdminRegErasing();
				/*choice = true;*/ break; }
				case 52:
				{//printf("ĞÅÃÈÑÒĞÀÖÈß ÏÎËÜÇÎÂÀÒÅËß\n");
				CreateGuest();
				/*choice = true;*/ break; }
				case 53:
				{//printf("ÓÄÀËÅÍÈÅ ÀÊÊÀÓÍÒÀ ÏÎËÜÇÎÂÀÒÅËß\n");
				DeleteGuestAcc();
				choice = true; break; }
				case 54:
				{//printf("ÂÕÎÄ Â ÑÈÑÒÅÌÓ ÀÄÌÈÍÈÑÒĞÀÒÎĞÀ\n");
				EnterToAdminAcc();
				choice = true; break; }
				case 55:
				{//printf("ÂÕÎÄ Â ÑÈÑÒÅÌÓ ÏÎËÜÇÎÂÀÒÅËß\n");
				EnterToGuestAcc();
				choice = true; break; }
				case 56:
				{//printf("ÂÛÕÎÄ ÈÇ ÏĞÎÃĞÀÌÌÛ\n");
				choice = true;
				cout << "\nÑÏÀÑÈÁÎ ÇÀ ÏÎËÜÇÎÂÀÍÈÅ ÏĞÎÃĞÀÌÌÎÉ!" << endl;
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

	void AdminRegistration()//ğåãèñòğàöèÿ àäìèíèñòğàòîğà
	{
		cout << "-----------------------------------" << endl;
		cout << "ĞÅÃÈÑÒĞÀÖÈß ÀÄÌÈÍÈÑÒĞÀÒÎĞÀ :" << endl;
		cout << "-----------------------------------" << endl;

		cout << "ÏÎÆÀËÓÉÑÒÀ ÂÂÈÅÄÈÒÅ ËÎÃÈÍ :" << endl;

		gets_s(temp_login);
		fp_adm_reg = fopen("AdminDetails.dat", "a+b");
		if (fp_adm_reg == NULL) {
			perror("Open");
			return;
		}
		fread(&a_data, sizeof(AdmData), 1, fp_adm_reg);
		if (a_data.is_registered == true)//ïğîâåğêà åñëè àäìèíèñòğàòîğ óæå çàğåãèñòğèğîâàí â ïğîãğàììå
		{
			cout << "ÈÇÂÈÍÈÒÅ, ÀÄÌÈÍÈÑÒĞÀÒÎĞ ÓÆÅ ÇÀĞÅÃÈÑÒĞÈĞÎÂÀÍ!" << endl;
			return;
		}
		if (!a_data.is_registered)
		{
			strcpy(a_data.admin_login, CodingStr(temp_login).c_str());
			cout << "ÏÎÆÀËÓÉÑÒÀ, ÂÂÅÄÈÒÅ ÏÀĞÎËÜ:" << endl;
			gets_s(temp_pass);
			strcpy(a_data.admin_pass, CodingStr(temp_pass).c_str());
			cout << "ÏÎÆÀËÓÉÑÒÀ, ÂÂÅÄÈÒÅ ÔÀÌÈËÈŞ:" << endl;
			gets_s(a_data.admin_surname);
			cout << "ÏÎÆÀËÓÉÑÒÀ, ÂÂÅÄÈÒÅ ÈÌß:" << endl;
			gets_s(a_data.admin_name);
			cout << "ÏÎÆÀËÓÉÑÒÀ, ÂÂÅÄÈÒÅ EMAIL:" << endl;
			gets_s(a_data.admin_email);
			a_data.is_registered = true;
			cout << "ÏÎÇÄĞÀÂËßÅÌ, ĞÅÃÈÑÒĞÀÖÈß ÏĞÎØËÀ ÓÑÏÅØÍÎ!" << endl;
			fwrite(&a_data, sizeof(AdmData), 1, fp_adm_reg);
			
		}

		fclose(fp_adm_reg);
		cout << "ÀÊÊÀÓÍÒ ÀÄÌÈÍÈÑÒĞÀÒÎĞÀ ÓÑÏÅØÍÎ ÑÎÇÄÀÍ!" << endl;
	}

	void AdminRegErasing()//óäàëåíèå àêêàóíòà àäìèíà
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
		bool choice_ = false;
		do
		{
			gets_s(temp_pass);
			if (!strcmp(DeCodingStr(a_data.admin_pass).c_str(), temp_pass))//ïğîâåğêà ëîãèíà è ïàğîëÿ
			{
				fp_adm_reg = fopen("AdminDetails.dat", "wb");
				if (fp_adm_reg == NULL) {
					perror("Open"); return; }
				cout << "ÀÊÊÀÓÍÒ ÀÄÌÈÍÈÑÒĞÀÒÎĞÀ ÁÛË ÓÄÀËÅÍ!" << endl;
				fclose(fp_adm_reg);
				break;
			}
			if (!strcmp("0", temp_pass)) choice_ = true;
			else
				cout << "ÓÊÀÆÈÒÅ ÂÅĞÍÛÉ ÏÀĞÎËÜ ÈËÈ <<0>> ÄËß ÂÛÕÎÄÀ!" << endl;
		} while (!choice_);
		//cin.ignore(); 
		
		FirstMenu();
	}

	void AdminLoginPassChange()//èçìåíåíèå ïàğîëÿ àäìèíèñòğàòîğà
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
				cout << "ÂÂÅÄÈÒÅ ÍÎÂÛÉ ÏÀĞÎËÜ :" << endl;
				gets_s(temp_pass);
				strcpy(a_data.admin_pass, CodingStr(temp_pass).c_str());
				fwrite(&a_data, sizeof(AdmData), 1, fp_adm_reg);
				fclose(fp_adm_reg);
				cout << "ÏÀĞÎËÜ ÀÄÌÈÍÈÑÒĞÀÒÎĞÀ ÁÛË ÈÇÌÅÍÅÍ!" << endl;
				Sleep(3000);
				break;
			}
			if (!strcmp("0", temp_pass)) choice_ = true;
			else
				cout << "ÓÊÀÆÈÒÅ ÂÅĞÍÛÉ ÏÀĞÎËÜ ÈËÈ <<0>> ÄËß ÂÛÕÎÄÀ!" << endl;
		} while (!choice_);

	}
	//-------------------------------------------------------------------
	void EnterToAdminAcc()// âõîä â àêêàóíò àäìèíèñòğàòîğà
	{
		char temp[100];
		cout << "\nÄËß ÂÕÎÄÀ Â ÀÊÊÀÓÍÒ ÀÄÌÈÍÈÑÒĞÀÒÎĞÀ, ÂÂÅÄÈÒÅ ËÎÃÈÍ :" << endl;
		
		fp_adm_reg = fopen("AdminDetails.dat", "r+b"); // îòêğûòèå ôàéëà äëÿ ñ÷èòûâàíèÿ äàííûõ
		if (fp_adm_reg == NULL) {
			cout << "ÂÍÈÌÀÍÈÅ ÀÊÊÀÓÍÒ ÀÄÌÈÍÀ ÅÙÅ ÍÅ ÑÎÇÄÀÍ!" << endl;
			return;
		}
		fread(&a_data, sizeof(AdmData), 1, fp_adm_reg);//ñ÷èòûâàíèå ñòğóêòóğû
		fclose(fp_adm_reg);
		bool choice_ = false;
		do
		{
			//cin.ignore();
			gets_s(temp);
			if (!strcmp(DeCodingStr(a_data.admin_login).c_str(), temp))//ğàñêîäèğîâàíèå ëîãèíà è åãî ñğàâíåíèå ñ ââåäåííûì
			break;
			if (!strcmp("0", temp)) {
			choice_ = true;return;}	
			else
				cout << "ÓÊÀÆÈÒÅ ÂÅĞÍÛÉ ËÎÃÈÍ ÈËÈ <<0>> ÄËß ÂÛÕÎÄÀ!" << endl;
		} while (!choice_);
		
		cout << "ÄËß ÂÕÎÄÀ, ÂÂÅÄÈÒÅ ÑÂÎÉ ÏÀĞÎËÜ :" << endl;
		choice_ = false;
		do
		{
			//cin.ignore();
			gets_s(temp);
			if (!strcmp(DeCodingStr(a_data.admin_pass).c_str(), temp))//ğàñêîäèğîâàíèå ïàğîëÿ è åãî ñğàâíåíèå ñ ââåäåííûì
			{
				AdminMenu_1();
				break;
			}
			if (!strcmp("0", temp)) {
			choice_ = true;return;}
			else
				cout << "ÓÊÀÆÈÒÅ ÂÅĞÍÛÉ ÏÀĞÎËÜ ÈËÈ <<0>> ÄËß ÂÛÕÎÄÀ!" << endl;
		} while (!choice_);


	}

	void EnterToGuestAcc()//âõîä â àêêàóíò ïîëüçîâàòåëÿ
	{
		char temp_pass[50], temp_login[50];
		bool data_is_ok = false;
		fstream file_read("GuestsLab.dat", ios::in | ios::binary);
		if (!file_read.is_open())
		{
			file_read.close();
			cout << "ÏÎËÜÇÎÂÀÒÅËÈ ÅÙÅ ÍÅ ÑÎÇÄÀÍÛ!" << endl;	Sleep(3000); return;
		}

		file_read.seekg(0, ios::end);
		int size_of_file_in_bytes = file_read.tellg();
		int size_of_array = size_of_file_in_bytes / sizeof(Guest); //ñ÷èòûâàíèå ìàññèâà îáúåêòîâ èç ôàéëà, îïğåäåëåíèå êîëè÷åñòâà îáúåêòîâ

		Guest *p = new Guest[size_of_array]; //âûäåëåíèå ïàìÿòè äëÿ ìàññèâà îáúåêòîâ êëàññà ïîëüçîâàòåëü
		file_read.seekg(0, ios::beg);
		for (int k = 0; k < size_of_array; k++) {
			Guest * _temp_ = new Guest;
			file_read.read((char*)_temp_, sizeof(Guest));
			*(p + k) = *_temp_;
			delete _temp_;
		}
		file_read.close();

		for (int i = 0; i < size_of_array; i++)
		{	VectGuests.push_back(p[i]);		}//çàïîëíåíèå âåêòîğà îáúåêòîâ, ñ ïîìîùüş ìàññèâà îáúåêòîâ êëàññà Ïîëüçîâàòåëü
		delete[] p;
		
		cout << "\nÄËß ÂÕÎÄÀ Â ÀÊÊÀÓÍÒ ÏÎËÜÇÎÂÀÒÅËß, ÂÂÅÄÈÒÅ ËÎÃÈÍ :" << endl;
		
		do
		{
			//cin.ignore();
			//cin >> temp;
			gets_s(temp_login);
			for (int i = 0; i < VectGuests.size(); i++) {
				if (!strcmp(DeCodingStr((char *)VectGuests.at(i).GetGuestLogin()).c_str(), temp_login))//ğàñêîäèğîâàíèå ëîãèíà è åãî ñğàâíåíèå ñ ââåäåííûì
				{data_is_ok = true;	break;}
			}
			
			if (!strcmp("0", temp_login)) {
			data_is_ok = true; FirstMenu();}
			if(data_is_ok == false)
				cout << "ÓÊÀÆÈÒÅ ÂÅĞÍÛÉ ËÎÃÈÍ ÈËÈ <<0>> ÄËß ÂÛÕÎÄÀ!" << endl;

		} while (!data_is_ok);
		
		cout << "ÄËß ÂÕÎÄÀ, ÂÂÅÄÈÒÅ ÑÂÎÉ ÏÀĞÎËÜ :" << endl;
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
				cout << "ÓÊÀÆÈÒÅ ÂÅĞÍÛÉ ËÎÃÈÍ ÈËÈ <<0>> ÄËß ÂÛÕÎÄÀ!" << endl;

		} while (!data_is_ok);
		
		strcpy(guest_login_stat, temp_login);
	}

	//-------------------------------------------------------------------
	void AdminMenu_1_draw() //Ìåíş àêêàóíòà àäìèíà
	{
		system("cls");	SoftNameShow();
		printf("1. ÓÏĞÀÂËÅÍÈÅ ÏÎËÜÇÎÂÀÒÅËßÌÈ\n");
		printf("2. ÏĞÎÑÌÎÒĞ ÑÒÀÒÈÑÒÈÊÈ\n");
		printf("3. ÓÏĞÀÂËÅÍÈÅ ÒÅÑÒÈĞÎÂÀÍÈÅÌ\n");
		printf("4. ÂÎÇÂĞÀÒ Â ÏĞÅÄÛÄÓÙÅÅ ÌÅÍŞ\n");
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
				{//printf("ÓÏĞÀÂËÅÍÈÅ ÏÎËÜÇÎÂÀÒÅËßÌÈ\n");
				AdminMenu_1_1();
					choice = true;  break; }
				case 50:
				{//printf("ÏĞÎÑÌÎÒĞ ÑÒÀÒÈÑÒÈÊÈ\n");
				AdminMenu_1_2();
				choice = true; break; }
				case 51:
				{//printf("ÓÏĞÀÂËÅÍÈÅ ÒÅÑÒÈĞÎÂÀÍÈÅÌ\n");
				AdminMenu_1_3();
				choice = true; break; }
				case 52:
				{//printf("ÂÎÇÂĞÀÒ Â ÏĞÅÄÛÄÓÙÅÅ ÌÅÍŞ\n");
				FirstMenu();
				choice = true; break; }
				}
			}
		}
	}

	//-------------------------------------------------------------------
	void AdminMenu_1_1_draw()// Ìåíş óïğàâëåíèå ïîëüçîâàòåëÿìè
	{
		system("cls");	SoftNameShow();
		printf("1. ÑÎÇÄÀÍÈÅ ÀÊÊÀÓÍÒÀ ÏÎËÜÇÎÂÀÒÅËß\n");//CreateGuest();
		printf("2. ÈÇÌÅÍÅÍÈÅ ÀÊÊÀÓÍÒÀ ÏÎËÜÇÎÂÀÒÅËß\n");//EditGuestAcc();
		printf("3. ÓÄÀËÅÍÈÅ ÀÊÊÀÓÍÒÀ ÏÎËÜÇÎÂÀÒÅËß\n");//DeleteGuestAcc();
		printf("4. ÂÎÇÂĞÀÒ Â ÏĞÅÄÛÄÓÙÅÅ ÌÅÍŞ\n");
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
				{//printf("ÑÎÇÄÀÍÈÅ ÀÊÊÀÓÍÒÀ ÏÎËÜÇÎÂÀÒÅËß\n");
				CreateGuest();
				choice = false;  break; }
				case 50:
				{//printf("ÈÇÌÅÍÅÍÈÅ ÀÊÊÀÓÍÒÀ ÏÎËÜÇÎÂÀÒÅËß\n");
				EditGuestAcc();
				choice = false; break; }
				case 51:
				{//printf("ÓÄÀËÅÍÈÅ ÀÊÊÀÓÍÒÀ ÏÎËÜÇÎÂÀÒÅËß\n");
				DeleteGuestAcc();
				choice = true; break; }
				case 52:
				{//printf("ÂÎÇÂĞÀÒ Â ÏĞÅÄÛÄÓÙÅÅ ÌÅÍŞ\n");
				AdminMenu_1();
				choice = true; break; }
				}
			}
		}
	}

	//-------------------------------------------------------------------
	void AdminMenu_1_2_draw()// Ìåíş ïğîñìîòğ ñòàòèñòèêè
	{
		system("cls");	SoftNameShow();
		printf("1. ÏĞÎÑÌÎÒĞ ÑÒÀÒÈÑÒÈÊÈ ÏÎ ÊÀÒÅÃÎĞÈÈ\n"); //ShowStatisticForAdminCategory();
		printf("2. ÏĞÎÑÌÎÒĞ ÑÒÀÒÈÑÒÈÊÈ ÏÎ ÎÏĞÅÄÅËÅÍÍÎÌÓ ÒÅÑÒÓ\n");//ShowStatisticForAdminTest();
		printf("3. ÏĞÎÑÌÎÒĞ ÑÒÀÒÈÑÒÈÊÈ ÏÎ ÏÎËÜÇÎÂÀÒÅËŞ\n");//ShowStatisticForAdminbyGuest();
		printf("4. ÂÛÂÎÄ ÑÒÀÒÈÑÒÈÊÈ Â ÔÀÉË\n");//ExportStatisticToFile();
		printf("5. ÂÎÇÂĞÀÒ Â ÏĞÅÄÛÄÓÙÅÅ ÌÅÍŞ\n");
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
				{//printf("ÏĞÎÑÌÎÒĞ ÑÒÀÒÈÑÒÈÊÈ ÏÎ ÊÀÒÅÃÎĞÈÈ\n");
				ShowStatisticForAdminCategory();
				choice = false;  break; }
				case 50:
				{//printf("ÏĞÎÑÌÎÒĞ ÑÒÀÒÈÑÒÈÊÈ ÏÎ ÎÏĞÅÄÅËÅÍÍÎÌÓ ÒÅÑÒÓ\n");
				ShowStatisticForAdminTest();
				choice = false; break; }
				case 51:
				{//printf("ÏĞÎÑÌÎÒĞ ÑÒÀÒÈÑÒÈÊÈ ÏÎ ÏÎËÜÇÎÂÀÒÅËŞ\n");
				choice = false; ShowStatisticForAdminbyGuest();
				break; }
				case 52:
				{//printf("ÂÛÂÎÄ ÑÒÀÒÈÑÒÈÊÈ Â ÔÀÉË\n");
				choice = false; ExportStatisticToFile();
				break; }
				case 53:
				{//printf("ÂÎÇÂĞÀÒ Â ÏĞÅÄÛÄÓÙÅÅ ÌÅÍŞ\n");
				AdminMenu_1();
				choice = true; break; }
			}
			}
		}
	}
	
	//-------------------------------------------------------------------
	void AdminMenu_1_3_draw()// Ìåíş óïğàâëåíèå òåñòèğîâàíèåì
	{
		system("cls");	SoftNameShow();
		printf("1. ÄÎÁÀÂËÅÍÈÅ ÊÀÒÅÃÎĞÈÈ ÒÅÑÒÀ\n"); //void CreateCategory()
		printf("2. ÄÎÁÀÂËÅÍÈÅ ÒÅÑÒÀ\n"); //void CreateTest()
		printf("3. ÊÎĞĞÅÊÒÈĞÎÂÊÀ ÒÅÑÒÀ\n"); //void EditTest()
		printf("4. İÊÑÏÎĞÒ ÊÀÒÅÃÎĞÈÉ ÒÅÑÒÎÂ Â ÔÀÉË\n"); //ExportCatToFile()
		printf("5. ÈÌÏÎĞÒ ÊÀÒÅÃÎĞÈÉ ÒÅÑÒÎÂ ÈÇ ÔÀÉËÀ\n"); //ImportCatFromFile()
		printf("6. İÊÑÏÎĞÒ ÒÅÑÒÎÂ Â ÔÀÉË\n"); //void ExportTestToFile()
		printf("7. ÈÌÏÎĞÒ ÒÅÑÒÀ ÈÇ ÔÀÉËÀ\n");//ImportTestFromFile();
		printf("8. ÂÎÇÂĞÀÒ Â ÏĞÅÄÛÄÓÙÅÅ ÌÅÍŞ\n");
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
				{//printf("ÄÎÁÀÂËÅÍÈÅ ÊÀÒÅÃÎĞÈÈ ÒÅÑÒÀ\n");
				CreateCategory();
				choice = false;  break; }
				case 50:
				{//printf("ÄÎÁÀÂËÅÍÈÅ ÒÅÑÒÀ\n");
				CreateTest();
				choice = false; break; }
				case 51:
				{//printf("ÊÎĞĞÅÊÒÈĞÎÂÊÀ ÒÅÑÒÀ\n");
				EditTest();
				choice = false; break; }
				case 52:
				{//printf("İÊÑÏÎĞÒ ÊÀÒÅÃÎĞÈÉ ÒÅÑÒÎÂ Â ÔÀÉË\n");
				ExportCatToFile();
				choice = false; break; }
				case 53:
				{//printf("ÈÌÏÎĞÒ ÊÀÒÅÃÎĞÈÉ ÒÅÑÒÎÂ ÈÇ ÔÀÉËÀ\n");
				ImportCatFromFile();
				choice = false; break; }
				case 54:
				{//printf("İÊÑÏÎĞÒ ÒÅÑÒÎÂ Â ÔÀÉË\n");
				ExportTestToFile();
				choice = false; break; }
				case 55:
				{//printf("ÈÌÏÎĞÒ ÒÅÑÒÀ ÈÇ ÔÀÉËÀ\n");
				ImportTestFromFile();
				choice = false; break; }
				case 56:
				{//printf("ÂÎÇÂĞÀÒ Â ÏĞÅÄÛÄÓÙÅÅ ÌÅÍŞ\n");
				AdminMenu_1();
				choice = true; break; }
				}

			}
		}
		AdminMenu_1();
	}

	//-------------------------------------------------------------------
	void GuestMenu_1_draw()// Ìåíş àêêàóíò ïîëüçîâàòåëÿ
	{
		system("cls");	SoftNameShow();
		printf("1. ÑÒÀÒÈÑÒÈÊÀ ÒÅÑÒÈĞÎÂÀÍÈß\n");//ShowStatisticForGuest(guest_login);
		printf("2. ÏĞÎÉÒÈ ÒÅÑÒ\n"); //TestPassing(guest_login);
		printf("3. ÇÀÂÅĞØÈÒÜ ÍÅ ÎÊÎÍ×ÅÍÍÛÉ ÒÅÑÒ\n");
		printf("4. ÂÎÇÂĞÀÒ Â ÏĞÅÄÛÄÓÙÅÅ ÌÅÍŞ\n");
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
				{//printf("ÑÒÀÒÈÑÒÈÊÀ ÒÅÑÒÈĞÎÂÀÍÈß\n");
				ShowStatisticForGuest(guest_login_stat);
				choice = false;  break; }
				case 50:
				{//printf("ÏĞÎÉÒÈ ÒÅÑÒ\n");
				TestPassing(guest_login_stat);
				choice = false; break; }
				case 51:
				{printf("\nÇÀÂÅĞØÈÒÜ ÍÅ ÎÊÎÍ×ÅÍÍÛÉ ÒÅÑÒ\n");
				Sleep(5000);
				choice = false; break; }
				case 52:
				{//printf("ÂÎÇÂĞÀÒ Â ÏĞÅÄÛÄÓÙÅÅ ÌÅÍŞ\n");
				FirstMenu();
				choice = true; break; }
				}

			}
		}
	}
	
	//-------------------------------------------------------------------
		
	void CreateGuest()//ñîçäàíèå îáúåêòà ïîëüçîâàòåëÿ
	{
		bool if_log_exist = false;
		bool file_absence = false;
		char temp[50];
		char temp_address[250];
		myguest = new Guest;
		
		cout << "-----------------------------------" << endl;
		cout << "ĞÅÃÈÑÒĞÀÖÈß ÏÎËÜÇÎÂÀÒÅËß :" << endl;
		cout << "-----------------------------------" << endl;
		fstream file_read("GuestsLab.dat", ios::in | ios::binary);//ñ÷èòûâàíèå èç ôàéëà ìàññèâà îáúåêòîâ Ïîëüçîâàòåëü
		
		do
		{
			cout << "ÏÎÆÀËÓÉÑÒÀ ÂÂÅÄÈÒÅ ËÎÃÈÍ :" << endl;
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
				int size_of_array = size_of_file_in_bytes / sizeof(Guest);// îïğåäåëåíèå ğàçìåğà ìàññèâà

				Guest *p = new Guest[size_of_array];
				if_log_exist = false;
				
				file_read.seekg(0, ios::beg);
				for (int k = 0; k < size_of_array; k++) {
					Guest * _temp_ = new Guest;
					file_read.read((char*)_temp_, sizeof(Guest));
					*(p + k) = *_temp_;//çàïîëíåíèå ñîçäàííîãî ìàññèâà äàííûìè èç ôàéëà
					delete _temp_;
				}
				

				for (int i = 0; i < size_of_array; i++)
				{
					if (!strcmp(DeCodingStr((char *)p->GetGuestLogin()).c_str(), temp))//ïğîâåğêà íà ïğåäìåò íàëè÷èÿ ââåäåííîãî ëîãèíà â ñèñòåìå
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

				myguest->SetGLogin((char *)CodingStr(temp).c_str());//çàïîëíåíèå äàííûìè ïîëüçîâàòåëÿ íîâîãî àêêàóíòà
				cout << "ÏÎÆÀËÓÉÑÒÀ, ÂÂÅÄÈÒÅ ÏÀĞÎËÜ:" << endl;
				gets_s(temp);
				myguest->SetGPass((char *)CodingStr(temp).c_str());
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
					fstream file_write("GuestsLab.dat", ios::out | ios::trunc | ios::binary);//çàïèñü â ôàéë, åñëè ıòî ïåğâàÿ çàïèñü
					if (!file_write.is_open())
					{cout << "Error to open for writing!" << endl;	}
					file_write.write((char*)(myguest), sizeof(Guest));
					file_write.flush();
					file_write.close();
				}
				if (!file_absence)
				{
					fstream file_read("GuestsLab.dat", ios::in | ios::binary);//Â ñëó÷àå åñëè ïîëüçîâàòåëè óæå èìşòñÿ, 
					file_read.seekg(0, ios::end);								//ñ÷èòûâàåì äàííûå èç ôàéëà, îïğåäåëÿåì ğàçìåğ ìàññèâà è âûäåëÿåì íà îäèí ıëåìåíò áîëüøå.
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
				Sleep(3000);
	}
	
	//-----------------------------
	
	void DeleteGuestAcc()// óäàëåíèå àêêàóíòà ïîëüçîâàòåëÿ
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
			//cin.ignore();
			gets_s(templog);
			cout << "ÓÊÀÆÈÒÅ ÏÀĞÎËÜ ÏÎËÜÇÎÂÀÒÅËß : ";
			gets_s(temppass);
			
			if (!strcmp("0", templog) && !strcmp("0", temppass))
			{
				if_acc_deleted = true;
				AdminMenu_1_1(); 
			}
			for (int i = 0; i < VectGuests.size(); i++)//ïğîâåğêà ââåäåííîãî ëîãèíà è ïàğîëüÿ íà íàëè÷èå â áàçå, ïåğåä óäàëåíèåì.
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
				cout << "ÈÇÂÈÍÈÒÅ, ÂÂÅÄÅÍÍÛÅ ÄÀÍÍÛÅ ÍÅ ÑÎÎÒÂÅÒÑÒÂÓŞÒ ËÎÃÈÍÓ ÈËÈ ÏÀĞÎËŞ!" << endl;
				cout << "ÏÎÂÒÎĞÈÒÅ ÏÎÏÛÒÊÓ ÈËÈ ÂÂÅÄÈÒÅ <<0>> ÄËß ÂÛÕÎÄÀ!" << endl;
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
		cout << "ÀÊÊÀÓÍÒ ÏÎËÜÇÎÂÀÒÅËß ÁÛË ÓÑÏÅØÅÎ ÓÄÀËÅÍ!"<<endl;
		Sleep(3000);
		AdminMenu_1_1();
	}
	//-------------------------
	
	void CreateCategory()//ñîçäàíèå êàòåãîğèè / ïğåäìåòà 
	{
		char temp[50];
		bool if_subj_avail = false;
		cout << "\nÈÌÅŞÙÈÅÑß Â ÍÀËÈ×ÈÈ ÊÀÒÅÃÎĞÈÈ :" << endl;

		fstream file_read("SubjLab.dat", ios::in | ios::binary);//îòêğûòèå è ñ÷èòûâàíèå èç ôàéëà ìàññèâà ÷àğ ñ íàçâàíèÿìè êàòåãîğèé / ïğåäìåòîâ
		if (!file_read.is_open())
		{
			file_read.close();
			cout << "Â ÍÀËÈ×ÈÈ ÅÙÅ ÍÅÒ ÏĞÅÄÌÅÒÎÂ..." << endl;
			cout << "\nÂÂÅÄÈÒÅ ÍÀÇÂÀÍÈÅ ÏĞÅÄÌÅÒÀ ÄËß ÒÅÑÒÈĞÎÂÀÍÈß : ";
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
				for (int i = 0; i < 50; i++) temp[i] = toupper(temp[i]);
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

				
	void CreateTest()//ñîçäàíèå òåñòà
{
	char temp[50];
	char temp_coice;
	char test_name_temp[50];
	char test_name_temp_index[10];
	
	cout << "ÄÎÁÀÂËÅÍÈÅ ÒÅÑÒÀ.." << endl;
	cout << "ÈÌÅŞÙÈÅÑß Â ÍÀËÈ×ÈÈ ÊÀÒÅÃÎĞÈÈ / ÏĞÅÄÌÅÒÛ :" << endl;
	
	fstream file_read("SubjLab.dat", ios::in | ios::binary); // îòêğûòèå è ñ÷èòûâàíèå ìàññèâà ÷àğ Ïğåäìåòîâ.
	if (!file_read.is_open())
	{	cout << "ÎØÈÁÊÀ ÏĞÈ ÎÒÊĞÛÒÈÈ ÔÀÉËÀ!" << endl;	}
	else
	{
		file_read.seekg(0, ios::end);
		int size_of_file_in_bytes = file_read.tellg();
		int size_of_array = size_of_file_in_bytes / (sizeof(char) * 50); //îïğåäåëåíèå ğàçìåğà ìàññèâà

		file_read.seekg(0, ios::beg);
		for (int k = 0; k < size_of_array; k++) {
			char _temp_[50];
			file_read.read(_temp_, sizeof(char) * 50);
			strcpy(subjectslab[k], _temp_);// çàïèñü ñòğîê â ìàññèâ äëÿ ğàáîòû

		}
		file_read.close();

		for (int i = 0; i < size_of_array; i++)
			cout << "No " << i << "  " << subjectslab[i] << endl;// âûâîä íà ıêğàí èìåşùèõñÿ ïğåäìåòîâ /êàòåãîğèé

		cout << "ÓÊÀÆÈÒÅ ÍÎÌÅĞ ÏĞÅÄÌÅÒÀ ÄËß ÇÀÏÎËÍÅÍÈß ÒÅÑÒÀ :" << endl;//îïğåäåëåíèå èíòåğåñóşùåãî ïğåäìåòà
		cout << "ÓÊÀÆÈÒÅ ÄËß ÑÎÇÄÀÍÈß ÏÎÄÕÎÄßÙÅÃÎ ÏĞÅÄÌÅÒÀ - 9 :";
		for (;;) {
		cin >> temp_coice; cin.ignore(100, '\n');
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
			fstream file_read("TestsLab.dat", ios::in | ios::binary);//åñëè ôàéë íå îòêğûâàåòñÿ, çíà÷èò òåñòîâ åùå íåò..
			if (!file_read.is_open())
			{
				file_read.close();
				cout << "Â ÍÀËÈÈ×ÈÈ ÅÙÅ ÍÅÒ ÒÅÑÒÎÂ..." << endl;
				Test * firstsign = new Test;
				strcpy(test_name_temp, "");
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
				int size_of_array = size_of_file_in_bytes / sizeof(Test);//åñëè ôàéë îòêğûò, ñ÷èòûâàåì äàííûå, îïğåäåëåÿì ğàçìåğ ìàññèâà

				Test *p = new Test[size_of_array];
				file_read.seekg(0, ios::beg);
				for (int k = 0; k < size_of_array; k++) {
					Test * _temp_ = new Test;
					file_read.read((char*)_temp_, sizeof(Test));//çàïèñûâàåì äàííûå â ìàññèâ îáúåêòîâ êëàññà Òåñò
					*(p + k) = *_temp_;
					delete _temp_;
				}
				file_read.close();

				for (int i = 0; i < size_of_array; i++)// äëÿ îïåğàòèâíîé ğàáîòû, çàïîëíÿåì âåêòîğ äàííûìè èç ìàññèâà îáúåêòîâ
				{	VectTests.push_back(p[i]);	}
				
				mytestobj = new Test; // ñîçäàåì îáúåêò êëàññà Òåñò
				strcpy(test_name_temp, ""); // ôîğìèğóåì óíèêàëüíîå íàçâàíèå òåñòà
				strcat(test_name_temp, subjectslab[temp_coice - '0']);
				strcat(test_name_temp, "-");
				itoa((size_of_array+1), test_name_temp_index, 10);
				strcat(test_name_temp, test_name_temp_index);
				mytestobj ->SetTest(subjectslab[temp_coice - '0'], test_name_temp); // çàäàåì äàííûå ïî äàííîìó òåñòó
				VectTests.push_back(*mytestobj);//çàïèñûâàåì ãîòîâûé îáúåêò â êîíåö âåêòîğà

				Test *p_out = new Test[VectTests.size()];//äëÿ çàïèñè â ôàéë, âûäåëÿåì ïàìÿòü ïîä ìàññèâ îáúåêòîâ, êîëè÷åñòâî îïğåäåëÿåì ÷åğåç ğàçìåğ âåêòîğà

				for (int i = 0; i < VectTests.size(); i++)
				{	*(p_out + i) = VectTests.at(i);	}

				fstream file_write("TestsLab.dat", ios::out | ios::trunc | ios::binary);
				if (!file_write.is_open())
				{	cout << "Error to open for writing!" << endl;	}
				for (int k = 0; k < VectTests.size(); k++)
				{
					file_write.write((char*)(p_out + k), sizeof(Test));//çàïèñûâàåì ìàññèâ â ôàéë
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

	void TestPassing(char * guest_login_stat)//ïğîõîæäåíèå òåñòà
	{
		char temp[50];
		char temp_coice;
		srand(time(0));
		cout << "ÒÅÑÒÈĞÎÂÀÍÈÅ..." << endl;
		cout << "ÈÌÅŞÙÈÅÑß Â ÍÀËÈ×ÈÈ ÊÀÒÅÃÎĞÈÈ / ÏĞÅÄÌÅÒÛ :" << endl;

		fstream file_read("SubjLab.dat", ios::in | ios::binary);//ñ÷èòûâàíèå ìàññèâà ïğåäìåòîâ èç ôàéëà
		if (!file_read.is_open())
		{
			cout << "ÊÀÒÅÃÎĞÈÈ / ÏĞÅÄÌÅÒÛ ÅÙÅ ÍÅ ÑÎÇÄÀÍÛ!!" << endl;
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
				cout << "No " << i << "  " << subjectslab[i] << endl;//âûâîä íà ıêğàí èìåşùèõñÿ ïğåäìåòîâ

			cout << "ÓÊÀÆÈÒÅ ÍÎÌÅĞ ÏĞÅÄÌÅÒÀ ÄËß ÂÛÂÎÄÀ ÂÑÅÕ ÒÅÑÒÎÂ ÏÎ ÏĞÅÄÌÅÒÓ:" << endl;
			cout << "ÄËß ÂÛÕÎÄÀ Â ÏĞÅÄÛÄÓÙÅÅ ÌÅÍŞ - 9 : ";
			for (;;) {
				cin >> temp_coice; cin.ignore(100, '\n');
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
				fstream file_read("TestsLab.dat", ios::in | ios::binary);//åñëè ïîëüçîâàòåëü âûáğàë íîìåğ â ğàìêàõ ìàññèâà, 
				if (!file_read.is_open())								// îòêğûâàåì ôàéë òåñòîâ 
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
					int size_of_array = size_of_file_in_bytes / sizeof(Test); // îïğåäåëÿì ğàçìåğ ìàññèâà îáúåêòîâ òåñò

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
						if (!strcmp((p + i)->GetTestSubjName(), subjectslab[temp_coice - '0']))//çàïèñü îáúåêòîâ â âåêòîğ äëÿ îïåğàòèâíîé ğàáòû
							VectTests.push_back(p[i]);
					}
					delete[]p;

					for (int i = 0; i < VectTests.size(); i++)//âûâîä íà ıêğàí òåñòîâ äëÿ îïğåäåëåíèÿ êàêîé òåñò ïğîéòè
					{
						cout << "\nÍÎÌÅĞ ÒÅÑÒÀ " << i << ":" << endl;
						cout << "-------------------------------------------------------------------" << endl;
						VectTests.at(i).DisplayTest();
					}
					cout << "ÓÊÀÆÈÒÅ ÍÎÌÅĞ ÒÅÑÒÀ ÏĞÎÕÎÆÄÅÍÈß :" << endl;

					for (;;) {
						cin >> temp_coice; 
						if ((temp_coice - '0' >= 0) && (temp_coice - '0' < VectTests.size()))
							break;
						else
							cout << "ÑÄÅËÀÉÒÅ ÏĞÀÂÈËÜÍÛÉ ÂÛÁÎĞ!" << endl;
					}
					//--------------------------------------------------------------
					
					Statistic * my_test_stat = new Statistic;//ñîçäàíèå îáúåêòà êëàññà Ñòàòèñòèêà
					//--------------------------------------------------------------
					char temp_answ1, temp_answ2;
					int counter_corr_answ = 0;
					int temp_test_rate = 0;
					cout << "ÒÅÑÒÈĞÎÂÀÍÈÅ..." << endl;
					VectTests.at(temp_coice - '0').DisplayTestForPassing();// test in work
					cout << "\nÓÊÀÆÈÒÅ ÍÎÌÅĞ ÏĞÀÂËÜÍÎÃÎ ÎÒÂÅÒÀ ÍÀ ÂÎÏĞÎÑ ¹1 :" << endl; //îòâåòû íà âîïğîñû ïî âûáğàííîìó òåñòó
					for (;;) {
						cin >> temp_answ1; 
						if ((temp_answ1 - '0' > 0) && (temp_answ1 - '0' <= 4))
							break;
						else
							cout << "ÑÄÅËÀÉÒÅ ÏĞÀÂÈËÜÍÛÉ ÂÛÁÎĞ!" << endl;
					}
					cout << "ÓÊÀÆÈÒÅ ÍÎÌÅĞ ÏĞÀÂËÜÍÎÃÎ ÎÒÂÅÒÀ ÍÀ ÂÎÏĞÎÑ ¹2 :" << endl;
					for (;;) {
						cin >> temp_answ2; cin.ignore(100, '\n');
						if ((temp_answ2 - '0' > 0) && (temp_answ2 - '0' <= 4))
							break;
						else
							cout << "ÑÄÅËÀÉÒÅ ÏĞÀÂÈËÜÍÛÉ ÂÛÁÎĞ!" << endl;
					}
					
					cout << "-------------------------------------------" << endl;//âûâîä íà ıêğàí ğåçóëüòàòîâ ñäà÷è òåñòà
					cout << "ĞÅÇÓËÜÒÀÒ ÏÎ ÄÀÍÍÎÌÓ ÒÅÑÒÓ :" << endl;

					cout << "ÎÒÂÅÒ ÍÀ ÂÎÏĞÎÑ ¹1 :" << endl;
					int temp_c = 0;
					for (int i = 0; i < 4; i++)
					{
						if (!strcmp(VectTests.at(temp_coice - '0').GetQuestArr()[0].answers_arr[i],
							VectTests.at(temp_coice - '0').temp_answ_arr1[temp_answ1 - '0' - 1]	)	)
							temp_c = i; //break;
					}
					
					if (VectTests.at(temp_coice - '0').GetQuestArr()[0].correct_answ_arr[temp_c] == true )
					{
						cout << "ÂÅĞÍÎ!" << endl;
						counter_corr_answ++;	
					}
					else cout << "ÍÅ ÂÅĞÍÎ!" << endl;
					
					cout << "ÎÒÂÅÒ ÍÀ ÂÎÏĞÎÑ ¹2 :" << endl;
					
					for (int i = 0; i < 4; i++)
					{
						if (!strcmp(VectTests.at(temp_coice - '0').GetQuestArr()[1].answers_arr[i],
							VectTests.at(temp_coice - '0').temp_answ_arr2[temp_answ2 - '0' - 1]))
							temp_c = i; //break;
					}

					if (VectTests.at(temp_coice - '0').GetQuestArr()[1].correct_answ_arr[temp_c] == true)
					{
						cout << "ÂÅĞÍÎ!" << endl;
						counter_corr_answ++;
					}
					else cout << "ÍÅ ÂÅĞÍÎ!" << endl;


					cout << "ÊÎËÈ×ÅÑÒÂÎ ÂÅĞÍÛÕ ÎÒÂÅÒÎÂ : "<< counter_corr_answ<<" ! "<< endl;
					
					cout << "ÎÖÅÍÊÀ ÏÎ ÄÀÍÍÎÌÓ ÒÅÑÒÓ : " << endl;
					if (counter_corr_answ == 0)
					{
						temp_test_rate = 2;
						cout << temp_test_rate <<" ÁÀËËÀ!" << endl;
					}
					if (counter_corr_answ == 1)
					{
						temp_test_rate = 6; 
						cout << temp_test_rate <<" ÁÀËËÎÂ!" << endl;
					}
					if (counter_corr_answ == 2)
					{
						temp_test_rate = 11; 
						cout << temp_test_rate <<" ÁÀËËÎÂ!" << endl;
					}
										
					cout << "-------------------------------------------" << endl;
				strcpy((char *)CodingStr(my_test_stat->stat_guest_login).c_str(), guest_login_stat);//çàïèñü äàííûõ ïî ïğîéäåííîìó òåñòó â îáúåêò Ñòàòèñòèêà
				strcpy(my_test_stat->stat_subject_name, subjectslab[temp_coice - '0']);
				strcpy(my_test_stat->stat_test_name, VectTests.at(temp_coice - '0').GetTestName());	
				my_test_stat->correct_answ_qty = counter_corr_answ;
				my_test_stat->test_rate = temp_test_rate;
				my_test_stat->complete_test = true;	
				
				
				fstream file_read("StatLab.dat", ios::in | ios::binary);//çàïèñü ìàññèâà îáúåêòîâ ñòàòèñòèêà â ôàéë
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

	
	void ShowStatisticForGuest(char * guest_login_stat)// âûâîä ñòàòèñòèêè ïî îïğåäåëåííîìó Ïîëüçîâàòåëş
	{
		char temp[50];
		char temp_coice;
		int pass_tests_counter = 0, correct_answ_counter = 0, aver_rate_counter = 0;
		bool test_passed = false;
		cout << "ÑÒÀÒÈÑÒÈÊÀ ÏÎËÜÇÎÂÀÒÅËß..." << endl;
		cout << "\nÈÌÅŞÙÈÅÑß Â ÍÀËÈ×ÈÈ ÊÀÒÅÃÎĞÈÈ / ÏĞÅÄÌÅÒÛ :" << endl;

		fstream file_read("SubjLab.dat", ios::in | ios::binary);
		if (!file_read.is_open())
		{
			cout << "ÊÀÒÅÃÎĞÈÈ / ÏĞÅÄÌÅÒÛ ÅÙÅ ÍÅ ÑÎÇÄÀÍÛ!!" << endl;
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

			cout << "ÓÊÀÆÈÒÅ ÍÎÌÅĞ ÏĞÅÄÌÅÒÀ ÄËß ÂÛÂÎÄÀ ÂÑÅÉ ÑÒÀÒÈÑÒÈÊÈ ÏÎ ÏĞÅÄÌÅÒÓ:" << endl;
			cout << "ÄËß ÂÛÕÎÄÀ Â ÏĞÅÄÛÄÓÙÅÅ ÌÅÍŞ - 9 : ";
			for (;;) {
				cin >> temp_coice;cin.ignore(100, '\n');
				if (temp_coice == '9' || ((temp_coice - '0' >= 0) && (temp_coice - '0' < size_of_array)))
					break;
				else
					cout << "ÑÄÅËÀÉÒÅ ÏĞÀÂÈËÜÍÛÉ ÂÛÁÎĞ!" << endl;
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
					cout << "Â ÍÀËÈ×ÈÈ ÅÙÅ ÍÅÒ ÑÒÀÒÈÑÒÈÊÈ..." << endl;
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
					cout << "ÑÒÀÒÈÑÒÈÊÀ ÏÎËÜÇÎÂÀÒÅËß ÏÎ ÏĞÅÄÌÅÒÓ " << subjectslab[temp_coice - '0'] << endl;


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
						cout << "\nÊÎËÈ×ÅÑÒÂÎ ÏĞÎÉÄÅÍÍÛÕ ÒÅÑÒÎÂ : " << pass_tests_counter << endl;
						cout << "ÊÎËÈ×ÅÑÒÂÎ ÂÅĞÍÛÕ ÎÒÂÅÒÎÂ    : " << correct_answ_counter << endl;
						cout << "\nÑĞÅÄÍßß ÎÖÅÍÊÀ ÏÎ ÏĞÅÄÌÅÒÓ   : " << aver_rate_counter / pass_tests_counter << endl;
						cout << "-------------------------------------------------------------------" << endl;
					}
					else
					{
						cout << "\nÏÎ ÄÀÍÍÎÌÓ ÏĞÅÄÌÅÒÓ ÅÙÅ ÍÅÒ ÑÒÀÒÈÑÒÈÊÈ!" << endl;
						cout << "-------------------------------------------------------------------" << endl;
					}

					//--------------------------------------------------------------
				//Sleep(5000); AdminMenu_1_3();
				}
			}
		}
		
	}
	void ShowStatisticForAdminCategory()//âûâîä ñòàòèñòèêè ïî îïğåäåëåííîìó ïğåäìåòó
	{
		char temp[50];
		char temp_coice;
		int tests_counter, aver_rate_counter = 0;
		vector<Statistic>StatVectAdmin_Temp;
		cout << "ÑÒÀÒÈÑÒÈÊÀ ÀÄÌÈÍÈÑÒĞÀÒÎĞÀ..." << endl;
		cout << "\nÈÌÅŞÙÈÅÑß Â ÍÀËÈ×ÈÈ ÊÀÒÅÃÎĞÈÈ / ÏĞÅÄÌÅÒÛ :" << endl;

		fstream file_read("SubjLab.dat", ios::in | ios::binary);
		if (!file_read.is_open())
		{
			cout << "ÊÀÒÅÃÎĞÈÈ / ÏĞÅÄÌÅÒÛ ÅÙÅ ÍÅ ÑÎÇÄÀÍÛ!!" << endl;
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

			cout << "ÓÊÀÆÈÒÅ ÍÎÌÅĞ ÏĞÅÄÌÅÒÀ ÄËß ÂÛÂÎÄÀ ÂÑÅÉ ÑÒÀÒÈÑÒÈÊÈ ÏÎ ÏĞÅÄÌÅÒÓ:" << endl;
			cout << "ÄËß ÂÛÕÎÄÀ Â ÏĞÅÄÛÄÓÙÅÅ ÌÅÍŞ - 9 : ";
			for (;;) {
				cin >> temp_coice;cin.ignore(100, '\n');
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
				fstream file_read("StatLab.dat", ios::in | ios::binary);
				if (!file_read.is_open())
				{
					file_read.close();
					cout << "Â ÍÀËÈ×ÈÈ ÅÙÅ ÍÅÒ ÑÒÀÒÈÑÒÈÊÈ..." << endl;
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
					cout << "ÑÒÀÒÈÑÒÈÊÀ ÀÄÌÈÍÈÑÒĞÀÒÎĞÀ ÏÎ ÏĞÅÄÌÅÒÓ " << subjectslab[temp_coice - '0'] << endl;//âûâîä íà ıêğàí ñòàòèñòèêè ïî ïîëüçîâàòåëş

					for (int i = 0; i<StatVectAdmin.size(); i++)//ïîèñê îáúåêòîâ è çàïèñü èõ â âåêòîğ ïî îïğåäåëåííîìó ïîëüçîâàòåëş
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
						cout << "\nÊÎËÈ×ÅÑÒÂÎ ÏĞÎÉÄÅÍÍÛÕ ÒÅÑÒÎÂ : " << StatVectAdmin.size() << endl;
						for (int i = 0; i < StatVectAdmin_Temp.size(); i++)
						{
							tests_counter = 0;
							cout << "ÊÎËÈ×ÅÑÒÂÎ ÏĞÎÉÄÅÍÍÛÕ ÒÅÑÒÎÂ ÏÎËÜÇÎÂÀÒÅËß Ñ ËÎÃÈÍÎÌ : " << DeCodingStr(StatVectAdmin_Temp.at(i).stat_guest_login) << endl;
							for (int j = 0; j < StatVectAdmin.size(); j++)
							{
								if (!strcmp(StatVectAdmin_Temp.at(i).stat_guest_login, StatVectAdmin.at(j).stat_guest_login))
									tests_counter++;
							}
							cout << tests_counter << " øò." <<endl;

						}
						
						for (int i = 0; i< StatVectAdmin.size(); i++)
						{	aver_rate_counter = aver_rate_counter + StatVectAdmin.at(i).test_rate;					
						}
						cout << "ÑĞÅÄÍÈÉ ÁÀËË ÏÎ ÏĞÎÉÄÅÍÍÛÌ ÒÅÑÒÀÌ : ";
						cout << aver_rate_counter / tests_counter << " ÁÀËËÎÂ."<< endl;
						cout << "-------------------------------------------------------------------" << endl;
					}
					else
					{
						cout << "\nÏÎ ÄÀÍÍÎÌÓ ÏĞÅÄÌÅÒÓ ÅÙÅ ÍÅÒ ÑÒÀÒÈÑÒÈÊÈ!" << endl;
						cout << "-------------------------------------------------------------------" << endl;
					}
										
					Sleep(3000); 
				}
			}
		}
	}
	
	void ShowStatisticForAdminTest()//âûâîä ñòàòèñòèêè ïî îïğåäåëåííîìó òåñòó.
	{
		char temp[50];
		char temp_coice;
		int tests_counter = 0;
		vector<string>VectTempLogins;
		cout << "ÑÒÀÒÈÑÒÈÊÀ ÀÄÌÈÍÈÑÒĞÀÒÎĞÀ..." << endl;
		
		fstream file_read("TestsLab.dat", ios::in | ios::binary);//ñ÷èòûâàíèå äàííûõ ïî èìåşùèìñÿ òåñòàì
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
			{	VectTests.push_back(p[i]);	}
		}
		cout << "ÈÌÅŞÙÈÅÑß ÒÅÑÒÛ :" << endl;
		for (int i = 0; i < VectTests.size(); i++)
		{
			cout << "No "<<i<<"  "<<VectTests.at(i).GetTestName() << endl;//âûâîä íîìåğà ïî ïîğÿäêó è íàçâàíèÿ òåñòà
		}
		
			cout << "ÓÊÀÆÈÒÅ ÍÎÌÅĞ ÒÅÑÒÀ ÄËß ÂÛÂÎÄÀ ÑÒÀÒÈÑÒÈÊÈ:" << endl;//îïğåäåëåíèå ïî êàêîìó èìåííî òåñòó èíòåğåñóåò ñòàòèñòèêà
			cout << "ÄËß ÂÛÕÎÄÀ Â ÏĞÅÄÛÄÓÙÅÅ ÌÅÍŞ - n : ";
			for (;;) {
				cin >> temp_coice;cin.ignore(100, '\n');
				if (temp_coice == 'n' || ((temp_coice - '0' >= 0) && (temp_coice - '0' < VectTests.size())))
					break;
				else
					cout << "ÑÄÅËÀÉÒÅ ÏĞÀÂÈËÜÍÛÉ ÂÛÁÎĞ!" << endl;
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
					cout << "Â ÍÀËÈ×ÈÈ ÅÙÅ ÍÅÒ ÑÒÀÒÈÑÒÈÊÈ..." << endl;
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
					cout << "ÑÒÀÒÈÑÒÈÊÀ ÏÎ ÒÅÑÒÓ : " << VectTests.at(temp_coice - '0').GetTestName() << endl;
					
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
						cout << "\nÊÎËÈ×ÅÑÒÂÎ ÏĞÎÉÄÅÍÍÛÕ ÒÅÑÒÎÂ : " << tests_counter << endl;
						
						for (int i = 0; i < VectTempLogins.size(); i++)
						{
							tests_counter = 0;
							cout << "ÊÎËÈ×ÅÑÒÂÎ ÏĞÎÉÄÅÍÍÛÕ ÒÅÑÒÎÂ ÏÎËÜÇÎÂÀÒÅËß Ñ ËÎÃÈÍÎÌ : " << DeCodingStr((char *)VectTempLogins.at(i).c_str()) << endl;
							for (int j = 0; j < StatVectAdmin.size(); j++)
							{
								if (!strcmp(VectTempLogins.at(i).c_str(), StatVectAdmin.at(j).stat_guest_login))
									tests_counter++;
							}
							cout << tests_counter << " øò." << endl;

						}
						cout << "ÑËÅÄÓŞÙÈÅ ÏÎËÜÇÎÂÀÒÅËÈ Ñ ËÎÃÈÍÀÌÈ ÈÌÅŞÒ ÁÀËË ÂÛØÅ 10 : "<<endl;
						bool higher_then_10 = false;
						for (int i = 0; i< StatVectAdmin.size(); i++)
						{
							if (StatVectAdmin.at(i).test_rate > 10)
							{
								cout << DeCodingStr(StatVectAdmin.at(i).stat_guest_login) << " : " << StatVectAdmin.at(i).test_rate << " ÁÀËËÎÂ" << endl;
								higher_then_10 = true;
							}
						}
					if (!higher_then_10) cout << "ÍÅÒ ÎÒÌÅÒÎÊ ÂÛØÅ 10 ÁÀËËÎÂ! " << endl;
						cout << "-------------------------------------------------------------------" << endl;
					
					Sleep(3000);
				}
			}
		}
	
	void ShowStatisticForAdminbyGuest()//âûâîä ñòàòèñòèêè ïî îïğåäåëåííîìó ïîëüçîâàòåëş
	{
		char temp[50];
		char temp_coice;
		int tests_counter = 0;
		int avar_rate;
		vector<string>VectTempSubj;
		
		cout << "ÑÒÀÒÈÑÒÈÊÀ ÀÄÌÈÍÈÑÒĞÀÒÎĞÀ ÏÎ ÎÏĞÅÄÅËÅÍÍÎÌÓ ÏÎËÜÇÎÂÀÒÅËŞ..." << endl;

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
		cout << "ÈÌÅŞÙÈÅÑß Â ÁÀÇÅ ËÎÃÈÍÛ ÏÎËÜÇÎÂÀÒÅËÅÉ :" <<endl;
		for (int i = 0; i < VectGuests.size(); i++)
		{
			cout << "No" << i << " - " << DeCodingStr((char *)VectGuests.at(i).GetGuestLogin()).c_str() << " ; ";
		}
		
		//----------------------------------------------------------------------------

		cout << "ÓÊÀÆÈÒÅ ÏÎĞßÄÊÎÂÛÉ ¹ ÏÎËÜÇÎÂÀÒÅËß ÄËß ÂÛÂÎÄÀ ÑÒÀÒÈÑÒÈÊÈ:" << endl;
		cout << "ÄËß ÂÛÕÎÄÀ Â ÏĞÅÄÛÄÓÙÅÅ ÌÅÍŞ - n : ";
		for (;;) {
			cin >> temp_coice;cin.ignore(100, '\n');
			if (temp_coice == 'n' || ((temp_coice - '0' >= 0) && (temp_coice - '0' < VectGuests.size())))
				break;
			else
				cout << "ÑÄÅËÀÉÒÅ ÏĞÀÂÈËÜÍÛÉ ÂÛÁÎĞ!" << endl;
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
				cout << "Â ÍÀËÈ×ÈÈ ÅÙÅ ÍÅÒ ÑÒÀÒÈÑÒÈÊÈ..." << endl;
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
				cout << "ÑÒÀÒÈÑÒÈÊÀ ÏÎ ÏÎËÜÇÎÂÀÒÅËŞ : " << DeCodingStr((char *)VectGuests.at(temp_coice - '0').GetGuestLogin()).c_str() << endl;
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
				cout << "\nÊÎËÈ×ÅÑÒÂÎ ÏĞÎÉÄÅÍÍÛÕ ÒÅÑÒÎÂ : " << tests_counter << endl;

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
					cout << "ÊÎËÈ×ÅÑÒÂÎ ÏĞÎÉÄÅÍÍÛÕ ÒÅÑÒÎÂ ÏÎ ÏĞÅÄÌÅÒÓ : " << VectTempSubj.at(i) << endl;
					cout << tests_counter << " øò." << endl;
					cout << "ÑĞÅÄÍÈÉ ÁÀËË ÏÎ ÏĞÅÄÌÅÒÓ                 : " << endl;
					cout << avar_rate << " ÁÀËËÎÂ" << endl;
				}
								
				cout << "-------------------------------------------------------------------" << endl;

				Sleep(3000);
			}
		}

	}
	
	void ExportStatisticToFile()//ıêñïîğò ñòàòèñòèêè â ôàéë
	{
		char temp[50];
		char temp_coice;
		int tests_counter = 0;
		int avar_rate;
		vector<string>VectTempSubj;

		cout << "ÂÛÂÎÄ Â ÔÀÉË ÑÒÀÒÈÑÒÈÊÈ ÏÎ ÎÏĞÅÄÅËÅÍÍÎÌÓ ÏÎËÜÇÎÂÀÒÅËŞ..." << endl;

		fstream file_read("GuestsLab.dat", ios::in | ios::binary);//ñ÷èòûâàåì äàííûå èç ôàéëà ïî Ïîëüçîâàòåëÿì

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
			VectGuests.push_back(p[i]);//çàïîëíÿåì âåêòîğ îáúåêòàìè òèïà Ïîëçîâàòåëü
		}
		delete[] p;

		file_read.close();
		cout << "ÈÌÅŞÙÈÅÑß Â ÁÀÇÅ ËÎÃÈÍÛ ÏÎËÜÇÎÂÀÒÅËÅÉ :" << endl;
		for (int i = 0; i < VectGuests.size(); i++)//ïåğå÷èñëÿåì âñåõ ïîëüçîâàòåëåé äëÿ âûáîğà
		{
			cout << "No" << i << " - " << DeCodingStr((char *)VectGuests.at(i).GetGuestLogin()) << " ; ";
		}

		//----------------------------------------------------------------------------

		cout << "ÓÊÀÆÈÒÅ ÏÎĞßÄÊÎÂÛÉ ¹ ÏÎËÜÇÎÂÀÒÅËß ÄËß ÂÛÂÎÄÀ ÑÒÀÒÈÑÒÈÊÈ:" << endl;
		cout << "ÄËß ÂÛÕÎÄÀ Â ÏĞÅÄÛÄÓÙÅÅ ÌÅÍŞ - n : ";
		for (;;) {
			cin >> temp_coice;cin.ignore(100, '\n');
			if (temp_coice == 'n' || ((temp_coice - '0' >= 0) && (temp_coice - '0' < VectGuests.size())))
				break;
			else
				cout << "ÑÄÅËÀÉÒÅ ÏĞÀÂÈËÜÍÛÉ ÂÛÁÎĞ!" << endl;
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
				cout << "Â ÍÀËÈ×ÈÈ ÅÙÅ ÍÅÒ ÑÒÀÒÈÑÒÈÊÈ..." << endl;
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
					StatVectAdmin.push_back(p[i]);// çàïîëíÿåì âåêòîğ îáúåêòàìè êëàññà Ñòàòèñòèêà
				}
				delete[]p;

				cout << "-------------------------------------------------------------------" << endl;//âûâîä ñòàòèñòèêè ïî îïğåäåëåííîìó ïîëüçîâàòåëş
				cout << "ÑÒÀÒÈÑÒÈÊÀ ÏÎ ÏÎËÜÇÎÂÀÒÅËŞ : " << DeCodingStr((char *)VectGuests.at(temp_coice - '0').GetGuestLogin()) << endl;
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


				cout << "\nÓÊÀÆÈÒÅ ÈÌß ÔÀÉËÀ ÄËß ÈÌÏÎĞÒÀ ÊÀÒÅÃÎĞÈÉ / ÏĞÅÄÌÅÒÎÂ: " << endl;
				cout << "ÍÀÏĞÈÌÅĞ, C:\\Categories.txt :" << endl;
				//cin.ignore();
				gets_s(temp);
				

				fstream file_write(temp, ios::out | ios::trunc);//çàïèñü ñòàòèñòèêè â óêàçàííûé ôàéë

				if (!file_write.is_open())
				{cout << "Error to open for writing!" << endl;	}
				file_write << "=========================================================" << endl;
				file_write << "ÏĞÎÃĞÀÌÌÀ ÏÎ ÒÅÑÒÈĞÎÂÀÍÈŞ ÑÒÓÄÅÍÒÎÂ ÏÎ ÏĞÅÄÌÅÒÀÌ" << endl;
				file_write << "ÌÀÒÅÌÀÒÈÊÀ, ÔÈÇÈÊÀ È Ò.Ä." << endl;
				file_write << "                                          <<ÒÅÑÒÎĞ 2018>>" << endl;
				file_write << "=========================================================" << endl;
				file_write << "-------------------------------------------------------------------------------------------" << endl;
				file_write << "İÊÑÏÎĞÒ ÑÒÀÒÈÑÒÈÊÈ ÈÇ ÏĞÎÃĞÀÌÌÛ ÏÎ ÏÎËÜÇÎÂÀÒÅËŞ :" << endl; 
				file_write << VectGuests.at(temp_coice - '0').GetGuestName() << " " << VectGuests.at(temp_coice - '0').GetGuestSurname() << endl;
				file_write << "-------------------------------------------------------------------------------------------" << endl<<endl;
				file_write << "ÊÎËÈ×ÅÑÒÂÎ ÏĞÎÉÄÅÍÍÛÕ ÒÅÑÒÎÂ : " << tests_counter << endl;

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
					file_write << "ÊÎËÈ×ÅÑÒÂÎ ÏĞÎÉÄÅÍÍÛÕ ÒÅÑÒÎÂ ÏÎ ÏĞÅÄÌÅÒÓ : " << VectTempSubj.at(i) << endl;
					file_write << tests_counter << " øò." << endl;
					file_write << "ÑĞÅÄÍÈÉ ÁÀËË ÏÎ ÏĞÅÄÌÅÒÓ                 : " << endl;
					file_write << avar_rate << " ÁÀËËÎÂ" << endl;
				}
				file_write << "-------------------------------------------------------------------------------------------" << endl;

				file_write.flush();
				file_write.close();

				cout << "ÑÒÀÒÈÑÒÈÊÀ ÓÑÏÅØÍÎ İÊÑÏÎĞÒÈĞÎÂÀÍÀ Â ÓÊÀÇÀÍÍÛÉ ÔÀÉË!" << endl;
				Sleep(5000);

			}
		}

	
	}
	void EditGuestAcc()//êîğğåêòèğîâêà àêêàóíòà ïîëüçîâàòåëÿ
	{
		char templog[50], temppass[50], tempguest_address[250];
		bool if_acc_match = false;

		cout << "\nÈÇÌÅÍÅÍÈÅ ÄÀÍÍÛÕ ÏÎ ÏÎËÜÇÎÂÀÒÅËŞ..." << endl;

		fstream file_read("GuestsLab.dat", ios::in | ios::binary);
		if (!file_read.is_open())
		{
			file_read.close();
			cout << "\nÏÎËÜÇÎÂÀÒÅËÈ ÅÙÅ ÍÅ ÑÎÇÄÀÍÛ!" << endl;	Sleep(3000); return;
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
			cout << "ÓÊÀÆÈÒÅ ËÎÃÈÍ ÄËß ÊÎĞĞÅÊÒÈĞÎÂÊÈ ÄÀÍÍÛÕ : ";
			//cin.ignore();
			gets_s(templog);
			for (int i = 0; i < VectGuests.size(); i++)
			{
				if (!strcmp(DeCodingStr((char *)VectGuests.at(i).GetGuestLogin()).c_str(), templog))
				{	if_acc_match = true; guest_number = i;	}
			}
			if (!if_acc_match)
			{
				cout << "ÈÇÂÈÍÈÒÅ, ÂÂÅÄÅÍÍÛÅ ÄÀÍÍÛÅ ÍÅ ÑÎÎÒÂÅÒÑÒÂÓŞÒ ËÎÃÈÍÓ!" << endl;
				cout << "ÏÎÂÒÎĞÈÒÅ ÏÎÏÛÒÊÓ!" << endl;
			}


		} while (!if_acc_match);

		cout << "ÄÀÍÍÛÅ ÏÎËÜÇÎÂÀÒÅËß Â ÑÈÑÒÅÌÅ ÑËÅÄÓŞÙÈÅ :" << endl;
		VectGuests.at(guest_number).ShowGuestDetails();
		cout << "\nÓÊÀÆÈÒÅ ÍÎÂÛÅ ÄÀÍÍÛÅ ÏÎ ÏÎËÜÇÎÂÀÒÅËŞ : " << endl;
		cout << "ÈÌß ÏÎËÜÇÎÂÀÒÅËß                     : ";
		cin.ignore(100, '\n');
		gets_s(templog); VectGuests.at(guest_number).SetGSurname(templog);
		cout << "ÔÀÌÈËÈß ÏÎËÜÇÎÂÀÒÅËß                 : ";
		gets_s(templog); VectGuests.at(guest_number).SetGSurname(templog);
		cout << "ËÎÃÈÍ ÀÊÊÀÓÍÒÀ ÏÎËÜÇÎÂÀÒÅËß          : " ;
		gets_s(templog); VectGuests.at(guest_number).SetGLogin((char *)CodingStr(templog).c_str());
		cout << "ÏÀĞÎËÜ ÀÊÊÀÓÍÒÀ ÏÎËÜÇÎÂÀÒÅËß         : " ;
		gets_s(templog); VectGuests.at(guest_number).SetGPass((char *)CodingStr(templog).c_str());
		cout << "ÒÅËÅÔÎÍ                              : ";
		gets_s(templog); VectGuests.at(guest_number).SetGPhone(templog);
		cout << "ÀÄĞÅÑ                                : ";
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
		cout << "\nÀÊÊÀÓÍÒ ÏÎËÜÇÎÂÀÒÅËß ÁÛË ÓÑÏÅØÍÎ ÎÁÍÎÂËÅÍ!" << endl;
		Sleep(3000);
	}
	
	void ImportCatFromFile()// Èìïîğò êàòåãîğèé / ïğåäìåòîâ èç ğàíåå ïîäãîòâîëåííîãî ôàéëà
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
			//gets_s(temp);

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
			//gets_s(temp);

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

	
	void ExportCatToFile()//İêñïîğò êàòåãîğèé / ïğåäìåòîâ â áàçó
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

			cout << "\nÓÊÀÆÈÒÅ ÈÌß ÔÀÉËÀ ÄËß İÊÑÏÎĞÒÀ ÊÀÒÅÃÎĞÈÉ / ÏĞÅÄÌÅÒÎÂ: " << endl;
			cout << "ÍÀÏĞÈÌÅĞ, C:\\Categories.txt :" << endl;
			gets_s(temp);
			//gets_s(temp);

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


	void EditTest()//èçìåíåíèå ñóùåñòâóşùåãî â ïğîãğàììå òåñòà 
	{
		char temp[50];
		char temp_coice;

		cout << "ÊÎĞĞÅÊÒÈĞÎÂÊÀ ÒÅÑÒÀ.." << endl;
		cout << "ÈÌÅŞÙÈÅÑß Â ÍÀËÈ×ÈÈ ÊÀÒÅÃÎĞÈÈ / ÏĞÅÄÌÅÒÛ :" << endl;

		fstream file_read("SubjLab.dat", ios::in | ios::binary); //ñ÷èòûâàåíèå ïåğå÷íÿ ïğåäìåòîâ èç ôàéëà â ìàññèâ
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
				cout << "No " << i << "  " << subjectslab[i] << endl;//ïîêàç èìåşùèõñÿ ïğåäìåòîâ

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

					for (int i = 0; i < VectTests.size(); i++)//âûâîä íà ıêğàí òåñòîâ
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
					VectTests.at(temp_coice - '0').DisplayTest();//âûâîä íà ıêğàí òåñòà äëÿ êîğğåêòèğîâêè
					obj = VectTests.at(temp_coice - '0');
					Question temp_arr[2];
					for (int i = 0; i < 2; i++)
					{
						
						cout << "ÏÎÆÀËÓÉÑÒÀ, ÓÊÀÆÈÒÅ ÍÎÂÎÅ ÍÀÏĞÀÂËÅÍÈÅ ÒÅÑÒÀ:" << endl;
						cout << "ÍÀÏĞÈÌÅĞ, ÊÂÀÍÒÎÂÀß ÔÈÇÈÊÀ.." << endl;
						cin.ignore(100, '\n');
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

	void ExportTestToFile()//İêñïîğò òåñòà â ôàéë
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
						cin >> temp_coice;  cin.ignore(100, '\n');
						if ( (temp_coice - '0' >= 0) || (temp_coice - '0' < VectTests.size()) )
							break;
						else
							cout << "ÑÄÅËÀÉÒÅ ÏĞÀÂÈËÜÍÛÉ ÂÛÁÎĞ!" << endl;
					}

					mytestobj = new Test[1];
					*mytestobj = VectTests.at(temp_coice - '0');
					
					fstream file_write("TestsExport.txt", ios::out | ios::trunc); //âûâîä òåñòà â ğàíåå îïğåäåëåííûé ôàéë
					
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

	void ImportTestFromFile()//èìïîğò òåñòà èç ğàíåå ïîäãîòîâëåííîãî ôàéëà
	{
		char temp[50];
		char temp_coice;

		cout << "ÈÌÏÎĞÒ ÒÅÑÒÀ ÈÇ ÔÀÉËÀ.." << endl;
		cout << "ÈÌÅŞÙÈÅÑß Â ÍÀËÈ×ÈÈ ÊÀÒÅÃÎĞÈÈ / ÏĞÅÄÌÅÒÛ :" << endl;

		fstream file_read("SubjLab.dat", ios::in | ios::binary);//ñ÷èòûâàíèå èìåşùèõñÿ â íàëè÷èè ïğåäìåòîâ äëÿ îïğåäåëåíèÿ êàòåãîğèè
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
				cin >> temp_coice;cin.ignore(100, '\n');
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
				char temp_semi_subj[500], temp_question[500], temp_answ0[50], temp_answ1[50],
					temp_answ2[50], temp_answ3[50];
				char correct_answ;
				int temp_corr_answ;
				ifstream import("ImportTest.txt", ios::in);
				import.seekg(0);
				if (!import)
				{	cout << "ÎØÈÁÊÀ ÎÒÊĞÛÒÈß ÔÀÉËÀ\n";	system("pause");}

					getline(import, _semi_subject);//ñ÷èòûâàíèå äàííûõ èç ôàéëà âî âğåìåííóş ïåğåìåííóş
					strcpy(temp_semi_subj, _semi_subject.c_str());//êîïèğîâàíèå äàííûõ â ïîëå îáúåêòà 
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
	
string CodingStr(char * str)//êîäèğîâàíèå ñòğîêè
{
	string str_temp;
	str_temp = str;
	for (int i = 0; i <str_temp.size(); i++) {
		str_temp[i] = str_temp[i] + 3;
	}
	return str_temp;
}

string DeCodingStr(char * str)//ğàñêîäèğîâàíèå ñòğîêè
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
	//myadmin.ImportTestFromFile();//+ äîäåëàòü çàïèñü â ôàéë..
	//myadmin.ShowStatisticForAdminTest();
	//myadmin.ShowStatisticForAdminbyGuest();
	//myadmin.ExportStatisticToFile();
	//myadmin.ExportCatToFile();


	//	system ("pause");
	return 0;
}
