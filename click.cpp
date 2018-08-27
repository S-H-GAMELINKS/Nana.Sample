// include nana
#include <nana/gui.hpp>
#include <iostream>

int main() {

	// create form
	nana::form fm;

	// set events to mouse click
	fm.events().click([&fm] {
		std::cout << "Click!" << std::endl;
	});


	// draw form
	fm.show();

	nana::exec();
}
