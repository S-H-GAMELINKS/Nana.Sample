// include nana
#include <nana/gui.hpp>
#include <iostream>

int main() {

	// create form
	nana::form fm;

	// set events to resized
	fm.events().resized([&fm] {
		std::cout << "Click!" << std::endl;
	});


	// draw form
	fm.show();

	nana::exec();
}
