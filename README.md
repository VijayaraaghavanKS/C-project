\# Hotel Management System



\## Overview

This is a console-based Hotel Management System implemented in C. It allows customers to book rooms, order food, and use hotel services, while calculating total costs including taxes. There's also an owner interface for viewing earnings and customer details, protected by a password. The system uses dynamic memory allocation to handle multiple customers and tracks total earnings.



The program simulates a hotel's operations with user-friendly prompts, making it easy for customers to plan their stay and for owners to manage data.



\## Functionality

\- \*\*Customer Interface\*\*:

&nbsp; - Collects customer name and books a room based on type (Suite, 2-Person, or Single) and number of days.

&nbsp; - Allows ordering meals (breakfast, lunch, dinner) for each day of stay, with options for buffet or room service dinner.

&nbsp; - Offers additional services like Spa, Gym, Swimming Pool, Massage, and Guided Tour.

&nbsp; - Calculates total costs (room + food + services) and optionally generates a bill with 5% CGST and 5% SGST taxes.

&nbsp; - Stores customer data dynamically for later owner access.



\- \*\*Owner Interface\*\*:

&nbsp; - Password-protected (default: "admin123") to ensure secure access.

&nbsp; - View total earnings, including taxes (CGST and SGST at 5% each).

&nbsp; - View details of all customers, including their costs and totals.



\- \*\*Key Features\*\*:

&nbsp; - Dynamic memory management for customer records using structs and pointers.

&nbsp; - Input validation for choices, with defaults for invalid inputs.

&nbsp; - Looping menus for multi-day food ordering.

&nbsp; - Automatic updates to total earnings with each customer booking.

&nbsp; - Memory cleanup at program exit to prevent leaks.



\- \*\*Cost Breakdown\*\*:

&nbsp; - Rooms: Suite (Rs. 2500/day), 2-Person (Rs. 1500/day), Single (Rs. 700/day).

&nbsp; - Meals: Breakfast (Rs. 100), Lunch (Rs. 300), Buffet Dinner (Rs. 500), Room Service Dinner (Rs. 600).

&nbsp; - Services: Spa (Rs. 500), Gym (Rs. 200), Pool (Rs. 300), Massage (Rs. 400), Tour (Rs. 600).

&nbsp; - Taxes: 5% CGST + 5% SGST on total cost (excluding tax in base calculations).



\## Installation

1\. Ensure you have a C compiler installed (e.g., GCC on Windows via MinGW, or built-in on Linux/macOS).

2\. Download or copy the `finalproject.c` file to your local machine.

3\. Compile the program:

&nbsp;  - Open a terminal or command prompt.

&nbsp;  - Run: `gcc finalproject.c -o hotel\_system` (this creates an executable named `hotel\_system`).

4\. If compilation fails due to missing headers, install necessary libraries (e.g., via your package manager).



\## Usage

1\. Run the compiled executable: `./hotel\_system` (on Linux/macOS) or `hotel\_system.exe` (on Windows).

2\. From the main menu:

&nbsp;  - Select 1 for Customer Interface to book and manage a stay.

&nbsp;  - Select 2 for Owner Interface (enter password "admin123").

&nbsp;  - Select 3 to exit.

3\. Follow the on-screen prompts for inputs.

4\. Example flow: Book a room, order food per day, add services, and generate a bill.



\## Contributing

If you'd like to contribute:

\- Fork the repository.

\- Make your changes (e.g., add new features like saving data to files).

\- Submit a pull request with a description of your updates.



\## License

This project is open-source and available under the MIT License (feel free to add or change this).



\## Notes

\- This is a basic console application— no GUI or file persistence is included.

\- Error handling is minimal; expand it for production use.

\- Tested on standard C environments; may require adjustments for specific compilers.



