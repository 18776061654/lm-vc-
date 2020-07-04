
// 综合实验Set.cpp : C综合实验Set 类的实现
//

#include "stdafx.h"
#include "综合实验.h"
#include "综合实验Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C综合实验Set 实现

// code generated on 2020年7月4日, 17:15

IMPLEMENT_DYNAMIC(C综合实验Set, CRecordset)

C综合实验Set::C综合实验Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = L"";
	m_2 = L"";
	m_3 = L"";
	m_4 = L"";
	m_5 = L"";
	m_6 = L"";
	m_7 = L"";
	m_8 = L"";
	m_nFields = 9;
	m_nDefaultType = snapshot;
}
//#error Security Issue: The connection string may contain a password
// The connection string below may contain plain text passwords and/or
// other sensitive information. Please remove the #error after reviewing
// the connection string for any security related issues. You may want to
// store the password in some other form or use a different user authentication.
CString C综合实验Set::GetDefaultConnect()
{
	return _T("DSN=\x6570\x636e\x6e90_\x5b66\x751f\x4fe1\x606f\x8868;DBQ=D:\\\x684c\x9762\\\x6570\x636e\x5e93.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString C综合实验Set::GetDefaultSQL()
{
	return _T("[学生信息表]");
}

void C综合实验Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// Macros such as RFX_Text() and RFX_Int() are dependent on the
// type of the member variable, not the type of the field in the database.
// ODBC will try to automatically convert the column value to the requested type
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[字段1]"), m_1);
	RFX_Text(pFX, _T("[字段2]"), m_2);
	RFX_Text(pFX, _T("[字段3]"), m_3);
	RFX_Text(pFX, _T("[字段4]"), m_4);
	RFX_Text(pFX, _T("[字段5]"), m_5);
	RFX_Text(pFX, _T("[字段6]"), m_6);
	RFX_Text(pFX, _T("[字段7]"), m_7);
	RFX_Text(pFX, _T("[字段8]"), m_8);

}
/////////////////////////////////////////////////////////////////////////////
// C综合实验Set diagnostics

#ifdef _DEBUG
void C综合实验Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void C综合实验Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

