import mysql.connector
from mysql.connector.fabric import connect

def main():
    db = mysql.connector.connect(
        host = "localhost",
        user = "root",
        passwd = ""
    )
    myCursor = db.cursor()
    menu = 1
    while (menu > 0):
        print("[1]. Querie.\n[0]. Salir.")
        menu = int(input("\n"))
        if (menu == 1):
            consulta = input("Querie: ")
            myCursor.execute(consulta)
            db.commit()
            print(consulta + "\n");
        elif (menu == 0):
            print("Adios... :)")

if __name__ == "__main__":
    main()
