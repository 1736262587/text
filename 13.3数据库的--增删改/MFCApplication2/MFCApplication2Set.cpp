
// MFCApplication2Set.cpp : CMFCApplication2Set ���ʵ��
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "MFCApplication2Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication2Set ʵ��

// ���������� 2020��5��19��, 20:26

IMPLEMENT_DYNAMIC(CMFCApplication2Set, CRecordset)

CMFCApplication2Set::CMFCApplication2Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = 0;
	m_nFields = 2;
	m_nDefaultType = dynaset;
}
//#error ��ȫ���⣺�����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CMFCApplication2Set::GetDefaultConnect()
{
	return _T("DSN=\x6570\x636e\x6e90_\x6570\x5b57;DBQ=D:\\VC++\x5b9e\x9a8c\\\x7b2c\x5341\x4e09\x6b21\x5b9e\x9a8c\\Database2.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CMFCApplication2Set::GetDefaultSQL()
{
	return _T("[�ۺ�ʵ��֮��]");
}

void CMFCApplication2Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Long(pFX, _T("[�ֶ�1]"), m_1);

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

