// include nana
#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>

int main() {

	// create form
	nana::form fm;

	fm.div("<text><button>");

	// create button
	nana::button btn{ fm, "click" };

	// set button events in click
	btn.events().click([&fm] {
		nana::label lab{ fm, "Hello, Nana C++ Library!" };
		fm["text"] << lab;
		fm.collocate();
	});

	fm["button"] << btn;
	fm.collocate();

	// draw form
	fm.show();

	nana::exec();
}
