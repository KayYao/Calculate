#include <wx/wx.h>
#include <wx/msgdlg.h>
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/dialog.h>

#define none     -1
#define Multi     0
#define Minus     1
#define Plus      2
#define Divid     3
#define Euqal     4

#define bin		  2
#define oct		  8
#define dec       10
#define hex		  16


class Calculate : public wxPanel
{
public:
    Calculate(wxPanel * parent);
	wxMenuBar *menubar;
	wxMenu *file;
	wxMenu *imp;
	wxMenu *file2;
	wxMenu *file3;


	wxBoxSizer *sizer1,*sizer2,*sizer3,*sizer4,*sizer5;
	wxGridSizer *gs;
	wxTextCtrl *display;
	wxStaticBoxSizer *stbox;
	wxRadioButton *rdoDec,*rdoHex,*rdoOct;
	wxGridBagSizer* gbs;
	wxPanel *plAll,*plControlPanel;

	void OnrdoHexSelect(wxCommandEvent& event);
	void OnrdoDecSelect(wxCommandEvent& event);
	void OnrdoOctSelect(wxCommandEvent& event);
	
    void OnClearc(wxCommandEvent & event);
	void OnDivid(wxCommandEvent & event);
	void OnMulti(wxCommandEvent & event);

    void OnSeven(wxCommandEvent & event);
	void OnEight(wxCommandEvent & event);
	void OnNight(wxCommandEvent & event);
    
	void OnFour(wxCommandEvent & event);
    void OnFive(wxCommandEvent & event);
	void OnSix(wxCommandEvent & event);
	
	void OnOne(wxCommandEvent & event);
	void OnTwo(wxCommandEvent & event);
	void OnThree(wxCommandEvent & event);

	void OnZero(wxCommandEvent & event);
	void OnDot(wxCommandEvent & event);

	void OnMinus(wxCommandEvent & event);
	void OnPlus(wxCommandEvent & event);
    void OnEqual(wxCommandEvent & event);

	void OnEngineer(wxCommandEvent & event);

private:
	int m_nCurOperator; 
	int m_nPreOperator; 
    double m_nPrevNum;
    double m_nCurNum;
    bool m_bIsFloat;
    bool m_bIsFirstIn;
	int m_count;
	

    void Init()
    {
            this->display->SetValue(_T("0"));
            this->m_nCurNum=0;
            this->m_nPrevNum=0;
			this->m_count=0;
            this->m_bIsFloat=false;
            this->m_bIsFirstIn=true;
            this->m_nCurOperator=-2;
			this->m_nPreOperator=-2;
     }

	void SetOperator(int p){
		m_count++;
		
		if(p==none)
         {
                Init();
          }
            else
			{
				if(m_count>=2){
                if(m_bIsFirstIn)
                {
                    this->m_bIsFirstIn=false;
                    this->m_nPrevNum=wxAtof(this->display->GetValue());
                    this->m_nPreOperator=p;
                }
                else
                {
					if(m_count>=3){
                       this->m_nCurNum=0;
					   this->m_nCurOperator=p;
				       m_nPreOperator=m_nCurOperator;
				       m_nCurOperator=-2;
			        }else{
                    this->m_nCurNum=wxAtof(this->display->GetValue());
					this->m_nCurOperator=p;
                    Run();
					}
                }
                //reset
                m_bIsFloat=false;
                this->m_nCurNum=0;
				if(m_nCurOperator>=none)
				{m_nPreOperator=m_nCurOperator;}
				m_nCurOperator=-2;
            }
		}
	}
	void Run(){
		double result=0;

            if(m_bIsFirstIn)
            {
                result=wxAtof(this->display->GetValue());
            }
            else
            {
                switch(this->m_nPreOperator)
                {
				case Multi:
                    result=this->m_nPrevNum * this->m_nCurNum;
					break;
				case Minus:
                    result=this->m_nPrevNum - this->m_nCurNum;
                    break;
                case Plus:
                    result=this->m_nPrevNum + this->m_nCurNum;
                    break;
				case Divid:
                    if(this->m_nCurNum!=0)
                    {
                        result=this->m_nPrevNum / this->m_nCurNum;
                    }
                    else
                    {
                        wxMessageBox(_T("Can not divided by zero!"));
                    }
                    break;
                case none:
                default:
                    result= this->m_nPrevNum;
                    break;
                }
			}
			this->m_nPrevNum=result;
            this->display->SetValue(GetResultTxt(result));

            if(result<0)
            {
                rdoDec->SetValue(true);
                rdoHex->Enable(false);
                rdoOct->Enable(false);
            }
            else
            {
                rdoHex->Enable(true);
                rdoOct->Enable(true);
            }

			if(m_count==1){
				m_bIsFirstIn=true;
				m_bIsFloat=false;
                this->m_nCurNum=0;
				m_nPreOperator=0;
				m_nCurOperator=-2;
			}
	}

