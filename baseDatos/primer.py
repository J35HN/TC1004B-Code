import mysql.connector

def main():
    db = mysql.connector.connect(
        host = "localhost",
        user = "",
        passwd = "",
    )
    myCursor = db.cursor()
    menu = 0
    while (menu > 0):
        print("[1]. Querie.\n[0]. Salir.")
        menu = input("\n")
        if (menu == 1):
            consulta = input("Querie: ")
            myCursor.execute(consulta)
        elif (menu == 0):
            print("Adios")

main()