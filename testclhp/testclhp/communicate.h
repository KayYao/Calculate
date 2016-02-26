#include <wx/wx.h>
#include "calculate.h"
#include <wx/wxprec.h>


class Communicate : public wxFrame
{
public:
    Communicate(const wxString& title);

	wxMenuBar *menubar;
	wxMenu *file;
	wxMenu *imp;
	wxMenu *file2;
	wxMenu *file3;
	wxBoxSizer *hbox;
	wxFrame * nwfram;
	wxBoxSizer *sizer1,*sizer2,*sizer3,*sizer4,*sizer5;
	wxTextCtrl *display;

    Calculate *m_call;
    Calculate2 *m_cal2;
    wxPanel *m_parent;

	void OnEngineer(wxCommandEvent &event);
	void OnStander(wxCommandEvent &event);
	void OnHelp(wxCommandEvent & event);
    void OnAbout(wxCommandEvent & event);
	void OnExit(wxCommandEvent & event);


protected:
	enum{ID_STANDER=300,
		 ID_ENGINEER};
private:

	 static int scount;
	 static int ecount;

	void Stander(){
		if(scount>0 && ((scount%2)==1)){
			scount++;
			ecount=1;

			m_cal2->Hide();
			m_call= new  Calculate(m_parent);
			hbox->Add(m_call,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);

			hbox->Fit(this);
			hbox->SetSizeHints(this);
			m_parent->SetSizer(hbox);
		}
	}

	void Engineer(){
		if(ecount>0 && ((ecount%2)==1)){
			ecount++;
			scount=1;

			m_call->Hide();
			m_cal2 = new  Calculate2(m_parent);
			hbox->Add(m_cal2,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	
			hbox->Fit(this);
			hbox->SetSizeHints(this);
			m_parent->SetSizer(hbox);	

		}
	}
	DECLARE_EVENT_TABLE();
};


	