	static wxString GetResultTxt(double result)
        {
            wxString resultstr=wxString::Format(_T("%.13f"),result);
            //delete the fractional when total length max than 14
            while(resultstr.Len()>14 && resultstr.Find('.')!=(int)resultstr.Len()-1)
            {
                resultstr=resultstr.Left(resultstr.Len()-1);
            }
            //delete 0 behind the string
            while(resultstr.Find('0',true)==(int)resultstr.Len()-1)
            {
                if(resultstr.Len()>2)
                {
                    resultstr=resultstr.Left(resultstr.Len()-1);
                }
                else
                {
                    break;
                }
            }

            //while result is max then 14,you can use the scientific notation

            return resultstr;
        }
	void Input(wxString num)
        {
			m_count=1;
            wxString curnumstr=GetResultTxt(this->m_nCurNum);
            if(curnumstr.Len()==14)
            {
                return;
            }

            if(curnumstr==_T("0"))
            {
                if(num==_T("."))
                {
                    this->m_bIsFloat=true;
                }
                else
                {
                    if(!m_bIsFloat)
                    {
                        this->display->SetValue(wxString::Format(_T("%s"),num));
                    }
                    else
                    {
                        this->display->AppendText(wxString::Format(_T("%s"),num));
                    }
                }
            }
            else
            {
                if(curnumstr.Find('.')==(int)curnumstr.Len()-1 && !m_bIsFloat)
                {
                    if(num==_T("."))
                    {
                        this->m_bIsFloat=true;
                    }
                    else
                    {
                        wxString numstr=curnumstr.Left(curnumstr.Len()-1);
                        this->display->SetValue(wxString::Format(_T("%s%s"),numstr,num));
						//this->display->SetValue(wxString::Format(_T("%s"),num));
                    }
                }
                else
                {
                    if(num!=_T("."))
                    {
                        this->display->AppendText(wxString::Format(_T("%s"),num));
                    }
                }
            }

            this->m_nCurNum=wxAtof(this->display->GetValue());
			
        }
	void SwitchControlPad(bool enable)
        {
            wxWindowList controls = this->plControlPanel->GetChildren();

             wxWindowList::iterator iter;
             for (iter = controls.begin(); iter != controls.end(); ++iter)
             {
                    wxWindow *button = *iter;
                    if(button!=NULL)  button->Enable(enable);
             }
        }



protected:
	enum{ID_STANDER=300,
		 ID_ENGINEER};

	enum{ID_Dec=200,
	     ID_Hex,
		 ID_Oct,
		 ID_CONTROLPANEL,

         ID_CLEARC,
		 ID_DIVID,
		 ID_MULTI,

		 ID_SEVEN,
		 ID_EIGHT,
		 ID_NIGHT,
		 
		 ID_FOUR,
		 ID_FIVE,
	     ID_SIX,
		 
		 ID_ONE,
		 ID_TWO,
		 ID_THREE,

		 ID_ZERO,
		 ID_DOT,
		 ID_MINUS,
		 ID_PLUS,
		 ID_EQUAL};

};

class Calculate2 :public wxPanel
{

private:
	int m_nCurOperator; 
	int m_nPreOperator; 
    static double m_nPrevNum;
    static double m_nCurNum;
    bool m_bIsFloat;
    bool m_bIsFirstIn;
	bool m_bIsSelection;
	int m_count;
    static int ncount;
	int kkk;
	int selection;
	int selection2;
	static int gcount;
	wxString transformresult2;
	
    void Init()
    {
            this->display->SetValue(_T("0"));
            this->m_nCurNum=0;
            this->m_nPrevNum=0;
			this->m_count=0;
			this->ncount=0;
            this->m_bIsFloat=false;
            this->m_bIsFirstIn=true;
            this->m_nCurOperator=-2;
			this->m_nPreOperator=-2;
     }

