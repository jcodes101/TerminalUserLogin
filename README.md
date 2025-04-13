# CLI User Authentication System (C++)

This is a simple **Command Line Interface (CLI) User Authentication System** written in C++ using basic file I/O operations. It allows users to:

- Sign Up (create an account)
- Login with credentials
- Recover forgotten passwords

This program stores user data (username, email, and password) in a text file named `loginData.txt`.

---

## 🔧 Built With

- C++
- CLion (IDE)
- Basic File Handling (`fstream`)

---

## 📁 File Structure

project-root/ │ ├── main.cpp # Main source file ├── loginData.txt # Auto-created text file to store user credentials


---

## 🧑‍💻 Features

1. **Sign-Up**
   - Allows a new user to register by entering a username, email, and password.
   - Saves the data to `loginData.txt` in the format:
     ```
     username*email*password
     ```

2. **Login**
   - Prompts the user to input a username and password.
   - Validates credentials against the entries in `loginData.txt`.

3. **Forgot Password**
   - Asks for the username and email.
   - If a match is found, it displays the stored password.

4. **Exit**
   - Ends the program.

---

## 🚀 How to Run

1. Open the project in **CLion** (or any C++ IDE).
2. Make sure a file named `loginData.txt` is in the same directory (it will be created automatically if it doesn't exist).
3. Build and run the program.
4. Follow the CLI prompts.

---

## 📝 Sample Usage

```bash
1- Login
2- Sign-Up
3- Forgot Password
4- Exit
Enter your choice: 2

Enter Username: johndoe
Enter Email: john@example.com
Enter Password: mypass123

# Account saved to loginData.txt

# Then try login:

1- Login
Enter Username: johndoe
Enter Password: mypass123
Login Successful!

⚠️ Note
This project is intended for educational purposes only.

Passwords are stored in plain text — do not use real credentials.

No encryption or hashing is used for password security.

📄 License
This project is licensed under the MIT License.

sql
Copy
Edit
MIT License
