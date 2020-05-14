
// DB2018Set.cpp : CDB2018Set ���ʵ��
//

#include "stdafx.h"
#include "DB2018.h"
#include "DB2018Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDB2018Set ʵ��

// ���������� 2020��5��12��, 20:29

IMPLEMENT_DYNAMIC(CDB2018Set, CRecordset)

CDB2018Set::CDB2018Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = L"";
	m_2 = L"";
	m_3 = L"";
	m_4 = L"";
	m_nFields = 5;
	m_nDefaultType = snapshot;
}
//#error ��ȫ���⣺�����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CDB2018Set::GetDefaultConnect()
{
	return _T("DSN=\x6570\x636e\x6e90_\x5b66\x751f\x4fe1\x606f\x8868;DBQ=D:\\VC++\x5b9e\x9a8c\\\x7b2c\x5341\x4e00\x6b21\x5b9e\x9a8c\\Database4.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CDB2018Set::GetDefaultSQL()
{
	return _T("[ѧ����Ϣ��]");
}

void CDB2018Set::DoFieldExchange(CFieldExchange* pFX)
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

}
/////////////////////////////////////////////////////////////////////////////
// CDB2018Set ���

#ifdef _DEBUG
void CDB2018Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CDB2018Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

