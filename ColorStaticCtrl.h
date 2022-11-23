#pragma once


// ColorStaticCtrl

class ColorStaticCtrl : public CStatic
{
	DECLARE_DYNAMIC(ColorStaticCtrl)

public:
	ColorStaticCtrl();
	virtual ~ColorStaticCtrl();

	int red, green, blue;
	CPoint point;

	void reDraw();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};


