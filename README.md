A simple, console-based application written in C++ that allows hotel staff to manage room availability and book rooms for customers. 
The system uses File Handling to save booking records and track room stock across different sessions.

Key Features:-
Secure Admin Login: Requires a username and password to access the management features.
Room Management: Tracks availability for three types of rooms:

Deluxe(Rs 5,000/day)
Super-Deluxe(Rs 7,000/day)
Suite(Rs 10,000/day)

Real-time Booking: Calculates total bills based on the number of days and reduces available room stock automatically.
Persistent Data: Saves remaining room counts to room.dat.
Appends customer names and billing history to booking.txt.
Record Viewing: Staff can view a full history of all successful bookings.

Technical Details
Language: C++
Storage: Flat files (.txt and .dat) for data persistence.
Concepts Used: Object-oriented logic, File I/O (ifstream/ofstream), Control Structures (switch-case, if-else), and Boolean flags for authentication.

How to Run.
Clone the repository.
Compile the Hotel-reservation-system.cpp file using any C++ compiler (e.g., g++).
Run the executable.
Default Credentials:
ID: admin
Password: admin123
