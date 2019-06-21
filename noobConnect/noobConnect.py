import sys
import asyncio
import websockets
import sqlServer
#Split in receive and send
import bank

class NoobConnect (bank.bank):
    version = '1.0.0'
    debug = False

    columnWidth = 15
    nrOfColumns = 3
    tableWidth = nrOfColumns * columnWidth + nrOfColumns - 1
    tableSeparator = '=' * tableWidth
    headerUnderline = '-' * tableWidth
    
    class Account:
        #Make balance a sql query
        def __init__ (self, pin):
            self.pin = pin
            self.balance = 0
    #===========================================================
    def __init__ (self, bankCode, valueOfLocalCoinInEuros = 1):
        super () . __init__ ('sumodo')
        
        self.print (f'Consumer bank emulator version {self.version} initiated')
        self.noobUrl = f'ws://{self.centralHostName}:{self.centralPortNr}'
        
        self.valueOfLocalCoinInEuros = valueOfLocalCoinInEuros  # All communication with central bank done in Euros
        self.accounts = {}
        
        asyncio.run (self.clientsCreator ())

    async def clientsCreator (self):
        ''' Initiates master and slave connections
        - The master connection is used to perform locally requested transactions on a remote bank
        - The slave connection is used to perform remotely requested transactions on the local bank
        '''
        
        async def roleClient (socket, role, action):
            await self.send (socket, role, ['register', role, self.bankCode])
            if await self.recv (socket, role):
                self.print (f'Registration of {role} accepted by {self.centralBankCode}')   
                while True:
                    await action ()
            else:
                self.print (f'Registration of {role} rejected by {self.centralBankCode}')
        
        async with websockets.connect (self.noobUrl) as self.masterSocket:
             self.print ('Master connection accepted by NOOB')
             async with websockets.connect (self.noobUrl) as self.slaveSocket:
                self.print ('Slave connection accepted by NOOB')
                await asyncio.gather (
                    roleClient (self.slaveSocket, 'slave', self.issueCommandFromRemote),
                    roleClient (self.masterSocket, 'master', self.issueCommandFromLocal)
                )
    #=================================================================================
    async def issueCommandFromLocal (self):
        ''' Obtains a command from the console and issues an execution order
        - If the bankcode matches the local bank, the order is executed locally
        - If the bankcode doesn't match this local bank, the order is executed remotely
        '''
        #Get command from php or database
        command = await self.input ('Open, close, deposit, withdraw, quit or hack: ')
        
        if self.match (command, 'open', 'close', 'deposit', 'withdraw', 'hack'):
            
            # --- Show current account statuses
            
            if self.match (command, 'hack'):
                self.print (f'{self.tableSeparator}')
                self.print (f'{"account nr":{self.columnWidth}}{"pin":{self.columnWidth}}{"balance":{self.columnWidth}}')
                self.print (f'{self.headerUnderline}')
                for accountNr, account in self.accounts.items ():
                    self.print (f'{accountNr:{self.columnWidth}} {account.pin:{self.columnWidth}} {account.balance:{self.columnWidth}}')
                self.print (f'{self.tableSeparator}')
                return
        
            # --- Get user input
            
            pin = await self.input ('Pin: ')
            
            slaveBankCode = await self.input ('Bank code (press [enter] for local bank): ')
            if not slaveBankCode:
                slaveBankCode = self.bankCode
                self.print (f'Bank code {slaveBankCode} assumed')
                
            accountNr = await self.input ('Account number: ')
            
            if self.match (command, 'open', 'close'):
                amount = 0
            else:
                amount = float (await self.input ('Amount: '))
               
            # --- Allow user to verify input, except pincode
            
            self.print (f'Command: {command}')
            self.print (f'Bank code: {slaveBankCode}')
            self.print (f'Account nr: {accountNr}')
            
            if self.match (command, 'deposit', 'withdraw'):
                self.print (f'Amount: {amount}')
                            
            if not self.match (await self.input ('Correct (yes / no): '), 'yes'):   # Stay on safe side
                self.print ('Transaction broken off')
                return
            
            # --- Issue command for local or remote execution
            #==================================================================================================================================
            if slaveBankCode == self.bankCode:
                self.print ('Success' if self.executeCommandLocally (command) else 'Failure')
            else:
                self.print ('Success' if await self.executeCommandRemotely (slaveBankCode) else 'Failure')
                
        elif self.match (command, 'quit'):
            for socket, role in ((self.masterSocket , 'master'), (self.slaveSocket, 'slave')):
                await self.send (socket, role, 'disconnect')
                reply = self.recv (socket, role)
            self.print ('\nConsumber bank emulator terminated\n')
            sys.exit (0)
            
        else:
            print ('Unknown command')
    #=====================================================================
    #=====================================================================
    #=====================================================================
    #=====================================================================
    async def issueCommandFromRemote (self):
        ''' Obtains a command from the slave socket and issues an execution order
        - The central bank used the bank code on the order it received, to send it to this bank specifially, for local execution
        - Since there's no need for the bank code anymore, the central bank stripped it off
        '''
        command = await self.recv (self.slaveSocket, 'slave', self.debug)
        await self.send (self.slaveSocket, 'slave', self.executeCommandLocally (command), self.debug)
    #==========================================================================================================================================================
    def executeCommandLocally (self, command): 
        ''' Executes a command on the local bank
        - Returns True if command succeeds
        - Returns False if command fails
        '''
        command = command.replace(" ","")
        command = command.replace("'","")
        command = command.replace("{","")
        command = command.replace("}","")
        command = command.split(",")

        myList = ['w']

        for x in range (6):
            myList.append(command.split(":"))
        idBank=None
        idSend=None
        func=None
        iban=None
        pin=None
        amount=None
        for x in range (len(myList)):
            if 'IDRecBank' in myList[x]:
                idBank = myList[x]
            elif 'IDSenBank' in myList[x]:
                idSend = myList[x]
            elif 'Func' in myList[x]:
                func = myList[x]
            elif 'IBAN' in myList[x]:
                iban = myList[x]
            elif 'PIN' in myList[x]:
                pin = myList[x]
            elif 'Amount' in myList[x]:
                amount = myList[x]

        #'IDRecBank' 'IDSenBank' 'Func' 'IBAN' 'PIN' 'Amount'
        noobdb=sqlServer.Sql()

        if func[1] == 'pinCheck':
            result = noobdb.checkPinCommand(iban[1], pin[1])
            return result
        elif func[1] == 'withdraw':
            result = noobdb.withdrawCommand(iban[1],pin[1],amount[1])
            return result

    #===========================================================================================================================================
    async def executeCommandRemotely (self, bankCode):
        '''Executes a command on the remove bank by delegation
        - Returns True if delegated command succeeds
        - Returns False if delegated command fails
        '''
        await self.send (self.masterSocket, 'master', bankCode)
        answer = await self.recv (self.masterSocket, 'master')
        print(answer)
        return answer
    
if len (sys.argv) < 3:
    print (f'Usage: python {sys.argv [0]} <bank code> <value of local coin in euro\'s>')
else:
    NoobConnect (sys.argv [1] .lower (), float (sys.argv [2]))
    
