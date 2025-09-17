# Hotel Management System (C Project)

A **console-based Hotel Management System** implemented in C that allows customers to book rooms, order food, and avail hotel services, while enabling owners to track earnings and customer details. This project demonstrates memory management, struct usage, and simple menu-driven programming in C.

---

## Features

### Customer Interface
- Book rooms: Suite, 2-Person, or Single.
- Order meals:
  - Breakfast (₹100)
  - Lunch (₹300)
  - Buffet Dinner (₹500)
  - Room Service Dinner (₹600)
- Add services:
  - Spa (₹500)
  - Gym (₹200)
  - Swimming Pool (₹300)
  - Massage (₹400)
  - Guided Tour (₹600)
- Multi-day food ordering with looping menus.
- Automatic total cost calculation (room + food + services).
- Bill generation with **5% CGST + 5% SGST**.
- Data stored dynamically for later access by the owner.

### Owner Interface
- Password-protected access (`admin123`).
- View total earnings (with tax details).
- Retrieve full customer details including billing.

### Technical Highlights
- Dynamic memory allocation for customer records using **structs and pointers**.
- Input validation with defaults for invalid inputs.
- Easy-to-follow **menu-driven navigation**.
- Tracks overall hotel **earnings and customers**.
- Prevents memory leaks with cleanup at program exit.

---

## Cost Breakdown

| Item             | Price (₹) |
|------------------|-----------|
| Suite Room       | 2500/day  |
| 2-Person Room    | 1500/day  |
| Single Room      | 700/day   |
| Breakfast        | 100       |
| Lunch            | 300       |
| Buffet Dinner    | 500       |
| Room Dinner      | 600       |
| Spa              | 500       |
| Gym              | 200       |
| Pool             | 300       |
| Massage          | 400       |
| Tour             | 600       |
| Taxes            | CGST 5% + SGST 5% |

---

## Installation

1. Ensure you have a **C compiler** installed:
   - Linux/macOS: GCC is usually included.
   - Windows: Install MinGW or TDM-GCC.
   
2. Download or copy the file `finalproject.c` to your computer.

3. Compile the program:
gcc finalproject.c -o hotel_system

5. If compilation fails due to missing headers, install required development libraries using your package manager.

---

## Usage

1. Run the executable:
- Linux/macOS: `./hotel_system`
- Windows: `hotel_system.exe`

2. Main menu options:
- Press **1 → Customer Interface** (booking, food, services).
- Press **2 → Owner Interface** (password: `admin123`).
- Press **3 → Exit**.

3. Example Flow:
- Book a room → Order meals for stay duration → Add services → Generate final bill.

---

## Contributing

Contributions are welcome! To contribute:
1. Fork this repository.
2. Add new features (e.g., file storage for persistence).
3. Submit a pull request with your changes.

---

## License

This project is licensed under the **MIT License** – free to use, modify, and distribute.

---

## Notes

- Console-based only (no GUI).
- File persistence not included (data lost on exit).
- Minimal error handling (extend for real-world deployment).
- Tested on standard C environments; compiler-specific adjustments may be required.
