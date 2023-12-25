//
// Created by tardis1 on 12/23/23.
//

#include "MainFrame.h"
#include <wx/wx.h>
#include <wx/spinctrl.h>

MainFrame::MainFrame(const wxString& title): wxFrame(nullptr, wxID_ANY, title)
{
   //If a frame (window) only has one child,
   //the child will fill the frame, so,
   //always make a panel and add things to the panel.
   //I think this all comes from GTK.
   auto panel = new wxPanel(this);

   //add a button control to panel
   [[maybe_unused]] auto button = new wxButton( panel,
                                   wxID_ANY,
                                   "Press Here",
                                   wxPoint(150,50),
                                   wxSize(100,35),
                                   wxBU_EXACTFIT);


   //add a checkbox control to panel
   [[maybe_unused]] auto checkBox = new wxCheckBox( panel,
                                   wxID_ANY,
                                   "Check Box",
                                   wxPoint(550, 55),
                                   wxDefaultSize,
                                   wxCHK_3STATE | wxCHK_ALLOW_3RD_STATE_FOR_USER); //binary OR styles to combine

   //add static text to panel
   //though it is often best to use wxDefault size OR wxSize(-1, -1),
   //using other choices and styles can have a good effect on display
   [[maybe_unused]] auto staticText = new wxStaticText(panel,
                                      wxID_ANY,
                                      "Static text - NOT editable",
                                      wxPoint(120, 150),
                                      wxSize(300, -1),
                                      wxALIGN_CENTER);

   staticText->SetBackgroundColour(*wxLIGHT_GREY); //must be pointer to color

   //add a text control box (input??) to panel
   [[maybe_unused]] auto textCtrl = new wxTextCtrl(panel,
                                  wxID_ANY,
                                  "Text Box",
                                  wxPoint(500, 145),
                                  wxSize(200, -1));

   //add a slider control to panel
   [[maybe_unused]] auto slider = new wxSlider(panel,
                              wxID_ANY,
                              25,
                              0,
                              100,
                              wxPoint(100, 250),
                              wxSize(200, -1));

   //add a gauge control to panel.  Gauge is output only.
   auto gauge = new wxGauge(panel,
                        wxID_ANY,
                        100,
                        wxPoint(500, 255),
                        wxSize(200, -1));

   //set the value of the gauge
   gauge->SetValue(50);

   //select choice

   //array of strings for list
   wxArrayString choices;
   choices.Add("Item A");
   choices.Add("Item B");
   choices.Add("Item C");

   //build list
   auto choice = new wxChoice(panel,
                                   wxID_ANY,
                                   wxPoint(150, 375),
                                   wxSize(100, -1),
                                   choices);

   //set default choice item
   choice->Select(1);

   //spin control item
   //a spin control is a numeric control that lets
   //user "spin" the mouse wheel to move number choice
   //up and down, also allows typing in, but
   //won't accept alpha chars
#pragma clang diagnostic push
#pragma ide diagnostic ignored "MemoryLeak"
   [[maybe_unused]] auto spinCtrl = new wxSpinCtrl(panel,
                                   wxID_ANY,
                                   "",
                                   wxPoint(550, 375),
                                   wxSize(100, -1),
                                   wxSP_ARROW_KEYS,
                                   0,
                                   255,
                                   5,
                                   "Spin Me"
                                   );
#pragma clang diagnostic pop

   //a list box control
   //uses same string array as above for wxChoice
#pragma clang diagnostic push
#pragma ide diagnostic ignored "MemoryLeak"
   [[maybe_unused]] auto listBox = new wxListBox(panel,
                                wxID_ANY,
                                wxPoint(150, 475),
                                wxSize(100, -1),
                                choices);

   //set default
   listBox->Select(2);
#pragma clang diagnostic pop

   //Radio Button
   //also uses array of choices
   auto radioButton = new wxRadioBox(panel,
                                     wxID_ANY,
                                     "Choose only 1",
                                     wxPoint(485, 475),
                                     wxDefaultSize,
                                     choices);

   //set default
   radioButton->Select(1);





}