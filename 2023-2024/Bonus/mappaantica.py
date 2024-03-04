# Testo:
# https://training.olinfo.it/#/task/mappa/submissions

N = 0
mappa = []

def fuori_matrice(i, j, y, x):
    if i + y < 0 or i + y > N - 1 or j + x < 0 or j + x > N - 1:
        return True
    else:
        return False

def attraversa(i, j):
    for y in range(-1, 2):
        for x in range(-1, 2):
            if fuori_matrice(i, j, y, x):
                # Non fare niente...
                # Il for sottostante non sarà eseguito
                pass
            # Se la cella in cui vogliamo andare è sicura
            # oppure abbiamo trovato un percorso migliore
            elif mappa[i + y][j + x] == 0 or mappa[i + y][j + x] > mappa[i][j] + 1:
                # Aggiungiamo 1 a quella cella
                mappa[i + y][j + x] = mappa[i][j] + 1
                # Andiamoci!
                attraversa(i + y, j + x)

input_file = open("./input.txt", mode = "r")
output_file = open("./output.txt", mode = "w")
N = int(input_file.readline())

for i in range(N):
    line = input_file.readline()
    riga = []
    for j in range(N):
        if line[j] == '*':
            riga.append(0)
        else:
            riga.append(-1)
    mappa.append(riga)

mappa[0][0] = 1
attraversa(0, 0)
output_file.write(str(mappa[N - 1][N - 1]))