	void SetOperator(int p){
		m_count++;
		gcount=0;
		if(p==none)
        {
            Init();
        }
        else
		{
			if(m_count>=2)
			{
				if(m_bIsFirstIn)
				{
					this->m_bIsFirstIn=false;
					if((ncount>0) ){
						if(this->m_nCurNum==0){
							this->m_nPrevNum=this->m_nPrevNum;
						}else
						{
							this->m_nPrevNum=this->m_nCurNum;
						}
					}else{
							//this->m_nPrevNum=this->m_nCurNum;
							this->m_nPrevNum=wxAtof(this->display->GetValue());
					}
					 this->m_nPreOperator=p;
				}else{
						if(m_count>=3)
						{
							 this->m_nCurNum=0;
							 this->m_nCurOperator=p;
							 m_nPreOperator=m_nCurOperator;
							 m_nCurOperator=-2;
						}else{
								this->m_nCurNum=wxAtof(this->display->GetValue());
								this->m_nCurOperator=p;
								Run();
							}
					}
                //reset
				m_bIsFloat=false;
				this->m_nCurNum=0;
				if(m_nCurOperator>=none){
					m_nPreOperator=m_nCurOperator;
				}
					m_nCurOperator=-2;
            }
		}
	}
	void OctTransform3(int num){transformresult2.Printf(_T("%o%s"),num,transformresult2);}
	void HexTransform3(int num){transformresult2.Printf(_T("%X%s"),num,transformresult2);}
	void DecTransform3(int num){transformresult2.Printf(_T("%d%s"),num,transformresult2);}
	void BinTransform3(int num){
		long double total=0;
		long double m=1;
		while(num!=0)
		{
			total=total+(num%2)*m;
			num=num/2;
			m=m*10;
		}
		transformresult2.Printf(_T("%.0f"),total);
	}

	void Run(){
		double result=0;
		 wxString transformresult=_T("");
           if(m_bIsFirstIn)
            {
                result=wxAtof(this->display->GetValue());
            }
            else
            {
                switch(this->m_nPreOperator)
                {
				case Multi:
                    result=this->m_nPrevNum * this->m_nCurNum;
					break;
				case Minus:
                    result=this->m_nPrevNum - this->m_nCurNum;
                    break;
                case Plus:
                    result=this->m_nPrevNum + this->m_nCurNum;
                    break;
				case Divid:
                    if(this->m_nCurNum!=0)
                    {
                        result=this->m_nPrevNum / this->m_nCurNum;
                    }
                    else
                    {
                        wxMessageBox(_T("Can not divided by zero!"));
                    }
                    break;
                case none:
                default:
                    result= this->m_nPrevNum;
                    break;
                }
			}
			this->m_nPrevNum=result;
			transformresult2=_T("");
			switch(selection2){
			case bin:
				BinTransform3(result);
				break;
			case oct:
				OctTransform3(result);
				break;
			case dec:
				DecTransform3(result);
				break;
			case hex:
				HexTransform3(result);
				break;
			}

			display->SetValue(transformresult2);

            if(result<0)
            {
                rdoDec->SetValue(true);
                rdoHex->Enable(false);
                rdoOct->Enable(false);
            }
            else
            {
                rdoHex->Enable(true);
                rdoOct->Enable(true);
            }

			if(m_count==1){
				m_bIsFirstIn=true;
				m_bIsFloat=false;
                this->m_nCurNum=0;
				m_nPreOperator=0;
				m_nCurOperator=-2;
			}
	}
	static wxString GetResultTxt(double result)
        {
            wxString resultstr=wxString::Format(_T("%.13f"),result);
            //delete the fractional when total length max than 14
            while(resultstr.Len()>14 && resultstr.Find('.')!=(int)resultstr.Len()-1)
            {
                resultstr=resultstr.Left(resultstr.Len()-1);
            }
            //delete 0 behind the string
            while((resultstr.Find('0',true)==(int)resultstr.Len()-1) )
            {
                if(resultstr.Len()>2)
                {
                    resultstr=resultstr.Left(resultstr.Len()-1);
                }
                else
                {
                    break;
                }
            }
            return resultstr;
        }

	void InputHex(wxString hexnum,double num2){
		m_count=1;
        wxString curnumstr=GetResultTxt(this->m_nCurNum);
        if(curnumstr.Len()==14)
        {
           return;
        }
		if(curnumstr!=_T("0"))
        {
           if((curnumstr.Find('.')==(int)curnumstr.Len()-1 )&&gcount==0)
                {
					gcount++;
                    wxString numstr=curnumstr.Left(curnumstr.Len()-1);
                    this->display->SetValue(wxString::Format(_T("%s%s"),numstr,hexnum));
                }else{
                    if(hexnum!=_T("."))
                    {
                        this->display->AppendText(wxString::Format(_T("%s"),hexnum));
                    }
                }
		}else{
			this->display->AppendText(wxString::Format(_T("%s"),hexnum));

		}

	   if(hexnum!=_T("")){
			if(ncount==0){
				this->m_nCurNum=num2;
			}else{
					this->m_nCurNum=this->m_nCurNum*selection2+num2;
			}
			ncount++;
		}else{
			ncount=0;
		}
   }

