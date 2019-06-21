import mysql.connector
#import noobConnect
from subprocess import Popen, PIPE

class Sql:
    def __init__(self):
        self.mydb = mysql.connector.connect(
            host = "monarchdouglasbank.tk",
            user = "root",
            passwd = "wK6227",
            database = "bank"
        )
        self.command = ""
        self.mycursor = self.mydb.cursor()

    def readDB(self):
        self.mycursor.execute("SELECT * FROM noob ORDER BY commandID DESC;")
        self.oneRow = self.mycursor.fetchone()
        self.mycursor.fetchall()
        self.command = self.oneRow[1]
    
    # def executeCommand(self):
    #     noobConnect.NoobConnect.executeCommandRemotely(self.command)
    
    def checkPinCommand(self, iban="", pin=""):
        query = "SELECT * FROM accounts WHERE iban = {};".format(iban)
        self.mycursor.execute(query)
        self.oneRow = self.mycursor.fetchone()
        self.mycursor.fetchall()
        self.pinHash = self.oneRow[5]
        process = Popen.wait(['php', 'pinCheck.php', pin, self.pinHash], stdout=PIPE, stderr=PIPE)
        stdout, stderr = process.communicate()
        return stdout
    
    def withdrawCommand(self, iban="", pin="", amount=""):
        result = checkPinCommand(iban, pin)
        if result == True:
            query = "SELECT * FROM accounts WHERE iban = {};".format(iban)
            self.mycursor.execute(query)
            self.oneRow = self.mycursor.fetchone()
            self.mycursor.fetchall()
            self.balance = self.oneRow[3]
            if int(self.balance) > int(amount):
                newBalance = str(int(self.balance) - int(amount))
                update = "UPDATE accounts SET balance = {}.0 where iban = {}".format(newBalance, iban)
                self.mycursor.execute(update)
                return True
            else:
                return False
        else:
            return False
