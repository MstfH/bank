import noobConnect.sqlServer as sqlServer
import noobConnect.noobConnect as noobConnect

db = sqlServer.Sql()
db.readDB()
noobConnect.executeCommandRemotely(db.command)