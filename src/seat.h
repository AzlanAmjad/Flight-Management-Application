
#ifndef seat_h
#define seat_h
#include <vector>
#include <string>

class seat{
	private:
		string seat_label;
	public:
		void set_seat_label(string a);
		/*REQUIREMENTS:
		 * 	- string a
		 * PROMISES:
		 * 	- set string seat label
		 */
		string get_seat_label()const;
		/*REQUIREMENTS:
		 * 	- none
		 * PROMISES:
		 * 	- returns string seat label
		 */
};

#endif
