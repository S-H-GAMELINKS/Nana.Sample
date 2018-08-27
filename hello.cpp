// include nana
#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>

int main() {

	// create form
	nana::form fm;

	nana::label lab{ fm, "Hello, Nana C++ Library!" };

	// set div
	fm.div("<weightt=80% text>");
	fm["text"] << lab;
	fm.collocate();	

	// draw form
	fm.show();

	nana::exec();
}
