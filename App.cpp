//
// Created by tardis1 on 12/23/23.
//

#include "App.h"
#include "MainFrame.h"
#include <wx/wx.h>

//Yes, I miss my good old main() function.
//But, this global declaration contains
//the main() function and neither you nor I
//can really hope to improve in this set up.
//So, just use it.
wxIMPLEMENT_APP(App);

//by overriding OnInit, an interface in App
// that inherits all of WxApp, this becomes
//your main set-up function.
bool App::OnInit() {
   auto* mainFrame = new MainFrame("C++ GUI");
   mainFrame->SetClientSize(800, 600);
   mainFrame->Center();
   return mainFrame->Show();
}
