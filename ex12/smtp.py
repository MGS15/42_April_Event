import smtplib, ssl
from getpass import getpass
import imghdr
from email.message import EmailMessage

host = 'mail-students.1337.ma'
port = 465
user = 'sel-kham@student.1337.ma'
_pass = getpass()
receiver = input('Enter receveiver email: ')

try:
	context = ssl._create_unverified_context()
	msg = EmailMessage()
	msg['Subject'] = 'Surprise!!'
	msg['From'] = user
	msg['To'] = receiver
	msg.set_content('Surprise madafaka!')
	with open('attachment.gif', 'rb') as att:
		data = att.read()
		image_type = imghdr.what(att.name)
		image_name = att.name
	msg.add_attachment(data, maintype='image', subtype=image_type, filename=image_name)
	with smtplib.SMTP_SSL(host, port, context=context) as server:
		repley = server.login(user, _pass)
		if (repley[0] != 235):
			print('Login error!')
			exit(1)
		server.send_message(msg)
		print('Email sent successfully.')
except Exception as e:
	print('Error sending email')