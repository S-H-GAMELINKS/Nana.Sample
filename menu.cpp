// ref https://qpcr4vir.github.io/nana-doxy/html/d1/d90/example_menu_8cpp-example.html
#include <nana/gui/wvl.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/menu.hpp>
#include <iostream> 

int main(){

	auto func = [&](auto item) { std::cout << item.index() << std::endl; };

	nana::form fm;

	fm.caption(L"Sample Menu");

	nana::menu menuobj;

	menuobj.append("Item0", func);
	menuobj.append_splitter();
	menuobj.append("Item1", func);


	nana::button btn(fm, nana::rectangle(nana::point(10, 10), nana::size(100, 25)));
	btn.caption("Popup Menu");

	btn.events().mouse_down(menu_popuper(menuobj, btn, nana::point(100, 36), nana::mouse::any_button));

	fm.show();
	nana::exec();
}
