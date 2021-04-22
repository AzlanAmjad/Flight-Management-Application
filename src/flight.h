
#ifndef flight_h
#define flight_h
#include <vector>
#include <string>

class flight{
	private:
		string flight_number;
		int row;
		int col;
		vector<passenger> passengers;
		int num_of_pass;
	public:
		flight(string file_name);
		/*REQUIREMENTS:
		 * 	- string file name
		 * PROMISES:
		 * 	- constructs object flight, within constructs passenger vector, 
		 * 	and seat within each passenger
		 */
		void set_flight_number(string a);
		/*REQUIREMENTS:
		 * 	- string a
		 * PROMISES:
		 * 	- sets string flight number
		 */
		void set_row(int a);
		/*REQUIREMENTS:
		 * 	- int a
		 * PROMISES:
		 * 	- sets int row
		 */
		void set_col(int a);
		/*REQUIREMENTS:
		 * 	- int a
		 * PROMISES:
		 * 	- sets int col
		 */
		string get_flight_number()const;
		/*REQUIREMENTS:
		 * 	- none
		 * PROMISES:
		 * 	- returns string flight number
		 */
		int get_row()const;
		/*REQUIREMENTS:
		 * 	- none
		 * PROMISES:
		 * 	- returns int row
		 */
		int get_col()const;
		/*REQUIREMENTS:
		 * 	- none
		 * PROMISES:
		 * 	- returns int col
		 */
		
		void show_seat_map();
		/*REQUIREMENTS:
		 * 	- none
		 * PROMISES:
		 * 	- displays visual flight seat map
		 */
		void display_passengers();
		/*REQUIREMENTS:
		 * 	- none
		 * PROMISES:
		 * 	- displays data table with passengers and their information
		 */
		void add_passenger();
		/*REQUIREMENTS:
		 * 	- none
		 * PROMISES:
		 * 	- allows user to add passenger
		 */
		void remove_passenger();
		/*REQUIREMENTS:
		 * 	- none
		 * PROMISES:
		 * 	- allows user to remove passenger using ID number
		 */
		void save_data();
		/*REQUIREMENTS:
		 * 	- none
		 * PROMISES:
		 * 	- allows user to save data back to file
		 */
};

#endif
