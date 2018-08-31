#include <nana/gui/screen.hpp>
#include <nana/gui.hpp>

int main(){
	auto s = nana::screen();
	auto pa = s.get_primary().workarea();
	nana::form fm;;

	fm.move(pa.x, pa.y);
	
	fm.outline_size({ pa.width, pa.height });
	fm.caption("Full Size Sample");
	fm.show();
	nana::exec();
}
