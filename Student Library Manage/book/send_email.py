import smtplib
import os
import sys
from email.message import EmailMessage

SENDER_EMAIL = "zerosimonriley833@gmail.com"
APP_PASSWORD = "owrh fhvh dcjw piwl" 
RECEIVER_EMAIL = sys.argv[1]

# Get the directory where THIS script is located
BASE_DIR = os.path.dirname(os.path.abspath(__file__))
PDF_FILE = os.path.join(BASE_DIR, "receipt.pdf")

# SAFETY CHECK: Don't try to open the file if it doesn't exist
if not os.path.exists(PDF_FILE):
    print(f"Error: PDF file not found at {PDF_FILE}")
    sys.exit(1)

msg = EmailMessage()
msg["Subject"] = "Library Book Issue Receipt"
msg["From"] = SENDER_EMAIL
msg["To"] = RECEIVER_EMAIL
msg.set_content("Dear Student,\n\nYour book has been issued successfully.\nPlease find the receipt attached.\n\nRegards,\nLibrary Management")

try:
    with open(PDF_FILE, "rb") as f:
        msg.add_attachment(
            f.read(),
            maintype="application",
            subtype="pdf",
            filename="Library_Receipt.pdf"
        )
    
    with smtplib.SMTP_SSL("smtp.gmail.com", 465) as server:
        server.login(SENDER_EMAIL, APP_PASSWORD)
        server.send_message(msg)
    print(f"Email sent successfully to {RECEIVER_EMAIL}")
except Exception as e:
    print(f"Failed to send email: {e}")