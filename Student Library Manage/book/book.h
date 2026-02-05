#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <filesystem>
#include <sstream>
#include <ctime>
#include <limits>

using namespace std;
struct Book
{
    int bookId, days;
    string title, author, issueDate, dueDate;

    bool isAvailable;
};

struct Student
{
    string studentName, fatherName, issueDate, dueDate, email;
    char section;
    int rollNumber, days;
};

class LibraryBook
{
private:
    vector<Student> students;
    vector<Book> books;

public:
    LibraryBook()
    {
        loadBooksFromFile();
    }

    // Add new book
    void addBook()
    {
        Book b;
        b.bookId = getNextBookId();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter Book Title : ";
        getline(cin, b.title);

        cout << "Enter Author Name : ";
        getline(cin, b.author);

        b.isAvailable = true;
        books.push_back(b);
        saveBookToFile(b);

        cout << "Book added successfully!\n";
        cout << "Auto Generated Book ID: " << b.bookId << endl;
    }

    // View all books in the file
    void viewAllBooks()
    {
        if (books.empty())
        {
            cout << "No books available in the library\n";
            return;
        }

        cout << "\n------ Library Books ------\n";
        for (const Book &b : books)
        {
            cout << "Book ID    : " << b.bookId << endl;
            cout << "Title      : " << b.title << endl;
            cout << "Author     : " << b.author << endl;
            cout << "Status     : " << (b.isAvailable ? "Available" : "Issued") << endl;
            cout << "-----------------------------------\n";
        }
    }

