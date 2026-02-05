import sys
import smtplib
from email.message import EmailMessage

to_email = sys.argv[1]
student_name = sys.argv[2]
book_title = sys.argv[3]
return_date = sys.argv[4]
fine = sys.argv[5]


EMAIL_ADDRESS = "zerosimonriley833@gmail.com"
EMAIL_PASSWORD = "owrh fhvh dcjw piwl"

msg = EmailMessage()
msg["Subject"] = "Library Book Return Confirmation"
msg["From"] = EMAIL_ADDRESS
msg["To"] = to_email

msg.set_content(f"""
Hello {student_name}),

Your book has been returned successfully.

Book Title : {book_title}
Return Date : {return_date}
Fine Amount : {fine}

Thank you for using the library.

Regards,
Library Management System
""")

try:
    with smtplib.SMTP_SSL("smtp.gmail.com",465)as server:
        server.login(EMAIL_ADDRESS,EMAIL_PASSWORD)
        server.send_message(msg)
except Exception as e:
    print("Email failed:",e)