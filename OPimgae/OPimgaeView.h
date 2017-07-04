
// OPimgaeView.h : COPimgaeView 클래스의 인터페이스
//

#pragma once


class COPimgaeView : public CScrollView
{
protected: // serialization에서만 만들어집니다.
	COPimgaeView();
	DECLARE_DYNCREATE(COPimgaeView)

// 특성입니다.
public:
	int m_nMagnify;
	COPimgaeDoc* GetDocument() const;
	void ResizeView();

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~COPimgaeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSizeOriginalsize();
	afx_msg void OnSizeZoomsize();
	afx_msg void OnSizeZoomoutsize();
	afx_msg void OnBnClickedOk();
};

#ifndef _DEBUG  // OPimgaeView.cpp의 디버그 버전
inline COPimgaeDoc* COPimgaeView::GetDocument() const
   { return reinterpret_cast<COPimgaeDoc*>(m_pDocument); }
#endif

