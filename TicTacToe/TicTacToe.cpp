// TicTacToe.cpp : Defines the entry point for the application.
//
#include<iostream>

#include <cstdlib>
#include <ctime>
#include"windows.h"
#include "stdafx.h"
#include "TicTacToe.h"
#include<time.h>
#include<string>

#define MAX_LOADSTRING 100
using namespace std;

// Global Variables:
HINSTANCE hInst;
static BOOL game[3][3];
static TCHAR gameTCHAR[3][3];
static TCHAR player;
static TCHAR computer;
static INT cntOfMove = 0;
static INT roundOfGame = 0;
static INT radioCheck = 1;
static HWND but1, but2, but3, but4, but5, but6, but7, but8, but9;
// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
INT_PTR CALLBACK    Game(HWND, UINT, WPARAM, LPARAM);
void				initGame(BOOL[][3], TCHAR[][3]);
void				computerPlay(TCHAR, LPARAM);
BOOL				cheking(HWND, int, int);
BOOL				play(int, int);
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);
	srand((unsigned)time(NULL));
	initGame(game, gameTCHAR);

//	srand(std::time(NULL));
	DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG02), NULL, Game);

    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK Game(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	//BOOL isChecked1, isChecked2, isChecked3;
	static BOOL isChecked = TRUE;
	

	static HBITMAP bitMapO;// = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP1));
	static HBITMAP bitMapX;// = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP2));

    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
	case WM_INITDIALOG: {	
		hInst = GetModuleHandle(NULL);
		player = TEXT('X');
		computer = TEXT('O');
		CheckRadioButton(hDlg, IDC_RADIO1, IDC_RADIO3, IDC_RADIO1);
		CheckDlgButton(hDlg, IDC_CHECK1, BST_UNCHECKED);
		bitMapX = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP1));
		bitMapO = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP2));
		//HWND hButton = GetDlgItem(hDlg, IDC_BUTTON1);
		//HMODULE hInstance = GetModuleHandle(NULL);
		//HBITMAP hBitmap = LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAP1));
		//SendMessage(hButton, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap);
		//return (INT_PTR)TRUE;



	//	HICON bitMapO = (HICON)LoadImage(hInst, MAKEINTRESOURCE(IDI_ICON1), IMAGE_ICON, 30, 30, LR_LOADTRANSPARENT);
		

	//HBITMAP bitMapO = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP1));
		::but1 = GetDlgItem(hDlg, IDC_BUTTON11);
		::but2 = GetDlgItem(hDlg, IDC_BUTTON12);
		::but3 = GetDlgItem(hDlg, IDC_BUTTON13);
		::but4 = GetDlgItem(hDlg, IDC_BUTTON14);
		::but5 = GetDlgItem(hDlg, IDC_BUTTON15);
		::but6 = GetDlgItem(hDlg, IDC_BUTTON16);
		::but7 = GetDlgItem(hDlg, IDC_BUTTON17);
		::but8 = GetDlgItem(hDlg, IDC_BUTTON18);
		::but9 = GetDlgItem(hDlg, IDC_BUTTON19);

	//SendMessage(but1, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bitMapO);
	}return (INT_PTR)TRUE;

    case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_BUTTON1: {
			SetWindowText(GetDlgItem(hDlg, IDC_STATIC2), TEXT("Game is started..."));
			computerPlay(computer, (LPARAM)bitMapO);
			if (radioCheck == 1) {

			}
			else if (radioCheck == 2) {

			}
			else if (radioCheck == 3) {

			}
		}return (INT_PTR)TRUE;

			case IDC_CHECK1: {
				isChecked = !isChecked;
				if (!isChecked) {
					player = TEXT('O');
					computer = TEXT('X');
					bitMapX = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP2));
					bitMapO = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP1));
				}
			}return (INT_PTR)TRUE;

			case IDC_BUTTON11:{
				if (play(0, 0)) {
					SendMessage(but1, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bitMapX);
					gameTCHAR[0][0] = player;
					computerPlay(computer, (LPARAM)bitMapO);
				}
				else {
					MessageBox(hDlg, TEXT("this place is already taken"), TEXT("Error"), MB_OK| MB_ICONERROR);
				}
				if (cheking(hDlg, 0, 0)) {
					MessageBox(hDlg, TEXT("WIN"), TEXT("WIN"), MB_OK);
				}
			}return (INT_PTR)TRUE;

			case IDC_BUTTON12: {
				if (play(0, 1)) {
					SendMessage(but2, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bitMapX);
					gameTCHAR[0][1] = player;
					computerPlay(computer, (LPARAM)bitMapO);
				}
				else {
					MessageBox(hDlg, TEXT("this place is already taken"), TEXT("Error"), MB_OK | MB_ICONERROR);
				}
				if (cheking(hDlg, 0, 1)) {
					MessageBox(hDlg, TEXT("WIN"), TEXT("WIN"), MB_OK);
				}
			}return (INT_PTR)TRUE;

			case IDC_BUTTON13: {
				if (play(0, 2)) {
					SendMessage(but3, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bitMapX);
					gameTCHAR[0][2] = player;
					computerPlay(computer, (LPARAM)bitMapO);
				}
				else {
					MessageBox(hDlg, TEXT("this place is already taken"), TEXT("Error"), MB_OK | MB_ICONERROR);
				}
				if (cheking(hDlg, 0, 2)) {
					MessageBox(hDlg, TEXT("WIN"), TEXT("WIN"), MB_OK);
				}
			}return (INT_PTR)TRUE;

			case IDC_BUTTON14: {////
				if (play(1, 0)) {
					SendMessage(but4, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bitMapX);
					gameTCHAR[1][0] = player;
					computerPlay(computer, (LPARAM)bitMapO);
				}
				else {
					MessageBox(hDlg, TEXT("this place is already taken"), TEXT("Error"), MB_OK | MB_ICONERROR);
				}
				if (cheking(hDlg, 1, 0)) {
					MessageBox(hDlg, TEXT("WIN"), TEXT("WIN"), MB_OK);
				}
			}return (INT_PTR)TRUE;

			case IDC_BUTTON15: {
				if (play(1, 1)) {
					SendMessage(but5, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bitMapX);
					gameTCHAR[1][1] = player;
					computerPlay(computer, (LPARAM)bitMapO);
				}
				else {
					MessageBox(hDlg, TEXT("this place is already taken"), TEXT("Error"), MB_OK | MB_ICONERROR);
				}
				if (cheking(hDlg, 1, 1)) {
					MessageBox(hDlg, TEXT("WIN"), TEXT("WIN"), MB_OK);
				}
			}return (INT_PTR)TRUE;

			case IDC_BUTTON16: {
				if (play(1, 2)) {
					SendMessage(but6, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bitMapX);
					gameTCHAR[1][2] = player;
					computerPlay(computer, (LPARAM)bitMapO);
				}
				else {
					MessageBox(hDlg, TEXT("this place is already taken"), TEXT("Error"), MB_OK | MB_ICONERROR);
				}
				if (cheking(hDlg, 1, 2)) {
					MessageBox(hDlg, TEXT("WIN"), TEXT("WIN"), MB_OK);
				}
			}return (INT_PTR)TRUE;

			case IDC_BUTTON17: {
				if (play(2, 0)) {
					SendMessage(but7, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bitMapX);
					gameTCHAR[2][0] = player;
					computerPlay(computer, (LPARAM)bitMapO);
				}
				else {
					MessageBox(hDlg, TEXT("this place is already taken"), TEXT("Error"), MB_OK | MB_ICONERROR);
				}
				if (cheking(hDlg, 2, 0)) {
					MessageBox(hDlg, TEXT("WIN"), TEXT("WIN"), MB_OK);
				}
			}return (INT_PTR)TRUE;

			case IDC_BUTTON18: {
				if (play(2, 1)) {
					SendMessage(but8, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bitMapX);
					gameTCHAR[2][1] = player;
					computerPlay(computer, (LPARAM)bitMapO);
				}
				else {
					MessageBox(hDlg, TEXT("this place is already taken"), TEXT("Error"), MB_OK | MB_ICONERROR);
				}
				if (cheking(hDlg, 2, 1)) {
					MessageBox(hDlg, TEXT("WIN"), TEXT("WIN"), MB_OK);
				}
			}return (INT_PTR)TRUE;

			case IDC_BUTTON19: {
				if (play(2, 2)) {
					SendMessage(but9, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bitMapX);
					gameTCHAR[2][2] = player;
					computerPlay(computer, (LPARAM)bitMapO);
				}
				else {
					MessageBox(hDlg, TEXT("this place is already taken"), TEXT("Error"), MB_OK | MB_ICONERROR);
				}
				if (cheking(hDlg, 2, 2)) {
					MessageBox(hDlg, TEXT("WIN"), TEXT("WIN"), MB_OK);
				}
			}return (INT_PTR)TRUE;

			case IDC_RADIO1: {
				::radioCheck = 1;
			}return (INT_PTR)TRUE;
			case IDC_RADIO2: {
				::radioCheck = 2;
			}return (INT_PTR)TRUE;
			case IDC_RADIO3: {
				::radioCheck = 3;
			}return (INT_PTR)TRUE;

			
			default:
				break;
		}
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
void initGame(BOOL game[3][3], TCHAR gameTCHAR[3][3]) {
	for (auto i = 0; i < 3; i++)
		for (auto j = 0; j < 3; j++)
		{
			game[i][j] = TRUE;
			gameTCHAR[i][j] = TEXT('_');
		}
}
void computerPlay(TCHAR comp, LPARAM bitMapO) {
	if (radioCheck == 1) {
	label:
		INT koord1 = rand() % 3;
		INT koord2 = rand() % 3;
		if (play(koord1, koord2)) {
			if (koord1 == 0 && koord2 == 0) {
				SendMessage(::but1, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bitMapO);
				gameTCHAR[0][0] = comp;
			}
			else if (koord1 == 0 && koord2 == 1) {
				SendMessage(::but2, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bitMapO);
				gameTCHAR[0][1] = comp;
			}
			else if (koord1 == 0 && koord2 == 2) {
				SendMessage(::but3, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bitMapO);
				gameTCHAR[0][2] = comp;
			}
			else if (koord1 == 1 && koord2 == 0) {
				SendMessage(::but4, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bitMapO);
				gameTCHAR[1][0] = comp;
			}
			else if (koord1 == 1 && koord2 == 1) {
				SendMessage(::but5, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bitMapO);
				gameTCHAR[1][1] = comp;
			}
			else if (koord1 == 1 && koord2 == 2) {
				SendMessage(::but6, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bitMapO);
				gameTCHAR[1][2] = comp;
			}
			else if (koord1 == 2 && koord2 == 0) {
				SendMessage(::but7, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bitMapO);
				gameTCHAR[2][0] = comp;
			}
			else if (koord1 == 2 && koord2 == 1) {
				SendMessage(::but8, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bitMapO);
				gameTCHAR[2][1] = comp;
			}
			else if (koord1 == 2 && koord2 == 2) {
				SendMessage(::but9, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bitMapO);
				gameTCHAR[2][2] = comp;
			}
		}
		else {
			if (cntOfMove == 9) {
				return;
			}
			goto label;
		}
	}
	else if (radioCheck == 2) {

	}
}