	void SwitchControlPad(bool enable,int selection)
        {
			int jjj;
			wxWindowList controls = this->plControlPanel->GetChildren();
			wxWindowList::iterator iter;

			if(m_bIsSelection==false) {
				for (iter = controls.begin(); iter != controls.end(); ++iter)
				 {
                    wxWindow *button = *iter;
                    if(button!=NULL)  button->Enable(true);
				}
				m_bIsSelection=true;
			}

			switch(selection){
			case bin: 
				selection2=bin;
				m_bIsSelection=false;
				for (jjj=0,iter = controls.begin(); iter != controls.end(); ++iter,++jjj)
				{
					if((jjj==1) ||(jjj==2)||(jjj==3) ||(jjj==13) ||(jjj==18)||(jjj==20)||(jjj==21) ||(jjj==22)) {
						;
					}else{
						wxWindow *button = *iter;
						if(button!=NULL)  button->Enable(enable);
					}
				}
				break;
			case oct: 
				selection2=oct;
				m_bIsSelection=false;
				for (jjj=0,iter = controls.begin(); iter != controls.end(); ++iter,++jjj)
				{
					if((((jjj%4)==0) &&jjj<20)||(jjj==6)||(jjj==17)||(jjj==7)||(jjj==19)){
						wxWindow *button = *iter;
						if(button!=NULL)  button->Enable(enable);
					}
				}
				break;
			case dec: 
				selection2=dec;
				m_bIsSelection=false;
				for (jjj=0,iter = controls.begin(); iter != controls.end(); ++iter,++jjj)
				{
					if((((jjj%4)==0) &&jjj<20)||(jjj==19)||(jjj==17)){
						wxWindow *button = *iter;
						if(button!=NULL)  button->Enable(enable);
					}
				}
				break;

			case hex: 
				selection2=hex;
				m_bIsSelection=false;
				for (jjj=0,iter = controls.begin(); iter != controls.end(); ++iter,++jjj)
				{
					if(jjj==19){
						wxWindow *button = *iter;
						if(button!=NULL)  button->Enable(enable);
					}
				}
				break;
			default: break;
		}	
	}

	public:
    Calculate2(wxPanel *parent);
	wxMenuBar *menubar;
	wxMenu *file;
	wxMenu *imp;
	wxMenu *file2;
	wxMenu *file3;


	wxBoxSizer *sizer1,*sizer2,*sizer3,*sizer4,*sizer5,*sizer6;
	wxGridSizer *gs;
	wxTextCtrl *display;
	wxStaticBoxSizer *stbox,*stbox2;
	wxRadioButton *rdoHex,*rdoDec,*rdoOct,*rdoBin,*rdoQword,*rdoDword,*rdoWord,*rdoByte;
	wxGridBagSizer* gbs;
	wxPanel *plControlPanel;

	
	void OnrdoHexSelect(wxCommandEvent& event);
	void OnrdoDecSelect(wxCommandEvent& event);
	void OnrdoOctSelect(wxCommandEvent& event);
	void OnrdoBinSelect(wxCommandEvent& event);

	void OnA(wxCommandEvent & event);
    void OnClearc(wxCommandEvent & event);
	void OnDivid(wxCommandEvent & event);
	void OnMulti(wxCommandEvent & event);

	void OnB(wxCommandEvent & event);
    void OnSeven(wxCommandEvent & event);
	void OnEight(wxCommandEvent & event);
	void OnNight(wxCommandEvent & event);
    
	void OnC(wxCommandEvent & event);
	void OnFour(wxCommandEvent & event);
    void OnFive(wxCommandEvent & event);
	void OnSix(wxCommandEvent & event);
	
	void OnD(wxCommandEvent & event);
	void OnOne(wxCommandEvent & event);
	void OnTwo(wxCommandEvent & event);
	void OnThree(wxCommandEvent & event);

	void OnE(wxCommandEvent & event);
	void OnF(wxCommandEvent & event);
	void OnZero(wxCommandEvent & event);
	void OnDot(wxCommandEvent & event);

	void OnMinus(wxCommandEvent & event);
	void OnPlus(wxCommandEvent & event);
    void OnEqual(wxCommandEvent & event);


protected:
	enum{ID_STANDER=300,
		 ID_ENGINEER};

	enum{ID_Dec=1000,
	     ID_Hex,
		 ID_Oct,
		 ID_Bin,
		 ID_Qword,
		 ID_Dword,
		 ID_Word,
		 ID_Byte,
		 ID_CONTROLPANEL,

		 ID_A,
         ID_CLEARC,
		 ID_DIVID,
		 ID_MULTI,

		 ID_B,
		 ID_SEVEN,
		 ID_EIGHT,
		 ID_NIGHT,
		 
		 ID_C,
		 ID_FOUR,
		 ID_FIVE,
	     ID_SIX,
		 
		 ID_D,
		 ID_ONE,
		 ID_TWO,
		 ID_THREE,

		 ID_E,
		 ID_F,
		 ID_ZERO,
		 ID_DOT,

		 ID_MINUS,
		 ID_PLUS,
		 ID_EQUAL};

};