
// MFCApplication2Set.cpp : CMFCApplication2Set ���ʵ��
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "MFCApplication2Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication2Set ʵ��

// ���������� 2020��5��23��, 11:33

IMPLEMENT_DYNAMIC(CMFCApplication2Set, CRecordset)

CMFCApplication2Set::CMFCApplication2Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = L"";
	m_2 = L"";
	m_3 = L"";
	m_4 = L"";
	m_5 = L"";
	m_nFields = 6;
	m_nDefaultType = snapshot;
}
//#error ��ȫ���⣺�����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CMFCApplication2Set::GetDefaultConnect()
{
	return _T("DSN=\x6570\x636e\x6e90_\x5305\x542b\x76f8\x7247\x5168\x8def\x5f84\x7684\x5b66\x751f\x4fe1\x606f;DBQ=D:\\VC++\x5b9e\x9a8c\\\x7b2c\x5341\x4e00\x6b21\x5b9e\x9a8c\\11.1\x5efa\x7acb\x5b66\x751f\x4fe1\x606f\x6570\x636e\x5e93\x6587\x4ef6\\database5.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CMFCApplication2Set::GetDefaultSQL()
{
	return _T("[ѧ����Ϣ��]");
}

void CMFCApplication2Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[�ֶ�1]"), m_1);
	RFX_Text(pFX, _T("[�ֶ�2]"), m_2);
	RFX_Text(pFX, _T("[�ֶ�3]"), m_3);
	RFX_Text(pFX, _T("[�ֶ�4]"), m_4);
	RFX_Text(pFX, _T("[�ֶ�5]"), m_5);

}
/////////////////////////////////////////////////////////////////////////////
// CMFCApplication2Set ���

#ifdef _DEBUG
void CMFCApplication2Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFCApplication2Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

