
// PicBrDoc.h : CPicBrDoc ��Ľӿ�
//


#pragma once
#include "PicBrSet.h"


class CPicBrDoc : public CDocument
{
protected: // �������л�����
	CPicBrDoc();
	DECLARE_DYNCREATE(CPicBrDoc)

// ����
public:
	CPicBrSet m_PicBrSet;

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CPicBrDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
