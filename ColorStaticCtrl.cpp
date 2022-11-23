// ColorStaticCtrl.cpp : implementation file
//

#include "pch.h"
#include "DemoMFCApp.h"
#include "ColorStaticCtrl.h"


// ColorStaticCtrl

IMPLEMENT_DYNAMIC(ColorStaticCtrl, CStatic)

ColorStaticCtrl::ColorStaticCtrl()
{

}

ColorStaticCtrl::~ColorStaticCtrl()
{
}

void ColorStaticCtrl::reDraw()
{
	Invalidate();
	UpdateWindow();
}


BEGIN_MESSAGE_MAP(ColorStaticCtrl, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// ColorStaticCtrl message handlers




void ColorStaticCtrl::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CStatic::OnPaint() for painting messages
	CRect rectWindow;
	GetClientRect(&rectWindow);

	CRgn clipRgn;
	if (clipRgn.CreateRectRgnIndirect(&rectWindow))
		dc.SelectClipRgn(&clipRgn);

	auto color{ RGB(red, green, blue) };

	CBrush brush(color);

	dc.FillRect(&rectWindow, &brush);
	dc.LineTo(500, 50);

	auto oldBkColor{ dc.SetBkColor(color) };
	CString strPoint;
	strPoint.Format(_T("x: %d"), point.x);
	dc.TextOutW(10, 10, strPoint);

	strPoint.Format(_T("y: %d"), point.y);
	dc.TextOutW(10, 40, strPoint);

	dc.SelectClipRgn(NULL);
}
