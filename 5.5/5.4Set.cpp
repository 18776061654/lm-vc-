
// 5.4Set.cpp : CMy54Set ���ʵ��
//

#include "stdafx.h"
#include "5.4.h"
#include "5.4Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy54Set ʵ��

// code generated on 2020��7��3��, 13:45

IMPLEMENT_DYNAMIC(CMy54Set, CRecordset)

CMy54Set::CMy54Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = L"";
	m_2 = L"";
	m_3 = L"";
	m_nFields = 4;
	m_nDefaultType = snapshot;
}
//#error Security Issue: The connection string may contain a password
// The connection string below may contain plain text passwords and/or
// other sensitive information. Please remove the #error after reviewing
// the connection string for any security related issues. You may want to
// store the password in some other form or use a different user authentication.
CString CMy54Set::GetDefaultConnect()
{
	return _T("DSN=\x6570\x636e\x6e90_\x5b66\x751f\x4fe1\x606f\x8868;DBQ=D:\\\x684c\x9762\\\x6570\x636e\x5e93.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CMy54Set::GetDefaultSQL()
{
	return _T("[ѧ����Ϣ��]");
}

void CMy54Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// Macros such as RFX_Text() and RFX_Int() are dependent on the
// type of the member variable, not the type of the field in the database.
// ODBC will try to automatically convert the column value to the requested type
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[�ֶ�1]"), m_1);
	RFX_Text(pFX, _T("[�ֶ�2]"), m_2);
	RFX_Text(pFX, _T("[�ֶ�3]"), m_3);

}
/////////////////////////////////////////////////////////////////////////////
// CMy54Set diagnostics

#ifdef _DEBUG
void CMy54Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMy54Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

