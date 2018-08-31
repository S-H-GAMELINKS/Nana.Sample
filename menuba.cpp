#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/filebox.hpp>
#include <nana/gui/place.hpp>
#include <nana/gui/widgets/menubar.hpp>
#include <iostream>

int main()
{
	nana::form fm;
	nana::place pl(fm);
	nana::menubar mn(fm);
	nana::label lab{ fm, "Click & Select Text File!" };
	nana::filebox fb(0, true);

	fb.add_filter(("Text File"), ("*.text;*.doc"));
	fb.add_filter(("All Files"), ("*.*"));

	auto fopen_lambda = [&fb] (nana::menu::item_proxy& ip) {
		if (fb()) {
			std::string file = fb.file();
			std::cout << file << std::endl;
		}
	};	

	pl.div("<vertical <menu weight=25>>");
	pl.field("menu") << mn;

	mn.push_back("Menu");
	mn.at(0).append("open modal window", fopen_lambda);
	pl.collocate();
	fm.show();
	nana::exec();
	return 0;
}
