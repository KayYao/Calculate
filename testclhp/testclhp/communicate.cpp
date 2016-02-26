#include "communicate.h"

Communicate::Communicate(const wxString& title): wxFrame(NULL, wxID_ANY, title, wxDefaultPosition,wxSize(250,425),wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER)
{
	SetIcon(wxIcon(wxT("mondrian")));

	//=== add the menu=======
	menubar = new wxMenuBar;

	file =new wxMenu;
	file->Append(ID_STANDER,_T("&標準型\tAlt+1"));
	file->Append(ID_ENGINEER,_T("&工程型\tAlt+2"));
	file->AppendSeparator();
	// submeun
	imp =new wxMenu;
	imp->Append(wxID_ANY,_T("租賃(M)\tshift+m"));
	imp->Append(wxID_ANY,_T("貸款(V)\tshift+v"));
	file->AppendSubMenu(imp,_T("&工作(W)\tshift+w"));
	file->Append(wxID_EXIT,_T("&退出\tAlt+F4"));


	file2= new wxMenu;
	file2->Append(wxID_ANY,_T("&複製\tCtrl+C"));
	file2->Append(wxID_ANY,_T("&貼上\tCtrl+V"));

	file3= new wxMenu;
	file3->Append(wxID_HELP,_T("&檢視說明\tF1"),_T(""));
	file3->Append(wxID_ABOUT,_T("關於小算盤"));


	menubar->Append(file,_T("&檢視"));
	menubar->Append(file2,_T("&編輯"));
	menubar->Append(file3,_T("&說明"));
	
	SetMenuBar(menubar);
	//============================================================================
	//hbox = new wxBoxSizer(wxHORIZONTAL);
	hbox = new wxBoxSizer(wxVERTICAL);
    m_parent = new wxPanel(this, wxID_ANY);

    m_call = new Calculate(m_parent);
    hbox->Add(m_call,1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);

    m_parent->SetSizer(hbox);
    this->Center();
}

BEGIN_EVENT_TABLE(Communicate, wxFrame)
	EVT_MENU(wxID_HELP,    Communicate::OnHelp)
	EVT_MENU(wxID_ABOUT,   Communicate::OnAbout)
	EVT_MENU(wxID_EXIT,    Communicate::OnExit)
	EVT_MENU(ID_ENGINEER,  Communicate::OnEngineer)
	EVT_MENU(ID_STANDER,  Communicate::OnStander)
END_EVENT_TABLE()


int Communicate::scount=1;
int Communicate::ecount=1;

void Communicate::OnHelp(wxCommandEvent & event){
	wxString msg=_T("你需要我的幫忙嗎 ?");
	wxMessageBox(msg,_T("小算盤說明"),wxYES_NO |wxICON_QUESTION, this);
}
void Communicate::OnAbout(wxCommandEvent & event){
	wxString msg;
	msg.Printf(_T("企業版，版本為 %s"),wxVERSION_STRING);
	wxMessageBox(msg,_T("小算盤關於"),wxOK | wxICON_INFORMATION, this);
}

void Communicate::OnExit(wxCommandEvent & event){
	Close();
}

void Communicate::OnEngineer(wxCommandEvent & event){
	Engineer();
}

void Communicate::OnStander(wxCommandEvent & event){
	Stander();
}