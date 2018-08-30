#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/wvl.hpp>
#include <nana/gui/filebox.hpp>
#include <nana/gui/wvl.hpp>
#include <iostream>
#include <string>

int main() {

	nana::form fm;

	nana::label lab{ fm, "Click & Select Text File!" };

	nana::button btn(fm, nana::rectangle(20, 20, 150, 30));
	btn.caption("Select!");

	nana::filebox fb(0, true);

	fb.add_filter(("Text File"), ("*.text;*.doc"));
	fb.add_filter(("All Files"), ("*.*"));

	auto fopen_lambda = [&fb]{ 
		if (fb()) {
			std::string file = fb.file();
			std::cout << file << std::endl;
		}
	};

	btn.events().click(fopen_lambda);

	// set div
	fm.div("<label>");
	fm["label"] << lab;
	fm.collocate();

	fm.show();

	nana::exec();
}
