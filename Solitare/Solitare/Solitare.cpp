// Solitare.cpp : Defines the entry point for the application.

#include <windows.h>
#include <windowsx.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "stdafx.h"
#include "Solitare.h"
#include "Canvas.h"
#include "Card.h"
#include "BackBuffer.h"
#include "Stack.h"
#include "Queue.h"
using namespace std;

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name


//-----My Defined Variables
CCanvas*	GlobalCanvasPointer = nullptr;
Card*		GlobalCardPointer	= nullptr;
Card*		CardArray[52];
Card*		CardToCheck			= nullptr;
RECT rect;

	//Stacks;
Stack*		GlobalStackPointer	= nullptr;
Stack*		StackArray[11];
int CardsInFront = 0;

	//Queues
Queue*		GlobalQueuePointer	= nullptr;
Queue*		Queue1Pointer		= nullptr;
Queue*		Queue2Pointer		= nullptr;

//-----Card Dimensions
int const CardWidth = 140;
int const CardHeight = 195;

int		MousePositionX;
int		MousePositionY;
bool	PickingUp = false;
bool	MoveBack = false;

//Main Game Loop Where Draw Gets Called
void GameLoop()
{
	if (GlobalCanvasPointer != nullptr)
	{
		if (MoveBack && !PickingUp)
		{
			MoveBack = false;

			if ((GlobalCardPointer->GetLastPositionX() - GlobalCardPointer->GetStartX() > 10 || GlobalCardPointer->GetLastPositionX() - GlobalCardPointer->GetStartX() < -10))	//if X is not within 10 pixels of its last position
			{
				MoveBack = true;
				GlobalCardPointer->SetStartX(GlobalCardPointer->GetStartX() + (GlobalCardPointer->GetLastPositionX() - GlobalCardPointer->GetStartX()) / 10);						//Move Back To it
			}
			else GlobalCardPointer->SetStartX(GlobalCardPointer->GetLastPositionX());																								//If you're really close, move to it

			if ((GlobalCardPointer->GetLastPositionY() - GlobalCardPointer->GetStartY() > 10 || GlobalCardPointer->GetLastPositionY() - GlobalCardPointer->GetStartY() < -10))	//Same For y
			{
				MoveBack = true;
				GlobalCardPointer->SetStartY(GlobalCardPointer->GetStartY() + (GlobalCardPointer->GetLastPositionY() - GlobalCardPointer->GetStartY()) / 10);
			}
			else GlobalCardPointer->SetStartY(GlobalCardPointer->GetLastPositionY());
				
		}

		GlobalCanvasPointer->Draw();
	}
}

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_SOLITARE, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SOLITARE));

    MSG msg;

    //// Main message loop:
    //while (GetMessage(&msg, nullptr, 0, 0))
    //{
    //    if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
    //    {
    //        TranslateMessage(&msg);
    //        DispatchMessage(&msg);
    //    }
    //}

	// Enter main event loop
	while (true)
	{
		// Test if there is a message in queue, if so get it.
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			// Test if this is a quit.
			if (msg.message == WM_QUIT)
			{
				break;
			}

			// Translate any accelerator keys.
			TranslateMessage(&msg);
			// Send the message to the window proc.
			DispatchMessage(&msg);
		}
		GameLoop();
	}

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SOLITARE));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_SOLITARE);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, 1600, 900, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
	case WM_CREATE:
	{
		//Initialize random seed
		srand((unsigned int)time(NULL));

		//-----Initialization of canvas
		GlobalCanvasPointer = new CCanvas();
		GetClientRect(hWnd, &rect);
		GlobalCanvasPointer->Initialise(hWnd, 1200, 1000);

		//-----Initialization of Stacks


		for (int StackNumber = 1; StackNumber < 12; StackNumber++)
		{
			if (StackNumber < 8)
			{
				StackArray[StackNumber - 1] = new Stack(170 * StackNumber, 250, false);
				Card* BlankCard = new Card(0, 0, 170 * StackNumber, 250, false, true);
				GlobalCanvasPointer->AddCard(BlankCard);
			}
			else
			{
				StackArray[StackNumber - 1] = new Stack(550 + 145 * (StackNumber - 7), 25, true);
				Card* BlankCard = new Card(0, 0, 550 + 145 * (StackNumber - 7), 25, false, true);
				GlobalCanvasPointer->AddCard(BlankCard);
			}
		}

		//Initialization of Queues
		Queue1Pointer = new Queue(125, 25, false);
		Queue2Pointer = new Queue(275, 25, true);

		//-----Initializing Cards
		for (int Suit = 0; Suit < 52; Suit += 13)
		{

			for (int Value = 0; Value < 13; Value++)
			{
				GlobalCardPointer = new Card(Suit/13, Value, 500, 500, false, false);
				CardArray[Suit + Value] = GlobalCardPointer;
			}

		}

		for (int Cards = 0; Cards < 52; Cards++)
		{
			int CardToPick;
			CardToPick = rand() % 52;
			
			while (CardArray[CardToPick] == nullptr)
			{
				CardToPick = rand() % 52;
			}

			GlobalCanvasPointer->AddCard(CardArray[CardToPick]);
			Queue1Pointer->Enqueue(CardArray[CardToPick]);
			CardArray[CardToPick] = nullptr;
			//Move appropriate number of cards to the seven stacks
		}
		
		for (int StackSize = 1; StackSize < 8; StackSize++)
		{
			for (int CardsToPlace = StackSize ; CardsToPlace > 0; CardsToPlace--)
			{
				Card* CardToMove = Queue1Pointer->Dequeue();
				StackArray[StackSize-1]->Push(CardToMove);
				if (CardsToPlace == 1)	CardToMove->SetFaceUp(true);
				else					CardToMove->SetFaceUp(false);
			}
		}

		return 0;
	}
	case WM_LBUTTONDOWN:
	{
		MousePositionX = static_cast<int>(LOWORD(lParam));			// find the pointer location
		MousePositionY = static_cast<int>(HIWORD(lParam));
		GlobalCardPointer = nullptr;

		//----------For Clicking On Stacks
		for (int StackPosition = 1; StackPosition < 8; StackPosition++)
		{
			if (MousePositionX > 170 * StackPosition && MousePositionX < 170 * StackPosition + 140 && MousePositionY > 250 && MousePositionY < 250 + StackArray[StackPosition-1]->GetLength() * 195)
			{
				GlobalStackPointer = StackArray[StackPosition - 1];
				CardToCheck = GlobalStackPointer->Peek();
				CardsInFront = 0;

				while (GlobalCardPointer == nullptr)
				{
					if (CardToCheck->GetPreviousCard() == nullptr && MousePositionY > CardToCheck->GetStartY() && MousePositionY < CardToCheck->GetEndY())
					{
						GlobalCardPointer = CardToCheck;
						break;
					}
					else if (CardToCheck->GetFaceUp() && MousePositionY > CardToCheck->GetStartY() && MousePositionY < CardToCheck->GetStartY() + 35)
					{
						GlobalCardPointer = CardToCheck;
						break;
					}
					

					CardsInFront++;
					if (CardToCheck->GetNextCard() != nullptr) CardToCheck = CardToCheck->GetNextCard();
					else
					{
						CardsInFront = 0;
						break;
					}
				}

				break;
			}
		}



		//----------For Clicking on Queues
		//Queue 1 (Deck)
		if (MousePositionX > Queue1Pointer->GetQueueXPosition() && MousePositionX < Queue1Pointer->GetQueueXPosition() + 140 && MousePositionY > Queue1Pointer->GetQueueYPosition() && MousePositionY < Queue1Pointer->GetQueueYPosition() + 195)
		{
			Card* CardToMove;
			if (Queue2Pointer->Peek() != nullptr)
			{
				CardToMove = Queue2Pointer->Dequeue();
				Queue1Pointer->Enqueue(CardToMove);

//				CardToMove = Queue2Pointer->Dequeue();
//				Queue1Pointer->Enqueue(CardToMove);

//				CardToMove = Queue2Pointer->Dequeue();
//				Queue1Pointer->Enqueue(CardToMove);

			}
			
			if (Queue2Pointer->Peek() == nullptr)
			{
				CardToMove = Queue1Pointer->Dequeue();
				Queue2Pointer->Enqueue(CardToMove);

//				CardToMove = Queue1Pointer->Dequeue();
//				Queue2Pointer->Enqueue(CardToMove);

//				CardToMove = Queue1Pointer->Dequeue();
//				Queue2Pointer->Enqueue(CardToMove);
			}
			GlobalCardPointer = nullptr;
		}

		//Queue 2
		if (MousePositionX > Queue2Pointer->GetQueueXPosition() && MousePositionX < Queue2Pointer->GetQueueXPosition() + 140 && MousePositionY > Queue2Pointer->GetQueueYPosition() && MousePositionY < Queue2Pointer->GetQueueYPosition() + 195)
		{
			if (Queue2Pointer->Peek() != nullptr)
			{
				GlobalCardPointer = Queue2Pointer->Peek();
				GlobalQueuePointer = Queue2Pointer;
			}
		}

		if (GlobalCardPointer != nullptr)
		{
				PickingUp = true;
				GlobalCardPointer->SetPickUpWidth(MousePositionX - GlobalCardPointer->GetStartX());
				GlobalCardPointer->SetPickUpHeight(MousePositionY - GlobalCardPointer->GetStartY());
		}
		break;
	}
	case WM_LBUTTONUP:
	{
		if (PickingUp)
		{
			PickingUp = false;
			GlobalCardPointer->SetPickUpWidth(0);
			GlobalCardPointer->SetPickUpHeight(0);


			//-----For Checking Card Position

			Stack* StackToCheck = nullptr;

			for (int StackPosition = 1; StackPosition < 8; StackPosition++)
			{
				if (MousePositionX > 170 * StackPosition && MousePositionX < 170 * StackPosition + 140 && MousePositionY > 250 + StackArray[StackPosition - 1]->GetLength() * 35 - 195 && MousePositionY < 250 + StackArray[StackPosition - 1]->GetLength() * 195)
				{
					StackToCheck = StackArray[StackPosition - 1];
					break;
				}
				else if (MousePositionX > 170 * StackPosition && MousePositionX < 170 * StackPosition + 140 && MousePositionY > 250 && MousePositionY < 250 + 195)
				{
					StackToCheck = StackArray[StackPosition - 1];
					break;
				}
			}

			for (int FinalStackPosition = 1; FinalStackPosition < 5; FinalStackPosition++)
			{
				if (MousePositionX > 550 + 145 * (FinalStackPosition - 1) && MousePositionX < 550 + 145 * (FinalStackPosition - 1) + 140 && MousePositionY > 25 && MousePositionY < 25 + 195)
				{
					StackToCheck = StackArray[FinalStackPosition + 5];
					break;
				}
			}
		
			if (StackToCheck != nullptr && StackToCheck->GetNextValidColour() == GlobalCardPointer->GetColour() && (StackToCheck->GetNextValidValue() == GlobalCardPointer->GetValue() || StackToCheck->GetNextValidValue() == ANY))
			{
				for (int Popping = 0; Popping <= CardsInFront; Popping++)
				{
					if(GlobalStackPointer != nullptr) CardArray[Popping] = GlobalStackPointer->Pop();
					else if (GlobalQueuePointer != nullptr) CardArray[Popping] = GlobalQueuePointer->Dequeue();
				}
				
				for (int Pushing = CardsInFront; Pushing >= 0; Pushing--)
				{
					if (GlobalStackPointer != nullptr) StackToCheck->Push(CardArray[Pushing]);
					else if (GlobalQueuePointer != nullptr)
					{
						StackToCheck->Push(CardArray[Pushing]);
						GlobalQueuePointer = nullptr;
						break;
					}
					 
				}
				GlobalStackPointer = nullptr;
			}
			else if (StackToCheck != nullptr  && StackToCheck->GetNextValidValue() == GlobalCardPointer->GetValue())
			{
				for (int Popping = 0; Popping <= CardsInFront; Popping++)
				{
					if (GlobalStackPointer != nullptr) CardArray[Popping] = GlobalStackPointer->Pop();
					else if (GlobalQueuePointer != nullptr) CardArray[Popping] = GlobalQueuePointer->Dequeue();
				}

				for (int Pushing = CardsInFront; Pushing >= 0; Pushing--)
				{
					if (GlobalStackPointer != nullptr) StackToCheck->Push(CardArray[Pushing]);
					else if (GlobalQueuePointer != nullptr)
					{
						StackToCheck->Push(CardArray[Pushing]);
						GlobalQueuePointer = nullptr;
						break;
					}

				}
				GlobalStackPointer = nullptr;
			}


			if (GlobalCardPointer->GetStartX() != GlobalCardPointer->GetLastPositionX() && GlobalCardPointer->GetStartY() != GlobalCardPointer->GetLastPositionY())
			{
				GlobalCardPointer->SetStartX(GlobalCardPointer->GetLastPositionX());
				GlobalCardPointer->SetStartY(GlobalCardPointer->GetLastPositionY());
			}
		}
		break;
	}
	case WM_RBUTTONDOWN:
	{
		break;
	}
	case WM_MOUSEMOVE:
	{
		MousePositionX = static_cast<int>(LOWORD(lParam));			// find the pointer location
		MousePositionY = static_cast<int>(HIWORD(lParam));

		if (PickingUp)
		{	
			GlobalCardPointer->SetStartX(MousePositionX - GlobalCardPointer->GetPickUpWidth());
			GlobalCardPointer->SetStartY(MousePositionY - GlobalCardPointer->GetPickUpHeight());

			if (GlobalCardPointer->GetPreviousCard() != nullptr && CardsInFront > 0)
			{
				CardToCheck = GlobalCardPointer->GetPreviousCard();
					for (int Mover = 0; Mover < CardsInFront; Mover++)
					{

						CardToCheck->SetStartX(MousePositionX - GlobalCardPointer->GetPickUpWidth());
						CardToCheck->SetStartY(MousePositionY - GlobalCardPointer->GetPickUpHeight() + 35 * (Mover + 1));

						if (CardToCheck->GetPreviousCard() != nullptr) CardToCheck = CardToCheck->GetPreviousCard();
						else break;
					}
			}
			
		}
	}
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
		for (int i = 0; i < 11; i++)
		{
			delete StackArray[i];
		}
		delete GlobalCanvasPointer;
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
