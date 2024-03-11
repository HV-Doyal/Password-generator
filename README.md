**Password Generator README**
Year 1 Coursework
---

**Introduction:**

This is a simple password generator program written in C. It generates a password by selecting random words from files containing words of varying lengths (4 to 7 characters). The user is prompted to specify the number of words to include in the password, and the program generates the password accordingly.

---

**Functionality:**

1. **Intro():**
   - Displays an introductory message with an animated effect.

2. **number_generator():**
   - Generates a random number between 1 and 500.

3. **read_from_4(), read_from_5(), read_from_6(), read_from_7():**
   - Reads a random line from files named "4", "5", "6", and "7" respectively.
   - Returns the line as a dynamically allocated string.

4. **Random_file():**
   - Chooses a random file among the four mentioned above and returns a line from that file.

5. **Correct_Parameter():**
   - Prompts the user for the number of words for the password.
   - Checks if the input is within the valid range (3 to 4).

6. **Generate_Password():**
   - Generates a password by calling Random_file() to get words from random files.
   - Prints the generated password.

7. **main():**
   - Calls Intro() to display the introductory message.
   - Calls Correct_Parameter() to prompt the user for the number of words (commented out by default).
   - Calls Generate_Password() to generate the password.

---

**Usage:**

1. Clone or download the source code files to your local machine.

2. Compile the code using a C compiler. For example, you can use `gcc`:

   ```bash
   gcc password_generator.c -o password_generator
   ```

3. Run the compiled executable:

   ```bash
   ./password_generator
   ```

4. Follow the on-screen instructions to generate a password.

---

**Notes:**

- Ensure that the files "4", "5", "6", and "7" exist and contain words for the program to read.
- The strengthen() function is incomplete and not utilized in the current version of the program.
- There might be issues with file handling in certain functions. Review and fix the fclose() statements if needed.
