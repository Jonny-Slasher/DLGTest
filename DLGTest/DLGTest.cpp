#include"resource.h"
#include <Windows.h>
#include <iostream>

HWND hEdit1;
HWND hEdit2;
HWND hEdit3;
HWND hList;
WCHAR boofer[300];
BOOL CALLBACK DlgProc1(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK DlgProc2(HWND, UINT, WPARAM, LPARAM);
HINSTANCE hInst;


int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
    DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), 0, DLGPROC(DlgProc1), 0);
    return 0;
}

BOOL CALLBACK DlgProc1(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  
    switch (uMsg) 
    {
    case WM_INITDIALOG: 
        hInst = GetModuleHandle(NULL);
       
        hList = GetDlgItem(hwnd,IDC_LIST1);
     
        break;
    case WM_COMMAND:
        switch (LOWORD(wParam)) 
    {
    case ID_MODAL: {
     
        DialogBoxParam(hInst, MAKEINTRESOURCE(IDD_DIALOG2), hwnd, DLGPROC(DlgProc2), 0);
    }
                 break;
    }
    break;
    case WM_CLOSE: {
        EndDialog(hwnd, 0);
        return FALSE;
    }
    }
    return FALSE;
}
BOOL CALLBACK DlgProc2(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    WCHAR first[100];
    WCHAR second[100];
    WCHAR third[100];
    switch (uMsg) 
    {
    case WM_INITDIALOG: 
        hEdit1 = GetDlgItem(hwnd, IDC_EDIT1);
        hEdit2 = GetDlgItem(hwnd, IDC_EDIT2);
        hEdit3 = GetDlgItem(hwnd, IDC_EDIT3);
        SetFocus(hEdit1);
      

        break;
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDOK: {
             // hList = GetDlgItem(hwnd, IDC_LIST1);
              SendMessage(hEdit1, WM_GETTEXT, (WPARAM)255, (LPARAM)first);
              SendMessage(hEdit2, WM_GETTEXT, (WPARAM)255, (LPARAM)second);
              SendMessage(hEdit3, WM_GETTEXT, (WPARAM)255, (LPARAM)third);
              wsprintf(boofer, L"%s %s %s", first, second, third);
              SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)boofer);
             // SendMessage(hEdit1, WM_SETTEXT, 0, (LPARAM)boofer);
              EndDialog(hwnd, 0);
           
        }
                     break;
        }
        break;
    
    break;
    case WM_CLOSE: {
        EndDialog(hwnd, 0);
        return FALSE;
    }
    }
    return FALSE;
}