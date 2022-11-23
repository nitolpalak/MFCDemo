#pragma once


// ColorStaticSliderCtrl

class ColorStaticSliderCtrl : public CStatic
{
	DECLARE_DYNAMIC(ColorStaticSliderCtrl)

public:
	ColorStaticSliderCtrl();
	virtual ~ColorStaticSliderCtrl();

	int red{ 255 }, green{ 0 }, blue{ 0 };

	void reDraw();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};