BOOL play(int koord1, int koord2) {
	if (game[koord1][koord2] == TRUE) {
		game[koord1][koord2] = FALSE;
		::cntOfMove++;
		return true;
	}
	else {
		return false;
	}
}

BOOL cheking(HWND hDlg, int koord1, int koord2) {
	int count, count1;
	char tmp;
	for (int i = 0; i <= koord1; i++)//////////////////////////////////////gorisontal
	{
		count = 0;
		count1 = 0;
		for (int j = 0; j <= koord2; j++)
		{
			if (gameTCHAR[i][j] == TEXT('X')) {
				tmp = gameTCHAR[i][j];
				count++;
			}
			if (gameTCHAR[i][j] == TEXT('O')) {
				tmp = gameTCHAR[i][j];
				count1++;
			}
		}
		if (count == 3) {
			SendMessage(GetDlgItem(hDlg, IDC_LIST2), LB_ADDSTRING, 0, (LPARAM)TEXT("X win "));
			::roundOfGame++;
			return TRUE;
		}
		else if (count1 == 3) {
			SendMessage(GetDlgItem(hDlg, IDC_LIST2), LB_ADDSTRING, 0, (LPARAM)TEXT("O win "));
			::roundOfGame++;
			return TRUE;
		}
	}
	for (int i = 0; i <= koord2; i++)   //////////////////////////////////vertical
	{
		count = 0;
		count1 = 0;
		for (int j = 0; j <= koord1; j++)
		{
			if (gameTCHAR[j][i] == TEXT('X')) {
				tmp = gameTCHAR[j][i];
				count++;
			}
			if (gameTCHAR[j][i] == TEXT('O')) {
				tmp = gameTCHAR[j][i];
				count1++;

			}
		}
		if (count == 3) {
			SendMessage(GetDlgItem(hDlg, IDC_LIST2), LB_ADDSTRING, 0, (LPARAM)TEXT("X win "));
			::roundOfGame++;
			return TRUE;
		}
		else if (count1 == 3) {
			SendMessage(GetDlgItem(hDlg, IDC_LIST2), LB_ADDSTRING, 0, (LPARAM)TEXT("O win "));
			::roundOfGame++;
			return TRUE;
		}
	}

	count = 0;
	count1 = 0;
	for (int i = 0; i <= koord1 - 1; i++)//////////////////////////////////diagonal # 1
	{
		for (int j = 0; j <= koord2 - 1; j++)
		{
			if (i == j && gameTCHAR[i][j] == TEXT('X') && gameTCHAR[i + 1][j + 1] == TEXT('X')) {
				count++;
			}
			if (i == j && gameTCHAR[i][j] == TEXT('O') && gameTCHAR[i + 1][j + 1] == TEXT('O')) {
				count1++;
			}
		}
		if (count == 2) {
			SendMessage(GetDlgItem(hDlg, IDC_LIST2), LB_ADDSTRING, 0, (LPARAM)TEXT("X win "));
			::roundOfGame++;
			return TRUE;
		}
		else if (count1 == 2) {
			SendMessage(GetDlgItem(hDlg, IDC_LIST2), LB_ADDSTRING, 0, (LPARAM)TEXT("O win "));
			::roundOfGame++;
			return TRUE;
		}
	}
	count = 0;
	count1 = 0;
	for (int i = 0; i <= koord1 - 1; i++)  //////////////////////////////////diagonal # 2
	{
		for (int j = koord2 - 1; j >= 0; j--)
		{
			if (i + j == 2 && gameTCHAR[i][j] == TEXT('X') && gameTCHAR[i + 1][j - 1] == TEXT('X')) {
				count++;
			}
			if (i + j == 2 && gameTCHAR[i][j] == TEXT('O') && gameTCHAR[i + 1][j - 1] == TEXT('O')) {
				count1++;
			}
		}
		if (count == 2) {
			::roundOfGame++;
			SendMessage(GetDlgItem(hDlg, IDC_LIST2), LB_ADDSTRING, 0, (LPARAM)TEXT("X win "));
			return TRUE;
		}
		else if (count1 == 2) {
			::roundOfGame++;
			SendMessage(GetDlgItem(hDlg, IDC_LIST2), LB_ADDSTRING, 0, (LPARAM)TEXT("O win "));
			return TRUE;
		}
	}
	return FALSE;
}