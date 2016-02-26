#include "calculate.h"
#include "mondrian.xpm"
#include <wx/gbsizer.h>
#include <wx/stattext.h>
#include <wx/msgdlg.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/msgdlg.h>
#include <wx/radiobut.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/dialog.h>

Calculate::Calculate(wxPanel * parent): wxPanel(parent, wxID_ANY, wxDefaultPosition,wxDefaultSize,wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER)
{

	sizer1= new wxBoxSizer(wxVERTICAL);
	sizer2= new wxBoxSizer(wxHORIZONTAL);

	display = new wxTextCtrl(this, wxID_ANY, _("0"), wxDefaultPosition, wxSize(-1,30), wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator);
	 wxFont displayFont(14,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    display->SetFont(displayFont);
	sizer2->Add(display, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    sizer1->Add(sizer2, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	
	stbox= new wxStaticBoxSizer(wxHORIZONTAL, this,_T("Options"));
	rdoDec=new wxRadioButton(this,ID_Dec,_T("Dec"));
	rdoDec->SetValue(true);
	stbox->Add(rdoDec,1,wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	rdoHex=new wxRadioButton(this,ID_Hex,_T("Hex"));
	stbox->Add(rdoHex,1,wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	rdoOct=new wxRadioButton(this,ID_Oct,_T("Oct"));
	stbox->Add(rdoOct,1,wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	sizer1->Add(stbox,0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	
	plControlPanel = new wxPanel(this, ID_CONTROLPANEL, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);

	sizer3 = new wxBoxSizer(wxHORIZONTAL);
	gbs=new wxGridBagSizer(0,0);
	gs=new wxGridSizer(0,3,0,0);
	
	gs->Add(new wxButton(plControlPanel,ID_CLEARC, _T("C"),wxDefaultPosition, wxSize(45,45),0, wxDefaultValidator),1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	gs->Add(new wxButton(plControlPanel,ID_DIVID,  _T("/"),wxDefaultPosition, wxSize(45,45),0, wxDefaultValidator),1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	gs->Add(new wxButton(plControlPanel,ID_MULTI,  _T("*"),wxDefaultPosition, wxSize(45,45),0, wxDefaultValidator),1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	gs->Add(new wxButton(plControlPanel,ID_SEVEN,  _T("7"),wxDefaultPosition, wxSize(45,45),0, wxDefaultValidator),1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	gs->Add(new wxButton(plControlPanel,ID_EIGHT,  _T("8"),wxDefaultPosition, wxSize(45,45),0, wxDefaultValidator),1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	gs->Add(new wxButton(plControlPanel,ID_NIGHT,  _T("9"),wxDefaultPosition, wxSize(45,45),0, wxDefaultValidator),1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	gs->Add(new wxButton(plControlPanel,ID_FOUR,   _T("4"),wxDefaultPosition, wxSize(45,45),0, wxDefaultValidator),1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	gs->Add(new wxButton(plControlPanel,ID_FIVE,   _T("5"),wxDefaultPosition, wxSize(45,45),0, wxDefaultValidator),1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	gs->Add(new wxButton(plControlPanel,ID_SIX,    _T("6"),wxDefaultPosition, wxSize(45,45),0, wxDefaultValidator),1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	gs->Add(new wxButton(plControlPanel,ID_ONE,    _T("1"),wxDefaultPosition, wxSize(45,45),0, wxDefaultValidator),1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	gs->Add(new wxButton(plControlPanel,ID_TWO,    _T("2"),wxDefaultPosition, wxSize(45,45),0, wxDefaultValidator),1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	gs->Add(new wxButton(plControlPanel,ID_THREE,  _T("3"),wxDefaultPosition, wxSize(45,45),0, wxDefaultValidator),1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	gbs->Add(gs, wxGBPosition(0, 0), wxDefaultSpan, wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	
	sizer5 = new wxBoxSizer(wxHORIZONTAL);
	sizer5->Add(new wxButton(plControlPanel,ID_ZERO,   _T("0"),wxDefaultPosition, wxSize(94,45),0, wxDefaultValidator),0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	sizer5->Add(new wxButton(plControlPanel,ID_DOT,    _T("."),wxDefaultPosition, wxSize(45,45),0, wxDefaultValidator),0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	gbs->Add(sizer5, wxGBPosition(1, 0), wxDefaultSpan, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	sizer3->Add(gbs, 0,wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	
    sizer4 = new wxBoxSizer(wxVERTICAL);
	sizer4->Add(new wxButton(plControlPanel,ID_MINUS,   _T("-"),wxDefaultPosition, wxSize(45,45),0, wxDefaultValidator),0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	sizer4->Add(new wxButton(plControlPanel,ID_PLUS,    _T("+"),wxDefaultPosition, wxSize(45,94),0, wxDefaultValidator),0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	sizer4->Add(new wxButton(plControlPanel,ID_EQUAL,   _T("="),wxDefaultPosition, wxSize(45,94),0, wxDefaultValidator),0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    sizer3->Add(sizer4, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	
	plControlPanel->SetSizer(sizer3);
	sizer3->Fit(plControlPanel);
    sizer3->SetSizeHints(plControlPanel);
    sizer1->Add(plControlPanel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);

	// Important ,this order can't change.
	SetSizer(sizer1); //use the sizer for layout
	sizer1->Fit(this); //fit the sizer to the content
    sizer1->SetSizeHints(this); //set hintd to honor min size

	Connect(ID_Dec,     wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&Calculate::OnrdoDecSelect);
    Connect(ID_Hex,     wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&Calculate::OnrdoHexSelect);
    Connect(ID_Oct,     wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&Calculate::OnrdoOctSelect);

	Connect(ID_CLEARC,  wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Calculate::OnClearc));
	Connect(ID_DIVID,   wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Calculate::OnDivid));
	Connect(ID_MULTI,   wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Calculate::OnMulti));

	Connect(ID_SEVEN,   wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Calculate::OnSeven));
	Connect(ID_EIGHT,   wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Calculate::OnEight));
	Connect(ID_NIGHT,   wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Calculate::OnNight));

	Connect(ID_FOUR,    wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Calculate::OnFour));
	Connect(ID_FIVE,    wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Calculate::OnFive));
	Connect(ID_SIX,     wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Calculate::OnSix));

	Connect(ID_ONE,     wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Calculate::OnOne));
	Connect(ID_TWO,     wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Calculate::OnTwo));
	Connect(ID_THREE,   wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Calculate::OnThree));

	Connect(ID_ZERO,    wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Calculate::OnZero));
	Connect(ID_DOT,     wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Calculate::OnDot));
	Connect(ID_MINUS,   wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Calculate::OnMinus));
	Connect(ID_PLUS,    wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Calculate::OnPlus));
	Connect(ID_EQUAL,   wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Calculate::OnEqual));

}
Calculate2::Calculate2( wxPanel * parent)
	:  wxPanel(parent, wxID_ANY, wxPoint(100,100),wxDefaultSize,wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER)
{
	sizer1 = new wxBoxSizer(wxVERTICAL);
	sizer2 = new wxBoxSizer(wxHORIZONTAL);
	sizer3 = new wxBoxSizer(wxHORIZONTAL);
	sizer4 = new wxBoxSizer(wxVERTICAL);
	sizer5 = new wxBoxSizer(wxVERTICAL);
	sizer6 = new wxBoxSizer(wxHORIZONTAL);

	display = new wxTextCtrl(this, wxID_ANY, _("0"), wxDefaultPosition, wxSize(-1,30), wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator);
	 wxFont displayFont(14,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    display->SetFont(displayFont);
	sizer2->Add(display, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    sizer1->Add(sizer2, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);

	plControlPanel = new wxPanel(this, ID_CONTROLPANEL, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);

	stbox= new wxStaticBoxSizer(wxVERTICAL,this,_T("Options"));
	rdoHex=new wxRadioButton(this,ID_Hex,_T("16進位"));
	
	stbox->Add(rdoHex,1,wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	rdoDec=new wxRadioButton(this,ID_Dec,_T("10進位"));
	rdoDec->SetValue(true);
	stbox->Add(rdoDec,1,wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	rdoOct=new wxRadioButton(this,ID_Oct,_T("8進位"));
	stbox->Add(rdoOct,1,wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	rdoBin=new wxRadioButton(this,ID_Bin,_T("2進位"));
	stbox->Add(rdoBin,1,wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	sizer5->Add(stbox,0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);

	stbox2= new wxStaticBoxSizer(wxVERTICAL,this,_T("Choices"));
	rdoQword=new wxRadioButton(this,ID_Qword,_T("Qword"));
	//rdoQword->SetValue(true);
	stbox2->Add(rdoQword,1,wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	rdoDec=new wxRadioButton(this,ID_Dword,_T("Dword"));
	stbox2->Add(rdoDec,1,wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	rdoDword=new wxRadioButton(this,ID_Word,_T("Word"));
	stbox2->Add(rdoDword,1,wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	rdoByte=new wxRadioButton(this,ID_Byte,_T("Byte"));
	stbox2->Add(rdoByte,1,wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	sizer5->Add(stbox2,0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	
	gbs=new wxGridBagSizer(0,0);
	gs=new wxGridSizer(0,4,0,0);
	
	gs->Add(new wxButton(plControlPanel,ID_A,      _T("A"),wxDefaultPosition, wxSize(45,45),0, wxDefaultValidator),1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	gs->Add(new wxButton(plControlPanel,ID_CLEARC, _T("c"),wxDefaultPosition, wxSize(45,45),0, wxDefaultValidator),1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	gs->Add(new wxButton(plControlPanel,ID_DIVID,  _T("/"),wxDefaultPosition, wxSize(45,45),0, wxDefaultValidator),1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	gs->Add(new wxButton(plControlPanel,ID_MULTI,  _T("*"),wxDefaultPosition, wxSize(45,45),0, wxDefaultValidator),1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);

	gs->Add(new wxButton(plControlPanel,ID_B,      _T("B"),wxDefaultPosition, wxSize(45,45),0, wxDefaultValidator),1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	gs->Add(new wxButton(plControlPanel,ID_SEVEN,  _T("7"),wxDefaultPosition, wxSize(45,45),0, wxDefaultValidator),1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	gs->Add(new wxButton(plControlPanel,ID_EIGHT,  _T("8"),wxDefaultPosition, wxSize(45,45),0, wxDefaultValidator),1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	gs->Add(new wxButton(plControlPanel,ID_NIGHT,  _T("9"),wxDefaultPosition, wxSize(45,45),0, wxDefaultValidator),1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);

	gs->Add(new wxButton(plControlPanel,ID_C,      _T("C"),wxDefaultPosition, wxSize(45,45),0, wxDefaultValidator),1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	gs->Add(new wxButton(plControlPanel,ID_FOUR,   _T("4"),wxDefaultPosition, wxSize(45,45),0, wxDefaultValidator),1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	gs->Add(new wxButton(plControlPanel,ID_FIVE,   _T("5"),wxDefaultPosition, wxSize(45,45),0, wxDefaultValidator),1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	gs->Add(new wxButton(plControlPanel,ID_SIX,    _T("6"),wxDefaultPosition, wxSize(45,45),0, wxDefaultValidator),1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);

	gs->Add(new wxButton(plControlPanel,ID_D,      _T("D"),wxDefaultPosition, wxSize(45,45),0, wxDefaultValidator),1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	gs->Add(new wxButton(plControlPanel,ID_ONE,    _T("1"),wxDefaultPosition, wxSize(45,45),0, wxDefaultValidator),1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	gs->Add(new wxButton(plControlPanel,ID_TWO,    _T("2"),wxDefaultPosition, wxSize(45,45),0, wxDefaultValidator),1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	gs->Add(new wxButton(plControlPanel,ID_THREE,  _T("3"),wxDefaultPosition, wxSize(45,45),0, wxDefaultValidator),1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);

	gs->Add(new wxButton(plControlPanel,ID_E,      _T("E"),wxDefaultPosition, wxSize(45,45),0, wxDefaultValidator),1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	gs->Add(new wxButton(plControlPanel,ID_F,      _T("F"),wxDefaultPosition, wxSize(45,45),0, wxDefaultValidator),1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	gs->Add(new wxButton(plControlPanel,ID_ZERO,   _T("0"),wxDefaultPosition, wxSize(45,45),0, wxDefaultValidator),1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	gs->Add(new wxButton(plControlPanel,ID_DOT,    _T("."),wxDefaultPosition, wxSize(45,45),0, wxDefaultValidator),1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	gbs->Add(gs, wxGBPosition(0, 0), wxDefaultSpan, wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	sizer3->Add(gbs, 1,wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);

	sizer4->Add(new wxButton(plControlPanel,ID_MINUS,   _T("-"),wxDefaultPosition, wxSize(45,45),0, wxDefaultValidator),0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	sizer4->Add(new wxButton(plControlPanel,ID_PLUS,    _T("+"),wxDefaultPosition, wxSize(45,94),0, wxDefaultValidator),0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	sizer4->Add(new wxButton(plControlPanel,ID_EQUAL,   _T("="),wxDefaultPosition, wxSize(45,94),0, wxDefaultValidator),0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    sizer3->Add(sizer4, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);

	plControlPanel->SetSizer(sizer3);
	sizer3->Fit(plControlPanel);
    sizer3->SetSizeHints(plControlPanel);
	sizer6->Add(sizer5,0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	sizer6->Add(plControlPanel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    
	sizer1->Add(sizer6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(sizer1); //use the sizer for layout
	sizer1->Fit(this); //fit the sizer to the content
    sizer1->SetSizeHints(this); //set hintd to honor min size
	
	//Centre();
	if(this->m_nCurNum!=0)
    {
        display->SetValue(GetResultTxt(this->m_nCurNum));
    }
    else
    {
        display->SetValue(_T("0"));
    }
    SwitchControlPad(false,dec);


	Connect(ID_Dec,     wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&Calculate2::OnrdoDecSelect);
    Connect(ID_Hex,     wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&Calculate2::OnrdoHexSelect);
    Connect(ID_Oct,     wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&Calculate2::OnrdoOctSelect);
	Connect(ID_Bin,     wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&Calculate2::OnrdoBinSelect);

	Connect(ID_A,       wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Calculate2::OnA));
	Connect(ID_CLEARC,  wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Calculate2::OnClearc));
	Connect(ID_DIVID,   wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Calculate2::OnDivid));
	Connect(ID_MULTI,   wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Calculate2::OnMulti));

	Connect(ID_B,       wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Calculate2::OnB));
	Connect(ID_SEVEN,   wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Calculate2::OnSeven));
	Connect(ID_EIGHT,   wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Calculate2::OnEight));
	Connect(ID_NIGHT,   wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Calculate2::OnNight));

	Connect(ID_C,       wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Calculate2::OnC));
	Connect(ID_FOUR,    wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Calculate2::OnFour));
	Connect(ID_FIVE,    wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Calculate2::OnFive));
	Connect(ID_SIX,     wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Calculate2::OnSix));

	Connect(ID_D,       wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Calculate2::OnD));
	Connect(ID_ONE,     wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Calculate2::OnOne));
	Connect(ID_TWO,     wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Calculate2::OnTwo));
	Connect(ID_THREE,   wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Calculate2::OnThree));

	Connect(ID_E,       wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Calculate2::OnE));
	Connect(ID_F,       wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Calculate2::OnF));
	Connect(ID_ZERO,    wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Calculate2::OnZero));
	Connect(ID_DOT,     wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Calculate2::OnDot));

	Connect(ID_MINUS,   wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Calculate2::OnMinus));
	Connect(ID_PLUS,    wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Calculate2::OnPlus));
	Connect(ID_EQUAL,   wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Calculate2::OnEqual));

}
int Calculate2::ncount=0;
double Calculate2::m_nPrevNum =0;
double Calculate2::m_nCurNum=0;
int Calculate2::gcount=0;
wxString transformresult=_T("");

void OctTransform(int num){  transformresult.Printf(_T("%o%s"),num,transformresult);}
void HexTransform(int num){ transformresult.Printf(_T("%X%s"),num,transformresult);}

void Calculate::OnClearc(wxCommandEvent & event){display->Clear();SetOperator(none);}
void Calculate::OnDivid(wxCommandEvent & event){SetOperator(Divid);}
void Calculate::OnMulti(wxCommandEvent & event){SetOperator(Multi);}

void Calculate::OnSeven(wxCommandEvent & event){Input(_T("7"));}
void Calculate::OnEight(wxCommandEvent & event){Input(_T("8"));}
void Calculate::OnNight(wxCommandEvent & event){Input(_T("9"));}

void Calculate::OnFour(wxCommandEvent & event){Input(_T("4"));}
void Calculate::OnFive(wxCommandEvent & event){Input(_T("5"));}
void Calculate::OnSix(wxCommandEvent & event){Input(_T("6"));}

void Calculate::OnOne(wxCommandEvent & event){Input(_T("1"));}
void Calculate::OnTwo(wxCommandEvent & event){Input(_T("2"));}
void Calculate::OnThree(wxCommandEvent & event){Input(_T("3"));}

void Calculate::OnZero(wxCommandEvent & event){Input(_T("0"));}
void Calculate::OnDot(wxCommandEvent & event){Input(_T("."));}
void Calculate::OnMinus(wxCommandEvent & event){SetOperator(Minus);}
void Calculate::OnPlus(wxCommandEvent & event){SetOperator(Plus);}
void Calculate::OnEqual(wxCommandEvent & event){Run();}

void Calculate::OnrdoDecSelect(wxCommandEvent& event)
{
    if(this->m_nCurNum!=0)
    {
        display->SetValue(GetResultTxt(this->m_nCurNum));
    }
    else
    {
        display->SetValue(GetResultTxt(this->m_nPrevNum));
    }
    SwitchControlPad(true);
}
void Calculate::OnrdoHexSelect(wxCommandEvent& event)
{
    double num=0;
    if(this->m_nCurNum!=0)
    {
        num=this->m_nCurNum;
    }
    else
    {
        num=this->m_nPrevNum;
    }

    if(num<0)
    {
        rdoDec->SetValue(true);
        event.Skip(false);
        return;
    }
    transformresult=_T("");
    HexTransform(num);
    display->SetValue(transformresult);
    SwitchControlPad(false);
}
void Calculate::OnrdoOctSelect(wxCommandEvent& event)
{
    double num=0;
    if(this->m_nCurNum!=0)
    {
        num=this->m_nCurNum;
    }
    else
    {
        num=this->m_nPrevNum;
    }
    if(num<0)
    {
        rdoDec->SetValue(true);
        event.Skip(false);
        return;
    }
    transformresult=_T("");
    OctTransform(num);
    display->SetValue(transformresult);
    SwitchControlPad(false);
}

void DecTransform2(int num){transformresult.Printf(_T("%d%s"),num,transformresult);}
void OctTransform2(int num){transformresult.Printf(_T("%o%s"),num,transformresult);}
void HexTransform2(int num){transformresult.Printf(_T("%X%s"),num,transformresult);}
//=============== NOTE  there are still some problem for the 位數 =======================
	void BinTransform2(int num){
    long double total=0;
	long double m=1;
	while(num!=0)
    {
       total=total+(num%2)*m;
       num=num/2;
       m=m*10;
  }
  transformresult.Printf(_T("%.0f"),total);
}
//=======================================================================================

void Calculate2::OnA(wxCommandEvent & event){InputHex(_T("A"),10);}
void Calculate2::OnClearc(wxCommandEvent & event){display->Clear();SetOperator(none);}
void Calculate2::OnDivid(wxCommandEvent & event){SetOperator(Divid);}
void Calculate2::OnMulti(wxCommandEvent & event){SetOperator(Multi);}

void Calculate2::OnB(wxCommandEvent & event){InputHex(_T("B"),11);}
void Calculate2::OnSeven(wxCommandEvent & event){InputHex(_T("7"),7);}
void Calculate2::OnEight(wxCommandEvent & event){InputHex(_T("8"),8);}
void Calculate2::OnNight(wxCommandEvent & event){InputHex(_T("9"),9);}

void Calculate2::OnC(wxCommandEvent & event){InputHex(_T("C"),12);}
void Calculate2::OnFour(wxCommandEvent & event){InputHex(_T("4"),4);;}
void Calculate2::OnFive(wxCommandEvent & event){InputHex(_T("5"),5);}
void Calculate2::OnSix(wxCommandEvent & event){InputHex(_T("6"),6);}

void Calculate2::OnD(wxCommandEvent & event){InputHex(_T("D"),13);}
void Calculate2::OnOne(wxCommandEvent & event){InputHex(_T("1"),1);}
void Calculate2::OnTwo(wxCommandEvent & event){InputHex(_T("2"),2);}
void Calculate2::OnThree(wxCommandEvent & event){InputHex(_T("3"),3);}

void Calculate2::OnE(wxCommandEvent & event){InputHex(_T("E"),14);}
void Calculate2::OnF(wxCommandEvent & event){InputHex(_T("F"),15);}
void Calculate2::OnZero(wxCommandEvent & event){InputHex(_T("0"),0);}
void Calculate2::OnDot(wxCommandEvent & event){InputHex(_T("."),-1);}

void Calculate2::OnMinus(wxCommandEvent & event){SetOperator(Minus);}
void Calculate2::OnPlus(wxCommandEvent & event){SetOperator(Plus);}
void Calculate2::OnEqual(wxCommandEvent & event){Run();}

void Calculate2::OnrdoDecSelect(wxCommandEvent& event)
{
	 double num=0;
    if(this->m_nCurNum!=0)
    {
		num=this->m_nCurNum;
    }
    else
    {
		num=this->m_nPrevNum;
    }
	transformresult=_T("");
    DecTransform2(num);
    display->SetValue(transformresult);
    SwitchControlPad(false,dec);
}
void Calculate2::OnrdoHexSelect(wxCommandEvent& event)
{
    double num=0;
    if(this->m_nCurNum!=0)
    {
        num=this->m_nCurNum;
    }
    else
    {
        num=this->m_nPrevNum;
    }

    if(num<0)
    {
        rdoDec->SetValue(true);
        event.Skip(false);
        return;
    }
    transformresult=_T("");
    HexTransform2(num);
    display->SetValue(transformresult);
    SwitchControlPad(false,hex);
}
void Calculate2::OnrdoOctSelect(wxCommandEvent& event)
{
    double num=0;
    if(this->m_nCurNum!=0)
    {
        num=this->m_nCurNum;
    }
    else
    {
        num=this->m_nPrevNum;
    }
    if(num<0)
    {
        rdoDec->SetValue(true);
        event.Skip(false);
        return;
    }
    transformresult=_T("");
    OctTransform2(num);
    display->SetValue(transformresult);
    SwitchControlPad(false,oct);
}
void Calculate2::OnrdoBinSelect(wxCommandEvent& event)
{
	double num=0;
    if(this->m_nCurNum!=0)
    {
        num=this->m_nCurNum;
    }
    else
    {
        num=this->m_nPrevNum;
    }

    if(num<0)
    {
        rdoDec->SetValue(true);
        event.Skip(false);
        return;
    }
    transformresult=_T("");
    BinTransform2(num);
    display->SetValue(transformresult);
    SwitchControlPad(false,bin);
}