
#ifndef passenger_h
#define passenger_h
#include <vector>
#include <string>

class passenger{
	private:
		string first_name;
		string last_name;
		string phone_number;
		seat passenger_seat;
		string ID_number;
	public:
		void set_first_name(string a);
		/*REQUIREMENTS:
		 * 	- string a
		 * PROMISES:
		 * 	- sets string first name
		 */
		void set_last_name(string a);
		/*REQUIREMENTS:
		 * 	- string a
		 * PROMISES:
		 * 	- sets string last name
		 */
		void set_phone_number(string a);
		/*REQUIREMENTS:
		 * 	- string a
		 * PROMISES:
		 * 	- sets string phone number
		 */
		void set_ID_number(string a);
		/*REQUIREMENTS:
		 * 	- string a
		 * PROMISES:
		 * 	- sets string ID number
		 */
		void set_passenger_seat(string a);
		/*REQUIREMENTS:
		 * 	- string a
		 * PROMISES:
		 * 	- constructs passenger seat by call to set_seat_label
		 */
		string get_first_name()const;
		/*REQUIREMENTS:
		 * 	- none
		 * PROMISES:
		 * 	- returns string first name
		 */
		string get_last_name()const;
		/*REQUIREMENTS:
		 * 	- none
		 * PROMISES:
		 * 	- returns string last name
		 */
		string get_phone_number()const;
		/*REQUIREMENTS:
		 * 	- none
		 * PROMISES:
		 * 	- returns string phone number
		 */
		string get_ID_number()const;
		/*REQUIREMENTS:
		 * 	- none
		 * PROMISES:
		 * 	- returns string ID number
		 */
		seat get_passenger_seat()const;
		/*REQUIREMENTS:
		 * 	- none
		 * PROMISES:
		 * 	- returns seat object passenger seat
		 */
};

#endif
