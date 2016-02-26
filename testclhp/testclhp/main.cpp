#include "main.h"
#include "communicate.h" 


IMPLEMENT_APP(MyApp)

bool MyApp::OnInit(){

	
	Communicate *comm = new Communicate(_T("¤pºâ½L"));
	comm->Show();

	return true;
}

