import mysql.connector

mydb = mysql.connector.connect(
    host = "localhost",
    user = "root",
    passwd = "root",
    database = "monc"
)

mycursor = mydb.cursor()

mycursor.execute("SELECT * FROM log ORDER BY log_id ASC;")
myresult = mycursor.fetchall()

mycursor.execute("SELECT * FROM log ORDER BY log_id ASC;")
oneRow = mycursor.fetchone()

for x in myresult:
    print(myresult)

print('Next')

print(oneRow)
