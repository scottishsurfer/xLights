#include "EventE131Panel.h"
#include "events/EventE131.h"

//(*InternalHeaders(EventE131Panel)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(EventE131Panel)
const long EventE131Panel::ID_STATICTEXT1 = wxNewId();
const long EventE131Panel::ID_SPINCTRL1 = wxNewId();
const long EventE131Panel::ID_STATICTEXT2 = wxNewId();
const long EventE131Panel::ID_SPINCTRL2 = wxNewId();
const long EventE131Panel::ID_STATICTEXT4 = wxNewId();
const long EventE131Panel::ID_CHOICE2 = wxNewId();
const long EventE131Panel::ID_STATICTEXT3 = wxNewId();
const long EventE131Panel::ID_SPINCTRL3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(EventE131Panel,wxPanel)
	//(*EventTable(EventE131Panel)
	//*)
END_EVENT_TABLE()

EventE131Panel::EventE131Panel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(EventE131Panel)
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
	FlexGridSizer1 = new wxFlexGridSizer(0, 2, 0, 0);
	FlexGridSizer1->AddGrowableCol(1);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Universe:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	SpinCtrl_Universe = new wxSpinCtrl(this, ID_SPINCTRL1, _T("1"), wxDefaultPosition, wxDefaultSize, 0, 1, 64000, 1, _T("ID_SPINCTRL1"));
	SpinCtrl_Universe->SetValue(_T("1"));
	FlexGridSizer1->Add(SpinCtrl_Universe, 1, wxALL|wxEXPAND, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Channel:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	SpinCtrl_Channel = new wxSpinCtrl(this, ID_SPINCTRL2, _T("1"), wxDefaultPosition, wxDefaultSize, 0, 1, 512, 1, _T("ID_SPINCTRL2"));
	SpinCtrl_Channel->SetValue(_T("1"));
	FlexGridSizer1->Add(SpinCtrl_Channel, 1, wxALL|wxEXPAND, 5);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Test:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	FlexGridSizer1->Add(StaticText4, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Choice_Test = new wxChoice(this, ID_CHOICE2, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
	Choice_Test->SetSelection( Choice_Test->Append(_("Equals")) );
	Choice_Test->Append(_("Less Than"));
	Choice_Test->Append(_("Less Than or Equals"));
	Choice_Test->Append(_("Greater Than"));
	Choice_Test->Append(_("Greater Than or Equals"));
	Choice_Test->Append(_("Not Equals"));
	Choice_Test->Append(_("Continuous"));
	Choice_Test->Append(_("On Change"));
	FlexGridSizer1->Add(Choice_Test, 1, wxALL|wxEXPAND, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Value:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	FlexGridSizer1->Add(StaticText3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	SpinCtrl_Value = new wxSpinCtrl(this, ID_SPINCTRL3, _T("255"), wxDefaultPosition, wxDefaultSize, 0, 0, 255, 255, _T("ID_SPINCTRL3"));
	SpinCtrl_Value->SetValue(_T("255"));
	FlexGridSizer1->Add(SpinCtrl_Value, 1, wxALL|wxEXPAND, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);
	//*)
}

EventE131Panel::~EventE131Panel()
{
	//(*Destroy(EventE131Panel)
	//*)
}

bool EventE131Panel::ValidateWindow()
{
    return true;
}

void EventE131Panel::Save(EventBase* event)
{
    EventE131* e = (EventE131*)event;
    e->SetUniverse(SpinCtrl_Universe->GetValue());
    e->SetChannel(SpinCtrl_Channel->GetValue());
    e->SetCondition(Choice_Test->GetStringSelection().ToStdString());
    e->SetThreshold(SpinCtrl_Value->GetValue());
}

void EventE131Panel::Load(EventBase* event)
{
    EventE131* e = (EventE131*)event;
    SpinCtrl_Universe->SetValue(e->GetUniverse());
    SpinCtrl_Channel->SetValue(e->GetChannel());
    Choice_Test->SetStringSelection(e->GetCondition());
    SpinCtrl_Value->SetValue(e->GetThreshold());
}

