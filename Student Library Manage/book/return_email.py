import sys
import smtplib
from email.message import EmailMessage

# Arguments from C++
to_email = sys.argv[1]
student_name = sys.argv[2]
book_title = sys.argv[3]
return_date = sys.argv[4]
fine = sys.argv[5]

EMAIL_ADDRESS = "zerosimonriley833@gmail.com"
EMAIL_PASSWORD = "owrh fhvh dcjw piwl"   # Gmail App Password

msg = EmailMessage()
msg["Subject"] = "Library Book Return Confirmation"
msg["From"] = EMAIL_ADDRESS
msg["To"] = to_email

# 📩 Email body (with or without fine)
if fine == "0":
    msg.set_content(f"""
Hello {student_name},

Your library book has been returned successfully.

Book Title  : {book_title}
Return Date : {return_date}

Thank you for returning the book on time.
We appreciate your cooperation.

Regards,
Library Management System
""")
else:
    msg.set_content(f"""
Hello {student_name},

Your library book has been returned successfully.

Book Title  : {book_title}
Return Date : {return_date}
Fine Amount : ₹{fine}

Please ensure timely returns in the future
to avoid fines.

Regards,
Library Management System
""")

# 📤 Send email
try:
    with smtplib.SMTP_SSL("smtp.gmail.com", 465) as server:
        server.login(EMAIL_ADDRESS, EMAIL_PASSWORD)
        server.send_message(msg)
        print("Email sent successfully")
except Exception as e:
    print("Email failed:", e)
