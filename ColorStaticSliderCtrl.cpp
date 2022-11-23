// ColorStaticSliderCtrl.cpp : implementation file
//

#include "pch.h"
#include "DemoMFCApp.h"
#include "ColorStaticSliderCtrl.h"


// ColorStaticSliderCtrl

IMPLEMENT_DYNAMIC(ColorStaticSliderCtrl, CStatic)

ColorStaticSliderCtrl::ColorStaticSliderCtrl()
{

}

ColorStaticSliderCtrl::~ColorStaticSliderCtrl()
{
}

void ColorStaticSliderCtrl::reDraw()
{
	Invalidate();
	UpdateWindow();
}


BEGIN_MESSAGE_MAP(ColorStaticSliderCtrl, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// ColorStaticSliderCtrl message handlers




void ColorStaticSliderCtrl::OnPaint()
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

	CString outputText;
	outputText.Format(_T("RGB: %d, %d, %d"), red, green, blue);
	dc.TextOutW(10, 10, outputText);

	dc.SelectClipRgn(NULL);
}
