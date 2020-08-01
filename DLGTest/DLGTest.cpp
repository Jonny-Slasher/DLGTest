#include"resource.h"
#include <Windows.h>
#include <iostream>

HWND hEdit1;
HWND hEdit2;
WCHAR boofer[100];
BOOL CALLBACK DlgProc1(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK DlgProc2(HWND, UINT, WPARAM, LPARAM);
HINSTANCE hInst;


int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
    DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), 0, (DlgProc1), 0);
    return 0;
}

BOOL CALLBACK DlgProc1(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  
    switch (uMsg) 
    {
    case WM_INITDIALOG: 
        hInst = GetModuleHandle(NULL);
        hEdit1 = GetDlgItem(hwnd, IDC_EDITONE);
      // 
        break;
    case WM_COMMAND:
        switch (LOWORD(wParam)) 
    {
    case ID_MODAL: {
     
        DialogBoxParam(hInst, MAKEINTRESOURCE(IDD_DIALOG2), hwnd, DlgProc2, 0);
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
    switch (uMsg) 
    {
    case WM_INITDIALOG: 
        hEdit2 = GetDlgItem(hwnd, IDC_EDIT2);
        SetFocus(hEdit2);
      

        break;
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDOK: {
              SendMessage(hEdit2, WM_GETTEXT, (WPARAM)255, (LPARAM)first);
              wsprintf(boofer, L"%s", first);
              SendMessage(hEdit1, WM_SETTEXT, 0, (LPARAM)boofer);
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