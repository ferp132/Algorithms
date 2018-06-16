/***********************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand

(c) 2018 Media Design School

File Name   :   [Filename]
Description :   [One line description of what is the file is for]
Author      :   [Your name]
Mail        :   [your.name]@mediadesign.school.nz
********************/

#ifndef __CANVAS_H__
#define __CANVAS_H__

//	Library Includes
#include <windows.h>
#include <windowsx.h>
#include <vector>




class Card; //Forward Declaration
class CBackBuffer;

class CCanvas
{
public:
	CCanvas();
	~CCanvas();
	bool Initialise(HWND _hwnd, int _iWidth, int _iHeight);
	CBackBuffer* GetBackBuffer();
	bool Draw();
	void Save(HWND _hwnd);
	void AddCard(Card*);
//	void AddStamp(CStamp*);

private:
	CBackBuffer* m_pBackBuffer; // A canvas has a backbuffer.
//	std::vector<CStamp*> m_vecStamps;
	std::vector<Card*> m_shapes;
	HWND hwnd;
};

#endif