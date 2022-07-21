#include "framework.h"

void UpdateConsole(HWND hwndList,char* ToAddtext, int stringSize, int ID) {

	ID = (ID < 0) ? ID = 0 : ID;
	static int ListBoxItemNumbers = -1;
	wchar_t* textToPrint = (wchar_t*)malloc(sizeof(wchar_t) * stringSize);

	for (int i = 0; i < stringSize; i++) {
		textToPrint[i] = ToAddtext[i];
	}
	if (ID > ListBoxItemNumbers) {
		SendMessage(hwndList, LB_INSERTSTRING, ID, (LPARAM)textToPrint);
	}
	else {
		SendMessage(hwndList, LB_DELETESTRING, ID, (LPARAM)textToPrint);
		SendMessage(hwndList, LB_INSERTSTRING, ID, (LPARAM)textToPrint);
	}
	ListBoxItemNumbers++;
}