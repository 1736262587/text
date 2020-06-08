
// PicBrSet.cpp : CPicBrSet ���ʵ��
//

#include "stdafx.h"
#include "PicBr.h"
#include "PicBrSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPicBrSet ʵ��

// ���������� 2020��5��12��, 21:02

IMPLEMENT_DYNAMIC(CPicBrSet, CRecordset)

CPicBrSet::CPicBrSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = L"";
	m_nFields = 2;
	m_nDefaultType = snapshot;
}
//#error ��ȫ���⣺�����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CPicBrSet::GetDefaultConnect()
{
	return _T("DSN=\x6570\x636e\x6e90_\x5b66\x751f\x4fe1\x606f\x8868;DBQ=D:\\VC++\x5b9e\x9a8c\\\x7b2c\x5341\x4e8c\x6b21\x5b9e\x9a8c\\Database21.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CPicBrSet::GetDefaultSQL()
{
	return _T("[ͼƬ��Ϣ��]");
}

void CPicBrSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[�ֶ�1]"), m_1);

}
/////////////////////////////////////////////////////////////////////////////
// CPicBrSet ���

#ifdef _DEBUG
void CPicBrSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CPicBrSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

