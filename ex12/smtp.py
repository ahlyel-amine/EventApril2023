import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.base import MIMEBase
from email.mime.text import MIMEText
from email.utils import COMMASPACE
from email import encoders

# Set the email sender, recipients, subject, and body text
sender = "sender@example.com"
recipients = ["recipient1@example.com", "recipient2@example.com"]
subject = "Email with Attachment"
body = "This email contains an attachment."

# Set the attachment file path and name
attachment_path = "/path/to/attachment"
attachment_name = "attachment.txt"

# Open the attachment file and read its contents
with open(attachment_path, "rb") as attachment:
    attachment_data = attachment.read()

# Create the email message object and set its properties
message = MIMEMultipart()
message["From"] = sender
message["To"] = COMMASPACE.join(recipients)
message["Subject"] = subject
message.attach(MIMEText(body))

# Add the attachment to the email message object
attachment = MIMEBase("application", "octet-stream")
attachment.set_payload(attachment_data)
encoders.encode_base64(attachment)
attachment.add_header("Content-Disposition", f"attachment; filename={attachment_name}")
message.attach(attachment)

# Send the email using SMTP
smtp_server = "smtp.example.com"
smtp_port = 587
smtp_username = "username"
smtp_password = "password"
with smtplib.SMTP(smtp_server, smtp_port) as server:
    server.starttls()
    server.login(smtp_username, smtp_password)
    server.sendmail(sender, recipients, message.as_string())

print("Email sent successfully.")