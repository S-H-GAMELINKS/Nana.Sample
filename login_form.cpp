#include <nana/gui/wvl.hpp>
#include <nana/gui/place.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/textbox.hpp>

int main() {

	nana::form fm;
	nana::textbox usr{ fm }, pswd{ fm };
	nana::button  login{ fm, "Login" }, cancel{ fm, "Cancel" };

	std::string name;

	cancel.events().click([&usr, &pswd, &name] {
		usr.saved();
		usr.reset("");
		pswd.reset("");
	});

	usr.tip_string("User:").multi_lines(false);
	pswd.tip_string("Password:").multi_lines(false).mask('*');

	nana::place plc{ fm };

	plc.div("<><weight=80% vertical<><weight=70% vertical <vertical gap=10 textboxs arrange=[25,25]>  <weight=25 gap=10 buttons> ><>><>");

	plc.field("textboxs") << usr << pswd;
	plc.field("buttons") << login << cancel;
	plc.collocate();

	fm.show();
	nana::exec();
}