    void findBook()
    {
        string searchTitle;
        cout << "Enter Book Title: ";
        getline(cin, searchTitle);

        bool found = false;
        for (const auto &b : books)
        {
            if (b.title == searchTitle)
            {
                cout << "\n---------------------------------------------\n";
                cout << "Book Found!\n";
                cout << "Book ID    : " << b.bookId << endl;
                cout << "Title      : " << b.title << endl;
                cout << "Author     : " << b.author << endl;
                cout << "Status     : " << (b.isAvailable ? "Available" : "Issued") << endl;
                cout << "---------------------------------------------\n";
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Book not found.\n";
        }
    };

    void returnBook()
    {
        int bookId;
        cout << "Enter Book ID: ";
        cin >> bookId;

        if (!isBookIssued(bookId))
        {
            cout << "Book not found in issue record\n";
            return;
        }

        Student s;
        Book b;

        if (!getIssueDetailsByBookId(bookId, s, b))
        {
            cout << "Failed to fetch issue details\n";
            return;
        }

        string currentDate = getCurrentDate();

        int dueDays = dateToDays(s.dueDate);
        int currentDays = dateToDays(currentDate);

        int fine = 0;

        if (currentDays > dueDays)
        {
            int delay = currentDays - dueDays;
            fine = delay * 5;

            cout << "Late return by " << delay << " days\n";
            cout << "Fine: " << fine << endl;
        }
        else
        {
            cout << "Book returned on time. No fine\n";
        }

        saveReturnLog(s.rollNumber, s.studentName, s.fatherName, s.section, s.email, b.bookId, b.title, s.issueDate, s.dueDate, currentDate, fine);

        // send return email
        string cmd = "python book/return_email.py \"" + s.email + "\" \"" + s.studentName + "\" \"" + b.title + "\" \"" + currentDate + "\" \"" + to_string(fine) + "\"";

        int emailStatus = system(cmd.c_str());

        if (emailStatus != 0)
        {
            cout << "Warning: Email could not be sent.\n";
        }
        else
        {
            cout << "Return confirmation email sent successfully.\n";
        }

        // Remove from issue record
        removeIssueRecord(bookId);

        // Update availability ONLY if issued
        for (auto &b : books)
        {
            if (b.bookId == bookId)
            {
                b.isAvailable = true;
                break;
            }
        }

        rewriteBooksFile();
        cout << "Book availability update successfully.\n";
    }

    void issueBook()
    {

        string searchBook;
        cout << "Enter Book Title : ";
        getline(cin, searchBook);
        bool found = false;
        for (auto &b : books)
        {
            if (b.title == searchBook)
            {
                found = true;

                if (b.isAvailable)
                {
                    cout << "\t\t\tYes this book is available you can issue it\n";
                    Student s;
                    cout << "Enter Student Name : ";

                    getline(cin, s.studentName);
                    cout << "Enter Roll Number  : ";
                    cin >> s.rollNumber;

                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Enter Student Class Section : ";
                    cin >> s.section;

                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Enter Father's Name : ";
                    getline(cin, s.fatherName);

                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Enter your gmail : ";
                    getline(cin, s.email);

                    if (s.email.find("@gmail.com") == string::npos)
                    {
                        cout << "Invalid Gmail address. Please enter a valid Gmail.\n";
                        return;
                    }

                    cout << "Enter number of days to issue: ";
                    cin >> s.days;

                    s.issueDate = getCurrentDate();
                    s.dueDate = calculateDueDate(s.days);

                    cout << "Issue Date: " << s.issueDate << endl;
                    cout << "Due Date  : " << s.dueDate << endl;

                    b.isAvailable = false;
                    rewriteBooksFile(); // UPDATE THE FILE
                    cout << "Book issued successfully\n";
                    saveIssueBook(s, b);

                    string receiptBaseName = s.studentName;
                    for (char &c : receiptBaseName)
                    {
                        if (c == ' ')
                            c = '_';
                    }
                    receiptBaseName += "_" + to_string(s.rollNumber) + "_receipt";

                    generateReceiptHTML(s, b, receiptBaseName);

                    convertHTMLtoPDF(receiptBaseName);
                    cout << "Receipt generated successfully (PDF)\n";

                    string cmd = "python book/send_email.py \"" + s.email + "\" \"" + receiptBaseName + "\"";

                    int emailStatus = system(cmd.c_str());
                    if (emailStatus != 0)
                        cout << "Email could not be sent\n";

                    else
                        cout << "Receipt email sent successfully\n";

                    return;
                }
                else
                {
                    cout << "Sorry this book is not available for issue";
                    return;
                }
                return;
            }
        }
        if (!found)
        {
            cout << "Book not fund in library\n";
        }
    };

    void viewIssuedBooks()
    {
        ifstream file("book/issueBookRecord.txt");
        if (!file.is_open())
        {
            cout << "No issued book records found.\n";
            return;
        }

        cout << "\n========== ISSUED BOOK RECORDS ==========\n";

        string line;
        bool empty = true;

        while (getline(file, line))
        {
            if (line.empty())
                continue;

            empty = false;

            stringstream ss(line);
            string field;

            int bookId, rollNumber, days;
            char section;
            string studentName, fatherName, issueDate, email, dueDate;

            // Read fields in the SAME order as writing
            getline(ss, field, '|');
            bookId = stoi(field);

            getline(ss, studentName, '|');
            getline(ss, fatherName, '|');

            getline(ss, field, '|');
            rollNumber = stoi(field);

            getline(ss, field, '|');
            section = field[0];

            getline(ss, field, '|');
            days = stoi(field);

            getline(ss, issueDate, '|');
            getline(ss, email, '|');
            getline(ss, dueDate);

            // Display
            cout << "----------------------------------\n";
            cout << "Book ID        : " << bookId << endl;
            cout << "Student Name   : " << studentName << endl;
            cout << "Father Name    : " << fatherName << endl;
            cout << "Roll Number    : " << rollNumber << endl;
            cout << "Section        : " << section << endl;
            cout << "Issued Days    : " << days << endl;
            cout << "Issue Date     : " << issueDate << endl;
            cout << "Due Date       : " << dueDate << endl;
            cout << "Student Email  : " << email << endl;
        }

        if (empty)
        {
            cout << "No books are currently issued.\n";
        }

        cout << "========================================\n";

        file.close();
    }

    /*---------------------------------------------PRIVATE FUNCTION-----------------------------------------------*/
private:
    int getNextBookId()
    {
        ifstream fin("book/bookIdCounter.txt");
        int lastId = 100;

        if (fin.is_open())
        {
            fin >> lastId;
            fin.close();
        }

        int newId = lastId + 1;
        ofstream fout("book/bookIdCounter.txt");
        fout << newId;
        fout.close();

        return newId;
    }
    void generateReceiptHTML(const Student &s, const Book &b, const string &baseName)
    {
        // Create safe filename using student name + roll number
        string fileName = baseName + ".html";

        ofstream html("book/" + fileName);
        if (!html)
        {
            cout << "Failed to create receipt file\n";
            return;
        }

        html << "<!DOCTYPE html>\n";
        html << "<html><head><meta charset='UTF-8'>\n";
        html << "<title>Library Receipt</title>\n";

        html << "<style>\n";
        html << "body{font-family:Arial;background:#f4f4f4;}\n";
        html << ".receipt{width:600px;margin:auto;background:#fff;padding:20px;border:1px solid #ccc;}\n";
        html << "h2{text-align:center;}\n";
        html << "p{font-size:14px;}\n";
        html << "</style>\n";

        html << "</head><body>\n";

        html << "<div class='receipt'>\n";
        html << "<h2>Library Book Issue Receipt</h2><hr>\n";

        html << "<p><b>Student Name:</b> " << s.studentName << "</p>\n";
        html << "<p><b>Father Name:</b> " << s.fatherName << "</p>\n";
        html << "<p><b>Student Gmail:</b> " << s.email << "</p>\n";
        html << "<p><b>Roll Number:</b> " << s.rollNumber << "</p>\n";
        html << "<p><b>Section:</b> " << s.section << "</p>\n";

        html << "<hr>\n";

        html << "<p><b>Book ID:</b> " << b.bookId << "</p>\n";
        html << "<p><b>Book Title:</b> " << b.title << "</p>\n";
        html << "<p><b>Author:</b> " << b.author << "</p>\n";

        html << "<hr>\n";

        html << "<p><b>Issue Date:</b> " << s.issueDate << "</p>\n";
        html << "<p><b>Due Date:</b> " << s.dueDate << "</p>\n";

        html << "<hr>\n";
        html << "<p style='text-align:center;'>Please return the book on time.</p>\n";

        html << "</div></body></html>\n";

        html.close();

        cout << "Receipt generated: book/" << fileName << endl;
    }

    void convertHTMLtoPDF(const string &baseFileName)
    {
        // Paths
        string htmlPath = filesystem::absolute("book/" + baseFileName + ".html").string();
        string pdfPath = filesystem::absolute("book/" + baseFileName + ".pdf").string();

        // Windows: fix slashes
        for (char &c : htmlPath)
            if (c == '\\')
                c = '/';
        for (char &c : pdfPath)
            if (c == '\\')
                c = '/';

        string cmd = "wkhtmltopdf --quiet --enable-local-file-access "
                     "\"file:///" +
                     htmlPath + "\" "
                                "\"" +
                     pdfPath + "\"";

        int result = system(cmd.c_str());

        if (result == 0)
            cout << "Receipt PDF generated: book/" << baseFileName << ".pdf\n";
        else
            cout << "PDF generation failed. Is wkhtmltopdf installed?\n";
    }

    string getCurrentDate()
    {
        time_t now = time(nullptr);
        tm *ltm = localtime(&now);

        return to_string(ltm->tm_mday) + "/" +
               to_string(ltm->tm_mon + 1) + "/" +
               to_string(ltm->tm_year + 1900);
    }

    string calculateDueDate(int days)
    {
        time_t now = time(nullptr);
        tm *ltm = localtime(&now);

        ltm->tm_mday += days; // add days
        mktime(ltm);          // normalize date

        int day = ltm->tm_mday;
        int month = ltm->tm_mon + 1;
        int year = ltm->tm_year + 1900;

        return to_string(day) + "/" +
               to_string(month) + "/" +
               to_string(year);
    }

    void loadBooksFromFile()
    {
        ifstream file("book/book.txt");
        if (!file.is_open())
        {
            return;
        }
        string line;
        while (getline(file, line))
        {
            if (line.empty())
                continue;
            if (line.find('|') == string::npos)
                continue;
            Book b;
            size_t pos;

            pos = line.find('|');
            b.bookId = stoi(line.substr(0, pos));
            line.erase(0, pos + 1);

            pos = line.find('|');
            b.title = line.substr(0, pos);
            line.erase(0, pos + 1);

            pos = line.find('|');
            b.author = line.substr(0, pos);
            line.erase(0, pos + 1);

            b.isAvailable = (line == "1");
            books.push_back(b);
        }
        file.close();
    }

    void saveBookToFile(const Book &b)
    {
        ofstream file("book/book.txt", ios::app);
        file << b.bookId << "|"
             << b.title << "|"
             << b.author << "|"
             << b.isAvailable << endl;
        file.close();
    }

    void rewriteBooksFile()
    {
        ofstream file("book/book.txt");
        for (const auto &b : books)
        {
            file << b.bookId << "|"
                 << b.title << "|"
                 << b.author << "|"
                 << b.isAvailable << endl;
        }
        file.close();
    }

    void saveIssueBook(const Student &s, const Book &b)
    {
        ofstream file("book/issueBookRecord.txt", ios::app);
        file << b.bookId << "|"
             << s.studentName << "|"
             << s.fatherName << "|"
             << s.rollNumber << "|"
             << s.section << "|"
             << s.days << "|"
             << s.issueDate << "|"
             << s.email << "|"
             << s.dueDate << endl;
        file.close();
    }

    // first we will check the is this book id present in the issuebook.txt record
    bool isBookIssued(int bookId)
    {
        ifstream file("book/issueBookRecord.txt");
        if (!file.is_open())
        {
            cout << "Issue record file not found\n";
            return false;
        }

        string line;
        while (getline(file, line))
        {
            if (line.empty())
                continue;

            size_t pos = line.find('|');
            if (pos == string::npos)
                continue;

            int issueBookId = stoi(line.substr(0, pos));
            if (issueBookId == bookId)
            {
                file.close();
                return true;
            }
        }
        file.close();
        return false;
    }

    // get the due date from the file
    string getDueDateByBookId(int bookId)
    {
        ifstream file("book/issueBookRecord.txt");
        if (!file.is_open())
            return "";

        string line;
        while (getline(file, line))
        {
            if (line.empty())
                continue;

            stringstream ss(line);
            string field;

            // Read book ID first
            getline(ss, field, '|');
            int issuedBookId = stoi(field);

            if (issuedBookId == bookId)
            {
                // skips next 7 fields
                for (int i = 0; i < 7; i++)
                    getline(ss, field, '|');

                // Last field = due date
                getline(ss, field);
                file.close();
                return field;
            }
        }
        file.close();
        return "";
    }

    int dateToDays(const string &date)
    {
        int d, m, y;
        char slash;
        stringstream ss(date);
        ss >> d >> slash >> m >> slash >> y;

        tm timeStruct = {};
        timeStruct.tm_mday = d;
        timeStruct.tm_mon = m - 1;
        timeStruct.tm_year = y - 1900;

        return static_cast<int>(mktime(&timeStruct) / (60 * 60 * 24));
    }

    void removeIssueRecord(int bookId)
    {
        ifstream file("book/issueBookRecord.txt");
        ofstream temp("book/temp_issueBookRecord.txt");

        if (!file.is_open())
            return;

        string line;
        while (getline(file, line))
        {
            if (line.empty())
                continue;

            size_t pos = line.find('|');
            if (pos == string::npos)
                continue;

            int issuedBookId = stoi(line.substr(0, pos));

            if (issuedBookId != bookId)
            {
                temp << line << endl;
            }
        }
        file.close();
        temp.close();

        remove("book/issueBookRecord.txt");
        rename("book/temp_issueBookRecord.txt", "book/issueBookRecord.txt");
    }

    void saveReturnLog(
        int studentId,
        const string &studentName,
        const string &fatherName,
        char section,
        const string &email,
        int bookId,
        const string &bookName,
        const string &issueDate,
        const string &dueDate,
        const string &returnDate,
        int fine)
    {
        // Ensure folder exists
        filesystem::create_directories("data");

        ofstream fout("data/studentReturnBookLog.txt", ios::app);
        if (!fout)
        {
            cout << "Error opening studentReturnBookLog.txt\n";
            return;
        }

        fout << studentId << " | "
             << studentName << " | "
             << fatherName << " | "
             << section << " | "
             << email << " | "
             << bookId << " | "
             << bookName << " | "
             << issueDate << " | "
             << dueDate << " | "
             << returnDate << " | "
             << fine << '\n';

        fout.close();
    }

    bool getIssueDetailsByBookId(int bookId, Student &s, Book &b)
    {
        ifstream file("book/issueBookRecord.txt");
        if (!file.is_open())
            return false;

        string line;
        while (getline(file, line))
        {
            if (line.empty())
                continue;

            stringstream ss(line);
            string field;

            getline(ss, field, '|'); // bookId
            int issuedBookId = stoi(field);

            if (issuedBookId == bookId)
            {
                b.bookId = issuedBookId;

                getline(ss, s.studentName, '|');
                getline(ss, s.fatherName, '|');

                getline(ss, field, '|');
                s.rollNumber = stoi(field);

                getline(ss, field, '|');
                s.section = field[0];

                getline(ss, field, '|');
                s.days = stoi(field);

                getline(ss, s.issueDate, '|');
                getline(ss, s.email, '|');
                getline(ss, s.dueDate);

                // get book title from books vector
                for (const auto &bk : books)
                {
                    if (bk.bookId == bookId)
                    {
                        b.title = bk.title;
                        break;
                    }
                }

                file.close();
                return true;
            }
        }
        file.close();
        return false;
    }
};
#endif