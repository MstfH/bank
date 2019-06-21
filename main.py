import sql.sqlServer as sqlServer
import noobConnect.noobConnect as noobConnect

def main():
    db = sqlServer.Sql()
    db.readDB()
    db.executeCommand()

if __name__ == "__main__":
    main()