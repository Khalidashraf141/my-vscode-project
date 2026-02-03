import smtplib
import sys
from email.message import EmailMessage

SENDER_EMAIL = "zerosimonriley833@gmail.com"
APP_PASSWORD = "owrh fhvh dcjw piwl"
RECEIVER_EMAIL = sys.argv[1]
PDF_FILE = "receipt.pdf"




msg = EmailMessage()
msg["Subject"] = "Library Book Issue Receipt"
msg["From"] = SENDER_EMAIL
msg["To"] = RECEIVER_EMAIL

msg.set_content("Dear Student,\n\n"
                "Your book has been issued successfully.\n"
                "Please find the receipt attached.\n\n"
                "Regards,\n"
                "Library Management"
)

with open(PDF_FILE,"rb") as f:
    msg.add_attachment(
        f.read(),
        maintype="application",
        subtype="pdf",
        filename="Library_Receipt.pdf"
)
    
with smtplib.SMTP_SSL("smtp.gmail.com",465) as server:
    server.login(SENDER_EMAIL,APP_PASSWORD)
    server.send_message(msg)
print("Email sent successfully!",RECEIVER_EMAIL)